
namespace Robohub_PC_App
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.cbPorts = new System.Windows.Forms.ComboBox();
            this.lblPortName = new System.Windows.Forms.Label();
            this.lblBaudRate = new System.Windows.Forms.Label();
            this.cbBaudRates = new System.Windows.Forms.ComboBox();
            this.btnConnect = new System.Windows.Forms.Button();
            this.btnDisconnect = new System.Windows.Forms.Button();
            this.btnMovementStop = new System.Windows.Forms.Button();
            this.btnMovementBackwards = new System.Windows.Forms.Button();
            this.btnMovementForwards = new System.Windows.Forms.Button();
            this.btnMovementRightwards = new System.Windows.Forms.Button();
            this.btnMovementLeftwards = new System.Windows.Forms.Button();
            this.trackBarSpeed = new System.Windows.Forms.TrackBar();
            this.textBoxShowSpeed = new System.Windows.Forms.TextBox();
            this.lbShowIncomingData = new System.Windows.Forms.ListBox();
            this.btnCsvIOStart = new System.Windows.Forms.Button();
            this.btnCsvIOStop = new System.Windows.Forms.Button();
            this.btnCsvIOClearListBox = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarSpeed)).BeginInit();
            this.SuspendLayout();
            // 
            // cbPorts
            // 
            this.cbPorts.FormattingEnabled = true;
            this.cbPorts.Location = new System.Drawing.Point(99, 12);
            this.cbPorts.Name = "cbPorts";
            this.cbPorts.Size = new System.Drawing.Size(121, 23);
            this.cbPorts.TabIndex = 0;
            // 
            // lblPortName
            // 
            this.lblPortName.AutoSize = true;
            this.lblPortName.Location = new System.Drawing.Point(12, 20);
            this.lblPortName.Name = "lblPortName";
            this.lblPortName.Size = new System.Drawing.Size(32, 15);
            this.lblPortName.TabIndex = 1;
            this.lblPortName.Text = "Port:";
            // 
            // lblBaudRate
            // 
            this.lblBaudRate.AutoSize = true;
            this.lblBaudRate.Location = new System.Drawing.Point(12, 55);
            this.lblBaudRate.Name = "lblBaudRate";
            this.lblBaudRate.Size = new System.Drawing.Size(60, 15);
            this.lblBaudRate.TabIndex = 2;
            this.lblBaudRate.Text = "BaudRate:";
            // 
            // cbBaudRates
            // 
            this.cbBaudRates.FormattingEnabled = true;
            this.cbBaudRates.Items.AddRange(new object[] {
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
            this.cbBaudRates.Location = new System.Drawing.Point(99, 47);
            this.cbBaudRates.Name = "cbBaudRates";
            this.cbBaudRates.Size = new System.Drawing.Size(121, 23);
            this.cbBaudRates.TabIndex = 3;
            // 
            // btnConnect
            // 
            this.btnConnect.Location = new System.Drawing.Point(262, 11);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(75, 23);
            this.btnConnect.TabIndex = 4;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // btnDisconnect
            // 
            this.btnDisconnect.Location = new System.Drawing.Point(262, 55);
            this.btnDisconnect.Name = "btnDisconnect";
            this.btnDisconnect.Size = new System.Drawing.Size(75, 23);
            this.btnDisconnect.TabIndex = 5;
            this.btnDisconnect.Text = "Disconnect";
            this.btnDisconnect.UseVisualStyleBackColor = true;
            this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
            // 
            // btnMovementStop
            // 
            this.btnMovementStop.Location = new System.Drawing.Point(99, 215);
            this.btnMovementStop.Name = "btnMovementStop";
            this.btnMovementStop.Size = new System.Drawing.Size(75, 23);
            this.btnMovementStop.TabIndex = 6;
            this.btnMovementStop.Text = "Stop";
            this.btnMovementStop.UseVisualStyleBackColor = true;
            this.btnMovementStop.Click += new System.EventHandler(this.btnMovement_Click);
            // 
            // btnMovementBackwards
            // 
            this.btnMovementBackwards.Location = new System.Drawing.Point(99, 244);
            this.btnMovementBackwards.Name = "btnMovementBackwards";
            this.btnMovementBackwards.Size = new System.Drawing.Size(75, 23);
            this.btnMovementBackwards.TabIndex = 7;
            this.btnMovementBackwards.Text = "Backwards";
            this.btnMovementBackwards.UseVisualStyleBackColor = true;
            this.btnMovementBackwards.Click += new System.EventHandler(this.btnMovement_Click);
            // 
            // btnMovementForwards
            // 
            this.btnMovementForwards.Location = new System.Drawing.Point(99, 186);
            this.btnMovementForwards.Name = "btnMovementForwards";
            this.btnMovementForwards.Size = new System.Drawing.Size(75, 23);
            this.btnMovementForwards.TabIndex = 8;
            this.btnMovementForwards.Text = "Forwards";
            this.btnMovementForwards.UseVisualStyleBackColor = true;
            this.btnMovementForwards.Click += new System.EventHandler(this.btnMovement_Click);
            // 
            // btnMovementRightwards
            // 
            this.btnMovementRightwards.Location = new System.Drawing.Point(180, 215);
            this.btnMovementRightwards.Name = "btnMovementRightwards";
            this.btnMovementRightwards.Size = new System.Drawing.Size(75, 23);
            this.btnMovementRightwards.TabIndex = 9;
            this.btnMovementRightwards.Text = "Rightwards";
            this.btnMovementRightwards.UseVisualStyleBackColor = true;
            this.btnMovementRightwards.Click += new System.EventHandler(this.btnMovement_Click);
            // 
            // btnMovementLeftwards
            // 
            this.btnMovementLeftwards.Location = new System.Drawing.Point(18, 215);
            this.btnMovementLeftwards.Name = "btnMovementLeftwards";
            this.btnMovementLeftwards.Size = new System.Drawing.Size(75, 23);
            this.btnMovementLeftwards.TabIndex = 10;
            this.btnMovementLeftwards.Text = "Leftwards";
            this.btnMovementLeftwards.UseVisualStyleBackColor = true;
            this.btnMovementLeftwards.Click += new System.EventHandler(this.btnMovement_Click);
            // 
            // trackBarSpeed
            // 
            this.trackBarSpeed.Location = new System.Drawing.Point(11, 320);
            this.trackBarSpeed.Maximum = 90;
            this.trackBarSpeed.Minimum = 10;
            this.trackBarSpeed.Name = "trackBarSpeed";
            this.trackBarSpeed.Size = new System.Drawing.Size(406, 45);
            this.trackBarSpeed.TabIndex = 11;
            this.trackBarSpeed.Value = 10;
            this.trackBarSpeed.ValueChanged += new System.EventHandler(this.trackBarSpeed_ValueChanged);
            // 
            // textBoxShowSpeed
            // 
            this.textBoxShowSpeed.Location = new System.Drawing.Point(424, 319);
            this.textBoxShowSpeed.Name = "textBoxShowSpeed";
            this.textBoxShowSpeed.ReadOnly = true;
            this.textBoxShowSpeed.Size = new System.Drawing.Size(100, 23);
            this.textBoxShowSpeed.TabIndex = 12;
            // 
            // lbShowIncomingData
            // 
            this.lbShowIncomingData.FormattingEnabled = true;
            this.lbShowIncomingData.ItemHeight = 15;
            this.lbShowIncomingData.Location = new System.Drawing.Point(404, 11);
            this.lbShowIncomingData.Name = "lbShowIncomingData";
            this.lbShowIncomingData.Size = new System.Drawing.Size(714, 214);
            this.lbShowIncomingData.TabIndex = 13;
            // 
            // btnCsvIOStart
            // 
            this.btnCsvIOStart.Location = new System.Drawing.Point(404, 244);
            this.btnCsvIOStart.Name = "btnCsvIOStart";
            this.btnCsvIOStart.Size = new System.Drawing.Size(86, 23);
            this.btnCsvIOStart.TabIndex = 14;
            this.btnCsvIOStart.Text = "Start logging";
            this.btnCsvIOStart.UseVisualStyleBackColor = true;
            this.btnCsvIOStart.Click += new System.EventHandler(this.btnCsvIO_Click);
            // 
            // btnCsvIOStop
            // 
            this.btnCsvIOStop.Location = new System.Drawing.Point(496, 244);
            this.btnCsvIOStop.Name = "btnCsvIOStop";
            this.btnCsvIOStop.Size = new System.Drawing.Size(83, 23);
            this.btnCsvIOStop.TabIndex = 15;
            this.btnCsvIOStop.Text = "Stop logging";
            this.btnCsvIOStop.UseVisualStyleBackColor = true;
            this.btnCsvIOStop.Click += new System.EventHandler(this.btnCsvIO_Click);
            // 
            // btnCsvIOClearListBox
            // 
            this.btnCsvIOClearListBox.Location = new System.Drawing.Point(585, 244);
            this.btnCsvIOClearListBox.Name = "btnCsvIOClearListBox";
            this.btnCsvIOClearListBox.Size = new System.Drawing.Size(86, 23);
            this.btnCsvIOClearListBox.TabIndex = 16;
            this.btnCsvIOClearListBox.Text = "Clear List Box";
            this.btnCsvIOClearListBox.UseVisualStyleBackColor = true;
            this.btnCsvIOClearListBox.Click += new System.EventHandler(this.btnCsvIO_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1130, 450);
            this.Controls.Add(this.btnCsvIOClearListBox);
            this.Controls.Add(this.btnCsvIOStop);
            this.Controls.Add(this.btnCsvIOStart);
            this.Controls.Add(this.lbShowIncomingData);
            this.Controls.Add(this.textBoxShowSpeed);
            this.Controls.Add(this.trackBarSpeed);
            this.Controls.Add(this.btnMovementLeftwards);
            this.Controls.Add(this.btnMovementRightwards);
            this.Controls.Add(this.btnMovementForwards);
            this.Controls.Add(this.btnMovementBackwards);
            this.Controls.Add(this.btnMovementStop);
            this.Controls.Add(this.btnDisconnect);
            this.Controls.Add(this.btnConnect);
            this.Controls.Add(this.cbBaudRates);
            this.Controls.Add(this.lblBaudRate);
            this.Controls.Add(this.lblPortName);
            this.Controls.Add(this.cbPorts);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.trackBarSpeed)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cbPorts;
        private System.Windows.Forms.Label lblPortName;
        private System.Windows.Forms.Label lblBaudRate;
        private System.Windows.Forms.ComboBox cbBaudRates;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.Button btnDisconnect;
        private System.Windows.Forms.Button btnMovementStop;
        private System.Windows.Forms.Button btnMovementBackwards;
        private System.Windows.Forms.Button btnMovementForwards;
        private System.Windows.Forms.Button btnMovementRightwards;
        private System.Windows.Forms.Button btnMovementLeftwards;
        private System.Windows.Forms.TrackBar trackBarSpeed;
        private System.Windows.Forms.TextBox textBoxShowSpeed;
        private System.Windows.Forms.ListBox lbShowIncomingData;
        private System.Windows.Forms.Button btnCsvIOStart;
        private System.Windows.Forms.Button btnCsvIOStop;
        private System.Windows.Forms.Button btnCsvIOClearListBox;
    }
}

