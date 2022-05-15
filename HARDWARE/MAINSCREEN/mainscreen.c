#include "mainscreen.h"
#include "oled.h"
#include "key.h"
#include "delay.h"

void showMainscreen(void){
	#ifndef __OLED_INIT__
	#define __OLED_INIT__
	OLED_Init();
	#endif /* __OLED_INIT__ */
	OLED_ShowString(0, 0, "Made by Guo", 16);  
	OLED_ShowString(12, 16, "1. LED TWINKLE", 12);  
	OLED_ShowString(12, 28, "2. BEEP MUSIC", 12);  
	OLED_ShowString(12, 40, "3. TEMPER DISPLAY", 12);  
	OLED_ShowString(12, 52, "4. CALCULATOR", 12);  
	OLED_Refresh_Gram();
}


void showLedScreen(void){
	#ifndef __OLED_INIT__
	#define __OLED_INIT__
	OLED_Init();
	#endif /* __OLED_INIT__ */
	OLED_ShowString(0, 0, "Made by Guo", 16);  
	OLED_ShowString(12, 16, "1. LED TWINKLE", 12);  
	OLED_ShowString(12, 28, "2. WAVE LIGHTEN", 12);   
	OLED_Refresh_Gram();
}


void showBeepScreen(void){
	#ifndef __OLED_INIT__
	#define __OLED_INIT__
	OLED_Init();
	#endif /* __OLED_INIT__ */
	OLED_ShowString(0, 0, "Made by Guo", 16);  
	OLED_ShowString(12, 16, "1. XiaoXingXing", 12);  
	OLED_ShowString(12, 28, "2. LiangZhiLaoHu", 12);   
	OLED_Refresh_Gram();
}


void showTemperScreen(void){
	#ifndef __OLED_INIT__
	#define __OLED_INIT__
	OLED_Init();
	#endif /* __OLED_INIT__ */
	OLED_ShowString(0, 0, "Made by Guo", 16);  
	OLED_ShowString(12, 16, "Temperature: ", 12);  
	OLED_ShowString(12, 28, "Humidity: ", 12);   
	OLED_ShowString(12, 40, "Set Alarm Temper: ", 12);
	OLED_ShowString(12, 52, "30", 12);
	OLED_Refresh_Gram();
}


