#ifndef __BEEP_H
#define __BEEP_H	 
#include "sys.h"
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

//�������˿ڶ���
#define BEEP PBout(8)	// BEEP,�������ӿ�		

//const double mDo = 1046;
//const double mRe = 1175;
//const double mMi = 1318;
//const double mFa = 1397;
//const double mSol = 1568;
//const double mLa = 1760;
//const double mSi = 1967;

void BEEP_Init(void);	//��ʼ��
void beepPlay(double f, double time);
void Music1(void);
		 				    
#endif

