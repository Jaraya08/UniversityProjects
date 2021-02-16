using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace SistemaGestor
{
    public partial class Departamento : Form
    {
        ManejoBD codigo = new ManejoBD();
        ConexionBD conexion = new ConexionBD();
        Componentes tabla = new Componentes();

        public Departamento()
        {
            InitializeComponent();
        }
        
        private void Departamento_Load(object sender, EventArgs e)
        {
            tabla.llenarTablas(dataGridViewDepartamentos,"SELECT Codigo_Departamento, Nombre_Departamento From Departamentos");
            textBoxCodigoDepa.Text = Convert.ToString(codigo.ultimoCodigo("Codigo_Departamento","Departamentos"));
        }

        private void buttonAgregarDepa_Click(object sender, EventArgs e)
        {
            try
            {
                if (veficar())
                {
                    MessageBox.Show("Espacio 'Nombre Departamento' NO Puede ser Vacio", "AVISO", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    codigo.agregarDepartamento(textBoxNombreDepa.Text);
                    tabla.llenarTablas(dataGridViewDepartamentos,"SELECT Codigo_Departamento, Nombre_Departamento From Departamentos");
                    textBoxCodigoDepa.Text = Convert.ToString(codigo.ultimoCodigo("Codigo_Departamento", "Departamentos"));
                    vaciasCampos(); 
                }
            }
            catch(SqlException ex)
            {
                MessageBox.Show("Se produjo una excepcion :"+ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Se produjo una Exepcion inesperada :" + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
            }
        }

        private void buttonbuttonEliminarDepartamento_Click(object sender, EventArgs e)
        {
            try
            {
                int id = (int)dataGridViewDepartamentos.CurrentRow.Cells["Codigo"].Value;
                codigo.eliminarDepartamento(id);
                tabla.llenarTablas(dataGridViewDepartamentos,"SELECT Codigo, Nombre From Departamento");
            }
            catch (SqlException ex)
            {
                MessageBox.Show("Se produjo una Exepcion: " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Se Produjo una Excepcion Inesperada : " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void buttonVolver_Click(object sender, EventArgs e)
        {
            cFormPrincipal volver = new cFormPrincipal();
            volver.Show();
            Visible = false;
            
        }

        private void vaciasCampos()
        {
            textBoxNombreDepa.Text ="";
        }

        private Boolean veficar()
        {
            if (textBoxNombreDepa.Text == "")
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }
}
