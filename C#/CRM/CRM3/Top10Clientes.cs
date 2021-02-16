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
    public partial class Top10Clientes : Form
    {
        public Top10Clientes()
        {
            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewClientes, "SELECT [Nombre del Cliente],[Monto Comprado] FROM ClientesConMayorVenta ORDER BY [Monto Comprado] ASC");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewClientes, "SELECT [Nombre del Cliente],[Monto Comprado] FROM ClientesConMayorVenta ORDER BY [Monto Comprado] ASC");

        }

        private void buttonDESC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewClientes, "SELECT [Nombre del Cliente],[Monto Comprado] FROM ClientesConMayorVenta ORDER BY [Monto Comprado] DESC");

        }
    }
}
