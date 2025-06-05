#include "buzzer.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;
void buzzer_on(uint16_t psc, uint16_t pwm)
{
	//���÷�Ƶ
	__HAL_TIM_PRESCALER(&htim1, psc);
	//���� PWM ��ռ�ձ�
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, pwm);
}
void buzzer_off(void)
{
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 0);
}