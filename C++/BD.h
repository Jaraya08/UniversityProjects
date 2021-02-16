#include <sys/time.h>
#include <stdlib.h>
#include <mysql.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class manejoBD
{

	private:
	
		MYSQL_RES *result;
		MYSQL *ptr_conexion, mysql;
		MYSQL_ROW row;
		int query_state;
		
		/*E: NINGUNA
		 *S: ABRE UNA CONEXION DE BASE DE DATOS
		 *R: LA BASE DE DATOS DEBE EXISTIR
		 *O: ABRIR UNA CONEXION A UNA BASE DE DATOS 
		 * */
		void abrirConexion()
		{
			mysql_init(&mysql);
			ptr_conexion = mysql_real_connect(&mysql,"localhost","root","jordanHAL.881992","TC3LP",0,0,0);
			if(!ptr_conexion)
			{
				cout<<"*****NO SE PUDO CONECTAR CON LA BASE DE DATOS*****"<<endl;
			}
		}
		
		/*E:NINGUNA
		 *S: CIERRA UNA CONEXION DE BASE DE DATOS 
		 *R: LA BASE DE DATOS DEBE ESTAR ABIERTA 
		 *O: CERRAR UNA CONEXION DE BASE DE DATOS
		 * */
		void cerrarConexion()
		{
			mysql_close(ptr_conexion);
		}
		

	public:
	
		/*E: UN STRING CON UNA SENTENCIA SQL
		 *S: LA EJECUCION DE LA SENTCIA EN EL MOTOR DE BASE DE DATOS MYSQL
		 *R: LA CONSULTA DEBE TENER LA SINTAXIS CORRECTA
		 *O: EJECUTAR CONSULTAS EN LA BASE DE DATOS 
		 * */
		int executarConsulta(string consulta)
		{
			abrirConexion();
			query_state=mysql_query(ptr_conexion, consulta.c_str());
			int afectadas = mysql_affected_rows(&mysql);
			result = mysql_use_result(ptr_conexion);
			if(query_state!=0 | (mysql_affected_rows(&mysql)==0)) 
			{
				cout<<"\nERROR : "<<mysql_error(ptr_conexion)<<endl<<endl;
				return 0;
			}
			mysql_free_result(result);
			cerrarConexion();
			return 1;
		}
		
		/*E: UN SNTRING CON UNA SENTENCIA SQL,ARREGLO DE STRING CON NUMEROS,UN LA CANTIDAD DE COLUMNAS DE LA CONSULTA
		 *S: LA IMPRESION DE LA CONSULTA EN PANTALLA
		 *R: EL RESULTADO DE LA CONSULTA DEBE CONTENER DATOS
		 *O: IMPRIMIR CONSULTAS DE SQL EN LA PANTALLA
		 * */
		void verConsula(string consulta,string array[],int len)
		{
			abrirConexion();
			query_state=mysql_query(ptr_conexion, consulta.c_str());
			result = mysql_use_result(ptr_conexion);
			if(query_state!=0)
			{
				cout<<mysql_error(ptr_conexion)<<endl<<endl;
			}
			while(row = mysql_fetch_row(result))
			{
				for(int i=0;i<len;i++)
				{
					string formato="%-"+array[i]+"s"; 
					printf(formato.c_str(),row[i]);
				}
				printf("\n");
			}
			mysql_free_result(result);
			cerrarConexion();
		}
		
		/*E: UN SENTENCIA DE SQL, Y UN ENTERO QUE REPRESENTA LA CANTIDAD DE COLUMNAS QUE VA A TENER LA CONSULTA
		 *S: UN VECTOR  DE VECTORES CON LO DATOS DE LA CONSULTA 
		 *R: LA CONSULTA DEBE SER CORRECTA 
		 *O: RETORNAR UNA MATRIZ CON LOS DATOS DE LA CONSULTA INGRESADA PARA PODER MOSTRARSE EN PANTALLA 
		 * */
		vector< vector <string> > obtenerDatos(string consulta,int columnas)
		{
			int afectadas = filasAfectadas(consulta);
			abrirConexion();
			query_state=mysql_query(ptr_conexion, consulta.c_str());
			vector< vector<string> > productos (afectadas,std::vector<string>(columnas,""));
			result = mysql_use_result(ptr_conexion);
			int i=0;
			if(query_state!=0)
			{
				cout<<mysql_error(ptr_conexion)<<endl<<endl;
			}
			while(row = mysql_fetch_row(result))
			{
				for(int j=0;j<columnas;j++)
				{
					productos[i][j]=row[j];
				}
				i++;
			}
			mysql_free_result(result);
			cerrarConexion();
			return productos;
		}
		
		/*E: UNA SENTENCIA SQL 
		 *S: LA CANTIDAD DE FILAS AFECTADAS EN LA BASE DE DATOS CON ESA CONSULTA
		 *R: NINGUNA
		 *O: DEVOLVER LA CANTIDAD DE FILAS QUE FUERA AFECTAS CON LA CONSULTA INGRESADA
		 * */
		int filasAfectadas(string consulta)
		{
			abrirConexion();
			query_state=mysql_query(ptr_conexion, consulta.c_str());
			result=mysql_store_result(ptr_conexion);
			int afectadas = mysql_num_rows(result);
			cerrarConexion();
			return afectadas;
		}
		
		/*E: NINGUNA
		 *S: EL NUMERO DE LA SIGUIENTE FACTURA
		 *R: NINGUNA
		 *O: RETORNAR LA SIGUENTE FACTURA DE LA BASE DE DATOS PARA PODER INSERTAR LO PRODUCTOS
		 * */
		string siguienteFactura()
		{
			string factura,consulta;
			consulta="INSERT INTO T_Facturas (CedulaCliente,CedulaLocal,FechaRegistro,SubTotal,Impuestos,total) values(null,null,null,null,null,null)";
			executarConsulta(consulta);
			abrirConexion();
			consulta = "SELECT MAX(NumeroFactura) FROM T_Facturas";
			query_state=mysql_query(ptr_conexion, consulta.c_str());
			result = mysql_use_result(ptr_conexion);
			while(row=mysql_fetch_row(result))
			{
				factura=row[0];
			}
			cerrarConexion();
			return factura;
			
		}
		
		/*E: UN VECTOR CON LOS PRODUCTOS REGISTRADOS 
		 *S: IMPRIMIR EN PANTALLA LA LISTA DE FORMA ORDENADA PARA SER VISUALIZADA POR EL USUARIO  
		 *R: LA LISTA DEBE TENER DATOS
		 *O: IMPRIMIR LA LISTA DE PRODUCTOS PARA SER VIZUALIZADA POR EL USUARIO 
		 * */
		void imprimirProductos(vector < vector <string> > lista)
		{
			printf("\n%-7s %-15s %-25s %-22s %-15s\n","Linea","Id Producto","Nombre","Categoria","Precio sin impuesto");
			printf("\n");
			string array[4]={"16","26","23","20"};
			for(int i=0;i<lista.size();i++)
			{
				printf("%-8d",i+1);
				for(int j=0;j<4;j++)
				{
					string formato="%-"+array[j]+"s";
					printf(formato.c_str(),lista[i][j].c_str());
				}
				printf("\n");
			}
		}
		
		/*E: UNA LISTA CON EL DETALLE DE PRODUCTOS DE UNA FACTURA
		 *S: IMPRIMIR EN PANTALLA EL LISTADO DE PRODUCTOS DE UNA FACTURA
		 *R: DEBEN EXISTIR PRODUCTOS EN LA LISTA
		 *O: IMPRIMIR EN PANTALLA LOS PRODUCTOS DE UNA FACTURA 
		 * */
		void detalleFactura(vector <vector <string> > lista)
		{
			printf("\n\n********** LISTA DE PRODUCTOS EN FACTURA **********\n\n");
			printf("\n%1s %10s %10s %24s %16s %12s %14s %14s %13s %10s\n","Linea","ID Prod.","Nombre","Categoria","Cant","Precio Uni","SubTotal","Impuesto","Impuestos","Total");
			printf("\n");
			string array[9]={"11","23","22","8","15","15","13","15","10"};
			for(int i=0;i<lista.size();i++)
			{
				printf("%-10d",i+1);
				for(int j=0;j<9;j++)
				{
					string formato="%-"+array[j]+"s";
					printf(formato.c_str(),lista[i][j].c_str());
				}
				printf("\n");
			}
		}
		
		/*E: UN NUMERO DE UNA FACTURA 
		 *S: IMPRIMIR TODO EL DETALLE DE LA FACTURA INGRESADA
		 *R: LA FACTURA DEBE EXISTIR
		 *O: MOSTARLE AL USUARIO TODA LA INFORMACION DE UNA FACTURA 
		 * */
		void mostrarFactura(string factura)
		{
			string consulta,detalle;
			consulta= "SELECT DF.Factura,DF.Fecha,DF.Cedula,DF.Nombre,DF.CedLocal,DF.Locall,DF.Subtotal,DF.Impuestos,DF.Total FROM V_DatosFactura AS DF WHERE Factura="+factura;
			detalle="SELECT IdProducto,Producto,Categoria,Cantidad,Precio,SubTotal,Impuesto,Impuestos,Total FROM V_detalleFactura WHERE idFactura ="+factura;
			vector < vector <string> > datosFactura;
			vector < vector <string> > detalleFact;
			datosFactura=obtenerDatos(consulta,9);
			detalleFact=obtenerDatos(detalle,9);
			if(datosFactura.size()==0)
			{
				printf("\n\n******************** LA FACTURA CONSULTADA NO EXISTE ********************\n\n");
			}
			else
			{
				printf("%-20s","\n\n******************** MOSTRANDO DATOS DE FACTURA ********************\n\n");
				printf("%-15s %-25s %-15s %-15s","Numero de Factura:",datosFactura[0][0].c_str(),"Fecha Factura:",datosFactura[0][1].c_str());
				printf("\n");
				printf("%-18s %-25s %-15s %-15s","Cliente: ",datosFactura[0][3].c_str(),"Cedula: ",datosFactura[0][2].c_str());
				printf("\n");
				printf("%-18s %-25s %-15s %-15s","Local: ",datosFactura[0][5].c_str(),"Cedula: ",datosFactura[0][4].c_str());
				printf("\n");
				detalleFactura(detalleFact);
				printf("\n");
				printf("%-15s %-15s\n","SubTotal: ",datosFactura[0][6].c_str());
				printf("%-15s %-13s\n","Impuestos:",datosFactura[0][7].c_str());
				printf("%-15s %-18s\n","Total: ",datosFactura[0][8].c_str());
			}
		}
};
