#include "Funciones.h"

void menu()
{
	char str[64] = "HolaA JAs AsjAS dJASDNJAS Asdass";
	int ciclo = 1;
	do 
	{
		char opciones[64];
		printf("%s\n","**************** BIENVENIDO AL SISTEMA DE PUNTOS DE VENTAS **************** ");
		printf("\n");
		printf("1-Ingresar a Opciones Administrativas \n2-Ingresar a Opciones Generales \n3-finalizar programa\n");
		printf("Opcion: ");
		char *i;
		i=fgets(opciones,64,stdin);
		int opcion = atoi(i);
		switch (opcion)
		{
			case 1:	
				ciclo=!opcionesAdministrativas();
				break;
			case 2:
				opcionesGenerales();
				break;
			case 3:
				ciclo=0;
				printf("\n");
				printf("*********PROGRAMA FINALIZADO*********");
				break;
			case 4:
				escribirCotizacion();
				break;
			default:
				break;			
		}
	} while (ciclo);
}

int opcionesAdministrativas()
{
	char usuario[64];
	char pass[64];
	printf("Ingrese el nombre de usuario: ");
    fgets(usuario,64,stdin);
	printf("Ingrese la Contraseña: ");
	fgets(pass,64,stdin);
	printf("\n");
	int acceso = validarUsuario(recortar(usuario),recortar(pass));
	if(acceso)
	{
		int ciclo=1;
		while(ciclo)
		{
			char opciones[64];
			printf("*************** OPCIONES ADMINISTRATIVAS ***************\n");
			printf("\n");
			printf("1-Valores Iniciales\n2-Familias de Productos\n3-Productos\n4-Inventario\n5-Facturas\n6-Volver al menu\nOpcion:");
			char *i;
			i = fgets(opciones,64,stdin);
			int opcion = atoi(recortar(i));
			printf("\n");
			switch (opcion)
			{
				case 1:
					valoresIniciales();
					ciclo=1;
					break;
				case 2:
					familiaDeProductos();
					ciclo=1;
					break;
				case 3:
					NuevoProducto();
					ciclo=1;
					break;
				case 4:
					printf("\n");
					cargarInventarioMenu();
					printf("\n");
					ciclo=1;
					break;
					
				case 5:
					ciclo=1;
					break;
				
				case 6:
					
					ciclo=0;
					break;
				default:
					ciclo=0;
					break;
			}
		}
	}
	else
	{
		printf("*******No se puso accesar al área administrativa vuelva a intentarlo*******\n");
		return 0;
	}
}

void valoresIniciales()
{
	int ciclo=1;
	while(ciclo)
	{
		char opciones[64];
		printf("*****VALORES INICIALES*****\n");
		printf("\n");
		printf("1-Mostrar valores iniciales\n2-Modificar valores iniciales\n3-Volver");
		printf("\n");
		printf("Opcion: ");
		char *i;
		i=fgets(opciones,64,stdin);
		int opcion =atoi(i);
		switch (opcion)
		{
			case 1:
				printf("\n");	
				printf("*******MOSTRANDO VALORES INICIALES *******\n");
				printf("\n");
				mostarValoresIniciales();
				printf("\n");
				ciclo=1;
				break;
			case 2:
				modificarValoresInicialesMenu();
				ciclo=1;
				break;
			case 3:
				ciclo=0;
				break;
			default:
				ciclo=1;
				break;
		}
		printf("\n");
	}
}

void modificarValoresInicialesMenu()
{
	
	int ciclo = 1,ciclo2=1,opcion;
	while(ciclo){
		char valor[64];
		char*i;
		printf("\n");		
		while(ciclo2)
		{
			printf("*****SELECCIONE EL VALOR QUE DESEA MODIFICAR*****\n");
			printf("\n");
			printf("1-Nombre del Local\n2-Cedula del local\n3-Telefono del local\n4-Horario\n5-Nombre de Usuario\n6-Contrasenha de usurio\nOpcion:");
			i = fgets(valor,64,stdin);
			opcion=atoi(recortar(i));
			switch(opcion)
			{
				case 1:
					printf("Digite el nuevo dato para Nombre del local: ");
					i=fgets(valor,64,stdin);
					printf("\n");
					modificarValoresIniciales(recortar(i),"Nombre");
					printf("*********El nombre del local fue modificado exitosamente*********\n");
					ciclo2=0;
					break;
				case 2:
					printf("Digite el nuevo dato para Cedula del Local: ");
					i=fgets(valor,64,stdin);
					printf("\n");
					modificarValoresIniciales(recortar(i),"Cedula");
					printf("*********la cedula del local fue modificado exitosamente*********\n");
					ciclo2=0;
					break;
				case 3:
					printf("Digite el nuevo dato para Telefono del Local: ");
					i=fgets(valor,64,stdin);
					printf("\n");
					modificarValoresIniciales(recortar(i),"Telefono");
					printf("*********El telefono del local fue modificado exitosamente*********\n");
					ciclo2=0;
					break;
				case 4:
					printf("Digite el nuevo dato para Horario: ");
					i=fgets(valor,64,stdin);
					printf("\n");
					modificarValoresIniciales(recortar(i),"Horario");
					printf("*********El Horario del local fue modificado exitosamente*********\n");
					ciclo2=0;
					break;
				case 5:
					printf("Digite el nuevo dato para Usuario: ");
					i=fgets(valor,64,stdin);
					printf("\n");
					modificarValoresIniciales(recortar(i),"Usuario");
					printf("*********El nombre Usuario fue modificado exitosamente*********\n");
					ciclo2=0;
					break;
				case 6:
					printf("Digite el nuevo dato para Contrasenha: ");
					i=fgets(valor,64,stdin);
					printf("\n");
					modificarValoresIniciales(recortar(i),"Password");
					printf("*********La contrasenha fue modificado exitosamente*********\n");
					ciclo2=0;
					break;
				default:
					ciclo2=1;
					break;
			}
		}
		printf("\n");
		printf("***¿Desea hacer otra modificacion?**\n");
		printf("0-NO\n1-SI\nOpcion:");
		i=fgets(valor,64,stdin);
		opcion = atoi(recortar(i));
		switch(opcion)
		{
			case 0:
				ciclo=0;
				break;
			case 1:
				ciclo=1;
				ciclo2=1;
				break;
			default:
				ciclo=0;
				break;
		}
	}
}

void familiaDeProductos()
{
	int ciclo=1;
	while(ciclo)
	{
		char opciones[64];
		char *i;
		char  identificador[64]={""};
		printf("*******FAMILIA DE PRODUCTOS*******\n");
		printf("\n");
		printf("1-Agregar nueva Familia\n2-Eliminar Familia\n3-Ver Familias\n4-Volver\nOpcion: ");
		i=fgets(opciones,64,stdin);
		int opcion = atoi(i);
		switch (opcion)
		{
			case 1:
				
				solicitudDatosFamilia();
				ciclo=1;
				break;
			case 2:
				printf("\n");
				visualizarFamiliasXML();
				printf("\n");
				printf("Digite el identificador del producto a Eliminar: ");
				fgets(identificador,64,stdin);
				eliminarFamilia(recortar(identificador));
				ciclo=1;
				break;
			case 3:
				printf("\n");
				printf("****MOSTRANDO FAMILIAS REGISTRADAS****\n");
				visualizarFamiliasXML();
				printf("\n");
				ciclo=1;
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

void solicitudDatosFamilia()
{
	char mas[64];
	int ciclo =1;
	while (ciclo)
	{
		struct st_familiaProducto familia;
		char id[64];
		char descripcion[64];
		VerificarDatosVacios("Digite el identificador de la nueva familia: ",id);
		VerificarDatosVacios("Digite la descripcion de la nueva familia: ",descripcion);
		strcpy(familia.IdFamilia,recortar(id));
		strcpy(familia.Descripcion,recortar(descripcion));
		agregarFamilia(&familia);
		printf("Desea Agregar mas Familias?\n 0-NO \n 1-SI \n Opcion: ");
		char *i =fgets(mas,64,stdin);
		printf("%s",i);
		int opcion = atoi(recortar(i));
		if(opcion)
		{
			ciclo=1;
		}
		else
		{
			ciclo=0;
		}
	}	
}

void NuevoProducto()
{
	int ciclo=1;
	while(ciclo)
	{
	    char opciones[64];
		char *i;
		char  identificador[64];
		printf("\n");
		printf("*******PRODUCTOS*******\n");
		printf("\n");
		printf("1-Agregar nuevo Producto\n2-Eliminar Producto\n3-Modificar Producto\n4-Visualizar todos los productos Registrados\n5-Volver\nOpcion: ");
		i=fgets(opciones,64,stdin);
		int opcion = atoi(recortar(i));
		switch (opcion)
		{
			case 1:
				printf("\n");
				solicitarDatosProductos();
				ciclo=1;
				break;
			case 2:
				printf("\n");
				visualizarProductosXML();
				printf("Digite el numero de identificacion del producto a eliminar:");
				i = fgets(opciones,64,stdin);
				eliminarProducto(recortar(i));
				ciclo=1;
				break;
			case 3: 
				printf("\n");
				printf("*********MOSTRANDO LISTA DE PRODUCTOS REGISTRADOS*********\n");
				modificarProductoMenu();
				ciclo=1;
				break;
			case 4:
				printf("\n");
				printf("*********MOSTRANDO LISTA DE PRODUCTOS REGISTRADOS*********\n");
				visualizarProductosXML();
				ciclo=1;
				break;
			case 5:
				ciclo=0;
				break;
			default:
				ciclo=1;
				break;
		}
	}
}

void solicitarDatosProductos()
{
		int ciclo = 1;
		while(ciclo)
		{
			struct st_productos productos;
			char idProd[64];
			char NomProd[64];
			char DesProd[128];
			char PrecioCosto[64]; 
			char PrecioVenta[64];
			char Stock[64];
			char idFam[64];
			char Fam[64];
			VerificarDatosVacios("Ingrese el Identificador del Nuevo Producto: ",idProd);
			VerificarDatosVacios("Ingrese el nombre del prodcucto: ",NomProd);
			VerificarDatosVacios("Ingrese la descripcion del producto: ",DesProd);
			VerificarDatosVacios("Ingrese el precio costo del producto: ",PrecioCosto);
			VerificarDatosVacios("Ingrese el precio de venta del producto: ",PrecioVenta);
			VerificarDatosVacios("Ingrese la cantidad del stock inicial: ",Stock);
			printf("\n");
			selecionarFamilia(Fam);
		
			//Insertar los datos en la estructura st_productos
			strcpy(productos.IdProducto,recortar(idProd));
			strcpy(productos.Nombre,recortar(NomProd));
			strcpy(productos.Descripcion,recortar(DesProd));
			strcpy(productos.Familia,recortar(Fam));
			strcpy(productos.Costo,recortar(PrecioCosto));
			strcpy(productos.Precio,PrecioVenta);
			strcpy(productos.stock,Stock);
			
			//Funcion para validad existencia de producto
			
			agregarProducto(&productos);
			ciclo=0;
		}
}

void modificarProductoMenu()
{
	char family[64];
	
	int j,k=1,cant = cantidadHijoProducto();
	char * lista[cant*7];
	int ciclo1 = 1,ciclo2=1;
	while(ciclo1){
		char valor[64];
		char*i;
		printf("\n");
		verFamiliaProductos("productos.xml",lista);
		printf("[Identificador - Nombre Producto -Descripcion - Familia - Precio Costo - Precio Venta ]\n");
		for(j=0;j<cant*7;j+=7)
		{
			printf("[%d - %s - %s - %s - %s - %s %s]\n",k,lista[j],lista[j+1],lista[j+2],lista[j+3],lista[j+4],lista[j+5]);
			k++;
		}
		printf("*****SELECCIONE EL PRODUCTO QUE DESEA MODIFICAR*****\n");
		printf("Opcion:");
		i = fgets(valor,64,stdin);
		int id=atoi(recortar(i));
		id--;
		id*=7;
		while(ciclo2)
		{
			if(0<id<cant){		
				printf("Se eligio el producto ID: %s Nombre: %s\n",lista[id],lista[id+1]);
				printf("\n");
				printf("**********SELECCIONE EL DATOS QUE QUIERE MODIFICAR*********\n");
				printf("\n");
				printf("1-Nombre del Producto\n2-Descipcion\n3-Precio Costo\n4-Precio Venta\n5-Familia\nOpcion:");
				i=fgets(valor,64,stdin);
				int opcion = atoi(recortar(i));
				switch(opcion)
				{
					case 1:
						printf("\n");
						printf("Digite el nuevo valor para Nombre de Producto:");
						i=fgets(valor,64,stdin);
						modificarProducto(recortar(i),"nombre",recortar(lista[id]));
						ciclo2=1;
						break;
					case 2:
						printf("\n");
						printf("Digite el nuevo valor para Descripcion de Producto:");
						i=fgets(valor,64,stdin);
						modificarProducto(recortar(i),"descripcion",recortar(lista[id]));
						ciclo2=1;
						break;
					case 3:
						printf("\n");
						printf("Digite el nuevo valor para Precio Costo de Producto:");
						i=fgets(valor,64,stdin);
						modificarProducto(recortar(i),"precioCosto",recortar(lista[id]));
						ciclo2=1;
						break;
					case 4:
						printf("\n");
						printf("Digite el nuevo valor para Precio Venta de Producto:");
						i=fgets(valor,64,stdin);
						modificarProducto(recortar(i),"precioVenta",recortar(lista[id]));
						ciclo2=1;
						break;
					case 5:	
						selecionarFamilia(family);
						modificarProducto(recortar(family),"familia",recortar(lista[id]));
						ciclo2=1;
						break;
					default:
						ciclo2=1;
						break;
							
				}
				printf("\n");
				printf("***¿Desea hacer otra modificacion?**\n");
				printf("0-NO\n1-SI\nOpcion:");
				i=fgets(valor,64,stdin);
				opcion = atoi(recortar(i));
				switch(opcion)
				{
					case 0:
						ciclo2=0;
						ciclo1=0;
						break;
					case 1:
						ciclo2=1;
						break;
					default:
						ciclo2=0;
						break;
				}
			}
			else
			{
				printf("*****SE DEBE SELECCIONAR UNA OPCION VALIDA*****\n");
				ciclo2=1;
			}
		}
	}
}
void cargarInventarioMenu()
{
	printf("\n");
	char archivo[256]="/home/jordan/Escritorio/productosExtras.xml";
	char *documento;
	printf("Ejemplo de RUTA: /home/nombrePC/Escritorio/archivo.xml\n");
	printf("\n");
	printf("Escriba la ruta del archivo xml que desea cargar para actualizar stock de productos RUTA: ");
	documento = fgets(archivo,256,stdin);
	if(validarArchicoXML(recortar(archivo)))
	{
		InventarioProductos(recortar(documento));

	}
	else
	{
		printf("\n");
		printf("***ARCHIVO NO SE PUDO ABRIR**\n*********Posibles Errores**********\n1-Archivo No existe\n2-Nombre de archivo incorrecto\n");
	}
	
}

void opcionesGenerales()
{
	char opcion[64];
	char*select;
	int ciclo=1;
	while (ciclo)
	{
		printf("1-Consulta de catálogo\n2-Cotizar\n3.Modificar cotización\n4-Facturar\n5-Volver\nOpcion:");
		select = fgets(opcion,64,stdin);
		int i=atoi(recortar(select));
		switch(i)
		{
			case 1:
				consultaCatalogoMenu();
				break;
			case 2:
				cotizacionesMenu();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				ciclo=0;
				break;
			default:
				ciclo=1;
				break;
		}
	}
}

void consultaCatalogoMenu()
{
	char opcion[64],area[64]="catalogo";
	char*select;
	int ciclo=1,i,cant=cantidadHijo("productos.xml");
	char *resultado[cant*7];
	while(ciclo)
	{
		printf("\n");
		printf("Digite la busqueda que desea realizar:");
		select = fgets(opcion,64,stdin);
		printf("*******VISUALIZANDO RESULTADOS DE LA BUSQUEDA********\n");
		printf("\n");
		busquedaCatalogoProductos(recortar(select),resultado,area);
		printf("\n");
		printf("******SELECCIONE UNA OPCION******\n");
		printf("1-Realizar otra busqueda\n2-volver\nOpcion");
		select = fgets(opcion,64,stdin);
		i=atoi(recortar(select));
		switch(i)
		{
			case 1:
				ciclo=1;
				break;
			case 2:
				ciclo=0;
				break;
			default:
				ciclo=1;
				break;
			}
		
	}
}

void cotizacionesMenu()
{
	char *productos[7*50];
	struct st_cotizaciones cotizacion;
	char opcion[128],area[64]="otro";
	char *get;
	int num,i=0;
	printf("\n");
	printf("**********BIENVENIDO AL AREA DE COTIZACIONES*********");
	printf("\n");
	int ciclo=1,cant=cantidadHijo("productos.xml");
	char *lista[cant*7];
	busquedaCatalogoProductos("",lista,area);
	while(ciclo)
	{
		printf("\n");
		printf("*****Digite la accion que desea realizar*****\n");
		printf("1-Ver productos\n2-seleccionar producto\nOpcion:");
		get = fgets(opcion,128,stdin);		
		if(es_numero(recortar(get)))
		{
			num=atoi(recortar(get));
			if(num==1)
			{
				printf("\n");
				printf("Ingrese el nombre del producto o parte del el:");
				get=fgets(opcion,128,stdin);
				printf("\n");
				busquedaCatalogoProductos(recortar(get),lista,area);
				printf("\n");
			}
			else if(num==2)
			{
				printf("Selecione la linea que desea agregar a la cotizacion:");
				get=fgets(opcion,128,stdin);
				if(es_numero(get))
				{
					num=(atoi(recortar(get)))-1;
					printf("NUmero de linea: %d\n",num);
					if(verificarProductoRepetidoMenu(lista[num*7],productos,lista[(num*7)+6]))
					{		
								
					}
					else
					{
						num*=7;
						productos[i]=lista[num];//id
						productos[i+1]=lista[num+1];//nombre
						productos[i+2]=lista[num+2];//desp
						productos[i+3]=lista[num+3];//fam
						productos[i+4]=lista[num+4];//precio C
						productos[i+5]=lista[num+5];//precio V
						productos[i+6]=lista[num+6];//stock
					}
					printf("\n");
					printf("**********Productos Agregados a la cotizacion**********\n");
					printf("\n");
					int k=1;
					printf("[Linea - ID - Producto - Descripcion - Precio Venta - Cantidad]\n");
					for(int m=0;productos[m]!=NULL;m+=7)
					{
						printf("[%d - %s - %s - %s - %s - %s]\n",k,productos[m],productos[m+1],productos[m+2],productos[m+5],productos[m+6]);
						k++;
					}
					i+=7;
				}
				else
				{
					printf("La linea selecionada no existe\n");
				}
				
			}
			else
			{
				ciclo=1;
			}
		}
		else
		{
			printf("la Seleccion no esta en la opciones\n");
			ciclo=1;
		}
		
	}
}
int verificarProductoRepetidoMenu(char * idProd,char *productos[],char * stock)
{
	for(int i =0;productos[i]!=NULL;i+=7)
	{
		if(!strcmp(tolowercase(recortar(idProd)),tolowercase(productos[i])))
		{
			int suma = atoi(recortar(stock))+atoi(recortar(productos[i+6]));
			sprintf(productos[i+6],"%i",suma);
			return 1;
		}
	}
	return 0;	
}
/*Funcion: selecionarFamilia(char * fami,char * idFami)
 * E:Recibe dos variables de familia
 * S:La seleccion de una familia de productos de una lista desplegada
 * R:La seleccion debe existir en la lista desplegada
 * 
 * */
void selecionarFamilia(char * fami)
{
		int ciclo = 1;
		int cant = cantidadHijoFamilia();
		while(ciclo)
		{
			printf("*****Familias Disponibles*****\n");
			printf("\n");
			char *familias[cant*2];
			verFamiliaProductos("FamiliaProductos.xml",familias);
			int numeracion=1,i;
			for(i=0;i<cant*2;i+=2)
			{
				printf("[%d - %s - %s]\n",numeracion,familias[i],familias[i+1]);
				numeracion++;
			}
			printf("\n");
			printf("Selecione el producto:");
			int opcion;
			char nomFamilia[64];
			char *num;
			num=fgets(nomFamilia, 64, stdin);
			opcion=atoi(recortar(num));
			opcion--;
			opcion*=2;
			if(0<opcion<cant)
			{
				strcpy(fami,recortar(familias[opcion+1]));
				ciclo=0;
			}
			else
			{
				printf("**********DEBE SELECCIONAR UNA FAMILIA DE LA LISTA*********\n");
				ciclo=1;
			}	
		}
}

/*Funcion: VerificarDatosVacios(char * const mensaje,char * const dato)
 * E:Un mensaje y un dato vacio
 * S:Retorna el mismo dato no vacio, 
 * R:Permanece en el bucle hasta que llene el dato
 * */
void VerificarDatosVacios(char * const mensaje,char * dato)
{
	int ciclo = 1;
	while(ciclo)
	{
		printf("%s",mensaje);
		fgets( dato, 64, stdin);
		if(strlen(dato)==1){
			ciclo=1;
		}
		else
		{
			ciclo=0;
		}
	}
}
