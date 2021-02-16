using Despacha.Despacha.Models;
using SQLite;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Despacha
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class NoDespachados : ContentPage
    {
        static string dbPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "Despacho.db3");

        static SQLiteConnection db = new SQLiteConnection(dbPath);

        TableQuery<Despacho> vDespachoData = db.Table<Despacho>();

        public NoDespachados()
        {
            InitializeComponent();

            var CL_Todos = vDespachoData.ToList();

            var CL_Contanedores = vDespachoData.Where(d => d.Despachado == 0).OrderBy(d=>d.Contenedor).ToList();

            lvw_NoDespachados.ItemsSource = CL_Contanedores;

            lblTitulo.Text = "Por despachar " + CL_Contanedores.Count.ToString() + "/" + CL_Todos.Count.ToString();
        }

        private void CountriesSearchBar_TextChanged(object sender, TextChangedEventArgs e)
        {                        
            var CL_Contanedores = vDespachoData.Where(d => d.Contenedor.Contains(CountriesSearchBar.Text)).OrderBy(d => d.Contenedor).ToList();

            lvw_NoDespachados.ItemsSource = CL_Contanedores;
        }

        private void lvw_NoDespachados_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            var objDespacho = (Despacho)e.SelectedItem;

            App.Current.MainPage = new datosDespacho(objDespacho.Contenedor);

        }
    }
}