#include <stdio.h>
#include <stdlib.h>
#include "tjpgd.h"
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>
#define JPEG_WBUF_SIZE 4096
JDEC *jpeg_dev;
FILE *f_jpeg;
uint8_t *jpg_buffer;
uint8_t data[320][507]; 

/*-----------------------------------------------------------------------*/
/* Apply Inverse-DCT in Arai Algorithm (see also aa_idct.png)            */
/*-----------------------------------------------------------------------*/
int idct_acc_fd;
int * pointer;
    
void block_idct (
	int32_t* src,	/* Input block data (de-quantized and pre-scaled for Arai Algorithm) */
	uint8_t* dst	/* Pointer to the destination to store the block as byte array */
)
{
	memcpy(pointer+64,src,256);
	*pointer=0x01;
	while(!((*pointer)&0x02));
	memcpy(dst,pointer+128,64);
	//read(idct_acc_fd,dst,64);
}


uint16_t jpeg_in_func(JDEC* jd,uint8_t* buf,uint16_t num) 
{ 
    uint16_t  rb; //读取到的字节数
    FILE *dev=(FILE*)jd->device;  //待解码的文件的信息，使用FATFS中的FIL结构类型进行定义
    if(buf)     				//读取数据有效，开始读取数据
    { 
	//printf("ftell(dev)=%ld\n",ftell(dev));
	//printf("num=%d\n",num);
        rb=fread(buf,1,num,dev);//调用FATFS的f_read函数，用于把jpeg文件的数据读取出来
        return rb;        		//返回读取到的字节数目
    }else
{
//printf("ftell(dev)%ld\n",ftell(dev));
 rb=(fseek(dev,ftell(dev)+num,0)==0)?num:0;
 //printf("ftell(dev)%ld\n",ftell(dev));
 return rb;//重新定位数据点，相当于删除之前的n字节数据 
}
}  
uint16_t out_func (
  JDEC* jdec,    /* Pointer to the decompression object */
  void* bitmap,  /* RGB bitmap to be output */
  JRECT* rect    /* Rectangular region to output */
)
{
	uint8_t *point=(uint8_t *)bitmap;
        for(int y=rect->top;y<=rect->bottom;y++)
		for(int x=rect->left;x<=rect->right;x++)
	{
		data[y][x]=*point>128?0:1;
		point=point+3;
	}
	//printf("rect->top=%d\n",rect->top);
	//printf("rect->bottom=%d\n",rect->bottom);
	//printf("rect->left=%d\n",rect->left);
	//printf("rect->right=%d\n",rect->right);
}
int main(int argc, char * argv[])
{
	idct_acc_fd= open("/dev/idct_acc",O_RDWR,S_IRUSR|S_IWUSR);
	pointer=mmap(0, 576, PROT_WRITE|PROT_READ , MAP_SHARED , idct_acc_fd, 0);
	FILE *txt=fopen("result.txt","a");
	jpg_buffer=(uint8_t *)malloc(JPEG_WBUF_SIZE);
	jpeg_dev=(JDEC *)malloc(sizeof(JDEC));
	f_jpeg=fopen(argv[1],"r");
	int res=jd_prepare(jpeg_dev,jpeg_in_func,jpg_buffer,JPEG_WBUF_SIZE,f_jpeg);
	res=jd_decomp(jpeg_dev,out_func,0); 
	int y_limit_top;
	int y_limit_bottom;
        int d=0; 
	for(int y=0;y<=320;y++)
	{
		int has_data=0;
		for(int x=0;x<=507;x++)
		{
			has_data+=data[y][x];
		}
		if(d==0&&has_data>0)
		{
			d=1;
			y_limit_top=y;
		}
		if(d==1&&has_data==0)
		{
			y_limit_bottom=y;
			break;
		}
	}
	//printf("%d %d\n",y_limit_bottom,y_limit_top);
	int x_left=0;
	int x_right=0;
	d=0;
	int full=0; 
	char a[19];
	int j=0;
	{
	for(int x=0;x<=507;x++)
	{
		
		int has_data=0;
		for(int y=y_limit_top;y<y_limit_bottom;y++)
		{
			has_data+=data[y][x];
		}
		if(d==0&&has_data>0)
		{
			x_left=x;
			d=1;
		}
		if(has_data>=y_limit_bottom-y_limit_top-1) full=1;
		if(d==1&&has_data==0)
		{
			x_right=x;
			d=0;
			int x_half=(x_left+x_right)/2;
			//for(int y=y_limit_top;y<y_limit_bottom;y++)
			//{
				//for(int x=x_left;x<x_right;x++)
				//{
				//	printf("%1d",data[y][x]);
				//}
				//printf("\n");
			//}
			if(x_right-x_left<=(y_limit_bottom-y_limit_top)/5*2)
			{
				a[j++]='1'; 
				//printf("1\n");
				
			}else if(full==1)
			{
				
				//printf("4\n");
				a[j++]='4'; 
	
			}else if(data[y_limit_top][x_left+1]==1&&data[y_limit_top][x_right-1]==1)
			{
				a[j++]='7'; 
				//printf("7\n");
			}else if(data[y_limit_bottom-1][x_left+1]==1&&data[y_limit_bottom-1][x_right-1]==1&&data[y_limit_bottom-1][x_half]==1)
			{
				//printf("2\n");
				a[j++]='2'; 
			}else
			{
				int y_top_1_4=y_limit_bottom/4+y_limit_top/4*3; 
				int y_top_3_4=y_limit_bottom/4*3+y_limit_top/4;
				int y_top_1_4_0_end=0;
				int y_top_1_4_1_end=0;
				int y_top_3_4_0_end=0;
				int y_top_3_4_1_end=0;
				
				for(int i=x_left;i<x_right;i++)
				{
					if(y_top_1_4_0_end==0&&data[y_top_1_4][i]==1) y_top_1_4_0_end=i;
					if(data[y_top_1_4][i]==1) y_top_1_4_1_end=i;
					if(y_top_3_4_0_end==0&&data[y_top_3_4][i]==1) y_top_3_4_0_end=i;
					if(data[y_top_3_4][i]==1) y_top_3_4_1_end=i;
				}
				if(y_top_1_4_1_end<x_half&&y_top_3_4_0_end<x_half&&y_top_3_4_1_end>x_half)
				{
					//printf("6\n");
					a[j++]='6'; 
				}else if(y_top_3_4_0_end>x_half&&y_top_1_4_0_end<x_half&&y_top_1_4_1_end>x_half)
				{
					//printf("9\n");
					a[j++]='9'; 
				}else if(y_top_1_4_1_end<x_half&&y_top_3_4_0_end>x_half&&y_top_3_4_1_end>x_half)
				{
					//printf("5\n");
					a[j++]='5'; 
				}else if(y_top_3_4_0_end>x_half&&y_top_1_4_0_end>x_half)
				{
					//printf("3\n");
					a[j++]='3'; 
				}else
				{
					int count=0;
					int pre_data=0; 
					for(int j=y_limit_top;j<y_limit_bottom;j++)
					{
						if(data[j][x_half]!=pre_data)
						{
							pre_data=data[j][x_half];
							count++;
						}
					}
					if(data[y_limit_bottom-1][x_half]==1) count++;
					if(count==6)
					{
						//printf("8\n");
						a[j++]='8'; 
					}else if(count==4)
					{
						//printf("0\n");
						a[j++]='0'; 
					}else if(count==2)
					{
						//printf("X\n");
						a[j++]='X'; 
					}else 
					{
						//printf("error\n");
						a[j++]='e'; 
					}
				}
			}
			full=0;
			
		}
	}
	}
	a[18]='\n';
	fwrite(a,19,1,txt);
	//printf("%d %d %d %d\n",y_limit_bottom,y_limit_top,x_left,x_right);
	munmap(pointer,320);
	fclose(f_jpeg);
	fclose(txt);
	close(idct_acc_fd);
	free(jpg_buffer);
	free(jpeg_dev);
}
