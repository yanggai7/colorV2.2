#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
#define u16 uint16_t
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/4
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//********************************************************************************
void TIM2_ch1_PWM_Init(u16 CCRx);
void TIM2_ch2_PWM_Init(u16 CCRx);
void TIM2_ch3_PWM_Init(u16 CCRx);
void TIM2_ch4_PWM_Init(u16 CCRx);

#endif
