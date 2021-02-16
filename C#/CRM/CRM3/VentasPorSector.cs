using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;


namespace CRM3
{
    public partial class VentasPorSector : Form
    {
        public VentasPorSector()
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
                    chart1.DataSource = ConexionBD.CargarDatos("SELECT [Nombre del Sector] as Sector ,[Monto Vendido] as Ventas FROM  FUN_VentasPorSectorMes (" + año + "," + mes + ")");
                    chart1.Series["Series1"].LegendText = "Sector";
                    chart1.Series["Series1"].YValueMembers = "Ventas";
                    chart1.Series["Series1"].XValueMember = "Sector";
                    ConexionBD.llenarTablas(dataGridView1, "SELECT [Nombre del Sector] as Sector ,[Monto Vendido] as Ventas FROM  FUN_VentasPorSectorMes (" + año + "," + mes + ")");
                }
                catch (Exception ex) {
                    MessageBox.Show("Filtro Mes: Uno de los campos mes / año no tiene el formato correcto","AVISO", MessageBoxButtons.OK,MessageBoxIcon.Information);
                }
            }
            else if (radioButtonRango.Checked)
            {
                String fecha1 = dateTimePickerInicio.Text;
                string fecha2 = dateTimePickerFinal.Text;
                chart1.DataSource = ConexionBD.CargarDatos("SELECT [Nombre del Sector] as Sector ,[Monto Vendido] as Ventas FROM  FUN_VentasPorSectorRango ('" + fecha1 + "','" + fecha2 + "')");
                chart1.Series["Series1"].LegendText = "Sector";
                chart1.Series["Series1"].YValueMembers = "Ventas";
                chart1.Series["Series1"].XValueMember = "Sector";
                ConexionBD.llenarTablas(dataGridView1, "SELECT[Nombre del Sector] as Sector,[Monto Vendido] as Ventas FROM  FUN_VentasPorSectorRango ('" + fecha1 + "','" + fecha2 + "')");

            }
            else
            {
                MessageBox.Show("No se Puede realizar el Grafico sin un filtro", "AVISO", MessageBoxButtons.OK);
            }


        }

        private void GrapVentasPorSector_Load(object sender, EventArgs e)
        {
            dateTimePickerInicio.Format = DateTimePickerFormat.Custom;
            dateTimePickerInicio.CustomFormat = "yyyy-MM-dd";
            dateTimePickerFinal.Format = DateTimePickerFormat.Custom;
            dateTimePickerFinal.CustomFormat = "yyyy-MM-dd";
        }

        private void maskedTextBoxAnno_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }
    }
}
