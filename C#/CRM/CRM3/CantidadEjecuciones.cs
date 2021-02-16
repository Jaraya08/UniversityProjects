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
    public partial class CantidadEjecuciones : Form
    {
        public CantidadEjecuciones()
        {
            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewEjecuciones, "" +
                "SELECT [Numero Mes],[Mes de Cierre],[Año Cierre],[Cantidad De Procesos] FROM FUN_EjecucionesPorCierreDeMesAño (2017) ORDER BY [Cantidad De Procesos] ASC ");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            if (maskedTextBoxAño.Text == "")
            {
                MessageBox.Show("El Filtro es obligatorio , favor ingresar un año","AVISO",MessageBoxButtons.OK,MessageBoxIcon.Information);
            }
            else
            {
                ConexionBD.llenarTablas(dataGridViewEjecuciones, "" +
                                "SELECT [Numero Mes],[Mes de Cierre],[Año Cierre],[Cantidad De Procesos] FROM FUN_EjecucionesPorCierreDeMesAño (" + maskedTextBoxAño.Text + ") ORDER BY [Cantidad De Procesos] ASC ");
            }
        }

        private void buttonDESC_Click(object sender, EventArgs e)
        {
            if (maskedTextBoxAño.Text == "")
            {
                MessageBox.Show("El Filtro es obligatorio , favor ingresar un año", "AVISO", MessageBoxButtons.OK,MessageBoxIcon.Information);
            }
            else
            {
                ConexionBD.llenarTablas(dataGridViewEjecuciones, "" +
                                "SELECT [Numero Mes],[Mes de Cierre],[Año Cierre],[Cantidad De Procesos] FROM FUN_EjecucionesPorCierreDeMesAño (" + maskedTextBoxAño.Text + ") ORDER BY [Cantidad De Procesos] DESC ");
            }
        }
    }
}
