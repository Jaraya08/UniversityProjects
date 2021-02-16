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
    public partial class ClientesPorUsuario : Form
    {
        public ClientesPorUsuario()
        {
            InitializeComponent();
            ConexionBD.llenarTablas(dataGridViewClientesPorUsuario,"" +
                "SELECT [Nombre del Usuario],[Cantidad Contactos] FROM CantidadContactosPorUsuario ORDER BY [Cantidad Contactos] ASC");
        }

        private void buttonaASC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewClientesPorUsuario, "" +
                "SELECT [Nombre del Usuario],[Cantidad Contactos] FROM CantidadContactosPorUsuario ORDER BY [Cantidad Contactos] ASC");
        }

        private void buttonDESC_Click(object sender, EventArgs e)
        {
            ConexionBD.llenarTablas(dataGridViewClientesPorUsuario, "" +
                "SELECT [Nombre del Usuario],[Cantidad Contactos] FROM CantidadContactosPorUsuario ORDER BY [Cantidad Contactos] DESC");

        }
    }
}
