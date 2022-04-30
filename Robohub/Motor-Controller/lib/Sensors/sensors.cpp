#include <sensors.h>
#include <fifo.h>

//https://forum.arduino.cc/t/send-a-struct-to-serial-with-serial-write/400739/4

FifoWarmth fifoWarmth;
FifoFlux fifoFlux;

uint32_t prevMillis = 0;

void sensors_setup()
{
    Wire.begin();

    fifoWarmth.tail = 0;
    fifoWarmth.head = 0;
    fifoWarmth.count = 0;

    fifoFlux.tail = 0;
    fifoFlux.head = 0;
    fifoFlux.count = 0;
}

void sensors_accelerometer_set_measurement_mode()
{
    Wire.beginTransmission(SENSOR_SLAVE_ADDRESS);
    Wire.write(CTRL1_XL);
    Wire.write(CONFIGURATION);
    Wire.endTransmission();

    Wire.beginTransmission(SENSOR_SLAVE_ADDRESS);
    Wire.write(CTRL3_C);
    Wire.write(IF_INC);
    Wire.endTransmission();
}

void sensors_accelerometer_measure(sensors_data* data)
{
    uint8_t array[6];
    int i = 0;

    Wire.beginTransmission(SENSOR_SLAVE_ADDRESS);
    Wire.write(OUTX_L_XL);
    Wire.endTransmission();

    Wire.requestFrom(SENSOR_SLAVE_ADDRESS, 6);

    while((Wire.available() > 0) && (Wire.available() < 7))
    {
        array[i] = Wire.read();
        i++;
    }

    data->accX = (int16_t)(array[1] << 8 | array[0]);
    data->accY = (int16_t)(array[3] << 8 | array[2]);
    data->accZ = (int16_t)(array[5] << 8 | array[4]);

    //Serial.print("accX: ");
    //Serial.print(data->accX);
    //Serial.print("accY: ");
    //Serial.print(data->accY);
    //Serial.print("accZ: ");
    //Serial.println(data->accZ);
}

float sensors_calculate_temperature(uint16_t value)
{
    float R1 = 10000;
    float logR2, R2, T, Tc;
    float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

    R2 = R1 * (1023.0 / (float)value - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    Tc = T - 273.15;

    return Tc;
}

//Light Intencity Measurement
//www.circuits4you.com
uint16_t sensors_calculate_flux(uint16_t value)
{
    double Vout=value*0.0048828125;
    //int lux=500/(10*((5-Vout)/Vout));//use this equation if the LDR is in the upper part of the divider
    uint16_t lux=(2500/Vout-500)/10;
    return lux;
}

void sensors_update_data(sensors_data* data)
{
    uint16_t readAnalogLight = analogRead(LIGHT_SENSOR_PIN);
    uint16_t readAnalogWarmth = analogRead(WARMTH_SENSOR_PIN);

    data->analogLight = readAnalogLight;
    data->analogWarmth = readAnalogWarmth;

    float temperature = sensors_calculate_temperature(readAnalogWarmth);
    uint16_t flux = sensors_calculate_flux(readAnalogLight);

    //Serial.print("Temperature: "); Serial.println(temperature);
    //Serial.print("Flux: "); Serial.println(flux);

    FifoFluxWrite(flux, &fifoFlux);
    FifoWarmthWrite(temperature, &fifoWarmth);
}

void sensors_get_averages(sensors_data* data)
{
    uint16_t fluxAverage = 0;
    int16_t temperatureAverage = 0;

    FifoFluxAverageBuffer(&fluxAverage, &fifoFlux);
    FifoWarmthAverageBuffer(&temperatureAverage, &fifoWarmth);

    //Serial.print("Flux Average: "); Serial.println(fluxAverage);
    //Serial.print("Temperature Average: "); Serial.println(temperatureAverage);

    data->flux = fluxAverage;
    data->temperature = temperatureAverage;
}

void sensors_loop()
{
    sensors_data data;

    sensors_update_data(&data);

    if(millis() >= (prevMillis + DELAY))
    {
        prevMillis = millis();

        sensors_accelerometer_measure(&data);
        sensors_get_averages(&data);

        Serial.write(SEND_DATA_COMMAND);
        Serial.write((uint8_t*)&data, sizeof(data));
    }
}