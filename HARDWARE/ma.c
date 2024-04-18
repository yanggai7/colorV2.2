#include "usart.h"
#include "ma.h"

void TIM2_ch1_PWM_Init(u16 CCRx)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //TIM2_CH1
 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIO
    
   //��ʼ��TIM2
	TIM_TimeBaseStructure.TIM_Period = 2000 - 1; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =720 - 1; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
  TIM_OCInitStructure.TIM_Pulse = CCRx;            //����ռ�ձȵ���
	TIM_OC1Init(TIM2, &TIM_OCInitStructure); 
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2_CH3�ϵ�Ԥװ�ؼĴ���
 
	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIM2
	TIM_ARRPreloadConfig(TIM2, ENABLE); 
}

void TIM2_ch2_PWM_Init(u16 CCRx)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; //TIM2_CH1
 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIO
    
   //��ʼ��TIM2
	TIM_TimeBaseStructure.TIM_Period = 2000 - 1; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =720 - 1; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
  TIM_OCInitStructure.TIM_Pulse = CCRx;            //����ռ�ձȵ���
	TIM_OC2Init(TIM2, &TIM_OCInitStructure); 
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2_CH3�ϵ�Ԥװ�ؼĴ���
 
	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIM2
	TIM_ARRPreloadConfig(TIM2, ENABLE); 
}

void TIM2_ch3_PWM_Init(u16 CCRx)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //TIM2_CH1
 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIO
    
   //��ʼ��TIM2
	TIM_TimeBaseStructure.TIM_Period = 2000 - 1; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =720 - 1; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
  TIM_OCInitStructure.TIM_Pulse = CCRx;            //����ռ�ձȵ���
	TIM_OC3Init(TIM2, &TIM_OCInitStructure); 
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2_CH3�ϵ�Ԥװ�ؼĴ���
 
	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIM2
	TIM_ARRPreloadConfig(TIM2, ENABLE); 
}

void TIM2_ch4_PWM_Init(u16 CCRx)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; //TIM2_CH1
 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIO
    
   //��ʼ��TIM2
	TIM_TimeBaseStructure.TIM_Period = 2000 - 1; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =720 - 1; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
  TIM_OCInitStructure.TIM_Pulse = CCRx;            //����ռ�ձȵ���
	TIM_OC4Init(TIM2, &TIM_OCInitStructure); 
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2_CH3�ϵ�Ԥװ�ؼĴ���
 
	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIM2
	TIM_ARRPreloadConfig(TIM2, ENABLE); 
}