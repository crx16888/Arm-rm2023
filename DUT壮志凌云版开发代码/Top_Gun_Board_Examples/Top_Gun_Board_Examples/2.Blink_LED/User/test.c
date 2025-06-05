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

void Init_LED()
{
  // �ر�����LED��
  HAL_GPIO_WritePin( LED1_GPIO_Port,  LED1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( LED2_GPIO_Port,  LED2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( LED3_GPIO_Port,  LED3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( LED4_GPIO_Port,  LED4_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( LED5_GPIO_Port,  LED5_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( LED6_GPIO_Port,  LED6_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( LED7_GPIO_Port,  LED7_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( LED8_GPIO_Port,  LED8_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( LED9_GPIO_Port,  LED9_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED13_GPIO_Port, LED13_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED14_GPIO_Port, LED14_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED15_GPIO_Port, LED15_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED16_GPIO_Port, LED16_Pin, GPIO_PIN_SET);
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
  Init_LED();
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
  // ����LED��1
  HAL_GPIO_WritePin(LED1_GPIO_Port,  LED1_Pin, GPIO_PIN_RESET);
  // ��ʱ1��
  HAL_Delay(1000);
  // �ر�LED��1
  HAL_GPIO_WritePin(LED1_GPIO_Port,  LED1_Pin, GPIO_PIN_SET);
  // ��ʱ1��
  HAL_Delay(1000);
}
