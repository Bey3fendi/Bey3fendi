#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
//#include "driverlib/gpio.c"
#include "math.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"
#include "driverlib/timer.h"
#include "inc/hw_sysctl.h"
#include "lcd.h"





//int a=2;
    int saniye=0;
    int dakika=0;
    int saat=0;

void Timerkesmefonk(void)
{
int saniyeonlar=saniye/10;
int saniye2=48+saniyeonlar;
int saniyebirler=saniye%10;
int saniye1=48+saniyebirler;
int dakikaonlar=dakika/10;
int dakika2=48+dakikaonlar;
int dakikabirler=dakika%10;
int dakika1=48+dakikabirler;
int saatonlar=saat/10;
int saat2=48+saatonlar;
int saatbirler=saat%10;
int saat1=48+saatbirler;

        //a=~a;
        //GPIOPinWrite(GPIO_PORTF_BASE, 2,2);
        //GPIOPinWrite(GPIO_PORTF_BASE, 2,GPIOPinRead(GPIO_PORTF_BASE, 2));
        saniye++;

        if(saniye==60)
        {
         saniye=0;
         dakika++;
        }if(dakika==60)
        {
         dakika=0;
         saat++;
        }if(saat==24)
        {
            saat=0;
        }





LcdGotoXY(2, 5);
LcdYaz(saat2);
LcdGotoXY(2, 6); //SAAT
LcdYaz(saat1);

LcdGotoXY(2, 7); //NOKTA
LcdYaz(0x2E);

LcdGotoXY(2, 8);
LcdYaz(dakika2);
LcdGotoXY(2, 9); //DAKİKA
LcdYaz(dakika1);

LcdGotoXY(2, 10); //NOKTA
LcdYaz(0x2E);

LcdGotoXY(2, 11);
LcdYaz(saniye2); //SANİYE
LcdGotoXY(2, 12);
LcdYaz(saniye1);




//LCDYAZLAR VB. BURADA OLACAK ZATEN. (ALT SATIRDA YAZSIN)
        TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);


}


int main(void)
{
    Lcdilkayar();
    LcdGotoXY(1, 2);
    LcdYaz(0x46);
    LcdYaz(0x55);
    LcdYaz(0x52);
    LcdYaz(0x4b);
    LcdYaz(0x41);
    LcdYaz(0x4e);
    LcdGotoXY(1, 9);
    LcdYaz(0x4f);
    LcdYaz(0x5a);
    LcdYaz(0x44);
    LcdYaz(0x45);
    LcdYaz(0x4d);
    LcdYaz(0x49);
    LcdYaz(0x52);
SysCtlDelay(5000000);
SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_RCC_XTAL_16MHZ|SYSCTL_OSC_MAIN);//40MHZ
long a=SysCtlClockGet();
//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);

//GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, 14);

IntMasterEnable();//SETB EA
IntEnable(INT_TIMER0A);//GLOBAL TIMER KESMESİ AYARLARI

TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC); //timer'ı konfigüre ederek kullanım şeklimizi belirledik
TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()-1);//ilk degeri girdik timer'a
TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);//0 dan -1 olunca timeout oluşturduk.
TimerEnable(TIMER0_BASE, TIMER_A);//setb tr0

//TimerIntRegister(ui32Base, ui32Timer, pfnHandler)//ccs.c ayarlarını yapmadan
//bu hazır fonksiyonu kullanabilirdin bunun yerine ccs.c de kesme fonksiyonumuzu
//deklare ettik ve main.c ye aktardık kütüphanelerin üstünde. ama bu apili koddur
//o yüzden apisiz yöntemi tercih etmek daha mantıklı

while(1);
}

//6 adet timer vardır=timer0=>timer5
//
