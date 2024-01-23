/***************STM32F103C8T6**********************
 * �ļ���  ��led.c
 *          
 * ʵ��ƽ̨��STM32F103C8T6
 * Ӳ�����ӣ�LED�˿�PC13,PB12��
 * ��ע    ���޸�led�˿�ʱҪͬʱ�޸�gpio��pin

********************LIGEN*************************/

#include "led.h"
#include "delay.h"

#define LED GPIO_Pin_8

 /***************  ����LED�õ���I/O�� *******************/
void LED_GPIO_Config(void)	
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); // ʹ�ܶ˿�ʱ��  
  GPIO_InitStructure.GPIO_Pin = LED;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);  //��ʼ���˿�
  GPIO_SetBits(GPIOB, LED);	 // �ر�����LED
}
void LED_Toggle(void)
{
	GPIO_WriteBit(GPIOB, LED, (BitAction)((1-GPIO_ReadOutputDataBit(GPIOB, LED))));//led��ƽ��ת
}
void LED_On()
{
	GPIO_WriteBit(GPIOB, LED,(BitAction)0);
}
void LED_Off()
{
	GPIO_WriteBit(GPIOB, LED,(BitAction)1);
}

void LED_Twinkle()
{
	LED_On();
	Delay_ms(10);
	LED_Off();
}
