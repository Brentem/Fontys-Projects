#include <stm32f303xe.h>

#include <LedStrip.h>

extern "C"
{
    #include <USART.h>
    #include <string.h>
}

PWM_Timer timer(A0, 7, 3, 9, 0);
LedStrip strip(&timer);

extern "C" void TIM2_IRQHandler(void)
{
    TIM2->SR = ~TIM_SR_UIF;

    // char str[] = "Interrupt called!\n";
    // USART_Send((uint8_t*)str, strlen(str));
        
    strip.Update();
}

int main(void)
{
    SystemInit();
    USART_Init();

    // char buf[] = "Setting buffer...\n";
    // USART_Send((uint8_t*)buf, strlen(buf));

    strip.SetBuffer(0, 0, 255, 0);
    strip.SetBuffer(1, 255, 0, 0);
    strip.SetBuffer(2, 0, 0, 255);

    strip.SetBuffer(10, 255, 0, 255);
    strip.SetBuffer(11, 255, 255, 0);
    strip.SetBuffer(12, 0, 255, 255);

    strip.SetBuffer(20, 255, 255, 255);

    // char str[] = "Buffer set\n";
    // USART_Send((uint8_t*)str, strlen(str));

    strip.StartUpdate();

    while(1)
    {

    }

    return 0;
}