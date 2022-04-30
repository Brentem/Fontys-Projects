using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CsvHelper;
using System.IO;
using System.Globalization;
using CsvHelper.Configuration;
using System.Diagnostics;

//https://joshclose.github.io/CsvHelper/examples/writing/appending-to-an-existing-file/
//https://zetcode.com/csharp/csv/
//https://superuser.com/a/1222081
//https://docs.microsoft.com/en-us/dotnet/api/system.io.directory.createdirectory?view=net-5.0
//https://docs.microsoft.com/answers/answers/245316/view.html
//https://stackoverflow.com/a/7898476

namespace Robohub_PC_App
{
    class CSVLogger
    {
        private bool firstWrite = true;
        private string filePath = "";
        private string fileName = "";

        public void CreateDirectory()
        {
            if (String.IsNullOrEmpty(filePath))
            {
                string currentDirectory = AppDomain.CurrentDomain.BaseDirectory;
                string path = Path.Combine(currentDirectory, @"..\..\..\..\Data");
                filePath = Path.GetFullPath(path);

                if (!Directory.Exists(filePath))
                {
                    Directory.CreateDirectory(filePath);
                }
            }
        }

        public void WriteData(SensorData sensorData)
        {
            if (firstWrite)
            {
                var config = new CsvConfiguration(CultureInfo.InvariantCulture)
                {
                    HasHeaderRecord = true,
                    Delimiter = ";"
                };

                fileName = @"\Sensor Data " + DateTime.Now.ToString("yyyyMMddHHmmss") + ".csv";

                using (StreamWriter writer = new StreamWriter(filePath + fileName))
                using (CsvWriter csvWriter = new CsvWriter(writer, config))
                {
                    csvWriter.WriteHeader<SensorData>();
                    csvWriter.NextRecord();

                    csvWriter.WriteRecord(sensorData);
                    csvWriter.NextRecord();

                    writer.Flush();
                    firstWrite = false;
                }
            }
            else
            {
                var config = new CsvConfiguration(CultureInfo.InvariantCulture)
                {
                    HasHeaderRecord = false,
                    Delimiter = ";"
                };

                using (var stream = File.Open(filePath + fileName, FileMode.Append))
                using (var writer = new StreamWriter(stream))
                using (var csv = new CsvWriter(writer, config))
                {
                    csv.WriteRecord(sensorData);
                    csv.NextRecord();
                    writer.Flush();
                }
            }
        }
    }
}
