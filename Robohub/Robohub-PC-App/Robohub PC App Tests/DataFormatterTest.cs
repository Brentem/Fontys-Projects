using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Robohub_PC_App;

namespace Robohub_PC_App_Tests
{
    [TestClass]
    public class DataFormatterTest
    {
        [TestMethod]
        public void DataFormatter_FormatSensorData()
        {
            // Arrange
            byte[] bytes = { 0x55, 0x09, // AccX = 2389
            0x07, 0x06, // AccY = 1543
            0x34, 0x3F, // AccZ = 16180
            0x5F, 0x00, // AnalogLight = 95
            0xEC, 0xA9, // Input = 43500 Flux = 435
            0x27, 0x02, // AnalogWarmth = 551
            0x54, 0x0B // Input = 2900 Temperature = 29
            };

            // Act
            SensorData data = DataFormatter.FormatSensorData(bytes);

            // Assert
            Assert.AreEqual(2389, data.AccX);
            Assert.AreEqual(1543, data.AccY);
            Assert.AreEqual(16180, data.AccZ);
            Assert.AreEqual(95, data.AnalogLight);
            Assert.AreEqual(435, data.Flux);
            Assert.AreEqual(551, data.AnalogWarmth);
            Assert.AreEqual(29, data.Temperature);
        }
    }
}
