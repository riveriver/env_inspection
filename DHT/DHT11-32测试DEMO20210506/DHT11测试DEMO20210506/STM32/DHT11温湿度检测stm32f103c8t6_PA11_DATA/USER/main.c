/***************STM32F103C8T6**********************
 * �ļ���  ��main.c
 * ����    ��dht11������
 * ��ע    : dht11�¶�ʪ�ȴ�����
 * �ӿ�    ���ο�dht11.c

********************LIGEN*************************/

#include "stm32f10x.h"
#include "led.h"
#include "usart1.h"
#include "delay.h"
#include "dht11.h"

u8 temp;
u8 humi;

int main(void)
{ 
	
  SystemInit();//����ϵͳʱ��Ϊ72M	
	LED_GPIO_Config();//led��ʼ��
	USART1_Config();//���ڳ�ʼ��
	Delay_init(72);
	printf("Start \n");
	while(DHT11_Init())
	{
		printf("DHT11 Error \r\n");
		Delay_ms(1000);
	}
	
  while (1)
  {
		DHT11_Read_Data(&temp,&humi);//
		printf("temp %d ,humi %d\r\n",temp,humi);
		LED_Toggle();
		Delay_ms(1000);
  }
}



