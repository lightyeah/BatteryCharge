#include "rit_test.h"
#include "lpc17xx_pinsel.h"

uint32_t count;

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

	GPIO_SetDir(0, (1<<0)|(1<<1)|(1<<2)|(1<<3), 1);           /* LEDs on PORT0[0123] defined as Output    */
	GPIO_SetValue(0, (1<<0)|(1<<1)|(1<<2)|(1<<3));



}

// void Pluse_SetOutput(void){

// }

// void Pluse_CleanOutput(void){

// }

void RIT_Test_Init(void){
	NVIC_SetPriorityGrouping(4);  
	NVIC_SetPriority(RIT_IRQn, 0);
	RIT_Init(LPC_RIT);
	RIT_TimerConfig(LPC_RIT, 5);
	RIT_Cmd(LPC_RIT,ENABLE);
	NVIC_EnableIRQ(RIT_IRQn);
	count = 0;
}
void RIT_IRQHandler(void){
	count = count + 1;
	if(count == 20000){
		count = 0;
//		Pluse_CleanOutput();
		GPIO_SetValue(0, (1<<0)|(1<<1)|(1<<2)|(1<<3));
	}
	else if(count == 10000){
		GPIO_ClearValue(0, (1<<0)|(1<<1)|(1<<2)|(1<<3));
//		Pluse_SetOutput();
	}

}