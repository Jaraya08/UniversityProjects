using Despacha.Despacha.Models;
using SQLite;
using Syncfusion.XlsIO;
using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.Mail;
using System.Text;

namespace Despacha
{
    public class EnvioCorreos
    {

        public string sendEmail(string vTo)
        {
			try
			{
				string from = "jordan.araya@tecoop.cr";

				MailMessage mailMessage = new MailMessage(from, vTo);

				mailMessage.Subject = "Informe de contendores despachados";

				mailMessage.Body = "NOTA*: Esta es un aplicación de prueba protegida por derechos de autor";

				//agregarmos los archivos al correo                
				Attachment vExcelInfome = new Attachment(createExcel());

				mailMessage.Attachments.Add(vExcelInfome);

				SmtpClient client = new SmtpClient("mail.tecoop.cr", 26);

				client.UseDefaultCredentials = false;

				client.Credentials = new NetworkCredential("jordan.araya@tecoop.cr", "2016254282-Jh");

				client.Send(mailMessage);

				client.Dispose();

				return "1";
			}
			catch (Exception)
			{
				return "0";
			}
            

        }

        public string createExcel()
        {

			 string dbPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "Despacho.db3");

			 SQLiteConnection db = new SQLiteConnection(dbPath);

			 TableQuery<Despacho> vDespachoData = db.Table<Despacho>();

			var CL_Contanedores = vDespachoData.Where(d => d.Despachado == 1).OrderByDescending(d => d.FechaSalida).ToList();

			using (ExcelEngine excelEngine = new ExcelEngine())
			{
				IApplication application = excelEngine.Excel;

				application.DefaultVersion = ExcelVersion.Excel2016;

				//Create a workbook
				IWorkbook workbook = application.Workbooks.Create(1);
				IWorksheet worksheet = workbook.Worksheets[0];

				//Enter details of products and prices
				worksheet.Range["A1"].Text = "CONTENEDOR";
				worksheet.Range["B1"].Text = "TAMAÑO";
				worksheet.Range["C1"].Text = "PLACA";
				worksheet.Range["D1"].Text = "MARCHAMO";
				worksheet.Range["E1"].Text = "FECHA Y HORA DE SALIDA";

				worksheet.Range["A1"].ColumnWidth = 20;
				worksheet.Range["B1"].ColumnWidth = 20;
				worksheet.Range["C1"].ColumnWidth = 20;
				worksheet.Range["D1"].ColumnWidth = 20;
				worksheet.Range["E1"].ColumnWidth = 20;


				var i = 1;
				foreach(var despacho in CL_Contanedores)
				{
					worksheet.Range["A" + (i + 1)].Text = despacho.Contenedor;
					worksheet.Range["B" + (i + 1)].Text = despacho.Tamanho;
					worksheet.Range["C" + (i + 1)].Text = despacho.Placa;
					worksheet.Range["D" + (i + 1)].Text = despacho.Marchamo;
					worksheet.Range["E" + (i + 1)].Text = despacho.FechaSalida;
					i++;
				}
								
				//Saving the Excel to the MemoryStream 
				MemoryStream stream = new MemoryStream();

				workbook.SaveAs(stream);

				//Set the position as '0'.
				stream.Position = 0;


				if (File.Exists(@"/data/user/0/com.tecoop.despacha/files/Informe.xlsx"))
				{
					File.Delete(@"/data/user/0/com.tecoop.despacha/files/Informe.xlsx");
				}
				string path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "Informe.xlsx");
				using (FileStream outputFileStream = new FileStream(path, FileMode.Create))
				{
					stream.CopyTo(outputFileStream);
				}
			}
			return @"/data/user/0/com.tecoop.despacha/files/Informe.xlsx";
		}
          
    }
}
