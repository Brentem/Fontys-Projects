#include "USART.h"

//NOTE:(BRENT) Dit was eigenlijk niet nodig om te maken.
void USART_Init()
{
    // Enable Clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER2) |
                    (0x02 << GPIO_MODER_MODER2_Pos);
    GPIOA->OTYPER &= ~GPIO_OTYPER_OT_2;
    GPIOA->OSPEEDR |= (0x03 << GPIO_OSPEEDER_OSPEEDR2_Pos);

    // Set alternate functions
    GPIOA->AFR[0] |= (0x07 << GPIO_AFRL_AFRL2_Pos);

    // Set databits to 8
    USART2->CR1 = (USART2->CR1 & ~USART_CR1_M) |
                    (0x00 << USART_CR1_M_Pos);

    // Set baudrate 9600 
    USART2->BRR = (SystemCoreClock/9600);
    
    // Set 1 stop bit
    USART2->CR2 = (USART2->CR2 & ~USART_CR2_STOP) |
                    (0x00 << USART_CR2_STOP_Pos);

    //16 oversampling    
    USART2->CR1 = (USART2->CR1 & ~USART_CR1_OVER8) |
                    (0x00 << USART_CR1_OVER8_Pos);

    // Turn USART on
    USART2->CR1 |= USART_CR1_UE;

    USART2->CR1 |= USART_CR1_TE;
}

bool USART_TXEFlagSet()
{
    bool flagSet = USART2->ISR & USART_ISR_TXE;
    return flagSet;
}

bool USART_TCFlagSet()
{
    bool flagSet = (USART2->ISR & USART_ISR_TC);
    return flagSet;
}

void USART_Send(uint8_t* buffer, uint32_t size)
{
    if(buffer == NULL)
    {
        return;
    }

    for(int i = 0; i < size; i++)
    {
        while(!USART_TXEFlagSet())
        {};

        USART2->TDR = buffer[i];

        while(!(USART_TCFlagSet())) 
        {};
    }
}
