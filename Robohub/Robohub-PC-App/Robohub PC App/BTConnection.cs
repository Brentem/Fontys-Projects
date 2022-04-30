using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Diagnostics;
using System.IO;

namespace Robohub_PC_App
{
    public class BTConnection
    {
        public SerialPort Port { get; private set; }
        
        public bool IsConnected
        {
            get
            {
                return Port.IsOpen;
            }
        }

        public BTConnection(SerialPort port)
        {
            if(port == null)
            {
                throw new ArgumentNullException("Argument(s) given are/is null!");
            }

            Port = port;
        }

        public byte[] ReadBytes()
        {
            if(Port.BytesToRead <= 0)
            {
                return null;
            }

            byte[] bytes = new byte[14];

            byte readByte = (byte)Port.ReadByte();

            if (readByte == Protocol.SendDataCommand)
            {
                for (int i = 0; i < 14; i++)
                {
                    bytes[i] = (byte)Port.ReadByte();
                }
            }
            else
            {
                return null;
            }

            return bytes;
        }

        public void Connect()
        {
            if(!Port.IsOpen)
            {
                Port.Open();
            }
        }

        public void Disconnect()
        {
            if(Port.IsOpen)
            {
                Port.Close();
            }
        }

        public void SendMessage(byte[] message)
        {
            Port.Write(message, 0, message.Count());
        }
    }
}
