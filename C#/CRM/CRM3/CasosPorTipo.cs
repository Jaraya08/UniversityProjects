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
    public partial class CasosPorTipo : Form
    {
        public CasosPorTipo()
        {
            InitializeComponent();
        }

        private void buttonConsultar_Click(object sender, EventArgs e)
        {
            if (radioButtonMes.Checked)
            {
                try
                {
                    int mes = comboBoxMeses.SelectedIndex + 1;
                    int año = Int32.Parse(maskedTextBoxAnno.Text);
                    chart1.DataSource = ConexionBD.CargarDatos("SELECT  [Nombre de Tipo] AS Tipo,[Cantidad de Casos] as Cantidad FROM FUN_CasosPorTipoMes (" + año + "," + mes + ")");
                    chart1.Series["Series1"].LegendText = "Estado";
                    chart1.Series["Series1"].YValueMembers = "Cantidad";
                    chart1.Series["Series1"].XValueMember = "Tipo";
                    ConexionBD.llenarTablas(dataGridView1, "SELECT   [Nombre de Tipo] AS Tipo,[Cantidad de Casos] as Cantidad FROM FUN_CasosPorTipoMes (" + año + "," + mes + ")");
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Filtro Mes: Uno de los campos mes / año no tiene el formato correcto", "AVISO", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            else if (radioButtonRango.Checked)
            {
                String fecha1 = dateTimePickerInicio.Text;
                string fecha2 = dateTimePickerFinal.Text;
                chart1.DataSource = ConexionBD.CargarDatos("SELECT  [Nombre de Tipo] AS Tipo,[Cantidad de Casos] as Cantidad FROM  FUN_CasosPorTiporRango ('" + fecha1 + "','" + fecha2 + "')");
                chart1.Series["Series1"].LegendText = "Estado";
                chart1.Series["Series1"].YValueMembers = "Cantidad";
                chart1.Series["Series1"].XValueMember = "Tipo";
                ConexionBD.llenarTablas(dataGridView1, "SELECT  [Nombre de Tipo] AS Tipo,[Cantidad de Casos] as Cantidad FROM  FUN_CasosPorTiporRango ('" + fecha1 + "','" + fecha2 + "')");

            }
        }

        private void CasosPorTipo_Load(object sender, EventArgs e)
        {
            dateTimePickerInicio.Format = DateTimePickerFormat.Custom;
            dateTimePickerInicio.CustomFormat = "yyyy-MM-dd";
            dateTimePickerFinal.Format = DateTimePickerFormat.Custom;
            dateTimePickerFinal.CustomFormat = "yyyy-MM-dd";
        }
    }
}
