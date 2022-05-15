/*
@description: A mixed function about what we have learned in the class
@author: Guo Haoran
@Data: 2022-5-15

This is task 3 of our stm32 class which is that to design a program you like. I promise that
it is completed finished by myself and it is original version.
Also, you can find it at https://github.com/Adan2002/Oled_Mixed
*/


#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"	
#include "oled.h"
#include "mainscreen.h"
#include "key.h"
#include "beep.h"
#include "dht11.h"



int main(void){
	vu8 key = 0;
	u8 mode = 0;
	u8 firstNode = 0;
	u8 secondNode = 0;
	u8 nodeFlag = 0;
	u8 cnt = 0;
	u8 cnt1 = 0;
	u8 temperFlag = 0;
	u8 temperature, humidity;
	u32 alarmTemper = 30;
	Stm32_Clock_Init(9);
	delay_init(72);	
	uart_init(72,115200);
	LED_Init();	
	OLED_Init();
	KEY_Init();
	BEEP_Init();
	DHT11_Init();
	showMainscreen();
	while(1){
		while(mode == 0){
			key = KEY_Scan(0);
			switch (key){
				case KEY1_PRES:{
					if(firstNode != 3){
						firstNode++;
					}
					break;
				}
				case KEY2_PRES:{
					OLED_Clear();
					mode = firstNode + 1;
					switch(mode){
						case 1:{
							showLedScreen();
							break;
						}
						case 2:{
							showBeepScreen();
							break;
						}
						case 3:{
							showTemperScreen();
							break;
						}
					}
					break;
				}
				case WKUP_PRES:{
					if(firstNode != 0){
						firstNode--;
					}
					break;
				}
				default:{
					if(cnt == 50){
						switch(firstNode){
							case 0:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 16, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 16, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 28, " ", 12);
								OLED_ShowString(0, 40, " ", 12);
								OLED_ShowString(0, 52, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
							case 1:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 28, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 28, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 16, " ", 12);
								OLED_ShowString(0, 40, " ", 12);
								OLED_ShowString(0, 52, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
							case 2:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 40, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 40, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 16, " ", 12);
								OLED_ShowString(0, 28, " ", 12);
								OLED_ShowString(0, 52, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
							case 3:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 52, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 52, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 16, " ", 12);
								OLED_ShowString(0, 40, " ", 12);
								OLED_ShowString(0, 28, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
						}
						cnt = 0;
					}
					++cnt;
					delay_ms(10);
				}
			}
		}
		
		while(mode == 1){
			key = KEY_Scan(0);
			switch(key){
				case KEY0_PRES:{
					mode = 0;
					secondNode = 0;
					OLED_Clear();
					showMainscreen();
					break;
				}
				case KEY1_PRES:{
					if(secondNode != 1){
						secondNode++;
					}
					break;
				}
				case KEY2_PRES:{
					if(secondNode == 0){
						u8 led_i;
						for(led_i = 0; led_i < 8; ++led_i){
							PCout(led_i) = 0;
							delay_ms(200);
						}
						delay_ms(200);
						for(led_i = 0; led_i < 8; ++led_i){
							PCout(led_i) = 1;
							delay_ms(200);
						}
					}
					if(secondNode == 1){
						u8 led_i;
						for(led_i = 0; led_i != 4; ++led_i){
							u8 led_j = led_i + 4;
							u8 led_k = 3 - led_i;
							PCout(led_k) = 0;
							PCout(led_j) = 0;
							delay_ms(200);
						}
						delay_ms(200);
						for(led_i = 0; led_i != 4; ++led_i){
							u8 led_j = led_i + 4;
							u8 led_k = 3 - led_i;
							PCout(led_k) = 1;
							PCout(led_j) = 1;
							delay_ms(200);
						}
						delay_ms(200);
						for(led_i = 0; led_i != 4; ++led_i){
							u8 led_j = led_i + 4;
							u8 led_k = 3 - led_i;
							PCout(led_k) = 0;
							PCout(led_j) = 0;
							delay_ms(200);
						}
						delay_ms(200);
						for(led_i = 0; led_i != 4; ++led_i){
							u8 led_j = led_i + 4;
							u8 led_k = 3 - led_i;
							PCout(led_k) = 1;
							PCout(led_j) = 1;
							delay_ms(200);
						}
					}
					break;
				}
				case WKUP_PRES:{
					if(secondNode != 0){
						secondNode--;
					}
					break;
				}
				default:{
					if(cnt == 50){
						switch(secondNode){
							case 0:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 16, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 16, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 28, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
							case 1:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 28, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 28, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 16, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
						}
						cnt = 0;
					}
					++cnt;
					delay_ms(10);
				}
			}
		}
		
		while(mode == 2){
			key = KEY_Scan(0);
			switch(key){
				case KEY0_PRES:{
					mode = 0;
					secondNode = 0;
					OLED_Clear();
					showMainscreen();
					break;
				}
				case KEY1_PRES:{
					if(secondNode != 1){
						secondNode++;
					}
					break;
				}
				case KEY2_PRES:{
					if(secondNode == 0){
						Music1();
					}
					break;
				}
				case WKUP_PRES:{
					if(secondNode != 0){
						secondNode--;
					}
					break;
				}
				default:{
					if(cnt == 50){
						switch(secondNode){
							case 0:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 16, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 16, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 28, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
							case 1:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 28, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 28, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 16, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
						}
						cnt = 0;
					}
					++cnt;
					delay_ms(10);
				}
			}
		}
		
		while(mode == 3){
			key = KEY_Scan(0);
			switch(key){
				case KEY0_PRES:{
					mode = 0;
					secondNode = 0;
					BEEP = 1;
					alarmTemper = 30;
					OLED_Clear();
					showMainscreen();
					break;
				}
				case KEY1_PRES:{
					if(secondNode != 3){
						secondNode++;
					}
					break;
				}
				case KEY2_PRES:{
					if(secondNode == 2 && alarmTemper != 0){
						alarmTemper -= 1;
						if(alarmTemper / 10 != 0){
							OLED_ShowNum(12, 52, alarmTemper, 2, 12);
							OLED_Refresh_Gram();
						}
						else{
							OLED_ShowString(12, 52, "        ", 12);  
							OLED_ShowNum(12, 52, alarmTemper, 2, 12);
							OLED_Refresh_Gram();
						}
					}
					if(secondNode == 3 && alarmTemper != 99){
						alarmTemper += 1;
						if(alarmTemper / 10 != 0){
							OLED_ShowNum(12, 52, alarmTemper, 2, 12);
							OLED_Refresh_Gram();
						}
					}
					break;
				}
				case WKUP_PRES:{
					if(secondNode != 0){
						secondNode--;
					}
					break;
				}
				default:{
					if(cnt == 50){
						temperFlag++;
						if(temperFlag == 4){
						if(DHT11_Read_Data(&temperature, &humidity) == 0){
							OLED_ShowString(90, 16, "     ", 12); 
							OLED_ShowString(90, 28, "     ", 12); 
							OLED_ShowNum(90, 16, (u32)temperature, 2, 12);
							OLED_ShowNum(90, 28, (u32)humidity, 2, 12);
							if(alarmTemper <= (u32)temperature){
								BEEP = !BEEP;
								u8 i;
								for(i = 0; i < 8; ++i){
									PCout(i) = !PCout(i);
								}
							}
						}
						else{
							OLED_ShowString(90, 16, "ERROR", 12); 
							OLED_ShowString(90, 28, "ERROR", 12); 
						}
						temperFlag = 0;
					}
						
						switch(secondNode){
							case 0:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 16, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 16, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 28, " ", 12);
								OLED_ShowString(0, 40, " ", 12);
								OLED_ShowString(0, 52, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
							case 1:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 28, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 28, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 16, " ", 12);
								OLED_ShowString(0, 40, " ", 12);
								OLED_ShowString(0, 52, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
							case 2:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 40, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 40, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 16, " ", 12);
								OLED_ShowString(0, 28, " ", 12);
								OLED_ShowString(0, 52, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
							case 3:{
								if(nodeFlag == 0){
									OLED_ShowString(0, 52, ">", 12);
									nodeFlag = 1;
								}
								else{
									OLED_ShowString(0, 52, " ", 12);
									nodeFlag = 0;
								}
								OLED_ShowString(0, 16, " ", 12);
								OLED_ShowString(0, 40, " ", 12);
								OLED_ShowString(0, 28, " ", 12);
								OLED_Refresh_Gram();
								break;
							}
						}
						cnt = 0;
					}
					++cnt;
					delay_ms(10);
				}
			}
		}
	}
	return 0;
}






