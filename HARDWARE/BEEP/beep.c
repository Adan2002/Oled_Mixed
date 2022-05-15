#include "beep.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK NANO STM32开发板
//蜂鸣器驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2018/3/27
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2018-2028
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   
	    
//蜂鸣器初始化
void BEEP_Init(void)
{
 	
  RCC->APB2ENR|=1<<3;    //使能PORTB时钟	   
  GPIOB->CRH&=0XFFFFFFF0; 
  GPIOB->CRH|=0X00000003;//PB8推挽输出   		
  GPIOB->ODR|=1<<8;//PB8 输出高电平	
	
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






