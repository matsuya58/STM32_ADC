/**
  ******************************************************************************
  * File Name          : maintask.h
  * Description        : Main task
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/
#include "stm32xxxx_hal.h"
#include "AD_UART_cfg.h"

/* Private variables ---------------------------------------------------------*/
static int ADcomsum;
static int ADSampleNum;
static __IO uint32_t ADCValue;
extern DMA_HandleTypeDef hdma_adc1;
extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

/* Private function prototypes -----------------------------------------------*/
int maintask(void);


#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */



