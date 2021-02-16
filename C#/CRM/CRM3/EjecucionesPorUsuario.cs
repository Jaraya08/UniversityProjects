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
    public partial class EjecucionesPorUsuario : Form
    {
        public EjecucionesPorUsuario()
        {
            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewEjecuciones, "" +
                "SELECT [Nombre de Usuario], [Cantidad de Ejecuciones] FROM CantidadEjecucionesUsuario ORDER BY [Cantidad de Ejecuciones] ASC ");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewEjecuciones, "" +
    "SELECT [Nombre de Usuario], [Cantidad de Ejecuciones] FROM CantidadEjecucionesUsuario ORDER BY [Cantidad de Ejecuciones] ASC ");
        }

        private void buttonDESC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewEjecuciones, "" +
    "SELECT [Nombre de Usuario], [Cantidad de Ejecuciones] FROM CantidadEjecucionesUsuario ORDER BY [Cantidad de Ejecuciones] DESC ");
        }
    }
}
