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
    public partial class FormServidores : Form
    {
        ConexionBD conexion = new ConexionBD();
        SqlCommand cmm;
        ManejoBD BD = new ManejoBD();
        Componentes componente = new Componentes();

        public FormServidores()
        {
            InitializeComponent();
            componente.llenarTablas(dataGridViewServidores, "SELECT Serie,Marca,Modelo,CapacidadPROC,CapacidadALM,MemoriaRAM FROM Servidor");
            componente.llenarTablas(dataGridViewRoles, "SELECT Codigo_rol,Tipo_Rol FROM RolesServidores");
            componente.llenarTablas(dataGridViewRolesPorServ, "SELECT Serie_Servidor,TipoRol,Codigo_Rol FROM RolesDeServidor");
        }


        private void buttonAgregarSer_Click(object sender, EventArgs e)
        {
            try
            {
                if (validar())
                {
                    MessageBox.Show("Todos los espacios deben ser llenados ", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    BD.agregarServidor(textBoxSerie.Text, textBoxMarca.Text, textBoxModelo.Text, Convert.ToDouble(textBoxProc.Text), Convert.ToDouble(textBoxProc.Text), Convert.ToDouble(textBoxRam.Text));
                    componente.llenarTablas(dataGridViewServidores, "SELECT Serie,Marca,Modelo,CapacidadPROC,CapacidadALM,MemoriaRAM FROM Servidor");

                    vaciasCampos();
                }

            }
            catch (SqlException ex)
            {
                MessageBox.Show("Se produjo un Exepcion :" + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (InvalidCastException ex)
            {
                MessageBox.Show("Hubo un error de conversion numerica : " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (FormatException ex)
            {
                MessageBox.Show("Hubo un error en un formato de un campo, favor verificar : " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Se produjo un error inesperado "+ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                vaciasCampos();
            }

        }

        private void comboBox2_MouseClick(object sender, MouseEventArgs e)
        {
            comboBoxServidores.Items.Clear();
            conexion.conectar();
            componente.llenarCombo(comboBoxServidores, cmm = new SqlCommand("SELECT Serie From Servidor", conexion.getConexion()), "Serie");
            conexion.desconectar();
        }

        private void buttonAgregarRol_Click(object sender, EventArgs e)
        {
            conexion.conectar();
            try
            {
                if (textBoxNuevoRol.Text == "")
                {
                    MessageBox.Show("Se requiere llenar el campo", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    BD.agregarRol(textBoxNuevoRol.Text);
                    componente.llenarTablas(dataGridViewRoles, "SELECT Codigo_Rol,Tipo_Rol FROM RolesServidores");
                }
                
            }
            catch (SqlException ex)
            {
                MessageBox.Show("Se produjo una excepcion "+ex,"ERROR",MessageBoxButtons.OK,MessageBoxIcon.Error);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Se produjo una exepcion inesperada : " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                conexion.desconectar();
            }


        }

        private void comboBoxRoles_MouseClick(object sender, MouseEventArgs e)
        {
            comboBoxRoles.Items.Clear();
            conexion.conectar();
            componente.llenarCombo(comboBoxRoles, cmm = new SqlCommand("SELECT Tipo_rol FROM RolesServidores", conexion.getConexion()), "Tipo_Rol");
            conexion.desconectar();
        }

        private void buttonVolver_Click(object sender, EventArgs e)
        {
            cFormPrincipal volver = new cFormPrincipal();
            volver.Visible = true;
            Visible = false;
        }

        private void contextMenuStripServidores_MouseClick(object sender, MouseEventArgs e)
        {
            BD.eliminarRolASer(dataGridViewServidores.CurrentRow.Cells["Serie"].Value.ToString());
            BD.eliminarServDeApliacion(dataGridViewServidores.CurrentRow.Cells["Serie"].Value.ToString());
            BD.eliminarServidor(dataGridViewServidores.CurrentRow.Cells["Serie"].Value.ToString());
            componente.llenarTablas(dataGridViewServidores, "SELECT Serie,Marca,Modelo,CapacidadPROC,CapacidadALM,MemoriaRAM FROM Servidor");
            componente.llenarTablas(dataGridViewRolesPorServ, "SELECT Serie_Servidor,TipoRol,Codigo_Rol FROM RolesDeServidor");

        }


        private void contextMenuStripRoles_MouseClick(object sender, MouseEventArgs e)
        {
            try
            {
                BD.eliminarRol((int)dataGridViewRoles.CurrentRow.Cells["Codigo_Rol"].Value);
                componente.llenarTablas(dataGridViewRoles, "SELECT Codigo_rol,Tipo_Rol FROM RolesServidores");
            }
            catch (SqlException ex)
            {
                MessageBox.Show("Se produjo una excepcion :" + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Se produjo una excepcion inesperada " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private Boolean validar()
        {
            if (textBoxSerie.Text == "" | textBoxMarca.Text == "" | textBoxModelo.Text == "" |
                textBoxProc.Text == "" | textBoxAlm.Text == "" | textBoxRam.Text == "")
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private void vaciasCampos()
        {
            textBoxSerie.Text = "";
            textBoxMarca.Text = "";
            textBoxModelo.Text = "";
            textBoxAlm.Text = "";
            textBoxProc.Text = "";
            textBoxRam.Text = "";
        }

        private void buttonAsignarRol_Click(object sender, EventArgs e)
        {
            try
            {
                if(comboBoxRoles.Text=="" | comboBoxServidores.Text == "")
                {
                    MessageBox.Show("Para asignar Rol a un servidor se requiere escoger un rol y un servidor ", "ADVERTENCIA", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                else
                {
                    BD.rolAServidor(comboBoxRoles.SelectedItem.ToString(), comboBoxServidores.SelectedItem.ToString());
                    componente.llenarTablas(dataGridViewRolesPorServ, "SELECT Serie_Servidor,TipoRol,Codigo_Rol FROM RolesDeServidor");
                }

            }
            catch (SqlException ex)
            {
                MessageBox.Show("Se produjo una excepcion " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
