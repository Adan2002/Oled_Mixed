#include "beep.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK NANO STM32������
//��������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2018/3/27
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2018-2028
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   
	    
//��������ʼ��
void BEEP_Init(void)
{
 	
  RCC->APB2ENR|=1<<3;    //ʹ��PORTBʱ��	   
  GPIOB->CRH&=0XFFFFFFF0; 
  GPIOB->CRH|=0X00000003;//PB8�������   		
  GPIOB->ODR|=1<<8;//PB8 ����ߵ�ƽ	
	
}


void beepPlay(double f, double time){
	int feq = (int)(1 / f * 1000000);
	double feqc = 1 / f;
	double cnt = 0;
	while(feqc * cnt <= time){
		BEEP = !BEEP;
		delay_us(feq);
		++cnt;
	}
	BEEP = 1;
}


void Music1(void){
	beepPlay(1046, 0.5);
	delay_ms(100);
	beepPlay(1046, 0.5);
	delay_ms(100);
	beepPlay(1568, 0.5);
	delay_ms(100);
	beepPlay(1568, 0.5);
	delay_ms(100);
	beepPlay(1760, 0.5);
	delay_ms(100);
	beepPlay(1760, 0.5);
	delay_ms(100);
	beepPlay(1568, 0.5);
	delay_ms(200);
	
	beepPlay(1397, 0.5);
	delay_ms(100);
	beepPlay(1397, 0.5);
	delay_ms(100);
	beepPlay(1318, 0.5);
	delay_ms(100);
	beepPlay(1318, 0.5);
	delay_ms(100);
	beepPlay(1175, 0.5);
	delay_ms(100);
	beepPlay(1175, 0.5);
	delay_ms(100);
	beepPlay(1046, 0.5);
	delay_ms(200);
	
	beepPlay(1568, 0.5);
	delay_ms(100);
	beepPlay(1568, 0.5);
	delay_ms(100);
	beepPlay(1397, 0.5);
	delay_ms(100);
	beepPlay(1397, 0.5);
	delay_ms(100);
	beepPlay(1318, 0.5);
	delay_ms(100);
	beepPlay(1318, 0.5);
	delay_ms(100);
	beepPlay(1175, 0.5);
	delay_ms(200);
	
	beepPlay(1568, 0.5);
	delay_ms(100);
	beepPlay(1568, 0.5);
	delay_ms(100);
	beepPlay(1397, 0.5);
	delay_ms(100);
	beepPlay(1397, 0.5);
	delay_ms(100);
	beepPlay(1318, 0.5);
	delay_ms(100);
	beepPlay(1318, 0.5);
	delay_ms(100);
	beepPlay(1175, 0.5);
	delay_ms(200);
	
	beepPlay(1046, 0.5);
	delay_ms(100);
	beepPlay(1046, 0.5);
	delay_ms(100);
	beepPlay(1568, 0.5);
	delay_ms(100);
	beepPlay(1568, 0.5);
	delay_ms(100);
	beepPlay(1760, 0.5);
	delay_ms(100);
	beepPlay(1760, 0.5);
	delay_ms(100);
	beepPlay(1568, 0.5);
}






