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
#include "driverlib/adc.h"





uint32_t gelendeger[4];
long ort,temp;
long temp2binler;
long temp2yuzler;
long temp2onlar;
long temp2birler;
long temp2_1;
long temp2_2;
long temp2_3;
long temp2_4;

void adckesme(){

   ADCSequenceDataGet(ADC0_BASE, 2, gelendeger);
   ort=(gelendeger[0]+gelendeger[1]+gelendeger[2]+gelendeger[3])/4;
   //temp=(1475-((2475*ort)/4096))/10;
   temp=ort*3;
   temp2birler=temp%10;
   temp2_1=temp2birler+48;
   temp2onlar=(temp%100)/10;
   temp2_2=temp2onlar+48;
   temp2yuzler=(temp%1000)/100;
   temp2_3=temp2yuzler+48;
   temp2binler=temp/1000;
   temp2_4=temp2binler+48;
   LcdGotoXY(2, 1);
   LcdYaz(temp2_4);
   LcdGotoXY(2, 2);
   LcdYaz(temp2_3);
   LcdGotoXY(2, 3);
   LcdYaz(temp2_2);
   LcdGotoXY(2, 4);
   LcdYaz(temp2_1);
   ADCIntClear(ADC0_BASE, 2);
   ADCProcessorTrigger(ADC0_BASE, 2);
}









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





LcdGotoXY(2, 6);
LcdYaz(saat2);
LcdGotoXY(2, 7); //SAAT
LcdYaz(saat1);

LcdGotoXY(2, 8); //NOKTA
LcdYaz(0x2E);

LcdGotoXY(2, 9);
LcdYaz(dakika2);
LcdGotoXY(2, 10); //DAKİKA
LcdYaz(dakika1);

LcdGotoXY(2, 11); //NOKTA
LcdYaz(0x2E);

LcdGotoXY(2, 12);
LcdYaz(saniye2); //SANİYE
LcdGotoXY(2, 13);
LcdYaz(saniye1);




//LCDYAZLAR VB. BURADA OLACAK ZATEN. (ALT SATIRDA YAZSIN)
        TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);


}


int main(void)
{
    Lcdilkayar();
//    LcdGotoXY(1, 2);
//    LcdYaz(0x46);
//    LcdYaz(0x55);
//    LcdYaz(0x52);
//    LcdYaz(0x4b);
//    LcdYaz(0x41);
//    LcdYaz(0x4e);
//    LcdGotoXY(1, 9);
//    LcdYaz(0x4f);
//    LcdYaz(0x5a);
//    LcdYaz(0x44);
//    LcdYaz(0x45);
//    LcdYaz(0x4d);
//    LcdYaz(0x49);
//    LcdYaz(0x52);
SysCtlDelay(5000000);
SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_RCC_XTAL_16MHZ|SYSCTL_OSC_MAIN);//40MHZ
long a=SysCtlClockGet();
//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

//GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, 14);

IntMasterEnable();//SETB EA
IntEnable(INT_TIMER0A);//GLOBAL TIMER KESMESİ AYARLARI
IntEnable(INT_ADC0SS2);

TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC); //timer'ı konfigüre ederek kullanım şeklimizi belirledik
TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()-1);//ilk degeri girdik timer'a
TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);//0 dan -1 olunca timeout oluşturduk.
TimerEnable(TIMER0_BASE, TIMER_A);//setb tr0

ADCSequenceConfigure(ADC0_BASE, 2, ADC_TRIGGER_PROCESSOR, 0);// seq 2 kullanilacak
//       ADCSequenceStepConfigure(ADC0_BASE, 2, 0, ADC_CTL_TS);
//       ADCSequenceStepConfigure(ADC0_BASE, 2, 1, ADC_CTL_TS);
//       ADCSequenceStepConfigure(ADC0_BASE, 2, 2, ADC_CTL_TS);
//       ADCSequenceStepConfigure(ADC0_BASE, 2, 3, ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);

ADCSequenceStepConfigure(ADC0_BASE, 2, 0, ADC_CTL_CH0);
ADCSequenceStepConfigure(ADC0_BASE, 2, 1, ADC_CTL_CH0);
ADCSequenceStepConfigure(ADC0_BASE, 2, 2, ADC_CTL_CH0);
ADCSequenceStepConfigure(ADC0_BASE, 2, 3, ADC_CTL_CH0|ADC_CTL_IE|ADC_CTL_END);

ADCIntClear(ADC0_BASE, 2);
ADCIntRegister(ADC0_BASE, 2, adckesme);
ADCIntEnable(ADC0_BASE, 2);

ADCSequenceEnable(ADC0_BASE, 2);

ADCProcessorTrigger(ADC0_BASE, 2); // CEVRIM BASLADI

//TimerIntRegister(ui32Base, ui32Timer, pfnHandler)//ccs.c ayarlarını yapmadan
//bu hazır fonksiyonu kullanabilirdin bunun yerine ccs.c de kesme fonksiyonumuzu
//deklare ettik ve main.c ye aktardık kütüphanelerin üstünde. ama bu apili koddur
//o yüzden apisiz yöntemi tercih etmek daha mantıklı

while(1);
}

//6 adet timer vardır=timer0=>timer5
//
