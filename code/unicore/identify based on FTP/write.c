#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>
int main()
{
    int fd;
    int msg[64];
char msg_2[64];
    for(int i=0;i<64;i++)
    {
	msg[i]=64-i;
    }
    fd= open("/dev/idct_acc",O_RDWR,S_IRUSR|S_IWUSR);
    int * pointer;
    pointer=mmap(0, 576, PROT_WRITE|PROT_READ , MAP_SHARED , fd, 0);
    if(pointer<0)
	{
	printf("mmap failure\n");
	return 0;
	}
    printf("mmp_addr is %p\n",pointer);
    if(fd!=-1)
    {
	*(pointer+128)=0xaaaaaaaa;
        //write(fd,msg,256);
        //for(int i=0;i<1000;i++);
        //read(fd,msg_2,64);
	/*for(int i=0;i<64;i++)
	    {
		printf("msg=%0x\n",msg[i]);
	    }
	for(int i=0;i<64;i++)
	    {
		printf("msg2=%0x\n",msg_2[i]);
	    }
*/
    }
    else
    {
        printf("device open failure\n");
    }
    close(fd);
    munmap(pointer,320);
    return 0;
}
