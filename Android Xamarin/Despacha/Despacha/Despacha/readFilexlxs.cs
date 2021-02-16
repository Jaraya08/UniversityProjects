using Despacha.Despacha.Models;
using SQLite;
using Syncfusion.XlsIO;
using System;
using System.IO;
using System.Reflection;


namespace Despacha
{
    class readFilexlxs
    {

        public void leerExcel(string pAbsolutePath)
        {
            try
            {
                string dbPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "Despacho.db3");

                var db = new SQLiteConnection(dbPath);

                db.Table<Despacho>().Delete(d => d.Despachado == 0 | d.Despachado == 1);

                ExcelEngine excelEngine = new ExcelEngine();

                using (var stream = File.Open(pAbsolutePath, FileMode.Open, FileAccess.Read))
                {
                    var workbook = excelEngine.Excel.Workbooks.Open(stream);

                    var worksheet = workbook.Worksheets["Listado"];

                    var usedRange = worksheet.UsedRange;

                    for (int i = 3; i <= usedRange.LastRow; i++)
                    {
                        Despacho despacho = new Despacho();
                        despacho.Contenedor = worksheet[i, 1].DisplayText;
                        despacho.Tamanho = worksheet[i, 2].DisplayText;
                        db.Insert(despacho);
                    }

                }
                App.Current.MainPage = new HomePage();
            }
            catch (Exception ex)
            {
                throw ex;
            }
            
        }
    }
}
