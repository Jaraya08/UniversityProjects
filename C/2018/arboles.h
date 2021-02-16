/* Curso :     Investigación de Operaciones
 * Estudiante: Jordan H. Araya Leiva
 * Carné:      2016254282
 * 
 * 
 * Proyecto Programado #5 : Árboles Binarios de Búsqueda Óptimos
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

//nombres del arbol

enum {LIST_ARBOL=0,LIST_LLAVES,N_COLUMNASAB};



/* Lista de Datos*/
GtkWidget *gTableAB;

 /* Puntero a la fila seleccionada */
GtkTreeSelection *gSignalAB;

/*Arreglo de GtkWidget*/
GtkWidget *llavesAB[10][2];
GtkWidget *gTexboxAB[3];
GtkWidget *gButtonAB[2];

/*E: NINGUNA.
 *S: INICIALIZA UNA TABLA PARA PODER LLENARSE CON LOS GRAFOS.
 *R: NINGUNA.
 * */
void iniciarTablaAB() /* Función que inicializa la lista de datos */
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkListStore *store;	

	 /* Establece la columna y la agrega*/
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Nombre Arbol",renderer,"text",LIST_ARBOL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableAB),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("# de Llaves",renderer,"text",LIST_LLAVES,NULL);	
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableAB),column);	 
			
	
	store = gtk_list_store_new(N_COLUMNASAB,G_TYPE_STRING,G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW(gTableAB),GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void llenarTablaAB()
{		
	FILE *arbol;
	
	GtkListStore *store;
	GtkTreeIter iter;
	
	char linea[256];	
	arbol =fopen("BD Arboles Binarios/arboles Registrados.txt","r");	
	
	/* Obtiene el modelo de datos */
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableAB))); 
	
	while (fgets(linea,256,arbol) != NULL)
	{	
		strtok(linea,"\n");
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "mochila" */
		char arbol[12];
		strcpy(arbol,token);
		
		token = strsep(&running, delimiters);    /* token => "peso" */
		char llaves[2];
		strcpy(llaves,token);		
		
		/* Añade una fila vacia */
		gtk_list_store_append(store, &iter);
		
		/* Cambia los valores de la fila */			
		gtk_list_store_set(store,&iter,LIST_ARBOL,arbol,-1);
		gtk_list_store_set(store,&iter,LIST_LLAVES,llaves,-1);			
	}
	fclose(arbol);	
}



/*E: NINGUNA
 *S: LIMPIA TODA LA TABLA TREEVIEW_LIST
 *R: NINGUNA.
 * */
void limpiarTablaAB()
{	
	GtkListStore *store;
	GtkTreeModel *model;
	GtkTreeIter  iter;		
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableAB)));
	model = gtk_tree_view_get_model(GTK_TREE_VIEW(gTableAB));
	if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) 
	{
		return;
	}
	/* Limpia toda la lista */	
	gtk_list_store_clear(store); 
}

void limpiarCamposAB()
{
	gtk_widget_set_sensitive (gButtonAB[0],TRUE);
	gtk_widget_set_sensitive (gButtonAB[1],FALSE);
	gtk_widget_set_sensitive (gTexboxAB[0],TRUE);
	for(int i=0;i<10;i++)
	{
		if(i<3)
		{
			gtk_entry_set_text(GTK_ENTRY(gTexboxAB[i]),"");
		}
		for (int j=0;j<2;j++)
		{
			gtk_entry_set_text(GTK_ENTRY(llavesAB[i][j]),"");
			gtk_widget_set_sensitive (llavesAB[i][j],FALSE);					

		}
	}
}

int existeAB(char arbol[])
{
	FILE *p_arbol;
	char linea[256];	
	p_arbol =fopen("BD Arboles Binarios/arboles Registrados.txt","r");	
	
	while (fgets(linea,256,p_arbol) != NULL)
	{	
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "mochila" */
		char nombre[12];
		strcpy(nombre,token);
		if(!strcmp(arbol,nombre))
		{
			return 1;
		}
	}
	fclose(p_arbol);
	return 0;
}
void agregarTxtAB(char datos[])
{
	/*Agregar en archivo*/
	FILE *arbol;
	arbol =fopen("BD Arboles Binarios/arboles Registrados.txt","a");	
	strtok(datos,"\n");
	fprintf(arbol, "%s\n",datos);	
	fclose(arbol);
}

void agregarAB(GtkWidget *button,gpointer data)
{
	const gchar *nombreArbol=   gtk_entry_get_text(GTK_ENTRY(gTexboxAB[0]));	
	const gchar *cantLlaves=  gtk_entry_get_text(GTK_ENTRY(gTexboxAB[1]));
			
	char ar_arbol[12];	
	char ar_llaves[2];
			
	strcpy(ar_arbol,nombreArbol);
	strcpy(ar_llaves,cantLlaves);
	
	if(!(strlen(ar_arbol))>0)
	{
		ShowMessage("El campo del Nombre del árbol no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(gTexboxAB[0]);
		return;
	}	
	if(existeAB(ar_arbol))	
	{
		ShowMessage("Nombre del árbol ya existe, intente con otro.","¡AVISO!");
		gtk_widget_grab_focus(gTexboxAB[0]);
		return;
	}	
					
	char new_arbol[50];
	sprintf(new_arbol,"%s,%s",ar_arbol,ar_llaves);

	agregarTxtAB(new_arbol);
	
	/*Crear Mochila*/
	FILE *llaves_Arbol;
	char archivo[64];
	sprintf(archivo,"BD Arboles Binarios/%s.txt",ar_arbol);
	llaves_Arbol =fopen(archivo,"w");
	
	char datosCompleto[1024]="";
	
	for (int i=0;i<atoi(ar_llaves);i++)
	{				
		const gchar *llave  = gtk_entry_get_text(GTK_ENTRY(llavesAB[i][0]));
		const gchar *valor  = gtk_entry_get_text(GTK_ENTRY(llavesAB[i][1]));	
					
		char ar_llave[12];	
		char ar_valor[8];
						
		strcpy(ar_llave,llave);
		strcpy(ar_valor,valor);
				
		char datos[20];
		sprintf(datos,"%s,%s\n",ar_llave,ar_valor);
		
		strcat(datosCompleto,datos);		
	}
	fprintf(llaves_Arbol,"%s",datosCompleto);	
	fclose(llaves_Arbol);	
	
	limpiarCamposAB();
	limpiarTablaAB();
	llenarTablaAB();
	
	char message[516];
	sprintf(message,"Se agrego el árbol : %s, con %s llaves",ar_arbol,ar_llaves);
	ShowMessage(message,"¡INFORMACIÓN!");	
}

void editarAB(GtkWidget *button,gpointer data)
{
	const gchar *nombreArbol =     gtk_entry_get_text(GTK_ENTRY(gTexboxAB[0]));
	const gchar *llavesArbol=     gtk_entry_get_text(GTK_ENTRY(gTexboxAB[1]));
	
	
	char ar_arbol[12];
	char ar_llaves[2];

	strcpy(ar_arbol,nombreArbol);
	strcpy(ar_llaves,llavesArbol);
	
	
	FILE *arbol,*temp;	
	arbol=fopen("BD Arboles Binarios/arboles Registrados.txt","r");
	temp =fopen("BD Arboles Binarios/temp2.txt","w");			
	
	char linea[64];
	while (fgets(linea,64,arbol) != NULL)
	{		
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "mochila" */
		char arbol[12];
		strcpy(arbol,token);
		
		if(!strcmp(ar_arbol,arbol)){}
		else
		{
			fprintf(temp,"%s\n",linea);			
		}
	}			
	char new_arbol[50];
	sprintf(new_arbol,"%s,%s",ar_arbol,ar_llaves);
	fprintf(temp,"%s\n",new_arbol);			
	fclose(temp);
	fclose(arbol);
	
	remove("BD Arboles Binarios/arboles Registrados.txt");
	rename("BD Arboles Binarios/temp2.txt","BD Arboles Binarios/arboles Registrados.txt");
	remove("temp2.txt");	
	
	/*Modificar Objetos*/	
	FILE *llaves_arbol;
	char archivo[64];
	sprintf(archivo,"BD Arboles Binarios/%s.txt",ar_arbol);
	llaves_arbol =fopen(archivo,"w");
	
	char datosCompleto[1024]="";
	
	for (int i=0;i<atoi(ar_llaves);i++)
	{				
		const gchar *llave  = gtk_entry_get_text(GTK_ENTRY(llavesAB[i][0]));
		const gchar *valor  = gtk_entry_get_text(GTK_ENTRY(llavesAB[i][1]));	
					
		char ar_llave[12];	
		char ar_valor[8];
						
		strcpy(ar_llave,llave);
		strcpy(ar_valor,valor);
		
		char datos[512];
		sprintf(datos,"%s,%s\n",ar_llave,ar_valor);
		strcat(datosCompleto,datos);	
	}
	fprintf(llaves_arbol,"%s",datosCompleto);
	fclose(llaves_arbol);	
	limpiarTablaAB();
	llenarTablaAB();
	limpiarCamposAB();
	ShowMessage("Los datos del arbol fueron modificados correctamente","¡AVISO!");
}

int mostrarChooseFileAB(GtkWidget * button,gpointer ventana)
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
		gtk_entry_set_text(GTK_ENTRY(gTexboxAB[2]),filename);		
	}
	gtk_widget_destroy (dialog);
}

void cargarDatosAB(char archivo[])
{
		FILE *llaves_arbol;
		llaves_arbol =fopen(archivo,"r");			
		int i=0;char linea[256];	
		
		while (fgets(linea,256,llaves_arbol) != NULL)
		{	
			strtok(linea,"\n");
			const char delimiters[] = ",";
			char * running = strdup(linea);
			char * token;

			token = strsep(&running, delimiters);    /* token => "objeto" */
			char llave[12];
			strcpy(llave,token);
			
			token = strsep(&running, delimiters);    /* token => "valor" */
			char valor[8];
			strcpy(valor,token);
						
			
			gtk_entry_set_text(GTK_ENTRY(llavesAB[i][0]),llave);
			gtk_entry_set_text(GTK_ENTRY(llavesAB[i][1]),valor);
						
			gtk_widget_set_sensitive (llavesAB[i][0],TRUE);					
			gtk_widget_set_sensitive (llavesAB[i][1],TRUE);
			
			i+=1;
		}
		for(int j=i;j<10;j++)
		{
			for(int k=0;k<2;k++)
			{
				gtk_widget_set_sensitive (llavesAB[j][k],FALSE);
				gtk_entry_set_text(GTK_ENTRY(llavesAB[j][k]),"");					
			}
		}		
		sprintf(linea,"%d",i);
}

void mostrarArchivoCargadoAB(GtkWidget * button,gpointer ventana)
{	
	gtk_widget_set_sensitive (gButtonAB[1],FALSE);
	gtk_widget_set_sensitive (gButtonAB[0],TRUE);
	FILE *arbol,*temp;
	const gchar *archivo = gtk_entry_get_text(GTK_ENTRY(gTexboxAB[2]));
	char ar_file[512],linea[64];	
	strcpy(ar_file,archivo);
	if(!strlen(ar_file)>0)
	{
		ShowMessage("No se ha selecionado ninguna ruta","¡AVISO!");
		return;
	}
	arbol = fopen(ar_file,"r");
	temp = fopen("temp.txt","w");			
	int i=0;
	while (fgets(linea,64,arbol) != NULL)
	{
		strtok(linea,"\n");
		if(i==0)
		{
			const char delimiters[] = ",";
			char * running = strdup(linea);
			char * token;
		
			token = strsep(&running, delimiters);    /* token => "mochila" */
			char arbol[12];
			strcpy(arbol,token);
			
			token = strsep(&running, delimiters);    /* token => "peso" */
			char valor[12];
			strcpy(valor,token);
						
			
			gtk_entry_set_text(GTK_ENTRY(gTexboxAB[0]),arbol);
			gtk_entry_set_text(GTK_ENTRY(gTexboxAB[1]),valor);			
		}
		else
		{			
			fprintf(temp,"%s\n",linea);			
		}
		i+=1;	
	}
	fclose(temp);
	cargarDatosAB("temp.txt");
	remove("temp.txt");
	gtk_entry_set_text(GTK_ENTRY(gTexboxAB[2]),"");
}
void SelectedChangedAB(GtkWidget *gTable,gpointer dato) 
{
	
	GtkTreeIter iter;
	GtkTreeModel *model;
	gchar *value;	
	char archivo[64];	
	char path[128]="";
	strcat(path,"BD Arboles Binarios/");
	gtk_widget_grab_focus(gTexboxAB[2]);
	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(gSignalAB),&model,&iter)) 
	{	
		gtk_widget_set_sensitive (gButtonAB[0],FALSE);
		gtk_widget_set_sensitive (gButtonAB[1],TRUE);
		gtk_widget_set_sensitive (gTexboxAB[0],FALSE);
		/* Obtiene el Valor  */
		gtk_tree_model_get(model,&iter,LIST_ARBOL,&value,-1); 		
		 /* Deposita el valor en el entry*/		
		gtk_entry_set_text(GTK_ENTRY(gTexboxAB[0]),value);//Llave
		
		gtk_tree_model_get(model,&iter,LIST_LLAVES,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexboxAB[1]),value);//Valor
		const gchar	*NomArbol = gtk_entry_get_text(GTK_ENTRY(gTexboxAB[0]));
		g_free(value);
		strcpy(archivo,NomArbol);	
		strcat(path,archivo);
		strcat(path,".txt");
		cargarDatosAB(path);
		
		//fclose(archivo);
	}
}

int letraAletra(char palabra1[],char palabra2[])
{
	for(int i=1;palabra1[i]!='\0' | palabra2[i]!='\0';i++)
	{
		if(tolower(palabra1[i]) > tolower(palabra2[i]))
		{
			return 1;
		}
		else if(tolower(palabra1[i]) < tolower(palabra2[i]))
		{
			return 0;
		}
	}
	return 0;
}

void ordenar(int n, char array[n][2][12])
{
	char nombre[12]; 
	char propa[8];
	for (int i=1; i<n; i++)
	{
       for (int j=0; j<n-1;j++)
       {
          if ( tolower(array[j][0][0]) > tolower(array[j+1][0][0]))
          {
             strcpy(nombre,array[j][0]);
             strcpy(propa,array[j][1]);
             
             strcpy(array[j][0],array[j+1][0]);
             strcpy(array[j][1],array[j+1][1]);
             
		     strcpy(array[j+1][0],nombre);		
		     strcpy(array[j+1][1],propa);	
		   }
		   else if(tolower(array[j][0][0]) == tolower(array[j+1][0][0]))
		   {
				int res=letraAletra(array[j][0],array[j+1][0]);
				if(res)
				{
					strcpy(nombre,array[j][0]);
					strcpy(propa,array[j][1]);    
					
					strcpy(array[j][0],array[j+1][0]);
					strcpy(array[j][1],array[j+1][1]);         					
					
					strcpy(array[j+1][0],nombre);		
					strcpy(array[j+1][1],propa);
				}				
			}
	   }
   }
}


void formarMatrizAB()
{
	const gchar *nombreArbol =     gtk_entry_get_text(GTK_ENTRY(gTexboxAB[0]));
	const gchar *llavesArbol=     gtk_entry_get_text(GTK_ENTRY(gTexboxAB[1]));
	
	char ar_arbol[12];
	char ar_llaves[8];
	
	strcpy(ar_arbol,nombreArbol);
	strcpy(ar_llaves,llavesArbol);
	int n=atoi(ar_llaves);
	
	float matrizA[n+1][n+1];	
	int matrizR[n+1][n+1];	
	char matrizC[n+1][n+1];	
	char array[n][2][12];
	
	for(int i=0;i<n;i++)
	{					

		for(int j=0;j<2;j++)
		{
			const gchar  *valor = gtk_entry_get_text(GTK_ENTRY(llavesAB[i][j])); 
			if(strlen(valor)==0)
			{
				ShowMessage("Hay una llave sin definir, Favor llenarla o eliminar la linea","¡ERROR!");
				return;
			}
			else
			{
				strcpy(array[i][j],valor);
				
			}
		}
	}
	
		
	//Ordenar el array 		
	ordenar(n,array);
				
	//Sacar el total de las llaves			
	float total=0;
	for(int k=0;k<n;k++)
	{
		total+=atoi(array[k][1]);
	}	
	
	//Sacar la probabilidad de los valores de las llaves	
	float probabilidades[n];				
	for(int m=0;m<n;m++)
	{
		float p= atof(array[m][1]);
		probabilidades[m]=p/total;
	}
	//inicializa matrizA y matrizR
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			matrizA[i][j]=0.0;
			matrizR[i][j]=0;
			matrizC[i][j]='N';
		}
	}
	
	for(int k=1;k<n+1;k++)
	{
		matrizA[k-1][k]=probabilidades[k-1];
		matrizC[k-1][k]='C';
	}
	
	for(int k=1;k<n+1;k++)
	{
		matrizR[k-1][k]=k;
	}
  
   //algoritmo arbol binario de busqueda optimo
   int par = n*(n+1)/2; // la sumatoria del numero
   int k=0; // contador de la cantidad de vueltas 
     
   int i=0; 
   int jj=2;
   int flag=0; 
   while(k!=par)
   {			
		for(int j=jj;j<=n;j++)
		{
			float probas=0.0;
			for(int m=i;m<j;m++)
			{
				probas+=probabilidades[m];
			}			
			float menor = 99999.9;
			int res=0;
			for(int k=(i+1);k<=j;k++)
			{
				float valor= matrizA[i][k-1] + matrizA[k][j] + probas;
				//printf("matrizA[%d][%d] = %.4f  + matrizA[%d][%d]= %.4f + P %.4f = %.4f\n",i,k-1,matrizA[i][k-1],k+1,j,matrizA[k][j],probas,valor);
				if(valor<menor)
				{
					
					menor=valor;
					flag=1;
					res=k;
				}
			}			
			if(flag)
			{
				//printf("Matriz[%d][%d]= %.4f\n",i,j,menor);
				matrizA[i][j]=menor;
				matrizR[i][j]=res;
				matrizC[i][j]='C';
				flag=0;
			}									
			i+=1;
		}
		k+=1;
		jj+=1;
		i=0;
					
   }   	
	
	mostrarTablaAB(total,n,matrizA,matrizR,matrizC,probabilidades,array,ar_arbol);

}

void mostrarTablaAB (float total,int n,float matrizA[n+1][n+1],int matrizR[n+1][n+1],char matrizC[n+1][n+1],float probabilidades[],char array[n][2][12],char arbol[])
{
	GtkWidget  * ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),arbol);		
	gtk_window_set_default_size(GTK_WINDOW(ventana),1366,768);
	gtk_widget_set_name(GTK_WIDGET(ventana),"winWhite");
	
	/*GdkRGBA color;
	gboolean res = gdk_rgba_parse (&color, "#ffffff");
	gtk_widget_override_background_color (ventana,GTK_STATE_FLAG_NORMAL,&color);*/
	
	GtkWidget  * sw = gtk_scrolled_window_new(NULL, NULL);	
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_widget_set_size_request(sw,1000,700);
		
	/*Crea un modelo*/
	GtkWidget *modelo= gtk_fixed_new ();	
	/*Carga imagen a la ventana*/
	GtkWidget *image = gtk_image_new_from_file ("BD Arboles Binarios/EncabezadoAB.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);	
	
		
	int x=60;
	int y=280;
	
	char *encabezado[4]={"Linea","LLave","Valor","Probabilidad"};
			
	/*Emcabezado de objetos*/
	for(int i=0;i<4;i++)
	{
		char texto[16];
		sprintf(texto, "%s", encabezado[i]);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);	
		x+=90;
	}
	x=70;
	y=310;
	for(int j=1;j<=n;j++)
	{
		char texto[2];
		sprintf(texto, "%d", j);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);
		y+=30;
	}	
	x=130;
	y=310;
	
	/*Mostrar tabla de objetos*/
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			char texto[16];
			sprintf(texto, "%s", array[i][j]);
			if(j==0)
			{				
				char cant[8];
				sprintf(cant, "%.4f", probabilidades[i]);
				GtkWidget *cantidades = gtk_label_new(cant);
				gtk_fixed_put(GTK_FIXED(modelo),cantidades,x+200,y);
			}			
			GtkWidget *label1 = gtk_label_new(texto);
			gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);
			x+=120;
		}
		x=130;
		y+=30;
	}
	char ar_total[16];
	sprintf(ar_total, "%.1f",total);
	GtkWidget *labelTotal = gtk_label_new(ar_total);
	gtk_fixed_put(GTK_FIXED(modelo),labelTotal,x+120,y);	
	
	GtkWidget *labelproba = gtk_label_new("1.0");
	gtk_fixed_put(GTK_FIXED(modelo),labelproba,x+200,y);	
				
	char tituloOb[128];
	sprintf(tituloOb,"Llaves del Árbol %s",arbol);
	GtkWidget *groupTextCargar =gtk_frame_new (tituloOb);	
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,50,240);
	gtk_widget_set_size_request( groupTextCargar , x+260 ,y-200);
	
	
	char ar_promerio[16];
	sprintf(ar_promerio, "El promedio mínimo del árbol %s es %.4f",arbol,matrizA[0][n]);
	GtkWidget *labelpromedio = gtk_label_new(ar_promerio);
	gtk_fixed_put(GTK_FIXED(modelo),labelpromedio,x+400,280);
	
	char ar_raiz[16];
	sprintf(ar_raiz, "La raíz del árbol %s de ser la llave %d",arbol,matrizR[0][n]);
	GtkWidget *labelraiz = gtk_label_new(ar_raiz);
	gtk_fixed_put(GTK_FIXED(modelo),labelraiz,x+400,310);
	
	char titulores[128];
	sprintf(titulores,"Respuestas del árbol %s",arbol);
	GtkWidget *groupTextRespuesta =gtk_frame_new (titulores);	
	gtk_fixed_put(GTK_FIXED(modelo),groupTextRespuesta,x+390,240);
	gtk_widget_set_size_request( groupTextRespuesta , 400 ,120);
	
		
	/*Colocando emcabezados de la tabla */	
	x=130;
	
	for(int j=0;j<=n;j++)
	{
		char texto[16];
		sprintf(texto, "%d",j);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y+90);	
		x+=100;
	}	
	for(int i=1;i<=n+1;i++)
	{
		char texto[16];
		sprintf(texto, "%d", i);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,70,y+120);
		y+=40;

	}
	x=40;
	y-=(40*n+1);
	matrizC[0][n]='V';
	for(int i=0;i<n+1;i++)
	{									
		for (int j=0;j<=n;j++)
		{
			char texto[16];
			sprintf(texto, "%.4f", matrizA[i][j]);
			GtkWidget *label1 = gtk_label_new(texto);
			gtk_widget_set_size_request( label1 ,90,30);			
			if(matrizC[i][j]=='V')
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelGreen");
				//res = gdk_rgba_parse (&color, "#09ff00");
			}
			else if(matrizC[i][j]=='C')
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelLightBlue");
				//res = gdk_rgba_parse (&color, "#a9e2f3");
			}
					
			else
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelDark");
				//res = gdk_rgba_parse (&color, "#000000");							
			}
			//gtk_widget_override_background_color (label1,GTK_STATE_FLAG_NORMAL,&color);
			gtk_fixed_put(GTK_FIXED(modelo),label1,x+50,y+80);
			x+=100;;
		}		
		y+=40;
		x=40;
	}
	int posy=y;
	y-=(40*n+1);
	char tituloTab[128];
	sprintf(tituloTab,"Tabla de promedio minimo del árbol: %s",arbol)	;
	GtkWidget *groupTextTabOptima =gtk_frame_new (tituloTab);
	gtk_fixed_put(GTK_FIXED(modelo),groupTextTabOptima,50,y-20);
	gtk_widget_set_size_request( groupTextTabOptima, 100*(n+1)+50 ,y-200);
		
	x=40;
	posy+=90;
	for(int i=0;i<n+1;i++)
	{									
		for (int j=0;j<=n;j++)
		{
			char texto[16];
			sprintf(texto, "%d", matrizR[i][j]);	
			GtkWidget *label1 = gtk_label_new(texto);
			gtk_widget_set_size_request( label1 ,90,30);		
			if(matrizC[i][j]=='V')
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelGreen");
				//res = gdk_rgba_parse (&color, "#09ff00");
			}
			else if(matrizC[i][j]=='C')
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelLightBlue");
				//res = gdk_rgba_parse (&color, "#a9e2f3");
			}
					
			else
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelDark");
				//res = gdk_rgba_parse (&color, "#000000");							
			}
			
			//gtk_widget_override_background_color (label1,GTK_STATE_FLAG_NORMAL,&color);
			gtk_fixed_put(GTK_FIXED(modelo),label1,x+50,posy+80);
			x+=100;;
		}		
		posy+=40;
		x=40;
	}	
	
	posy-=(40*n+1);
	char titulotabR[128];
	sprintf(titulotabR,"Tabla R  del árbol: %s",arbol)	;
	GtkWidget *groupTextTabR =gtk_frame_new (titulotabR);
	gtk_fixed_put(GTK_FIXED(modelo),groupTextTabR,50,posy);
	gtk_widget_set_size_request( groupTextTabR, 100*(n+1)+50 ,posy-550);
			
	
	GtkWidget *fin = gtk_label_new(" ");
	gtk_fixed_put(GTK_FIXED(modelo),fin,10,40*(n+1)*3);
	
	GtkWidget *finlado = gtk_label_new(" ");
	gtk_fixed_put(GTK_FIXED(modelo),finlado,2000,20);
	
	gtk_container_add(GTK_CONTAINER(sw),modelo);
	gtk_container_add(GTK_CONTAINER(ventana),sw);

	gtk_widget_show_all(ventana);
		
	/* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	/* Termina la aplicación */
	gtk_main(); 
	
}


int validarAB(GtkWidget *entry,gpointer puntero)
{
	const gchar *arbol = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_arbol[12];
	
	strcpy(ar_arbol,arbol);
	
	strtok(ar_arbol,"\n");
	
	if(!strlen(ar_arbol)>0)
	{
		ShowMessage("El nombre del arbol no puede ser vacio","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}	
	else if(IS_NUM(ar_arbol))
	{
		ShowMessage("El nombre del arbol debe tener al menos un caracter","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}
	else if(existeAB(ar_arbol))
	{
		ShowMessage("Nombre del arbol ya existe, favor intente con otro nombre","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}	
}



int validarLlaveAB(GtkWidget *entry,gpointer puntero)
{
	const gchar *llave = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_llave[12];
	strcpy(ar_llave,llave);
	int val = IS_NUM(ar_llave);
	strtok(ar_llave,"\n");
	if(!strlen(ar_llave)>0)
	{
		ShowMessage("El nombre de la llave no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}
	else if(val)
	{
		ShowMessage("El nombre de la llave debe tener al menos una letra","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}
	return 0;
}
int ValidarValorAB(GtkWidget *entry,gpointer puntero)
{
	const gchar *valor = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_valor[6];
	strcpy(ar_valor,valor);
	int val = IS_NUM(ar_valor);
	strtok(ar_valor,"\n");
	if(!strlen(ar_valor)>0)
	{
		ShowMessage("El valor no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(!val)
	{
		ShowMessage("El valor solo acepta numeros enteros positivos","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(atoi(ar_valor)<1)
	{
		ShowMessage("El valor solo acepta numeros enteros positivos mayores a 0","¡AVISO!");	
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	return 0;
}

void cuerpoAB(GtkWidget *ventana)
{
	
	/*Crea un modelo*/
	GtkWidget *modelo= gtk_fixed_new ();	
	/*Carga imagen a la ventana*/
	GtkWidget *image = gtk_image_new_from_file ("BD Arboles Binarios/EncabezadoAB.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);	
	
	/*Creando un Gruptext*/
	GtkWidget *groupTextMochila =gtk_frame_new ("Árboles Registrados");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextMochila,10,230);
	gtk_widget_set_size_request( groupTextMochila ,215 ,380);
	
	GtkWidget *groupTextGeneral =gtk_frame_new ("Datos generales del Árbol");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextGeneral,300,230);
	gtk_widget_set_size_request( groupTextGeneral ,400 ,250);
	
	GtkWidget *groupTextObjetos =gtk_frame_new ("Llaves del Árbol");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextObjetos,800,230);
	gtk_widget_set_size_request( groupTextObjetos ,390 ,370);
	
	GtkWidget *groupTextCargar =gtk_frame_new ("Cargar Archivos");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,300,490);
	gtk_widget_set_size_request( groupTextCargar ,480 ,110);
	
	/*Inicializar tabla*/
	gTableAB = gtk_tree_view_new(); /* Crea la vista de la lista */
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(gTableAB),TRUE); /* Visualiza las cebeceras de la lista */
	gSignalAB = gtk_tree_view_get_selection(GTK_TREE_VIEW(gTableAB));


	/*Posicionar tabla*/
	gtk_fixed_put(GTK_FIXED(modelo),gTableAB,20,250);
	
	/*Etiquetas*/
	GtkWidget *gLabelArbol,*gLabelLlaves,*gLabellinea,*gLabelNombreLlave,*gLabelValor;
	GtkWidget *gLabelRuta;
	
	/*TextBox*/
	GtkWidget *gTextBoxArbol,*gTextBoxLlaves,*gTextBoxRuta;
	
	/*Buttons*/
	GtkWidget *gButtonAgregar,*gButtonEditar,*gButtonVolver,*gButtonCargar,*gButtonBusqueda,*gButtonLimpiar ,*gButtonResolver;
	
	/*Inicializar GtkWidget*/
	gLabelArbol = gtk_label_new("Nombre Árbol:");
	gLabelLlaves = gtk_label_new("Llaves del Árbol:");
	
	gLabellinea = gtk_label_new("Linea");
	gLabelNombreLlave = gtk_label_new("Nombre LLave");
	gLabelValor = gtk_label_new("Valor de Llave");
	
	gLabelRuta=gtk_label_new("Ruta:");
	
	gTextBoxArbol = gtk_entry_new();
	gTextBoxLlaves = gtk_entry_new();
	
	gTextBoxRuta=gtk_entry_new();
	
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxArbol),12);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxLlaves),2);
		
	gtk_widget_set_size_request(gTextBoxRuta ,380,-1);

	gButtonAgregar = gtk_button_new_with_label("Agregar árbol");
	gButtonEditar = gtk_button_new_with_label("Editar árbol");
	gButtonVolver = gtk_button_new_with_label("Volver");
	gButtonCargar =gtk_button_new_with_label("Cargar");
	gButtonBusqueda=gtk_button_new_with_label("...");
	gButtonLimpiar=gtk_button_new_with_label("Limpiar");
	gButtonResolver=gtk_button_new_with_label("Resolver");
	
	/*Posicionar GtkWidget*/
	gtk_fixed_put(GTK_FIXED(modelo),gLabelArbol,320,270);	
	gtk_fixed_put(GTK_FIXED(modelo),gLabelLlaves,320,300);
		
	gtk_fixed_put(GTK_FIXED(modelo),gLabellinea,820,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelNombreLlave,890,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelValor,1020,250);	
	
	gtk_fixed_put(GTK_FIXED(modelo),gLabelRuta,320,520);

	
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxArbol,520,265);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxLlaves,520,295);
		
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxRuta,360,515);

	
	gtk_fixed_put(GTK_FIXED(modelo),gButtonAgregar,320,400);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonEditar,450,400);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonResolver,400,430);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonLimpiar,620,400);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonVolver,630,440);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonCargar,680,555);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonBusqueda,750,515);
	


	gButtonAB[0]=gButtonAgregar;
	gButtonAB[1]=gButtonEditar;
	gtk_widget_set_sensitive (gButtonEditar,FALSE);

		
	/*Iterando Campos de objetos*/	
	int x=885;
	int y=270;
	int xl=830;
	for(int i =0;i<10;i++)
	{			
		for(int j=0;j<2;j++)
		{		
			GtkWidget *entry = gtk_entry_new();
			gtk_entry_set_width_chars(GTK_ENTRY(entry),12);
			gtk_entry_set_max_length(GTK_ENTRY(entry),12);

			if (j==0)//entrys de nombre
			{				
				g_signal_connect (G_OBJECT (entry), "focus-out-event",G_CALLBACK (validarLlaveAB), NULL);
				llavesAB[i][j]=entry;
			}
			else if(j==1)//entrys de peso
			{		
				x-=20;		
				char num[2];
				sprintf(num,"%d",(i+1));
				GtkWidget *gLabelLinea=gtk_label_new(num);
				gtk_fixed_put(GTK_FIXED(modelo),gLabelLinea,xl,y+5);				
				gtk_entry_set_width_chars(GTK_ENTRY(entry),8);
				gtk_entry_set_max_length(GTK_ENTRY(entry),8);
				g_signal_connect (G_OBJECT (entry), "focus-out-event",G_CALLBACK (ValidarValorAB),NULL);
				llavesAB[i][j]=entry;
			}
			gtk_widget_set_sensitive (entry, FALSE);					
			gtk_fixed_put(GTK_FIXED(modelo),entry,x,y);	
			x+=160;
		}
		x=885;
		y+=30;
	}
	
	/*Lista de textbox */
	gTexboxAB[0]=gTextBoxArbol;
	gTexboxAB[1]=gTextBoxLlaves;
	gTexboxAB[2]=gTextBoxRuta;
	/*Señales*/
	
	/*Señal para la seleccion*/
	g_signal_connect(gSignalAB,"changed",G_CALLBACK(SelectedChangedAB),NULL); 
	
	/*Señales para los Textbox*/
	g_signal_connect (G_OBJECT (gTextBoxLlaves), "focus-out-event",G_CALLBACK (gTextBoxVisibleAB),NULL);
	g_signal_connect (G_OBJECT (gTextBoxArbol), "focus-out-event",G_CALLBACK (validarAB),NULL);
	
	
	/*Señales para los botones*/
	g_signal_connect (G_OBJECT (gButtonAgregar), "clicked",G_CALLBACK (agregarAB),NULL);
	g_signal_connect (G_OBJECT (gButtonEditar), "clicked",G_CALLBACK (editarAB),NULL);
	g_signal_connect (G_OBJECT (gButtonResolver), "clicked",G_CALLBACK (formarMatrizAB),NULL);
	g_signal_connect (G_OBJECT (gButtonBusqueda), "clicked",G_CALLBACK (mostrarChooseFileAB),ventana);
	g_signal_connect (G_OBJECT (gButtonCargar), "clicked",G_CALLBACK (mostrarArchivoCargadoAB),ventana);
	g_signal_connect (G_OBJECT (gButtonLimpiar), "clicked",G_CALLBACK (limpiarCamposAB),ventana);
	g_signal_connect(G_OBJECT(gButtonVolver),"clicked",G_CALLBACK(cerrarVentana),ventana); 




	
	/*Set modelo en la ventana*/
	gtk_container_add(GTK_CONTAINER(ventana),modelo);
	
	/*Mostrar Todo*/
	gtk_widget_show_all(ventana);		

}
int gTextBoxVisibleAB(GtkWidget *entry,gpointer puntero)
{
	const gchar * cantidad = gtk_entry_get_text(GTK_ENTRY(entry));
	char cant[2];
	strcpy(cant,cantidad);
	int fin = IS_NUM(cant);
	strtok(cant,"\n");
	if(!strlen(cant))
	{
		ShowMessage("El campo CANTIDAD DE LLAVES no puede ser vacio","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	if(!fin)
	{
		ShowMessage("El campo CANTIDAD DE LLAVES solo acepta numeros enteros positivos","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;	
	}
	else if(atoi(cant)>10)
	{
		ShowMessage("La cantidad de llaves no puede ser mayor a 10","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<2;j++)
			{	
				gtk_widget_set_sensitive (llavesAB[i][j],TRUE);					
				if(i>=atoi(cant))
				{
					gtk_entry_set_text(GTK_ENTRY(llavesAB[i][j]),"");
					gtk_widget_set_sensitive (llavesAB[i][j],FALSE);					
				}		
			}
		}
		return 0;
	}	
}

int winArbonBinario()
{
	/*Crear ventana con sus propiedades*/
	GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Árboles Binarios de Búsqueda Óptimos");		
	gtk_window_set_default_size(GTK_WINDOW(ventana),1366,768);
	gtk_widget_set_name(GTK_WIDGET(ventana),"winWhite");
	
	/*GdkRGBA color;
	gboolean res = gdk_rgba_parse (&color, "#ffffff");
	gtk_widget_override_background_color (ventana,GTK_STATE_FLAG_NORMAL,&color);	*/
				
	
	/*Llama al cuerpo de la ventana*/
	cuerpoAB(ventana);
	iniciarTablaAB();
	llenarTablaAB();
	 /* Muestra la ventana principal con todo su contenido */
	gtk_widget_show_all(ventana);		
	 /* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	/* Termina la aplicación */
	gtk_main(); 
	
	return 0;
}
