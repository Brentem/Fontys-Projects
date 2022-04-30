#include "PWM_Timer.h"

#include <stm32f303xe.h>

PWM_Timer::PWM_Timer()
{
}

PWM_Timer::PWM_Timer(PWM_Pin pin, uint32_t high_symbol, uint32_t low_symbol,
 uint64_t arr, uint8_t prescaler)
{
    this->high_symbol = high_symbol;
    this->low_symbol = low_symbol;
    this->arr = arr;
    this->prescaler = prescaler;

    //setInterrupts();
    //setupTimer(pin);
    //setupAlternateFunction(pin);

    // Dit moet nog fatsoenlijk verwerkt worden in setInterrupts, setupTimer
    // en setupAlternateFunction
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    TIM2->PSC = 0;
    TIM2->ARR = 9;
    TIM2->CCMR1 &= ~TIM_CCMR1_CC1S;
    TIM2->CCMR1 |= (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2);
    TIM2->CCR1 = 0;
    TIM2->CCER |= TIM_CCER_CC1E;
    
    TIM2->DIER |= TIM_DIER_UIE;

    TIM2->CR1 |= TIM_CR1_CEN;

    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    GPIOA->MODER |= (0x02 << GPIO_MODER_MODER0_Pos);
    GPIOA->AFR[0] |= (0x01 << GPIO_AFRL_AFRL0_Pos);
}

// Onderste 3 functies algemener maken.
void PWM_Timer::SetHighSymbol()
{
    TIM2->CCR1 = high_symbol;
}

void PWM_Timer::SetLowSymbol()
{
    TIM2->CCR1 = low_symbol;
}

void PWM_Timer::SetLineLow()
{
    TIM2->CCR1 = 0;
}

// Note: Deze functie kan nog verbeterd worden!
// TIM2 en TIM2->CR1 vervangen met iets algemeners.
void PWM_Timer::setupTimer(PWM_Pin pin)
{
    Data_Timer data_timer = getDataForTimer(pin);

    RCC->APB1ENR |= data_timer.timer_enable;
    TIM2->PSC = prescaler;
    TIM2->ARR = arr;
    TIM2->CCMR1 &= ~data_timer.capture_compare_selection;
    TIM2->CCMR2 |= (data_timer.output_compare_mode_bit_1 | 
                    data_timer.output_compare_mode_bit_2);
    TIM2->CCR1 = 0;
    TIM2->CCER |= data_timer.output_enable;

    TIM2->CR1 |= TIM_CR1_CEN;
}

// Note: Deze functie algemener maken.
void PWM_Timer::setupAlternateFunction(PWM_Pin pin)
{
    Data_Alternate_Function alternate_function = getDataForAlternateFunction(pin);

    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    GPIOA->MODER |= (ALTERNATE_FUNCTION_MODE << alternate_function.gpio_moder_pos);
    GPIOA->AFR[0] |= (TEMP_ALTERNATE_FUNCTION << alternate_function.alternate_function_pos);
}

Data_Timer PWM_Timer::getDataForTimer(PWM_Pin pin)
{
    Data_Timer data_timer;

    switch (pin)
    {
    case A0:
        data_timer.timer_enable = RCC_APB1ENR_TIM2EN;
        data_timer.capture_compare_selection = TIM_CCMR1_CC1S;
        data_timer.output_compare_mode_bit_1 = TIM_CCMR1_OC1M_1;
        data_timer.output_compare_mode_bit_2 = TIM_CCMR1_OC1M_2;
        data_timer.output_enable = TIM_CCER_CC1E;
        break;
    
    default:
        break;
    }

    return data_timer;
}

Data_Alternate_Function PWM_Timer::getDataForAlternateFunction(PWM_Pin pin)
{
    Data_Alternate_Function alternate_function;

    switch (pin)
    {
    case A0:
        alternate_function.gpio_moder_pos = GPIO_MODER_MODER0_Pos;
        alternate_function.alternate_function_pos = GPIO_AFRL_AFRL0_Pos;
        break;
    
    default:
        break;
    }

    return alternate_function;
}

void PWM_Timer::setInterrupts()
{
    TIM2->DIER |= TIM_DIER_UIE;
    NVIC_EnableIRQ(TIM2_IRQn);
}