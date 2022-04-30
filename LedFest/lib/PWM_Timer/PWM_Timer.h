#ifndef PWM_TIMER_H
#define PWM_TIMER_H

#include <stdint.h>

#define ALTERNATE_FUNCTION_MODE 0x02
#define TEMP_ALTERNATE_FUNCTION 0x01 // Dit is tijdelijk!


struct  Data_Timer
{
    uint32_t timer_enable;
    uint32_t capture_compare_selection;
    uint32_t output_compare_mode_bit_1;
    uint32_t output_compare_mode_bit_2;
    uint32_t output_enable;
};

struct Data_Alternate_Function
{
    uint32_t gpio_moder_pos;
    uint32_t alternate_function_pos;
};


enum PWM_Pin
{
    A0,
    A1,
    A2
};

class PWM_Timer
{
    private:
        uint32_t high_symbol;
        uint32_t low_symbol;
        uint64_t arr;
        uint8_t prescaler;

        Data_Timer getDataForTimer(PWM_Pin pin);
        Data_Alternate_Function getDataForAlternateFunction(PWM_Pin pin);
        void setupTimer(PWM_Pin pin);
        void setupAlternateFunction(PWM_Pin pin);
        void setInterrupts();

    public:
        PWM_Timer();
        PWM_Timer(PWM_Pin pin, uint32_t high_symbol, uint32_t low_symbol,
         uint64_t arr, uint8_t prescaler);
        void SetHighSymbol();
        void SetLowSymbol();
        void SetLineLow();
};

#endif