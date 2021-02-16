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


    public partial class Aplicaciones : Form
    {
        ConexionBD conexion = new ConexionBD();
        SqlConnection cone = new SqlConnection();
        Componentes comp = new Componentes();
        SqlCommand cmm;
        ManejoBD manejo = new ManejoBD();

        public Aplicaciones()
        {
            InitializeComponent();
            comp.llenarTablas(dataGridViewDepartamentos,"SELECT Codigo_Departamento,Nombre_Departamento FROM Departamentos");
            comp.llenarTablas(dataGridViewAplicacion,"Select Codigo_Software, Nombre_Software,Tipo_Software,Fecha,Departamento,Descripcion_Software FROM Software");
            comp.llenarTablas(dataGridViewApliXServ, "SELECT Serie_Servidores,Codigo_Software FROM Aplicacion_servidor");

        }



        private void Aplicaciones_Load(object sender, EventArgs e) { }

        private void maskedTextBoxFecha_TypeValidationCompleted(object sender, TypeValidationEventArgs e)
        {
            if (!e.IsValidInput)
            {
                MessageBox.Show("El Formato de fecha NO es Correcto", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                maskedTextBoxFecha.Text = "";
                maskedTextBoxFecha.Focus();
            }
            else
            {
                DateTime userDate = (DateTime)e.ReturnValue;
                if (userDate > DateTime.Now)
                {
                    MessageBox.Show("No se acepta fecha mayor a hoy", "AVISO", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    maskedTextBoxFecha.Text = "";
                    maskedTextBoxFecha.Focus();
                }
            }
        }



        private void comboBoxDepartamentos_MouseClick(object sender, MouseEventArgs e)
        {
            comboBoxDepartamentos.Items.Clear();
            conexion.conectar();
            comp.llenarCombo(comboBoxDepartamentos, cmm = new SqlCommand("SELECT Codigo_Departamento FROM Departamentos", conexion.getConexion()), "Codigo_Departamento");
            conexion.desconectar();
        }

        private void comboBoxAplicaciones_MouseClick(object sender, MouseEventArgs e)
        {
            comboBoxAplicaciones.Items.Clear();
            conexion.conectar();
            comp.llenarCombo(comboBoxAplicaciones, new SqlCommand("SELECT Codigo_Software FROM  Software", conexion.getConexion()), "Codigo_Software");
            conexion.desconectar();
        }

        private void buttonVolver_Click(object sender, EventArgs e)
        {
            cFormPrincipal volver = new cFormPrincipal();
            volver.Visible = true;
            Visible = false;
        }

        private void comboBox2_MouseClick(object sender, MouseEventArgs e)
        {
            comboBoxServidor.Items.Clear();
            conexion.conectar();
            comp.llenarCombo(comboBoxServidor, cmm = new SqlCommand("SELECT Serie FROM Servidor", conexion.getConexion()), "Serie");
            conexion.desconectar();


        }

        private void contextMenuStripOpciones_MouseClick(object sender, MouseEventArgs e)
        {
            manejo.eliminarAplicacionSer((int)dataGridViewAplicacion.CurrentRow.Cells["Codigo_Software"].Value);
            manejo.eliminarSoftware((int)dataGridViewAplicacion.CurrentRow.Cells["Codigo_Software"].Value);
            comp.llenarTablas(dataGridViewAplicacion,"Select Codigo_Software, Nombre_Software,Tipo_Software,Fecha,Departamento,Descripcion_Software FROM Software");
            comp.llenarTablas(dataGridViewApliXServ, "SELECT Serie_Servidores,Codigo_Software FROM Aplicacion_servidor");
        }

        private Boolean validarCampos()
        {
            if(comboBoxDepartamentos.Text=="" | textBoxNombre.Text=="" | comboBoxTipo.Text==""
                | maskedTextBoxFecha.Text=="" | textBoxDescripcion.Text == "")
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private void vaciarCampos()
        {
            textBoxNombre.Text = "";
            textBoxDescripcion.Text = "";
            maskedTextBoxFecha.Text = "";

        }

        private void buttonAgregarAplicacion_Click_1(object sender, EventArgs e)
        {
            try
            {
                if (validarCampos())
                {
                    MessageBox.Show("Todos los espacios deben ser llenados", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    manejo.agregarSoftware(textBoxNombre.Text.ToString(), comboBoxTipo.SelectedItem.ToString(), maskedTextBoxFecha.Text.ToString(),
                        Convert.ToInt32( comboBoxDepartamentos.SelectedItem.ToString()) ,textBoxDescripcion.Text.ToString());
                    comp.llenarTablas(dataGridViewAplicacion, "Select Codigo_Software,Nombre_Software,Tipo_Software,Fecha,Departamento,Descripcion_Software FROM Software");
                }

            }
            catch (SqlException ex)
            {
                MessageBox.Show("Se Produjo una Excepcion " + ex.ToString(), "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                MessageBox.Show("Los datos no fueron almacenados, Procure llenar todos los espacios y/o de forma correcta", "AVISO", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            finally
            {
                vaciarCampos();

            }
        }

        private void buttonEnlazarApliASer_Click(object sender, EventArgs e)
        {
            try
            {
                if (comboBoxServidor.Text=="" | comboBoxAplicaciones.Text == "")
                {
                    MessageBox.Show("Se deben llenar los dos campos ", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    manejo.aplicacionAServidor(Convert.ToInt32(comboBoxAplicaciones.SelectedItem), comboBoxServidor.SelectedItem.ToString());
                    comp.llenarTablas(dataGridViewApliXServ, "SELECT Serie_Servidores,Codigo_Software FROM Aplicacion_servidor");
                }
            }
                
            catch(SqlException ex)
            {
                MessageBox.Show("Se produjo una Excepcion :" + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                
            }
            catch(InvalidCastException ex)
            {
                MessageBox.Show("Un elemento no se podo convertir " + ex, "ADVERTENCIA", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }
    }
}
    


    

