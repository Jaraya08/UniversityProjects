using Despacha.Despacha.Models;
using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Despacha
{
    public partial class App : Application
    {
        public App()
        {

            createDB BD = new createDB();

            BD.CreateDataBase();

            InitializeComponent();

            MainPage = new HomePage();
            
        }

        protected override void OnStart()
        {
        }

        protected override void OnSleep()
        {
        }

        protected override void OnResume()
        {
        }
    }
}
