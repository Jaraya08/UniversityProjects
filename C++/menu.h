#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class Menu
{
	private:
		
		/*E: UN STRING 
		 *S: TRUE SI ES NUMERO FALSE SI NO LO ES
		 *R: NINGUNA
		 *O: VERIFICAR UNA CADENA Y RETORNAR SI ES NUMERO O NO 
		 * */
		int ISNUMBER(string numero)
		{
			int len = strlen(numero.c_str());
			for(int i=0;i<len;i++)
			{
				if(!isdigit(numero[i]))
				{
					return 0;
				}
			}
			return 1;
		}
			
		/*E: UN STRING CON UN MENSAJE, Y UN VALOR VACIO
		 *S: RETORNAR EL VALOR CON UN DATOS NUMERICO
		 *R: EL CAMPO QUE SE INGRESA TIENE QUE SER NUMERICO
		 *O: MANTENER AL USURIO EN UN CICLO HASTA QUE INGRESE UN NUMERO. 
		 * */
		string campoNumerico(string mensaje,string valor)
		{
			int ciclo=1;
			while(ciclo)
			{
				cout<<mensaje;
				std::getline (std::cin,valor);
				if(ISNUMBER(valor) & strlen(valor.c_str())!=0)
				{
					ciclo=0;
					return valor;
				}
				else printf("\n\n ***** OPCION INVALIDA, INGRESE UN NUMERO *****\n\n");
			}
			return valor;
		}
		
		/*E: UN STRING CON UN MENSAJE, Y UN VALOR VACIO
		 *S: RETORNAR EL VALOR CON ALGUN DATO
		 *R: EL CAMPO QUE SE INGRESA TIENE QUE TENER CARACTERES
		 *O: MANTENER AL USURIO EN UN CICLO HASTA QUE INGRESE UN CARACTER O CADENA. 
		 * */
		string campoVacio(string mensaje,string valor)
		{
			int ciclo=1;
			while(ciclo)
			{
				cout<<mensaje;
				std::getline (std::cin,valor);
				if(strlen(valor.c_str())!=0)
				{
					ciclo=0;
					return valor;
				}
				else printf("\n\n ***** CAMPO NO PUEDE SER VACIO *****\n\n");
			}
			return valor;
		}
		
	public:
		manejoBD BD;
		
		void menu()
		{
			int ciclo=1;
			string opcion;
			while(ciclo)
			{
				printf("\n\n********** BIENVENIDO AL SISTEMA GESTOR **********\n\n");
				opcion=campoNumerico("Ingrese la accion que desea ejecutar\n1-Categorias\n2-Clientes\n3-Items\n4-Facturacion\n5-Estadisticas\n6-Salir\nOpcion:","");				
				switch (atoi(opcion.c_str()))
				{
					case 1:
						categorias();
						break;
					case 2:
						clientes();
						break;
					case 3: 
						items();
						break;
					case 4:
						facturacion();
						break;
					case 5:
						estadisticas();
						break;
					case 6:
						ciclo=0;
						break;
					default:
						ciclo=1;
						break;						
					}
			}
			printf("\n\n ***** GRACIAS POR USARA EL SISTAMA *****\n\n");
		}
		
		
		void categorias()
		{
			int ciclo=1;
			string opcion;
			while(ciclo)
			{
				printf("\n\n********** BIENVENIDO AL AREA DE CATEGORIAS **********\n\n");
				opcion=campoNumerico("Ingrese la accion de desea realizar\n1-Agregar Categoria\n2-Eliminar Categoria\n3-Ver Categorias\n4-volver\nOpcion:","");
				switch (atoi(opcion.c_str()))
				{
					case 1:
						agregarCategoria();
						break;
					case 2:
						eliminarCategoria();
						break;
					case 3:
						verCategorias();
						break;
					case 4:
						ciclo=0;
						break;
					default:
						ciclo=1;
						break;
				}
			}
		}
		
		void agregarCategoria()
		{
			string nombreItem,tipoCategoria,impuestoItem="0";
			printf("\n");
			nombreItem=campoVacio("Ingrese el Nombre de la categoria: ","");
			int ciclo=1;
			while(ciclo)
			{
				tipoCategoria=campoNumerico("Tipos de categoria\n1-Productos\n2-Servicios\nOpcion:","");
				switch (atoi(tipoCategoria.c_str()))
				{
					case 1:
						tipoCategoria="Productos";
						impuestoItem=campoNumerico("Ingrese el IMPUESTO del producto:","");
						ciclo=0;
						break;
					case 2:
						tipoCategoria="Servicios";
						ciclo=0;
						break;
					default :
						ciclo=1;
						break;
				}
			}
			string insert = "INSERT INTO T_Categorias (Nombre,TipoCategoria,Impuesto) VALUES('"+nombreItem+"','"+tipoCategoria+"',"+impuestoItem+")";
			int res= BD.executarConsulta(insert);
			if(!res)
			{
				printf("\n\n*****NOMBRE DE CATEGORIA YA EXISTE, NO SE AGREGO EL REGISTRO *****\n\n");
			}
			verCategorias();
		}
		
		void eliminarCategoria()
		{
			string idItem;
			verCategorias();
			printf("\n");
			idItem=campoNumerico("Ingrese el numero de CATEGORIA que desea eliminar: ","");
			string consulta = "DELETE FROM T_Categorias WHERE IdCategoria ="+idItem;
			int res = BD.executarConsulta(consulta);
			if(!res)
			{
				cout<<"\n\nNO SE PUDO ELIMINAR LA CATEGORIA, POSIBLES ERRORES\n1-Se Encuentra asosicada a un Item\n2-No Existe\n\n";
			}
			verCategorias();

		}
		
		void verCategorias()
		{
			printf("\n\n**********CATEGORIAS REGISTRADAS**********\n\n");
			string select = "SELECT IdCategoria,Nombre,TipoCategoria,Impuesto FROM T_Categorias";
			printf("\n%1s %10s %25s %15s\n","Id Item","Nombre","Tipo Categoria","Impuesto");
			string array[4]={"12","20","23","20"};
			BD.verConsula(select,array,4);
		}

		void clientes()
		{
			string opcion;
			int ciclo=1;
			while(ciclo)
			{
				printf("\n\n ********** BIENVENIDO AL AREA DE CLIENTES **********\n\n");
				opcion=campoNumerico("Ingrese la acccion que desea realizar\n1-Agregar Cliente\n2-Eliminar Cliente\n3-Ver clientes\n4-Volver\nOpcion:","");
				switch (atoi(opcion.c_str()))
				{
					case 1:
						agregarCliente();
						break;
					case 2: 
						eliminarCliente();
						break;
					case 3:
						verClientes();
						break;
					case 4:
						ciclo=0;
						break;
					default:
						ciclo=1;
						break;
				}
			}	
		}

		void agregarCliente()
		{
			
			string cedula, nombre, apellidos,telefono,consulta;
			cedula=campoVacio("Ingrese la CEDULA del cliente: ","");
			nombre=campoVacio("Ingrese el NOMBRE del cliente: ","");
			apellidos=campoVacio("Ingrese los APELLIDOS del cliente: ","");
			telefono=campoVacio("Ingrese el TELEFONO del cliente :","");
			consulta = "INSERT INTO T_Cliente (Cedula,Nombre,Apellido,Telefono) VALUES('"+cedula+"','"+nombre+"','"+apellidos+"','"+telefono+"')";
			int res = BD.executarConsulta(consulta);
			if(!res)
			{
				printf("\n\n***** CLIENTE YA EXISTE *****\n\n");
			}
			verClientes();	
			
		}
		
		void eliminarCliente()
		{
			string cedula;
			verClientes();
			cedula=campoVacio("Ingrese la CEDULA del cliente que desea eliminar: ","");
			string consulta = "DELETE FROM T_Cliente WHERE Cedula ='"+cedula+"'";
			int res = BD.executarConsulta(consulta);
			if(!res)
			{
				cout<<"\n\nNO SE PUDO ELIMINAR El CLIENTE, POSIBLES ERRORES\n1-Se Encuentra asosicada a una Factura\n2-No Existe\n\n";
			}
			verClientes();
		}
		
		void verClientes()
		{
			printf("\n\n**********CLIENTES REGISTRADAS**********\n\n");
			string select = "SELECT Cedula,Nombre,Apellido,Telefono FROM T_Cliente";
			printf("\n%1s %17s %17s %21s\n","Cedula","Nombre","Apellidos","Telefono");
			printf("\n");
			string array[4]={"18","15","23","20"};
			BD.verConsula(select,array,4);	
		}
	
		void items()
		{
			int ciclo=1;
			string opcion;
			while(ciclo)
			{
				printf("\n\n********** BIENVENIDO AL AREA DE ITEMS **********\n\n");
				opcion=campoNumerico("Ingrese la accion que desea realizar\n1-Agregar Item\n2-Eliminar Item\n3-Ver items\n4-Salir\nOpcion:","");
				switch (atoi(opcion.c_str()))
				{
					case 1:
						agregarItem();
						break;
					case 2:
						eliminarItem();
						break;
					case 3:
						verItems();
						break;
					case 4:
						ciclo=0;
						break;
					default:
						ciclo=1;
						break;
				}
			}
		}
		
		void agregarItem()
		{
			string nombre, categoria,precio,consulta;
			int ciclo1=1,ciclo2=1,queryRes;
			nombre=campoVacio("Ingrese el NOMBRE del item :","");
			verCategorias();
			categoria=campoNumerico("Ingrese la categoria por el IDENTIFICADOR : ","");
			precio=campoNumerico("Ingrese el PRECIO SIN IMPUESTO del item : ","");
			consulta = "INSERT INTO T_Productos (Nombre,Categoria,Precio) VALUES('"+nombre+"',"+categoria+","+precio+")";
			queryRes=BD.executarConsulta(consulta);
			if(!queryRes)
			{
				cout<<"\n\n ***** NO SE PUDO AGREGAR EL ITEM, POSIBLES ERRORES\n1-Ya existe el Item\n2-La categoria Ingresada No Existe*****\n\n";
			}
			verItems();
			
			
		}
		
		void eliminarItem()
		{
			string id,consulta;
			int queryRes;
			verItems();
			id=campoNumerico("\nIngrese el ID del item que desea eliminar :","");
			consulta="DELETE FROM T_Productos WHERE IdProducto ="+id;
			queryRes=BD.executarConsulta(consulta);
			if(!queryRes)
			{
				cout<<"\n\nNO SE PUDO ELIMINAR El ITEM, POSIBLES ERRORES\n1-Se Encuentra asosicada a una factura\n2-No Existe\n\n";
				
			}
			verItems();
			
		}
		
		void verItems()
		{
			printf("\n\n**********ITEMS REGISTRADOS**********\n\n");
			string select = "SELECT IdProducto,Producto,Categoria,Precio FROM V_Productos";
			printf("\n%1s %10s %25s %15s \n","IdProducto","Nombre","Categoria","Precio");
			printf("\n");	
			string array[4]={"15","23","19","20"};
			BD.verConsula(select,array,4);		
		}
		
		void facturacion()
		{
			string opcion;
			int ciclo=1;
			while(ciclo)
			{
				printf("\n\n********** BIENVENIDO AL AREA DE FACTURACION **********\n\n");
				opcion=campoNumerico("Ingrese la accion que desea realizar\n1-Nueva Factura\n2-Consultar Facturas\n3-Ver Facturas\n4-volver\nOpcion:","");
				switch (atoi(opcion.c_str()))
				{
					case 1:
						agregarFactura();
						break;
					case 2:
						consultarFactura();
						break;
					case 3:
						verFactura();
						break;
					case 4:
						ciclo=0;
						break;
					default:
						ciclo=1;
						break;
				}
			}					
		}
		
		void agregarFactura()
		{			
			string opcion,cantidad,consulta,factura,idProducto,detalle,client;
			int res=0,ciclo=1,ciclo2=1,ciclo3=1;
			consulta = "SELECT IdProducto,Producto,Categoria,Precio FROM  V_Productos";			
			factura = BD.siguienteFactura();
			vector < vector <string> > listaProductos;
			vector < vector <string> > detalleFact;
			vector < vector <string> > lClientes;
			listaProductos= BD.obtenerDatos(consulta,4);
			if(listaProductos.size())
			{
				while(ciclo)
				{
					ciclo2=1;
					printf("\n\n ***** MOSTRANDO PRODUCTOS REGISTRADOS *****\n\n");
					BD.imprimirProductos(listaProductos);
					opcion=campoNumerico("Selecione una accion\n1-Selecionar Productos\n2-Filtrar por Categoria\nOpcion:","");
					switch (atoi(opcion.c_str()))
					{
						case 1:
							while(ciclo2)
							{
								opcion = campoNumerico("Ingrese la Linea del productos que desea agregar :","");									
								if(atoi(opcion.c_str())==0 | atoi(opcion.c_str())-1>((listaProductos.size())-1))
								{
									printf("\n\n***** LA SELECCION NO SE ENCUENTRA EN LA LISTA ***** \n\n");
								}
								else
								{
									cantidad = campoNumerico("Ingrese la cantidad de "+listaProductos[atoi(opcion.c_str())-1][1]+" que desea: ","");
									idProducto = listaProductos[atoi(opcion.c_str())-1][0];
									res=BD.executarConsulta("CALL ST_ProductosPorFactura ("+idProducto+","+factura+","+cantidad+")");
									if(!res)
									{
										cout<<"ALGOOO PASOOOO MOOPPP"<<endl;
									}
									else
									{
										ciclo3=1;
										detalle = "SELECT IdProducto,Producto,Categoria,Cantidad,Precio,SubTotal,Impuesto,Impuestos,Total FROM V_detalleFactura WHERE idFactura ="+factura;
										detalleFact= BD.obtenerDatos(detalle,9);
										BD.detalleFactura(detalleFact);
										while(ciclo3)
										{
											opcion=campoNumerico("Ingrese la accion que desea realizar\n1-Agregar Producto\n2-Eliminar Producto\n3-Guardar Factura\nOpcion:","");
											switch (atoi(opcion.c_str()))
											{
												case 1:
													ciclo3=0;
													ciclo2=0;
													break;
												case 2:
													detalleFact= BD.obtenerDatos(detalle,9);
													BD.detalleFactura(detalleFact);
													cout<<"Ingrese la LINEA del detalle que desea eliminar :";
													std::getline (std::cin,opcion);
													if(atoi(opcion.c_str())==0 | atoi(opcion.c_str())-1>((detalleFact.size())-1))
													{
														printf("\n\n***** LA SELECCION NO SE ENCUENTRA EN LA LISTA ***** \n\n");
													}
													else
													{
														idProducto = detalleFact[atoi(opcion.c_str())-1][0];
														res = BD.executarConsulta("DELETE FROM T_ProductosPorFactura WHERE IdFactura ="+factura+" AND IdProductos ="+idProducto);
														detalleFact= BD.obtenerDatos(detalle,9);
														BD.detalleFactura(detalleFact);
													}
													break;
												case 3:								
													ciclo3=0;
													ciclo2=0;
													ciclo=0;
													break;
												default:
													ciclo3=1;
													break;
											}
										}
									}
								}
							}
							break;
						case 2:
							cout<<"Ingrese la CATEGORIA o parte de ella para filtar: ";
							std::getline (std::cin,opcion);
							consulta = "SELECT IdProducto,Producto,Categoria,Precio FROM  V_Productos WHERE Categoria LIKE '%"+opcion+"%'";
							listaProductos= BD.obtenerDatos(consulta,4);
							BD.imprimirProductos(listaProductos);
							break;
						default:
							ciclo=1;
							break;
					}
				}
				consulta="SELECT Cedula,concat_ws(' ',Nombre,Apellido) AS Nombre  FROM T_Cliente";
				lClientes = BD.obtenerDatos(consulta,3);
				ciclo=1;
				while(ciclo)
				{
					printf("\n***** CLIENTE REGISTRADOS *****\n");
					printf("%1s %15s","Cedula","Nombre Completo");
					printf("\n");
					string array[3]={"12","25"};
					BD.verConsula(consulta,array,2);
					printf("\n");
					opcion=campoVacio("Ingrese la CEDULA del cliente :","");
					client = "SELECT Cedula FROM T_Cliente WHERE Cedula ='"+opcion+"'";
					if(!BD.filasAfectadas(client))
					{
						printf("\n ***** CLIENTE NO EXISTE *****\n");
					}
					else
					{
							BD.executarConsulta("CALL ST_CrearFactura('"+opcion+"',"+factura+")");
							ciclo=0;
					}
				}
				BD.mostrarFactura(factura);
			}			
			else printf("\n\n ***** NO HAY PRODUCTOS PARA FACTURAR *****\n\n");
		}
		
		void consultarFactura()
		{
			string opcion;
			opcion =campoNumerico("Ingrese el NUMERO de factura que desea consultar :","");
			BD.mostrarFactura(opcion);
		}
		void verFactura()
		{
			printf("\n\n ********** MOSTRANDO FACTURAS REGISTRADAS **********\n\n");
			string consulta;
			consulta= "SELECT DF.Factura,DF.Nombre,DF.Cantidad,DF.Subtotal,DF.Impuestos,DF.Total FROM V_DatosFactura AS DF ";
			printf("%-15s %-22s %-15s %-15s %-15s %-15s\n","ID Fact","Cliente","Cantidad art.","SubTotal","Impuestos","Total");
			printf("\n");
			string array[6]={"15", "25","15","17","15","15"};
			BD.verConsula(consulta,array,6);
		}
		void estadisticas()
		{
			printf("\n\n ********** BIENVENIDO AL AREA DE ESTADISTICAS **********\n\n");
			string opcion;
			int ciclo=1;
			while(ciclo)
			{
				opcion=campoNumerico("Igrese la opcion que desea realizar\n1-Clientes Facturados\n2-Item Facturados\nOpcion","");
				printf("\n");
				switch (atoi(opcion.c_str()))
				{
					case 1:
						clientesFacturados();
						break;
					case 2:
						itemsFacturados();
						ciclo=0;
						break;
					default:
						ciclo=1;
						break;
				}
			}
		}
		void clientesFacturados()
		{
			string consulta = "SELECT Cliente,Nombre,Cantidad,total FROM V_ClientesFacturados";
			printf("%-15s %-10s %-15s %-10s\n","Cedula","Cliente","Cantidad Fact","Monto Total");
			string array[4]={"16","11","16","10"};
			printf("\n");
			BD.verConsula(consulta,array,4);
			printf("\n");
		}
		void itemsFacturados()
		{
			string consulta="SELECT IdProducto,Nombre,Cantidad FROM V_ItemFacturados";
			printf("\n");
			printf("%-15s %-20s %-10s\n","Id Producto","Nombre","Cantidad");
			string array[3]={"16", "21", "10"};
			BD.verConsula(consulta,array,3);
			printf("\n");
		}
};
