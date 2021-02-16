using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SistemaGestor
{
    public partial class cFormPrincipal : Form
    {
        public cFormPrincipal()
        {
            InitializeComponent();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            Aplicaciones Aplicacion = new Aplicaciones();
            Aplicacion.Visible = true;
            Visible = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Departamento depa = new Departamento();
            depa.Show();
            Visible = false;
            
       }

        private void button3_Click(object sender, EventArgs e)
        {
            FormServidores servidores = new FormServidores();
            servidores.Visible = true;
            Visible = false;
        }

        private void buttonErrores_Click(object sender, EventArgs e)
        {
            SistemaDeGestion Errores = new SistemaDeGestion();
            Errores.Visible = true;
            Visible = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            FormPersonas personas = new FormPersonas();
            personas.Visible = true;
            Visible = false;
        }

        private void buttonCerrarSistema_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
