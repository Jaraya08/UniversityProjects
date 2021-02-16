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
    public partial class CasosPorEstado : Form
    {
        public CasosPorEstado()
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
                    chart1.DataSource = ConexionBD.CargarDatos("SELECT  [Nombre de Estado] AS Estado,[Cantidad de Estados] as Cantidad FROM FUN_CasosPorEstadoMes (" + año + "," + mes + ")");
                    chart1.Series["Series1"].LegendText = "Casos";
                    chart1.Series["Series1"].YValueMembers = "Cantidad";
                    chart1.Series["Series1"].XValueMember = "Estado";
                    ConexionBD.llenarTablas(dataGridView1, "SELECT  [Nombre de Estado] AS Estado,[Cantidad de Estados] as Cantidad FROM  FUN_CasosPorEstadoMes (" + año + "," + mes + ")");
                }
                catch(Exception ex)
                {
                    MessageBox.Show("Filtro Mes: Uno de los campos mes / año no tiene el formato correcto", "AVISO", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            else if (radioButtonRango.Checked)
            {
                String fecha1 = dateTimePickerInicio.Text;
                string fecha2 = dateTimePickerFinal.Text;
                chart1.DataSource = ConexionBD.CargarDatos("SELECT  [Nombre de Estado] AS Estado ,[Cantidad de Estados] as Cantidad FROM  FUN_CasosPorEstadoRango ('" + fecha1 + "','" + fecha2 + "')");
                chart1.Series["Series1"].LegendText = "Casos";
                chart1.Series["Series1"].YValueMembers = "Cantidad";
                chart1.Series["Series1"].XValueMember = "Estado";
                ConexionBD.llenarTablas(dataGridView1, "SELECT  [Nombre de Estado] AS Estado ,[Cantidad de Estados] as Cantidad FROM  FUN_CasosPorEstadoRango ('" + fecha1 + "','" + fecha2 + "')");

            }
            else
            {
                MessageBox.Show("No se Puede realizar el Grafico sin un filtro", "AVISO", MessageBoxButtons.OK);
            }
        }

        private void CasosPorEstado_Load(object sender, EventArgs e)
        {
            dateTimePickerInicio.Format = DateTimePickerFormat.Custom;
            dateTimePickerInicio.CustomFormat = "yyyy-MM-dd";
            dateTimePickerFinal.Format = DateTimePickerFormat.Custom;
            dateTimePickerFinal.CustomFormat = "yyyy-MM-dd";
        }
    }
}
