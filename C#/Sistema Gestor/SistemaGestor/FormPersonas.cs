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
    public partial class FormPersonas : Form
    {
        ManejoBD BD = new ManejoBD();
        Componentes componente = new Componentes();
        SqlCommand cmm = new SqlCommand();
        ConexionBD conexion = new ConexionBD();


        public FormPersonas()
        {
            InitializeComponent();
            componente.llenarTablas(dataGridViewPersonas,"SELECT Cedula,Nombre,Apellido,Rol FROM Personas");
            componente.llenarTablas(dataGridViewProyectos,"SELECT Codigo_Correcion, Nombre_Coreccion FROM ProyectoCorreccion");
            componente.llenarTablas(dataGridViewProyPers, "SELECT Cedula,Nombre,Apellido,Codigo_Proyecto FROM PersonasProyectos");
        }

        private void contextMenuStripEliminarPersona_MouseClick(object sender, MouseEventArgs e)
        {
            string cedula = dataGridViewPersonas.CurrentRow.Cells["Cedula"].Value.ToString();
            BD.eliminarPersProy(cedula);
            BD.eliminarPersona(cedula);
            componente.llenarTablas(dataGridViewPersonas,"SELECT Cedula,Nombre,Apellido,Rol FROM Personas");
            componente.llenarTablas(dataGridViewProyPers, "SELECT Cedula,Nombre,Apellido,Codigo_Proyecto FROM PersonasProyectos");



        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                if (validar()) {
                    MessageBox.Show("Los Campos no pueden ser vacios ", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    BD.agregarPersona(textBoxNombre.Text, textBoxCedula.Text, textBoxApellido.Text, textBoxRol.Text);
                    componente.llenarTablas(dataGridViewPersonas, "SELECT Cedula,Nombre,Apellido,Rol FROM Personas");
                    textBoxCedula.Text = ""; textBoxNombre.Text = ""; textBoxApellido.Text = ""; textBoxRol.Text = "";
                }
            }
                
            catch(SqlException ex)
            {
                MessageBox.Show("Se produjo una excepcion " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Ser produjo una excepcion inesperada " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            
        }


        private void textBoxCedula_Enter(object sender, EventArgs e)
        {
            if (!String.IsNullOrEmpty(textBoxCedula.Text))
            {
                textBoxCedula.SelectionStart = 0;
                textBoxCedula.SelectionLength = textBoxCedula.Text.Length;
            }
        }

        private void textBoxNombre_Enter(object sender, EventArgs e)
        {
            if (!String.IsNullOrEmpty(textBoxNombre.Text))
            {
                textBoxNombre.SelectionStart = 0;
                textBoxNombre.SelectionLength = textBoxNombre.Text.Length;
            }
        }

        private void textBoxApellido_Enter(object sender, EventArgs e)
        {
            if (!String.IsNullOrEmpty(textBoxNombre.Text))
            {
                textBoxApellido.SelectionStart = 0;
                textBoxApellido.SelectionLength = textBoxApellido.Text.Length;
            }
        }

        private void textBoxRol_Enter(object sender, EventArgs e)
        {
            if (!String.IsNullOrEmpty(textBoxNombre.Text))
            {
                textBoxRol.SelectionStart = 0;
                textBoxRol.SelectionLength = textBoxRol.Text.Length;
            }
        }

        private void comboBoxPersonas_MouseClick(object sender, MouseEventArgs e)
        {
            comboBoxPersonas.Items.Clear();
            conexion.conectar();
            componente.llenarCombo(comboBoxPersonas, cmm = new SqlCommand("SELECT Cedula FROM Personas ", conexion.getConexion()), "Cedula");
            conexion.desconectar();

        }

        private void comboBoxProyectos_MouseClick(object sender, MouseEventArgs e)
        {
            comboBoxProyectos.Items.Clear();
            conexion.conectar();
            componente.llenarCombo(comboBoxProyectos, cmm = new SqlCommand("SELECT Codigo_Correcion FROM ProyectoCorreccion", conexion.getConexion()),"Codigo_Correcion");
            conexion.desconectar();

        }

        private void buttonAgregarPerProy_Click(object sender, EventArgs e)
        {
            if (comboBoxPersonas.Text == "" | comboBoxProyectos.Text == "")
            {
                MessageBox.Show("Se deben llenar las dos cajas de Texto ", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                BD.personasProyect(Convert.ToInt32(comboBoxProyectos.SelectedItem), comboBoxPersonas.SelectedItem.ToString());
                componente.llenarTablas(dataGridViewProyPers, "SELECT * FROM PersonasProyectos");
                conexion.desconectar();
            }
        }

        private void buttonVolver_Click(object sender, EventArgs e)
        {
            cFormPrincipal volver = new cFormPrincipal();
            volver.Visible = true;
            Visible = false;
        }

        private Boolean validar()
        {
            if(textBoxNombre.Text==""| textBoxApellido.Text=="" | textBoxCedula.Text=="" | textBoxRol.Text == "")
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
