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
    public partial class Top10Vendedores : Form
    {
        public Top10Vendedores()
        {
            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewVendedores, "" +
                "SELECT [Nombre del Vendedor], [Monto Vendido] FROM VendedoresConMayorVenta ORDER BY [Monto Vendido] ASC ");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewVendedores, "" +
                 "SELECT [Nombre del Vendedor], [Monto Vendido] FROM VendedoresConMayorVenta ORDER BY [Monto Vendido] ASC ");
    }

        private void buttonDESC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewVendedores, "" +
                "SELECT [Nombre del Vendedor], [Monto Vendido] FROM VendedoresConMayorVenta ORDER BY [Monto Vendido] DESC ");

        }

        private void Top10Vendedores_Load(object sender, EventArgs e)
        {

        }
    }
}
