using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace CRM3
{
    public partial class Inicio : Form
    {

        public Inicio()
        {
            InitializeComponent();

        }

        private void FamiliaProdMasVendida_Click(object sender, EventArgs e)
        {
            
                /*chartBarras.Palette = ChartColorPalette.BrightPastel;
                chartBarras.DataSource = ConexionBD.CargarDatos("SELECT [Nombre de la Familia] as Familia,[Monto Vendido] as Monto FROM FamiliaMasVendida");
                chartBarras.Series["Series1"].LegendText = "Familia Mas Vendida";
                chartBarras.Series["Series1"].XValueMember = "Familia";
                chartBarras.Series["Series1"].YValueMembers = "Monto";*/
                FamiliaProductos FP = new FamiliaProductos();
                FP.Visible = true;
           
        }
        private void VentCotPorDet_Click(object sender, EventArgs e)
        {
            /*chartBarras.Palette = ChartColorPalette.BrightPastel;
            chartBarras.DataSource = ConexionBD.CargarDatos("SELECT [Nombre del Departamento] as Departamento,[Ventas Por Departamentos] AS Ventas," +
                "[Cotizaciones Por Departamento] as Cotizaciones FROM ContizacionesYVentasPorDep");
            chartBarras.Series["Cotizaciones"].LegendText = "Ventas Departamentos";
            chartBarras.Series["Ventas"].LegendText = "Cotizaciones Departamentos";
            chartBarras.Series["Ventas"].XValueMember = "Departamento";
            chartBarras.Series["Ventas"].YValueMembers = "Cotizaciones";
            chartBarras.Series["Cotizaciones"].YValueMembers = "Ventas";*/
            VentasPorZona Zonas = new VentasPorZona();
            Zonas.Visible = true;


        }

        private void Top10Clientes_Click(object sender, EventArgs e)
        {
            Top10Clientes Cliente = new CRM3.Top10Clientes();
            Cliente.Visible = true;
  
        }

        private void buttonTop10Prod_Click(object sender, EventArgs e)
        {
            Top10Productos Productos = new Top10Productos();
            Productos.Visible = true;
        }

        private void buttonProdMasCotizados_Click(object sender, EventArgs e)
        {
            Top10ProdCotizados ProdCot = new Top10ProdCotizados();
            ProdCot.Visible = true;

        }

        private void buttonVentasSector_Click(object sender, EventArgs e)
        {
            VentasPorSector ventasSector = new VentasPorSector();
            ventasSector.Visible = true;
        }

        private void buttonVentasPorDep_Click(object sender, EventArgs e)
        {
            VentasPorDepartamentos departamentos = new VentasPorDepartamentos();
            departamentos.Visible = true;
        }

        private void buttonVentasYCotPorDep_Click(object sender, EventArgs e)
        {
            VentYCotPorDep VentasYCotizaciones = new VentYCotPorDep();
            VentasYCotizaciones.Visible = true;
        }

        private void buttonClientePorUsuairo_Click(object sender, EventArgs e)
        {
            ClientesPorUsuario CantCliente = new ClientesPorUsuario();
            CantCliente.Visible = true;
        }

        private void buttonVendedoresMayor_Click(object sender, EventArgs e)
        {
            Top10Vendedores vendedores = new Top10Vendedores();
            vendedores.Visible = true;
        }

        private void buttonEjecucionesConCierre_Click(object sender, EventArgs e)
        {
            CantidadEjecuciones ejecuciones = new CantidadEjecuciones();
            ejecuciones.Visible = true;
        }

        private void buttonCasosPorEstado_Click(object sender, EventArgs e)
        {
            CasosPorEstado casos = new CasosPorEstado();
            casos.Visible = true;
        }

        private void buttonVentYCliet_Click(object sender, EventArgs e)
        {
            VentasClientesPorZona ventasClientes = new VentasClientesPorZona();
            ventasClientes.Visible = true;
        }

        private void buttonVentasYCot_Click(object sender, EventArgs e)
        {
            VentasyCotPorMes ventas = new VentasyCotPorMes();
            ventas.Visible = true;
        }

        private void buttonCerrar_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonaCotMasActivyTareas_Click(object sender, EventArgs e)
        {
            CotizacionesActividadYTareas CotizacionesMasTyA = new CotizacionesActividadYTareas();
            CotizacionesMasTyA.Visible = true;
        }

        private void buttonCasosPorTipo_Click(object sender, EventArgs e)
        {
            CasosPorTipo tipos = new CasosPorTipo();
            tipos.Visible = true;
        }

        private void buttonEjecucionesPorUsuario_Click(object sender, EventArgs e)
        {
            EjecucionesPorUsuario ejecuciones = new EjecucionesPorUsuario();
            ejecuciones.Visible = true;
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }
    } 

}
