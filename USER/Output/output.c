#include "output.h"


/*********************************************************************
 * @Function    Output_Init
 * @brief       Init the SCRx output and the run relay output and fault 
                relay output
 * @param[in]   None
 * @return      None
 **********************************************************************/
void Output_Init(void){
    PINSEL_CFG_Type PinCfg;
    
    //Init the SCRx output
    PinCfg.Funcnum = 0;
    PinCfg.OpenDrain = 0;
    PinCfg.Pinmode = 0;

    //No.59 SCR5 P0[19]
    PinCfg.Portnum = 0;
    PinCfg.Pinnum = 19;
    PINSEL_ConfigPin(&PinCfg);
    
    //No.60 SCR3 P0[18]
    PinCfg.Portnum = 0;
    PinCfg.Pinnum = 18;
    PINSEL_ConfigPin(&PinCfg);

    //No.61 SCR1 P0[17]
    PinCfg.Portnum = 0;
    PinCfg.Pinnum = 17;
    PINSEL_ConfigPin(&PinCfg);

    //No.62 SCR2 P0[15]
    PinCfg.Portnum = 0;
    PinCfg.Pinnum = 15;
    PINSEL_ConfigPin(&PinCfg);
    
    //No.63 SCR6 P0[16]
    PinCfg.Portnum = 0;
    PinCfg.Pinnum = 16;
    PINSEL_ConfigPin(&PinCfg);
    
    //No.64 SCR4 P2[9]
    PinCfg.Portnum = 2;
    PinCfg.Pinnum = 9;
    PINSEL_ConfigPin(&PinCfg);
    
    //Defined as output
    GPIO_SetDir(0, (1<<16)|(1<<17)|(1<<15)|(1<<18)|(1<<19),1);
    GPIO_SetDir(2, (1<<9),1);
    
    //Init the value
    GPIO_ClearValue(0, (1<<16)|(1<<17)|(1<<15)|(1<<18)|(1<<19));
    GPIO_ClearValue(2, (1<<9));
    
    //Init the Run-Relay output
    //No.57 P0[21]
    PinCfg.Portnum = 0;
    PinCfg.Pinnum = 21;
    PINSEL_ConfigPin(&PinCfg);

    //Init the Fault-Relay output
    //No.56 P0[22]
    PinCfg.Portnum = 0;
    PinCfg.Pinnum = 22;
    PINSEL_ConfigPin(&PinCfg);
    
    //Defined as output
    GPIO_SetDir(0, (1<<21)|(1<<22),1);
    
    //Init the value
    GPIO_ClearValue(0, (1<<21)|(1<<22));

}

/*********************************************************************
 * @Function    Output_Triggle_Set
 * @brief       Set the SCRx output as high level
 * @param[in]   SCRx: Should be SCR1/SCR2/SCR3/SCR4/SCR5/SCR6
 * @return      None
 **********************************************************************/
void Output_Triggle_Set(TRIGGLE_PORT SCRx){
    switch (SCRx){
       case SCR1:
         GPIO_SetValue(0,(1<<17));
         break;
       case SCR2:
         GPIO_SetValue(0,(1<<15));
         break;
       case SCR3:
         GPIO_SetValue(0,(1<<18));
         break;
       case SCR4:
         GPIO_SetValue(2,(1<<9));
         break;
       case SCR5:
         GPIO_SetValue(0,(1<<19));
         break;
       case SCR6:
         GPIO_SetValue(0,(1<<16));
         break;
       default:
         break;
    }
}
/*********************************************************************
 * @Function    Output_Triggle_Clear
 * @brief       Set the SCRx output as low level
 * @param[in]   SCRx: Should be SCR1/SCR2/SCR3/SCR4/SCR5/SCR6
 * @return      None
 **********************************************************************/
void Output_Triggle_Clear(TRIGGLE_PORT SCRx){
       switch (SCRx){
       case SCR1:
         GPIO_ClearValue(0,(1<<17));
         break;
       case SCR2:
         GPIO_ClearValue(0,(1<<15));
         break;
       case SCR3:
         GPIO_ClearValue(0,(1<<18));
         break;
       case SCR4:
         GPIO_ClearValue(2,(1<<9));
         break;
       case SCR5:
         GPIO_ClearValue(0,(1<<19));
         break;
       case SCR6:
         GPIO_ClearValue(0,(1<<16));
         break;
       default:
         break;
    }
}   

/*********************************************************************
 * @Function    Output_Run_Relay
 * @brief       Set the Run_Relay output level
 * @param[in]   status: true  : output high level
                        false : output low level
 * @return      None 
 **********************************************************************/
void Output_Run_Relay(bool status){
    if (status){    
        GPIO_SetValue(0, (1<<21));
    }
    else{
        GPIO_ClearValue(0, (1<<21));
    }
}

/*********************************************************************
 * @Function    Output_Fault_Relay
 * @brief       Set the Fault_Relay output level
 * @param[in]   status: true  : output high level
                        false : output low level
 * @return      None 
 **********************************************************************/
void Output_Fault_Relay(bool status){
    if (status){    
        GPIO_SetValue(0, (1<<22));
    }
    else{
        GPIO_ClearValue(0, (1<<22));
    }
}