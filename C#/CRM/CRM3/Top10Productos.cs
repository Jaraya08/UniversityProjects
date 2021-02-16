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
    public partial class Top10Productos : Form
    {
        public Top10Productos()
        {
            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewProductos, "SELECT [Nombre de Producto],[Monto Vendido] FROM ProductosMasVendidos ORDER BY [Monto Vendido] ASC ");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewProductos, "SELECT [Nombre de Producto],[Monto Vendido] FROM ProductosMasVendidos ORDER BY [Monto Vendido] ASC ");

        }

        private void buttonDESC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewProductos, "SELECT [Nombre de Producto],[Monto Vendido] FROM ProductosMasVendidos ORDER BY [Monto Vendido] DESC ");

        }

        private void Top10Productos_Load(object sender, EventArgs e)
        {

        }
    }
}
