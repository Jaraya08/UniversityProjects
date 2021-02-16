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
    public partial class datosDespacho : ContentPage
    {

        private static string _gNumeroContenedor;
        public datosDespacho(string NumeroContenedor)
        {
            _gNumeroContenedor = NumeroContenedor;

            InitializeComponent();

            txbContenedor.Text = NumeroContenedor;

            txbFecha.Text = DateTime.Now.ToString("dd-MM-yyyy HH:mm");

            btnDespachar.IsEnabled = false;

        }

        private void btnCancelar_Clicked(object sender, EventArgs e)
        {
            App.Current.MainPage = new HomePage();

        }

        private void btnDespachar_Clicked(object sender, EventArgs e)
        {
            var dbPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "Despacho.db3");

            var db = new SQLiteConnection(dbPath);

            var vDespachoData = db.Table<Despacho>().Where(d => d.Contenedor == _gNumeroContenedor).First();

            vDespachoData.Despachado = 1;

            vDespachoData.Placa = txbPlaca.Text;

            vDespachoData.Marchamo = txbMarchamo.Text;

            vDespachoData.FechaSalida = txbFecha.Text;

            db.Update(vDespachoData);
           
            App.Current.MainPage = new HomePage();
        }
        private void txbPlaca_TextChanged(object sender, TextChangedEventArgs e)
        {
            (sender as Entry).Text = e.NewTextValue.ToUpperInvariant();

            if (e.NewTextValue.Equals(""))
            {                
                lblPlacaIsvalid.IsVisible = true;
                btnDespachar.IsEnabled = false;
            }
            else
            {
                lblPlacaIsvalid.IsVisible = false;

                if(txbMarchamo.Text != null)
                {
                    if(txbMarchamo.Text != "")
                    {
                        btnDespachar.IsEnabled = true;
                    }
                }               
            }
        }

        private void txbMarchamo_TextChanged(object sender, TextChangedEventArgs e)
        {
            (sender as Entry).Text = e.NewTextValue.ToUpperInvariant();

            if (e.NewTextValue.Equals(""))
            {
                lblMarchamoIsvalid.IsVisible = true;
                btnDespachar.IsEnabled = false;
            }
            else
            {
                lblMarchamoIsvalid.IsVisible = false;

                if (txbPlaca.Text != null)
                {
                    if (txbPlaca.Text != "")
                    {
                        btnDespachar.IsEnabled = true;
                    }
                }
             
            }

        }

        
    }
}