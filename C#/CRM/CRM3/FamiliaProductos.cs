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
    public partial class FamiliaProductos : Form
    {
 
        public FamiliaProductos()
        {            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewFamProd, "SELECT [Nombre de la Familia],[Monto Vendido] FROM FamiliaMasVendida ORDER BY [Monto Vendido] ASC");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewFamProd, "SELECT [Nombre de la Familia],[Monto Vendido] FROM FamiliaMasVendida ORDER BY [Monto Vendido] ASC");
        }
        private void buttonDESC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewFamProd, "SELECT [Nombre de la Familia],[Monto Vendido] FROM FamiliaMasVendida ORDER BY [Monto Vendido] DESC");

        }
    }
}
