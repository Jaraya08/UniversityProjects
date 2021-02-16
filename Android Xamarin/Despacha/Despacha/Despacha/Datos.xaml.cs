using Despacha.Despacha.Models;
using Plugin.FilePicker;
using Plugin.FilePicker.Abstractions;
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
    public partial class Datos : ContentPage
    {

        private string _gAdsolutePath = "";
        public Datos()
        {
            InitializeComponent();
        }

        private void Button_Clicked(object sender, EventArgs e)
        {
            string dbPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "Despacho.db3");

            var db = new SQLiteConnection(dbPath);

            db.Table<Despacho>().Delete(d => d.Despachado==0 | d.Despachado == 1);


            int NoContenedor = 1000000;

            for (int i = 0; i < 100; i++)
            {
                Despacho despacho = new Despacho();
                despacho.Contenedor = "CRSU" + (NoContenedor + i + 1).ToString();
                despacho.Tamanho = "B40";
                db.Insert(despacho);
            }

            App.Current.MainPage = new HomePage();

            return;
            
        }

        private async void btnCargar_Clicked(object sender, EventArgs e)
        {
            try
            {
                bool answer = await DisplayAlert("Confirmación", "¿Esta seguro que quiere cargar los datos del archivo seleccionado?", "Si", "No");
                if (answer)
                {
                    readFilexlxs readFilexlxs = new readFilexlxs();

                    readFilexlxs.leerExcel(_gAdsolutePath);
                }
            }
            catch (Exception ex)
            {

                await DisplayAlert("ERROR", ex.ToString(),"OK");
            }

        }

        private async void brnEnvioDatos_Clicked(object sender, EventArgs e)
        {

            bool answer = await DisplayAlert("Confirmación", "¿Esta seguro que quiere enviar el correo?", "Si", "No");

            if (answer)
            {
                EnvioCorreos envioCorreos = new EnvioCorreos();

                var restuld = envioCorreos.sendEmail(txbEmail.Text);
                if (restuld.Equals("0"))
                {
                    await DisplayAlert("ERROR", "Imposible Enviar mensaje","OK");
                }
            } 
        }

        private async void btnBuscarArchivo_Clicked(object sender, EventArgs e)
        {
            string[] tipos = { "*.xlsx" };

            FileData file = await CrossFilePicker.Current.PickFile(tipos);

            if (file != null)
            {
                _gAdsolutePath = file.FilePath;
                
                txbNombreArchivo.Text = file.FileName;
            }            
        }
    }
}