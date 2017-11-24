#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "adxl345.h"

int main(void)
 {		
 	u8 t=0;
	float x,y,z;  	    
	float angx,angy,angz; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
	while(ADXL345_Init())
	{
		 printf("init_fail\r\n");
	}
  while(1)
	{

			//�õ�X,Y,Z��ļ��ٶ�ֵ(ԭʼֵ)
			ADXL345_Read_Average(&x,&y,&z,10);	//��ȡX,Y,Z��������ļ��ٶ�ֵ 
		
 			//�õ��Ƕ�
			angx=ADXL345_Get_Angle(x,y,z,1);    
			angy=ADXL345_Get_Angle(x,y,z,2);   
			angz=ADXL345_Get_Angle(x,y,z,0);      
	      
      trans(&x,&y,&z);
		  printf("x:%f,y:%f,z:%f,angx:%f,angy:%f,angz:%f\r\n",x,y,z,angx,angy,angz);
		  delay_ms(100);

	}	 
} 

