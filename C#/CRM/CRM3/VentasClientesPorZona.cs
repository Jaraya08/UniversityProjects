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
    public partial class VentasClientesPorZona : Form
    {
        public VentasClientesPorZona()
        {
            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewClientesYVentas, "" +
                "SELECT [Nombre de la Zona],[Cantidad Clientes Por Zona],[Monto Vendido Zona] FROM ClientesYVentasPorZona ORDER BY [Monto Vendido Zona] ASC");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewClientesYVentas, "" +
               "SELECT [Nombre de la Zona],[Cantidad Clientes Por Zona],[Monto Vendido Zona] FROM ClientesYVentasPorZona ORDER BY [Monto Vendido Zona] ASC");

        }

        private void buttonDESC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewClientesYVentas, "" +
               "SELECT [Nombre de la Zona],[Cantidad Clientes Por Zona],[Monto Vendido Zona] FROM ClientesYVentasPorZona ORDER BY [Monto Vendido Zona] DESC");

        }
    }
}
