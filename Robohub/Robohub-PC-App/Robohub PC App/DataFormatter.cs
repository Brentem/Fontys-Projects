using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Robohub_PC_App
{
    public static class DataFormatter
    {
        public static SensorData FormatSensorData(byte[] message)
        {
            short temp = (short)((message[13] << 8) | message[12]);

            SensorData sensorData = new SensorData()
            {
                AccX = ((message[1] << 8) | message[0]),
                AccY = ((message[3] << 8) | message[2]),
                AccZ = ((message[5] << 8) | message[4]),
                AnalogLight = ((message[7] << 8) | message[6]),
                Flux = (((message[9] << 8) | message[8]) / 100),
                AnalogWarmth = ((message[11] << 8) | message[10]),
                Temperature = temp / 100.00
            };

            return sensorData;
        }
    }
}
