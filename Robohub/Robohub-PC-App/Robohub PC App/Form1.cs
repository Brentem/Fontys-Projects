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

// https://stackoverflow.com/questions/3356400/operator-with-events
// https://rules.sonarsource.com/csharp/tag/error-handling/RSPEC-1696
// https://stackoverflow.com/questions/13725619/cant-catch-nullreferenceexception

namespace Robohub_PC_App
{
    public partial class Form1 : Form
    {
        private BTConnection btConnection;
        private CSVLogger csvLogger = new CSVLogger();
        private bool loggingActivated = false;

        private byte speed = 0;
        private MovementState state = MovementState.STOP;

        Timer timer = new Timer();

        public Form1()
        {
            InitializeComponent();

            timer.Interval = 10;
            timer.Tick += Timer_Tick;
            timer.Start();

            FormClosed += form_FormClosed;
            
            UpdateUI();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            try
            {
                if (loggingActivated && (btConnection != null))
                {
                    byte[] bytes = btConnection.ReadBytes();

                    ProcessMessage(bytes);
                }
            }
            catch (IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch (OperationCanceledException ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void UpdateUI()
        {
            cbPorts.Items.Clear();

            string[] ports = SerialPort.GetPortNames();

            foreach (string port in ports)
            {
                cbPorts.Items.Add(port);
            }
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            try
            {
                int baudRate = Convert.ToInt32(cbBaudRates.Text);
                SerialPort port = new SerialPort(cbPorts.Text, baudRate);
                btConnection = new BTConnection(port);
                btConnection.Connect();

                if (btConnection.IsConnected)
                {
                    MessageBox.Show("Succesfully connected!");
                }
            }
            catch(FormatException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch(IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch(InvalidOperationException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch (UnauthorizedAccessException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnDisconnect_Click(object sender, EventArgs e)
        {
            try
            {
                if (btConnection != null)
                {
                    btConnection.Disconnect();
                    btConnection = null;
                    MessageBox.Show("Succesfully disconnected!");
                }
            }
            catch(IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnMovement_Click(object sender, EventArgs e)
        {
            if((sender is not Button) || (btConnection == null))
            {
                return;
            }

            Button movementButton = (Button)sender;

            switch(movementButton.Name)
            {
                case "btnMovementStop":
                    state = MovementState.STOP;
                    break;
                case "btnMovementForwards":
                    state = MovementState.FORWARDS;
                    break;
                case "btnMovementLeftwards":
                    state = MovementState.LEFTWARDS;
                    break;
                case "btnMovementRightwards":
                    state = MovementState.RIGHTWARDS;
                    break;
                case "btnMovementBackwards":
                    state = MovementState.BACKWARDS;
                    break;
                default:
                    MessageBox.Show("Default case of btnMovement_Click is reached this isn't supposed to happen!");
                    break;
            }

            try
            {
                HandleMovementMessage(state, speed);
            }
            catch(IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnCsvIO_Click(object sender, EventArgs e)
        {
            if (sender is not Button)
            {
                return;
            }

            Button movementButton = (Button)sender;

            switch (movementButton.Name)
            {
                case "btnCsvIOStart":
                    if (btConnection != null)
                    {
                        if (btConnection.IsConnected)
                        {
                            loggingActivated = true;
                            lbShowIncomingData.Items.Clear();
                        }
                        else
                        {
                            MessageBox.Show("Bluetooth isn't connected!");
                        }
                    }
                    break;
                case "btnCsvIOStop":
                    loggingActivated = false;
                    break;
                case "btnCsvIOClearListBox":
                    lbShowIncomingData.Items.Clear();
                    break;
                default:
                    MessageBox.Show("Default case of btnCsvIO_Click is reached this isn't supposed to happen!");
                    break;
            }
        }

        private void HandleMovementMessage(MovementState movementState, byte speed)
        {
            byte[] payload = { Protocol.MovementCommand, (byte)movementState, speed, Protocol.MessageEndMarker };

            if (btConnection != null)
            {
                btConnection.SendMessage(payload);
            }
        }

        private void trackBarSpeed_ValueChanged(object sender, EventArgs e)
        {
            try
            {
                speed = (byte)trackBarSpeed.Value;
                textBoxShowSpeed.Text = Convert.ToString(speed);
                HandleMovementMessage(state, speed);
            }
            catch (IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void form_FormClosed(object sender, FormClosedEventArgs e)
        {
            try
            {
                if (btConnection != null)
                {
                    if (btConnection.Port != null && btConnection.IsConnected)
                    {
                        btConnection.Disconnect();
                    }
                }
            }
            catch(IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void ProcessMessage(byte[] bytes)
        {
            try
            {
                if (bytes != null)
                {
                    SensorData sensorData = DataFormatter.FormatSensorData(bytes);
                    lbShowIncomingData.Items.Add(sensorData);
                    
                    csvLogger.CreateDirectory();
                    csvLogger.WriteData(sensorData);
                }
            }
            catch(IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch(UnauthorizedAccessException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
