using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Data;

namespace SistemaGestor
{
    class Componentes
    {

        SqlDataAdapter da;
        SqlDataReader dr;
        SqlCommand cmm;
        ConexionBD conexion = new ConexionBD();

        /* Recibe una tabla y la llena con la consulta recibida*/
        public DataGridView llenarTablas(DataGridView dgv, string comando)
        {
            conexion.conectar();
            try
            {
                cmm = new SqlCommand(comando, conexion.getConexion());
                DataTable dt = new DataTable();
                da = new SqlDataAdapter(cmm);
                da.Fill(dt);
                dgv.DataSource = dt;
                
            }
            catch (Exception ex)
            {
                if(ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                conexion.desconectar();     
            }
            return dgv;

        }

        /*Recibe una combobox y la llena con la consulta recibida*/
        public ComboBox llenarCombo(ComboBox cmb, SqlCommand cmm,String columna)
        {
            dr = cmm.ExecuteReader();
            while (dr.Read())
            {
                cmb.Items.Add(dr[columna].ToString());
            }
            dr.Close();
            return cmb;


        }
        
    }
}




