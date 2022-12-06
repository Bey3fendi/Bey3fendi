#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "math.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"
#include "driverlib/timer.h"
#include "driverlib/adc.h"

//int SReferans=0;    SORU1(50 PUAN)
//int tursayisi;
//
//void GPIOKesmesi(void)
//{
//    if(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_4)==0)
//    {         //start ile enerjiyi verme
//        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_0, 1);
//    }
//
//    if(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_5)==0)
//    {         //start ile enerjiyi verme
//        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_0, 0);
//    }
//
//    if(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_1)==0)
//    {         //start ile enerjiyi verme
//        tursayisi=tursayisi+1;
//    }
//
//   GPIOIntClear(GPIO_PORTA_BASE, GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5);
//
//
//}
//
//
//void TIMERKesmesi(void)
//{
//    if(tursayisi!=SReferans)
//    {
//        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);
//        tursayisi=0;
//    }
//
//    if(tursayisi==SReferans)
//    {
//        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 8);
//        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_0, 0);
//    }
//    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
//
//}
//
//
//
//
//
//
//
//int main(void)
//{
//    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
//    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3);
//    GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5);
//    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
//    void GPIOPadConfigSet(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32Strength, uint32_t ui32PadType);
//    long a=SysCtlClockGet();
//    IntMasterEnable();
//    IntEnable(INT_GPIOA);
//    IntEnable(INT_TIMER0A);
//    GPIOIntTypeSet(GPIO_PORTA_BASE, GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5,GPIO_FALLING_EDGE );
//    GPIOIntRegister(GPIO_PORTA_BASE, GPIOKesmesi);
//    GPIOIntEnable(GPIO_PORTA_BASE, GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5);
//    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
//    TimerEnable(TIMER0_BASE, TIMER_A);
//    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()-1);//?????????
//    TimerIntRegister(TIMER0_BASE, TIMER_A, TIMERKesmesi);
//
//
//
//    while(1){SReferans=GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7)&0b00001111;//???}
//
//
//
//
//}
