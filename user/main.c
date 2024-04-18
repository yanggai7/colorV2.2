
#include "stm32f10x.h"
#include "config.h"
#include "sys.h"
#include "usart.h"
//#include "delay.h"
//#include "timer.c"
#include "ma.h"
#include "tcs34725.c"
#include "delay.h"
#include "arm.c"
/******************************************************************************/
void com2_order(void);
//void arm_move(float a1,float a2,float a3,float a4,float b1,float b2,float b3,float b4);
/******************************************************************************/
void delay_s(u32 i)
{
	while(i--);
}
/******************************************************************************/
void RCC_Configuration(void)
{
	RCC_DeInit();//RCC寄存器取消初始化设置
	RCC_HSEConfig(RCC_HSE_ON);//开启外部高速时钟
	RCC_WaitForHSEStartUp();//等待外部晶振启动
	FLASH_SetLatency(FLASH_Latency_2);//代码延时2周期
	FLASH_HalfCycleAccessCmd(FLASH_HalfCycleAccess_Disable);//半周期访问失能
	FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);//预取指缓存使能
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);//外部高速时钟为PLL时钟输入源，9倍频
	RCC_PLLCmd(ENABLE);//使能PLL
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//PLL作为系统时钟
	RCC_HCLKConfig(RCC_SYSCLK_Div1);//AHB 时钟 = 系统时钟
	RCC_PCLK1Config(RCC_HCLK_Div2);//APB1 时钟 = HCLK / 2,即AHB时钟的一半
	RCC_PCLK2Config(RCC_HCLK_Div1);//APB2 时钟 = HCLK，即AHB时钟
	//RCC_ADCCLKConfig(RCC_PCLK2_Div6);//ADC 时钟 = PCLK / 6，即APB2时钟，72/6=12M
	RCC_LSEConfig(RCC_LSE_OFF);//关闭外部低速时钟
}
/******************************************************************************/
void GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO, ENABLE);//使能GPIOA,GPIOB,GPIOC,AFIO;
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_4|GPIO_Pin_8|GPIO_Pin_9;        //是LED
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //复用推挽输出	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;//速度
	GPIO_Init(GPIOA, &GPIO_InitStructure);           //对选中管脚初始化
	GPIO_ResetBits(GPIOA,GPIO_Pin_6|GPIO_Pin_4|GPIO_Pin_8|GPIO_Pin_9);     
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;        
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);           
	GPIO_ResetBits(GPIOA,GPIO_Pin_5); 
}
/******************************************************************************/
/******************************************************************************/
int main(void)
{
	int i=0;
	int sp;
//	DATA arm1,arm2,arm3,arm4,arm5;
//	PTDATA parm1,parm2,parm3,parm4,parm5;
	//COLOR_RGBC red,blue,yellow;
	
//	red.r=0;red.g=0;red.b=0;red.c=0;
//	blue.r=0;blue.g=0;blue.b=0;blue.c=0;
//	yellow.r=0;yellow.g=0;yellow.b=0;yellow.c=0;
	sp=0;
	RCC_Configuration();
	GPIO_Config();
	uart_init(115200);
	delay_init();
	delay_s(0x1fffff);
	TCS34725_Init();
	TIM2_ch1_PWM_Init(sp);
  TIM2_ch2_PWM_Init(sp);
	TIM2_ch3_PWM_Init(sp);
	TIM2_ch4_PWM_Init(sp);
	//arm_init(50);
	//delay_ms(5000);
	arm_try(122,120,185,255);
	//arm_move(xz,xfz);
	while(1)
	{
				//delsy_ms(1000);
				TCS34725_GetRawData(&rgb);
//				if(i==0){
//					i=get(3);	
//				}
				//arm_try(40,100,130,240);
//		arm_move(fang,juqi);
//		//delay_ms(2000);
//		GPIO_SetBits(GPIOA,GPIO_Pin_4);
//		delay_ms(8000);
//		arm_move(fang,fang);
//		//delay_ms(2000);
//		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
//		delay_ms(8000);
				
	
		
				
	}
}


