using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Despacha.Despacha.Models;
using SQLite;
namespace Despacha
{
    public class createDB
    {

        public void CreateDataBase()
        {
 
            if (File.Exists(@"/data/user/0/com.tecoop.despacha/files/Despacho.db3"))
            {                
                return;
            }
            else
            {
                string dbPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "Despacho.db3");

                var db = new SQLiteConnection(dbPath);

                db.CreateTable<Despacho>();
                
                return;
            }

        }
    }
    

}
