#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "control.h"

int main(void)
{
	/*模块初始化*/
	OLED_Init();
	LED_Init();	
	Control_Init();
	
	while (1)
	{
		Control_OFF_Together();
		Control_ON_Together();
		Delay_ms(1000);
	}

}
