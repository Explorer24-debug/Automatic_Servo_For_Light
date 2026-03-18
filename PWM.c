#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	//时基单元和GPIO初始化（这里不需要中断控制）*********************
	//基本的RCC时钟控制
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//引脚重映射（注意重映射引脚应该在初始化GPIO前）
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//定时器为片上外设，需要复用模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	
	//时钟源选择，不写一般默认选择内部时钟
	TIM_InternalClockConfig(TIM2);
	
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 20000-1;//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72-1;//PSC
	//注意预分频器和计数器都有一个数的偏差，所以再多减了个一
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	//这里用得通用定时器，没有高级定时器特有的重复计数器，这里给0
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	TIM_Cmd(TIM2,ENABLE);
	//*********************************************************


	//输出比较单元初始化*******************************************
	TIM_OCInitTypeDef TIM_OCInitStructure;
	//为了避免无意使用高级定时器，却由于没有指定相关属性，
	//这里对没有用的也配置一下,直接使用官方给的函数对该结
	//构体先初始化，再在后面改以下属性
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity =TIM_OCPolarity_High ;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;//CCR
	
	//初始化输出比较的通道一和二并使能预装载，减少pwm波形毛刺，提高控制精度
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC2Init(TIM2,&TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM2,ENABLE);
	
	//*********************************************************
}

void PWM_SetCompare1(uint16_t Compare1)
{
	TIM_SetCompare1(TIM2,Compare1);
}

void PWM_SetCompare2(uint16_t Compare2)
{
	TIM_SetCompare2(TIM2,Compare2);
}
