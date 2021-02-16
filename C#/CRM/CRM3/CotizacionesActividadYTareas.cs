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
    public partial class CotizacionesActividadYTareas : Form
    {
        public CotizacionesActividadYTareas()
        {
            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewCotizacion, "" +
                "SELECT [Numero Cotizacion],[Suma Actividades y Tareas Registradas] FROM CotizacionesActividadYTareas ORDER BY" +
                "[Suma Actividades y Tareas Registradas] ASC ");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewCotizacion, "" +
                "SELECT [Numero Cotizacion],[Suma Actividades y Tareas Registradas] FROM CotizacionesActividadYTareas ORDER BY" +
                "[Suma Actividades y Tareas Registradas] ASC ");
        }

        private void buttonDESC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewCotizacion, "" +
                "SELECT [Numero Cotizacion],[Suma Actividades y Tareas Registradas] FROM CotizacionesActividadYTareas ORDER BY" +
                "[Suma Actividades y Tareas Registradas] DESC"); 
        }
    }
}
