#include <stdio.h>
#include <stdio.h>
void delay(int t)
    {
         int  i;
         for(;t>0;t--) 
        for(i=0;i<200;i++);
    }
void main()
{
	    int led_data[60];
		int j=0;
		led_data[j++]=0x801F;
		led_data[j++]=0x0030;
		led_data[j++]=0x0020;
		led_data[j++]=0x0030;
		led_data[j++]=0x0018;
		led_data[j++]=0x803F;
		led_data[j++]=0x0000;
		led_data[j++]=0x0000;
		led_data[j++]=0x0000;
		led_data[j++]=0x803F;
		led_data[j++]=0x0001;
		led_data[j++]=0x8000;
		led_data[j++]=0x8000;
		led_data[j++]=0x8000;
		led_data[j++]=0x803F;
		led_data[j++]=0x0000;
		led_data[j++]=0x0000;
		led_data[j++]=0x0000;
		led_data[j++]=0x0000;
                led_data[j++]=0x983F;
                led_data[j++]=0x983F;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;
                led_data[j++]=0x001F;
                led_data[j++]=0x8030;
                led_data[j++]=0x8020;
                led_data[j++]=0x8020;
                led_data[j++]=0x8011;
                led_data[j++]=0x0019;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;
                led_data[j++]=0x001F;
                led_data[j++]=0x8010;
                led_data[j++]=0x8020;
                led_data[j++]=0x8011;
                led_data[j++]=0x001F;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;
                led_data[j++]=0x803F;
                led_data[j++]=0x0001;
                led_data[j++]=0x8000;
                led_data[j++]=0x8000;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;
                led_data[j++]=0x001F;
                led_data[j++]=0x8012;
                led_data[j++]=0x8022;
                led_data[j++]=0x8033;
                led_data[j++]=0x001B;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;
                led_data[j++]=0x0000;


        int *led =(int *)0x60010000;
	    int *led_tri =(int *)0x60010004;
		*led_tri=0x0000;
		while (1)
		{
			*led=0x0000;
			for(int j=0;j<56;j++)
			{
				for(int i=0;i<10;i++)
				{
					*led=0x0000;delay(10);
					*led=led_data[j];delay(10);
				}
			}
			while(1);
				//else *led=*led<<1;
		}
		
}
