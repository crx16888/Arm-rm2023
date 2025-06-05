/***************************************************************************
**   					             ��������ѧ ��BUGս��
**   					               �������ƣ����Լ���!
**-------------------------------------------------------------------------
** ��    Ŀ��   STM32G0_Board
** �� �� ����   test.c
** �ļ�˵����   �̳̲��Գ���
**-------------------------------------------------------------------------
**						*�޶�*
**	*�汾*							*�޸�����*							*�޸���*      			 *����*
**	 1.0							   ��ʼ�汾						     ���Ӻ�     	     2022-09-26
***************************************************************************/

#include "main.h"
#include "gpio.h"
#include "stdint.h"
#include "test.h"

// ʹ��һ��16λ2���������16��led�Ƶ�״̬����λ����Ŵ��LED
uint16_t led_state = 0b0000000000000001;
int k = 0;

/***********************************************************************
** �� �� ���� Get_Bit()
** ����˵���� 
**---------------------------------------------------------------------
** ��������� ��
** ���ز����� ��
***********************************************************************/
uint8_t Get_Bit(uint16_t num, uint8_t bit_id) // id��ʾ������λ��λ�ã���0��ʼ�����������0b111101�ĵ�0λ��1����1λ��0����2~5λΪ1
{
  return (num >> bit_id) & 0b01;
}

/***********************************************************************
** �� �� ���� Refresh_LED(uint16_t state)
** ����˵���� ˢ��LED�Ƶ���״̬��0��1��
**---------------------------------------------------------------------
** ��������� һ��16λ������ÿ��λ��Ӧһ��LED�Ƶ�״̬
** ���ز����� ��
***********************************************************************/
void Refresh_LED(uint16_t state)
{
  HAL_GPIO_WritePin( LED1_GPIO_Port,  LED1_Pin, Get_Bit(state,  0));
  HAL_GPIO_WritePin( LED2_GPIO_Port,  LED2_Pin, Get_Bit(state,  1));
  HAL_GPIO_WritePin( LED3_GPIO_Port,  LED3_Pin, Get_Bit(state,  2));
  HAL_GPIO_WritePin( LED4_GPIO_Port,  LED4_Pin, Get_Bit(state,  3));
  HAL_GPIO_WritePin( LED5_GPIO_Port,  LED5_Pin, Get_Bit(state,  4));
  HAL_GPIO_WritePin( LED6_GPIO_Port,  LED6_Pin, Get_Bit(state,  5));
  HAL_GPIO_WritePin( LED7_GPIO_Port,  LED7_Pin, Get_Bit(state,  6));
  HAL_GPIO_WritePin( LED8_GPIO_Port,  LED8_Pin, Get_Bit(state,  7));
  HAL_GPIO_WritePin( LED9_GPIO_Port,  LED9_Pin, Get_Bit(state,  8));
  HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, Get_Bit(state,  9));
  HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, Get_Bit(state, 10));
  HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, Get_Bit(state, 11));
  HAL_GPIO_WritePin(LED13_GPIO_Port, LED13_Pin, Get_Bit(state, 12));
  HAL_GPIO_WritePin(LED14_GPIO_Port, LED14_Pin, Get_Bit(state, 13));
  HAL_GPIO_WritePin(LED15_GPIO_Port, LED15_Pin, Get_Bit(state, 14));
  HAL_GPIO_WritePin(LED16_GPIO_Port, LED16_Pin, Get_Bit(state, 15));
}

/***********************************************************************
** �� �� ���� Refresh_LED_Neg(uint16_t state)
** ����˵���� ˢ��LED�Ƶ���״̬��0��1����
**---------------------------------------------------------------------
** ��������� һ��16λ������ÿ��λ��Ӧһ��LED�Ƶ�״̬
** ���ز����� ��
***********************************************************************/
void Refresh_LED_Neg(uint16_t state)
{
  Refresh_LED(~state);
}
/***********************************************************************
** �� �� ���� Setup()
** ����˵���� �����ʼ���������ϵ��ִ��һ��
**---------------------------------------------------------------------
** ��������� ��
** ���ز����� ��
***********************************************************************/
void Setup()
{
	Refresh_LED(~0);
}

/***********************************************************************
** �� �� ���� Loop()
** ����˵���� ������ѭ���������ϵ��ѭ��ִ��
**---------------------------------------------------------------------
** ��������� ��
** ���ز����� ��
***********************************************************************/
void Loop()
{
//	Refresh_LED(~led_state);
	for(k = 0; k < 16; k++)
	{
		led_state<<=1;
		led_state++;
		Refresh_LED(led_state);
		HAL_Delay(500);
	}
	led_state = 0;
}

