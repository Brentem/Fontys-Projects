#include <Arduino.h>
#include <protocol_handler.h>
#include <BluetoothSerial.h>
#include <ELMduino.h>

//https://forum.arduino.cc/t/sending-4-bytes-int-number-with-serial-write-to-serial/311669/7
//https://github.com/PowerBroker2/ELMduino/blob/master/examples/ESP32_Bluetooth_Serial/ESP32_Bluetooth_Serial.ino

ELM327 ELM;
BluetoothSerial BTSerial;

void send_float_as_four_byte_array(uint8_t messageStart, float value);
void send_float_as_six_byte_array(uint8_t messageStart, float value);
void send_int32_as_four_byte_array(uint8_t messageStart, int32_t value);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  BTSerial.begin("ESP32 OBD");

  while(!ELM.begin(BTSerial, false, 2000))
  {
    Serial.println("Couldn't connect to OBD scanner");
  }

  Serial.println("Connected to ELM327");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ELM.status == ELM_SUCCESS)
  {
    send_float_as_four_byte_array(PROTOCOL_THROTTLE_POSITION, ELM.throttle());
    send_int32_as_four_byte_array(PROTOCOL_VEHICLE_SPEED, ELM.kph());
    send_float_as_six_byte_array(PROTOCOL_ENGINE_SPEED, ELM.rpm());
    send_float_as_four_byte_array(PROTOCOL_FUEL_TANK_LEVEL_INPUT, ELM.fuelLevel());
    send_float_as_six_byte_array(PROTOCOL_ENGINE_FUEL_RATE, ELM.fuelRate());
    send_float_as_six_byte_array(PROTOCOL_FUEL_PRESSURE, ELM.fuelPressure());
  }
  else
  {
    ELM.printError();
  }
  delay(1000);
}

void send_float_as_four_byte_array(uint8_t messageStart, float value)
{
  uint8_t payload[4] = {messageStart, 0, 0, MESSAGE_END};
  uint8_t valueToParse = (uint8_t) value;

  protocol_handler_format_byte(valueToParse, &payload[1], 2);

  Serial.write(payload, sizeof(payload) / sizeof(uint8_t));
}

void send_float_as_six_byte_array(uint8_t messageStart, float value)
{
  uint8_t payload[6] = {messageStart, 0, 0, 0, 0, MESSAGE_END};
  uint16_t valueToParse = (uint16_t) value;

  protocol_handler_format_two_bytes(valueToParse, &payload[4], 4);

  Serial.write(payload, sizeof(payload) / sizeof(uint8_t));
}

void send_int32_as_four_byte_array(uint8_t messageStart, int32_t value)
{
  uint8_t payload[4] = {messageStart, 0, 0, MESSAGE_END};
  uint8_t valueToParse = (uint8_t) value;

  protocol_handler_format_byte(valueToParse, &payload[1], 2);

  Serial.write(payload, sizeof(payload) / sizeof(uint8_t));
}