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
    public partial class VentasyCotPorMes : Form
    {
        public VentasyCotPorMes()
        {
            InitializeComponent();
            chart1.DataSource = ConexionBD.CargarDatos("SELECT [Año] AS Año,[Cotización Anual] as Cotizaciones" +
                ",[Venta Anual] AS Ventas FROM VentasCotizaciones");
            chart1.Series["Series1"].LegendText = "Ventas";
            chart1.Series["Series2"].LegendText = "Cotizaciones";
            chart1.Series["Series1"].XValueMember = "Año";
            chart1.Series["Series1"].YValueMembers = "Ventas";
            chart1.Series["Series2"].YValueMembers = "Cotizaciones";
            
        }

    }
}
