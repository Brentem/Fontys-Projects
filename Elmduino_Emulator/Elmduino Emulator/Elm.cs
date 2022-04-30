using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Windows.Forms;
using System.Diagnostics;

//https://stackoverflow.com/a/12983496

namespace Elmduino_Emulator
{
    class Elm
    {
        public SerialPort Port { get; private set; }

        public int ThrottlePosition { private get; set; }
        public int RPM { private get; set; }
        public int KPH { private get; set; }
        public int FuelLevel { private get; set; }
        public int FuelRate { private get; set; }
        public int FuelPressure { private get; set; }

        private Form1 form;

        public Elm(SerialPort port, Form1 form)
        {
            Port = port;
            this.form = form;
            
            InitializeElm();
        }

        private void InitializeElm()
        {
            form.FormClosed += new FormClosedEventHandler(form_FormClosed);
            Port.DataReceived += new SerialDataReceivedEventHandler(Port_DataReceived);
        }

        private void form_FormClosed(object sender, FormClosedEventArgs e)
        {
            if(Port != null && Port.IsOpen)
            {
                Port.Close();
            }
        }

        private void Port_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string message = "";
            bool communicationStarted = true;

            while(communicationStarted)
            {
                char receivedChar = (char)Port.ReadChar();

                if (receivedChar == '\r')
                {
                    communicationStarted = false;
                    ProcessMessage(message);
                    message = ""; //Misschien niet nodig.
                }
                else
                {
                    message += receivedChar;
                }
            }
        }

        public void SendMessage(string message)
        {
            Port.Write(message);
        }

        private void ProcessMessage(string message)
        {
            if (message.StartsWith("AT "))
            {
                Debug.WriteLine(message);
                Port.Write("OK>\r");
            }
            else if (message.StartsWith("01"))
            {
                string pid = message.Substring(2, 2);

                switch (pid)
                {
                    case PID.THROTTLE_POSITION:
                        SendMessage(Service01.ThrottlePosition(ThrottlePosition));
                        break;

                    case PID.ENGINE_RPM:
                        SendMessage(Service01.RPM(RPM));
                        break;

                    case PID.VEHICLE_SPEED:
                        SendMessage(Service01.KPH(KPH));
                        break;

                    case PID.FUEL_TANK_LEVEL_INPUT:
                        SendMessage(Service01.FuelLevel(FuelLevel));
                        break;

                    case PID.ENGINE_FUEL_RATE:
                        SendMessage(Service01.FuelRate(FuelRate));
                        break;

                    case PID.FUEL_PRESSURE:
                        SendMessage(Service01.FuelPressure(FuelPressure));
                        break;
                }
            }
        }

        public void Connect()
        {
            Port.Open();
        }

        public void Disconnect()
        {
            Port.Close();
        }
    }
}
