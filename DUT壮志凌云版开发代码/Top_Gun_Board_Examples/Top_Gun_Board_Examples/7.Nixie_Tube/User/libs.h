#ifndef _LIBS_H_
#define _LIBS_H_

#include "stdint.h"

extern void Refresh_LED(uint16_t state); // ˢ��LED�ƣ�0��1��
extern void Refresh_LED_Neg(uint16_t state); // ˢ��LED�ƣ�0��1����
extern void Refresh_Display(uint8_t code, uint8_t dot, uint8_t id, uint16_t brightness); // ˢ�������
extern void Clear_Display(); // ���������

#endif
