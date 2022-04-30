#include <My_UART.h>

UART_Config UART;

uint8_t interval = 0;

void PrintNewLine();
uint8_t GetParityBit(uint8_t bitsForParity, ParityType parity);
bool UART_ErrorOccurred(uint8_t actualParityBit, uint8_t bitsForParity, ParityType parity);

bool parityError = false;

//Rx
bool reading = false;
uint32_t receiveTime = 0;
uint32_t lineHighTime = 0;

void UART_Init(UART_Config init)
{
    UART = init;

    pinMode(UART.RxPin, INPUT);
    pinMode(UART.TxPin, OUTPUT);

    digitalWrite(UART.TxPin, HIGH);
    
    interval = MICROSECONDS/UART.BaudRate;
}

bool UART_CheckReadState()
{
    if(digitalRead(UART.RxPin) == LOW)
    {
        reading = true;
        uint32_t currentTime = micros();
        uint8_t delay = currentTime - lineHighTime;
        receiveTime = currentTime + (interval + (interval / 2)- delay);
        return true;
    }
    else
    {
        reading = false;
        lineHighTime = micros();
        return false;
    }
}

uint8_t UART_Read()
{
    uint8_t readByte = 0;
    uint8_t counter = 0;
    receiveTime = micros() + interval;

    // Parity
    bool recieveParityBit = UART.Parity != NONE;
    uint8_t bitsForParity = 0;
    parityError = false;

    while(reading)
    {
        if((micros() >= receiveTime) &&
        (counter != UART.NrDataBits))
        {
            receiveTime += interval;
            uint8_t digitalValue = digitalRead(UART.RxPin);
            readByte |= (digitalValue << counter);
            bitsForParity += digitalValue;
            counter++;
        }
        else if((micros() >= receiveTime) &&
        recieveParityBit &&
        (counter == UART.NrDataBits))
        {
            uint8_t actualParityBit = digitalRead(UART.RxPin);
            parityError = UART_ErrorOccurred(actualParityBit, bitsForParity, UART.Parity);
            receiveTime += interval;
            recieveParityBit = false;
        }
        else if((micros() >= receiveTime) &&
        (counter == UART.NrDataBits) &&
        !recieveParityBit)
        {
            if(digitalRead(UART.RxPin) == HIGH)
            {
                reading = false;
            }
        }
    }
    return readByte;
}

void UART_Write(const uint8_t byte)
{
    bool writing = true;
    uint8_t dataCounter = 0;
    uint8_t stopCounter = 0;
    uint32_t sendTime = micros() + interval;

    // Parity
    bool sendParityBit = UART.Parity != NONE;
    uint8_t bitsForParity = 0;

    // Start bit
    digitalWrite(UART.TxPin, LOW);

    while(writing)
    {
        // Send data bits
        if((micros() >= sendTime) &&
        (dataCounter != UART.NrDataBits))
        {
            uint8_t digitalValue = byte & (1 << dataCounter);
            digitalValue >>= dataCounter;
            digitalWrite(UART.TxPin, digitalValue);
            bitsForParity += digitalValue;
            dataCounter++;
            sendTime += interval;
        }
        else if((micros() >= sendTime) &&
        sendParityBit &&
        dataCounter == UART.NrDataBits)
        {
            uint8_t parityBit = GetParityBit(bitsForParity, UART.Parity);
            digitalWrite(UART.TxPin, parityBit);
            sendTime += interval;
            sendParityBit = false;
        }
        else if((micros() >= sendTime) &&
        (dataCounter == UART.NrDataBits) && !sendParityBit)
        {
            writing = false;
            sendTime += interval;
        }
    }

    // Send stop bit
    while(stopCounter < UART.NrStopBits)
    {
        digitalWrite(UART.TxPin, HIGH);

        if(micros() >= sendTime)
        {
            stopCounter++;
            sendTime += interval;
        }
    }
}

bool UART_DataBitsConfig()
{
    bool dataConfig = false;

    if(UART.NrDataBits < 7)
    {
        dataConfig = true;
    }

    return dataConfig;
}

bool UART_ParityError()
{
    return parityError;
}

uint8_t GetParityBit(uint8_t bitsForParity, ParityType parity)
{
    uint8_t parityBit = 0;

    if(parity == EVEN)
    {
        parityBit = bitsForParity % 2;
    }
    else
    {
        if((bitsForParity % 2) == 0)
        {
            parityBit = 1;
        }
        else
        {
            parityBit = 0;
        }
    }

    return parityBit;
}

bool UART_ErrorOccurred(uint8_t actualParityBit, uint8_t bitsForParity, ParityType parity)
{
    uint8_t parityBit = GetParityBit(bitsForParity, parity);

    return actualParityBit != parityBit;
}

uint8_t GetDataBitsCount()
{
    return UART.NrDataBits;
}