/* Curso :     Investigación de Operaciones
 * Estudiante: Jordan H. Araya Leiva
 * Carné:      2016254282
 * 
 * 
 * Proyecto Programado #1 : Rutas Óptimas (Algoritmo de Floyd)
 * 
 * INSTRUCCIONES DE COMPILACIÓN
 * 
 * 	Comando 1 para compilar con interfaz gtk.
 *  		--> gcc main.c -o main `pkg-config --cflags --libs gtk+-3.0`  		
 * 	Ejecutar 
 * 			--> ./menu 
 * */
 
 /*Include's*/
#include "funciones.h"
 
 
enum {LIST_GRAFO=0,N_COLUMNS};
 
 /*Campos de Texto*/
GtkWidget *gTextoBoxGrafo,*gTexboxCargarArchivo,*gTextboxNodo1,*gTextboxNodo2;

 /* Lista de Datos*/
GtkWidget *TREEVIEW_LIST;

 /* Puntero a la fila seleccionada */
GtkTreeSelection *selection;

int tamMtriz=0;

/*--------------------------------------------------------------------------------------------*/

/*E: UN COMPONENTE Y UN DATOS ENVIADOS DESDE LA SEÑAÑ CLICKED DEL BOTON. 
 *S: UN MENSAJE AL USUARIO CON LA AYUDA NECESARIA PARA LLENAR UN GRAFO.
 *R: NINGUNA.
 * */
void helpMessage(GtkWidget *widget,gpointer datos)
{
	ShowMessage("1-Numero antes de los dos puntos es el tamaño del grafo\n2-numero antes del guion nodo actual\n3-numero despues del guion nodo destino \n4-numero despues de la coma es el peso\n5-punto y coma representa el inicio de otra ruta\n6- barrita indica el sigueinte nodo del grafo\nEjemplo: 5:1-2,6;1-5,7;|2-3,5;2-1,9;|3-5,14;3-2,5;|4-5,15;4-2,1;|5-1,2;5-4,19;5-3,2;","¡AYUDA!");
}

/*E: NINGUNA.
 *S: INICIALIZA UNA TABLA PARA PODER LLENARSE CON LOS GRAFOS.
 *R: NINGUNA.
 * */
void iniciarTabla() /* Función que inicializa la lista de datos */
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkListStore *store;	
	
	/* Prepara la cabecera para una columna */
	renderer = gtk_cell_renderer_text_new (); 
	
	 /* Establece la columna */
	column = gtk_tree_view_column_new_with_attributes("Datos de Grafo",renderer,"text",LIST_GRAFO,NULL);
	
	 /* Añade la columna a la lista de datos */
	gtk_tree_view_append_column(GTK_TREE_VIEW(TREEVIEW_LIST),column);
	store = gtk_list_store_new(N_COLUMNS,G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW(TREEVIEW_LIST),GTK_TREE_MODEL(store));
	g_object_unref(store);

}
/*E: NINGUNA
 *S: LLENA LA TABLA TREEVIEW_LIST CON LOS DATOS DEL ARCHIVO DE TEXTO grafos.txt.
 *R: EL ARCHIVO DE TEXT grafos.txt DEBE TENER DATOS.
 * */
void llenarTabla()
{		
	FILE *grafosTxt;
	
	GtkListStore *store;
	GtkTreeIter iter;
	
	char linea[1024];
	
	grafosTxt =fopen("Rutas Optimas BD/grafos.txt","r");	
	
	/* Obtiene el modelo de datos */
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(TREEVIEW_LIST))); 
	
	while (fgets(linea,1024,grafosTxt) != NULL)
	{	
		strtok(linea,"\n");
		/* Añade una fila vacia */
		gtk_list_store_append(store, &iter);
		/* Cambia los valores de la fila */	
		gtk_list_store_set(store,&iter,LIST_GRAFO,linea,-1);
	}
	fclose(grafosTxt);	
}

/*E: NINGUNA
 *S: LIMPIA TODA LA TABLA TREEVIEW_LIST
 *R: NINGUNA.
 * */
void limpiarTabla()
{	
	GtkListStore *store;
	GtkTreeModel *model;
	GtkTreeIter  iter;	
	gtk_entry_set_text(GTK_ENTRY(gTexboxCargarArchivo),"");	
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(TREEVIEW_LIST)));
	model = gtk_tree_view_get_model(GTK_TREE_VIEW(TREEVIEW_LIST));
	if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) 
	{
		return;
	}
	/* Limpia toda la lista */	
	gtk_list_store_clear(store); 
}

/*E: UNA CADENA DE CARACTERES
 *S: 1 SI LA CADENA CUMPLE CON EL FORMATO ESTABLECIDO 0 SI NO CUMPLE
 *R: LA CEDENA DEBE TENER EL FORMATO CORRECTO
 * */
int validarformato(char cadena[])
{	
	if(!(cadena[strlen(cadena)-1]==';'))
	{
		return 0;
	}	
	else
	{
		for(int i =0;!(cadena[i]=='\0');i++)
		{	
			if(isdigit(cadena[i]))
			{
				continue;
			}
			else if (!(cadena[i]==',' | cadena[i]=='-' | cadena[i]==';' | cadena[i]==':' | cadena[i]=='|'))
			{
				return 0;
			}				
			else if(cadena[i]==cadena[i+1])
			{
				return 0;
			}
			else if(cadena[i]=='-' | cadena[i]==',' | cadena[i]==':' | cadena[i]==';')
			{
				if(cadena[i]==';' & cadena[i+1]=='|')
				{
					continue;
				}
				else
				{
					if (cadena[i+1]=='\0')
					{
						return 1;
					}
					else if(!isdigit(cadena[i-1]) | !(isdigit(cadena[i+1])))
					{
						return 0;
					}
				}
			}			
		}
	}
}


void obtenerRutaOptima(GtkWidget *widget,int matriz[][tamMtriz])
{
	ShowMessage("Funcionalidad en construcción","!AVISO¡");
}

void mostarTablas(GtkWidget *widget,gpointer entry)
{
	const gchar *grafo = gtk_entry_get_text(GTK_ENTRY(gTextoBoxGrafo));	
	
	char str_grafo[512];
	strcpy(str_grafo,grafo);
	
	if(!validarformato(str_grafo))
	{
		ShowMessage("El Formato del grafo ingresado es incorrecto","¡ERROR!");
		return;
	}
	int len=0;
	char ar_len[16];
	for(int i=0;i<(strlen(str_grafo));i++)
	{
		if(str_grafo[i]==':')
		{
			len=atoi(ar_len);
			break;
		}
		ar_len[i]=str_grafo[i];		
	}
	int matriz[len][len];
	int tablaP[len][len];		
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{	
			tablaP[i][j]=0;		
			matriz[i][j]=99999;	
		}
		matriz[i][i]=0;	
	}
	formarMatriz(len,str_grafo,matriz);
	
	/*Crear ventana con sus propiedades*/
	GtkWidget  * ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Solucion Optima de floyd");		
	gtk_window_set_default_size(GTK_WINDOW(ventana),700,700);
	gtk_container_set_border_width(GTK_CONTAINER(ventana),20); /* Establece el borde de la ventana */
	gtk_window_set_resizable(GTK_WINDOW(ventana),FALSE);
	
	GtkWidget  * sw = gtk_scrolled_window_new(NULL, NULL);	
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_widget_set_size_request(sw,700,700);
	
	GtkWidget * modelo= gtk_fixed_new ();		
	GtkWidget *label = gtk_label_new("Mostrando Tablas D"); 
	gtk_fixed_put(GTK_FIXED(modelo),label,0,0);
	
	GtkWidget *labelNota = gtk_label_new("NOTA: 99999 Representa Infinito"); 
	gtk_fixed_put(GTK_FIXED(modelo),labelNota,0,30);
	int x=0;
	int y=100;	
			
	for(int k = 0; k < len; k++)
	{	
		char num[63]="";
		sprintf(num, "Tabla D= %d", k);		
		GtkWidget *label = gtk_label_new(num); 
		gtk_fixed_put(GTK_FIXED(modelo),label,x,y-35);
			
		GtkWidget *label2 = gtk_label_new("___________"); 
		gtk_fixed_put(GTK_FIXED(modelo),label2,x,y-25);	
		
		for(int i =0;i<len;i++)
		{	
								
			for (int j=0;j<len;j++)
			{
				char texto[16];
				sprintf(texto, "%d", matriz[i][j]);
				GtkWidget *label = gtk_label_new(texto); 
				gtk_fixed_put(GTK_FIXED(modelo),label,x,y);
				x+=70;
			}			
			x=0;
			y+=40;		
		}
		y+=50;
		for(int m = 0; m < len; m++)
		{				
			for(int g = 0; g < len; g++)
			{
				int dt = matriz[m][k] + matriz[k][g];
				if(matriz[m][g] > dt)
				{
					matriz[m][g] = dt;
					tablaP[k][g]=m;
				}			
			}
		}		
		
	}
		GtkWidget *label1 = gtk_label_new("TABLA (P)"); 
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y-35);
		
		GtkWidget *label2 = gtk_label_new("___________"); 
		gtk_fixed_put(GTK_FIXED(modelo),label2,x,y-25);	
		
		for(int i =0;i<len;i++)
		{									
			for (int j=0;j<len;j++)
			{
				char texto[16];
				sprintf(texto, "%d", tablaP[i][j]);
				GtkWidget *label1 = gtk_label_new(texto); 
				gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);
				x+=70;
			}			
			x=0;
			y+=40;		
		}
	
	/*Label de rutas*/
	GtkWidget *gLabelRuta1 = gtk_label_new("Nodo 1:"); 
	gtk_fixed_put(GTK_FIXED(modelo),gLabelRuta1,0,y+20);
	
	GtkWidget *gLabelRuta2 = gtk_label_new("Nodo 2:"); 
	gtk_fixed_put(GTK_FIXED(modelo),gLabelRuta2,0,y+60);
	
	/*Campos de texto para optener la rutas mas corta entre un par de nodos*/
	gTextboxNodo1=gtk_entry_new();
	gTextboxNodo2 = gtk_entry_new();
	
	gtk_fixed_put (GTK_FIXED(modelo), gTextboxNodo1,100,y+15);
	gtk_fixed_put (GTK_FIXED(modelo), gTextboxNodo2,100, y+55);
	
	/*Boton para resolver ruta optima*/
	GtkWidget *resolver = gtk_button_new_with_label("Mostrar Ruta");
	gtk_fixed_put (GTK_FIXED(modelo),resolver,300,y+30);

	/*Label para agregar espacion al final*/
	GtkWidget *labelfin = gtk_label_new(""); 
	gtk_fixed_put(GTK_FIXED(modelo),labelfin,0,y+100);		
	
	
	gtk_container_add(GTK_CONTAINER(sw),modelo);
	gtk_container_add(GTK_CONTAINER(ventana),sw);
	
	
	gtk_widget_show_all(ventana);
	
	tamMtriz=len;
	/* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(G_OBJECT(resolver),"clicked",G_CALLBACK(obtenerRutaOptima),tablaP); 


	/* Termina la aplicación */
	gtk_main(); 
	
}


/*E: UN TAMAÑO QUE INDICA EL TAMAÑO DE LA MATRIZ, UNA CADENA QUE REPRESENTA EL GRAFO, Y UNA MATRIZ NXN 
 *S: LA MATRIZ D(0) DEL GRAFO
 *R: EL GRAFO DEBE SER CORRECTO
 * */
void formarMatriz(int tam,char *grafo,int matriz[][tam])
{
	int posChar=2;			
	char str_grafo[512];
	strcpy(str_grafo,grafo);		
	
	int flagNodo=0;
	int flagPeso=0;	
	for(int j=1;j<=tam;j++)
	{				
		int k=posChar;		
		int m=0;		
			
		char nodoDes[16];
		char peso[16];
		
		for(k;k<(strlen(str_grafo));k++)
		{					
			if(str_grafo[k]=='|')
			{		
				k+=1;
				flagNodo=0;						
				break;
			}
			else if(str_grafo[k]=='-')
			{					
				flagNodo=1;
				m=0;				
			}
			else if(str_grafo[k]==';')
			{					
				flagNodo=0;
				flagPeso=0;					
				matriz[j-1][(atoi(nodoDes)-1)]=atoi(peso);									
				memset(nodoDes,'\0',strlen(nodoDes));
				memset(peso,'\0',strlen(peso));				
				m=0;																														
			}
			else if(str_grafo[k]==',')
			{					
				flagPeso=1;
				flagNodo=0;	
				m=0;																		
			}					
			else 
			{
				if(flagNodo)
				{							
					nodoDes[m]=str_grafo[k];				
				}
				else if(flagPeso)
				{												
					peso[m]=str_grafo[k];																							
				}						
				m+=1;													
			}											
		}
		posChar=k;				
	}
}


/*E: NINGUNA.
 *S: LLENA LA TABLA TREEVIEW_LIST CON LOS GRAFOS CARGADOS EN EL TXT.
 *R: NINGUNA. 
 * */
void guardarArchivo(GtkWidget *widget,gpointer entry)
{
	FILE *grafosExtra,*grafosTxt;
	
	const gchar *archivo = gtk_entry_get_text(GTK_ENTRY(gTexboxCargarArchivo));	
	
	char str_archivo[512];
	strcpy(str_archivo,archivo);
	
	grafosExtra =fopen(str_archivo,"r");		
	char linea1[512];
	char linea2[512];
	int flagRes=0;
	
	if(grafosExtra)
	{
		grafosTxt =fopen("Rutas Optimas BD/grafos.txt","a");	
		while (fgets(linea1, 512, grafosExtra) != NULL)
		{					
			strtok(linea1,"\n");									
			fprintf(grafosTxt, "%s\n", linea1);							
		}		
		fclose(grafosTxt);
		fclose(grafosExtra);
		
	}
	else
	{
		ShowMessage("Archivo no se puedo abrir\nPosibles Errores\n1-Ruta Incorrecta\n2-Archivo no existe\n","¡ERROR!");
	}	
	limpiarTabla();
	llenarTabla();	
}

/*E:UN COMPONENTE Y UN PUNTERO CON UN DATO.
 *S: AGREGAR EN EL TXT grafos.txt EL NUEVO GRAFO
 *R: EL GRAFO DEBE CONTAR CON EL FORMATO CORRECTO Y NO DEBE SER VACIO
 * */
void nuevoGrafo(GtkWidget *widget,gpointer entry) /* Inserta una fila nueva en la lista de datos */
{	
	FILE *grafos;
	GtkListStore *store;
	GtkTreeIter iter;

	const gchar *newGrafo = gtk_entry_get_text(GTK_ENTRY(gTextoBoxGrafo)); /* Metemos la informacion del entry en un gchar */
	
	char arr_grafo[1024];
	strcpy(arr_grafo,newGrafo);
	if(!strcmp(newGrafo,""))
	{
		ShowMessage("El grafo no puede ser vacio","¡ERROR!");
	}
	else if(!validarformato(arr_grafo))
	{
		ShowMessage("El grafo no cuenta con el formato Correcto","¡ERROR!");
	}
	else
	{
		
		char str_grafo[512];		
		strcpy(str_grafo,newGrafo);	
		grafos =fopen("Rutas Optimas BD/grafos.txt","a");		
		fprintf(grafos, "%s\n",str_grafo );	
		fclose(grafos);
		limpiarTabla();
		llenarTabla();
		gtk_entry_set_text(GTK_ENTRY(gTextoBoxGrafo),"");							
	}		
}

/*E: UN COMPONENTE Y UN DATO PROVENIENTE DE LA SENAL CHANGED 
 *S: LLENA EL CAMPO DE TEXTO gTextoBoxGrafo CON LOS DATOS QUE TIENE LA SELECCION DE LA TABLA.
 *R: DEBE SELECIONAR UN ELEMENTO PARA QUE SE PUEDE LLENAR
 * */
void SelectedChanged(GtkWidget *widget,gpointer label) 
{
	GtkTreeIter iter;
	GtkTreeModel *model;
	gchar *value;
	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget),&model,&iter)) 
	{
		/* Obtiene el Valor  */
		gtk_tree_model_get(model,&iter,LIST_GRAFO,&value,-1); 
		
		 /* Deposita el valor en el entry*/		
		gtk_entry_set_text(GTK_ENTRY(gTextoBoxGrafo),value);
		g_free(value);
	}
}


void cerrarVentana(GtkWidget *widget,gpointer win)
{
	gtk_widget_hide(win);
}
/*E: UNA VENTANA
 *S: EL CUERPO DE LA VENTANA LLENO CON LOS COMPONENTES NECESARIOS PARA SU FUNCIONAMIENTO 
 *R: NINGUNA
 * */ 
void cuerpoFloyd(GtkWidget *win)
{
	/*Crear un scrolled para la ventana*/
	GtkWidget  * sw = gtk_scrolled_window_new(NULL, NULL);	
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_widget_set_size_request(sw,900,500);

	
	/*Inicializar modelo para la ventana*/
	GtkWidget * modelo= gtk_fixed_new ();
	
	/*Creando un Gruptext*/ 		
	GtkWidget *groupTextPrincipal =gtk_frame_new ("Rutas Óptimas (Algoritmo de Floyd)");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextPrincipal,10,10);
	gtk_widget_set_size_request(groupTextPrincipal , 700 , 300);
		
	GtkWidget *groupTextGrafo =gtk_frame_new ("Nuevo Grafo");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextGrafo,20,40);
	gtk_widget_set_size_request( groupTextGrafo , 610 , 110);
	
	GtkWidget *groupTextCargar =gtk_frame_new ("Cargar Grafos");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,20,170);
	gtk_widget_set_size_request( groupTextCargar , 670 , 90);
	 			
	 /*Botones */
	GtkWidget *agregar, *volver, *resolver,*help, *cargar;
	
	/*Etiquetas*/
	GtkWidget *gLabelTitulo,*gLabelFormaGrafo,*gLabelRuta; 
		
	/* Inicializar etiquetas */
	gLabelFormaGrafo = gtk_label_new("Formar Grafo:"); 
	gLabelRuta = gtk_label_new("Ruta:");
	
	/*Inicializar Textboxs*/
	gTextoBoxGrafo=gtk_entry_new();
	gTexboxCargarArchivo=gtk_entry_new();
	
	/*Asignar largo al entry*/
	 gtk_widget_set_size_request( gTexboxCargarArchivo , 400 , -1);
	 gtk_widget_set_size_request( gTextoBoxGrafo , 400 , -1);


	/*Inicializar botones*/
	agregar = gtk_button_new_with_label("Agregar Grafo");
	resolver = gtk_button_new_with_label("Ver solución");
	help = gtk_button_new_with_label("Ayuda");
	cargar=gtk_button_new_with_label("Cargar Archivo");	
	volver = gtk_button_new_with_label("Volver");
	
	/*Inicializar tabla*/
	TREEVIEW_LIST = gtk_tree_view_new(); /* Crea la vista de la lista */
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(TREEVIEW_LIST),TRUE); /* Visualiza las cebeceras de la lista */
	
	/*Posicionar tabla*/
	gtk_fixed_put(GTK_FIXED(modelo),TREEVIEW_LIST,10,330);
	
	/*Posicionar etiquetas*/
	gtk_fixed_put (GTK_FIXED(modelo), gLabelFormaGrafo,30,75);
	gtk_fixed_put (GTK_FIXED(modelo),gLabelRuta,30,210);
	
	/*Posicionar textbox*/
	gtk_fixed_put (GTK_FIXED(modelo), gTextoBoxGrafo,150,70);
	gtk_fixed_put (GTK_FIXED(modelo), gTexboxCargarArchivo,150, 205);
	
	/*Posicionar botones*/
	gtk_fixed_put (GTK_FIXED(modelo),agregar,150,105);
	gtk_fixed_put (GTK_FIXED(modelo),help,560,70);     
	gtk_fixed_put (GTK_FIXED(modelo),resolver,270,105);   
	gtk_fixed_put (GTK_FIXED(modelo),cargar,560,205);        	
    gtk_fixed_put (GTK_FIXED(modelo),volver,630,270);
    
     		
	gtk_container_add(GTK_CONTAINER(sw),modelo);
	gtk_container_add(GTK_CONTAINER(win),sw);
	
	 /* captura la fila seleccionada */
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(TREEVIEW_LIST));

	/*Señal para la seleccion*/
	g_signal_connect(selection,"changed",G_CALLBACK(SelectedChanged),NULL); 	
	
	/*Eventos de botones*/	
	g_signal_connect(G_OBJECT(help),"clicked",G_CALLBACK(helpMessage),NULL); 
	g_signal_connect(G_OBJECT(agregar),"clicked",G_CALLBACK(nuevoGrafo),NULL); 
	g_signal_connect(G_OBJECT(resolver),"clicked",G_CALLBACK(mostarTablas),NULL); 
	g_signal_connect(G_OBJECT(cargar),"clicked",G_CALLBACK(guardarArchivo),NULL); 
	g_signal_connect(G_OBJECT(volver),"clicked",G_CALLBACK(cerrarVentana),win); 

}
 
/*E: NINGUNA
 *S: MUESTRA AL USUARIO LA VENTANA PRINCIPAL DE FLOYD
 *R: NINGUNA
 * */ 
int winFloyd()
{		
	/*Crear ventana con sus propiedades*/
	GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Rutas Óptimas (Algoritmo de Floyd)");		
	gtk_window_set_default_size(GTK_WINDOW(ventana),500,500);
    gtk_window_set_resizable(GTK_WINDOW(ventana),FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(ventana),10); /* Establece el borde de la ventana */
	
	/*Llamar modelo de ventana*/
	cuerpoFloyd(ventana);
	
	/*Iniciar y llenar la tabla*/
	iniciarTabla();	
	llenarTabla();
		
	 /* Muestra la ventana principal con todo su contenido */
	gtk_widget_show_all(ventana);
		
	 /* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	/* Termina la aplicación */
	gtk_main(); 
	
	return 0;	
}
