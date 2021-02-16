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
    public partial class SistemaDeGestion : Form
    {
        ConexionBD conexion = new ConexionBD();
        Componentes componente = new Componentes();
        ManejoBD manejo = new ManejoBD();
        SqlCommand cmm = new SqlCommand();
        public SistemaDeGestion()
        {
            InitializeComponent();
            conexion.conectar();
            textBoxIdError.Text=manejo.ultimoCodigo("Codigo_Erro", "ErrorProduccion").ToString();
            textBoxIdProyecto.Text= manejo.ultimoCodigo("Codigo_Correcion", "ProyectoCorreccion").ToString();
            componente.llenarTablas(dataGridViewErrores,"SELECT Codigo_Erro,Serie_Servidor,Nombre_Aplicacion,Fecha_Error,Hora_Error,Impacto,Descripcion_Erro FROM ErrorProduccion ");
            componente.llenarTablas(dataGridViewProyectos,"SELECT Codigo_Correcion,Nombre_Coreccion,FechaINI,FechaFIN,EsfuezoEstimado,EsfuerzoReal,Descripcion_Correcion FROM ProyectoCorreccion");
            conexion.desconectar();
        }

        private void comboBox1_MouseClick(object sender, MouseEventArgs e)
        {
            comboBoxServidor.Items.Clear();
            conexion.conectar();
            componente.llenarCombo(comboBoxServidor, cmm = new SqlCommand("SELECT Serie FROM Servidor", conexion.getConexion()), "Serie");
            conexion.desconectar();
        }

        private void comboBoxAplicacion_MouseClick(object sender, MouseEventArgs e)
        {
            comboBoxAplicacion.Items.Clear();
            conexion.conectar();
            componente.llenarCombo(comboBoxAplicacion, cmm = new SqlCommand("SELECT Nombre_Software FROM Software",conexion.getConexion()),"Nombre_software");
            conexion.desconectar();
        }

        private void buttonAgregarError_Click(object sender, EventArgs e)
        {
            try{
                if (validarError())
                {
                    MessageBox.Show("Los Compos de Error de produccion estan incompletos ", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);

                }
                else if (validarProyecto()) {
                    MessageBox.Show("Los campos del proyectos estan incompletos ", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    DateTime date = Convert.ToDateTime(maskedTextBoxFechaError.Text).Date;
                    DateTime horas = Convert.ToDateTime(maskedTextBoxHora.Text);
                    manejo.agregarError(comboBoxServidor.SelectedItem.ToString(), comboBoxAplicacion.SelectedItem.ToString(), date, horas, comboBoxImpacto.SelectedItem.ToString(), textBoxDescripcionError.Text);
                    manejo.agregarProyecto(textBoxNomProy.Text, maskedTextBoxFechaINI.Text, maskedTextBoxFechaFin.Text, Convert.ToDouble(textBoxEsfuerzoEst.Text.ToString()),Convert.ToDouble( textBoxEsfuerzoReal.Text), textBoxDescripcionProy.Text);
                    componente.llenarTablas(dataGridViewErrores, "SELECT Codigo_Erro,Serie_Servidor,Nombre_Aplicacion,Fecha_Error,Hora_Error,Impacto,Descripcion_Erro FROM ErrorProduccion ");
                    componente.llenarTablas(dataGridViewProyectos, "SELECT Codigo_Correcion,Nombre_Coreccion,FechaINI,FechaFIN,EsfuezoEstimado,EsfuerzoReal,Descripcion_Correcion FROM ProyectoCorreccion");
                }
               
            }
            catch(FormatException ex)
            {
                MessageBox.Show("Existe un error de formato en algun campo "+ex, "ADVERTENCIA", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            catch(InvalidCastException ex)
            {
                MessageBox.Show("No se pudo hacer conversiones, verificar los campos "+ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Se produjo una excepcion inesperada " + ex, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
            

        private void contextMenuStripErrores_MouseClick(object sender, MouseEventArgs e)
        {
            DialogResult  resul =MessageBox.Show("Si un error es elimnado el Proyecto de Correccion tambien se eliminara", "ADVERTENCIA", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (resul == DialogResult.Yes){
                manejo.eliminarError((int)dataGridViewErrores.CurrentRow.Cells["Codigo_Erro"].Value);
                manejo.eliminarProyecto((int)dataGridViewErrores.CurrentRow.Cells["Codigo_Erro"].Value);
                componente.llenarTablas(dataGridViewErrores,"SELECT Codigo_Erro,Serie_Servidor,Nombre_Aplicacion,Fecha_Error,Hora_Error,Impacto,Descripcion_Erro FROM ErrorProduccion ");
                componente.llenarTablas(dataGridViewProyectos,"SELECT Codigo_Correcion,Nombre_Coreccion,FechaINI,FechaFIN,EsfuezoEstimado,EsfuerzoReal,Descripcion_Correcion FROM ProyectoCorreccion");

            }
        }

        private void buttonVolver_Click(object sender, EventArgs e)
        {
            cFormPrincipal volver = new cFormPrincipal();
            volver.Visible = true;
            Visible = false;
        }

        private void maskedTextBoxFechaError_TypeValidationCompleted(object sender, TypeValidationEventArgs e)
        {
            if (!e.IsValidInput)
            {
                MessageBox.Show("El Formato de fecha NO es Correcto", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                maskedTextBoxFechaError.Text = "";
                maskedTextBoxFechaError.Focus();
            }
            else
            {
                DateTime userDate = (DateTime)e.ReturnValue;
                if (userDate > DateTime.Now)
                {
                    MessageBox.Show("No se acepta fecha mayor a hoy", "AVISO", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    maskedTextBoxFechaError.Text = "";
                    maskedTextBoxFechaError.Focus();
                }
            }
        }

        private void maskedTextBoxFechaINI_TypeValidationCompleted(object sender, TypeValidationEventArgs e)
        {
            if (!e.IsValidInput)
            {
                MessageBox.Show("El Formato de fecha NO es Correcto", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                maskedTextBoxFechaINI.Text = "";
                maskedTextBoxFechaINI.Focus();
            }
            else
                {
                    DateTime fechaINI = (DateTime)e.ReturnValue;
                    if (fechaINI > DateTime.Now)
                    {
                        MessageBox.Show("No se acepta fecha mayor a hoy", "AVISO", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        maskedTextBoxFechaINI.Text = "";
                        maskedTextBoxFechaINI.Focus();
                    }
                }
            }

        private void maskedTextBoxFechaFin_TypeValidationCompleted(object sender, TypeValidationEventArgs e)
        {
            if (!e.IsValidInput)
            {
                MessageBox.Show("El Formato de fecha NO es Correcto", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                maskedTextBoxFechaFin.Text = "";
                maskedTextBoxFechaFin.Focus();
            }
        }

        private Boolean validarError()
        {
            if(comboBoxServidor.Text=="" | comboBoxAplicacion.Text =="" |comboBoxImpacto.Text=="" | textBoxDescripcionError.Text == "")
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private Boolean validarProyecto()
        {
            if (textBoxNomProy.Text == "" | textBoxEsfuerzoEst.Text == "" | textBoxEsfuerzoReal.Text == "" | textBoxDescripcionProy.Text == "")
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


