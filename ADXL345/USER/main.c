#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "adxl345.h"

int main(void)
 {		
 	u8 t=0;
	float x,y,z;  	    
	float angx,angy,angz; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	delay_init();	    	 //延时函数初始化	  
	uart_init(115200);	 //串口初始化为115200
	while(ADXL345_Init())
	{
		 printf("init_fail\r\n");
	}
  while(1)
	{

			//得到X,Y,Z轴的加速度值(原始值)
			ADXL345_Read_Average(&x,&y,&z,10);	//读取X,Y,Z三个方向的加速度值 
		
 			//得到角度
			angx=ADXL345_Get_Angle(x,y,z,1);    
			angy=ADXL345_Get_Angle(x,y,z,2);   
			angz=ADXL345_Get_Angle(x,y,z,0);      
	      
      trans(&x,&y,&z);
		  printf("x:%f,y:%f,z:%f,angx:%f,angy:%f,angz:%f\r\n",x,y,z,angx,angy,angz);
		  delay_ms(100);

	}	 
} 

