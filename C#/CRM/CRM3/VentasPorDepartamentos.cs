using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CRM3
{
    public partial class VentasPorDepartamentos : Form
    {
        public VentasPorDepartamentos()
        {
            InitializeComponent();
        }

        private void buttonConsultar_Click(object sender, EventArgs e)
        {
            if (radioButtonMes.Checked)

                try
                {
                    int mes = comboBoxMeses.SelectedIndex + 1;
                    int año = Int32.Parse(maskedTextBoxAnno.Text);
                    chart1.DataSource = ConexionBD.CargarDatos("SELECT [Nombre del Departamento] as Departamento,[Porcentaje de Ventas Sobre 100] as Porcentaje FROM FUN_VentasPorDepartamentoMes(" + año + "," + mes + ")");
                    chart1.Series["Series1"].LegendText = "Departamento";
                    chart1.Series["Series1"].YValueMembers = "Porcentaje";
                    chart1.Series["Series1"].XValueMember = "Departamento";
                    ConexionBD.llenarTablas(dataGridView1, "SELECT [Nombre del Departamento] as Departamento,[Porcentaje de Ventas Sobre 100] as Porcentaje FROM FUN_VentasPorDepartamentoMes(" + año + ", " + mes + ")");
                }
                catch (Exception ex) {
                    MessageBox.Show("Filtro Mes: Uno de los campos mes / año no tiene el formato correcto", "AVISO", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }

            else if (radioButtonRango.Checked)
            {
                String fecha1 = dateTimePickerInicio.Text;
                string fecha2 = dateTimePickerFinal.Text;
                chart1.DataSource = ConexionBD.CargarDatos("select [Nombre del Departamento] as Departamento,[Porcentaje de Ventas Sobre 100] as Porcentaje from FUN_VentasPorDepartamentoRango ('" + fecha1 + "','" + fecha2 + "')");
                chart1.Series["Series1"].LegendText = "Departamento";
                chart1.Series["Series1"].YValueMembers = "Porcentaje";
                chart1.Series["Series1"].XValueMember = "Departamento";
                ConexionBD.llenarTablas(dataGridView1, "select [Nombre del Departamento] as Departamento,[Porcentaje de Ventas Sobre 100] as Porcentaje from FUN_VentasPorDepartamentoRango ('" + fecha1 + "','" + fecha2 + "')");

            }
            else
            {
                MessageBox.Show("No se Puede realizar el Grafico sin un filtro", "AVISO", MessageBoxButtons.OK);
            }
        }

        private void VentasPorDepartamentos_Load(object sender, EventArgs e)
        {
            dateTimePickerInicio.Format = DateTimePickerFormat.Custom;
            dateTimePickerInicio.CustomFormat = "yyyy-MM-dd";
            dateTimePickerFinal.Format = DateTimePickerFormat.Custom;
            dateTimePickerFinal.CustomFormat = "yyyy-MM-dd";
        }

    }
}
