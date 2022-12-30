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
#include "inc/hw_uart.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "lcd.h"
#include "utils/uartstdio.h"

//com4

void SetInitSettings();

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





LcdGotoXY(2, 1);
LcdYaz(saat2);
LcdGotoXY(2, 2); //SAAT
LcdYaz(saat1);

LcdGotoXY(2, 3); //NOKTA
LcdYaz(0x2E);

LcdGotoXY(2, 4);
LcdYaz(dakika2);
LcdGotoXY(2, 5); //DAKİKA
LcdYaz(dakika1);

LcdGotoXY(2, 6); //NOKTA
LcdYaz(0x2E);

LcdGotoXY(2, 7);
LcdYaz(saniye2); //SANİYE
LcdGotoXY(2, 8);
LcdYaz(saniye1);




//LCDYAZLAR VB. BURADA OLACAK ZATEN. (ALT SATIRDA YAZSIN)
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);


}

int main(void)

{
    SetInitSettings();
    while(1)
    {
       //UARTCharPut(UART0_BASE,"a");//umputty ile mikroişlemciden bilgisayar gönderilen a ları inceleyebiliriz.
        if(UARTCharsAvail(UART0_BASE))//char varmı diye sorguluyoruz. varsa karakteri al işlemleri yap.
        {
      int c= UARTCharGet(UART0_BASE);
      if(c==36){

          c=0;

              if(UARTCharsAvail(UART0_BASE)){
                  int c= UARTCharGet(UART0_BASE);// bu durumda charget bekler.
                  int d= UARTCharGet(UART0_BASE);
                  int e= UARTCharGet(UART0_BASE);
                  int f= UARTCharGet(UART0_BASE);
                  int g= UARTCharGet(UART0_BASE);
                  int h= UARTCharGet(UART0_BASE);
                  int p= UARTCharGet(UART0_BASE);
                  int s= UARTCharGet(UART0_BASE);
                  UARTCharPut(UART0_BASE, c);
                  UARTCharPut(UART0_BASE, d);
                  UARTCharPut(UART0_BASE, e);
                  UARTCharPut(UART0_BASE, f);
                  UARTCharPut(UART0_BASE, g);
                  UARTCharPut(UART0_BASE, h);
                  UARTCharPut(UART0_BASE, p);
                  UARTCharPut(UART0_BASE, s);
                  saat=(((c-48)*10)+(d-48));
                  dakika=(((f-48)*10)+(g-48));
                  saniye=(((p-48)*10)+(s-48));
//                  LcdGotoXY(2, 1);
//                  LcdYaz(c);
//                  LcdYaz(d);
//                  LcdYaz(e);
//                  LcdYaz(f);
//                  LcdYaz(g);
//                  LcdYaz(h);
//                  LcdYaz(p);
//                  LcdYaz(s);






              }



      }
      if(c==35){
          int b=1;
          c=0;
LcdGotoXY(2, 10);
          while(b>0){

              if(UARTCharsAvail(UART0_BASE)){
                  int c= UARTCharGet(UART0_BASE);// bu durumda charget bekler.
                  if(c==42)
                  {
                      b--;
                      c=0;
                  }
                  if(c>0)
                  {
                  UARTCharPut(UART0_BASE, c);
                  LcdYaz(c);
                  }

              }

          }

      }
        }
    }
}

void SetInitSettings(){
    Lcdilkayar();
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_RCC_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    long a=SysCtlClockGet();
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    IntMasterEnable();//SETB EA
    IntEnable(INT_TIMER0A);//GLOBAL TIMER KESMESİ AYARLARI
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC); //timer'ı konfigüre ederek kullanım şeklimizi belirledik
    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()-1);//ilk degeri girdik timer'a
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);//0 dan -1 olunca timeout oluşturduk.
    TimerEnable(TIMER0_BASE, TIMER_A);//setb tr0
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0|GPIO_PIN_1);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE);//Uİ32CONFIG KOPYALANIR BU FONKSİYONUN OLDUGU YERE CTRL İLE GİDİLİR VE ORADAN SEÇİLİR(KAFANA GÖRE)
    UARTEnable(UART0_BASE);


}
