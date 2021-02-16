using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data;
using System.Data.SqlClient;

namespace CRM3
{
    class ConexionBD
    {
        static SqlConnection Conexion = new SqlConnection(@"Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=CRM;Data Source=LAPTOP-MMH0A6BI\SQLEXPRESS");
        static SqlDataAdapter da;
        static SqlDataReader dr;
        static SqlCommand cmm;

        public ConexionBD() { }

        public static void ejecutarConsulta(String sql)
        {
            Conexion.Open();
            SqlCommand cmd = new SqlCommand(sql, Conexion);
            cmd.ExecuteNonQuery();
            Conexion.Close();
        }
        /* Recibe una tabla y la llena con la consulta recibida*/
        public static DataGridView llenarTablas(DataGridView dgv, string comando)
        {
            try
            {
                Conexion.Open();
                cmm = new SqlCommand(comando, Conexion);
                DataTable dt = new DataTable();
                da = new SqlDataAdapter(cmm);
                da.Fill(dt);
                dgv.DataSource = dt;

            }
            catch (Exception ex)
            {
                if (ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.Close();
            }
            return dgv;

        }
        public static DataTable CargarDatos(String Sql) {
            Conexion.Open();
            DataTable tabla = new DataTable(); ;
            try
            {
                cmm = new SqlCommand(Sql, Conexion);
                da = new SqlDataAdapter(cmm);
                da.Fill(tabla);
            }
            catch (Exception ex)
            {
                if (ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.Close();
               
            }
            return tabla;
        }
    }

}
