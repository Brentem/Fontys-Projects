using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;

namespace Elmduino_Emulator
{
    public partial class Form1 : Form
    {
        private Elm elm;

        public Form1()
        {
            InitializeComponent();

            string[] ports = SerialPort.GetPortNames();

            foreach (string port in ports)
            {
                cbPort.Items.Add(port);
            }
        }

        private void TrackBar_ValueChanged(object sender, EventArgs e)
        {
            //https://stackoverflow.com/a/14479279

            if(elm == null)
            {
                return;
            }

            TrackBar trackBar = sender as TrackBar;

            switch (trackBar.Name)
            {
                case "trackBarThrottlePosition":
                    textBoxThrottlePosition.Text = Convert.ToString(trackBar.Value);
                    elm.ThrottlePosition = trackBar.Value;
                    break;

                case "trackBarRPM":
                    textBoxRPM.Text = Convert.ToString(trackBar.Value);
                    elm.RPM = trackBar.Value;
                    break;

                case "trackBarKPH":
                    textBoxKPH.Text = Convert.ToString(trackBar.Value);
                    elm.KPH = trackBar.Value;
                    break;

                case "trackBarFuelLevel":
                    textBoxFuelLevel.Text = Convert.ToString(trackBar.Value);
                    elm.FuelLevel = trackBar.Value;
                    break;

                case "trackBarFuelRate":
                    textBoxFuelRate.Text = Convert.ToString(trackBar.Value);
                    elm.FuelRate = trackBar.Value;
                    break;

                case "trackBarFuelPressure":
                    textBoxFuelPressure.Text = Convert.ToString(trackBar.Value);
                    elm.FuelPressure = trackBar.Value;
                    break;

            }
        }

        private void buttonConnect_Click(object sender, EventArgs e)
        {
            try
            {
                int baudRate = Convert.ToInt32(cbBaudRate.Text);
                SerialPort port = new SerialPort(cbPort.Text, baudRate);
                elm = new Elm(port, this);

                elm.Connect();
            }
            catch (IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch(FormatException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void buttonDisconnect_Click(object sender, EventArgs e)
        {
            try
            {
                // NullReferenceException opvangen werkte niet
                if (elm != null)
                {
                    elm.Disconnect();

                    elm = null;
                }
            }
            catch (IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
