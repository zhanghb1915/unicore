#include <stdio.h>
void delay(int t)
    {
         int  i;
         for(;t>0;t--) 
        for(i=0;i<200;i++);
    }
void main()
{
	
    
        int *led =(int *)0x60010000;
	    int *led_tri =(int *)0x60010004;
		*led_tri=0x0000;
		while (1)
		{
		        *led=0x0000;
				//for(int i=0;i<=1000000;i++);
				//if （*led==0x8000）
				  //u
				     *led=0x0000;delay(100);
                     *led=0x801F;delay(100);
                     *led=0x0000;delay(100);
                     *led=0x801F;delay(100);
					 *led=0x0000;delay(100);
                     *led=0x0030;delay(100);
                     *led=0x0000;delay(100);
                     *led=0x0030;delay(100);*led=0x0000;delay(100);
                     *led=0x0020;delay(100);
                     *led=0x0000;delay(100);
*led=0x0020;delay(100);
                     *led=0x0030;delay(100);
                     *led=0x0000;delay(100);
*led=0x0030;delay(100);*led=0x0000;delay(100);
                     *led=0x0018;delay(100);
                     *led=0x0000;delay(100);
*led=0x0018;delay(100);*led=0x0000;delay(100);
                     *led=0x803F;delay(100);
                     *led=0x0000;delay(100);
*led=0x803F;delay(100);
                     *led=0x0000;delay(700);
				 //n
                     *led=0x803F;delay(100);
*led=0x0000;delay(100);
*led=0x803F;delay(100);*led=0x0000;delay(100);
                     *led=0x0001;delay(100);
*led=0x0000;delay(100);
*led=0x0001;delay(100);*led=0x0000;delay(100);
                     *led=0x8000;delay(100);
*led=0x0000;delay(100);
*led=0x8000;delay(100);*led=0x0000;delay(100);
                     *led=0x8000;delay(100);
*led=0x0000;delay(100);
*led=0x8000;delay(100);*led=0x0000;delay(100);
                     *led=0x8000;delay(100);
*led=0x0000;delay(100);
*led=0x8000;delay(100);*led=0x0000;delay(100);
                     *led=0x803F;delay(100);
*led=0x0000;delay(100);
*led=0x803F;delay(100);
                     *led=0x0000;delay(100);
                     *led=0x0000;delay(200);
				//i
				     *led=0x0000;delay(100);
                     *led=0x0000;delay(100);
*led=0x0000;delay(100);
*led=0x0000;delay(100);
                     *led=0x0000;delay(100);
*led=0x0000;delay(100);
*led=0x0000;delay(100);
                     *led=0x983F;delay(100);
*led=0x0000;delay(100);
*led=0x983F;delay(100);*led=0x0000;delay(100);
                     *led=0x983F;delay(100);
*led=0x0000;delay(100);
*led=0x983F;delay(100);
                     *led=0x0000;delay(100);
*led=0x0000;delay(100);
*led=0x0000;delay(100);
                     *led=0x0000;delay(100);
*led=0x0000;delay(100);
                     *led=0x0000;delay(100);
                     *led=0x0000;delay(200);
				//c
				     *led=0x0000;delay(100);
                     *led=0x001F;delay(100);
*led=0x0000;delay(100);
*led=0x001F;delay(100);*led=0x0000;delay(100);
                     *led=0x8030;delay(100);
*led=0x0000;delay(100);
*led=0x8030;delay(100);*led=0x0000;delay(100);
                     *led=0x8020;delay(100);
*led=0x0000;delay(100);
*led=0x8020;delay(100);*led=0x0000;delay(100);
                     *led=0x8020;delay(100);
*led=0x0000;delay(100);
*led=0x8020;delay(100);*led=0x0000;delay(100);
                     *led=0x8011;delay(100);
*led=0x0000;delay(100);
*led=0x8011;delay(100);*led=0x0000;delay(100);
                     *led=0x0019;delay(100);
*led=0x0000;delay(100);
*led=0x0019;delay(100);
                     *led=0x0000;delay(100);
                     *led=0x0000;delay(500);
				//o
				     *led=0x0000;delay(100);
                     *led=0x001F;delay(100);
*led=0x0000;delay(100);
*led=0x001F;delay(100);*led=0x0000;delay(100);
                     *led=0x8010;delay(100);
*led=0x0000;delay(100);
*led=0x8010;delay(100);*led=0x0000;delay(100);
                     *led=0x8020;delay(100);
*led=0x0000;delay(100);
*led=0x8020;delay(100);*led=0x0000;delay(100);
                     *led=0x8020;delay(100);
*led=0x0000;delay(100);
*led=0x8020;delay(100);*led=0x0000;delay(100);
                     *led=0x8011;delay(100);
*led=0x0000;delay(100);
*led=0x8011;delay(100);*led=0x0000;delay(100);
                     *led=0x001F;delay(100);
*led=0x0000;delay(100);
*led=0x001F;delay(100);
                     *led=0x0000;delay(100);
					 *led=0x0000;delay(200);	 
			    //r
				     *led=0x0000;delay(100);
                     *led=0x0000;delay(100);
*led=0x0000;delay(100);
*led=0x0000;delay(100);
                     *led=0x803F;delay(100);
*led=0x0000;delay(100);
*led=0x803F;delay(100);*led=0x0000;delay(100);
                     *led=0x0001;delay(100);
*led=0x0000;delay(100);
*led=0x0001;delay(100);*led=0x0000;delay(100);
                     *led=0x8000;delay(100);
*led=0x0000;delay(100);
*led=0x8000;delay(100);*led=0x0000;delay(100);
                     *led=0x8000;delay(100);
*led=0x0000;delay(100);
*led=0x8000;delay(100);
                     *led=0x0000;delay(100);
*led=0x0000;delay(100);
*led=0x0000;delay(100);
                     *led=0x0000;delay(100);
                     *led=0x0000;delay(200);
				//e
				     *led=0x0000;delay(100);
                     *led=0x001F;delay(100);
*led=0x0000;delay(100);
*led=0x001F;delay(100);
                     *led=0x8012;delay(100);
*led=0x0000;delay(100);
*led=0x8012;delay(100);*led=0x0000;delay(100);
                     *led=0x8022;delay(100);
*led=0x0000;delay(100);
*led=0x8022;delay(100);*led=0x0000;delay(100);
                     *led=0x8022;delay(100);
*led=0x0000;delay(100);
*led=0x8022;delay(100);*led=0x0000;delay(100);
                     *led=0x8033;delay(100);
*led=0x0000;delay(100);
*led=0x8033;delay(100);*led=0x0000;delay(100);
                     *led=0x001B;delay(100);
*led=0x0000;delay(100);
*led=0x001B;delay(100);
                     *led=0x0000;delay(100);
                     *led=0x0000;delay(200);
				//else *led=*led<<1;
		}
		
}
				
	
