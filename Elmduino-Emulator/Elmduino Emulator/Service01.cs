using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Elmduino_Emulator
{
    public static class Service01
    {
        private const string request = "01";
        private const string answer = "41";
        private const string messageEnd = ">\r";

        public static string ThrottlePosition(decimal value)
        {
            value /= (100m / 255m);
            int parsed = (int)value;
            string hexString = parsed.ToString("X2");

            return answer + PID.THROTTLE_POSITION + hexString + messageEnd;
        }

        //https://www.codegrepper.com/code-examples/csharp/C%23+int+to+hex
        public static string RPM(int value)
        {
            value *= 4;
            string hexString = value.ToString("X4");

            return answer + PID.ENGINE_RPM + hexString + messageEnd;
        }

        public static string KPH(int value)
        {
            string hexString = value.ToString("X2");

            return answer + PID.VEHICLE_SPEED + hexString + messageEnd;
        }

        public static string FuelLevel(decimal value)
        {
            value /= (100m / 255m);
            int parsed = (int)value;
            string hexString = parsed.ToString("X2");

            return answer + PID.FUEL_TANK_LEVEL_INPUT + hexString + messageEnd;
        }

        public static string FuelRate(int value)
        {
            value *= 20;
            string hexString = value.ToString("X4");

            return answer + PID.ENGINE_FUEL_RATE + hexString + messageEnd;
        }

        public static string FuelPressure(int value)
        {
            value /= 3;
            string hexString = value.ToString("X2");

            return answer + PID.FUEL_PRESSURE + hexString + messageEnd;
        }
    } 
}
