#include "rit_test.h"
#include "lpc17xx_pinsel.h"

uint32_t count;
uint32_t test_count;
uint8_t flag;
	
void Pluse_Init(void){
	PINSEL_CFG_Type PinCfg;
	PinCfg.Funcnum = 0;
	PinCfg.Pinnum = 0;
	PinCfg.Portnum = 0;	
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 1;
	PINSEL_ConfigPin(&PinCfg);	
	PinCfg.Pinnum = 2;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 3;
	PINSEL_ConfigPin(&PinCfg);
	
	PinCfg.Funcnum = 0;
	PinCfg.Pinnum = 25;
	PinCfg.Portnum = 3;	
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 26;
	PINSEL_ConfigPin(&PinCfg);

	GPIO_SetDir(3, (1<<25)|(1<<26), 1);           
	GPIO_SetValue(3, (1<<25)|(1<<26));
	
	GPIO_SetDir(0, (1<<0)|(1<<1)|(1<<2)|(1<<3), 1);           /* LEDs on PORT0[0123] defined as Output    */
	GPIO_SetValue(0, (1<<0)|(1<<1)|(1<<2)|(1<<3));
	
	//GPIO_ClearValue(0, (1<<0)|(1<<1)|(1<<2)|(1<<3));
	
}

void Pluse_SetOutput(void){
      GPIO_SetValue(3, (1<<25)|(1<<26));
}

void Pluse_CleanOutput(void){
			GPIO_ClearValue(3, (1<<25)|(1<<26));
}

void RIT_Test_Init(void){
	RIT_Init(LPC_RIT);
	RIT_Cmd(LPC_RIT,DISABLE);
	RIT_TimerConfig(LPC_RIT, 5);
	NVIC_SetPriorityGrouping(4);  
	NVIC_SetPriority(RIT_IRQn, 1);
	NVIC_EnableIRQ(RIT_IRQn);
	RIT_Cmd(LPC_RIT,ENABLE);
	count = 0;
	flag = 0;
	test_count = 0;
}
void RIT_IRQHandler(void){
	count = count + 1;
	test_count = 0;
	while(test_count <100){
		test_count++;
	}
	if(flag == 1){
		Pluse_CleanOutput();
		flag = 0;
	}
	else if(flag == 0){
		Pluse_SetOutput();
		flag = 1;
	}
	RIT_GetIntStatus(LPC_RIT);
	if(count == 40000){
		count = 0;
		GPIO_SetValue(0, (1<<0)|(1<<1)|(1<<2)|(1<<3));
	}
	else if(count == 20000){
		GPIO_ClearValue(0, (1<<0)|(1<<1)|(1<<2)|(1<<3));
	}

}