using Despacha.Despacha.Models;
using SQLite;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Despacha
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class Despachados : ContentPage
    {

        static string dbPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "Despacho.db3");

        static SQLiteConnection db = new SQLiteConnection(dbPath);

        TableQuery<Despacho> vDespachoData = db.Table<Despacho>();

        public Despachados()
        {
            InitializeComponent();

            var CL_Todos = vDespachoData.ToList();

            var CL_Contanedores = vDespachoData.Where(d => d.Despachado == 1).OrderByDescending(d => d.FechaSalida).ToList();

            lvw_Despachados.ItemsSource = CL_Contanedores;

            lblTitulo.Text = "Despachados " + CL_Contanedores.Count + "/" + CL_Todos.Count;

        }

        private void CountriesSearchBar_TextChanged(object sender, TextChangedEventArgs e)
        {
            var CL_Contanedores = vDespachoData.Where(d => d.Contenedor.Contains(CountriesSearchBar.Text) & d.Despachado == 1).OrderByDescending(d => d.FechaSalida).ToList(); ;

            lvw_Despachados.ItemsSource = CL_Contanedores;

        }
    }
}