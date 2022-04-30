
namespace Elmduino_Emulator
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblPort = new System.Windows.Forms.Label();
            this.lblBaudRate = new System.Windows.Forms.Label();
            this.cbPort = new System.Windows.Forms.ComboBox();
            this.cbBaudRate = new System.Windows.Forms.ComboBox();
            this.trackBarRPM = new System.Windows.Forms.TrackBar();
            this.lblRPM = new System.Windows.Forms.Label();
            this.lblKPH = new System.Windows.Forms.Label();
            this.trackBarKPH = new System.Windows.Forms.TrackBar();
            this.textBoxRPM = new System.Windows.Forms.TextBox();
            this.textBoxKPH = new System.Windows.Forms.TextBox();
            this.buttonConnect = new System.Windows.Forms.Button();
            this.buttonDisconnect = new System.Windows.Forms.Button();
            this.textBoxFuelLevel = new System.Windows.Forms.TextBox();
            this.textBoxThrottlePosition = new System.Windows.Forms.TextBox();
            this.lblFuelLevel = new System.Windows.Forms.Label();
            this.trackBarFuelLevel = new System.Windows.Forms.TrackBar();
            this.lblThrottlePosition = new System.Windows.Forms.Label();
            this.trackBarThrottlePosition = new System.Windows.Forms.TrackBar();
            this.textBoxFuelPressure = new System.Windows.Forms.TextBox();
            this.textBoxFuelRate = new System.Windows.Forms.TextBox();
            this.lblFuelPressure = new System.Windows.Forms.Label();
            this.trackBarFuelPressure = new System.Windows.Forms.TrackBar();
            this.lblFuelRate = new System.Windows.Forms.Label();
            this.trackBarFuelRate = new System.Windows.Forms.TrackBar();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarRPM)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarKPH)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFuelLevel)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarThrottlePosition)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFuelPressure)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFuelRate)).BeginInit();
            this.SuspendLayout();
            // 
            // lblPort
            // 
            this.lblPort.AutoSize = true;
            this.lblPort.Location = new System.Drawing.Point(13, 13);
            this.lblPort.Name = "lblPort";
            this.lblPort.Size = new System.Drawing.Size(29, 13);
            this.lblPort.TabIndex = 0;
            this.lblPort.Text = "Port:";
            // 
            // lblBaudRate
            // 
            this.lblBaudRate.AutoSize = true;
            this.lblBaudRate.Location = new System.Drawing.Point(13, 57);
            this.lblBaudRate.Name = "lblBaudRate";
            this.lblBaudRate.Size = new System.Drawing.Size(58, 13);
            this.lblBaudRate.TabIndex = 1;
            this.lblBaudRate.Text = "BaudRate:";
            // 
            // cbPort
            // 
            this.cbPort.FormattingEnabled = true;
            this.cbPort.Location = new System.Drawing.Point(72, 10);
            this.cbPort.Name = "cbPort";
            this.cbPort.Size = new System.Drawing.Size(121, 21);
            this.cbPort.TabIndex = 2;
            // 
            // cbBaudRate
            // 
            this.cbBaudRate.FormattingEnabled = true;
            this.cbBaudRate.Items.AddRange(new object[] {
            "300",
            "600",
            "1200",
            "2400",
            "4800",
            "9600",
            "14400",
            "19200",
            "28800",
            "31250",
            "38400",
            "57600",
            "115200"});
            this.cbBaudRate.Location = new System.Drawing.Point(72, 54);
            this.cbBaudRate.Name = "cbBaudRate";
            this.cbBaudRate.Size = new System.Drawing.Size(121, 21);
            this.cbBaudRate.TabIndex = 3;
            // 
            // trackBarRPM
            // 
            this.trackBarRPM.Location = new System.Drawing.Point(1, 281);
            this.trackBarRPM.Maximum = 16383;
            this.trackBarRPM.Name = "trackBarRPM";
            this.trackBarRPM.Size = new System.Drawing.Size(177, 45);
            this.trackBarRPM.TabIndex = 4;
            this.trackBarRPM.ValueChanged += new System.EventHandler(this.TrackBar_ValueChanged);
            // 
            // lblRPM
            // 
            this.lblRPM.AutoSize = true;
            this.lblRPM.Location = new System.Drawing.Point(2, 265);
            this.lblRPM.Name = "lblRPM";
            this.lblRPM.Size = new System.Drawing.Size(34, 13);
            this.lblRPM.TabIndex = 5;
            this.lblRPM.Text = "RPM:";
            // 
            // lblKPH
            // 
            this.lblKPH.AutoSize = true;
            this.lblKPH.Location = new System.Drawing.Point(6, 200);
            this.lblKPH.Name = "lblKPH";
            this.lblKPH.Size = new System.Drawing.Size(32, 13);
            this.lblKPH.TabIndex = 7;
            this.lblKPH.Text = "KPH:";
            // 
            // trackBarKPH
            // 
            this.trackBarKPH.Location = new System.Drawing.Point(5, 216);
            this.trackBarKPH.Maximum = 254;
            this.trackBarKPH.Name = "trackBarKPH";
            this.trackBarKPH.Size = new System.Drawing.Size(177, 45);
            this.trackBarKPH.TabIndex = 6;
            this.trackBarKPH.ValueChanged += new System.EventHandler(this.TrackBar_ValueChanged);
            // 
            // textBoxRPM
            // 
            this.textBoxRPM.Location = new System.Drawing.Point(185, 292);
            this.textBoxRPM.Name = "textBoxRPM";
            this.textBoxRPM.ReadOnly = true;
            this.textBoxRPM.Size = new System.Drawing.Size(100, 20);
            this.textBoxRPM.TabIndex = 8;
            // 
            // textBoxKPH
            // 
            this.textBoxKPH.Location = new System.Drawing.Point(185, 225);
            this.textBoxKPH.Name = "textBoxKPH";
            this.textBoxKPH.ReadOnly = true;
            this.textBoxKPH.Size = new System.Drawing.Size(100, 20);
            this.textBoxKPH.TabIndex = 9;
            // 
            // buttonConnect
            // 
            this.buttonConnect.Location = new System.Drawing.Point(210, 8);
            this.buttonConnect.Name = "buttonConnect";
            this.buttonConnect.Size = new System.Drawing.Size(75, 23);
            this.buttonConnect.TabIndex = 10;
            this.buttonConnect.Text = "Connect";
            this.buttonConnect.UseVisualStyleBackColor = true;
            this.buttonConnect.Click += new System.EventHandler(this.buttonConnect_Click);
            // 
            // buttonDisconnect
            // 
            this.buttonDisconnect.Location = new System.Drawing.Point(210, 54);
            this.buttonDisconnect.Name = "buttonDisconnect";
            this.buttonDisconnect.Size = new System.Drawing.Size(75, 23);
            this.buttonDisconnect.TabIndex = 11;
            this.buttonDisconnect.Text = "Disconnect";
            this.buttonDisconnect.UseVisualStyleBackColor = true;
            this.buttonDisconnect.Click += new System.EventHandler(this.buttonDisconnect_Click);
            // 
            // textBoxFuelLevel
            // 
            this.textBoxFuelLevel.Location = new System.Drawing.Point(185, 357);
            this.textBoxFuelLevel.Name = "textBoxFuelLevel";
            this.textBoxFuelLevel.ReadOnly = true;
            this.textBoxFuelLevel.Size = new System.Drawing.Size(100, 20);
            this.textBoxFuelLevel.TabIndex = 18;
            // 
            // textBoxThrottlePosition
            // 
            this.textBoxThrottlePosition.Location = new System.Drawing.Point(185, 164);
            this.textBoxThrottlePosition.Name = "textBoxThrottlePosition";
            this.textBoxThrottlePosition.ReadOnly = true;
            this.textBoxThrottlePosition.Size = new System.Drawing.Size(100, 20);
            this.textBoxThrottlePosition.TabIndex = 17;
            // 
            // lblFuelLevel
            // 
            this.lblFuelLevel.AutoSize = true;
            this.lblFuelLevel.Location = new System.Drawing.Point(6, 332);
            this.lblFuelLevel.Name = "lblFuelLevel";
            this.lblFuelLevel.Size = new System.Drawing.Size(117, 13);
            this.lblFuelLevel.TabIndex = 16;
            this.lblFuelLevel.Text = "Fuel Tank Level Input: ";
            // 
            // trackBarFuelLevel
            // 
            this.trackBarFuelLevel.Location = new System.Drawing.Point(5, 348);
            this.trackBarFuelLevel.Maximum = 100;
            this.trackBarFuelLevel.Name = "trackBarFuelLevel";
            this.trackBarFuelLevel.Size = new System.Drawing.Size(177, 45);
            this.trackBarFuelLevel.TabIndex = 15;
            this.trackBarFuelLevel.ValueChanged += new System.EventHandler(this.TrackBar_ValueChanged);
            // 
            // lblThrottlePosition
            // 
            this.lblThrottlePosition.AutoSize = true;
            this.lblThrottlePosition.Location = new System.Drawing.Point(2, 137);
            this.lblThrottlePosition.Name = "lblThrottlePosition";
            this.lblThrottlePosition.Size = new System.Drawing.Size(89, 13);
            this.lblThrottlePosition.TabIndex = 14;
            this.lblThrottlePosition.Text = "Throttle Position: ";
            // 
            // trackBarThrottlePosition
            // 
            this.trackBarThrottlePosition.Location = new System.Drawing.Point(1, 153);
            this.trackBarThrottlePosition.Maximum = 100;
            this.trackBarThrottlePosition.Name = "trackBarThrottlePosition";
            this.trackBarThrottlePosition.Size = new System.Drawing.Size(177, 45);
            this.trackBarThrottlePosition.TabIndex = 13;
            this.trackBarThrottlePosition.ValueChanged += new System.EventHandler(this.TrackBar_ValueChanged);
            // 
            // textBoxFuelPressure
            // 
            this.textBoxFuelPressure.Location = new System.Drawing.Point(185, 480);
            this.textBoxFuelPressure.Name = "textBoxFuelPressure";
            this.textBoxFuelPressure.ReadOnly = true;
            this.textBoxFuelPressure.Size = new System.Drawing.Size(100, 20);
            this.textBoxFuelPressure.TabIndex = 24;
            // 
            // textBoxFuelRate
            // 
            this.textBoxFuelRate.Location = new System.Drawing.Point(185, 420);
            this.textBoxFuelRate.Name = "textBoxFuelRate";
            this.textBoxFuelRate.ReadOnly = true;
            this.textBoxFuelRate.Size = new System.Drawing.Size(100, 20);
            this.textBoxFuelRate.TabIndex = 23;
            // 
            // lblFuelPressure
            // 
            this.lblFuelPressure.AutoSize = true;
            this.lblFuelPressure.Location = new System.Drawing.Point(6, 455);
            this.lblFuelPressure.Name = "lblFuelPressure";
            this.lblFuelPressure.Size = new System.Drawing.Size(74, 13);
            this.lblFuelPressure.TabIndex = 22;
            this.lblFuelPressure.Text = "Fuel Pressure:";
            // 
            // trackBarFuelPressure
            // 
            this.trackBarFuelPressure.Location = new System.Drawing.Point(5, 471);
            this.trackBarFuelPressure.Maximum = 765;
            this.trackBarFuelPressure.Name = "trackBarFuelPressure";
            this.trackBarFuelPressure.Size = new System.Drawing.Size(177, 45);
            this.trackBarFuelPressure.TabIndex = 21;
            this.trackBarFuelPressure.ValueChanged += new System.EventHandler(this.TrackBar_ValueChanged);
            // 
            // lblFuelRate
            // 
            this.lblFuelRate.AutoSize = true;
            this.lblFuelRate.Location = new System.Drawing.Point(2, 393);
            this.lblFuelRate.Name = "lblFuelRate";
            this.lblFuelRate.Size = new System.Drawing.Size(92, 13);
            this.lblFuelRate.TabIndex = 20;
            this.lblFuelRate.Text = "Engine Fuel Rate:";
            // 
            // trackBarFuelRate
            // 
            this.trackBarFuelRate.Location = new System.Drawing.Point(1, 409);
            this.trackBarFuelRate.Maximum = 3212;
            this.trackBarFuelRate.Name = "trackBarFuelRate";
            this.trackBarFuelRate.Size = new System.Drawing.Size(177, 45);
            this.trackBarFuelRate.TabIndex = 19;
            this.trackBarFuelRate.ValueChanged += new System.EventHandler(this.TrackBar_ValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 556);
            this.Controls.Add(this.textBoxFuelPressure);
            this.Controls.Add(this.textBoxFuelRate);
            this.Controls.Add(this.lblFuelPressure);
            this.Controls.Add(this.trackBarFuelPressure);
            this.Controls.Add(this.lblFuelRate);
            this.Controls.Add(this.trackBarFuelRate);
            this.Controls.Add(this.textBoxFuelLevel);
            this.Controls.Add(this.textBoxThrottlePosition);
            this.Controls.Add(this.lblFuelLevel);
            this.Controls.Add(this.trackBarFuelLevel);
            this.Controls.Add(this.lblThrottlePosition);
            this.Controls.Add(this.trackBarThrottlePosition);
            this.Controls.Add(this.buttonDisconnect);
            this.Controls.Add(this.buttonConnect);
            this.Controls.Add(this.textBoxKPH);
            this.Controls.Add(this.textBoxRPM);
            this.Controls.Add(this.lblKPH);
            this.Controls.Add(this.trackBarKPH);
            this.Controls.Add(this.lblRPM);
            this.Controls.Add(this.trackBarRPM);
            this.Controls.Add(this.cbBaudRate);
            this.Controls.Add(this.cbPort);
            this.Controls.Add(this.lblBaudRate);
            this.Controls.Add(this.lblPort);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.trackBarRPM)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarKPH)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFuelLevel)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarThrottlePosition)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFuelPressure)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFuelRate)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblPort;
        private System.Windows.Forms.Label lblBaudRate;
        private System.Windows.Forms.ComboBox cbPort;
        private System.Windows.Forms.ComboBox cbBaudRate;
        private System.Windows.Forms.TrackBar trackBarRPM;
        private System.Windows.Forms.Label lblRPM;
        private System.Windows.Forms.Label lblKPH;
        private System.Windows.Forms.TrackBar trackBarKPH;
        private System.Windows.Forms.TextBox textBoxRPM;
        private System.Windows.Forms.TextBox textBoxKPH;
        private System.Windows.Forms.Button buttonConnect;
        private System.Windows.Forms.Button buttonDisconnect;
        private System.Windows.Forms.TextBox textBoxFuelLevel;
        private System.Windows.Forms.TextBox textBoxThrottlePosition;
        private System.Windows.Forms.Label lblFuelLevel;
        private System.Windows.Forms.TrackBar trackBarFuelLevel;
        private System.Windows.Forms.Label lblThrottlePosition;
        private System.Windows.Forms.TrackBar trackBarThrottlePosition;
        private System.Windows.Forms.TextBox textBoxFuelPressure;
        private System.Windows.Forms.TextBox textBoxFuelRate;
        private System.Windows.Forms.Label lblFuelPressure;
        private System.Windows.Forms.TrackBar trackBarFuelPressure;
        private System.Windows.Forms.Label lblFuelRate;
        private System.Windows.Forms.TrackBar trackBarFuelRate;
    }
}

