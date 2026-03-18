#ifndef __CONTROL_H
#define __CONTROL_H

#define Angle1_OFF  42
#define Angle1_ON  138
#define Angle2_OFF 138
#define Angle2_ON   42

//由于开关的频率不高，这里方便起见用的阻塞式控制开关复位
void Control_Init(void);
void Control_OFF1(void);
void Control_OFF2(void);
void Control_OFF_Together(void);
void Control_ON1(void);
void Control_ON2(void);
void Control_ON_Together(void);


#endif
