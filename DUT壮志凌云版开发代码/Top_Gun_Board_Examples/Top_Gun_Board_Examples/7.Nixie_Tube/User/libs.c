/***************************************************************************
**   					             ��������ѧ ��BUGս��
**   					               �������ƣ����Լ���!
**-------------------------------------------------------------------------
** ��    Ŀ��   STM32G0_Board
** �� �� ����   libs.c
** �ļ�˵����   �̳̲��Գ���
**-------------------------------------------------------------------------
**						*�޶�*
**	*�汾*							*�޸�����*							*�޸���*      			 *����*
**	 1.0							   ��ʼ�汾						     ���Ӻ�     	     2022-09-26
***************************************************************************/

#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "stdint.h"
#include "test.h"
#include "libs.h"

void Refresh_Display(uint8_t code, uint8_t dot, uint8_t id, uint16_t brightness); // ˢ�������
void Clear_Display(); // ���������

/***********************************************************************
** �� �� ���� Get_Bit()
** ����˵���� ��ʱ���жϻص�������������ʱ����������
**---------------------------------------------------------------------
** ��������� ��
** ���ز����� ��
***********************************************************************/
uint8_t Get_Bit(uint16_t num, uint8_t bit_id) // id��ʾ������λ��λ�ã���0��ʼ�����������0b111101�ĵ�0λ��1����1λ��0����2~5λΪ1
{
  return (num >> bit_id) & 0b01;
}

/***********************************************************************
** �� �� ���� Clear_Display()
** ����˵���� ���������
**---------------------------------------------------------------------
** ��������� ��
** ���ز����� ��
***********************************************************************/
void Clear_Display()
{
  HAL_GPIO_WritePin( Display_A_GPIO_Port,  Display_A_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( Display_B_GPIO_Port,  Display_B_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( Display_C_GPIO_Port,  Display_C_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( Display_D_GPIO_Port,  Display_D_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( Display_E_GPIO_Port,  Display_E_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( Display_F_GPIO_Port,  Display_F_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( Display_G_GPIO_Port,  Display_G_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin( Display_DP_GPIO_Port,  Display_DP_Pin, GPIO_PIN_SET);
}

/***********************************************************************
** �� �� ���� Refresh_Display(uint8_t code, uint8_t id)
** ����˵���� �������ʾ
**---------------------------------------------------------------------
** ��������� �������ģ�������������ڼ�λ������
** ���ز����� ��
***********************************************************************/
void Refresh_Display(uint8_t code, uint8_t dot, uint8_t id, uint16_t brightness)
{
  code &= ~(dot << 5);
  if(id == 2)
  {
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 1000 - brightness);
  }
  else
  {
    htim1.Instance->CNT = 996;
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 1000);

  }
  if(id == 1)
  {
    __HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, brightness);
  }
  else
  {
    __HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, 0);

  }

  if(id == 0)
  {
    __HAL_TIM_SetCompare(&htim16, TIM_CHANNEL_1, brightness);

  }
  else
  {
    __HAL_TIM_SetCompare(&htim16, TIM_CHANNEL_1, 0);
  }
  HAL_GPIO_WritePin( Display_A_GPIO_Port,  Display_A_Pin, Get_Bit(code, 7));
  HAL_GPIO_WritePin( Display_B_GPIO_Port,  Display_B_Pin, Get_Bit(code, 6));
  HAL_GPIO_WritePin( Display_C_GPIO_Port,  Display_C_Pin, Get_Bit(code, 5));
  HAL_GPIO_WritePin( Display_D_GPIO_Port,  Display_D_Pin, Get_Bit(code, 4));
  HAL_GPIO_WritePin( Display_E_GPIO_Port,  Display_E_Pin, Get_Bit(code, 3));
  HAL_GPIO_WritePin( Display_F_GPIO_Port,  Display_F_Pin, Get_Bit(code, 2));
  HAL_GPIO_WritePin( Display_G_GPIO_Port,  Display_G_Pin, Get_Bit(code, 1));
  HAL_GPIO_WritePin( Display_DP_GPIO_Port,  Display_DP_Pin, Get_Bit(code, 0));
}


