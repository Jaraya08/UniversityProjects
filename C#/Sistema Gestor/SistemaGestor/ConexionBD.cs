using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace SistemaGestor
{
    class ConexionBD
    {
        SqlConnection Conexion = new SqlConnection(@"Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=SistemaGestor;Data Source=LAPTOP-MMH0A6BI\SQLEXPRESS");


        /*Abre la conexion de la base de datos*/
        public  SqlConnection conectar() {
              Conexion.Open();
            return Conexion;
        }
        /* Cierra la conexion de la base de datos*/
        public  SqlConnection desconectar() {
             Conexion.Close();
            return Conexion;
        }
        /*Devuelve el string de conexion*/
        public SqlConnection getConexion() {
            return Conexion;
        }
    }
}
