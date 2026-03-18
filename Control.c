#include "stm32f10x.h"                  // Device header
#include "servo.h"
#include "Delay.h"

#define Angle1_OFF  42
#define Angle1_ON  138
#define Angle2_OFF 138
#define Angle2_ON   42

void Control_Init(void)
{
	Servo_Init();
	Servo_SetAngle1(90);
	Servo_SetAngle2(90);
}

void Control_OFF1(void)
{
	Servo_SetAngle1(Angle1_OFF);//这里修改关灯参数，下面同
	Delay_ms(1000);
	Servo_SetAngle1(90);

}
void Control_OFF2(void)
{
	Servo_SetAngle2(Angle2_OFF);
	Delay_ms(1000);
	Servo_SetAngle2(90);
}

void Control_OFF_Together(void)
{
	Servo_SetAngle1(Angle1_OFF);
	Servo_SetAngle2(Angle2_OFF);
	Delay_ms(1000);
	Servo_SetAngle1(90);
	Servo_SetAngle2(90);	
}
void Control_ON1(void)
{
	Servo_SetAngle1(Angle1_ON);//这里修改开灯参数，下面同
	Delay_ms(1000);
	Servo_SetAngle1(90);

}
void Control_ON2(void)
{
	Servo_SetAngle2(Angle2_ON);
	Delay_ms(1000);
	Servo_SetAngle2(90);
}

void Control_ON_Together(void)
{
	Servo_SetAngle1(Angle1_ON);
	Servo_SetAngle2(Angle2_ON);
	Delay_ms(1000);
	Servo_SetAngle1(90);
	Servo_SetAngle2(90);	
}
