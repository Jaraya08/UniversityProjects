/* Curso :     Investigación de Operaciones
 * Estudiante: Jordan H. Araya Leiva
 * Carné:      2016254282
 * 
 * 
 * Proyecto Programado #4 : Series Deportivas
 * 
 * INSTRUCCIONES DE COMPILACIÓN
 * 
 * 	Comando para compilar con interfaz gtk.
 *  		--> gcc main.c -o main `pkg-config --cflags --libs gtk+-3.0`  		
 * 	Ejecutar 
 * 			--> ./menu 
 * */
 
 /*Include's*/
#include "funciones.h"

enum {LIST_JUEGO=0,LIST_EQUIPO1,LIST_EQUIPO2,LIST_PARTIDOS,LIST_FORMATO,LIST_PH,LIST_PR,N_COLUMNASSD};

/* Lista de Datos*/
GtkWidget *gTableSeriesDeportivas;

 /* Puntero a la fila seleccionada */
GtkTreeSelection *gSignalSelectionSD;

/*Arreglo de GtkWidget*/
GtkWidget *gTexBoxsSD[8];
GtkWidget *gButtonsSD[2];

void iniciarTablaSD() /* Función que inicializa la lista de datos */
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkListStore *store;	

	 /* Establece la columna y la agrega*/
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Juego",renderer,"text",LIST_JUEGO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableSeriesDeportivas),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Equipo1",renderer,"text",LIST_EQUIPO1,NULL);	
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableSeriesDeportivas),column);	 
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Equipo2",renderer,"text",LIST_EQUIPO2,NULL);	
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableSeriesDeportivas),column);	 
		
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("# Partidos",renderer,"text",LIST_PARTIDOS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableSeriesDeportivas),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Formato",renderer,"text",LIST_FORMATO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableSeriesDeportivas),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Ph",renderer,"text",LIST_PH,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableSeriesDeportivas),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Pr",renderer,"text",LIST_PR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableSeriesDeportivas),column);
	
	store = gtk_list_store_new(N_COLUMNASSD,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW(gTableSeriesDeportivas),GTK_TREE_MODEL(store));
	g_object_unref(store);
}

//llena la tabla con los datos que haya en el archivo de texto Equipos Registrados.txt
void llenarTablaSD()
{		
	FILE *juegos;
	
	GtkListStore *store;
	GtkTreeIter iter;
	
	char linea[512];		
	juegos =fopen("Series Deportivas BD/Juegos Registrados.txt","r");	
	
	/* Obtiene el modelo de datos */
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableSeriesDeportivas))); 
	
	int count=0;
	while (fgets(linea,512,juegos) != NULL)
	{	
		strtok(linea,"\n");
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);   
		char juego[128];
		strcpy(juego,token);
		
		token = strsep(&running, delimiters);    
		char equipo1[64];
		strcpy(equipo1,token);
		
		token = strsep(&running, delimiters);    
		char equipo2[64];
		strcpy(equipo2,token);
		
		token = strsep(&running, delimiters); 	
		char Npartidos[2]; 
		strcpy(Npartidos,token);				
		
		token = strsep(&running, delimiters); 
		char formato[21];
		strcpy(formato,token);				
		
		token = strsep(&running, delimiters); 
		char Pr[3];
		strcpy(Pr,token);				
		
		token = strsep(&running, delimiters); 
		char Ph[3];
		strcpy(Ph,token);				
							
		/* Añade una fila vacia */
		gtk_list_store_append(store, &iter);
		
		/* Cambia los valores de la fila */			
		gtk_list_store_set(store,&iter,LIST_JUEGO,juego,-1);
		gtk_list_store_set(store,&iter,LIST_EQUIPO1,equipo1,-1);
		gtk_list_store_set(store,&iter,LIST_EQUIPO2,equipo2,-1);
		gtk_list_store_set(store,&iter,LIST_PARTIDOS,Npartidos,-1);		
		gtk_list_store_set(store,&iter,LIST_FORMATO,formato,-1);
		gtk_list_store_set(store,&iter,LIST_PH,Pr,-1);
		gtk_list_store_set(store,&iter,LIST_PR,Ph,-1);				
	}
	fclose(juegos);	
}

/*E: NINGUNA
 *S: LIMPIA TODA LA TABLA gTableEquipos
 *R: NINGUNA.
 * */
void limpiarTablaSD()
{	
	GtkListStore *store;
	GtkTreeModel *model;
	GtkTreeIter  iter;		
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableSeriesDeportivas)));
	model = gtk_tree_view_get_model(GTK_TREE_VIEW(gTableSeriesDeportivas));
	if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) 
	{
		return;
	}
	/* Limpia toda la lista */	
	gtk_list_store_clear(store); 
}

int ChooseFileSD(GtkWidget * button,gpointer ventana)
{
	GtkWidget *dialog;
	GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
	gint res;

	dialog = gtk_file_chooser_dialog_new ("Open File",ventana,action,"Cancel",GTK_RESPONSE_CANCEL,"Open",GTK_RESPONSE_ACCEPT,NULL);

	res = gtk_dialog_run (GTK_DIALOG (dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		char *filename;
		GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
		filename = gtk_file_chooser_get_filename (chooser);
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[7]),filename);		
	}
	gtk_widget_destroy (dialog);
}
void limpiarCamposSD()
{
	gtk_widget_set_sensitive (gButtonsSD[0],TRUE); // boton de agregar equipo Enadable TRUE
	gtk_widget_set_sensitive (gButtonsSD[1],FALSE); // boton de Editar enable FALSE
	gtk_widget_set_sensitive (gTexBoxsSD[0],TRUE); // campo nombre Equipo Enable TRUE	
	for(int i=0;i<8;i++)
	{
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[i]),"");
	}
}
//verifica la existencia de un equipo en la base de datos de equipo
int existeSD(char serie[])
{
	FILE *juego;
	char linea[256];	
	juego =fopen("Series Deportivas BD/Juegos Registrados.txt","r");		
	
	while (fgets(linea,256,juego) != NULL)
	{	
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => Equipo */
		char juego[64];
		strcpy(juego,token);
		if(!strcmp(juego,serie))
		{
			return 1;
		}
	}
	fclose(juego);
	return 0;
}

//agrega un nuevo equipo al archivo de texto Equipos Registrados.txt
void agregarTxtSD(char datos[])
{
	/*Agregar en archivo*/
	FILE *equipo;
	equipo =fopen("Series Deportivas BD/Juegos Registrados.txt","a");
	strtok(datos,"\n");
	fprintf(equipo,"%s\n",datos);	
	fclose(equipo);
}


//agrega un nuevo equipo con todas su variables 
void agregarSD(GtkWidget *button,gpointer data)
{
	const gchar *nombreJuego=   gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[0]));
	const gchar *equipo1=     gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[1]));
	const gchar *equipo2=  gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[2]));
	const gchar *Ph = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[3]));
	const gchar *Pr = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[4]));
	const gchar *NoJuegos = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[5]));
	const gchar *formato = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[6]));
		
	char ar_juego[30];			
	strcpy(ar_juego,nombreJuego);
	if(!(strlen(ar_juego))>0)
	{
		ShowMessage("El campo del Nombre del juego no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(gTexBoxsSD[0]);
		return;
	}	
	if(existeSD(ar_juego))	
	{
		ShowMessage("Nombre de la serie deportiva ya existe, intente con otro.","¡AVISO!");
		gtk_widget_grab_focus(gTexBoxsSD[0]);
		return;
	}
	char ar_equipo1[30];
	char ar_equipo2[12];
	char ar_Ph[3];
	char ar_Pr[3];
	char ar_Nojuegos[2];
	char ar_formato[64];
	
	strcpy(ar_equipo1,equipo1);
	strcpy(ar_equipo2,equipo2);
	strcpy(ar_Ph,Ph);
	strcpy(ar_Pr,Pr);	
	strcpy(ar_Nojuegos,NoJuegos);
	strcpy(ar_formato,formato);

	char new_SD[512];
	
	//nombre,costo,plazo,vida util,inflacion
	sprintf(new_SD,"%s,%s,%s,%s,%s,%s,%s",ar_juego,ar_equipo1,ar_equipo2,ar_Nojuegos,ar_formato,ar_Ph,ar_Pr);
	agregarTxtSD(new_SD);		
	
	limpiarCamposSD();
	limpiarTablaSD();
	llenarTablaSD();
	char message[1024];
	sprintf(message,"Se agregó un %s, Equipos  %s y %s , cantidad de juegos %s y formato %s",ar_juego,ar_equipo1,ar_equipo2,ar_Nojuegos,ar_formato);
	ShowMessage(message,"¡INFORMACIÓN!");	
}


//edita todos los campos de un equipo seleccionado 
void editarSD(GtkWidget *button,gpointer data)
{
	const gchar *nombreJuego=   gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[0]));
	const gchar *equipo1=     gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[1]));
	const gchar *equipo2=  gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[2]));
	const gchar *Ph = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[3]));
	const gchar *Pr = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[4]));
	const gchar *NoJuegos = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[5]));
	const gchar *formato = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[6]));
	char ar_juego[64];		
	char ar_equipo1[12];
	char ar_equipo2[12];
	char ar_Ph[3];
	char ar_Pr[3];
	char ar_Nojuegos[2];
	char ar_formato[64];
	
	strcpy(ar_juego,nombreJuego);
	strcpy(ar_equipo1,equipo1);
	strcpy(ar_equipo2,equipo2);
	strcpy(ar_Ph,Ph);
	strcpy(ar_Pr,Pr);	
	strcpy(ar_Nojuegos,NoJuegos);
	strcpy(ar_formato,formato);	
	
	FILE *juego,*temp;	
	juego =fopen("Series Deportivas BD/Juegos Registrados.txt","r");
	temp =fopen("Series Deportivas BD/temp2.txt","w");	
	char linea[512];	
	while (fgets(linea,512,juego) != NULL)
	{		
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);
		char SD[64];
		strcpy(SD,token);
		
		if(!strcmp(ar_juego,SD)){}
		else
		{
			fprintf(temp,"%s\n",linea);			
		}
	}			
	char new_SD[512];
	sprintf(new_SD,"%s,%s,%s,%s,%s,%s,%s",ar_juego,ar_equipo1,ar_equipo2,ar_Nojuegos,ar_formato,ar_Ph,ar_Pr);
	fprintf(temp,"%s\n",new_SD);			
	fclose(temp);
	fclose(juego);
	remove("Series Deportivas BD/Juegos Registrados.txt");
	rename("Series Deportivas BD/temp2.txt","Series Deportivas BD/Juegos Registrados.txt");
	remove("Series Deportivas BD/temp2.txt");	
	
	limpiarTablaSD();
	llenarTablaSD();
	limpiarCamposSD();	
	ShowMessage("Los datos de la Serie deportiva fueron modificados correctamente","¡AVISO!");
}
void SelectedChangedSD(GtkWidget *gTable,gpointer dato) 
{
	GtkTreeIter iter;
	GtkTreeModel *model;
	gchar *value;	
	
	gtk_widget_grab_focus(gTexBoxsSD[7]);
	
	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(gSignalSelectionSD),&model,&iter)) 
	{	
		gtk_widget_set_sensitive (gButtonsSD[0],FALSE);
		gtk_widget_set_sensitive (gButtonsSD[1],TRUE);
		gtk_widget_set_sensitive (gTexBoxsSD[0],FALSE);

		/* Obtiene el Valor  */
		gtk_tree_model_get(model,&iter,LIST_JUEGO,&value,-1); 		
		/* Deposita el valor en el entry*/				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[0]),value);
		
		gtk_tree_model_get(model,&iter,LIST_EQUIPO1,&value,-1);						
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[1]),value);		
		
		gtk_tree_model_get(model,&iter,LIST_EQUIPO2,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[2]),value);
		
		gtk_tree_model_get(model,&iter,LIST_PH,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[3]),value);		
		
		gtk_tree_model_get(model,&iter,LIST_PR,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[4]),value);		
		
		gtk_tree_model_get(model,&iter,LIST_PARTIDOS,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[5]),value);		
		
		gtk_tree_model_get(model,&iter,LIST_FORMATO,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[6]),value);		
		
		g_free(value);
	}
}

void mostrarArchivoCargadoSD(GtkWidget * button,gpointer ventana)
{
	
	gtk_widget_set_sensitive (gButtonsSD[1],FALSE);
	gtk_widget_set_sensitive (gButtonsSD[0],TRUE);
	
	FILE *juego,*temp;
	
	const gchar *archivo = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[7]));
	
	char ar_file[512],linea[512];	
	
	strcpy(ar_file,archivo);
		
	
	if(!strlen(ar_file)>0)
	{
		ShowMessage("No se ha selecionado ninguna ruta","¡AVISO!");
		return;
	}
	juego = fopen(ar_file,"r");				
	while (fgets(linea,512,juego) != NULL)
	{
			strtok(linea,"\n");
			const char delimiters[] = ",";
			char * running = strdup(linea);
			char * token;
		
			token = strsep(&running, delimiters);    
			char juego[128];
			strcpy(juego,token);
			
			token = strsep(&running, delimiters);    
			char equipo1[24];
			strcpy(equipo1,token);
			
			token = strsep(&running, delimiters);   
			char equipo2[24];
			strcpy(equipo2,token);
			
			token = strsep(&running, delimiters);  
			char NoPartidos[2];
			strcpy(NoPartidos,token);
			
			
			token = strsep(&running, delimiters);  
			char formato[64];
			strcpy(formato,token);
			
			
			token = strsep(&running, delimiters);  
			char Ph[3];
			strcpy(Ph,token);
			
			
			token = strsep(&running, delimiters);  
			char Pr[3];
			strcpy(Pr,token);
		
			
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[0]),juego);
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[1]),equipo1);
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[2]),equipo2);
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[5]),NoPartidos);	
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[6]),formato);
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[3]),Ph);	
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[4]),Pr);				
			
	}
	gtk_entry_set_text(GTK_ENTRY(gTexBoxsSD[7]),"");
}

int validarSitaxisSD(char formato[])
{
	if(!isdigit(formato[0]) | !isdigit(formato[strlen(formato)-1]))
	{
		return 1;
	}
	for(int i=0;formato[i]!='\0';i++)
	{
		if(isdigit(formato[i]))
		{
			continue;
		}
		else if(formato[i]=='0')
		{
			return 1;
		}
		else if(formato[i]=='-')
		{
			if(!isdigit(formato[i-1]) | !isdigit(formato[i+1]))
			{
				return 1;
			}
		}		
	}
	return 0;

}


void formarMatrizSD()
{
	const gchar * juego = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[0]));
	const gchar * equipo1 = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[1]));
	const gchar * equipo2 = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[2]));
	const gchar * Ph = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[3]));
	const gchar * Pr = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[4]));
	const gchar * NoPartidos = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[5]));
	const gchar * formato = gtk_entry_get_text(GTK_ENTRY(gTexBoxsSD[6]));
	
	int n=atoi(NoPartidos); 
	int tam=(n+1)/2;
	char ar_formato[512],ar_equipo1[64],ar_equipo2[64],ar_juego[64];
	
	strcpy(ar_formato,formato);
	strcpy(ar_equipo1,equipo1);
	strcpy(ar_equipo2,equipo2);
	strcpy(ar_juego,juego);

	if(validarSitaxisSD(ar_formato))
	{
		ShowMessage("La Sintaxis del Formato no cumple con lo establecido, Ejemplo Formado: 1-2-3-4-5-6","¡AVISO!");
		return;
	}
	
	float matrizM[tam+1][tam+1];
	char matrizC[tam+1][tam+1];
	
	for(int i=0;i<tam+1;i++)
	{
		for(int j=0;j<tam+1;j++)
		{
			matrizM[i][j]=0;
			matrizC[i][j]='A';
		}		
	}
	//inicializar matrices
	matrizM[0][0]=-1;	
	matrizC[0][0]='R';
	matrizC[tam][tam]='V';
	for(int f=1;f<tam+1;f++)matrizM[0][f]=1;
	for(int c=1;c<tam+1;c++)
	{
		matrizM[c][0]=0;
		matrizC[c][0]='C';
	}		
	
	int res=algoritmoSD(tam,n,ar_formato,matrizM,matrizC,atof(Ph)/100,atof(Pr)/100);
		
	if(res)
	{
		ShowMessage("EL formato no cumple con la cantidad de partidos establecida","¡AVISO!");
		return;
	}
	mostrarTablaSD(ar_formato,ar_juego,tam,n,matrizM,matrizC,ar_equipo1,ar_equipo2,atof(Ph)/100,atof(Pr)/100);		
}

int algoritmoSD(int tam,int n,char formato[], float matrizM[tam+1][tam+1], char matrizC[tam+1][tam+1],float f_Ph, float f_Pr)
{	
	
	int juegosBin[n+1];		
	long juegos[(n+1)];	
	for(int l=0;l<n;l++)juegosBin[l]=1;
	
	char valor[strlen(formato)+1];
	int count=0;
	int v=0;	
	int flag=1;
	long suma=0;
	for(int i=0;flag;i++)
	{
		if(formato[i]=='-')
		{
			suma+=atof(valor);			
			juegos[count]=atoi(valor);
			memset(valor,'\0',strlen(valor));
			count+=1;
			v=0;		
			
		}
		else if(formato[i]=='\0')
		{
			suma+=atof(valor);			
			juegos[count]=atoi(valor);
			memset(valor,'\0',strlen(valor));
			count+=1;			
			flag=0;			
		}
		else
		{
			valor[v]=formato[i];
			v+=1;			
		}			
	}
	if(suma!=n)
	{
		return 1;
	}	
	//Convertir el formato a Binario
	int bin=0;	
	for (int i=0;i<count;i++)
	{
		for(int j=0;j<juegos[i];j++)
		{			
			if((i+1)%2==0)
			{
				juegosBin[bin]=0;
			}
			bin+=1;
		}
	}
	
	float Ph = f_Ph;
	float Pr = f_Pr;
	
	float Qr = (1.0-Ph);
	float Qh = (1.0-Pr);
					
	for(int i=1;i<=tam;i++)
	{
		for(int j=1;j<=tam;j++)
		{
			int suma=(tam-i)+(tam-j);
			
			if(juegosBin[suma]==1)
			{
				matrizM[i][j]=(matrizM[i-1][j]*Ph)+((matrizM[i][j-1]*Qr));				
			}
			else
			{
				matrizC[i][j]='C';
				matrizM[i][j]=(matrizM[i-1][j]*Pr)+((matrizM[i][j-1]*Qh));
			}
		}		
	}
	return 0;
}

void mostrarTablaSD(char formato[64],char juego[],int tam, int n, float matrizM[tam+1][tam+1],char matrizC[tam+1][tam+1],char equipo1[],char equipo2[],float Ph, float Pr)
{

/*Crear ventana con sus propiedades*/	
	GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Información del Juego");		
	gtk_window_set_default_size(GTK_WINDOW(ventana),1366,768);
	gtk_widget_set_name(GTK_WIDGET(ventana),"winWhite");

	/*GdkRGBA color;
	gboolean res = gdk_rgba_parse (&color, "#ffffff");
	gtk_widget_override_background_color (ventana,GTK_STATE_FLAG_NORMAL,&color);*/
	
	/*Crea un modelo*/
	GtkWidget *modelo= gtk_fixed_new ();	
	/*Carga imagen a la ventana*/
	GtkWidget *image = gtk_image_new_from_file ("Series Deportivas BD/EncabezadoSD.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);
	
	GtkWidget  * sw = gtk_scrolled_window_new(NULL, NULL);	
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_widget_set_size_request(sw,1000,700);
	
	int x=30;	
	int y=250;
	
	char probaPh[16];
	char probaPr[16];
	char probaQr[16];
	char probaQh[16];
	
	sprintf(probaPh,"%.2f",Ph);
	sprintf(probaPr,"%.2f",Pr);
	sprintf(probaQr,"%.2f",1-Ph);
	sprintf(probaQh,"%.2f",1-Pr);
	
	
	char *labelsDatosJuego[7]={"Nombre Equipo1:","Nombre Equipo2:","Ph:","Pr:","Qr:","Qh","Formato"};
	char *labelsDatosJuegoRes[7]={equipo1,equipo2,probaPh,probaPr,probaQr,probaQh,formato};
	for(int i=0;i<7;i++)
	{
		GtkWidget *labeldatos = gtk_label_new(labelsDatosJuego[i]);
		gtk_fixed_put(GTK_FIXED(modelo),labeldatos,x+5,y);
		
		GtkWidget *labeldatosRes = gtk_label_new(labelsDatosJuegoRes[i]);
		gtk_fixed_put(GTK_FIXED(modelo),labeldatosRes,x+150,y);
		
		y+=30;
	}
	y-=(30*7);
		
	char nombreJuego[128];
	sprintf(nombreJuego,"Datos del Juego %s",juego)	;
		
	GtkWidget *groupTextCargar =gtk_frame_new (nombreJuego);
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,25,210);
	gtk_widget_set_size_request( groupTextCargar ,x+300,y);
	
	
	char respuesta[1024];
	sprintf(probaPh,"%.4f",matrizM[tam][tam]);
	sprintf(probaPr,"%.4f",(1.0-(matrizM[tam][tam])));
	sprintf(respuesta,"La probabilidad que gane %s es de %s\n\nLa Probabilidad que gane %s es de %s",equipo1,probaPh,equipo2,probaPr);
	GtkWidget *labeldatos = gtk_label_new(respuesta);	
	gtk_fixed_put(GTK_FIXED(modelo),labeldatos,410,y);
		
	GtkWidget *groupTextRespuesta =gtk_frame_new ("Respuesta");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextRespuesta,400,210);
	gtk_widget_set_size_request( groupTextRespuesta ,x+400,130);
	
	
	
	x=35;
	y=600;
	
	//res = gdk_rgba_parse (&color, "#f3f781"); // Amarillo local
	sprintf(nombreJuego,"%s de Local",equipo1)	;
	GtkWidget *labelLoca = gtk_label_new(nombreJuego);
	gtk_widget_set_size_request( labelLoca ,200,30);
	gtk_widget_set_name(GTK_WIDGET(labelLoca),"labelYellow");
	//gtk_widget_override_background_color (labelLoca,GTK_STATE_FLAG_NORMAL,&color);
	gtk_fixed_put(GTK_FIXED(modelo),labelLoca,x,y-90);
	
	//res = gdk_rgba_parse (&color, "#a9e2f3"); // celeste Visita
	sprintf(nombreJuego,"%s de Visita",equipo1)	;
	GtkWidget *labelVisita = gtk_label_new(nombreJuego);
	gtk_widget_set_size_request( labelVisita ,200,30);
	gtk_widget_set_name(GTK_WIDGET(labelVisita),"labelLightBlue");
	//gtk_widget_override_background_color (labelVisita,GTK_STATE_FLAG_NORMAL,&color);
	gtk_fixed_put(GTK_FIXED(modelo),labelVisita,x,y-55);
	
	
	int c=630;
	for(int j=0;j<tam+1;j++)
	{
		char result[8];
		sprintf(result,"%d",j);
		GtkWidget *labelfila = gtk_label_new(result);
		gtk_fixed_put(GTK_FIXED(modelo),labelfila,50,c);
		c+=40;
	}
	
	x=80;
	y=620;
	int xx=0;
	for(int i=0;i<tam+1;i++)
	{	
		for(int j=0;j<tam+1;j++)
		{
			char result[16];
			sprintf(result,"%.4f",matrizM[i][j]);
			GtkWidget *labelres = gtk_label_new(result);
			gtk_widget_set_size_request( labelres ,90,30);
			if(matrizC[i][j]=='A')
			{
				gtk_widget_set_name(GTK_WIDGET(labelres),"labelYellow");
				//res = gdk_rgba_parse (&color, "#f3f781");
			}
			else if(matrizC[i][j]=='R')
			{
				gtk_widget_set_name(GTK_WIDGET(labelres),"labelDark");
				//res = gdk_rgba_parse (&color, "#000000");

			}
			else if(matrizC[i][j]=='V')
			{
				gtk_widget_set_name(GTK_WIDGET(labelres),"labelGreen");
				//res = gdk_rgba_parse (&color, "#01df01");

			}
			else
			{
				gtk_widget_set_name(GTK_WIDGET(labelres),"labelLightBlue");
				//res = gdk_rgba_parse (&color, "#a9e2f3");							
			}			
			//gtk_widget_override_background_color (labelres,GTK_STATE_FLAG_NORMAL,&color);			
			gtk_fixed_put(GTK_FIXED(modelo),labelres,x,y);
			
			x+=100;	
		}
		xx+=100;
		x=80;
		y+=40;				
	}
		
	int f=120;	
	for(int i=0;i<tam+1;i++)
	{
		char resultado[8];
		sprintf(resultado,"%d",i);
		GtkWidget *labelres = gtk_label_new(resultado);
		gtk_fixed_put(GTK_FIXED(modelo),labelres,f,590);
		f+=100;
	}
	sprintf(nombreJuego,"Calculando Probabilidades del Juego %s",juego)	;	
	GtkWidget *groupTextProbas =gtk_frame_new (nombreJuego);
	gtk_fixed_put(GTK_FIXED(modelo),groupTextProbas,25,480);
	gtk_widget_set_size_request( groupTextProbas ,xx+70,y-450);	
	
	
	GtkWidget *fin = gtk_label_new(" ");
	gtk_fixed_put(GTK_FIXED(modelo),fin,0,y+100);
	
	GtkWidget *finlado = gtk_label_new(" ");
	gtk_fixed_put(GTK_FIXED(modelo),finlado,xx+100,0);
	
	
	gtk_container_add(GTK_CONTAINER(sw),modelo);
	gtk_container_add(GTK_CONTAINER(ventana),sw);	
	
	gtk_widget_show_all(ventana);		
	 /* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	/* Termina la aplicación */
	gtk_main();	
		
	
}

void cuerpoSeriesDeporticas(GtkWidget *ventana)
{
	/*Crea un modelo*/
	GtkWidget *modelo= gtk_fixed_new ();	
	/*Carga imagen a la ventana*/
	GtkWidget *image = gtk_image_new_from_file ("Series Deportivas BD/EncabezadoSD.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);	
	/*Creando un Gruptext*/
	GtkWidget *groupTextEquiposResg =gtk_frame_new ("Juegos Registrados");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextEquiposResg,10,230);
	gtk_widget_set_size_request( groupTextEquiposResg ,640 ,500);
	
	GtkWidget *groupTextGeneral =gtk_frame_new ("Datos del Juego");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextGeneral,700,230);
	gtk_widget_set_size_request( groupTextGeneral ,400 ,340);
			
	GtkWidget *groupTextCargar =gtk_frame_new ("Cargar Archivos");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,700,580);
	gtk_widget_set_size_request( groupTextCargar ,480 ,110);
	
	/*Inicializar tabla*/
	gTableSeriesDeportivas = gtk_tree_view_new(); /* Crea la vista de la lista */
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(gTableSeriesDeportivas),TRUE); /* Visualiza las cebeceras de la lista */
	gSignalSelectionSD = gtk_tree_view_get_selection(GTK_TREE_VIEW(gTableSeriesDeportivas));

	/*Posicionar tabla*/
	gtk_fixed_put(GTK_FIXED(modelo),gTableSeriesDeportivas,20,250);
	
	/*Etiquetas*/
	GtkWidget *gLabelJuego,*gLabelEquipo1,*gLabelEquipo2,*gLabelPH,*gLabelQH,*gLabelNoPartidos,*gLabelFormato;
	GtkWidget *gLabelRuta;
	
	/*TextBox*/
	GtkWidget *gTextBoxJuego,*gTextBoxEquipo1,*gTextBoxEquipo2,*gTextBoxPH,*gTextBoxQH,*gTextBoxNoPartidos,*gTextBoxFormato,*gTextBoxRuta;
	
	/*Buttons*/
	GtkWidget *gButtonAgregar,*gButtonEditar,*gButtonVolver,*gButtonCargar,*gButtonBusqueda,*gButtonLimpiar ,*gButtonResolver;
	
	/*Inicializar GtkWidget*/
	gLabelJuego = gtk_label_new("Nombre del juego:");
	gLabelEquipo1 = gtk_label_new("Nombre equipo #1:");
	gLabelEquipo2 = gtk_label_new("Nombre equipo #2:");
	gLabelPH = gtk_label_new("Prob. de equipo #1 Casa:");
	gLabelQH = gtk_label_new("Prob. de equipo #1 Visita:");
	gLabelNoPartidos = gtk_label_new("Numero de partidos:");
	gLabelFormato = gtk_label_new("Formato :");
				
	gLabelRuta=gtk_label_new("Ruta:");
	gTextBoxJuego = gtk_entry_new();
	gTextBoxEquipo1 = gtk_entry_new();
	gTextBoxEquipo2 = gtk_entry_new();
	gTextBoxPH =gtk_entry_new();
	gTextBoxQH=gtk_entry_new();
	gTextBoxNoPartidos =gtk_entry_new();
	gTextBoxFormato =gtk_entry_new();
	gTextBoxRuta  = gtk_entry_new();
	
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxJuego),28);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxEquipo1),12);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxEquipo2),12);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxPH),3);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxQH),3);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxNoPartidos),2);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxFormato),21);
	
	gtk_widget_set_size_request(gTextBoxRuta ,380,-1);

	gButtonAgregar = gtk_button_new_with_label("Agregar Equipo");
	gButtonEditar = gtk_button_new_with_label("Editar Equipo");
	gButtonVolver = gtk_button_new_with_label("Volver");
	gButtonCargar =gtk_button_new_with_label("Cargar");
	gButtonBusqueda=gtk_button_new_with_label("...");
	gButtonLimpiar=gtk_button_new_with_label("Limpiar");
	gButtonResolver=gtk_button_new_with_label("Resolver");
	
	/*Posicionar GtkWidget*/
	gtk_fixed_put(GTK_FIXED(modelo),gLabelJuego,720,270);	
	gtk_fixed_put(GTK_FIXED(modelo),gLabelEquipo1,720,300);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelEquipo2,720,330);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelPH,720,360);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelQH,720,390);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelNoPartidos,720,420);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelFormato,720,450);
		
	gtk_fixed_put(GTK_FIXED(modelo),gLabelRuta,720,620);//mover

	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxJuego,920,265);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxEquipo1,920,295);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxEquipo2,920,325);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxPH,920,355);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxQH,920,385);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxNoPartidos,920,415);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxFormato,920,445);
	
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxRuta,760,615);//Mover

	gtk_fixed_put(GTK_FIXED(modelo),gButtonAgregar,720,490);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonEditar,850,490);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonResolver,800,520);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonLimpiar,1020,490);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonVolver,1030,530);
	
	gtk_fixed_put(GTK_FIXED(modelo),gButtonCargar,1080,655);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonBusqueda,1150,615);
	
	gButtonsSD[0]=gButtonAgregar;
	gButtonsSD[1]=gButtonEditar;
	gtk_widget_set_sensitive (gButtonEditar,FALSE);

	/*Lista de textbox */
	gTexBoxsSD[0]=gTextBoxJuego;
	gTexBoxsSD[1]=gTextBoxEquipo1;
	gTexBoxsSD[2]=gTextBoxEquipo2;
	gTexBoxsSD[3]=gTextBoxPH;	
	gTexBoxsSD[4]=gTextBoxQH;	
	gTexBoxsSD[5]=gTextBoxNoPartidos;
	gTexBoxsSD[6]=gTextBoxFormato;
	gTexBoxsSD[7]=gTextBoxRuta;
	
	/*Señales*/
	
	/*Señal para la seleccion*/
	g_signal_connect(gSignalSelectionSD,"changed",G_CALLBACK(SelectedChangedSD),NULL); 
	
	/*Señales para los Textbox*/	
	/*g_signal_connect (G_OBJECT (gTextBoxCosto), "focus-out-event",G_CALLBACK (validarCampoEquipoNum),NULL);
	g_signal_connect (G_OBJECT (gTextBoxPlazo), "focus-out-event",G_CALLBACK (validarCampoEquipoNum),NULL);
	g_signal_connect (G_OBJECT (gTextBoxEquipo), "focus-out-event",G_CALLBACK (validarEquipo),NULL);*/

	
	/*Señales para los botones*/
	  g_signal_connect (G_OBJECT (gButtonAgregar), "clicked",G_CALLBACK (agregarSD),NULL);
	  g_signal_connect (G_OBJECT (gButtonEditar), "clicked",G_CALLBACK (editarSD),NULL);
	  g_signal_connect (G_OBJECT (gButtonResolver), "clicked",G_CALLBACK (formarMatrizSD),NULL);
	  g_signal_connect (G_OBJECT (gButtonBusqueda), "clicked",G_CALLBACK (ChooseFileSD),ventana);
      g_signal_connect (G_OBJECT (gButtonCargar), "clicked",G_CALLBACK (mostrarArchivoCargadoSD),ventana);
	  g_signal_connect (G_OBJECT (gButtonLimpiar), "clicked",G_CALLBACK (limpiarCamposSD),ventana);
	  g_signal_connect(G_OBJECT(gButtonVolver),"clicked",G_CALLBACK(cerrarVentana),ventana); 

	/*Set modelo en la ventana*/
	gtk_container_add(GTK_CONTAINER(ventana),modelo);

	/*Mostrar Todo*/
	gtk_widget_show_all(ventana);	
	
}

int winSeriesDeportivas()
{
	/*Crear ventana con sus propiedades*/
	GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Series Deportivas");		
	gtk_window_set_default_size(GTK_WINDOW(ventana),1366,768);
	gtk_widget_set_name(GTK_WIDGET(ventana),"winWhite");
	
	/*GdkRGBA color;
	gboolean res = gdk_rgba_parse (&color, "#ffffff");
	gtk_widget_override_background_color (ventana,GTK_STATE_FLAG_NORMAL,&color);*/
	
	/*Llama al cuerpo de la ventana*/
	cuerpoSeriesDeporticas(ventana);	
	iniciarTablaSD();	
	llenarTablaSD();	
	 /* Muestra la ventana principal con todo su contenido */
	gtk_widget_show_all(ventana);		
	 /* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	/* Termina la aplicación */
	gtk_main(); 
	
	return 0;
}

