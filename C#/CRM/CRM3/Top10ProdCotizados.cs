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
    public partial class Top10ProdCotizados : Form
    {
        public Top10ProdCotizados()
        {
            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewProductosCotizados, "" +
                "SELECT [Nombre del Producto],[Monto Cotizado] FROM ProductosMasCotizados ORDER BY [Monto Cotizado] ASC");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewProductosCotizados, "" +
    "SELECT [Nombre del Producto],[Monto Cotizado] FROM ProductosMasCotizados ORDER BY [Monto Cotizado] ASC");
        }

        private void buttonDESC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewProductosCotizados, "" +
    "SELECT [Nombre del Producto],[Monto Cotizado] FROM ProductosMasCotizados ORDER BY [Monto Cotizado] DESC");
        }
    }
}
