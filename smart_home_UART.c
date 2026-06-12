#define STM32F10X_MD
#include "stm32f10x.h"


char command[30];
int index = 0;


//---------------- UART FUNCTIONS ----------------

void UART_Send(char c)
{
    while(!(USART1->SR & (1<<7)));   // wait TX empty

    USART1->DR = c;
}


void UART_Print(char *str)
{
    while(*str)
    {
        UART_Send(*str);
        str++;
    }
}


char UART_Read()
{
    while(!(USART1->SR & (1<<5)));   // wait RX data

    return USART1->DR;
}



//---------------- STRING COMPARE ----------------

int compare(char *a,char *b)
{
    int i=0;

    while(a[i] && b[i])
    {
        if(a[i] != b[i])
            return 0;

        i++;
    }

    if(a[i]=='\0' && b[i]=='\0')
        return 1;

    return 0;
}



//---------------- OUTPUT CONTROL ----------------

void LED1_ON()
{
    GPIOC->ODR &= ~(1<<13);
}

void LED1_OFF()
{
    GPIOC->ODR |= (1<<13);
}


void LED2_ON()
{
    GPIOC->ODR &= ~(1<<14);
}

void LED2_OFF()
{
    GPIOC->ODR |= (1<<14);
}


void BUZZER_ON()
{
    GPIOB->ODR |= (1<<0);
}

void BUZZER_OFF()
{
    GPIOB->ODR &= ~(1<<0);
}


void MOTOR_ON()
{
    GPIOB->ODR |= (1<<1);
}

void MOTOR_OFF()
{
    GPIOB->ODR &= ~(1<<1);
}



//---------------- MAIN ----------------

int main()
{


// Enable GPIOA GPIOB GPIOC USART1 clocks

RCC->APB2ENR |= (1<<0) | (1<<2) | (1<<3) | (1<<4) | (1<<14);



// PC13 LED1 output

GPIOC->CRH &= ~(0xF<<20);
GPIOC->CRH |= (0x2<<20);


// PC14 LED2 output

GPIOC->CRH &= ~(0xF<<24);
GPIOC->CRH |= (0x2<<24);



// PB0 Buzzer output

GPIOB->CRL &= ~(0xF<<0);
GPIOB->CRL |= (0x2<<0);



// PB1 Motor output

GPIOB->CRL &= ~(0xF<<4);
GPIOB->CRL |= (0x2<<4);



// PA9 TX

GPIOA->CRH &= ~(0xF<<4);
GPIOA->CRH |= (0xB<<4);



// PA10 RX

GPIOA->CRH &= ~(0xF<<8);
GPIOA->CRH |= (0x4<<8);



// UART configuration

USART1->BRR = 0x341;   // 9600 baud


USART1->CR1 |= (1<<13); // enable USART

USART1->CR1 |= (1<<2);  // RX enable

USART1->CR1 |= (1<<3);  // TX enable



UART_Print("STM32 Home Automation Ready\r\n");



while(1)
{


char data;


data = UART_Read();



if(data == '\r')
{

command[index]='\0';



if(compare(command,"LED1 OFF"))
{
    LED1_ON();
    UART_Print("LED1 OFF\r\n");
}


else if(compare(command,"LED1 ON"))
{
    LED1_OFF();
    UART_Print("LED1 ON\r\n");
}



else if(compare(command,"LED2 OFF"))
{
    LED2_ON();
    UART_Print("LED2 OFF\r\n");
}


else if(compare(command,"LED2 ON"))
{
    LED2_OFF();
    UART_Print("LED2 ON\r\n");
}



else if(compare(command,"BUZZER ON"))
{
    BUZZER_ON();
    UART_Print("BUZZER ON\r\n");
}


else if(compare(command,"BUZZER OFF"))
{
    BUZZER_OFF();
    UART_Print("BUZZER OFF\r\n");
}



else if(compare(command,"MOTOR ON"))
{
    MOTOR_ON();
    UART_Print("MOTOR ON\r\n");
}



else if(compare(command,"MOTOR OFF"))
{
    MOTOR_OFF();
    UART_Print("MOTOR OFF\r\n");
}



else if(compare(command,"STATUS"))
{
    UART_Print("SYSTEM OK\r\n");
}



else
{
    UART_Print("INVALID COMMAND\r\n");
}



index=0;

}



else
{

command[index]=data;

index++;

}



}


}
