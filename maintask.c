/**
  ******************************************************************************
  * File Name          : maintask.c
  * Description        : Main task
  ******************************************************************************
**/
/* Includes ------------------------------------------------------------------*/
#include "maintask.h"

int maintask(void)
{
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)&ADCValue, 1);

  while (1)
  {

  }

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    float mvf=0;
    ADcomsum+=ADCValue;
    ADSampleNum++;
    if(ADSampleNum==mnum){
        mvf=(((float)ADcomsum/mnum)/4095)*inv;
        printf("AD Data = %d mV\r\n", (int)(mvf*1000));
        ADSampleNum=0;
        ADcomsum=0;
    }
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
    float mvf=0;
    ADcomsum+=ADCValue;
    ADSampleNum++;
    if(ADSampleNum==mnum){
        mvf=(((float)ADcomsum/mnum)/4095)*inv;
        printf("AD Data = %d mV\r\n", (int)(mvf*1000));
        ADSampleNum=0;
        ADcomsum=0;
    }
}

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}



