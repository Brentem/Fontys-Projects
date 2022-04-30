using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Robohub_PC_App;
using System.IO.Ports;

namespace Robohub_PC_App_Tests
{
    [TestClass]
    public class BTConnectionTest
    {
        [TestMethod]
        public void BTConnection_Constructor()
        {
            // Arrange
            SerialPort port = new SerialPort("COM9", 9600);

            // Act
            BTConnection connection = new BTConnection(port);

            // Assert
            Assert.AreEqual(connection.Port, port);
        }

        [ExpectedException(typeof(ArgumentNullException))]
        [TestMethod]
        public void BTConnection_ConstructorPortNull()
        {
            // Arrange
            Form1 form = new Form1();

            // Act
            BTConnection connection = new BTConnection(null);

            // Assert
            Assert.IsTrue(false, "The constructor parameters aren't allowed to be null!");
        }
    }
}
