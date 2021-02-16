/* Curso :     Investigación de Operaciones
 * Estudiante: Jordan H. Araya Leiva
 * Carné:      2016254282
 * 
 * 
 * Proyecto Programado #6 : Multiplicación de Matrices
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

enum {LIST_MATRIZ=0,LIST_NMATRICES,N_COLUMNASMM};



/* Lista de Datos*/
GtkWidget *gTableMM;

 /* Puntero a la fila seleccionada */
GtkTreeSelection *gSignalMM;

/*Arreglo de GtkWidget*/
GtkWidget *matricesMM[10][2];
GtkWidget *gTexboxMM[3];
GtkWidget *gButtonMM[2];

/*E: NINGUNA.
 *S: INICIALIZA UNA TABLA PARA PODER LLENARSE CON LOS GRAFOS.
 *R: NINGUNA.
 * */
void iniciarTablaMM() /* Función que inicializa la lista de datos */
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkListStore *store;	

	 /* Establece la columna y la agrega*/
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Nombre Matriz",renderer,"text",LIST_MATRIZ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableMM),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("# Matrices",renderer,"text",LIST_NMATRICES,NULL);	
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableMM),column);	 
			
	
	store = gtk_list_store_new(N_COLUMNASMM,G_TYPE_STRING,G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW(gTableMM),GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void llenarTablaMM()
{		
	FILE *matriz;
	
	GtkListStore *store;
	GtkTreeIter iter;
	
	char linea[256];	
	matriz =fopen("BD Multiplicacion Matrices/matrices registradas.txt","r");	
	
	/* Obtiene el modelo de datos */
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableMM))); 
	
	while (fgets(linea,256,matriz) != NULL)
	{	
		strtok(linea,"\n");
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "mochila" */
		char matriz[12];
		strcpy(matriz,token);
		
		token = strsep(&running, delimiters);    /* token => "peso" */
		char nMatrices[2];
		strcpy(nMatrices,token);		
		
		/* Añade una fila vacia */
		gtk_list_store_append(store, &iter);
		
		/* Cambia los valores de la fila */			
		gtk_list_store_set(store,&iter,LIST_MATRIZ,matriz,-1);
		gtk_list_store_set(store,&iter,LIST_NMATRICES,nMatrices,-1);			
	}
	fclose(matriz);	
}



/*E: NINGUNA
 *S: LIMPIA TODA LA TABLA TREEVIEW_LIST
 *R: NINGUNA.
 * */
void limpiarTablaMM()
{	
	GtkListStore *store;
	GtkTreeModel *model;
	GtkTreeIter  iter;		
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableMM)));
	model = gtk_tree_view_get_model(GTK_TREE_VIEW(gTableMM));
	if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) 
	{
		return;
	}
	/* Limpia toda la lista */	
	gtk_list_store_clear(store); 
}

void limpiarCamposMM()
{
	gtk_widget_set_sensitive (gButtonMM[0],TRUE);
	gtk_widget_set_sensitive (gButtonMM[1],FALSE);
	gtk_widget_set_sensitive (gTexboxMM[0],TRUE);
	for(int i=0;i<10;i++)
	{
		if(i<3)
		{
			gtk_entry_set_text(GTK_ENTRY(gTexboxMM[i]),"");
		}
		for (int j=0;j<2;j++)
		{
			gtk_entry_set_text(GTK_ENTRY(matricesMM[i][j]),"");
			gtk_widget_set_sensitive (matricesMM[i][j],FALSE);					

		}
	}
}

int existeMM(char matriz[])
{
	FILE *p_matriz;
	char linea[256];	
	p_matriz =fopen("BD Multiplicacion Matrices/matrices registradas.txt","r");	
	
	while (fgets(linea,256,p_matriz) != NULL)
	{	
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "mochila" */
		char nombre[12];
		strcpy(nombre,token);
		if(!strcmp(matriz,nombre))
		{
			return 1;
		}
	}
	fclose(p_matriz);
	return 0;
}
void agregarTxtMM(char datos[])
{
	/*Agregar en archivo*/
	FILE *matriz;
	matriz =fopen("BD Multiplicacion Matrices/matrices registradas.txt","a");	
	strtok(datos,"\n");
	fprintf(matriz, "%s\n",datos);	
	fclose(matriz);
}

void agregarMM(GtkWidget *button,gpointer data)
{
	const gchar *nombreMatriz=   gtk_entry_get_text(GTK_ENTRY(gTexboxMM[0]));	
	const gchar *cantMatrices=  gtk_entry_get_text(GTK_ENTRY(gTexboxMM[1]));
			
	char ar_matriz[12];	
	char ar_nMatrices[2];
			
	strcpy(ar_matriz,nombreMatriz);
	strcpy(ar_nMatrices,cantMatrices);
	
	if(!(strlen(ar_matriz))>0)
	{
		ShowMessage("El campo del Nombre de la matriz no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(gTexboxMM[0]);
		return;
	}	
	if(existeMM(ar_matriz))	
	{
		ShowMessage("Nombre de la matriz ya existe, intente con otro.","¡AVISO!");
		gtk_widget_grab_focus(gTexboxMM[0]);
		return;
	}	
					
	char new_matriz[50];
	sprintf(new_matriz,"%s,%s",ar_matriz,ar_nMatrices);

	agregarTxtMM(new_matriz);
	
	/*Crear Mochila*/
	FILE *matrices_Mat;
	char archivo[64];
	sprintf(archivo,"BD Multiplicacion Matrices/%s.txt",ar_matriz);
	matrices_Mat =fopen(archivo,"w");
	
	char datosCompleto[1024]="";
	
	for (int i=0;i<atoi(ar_nMatrices);i++)
	{				
		const gchar *izquierda  = gtk_entry_get_text(GTK_ENTRY(matricesMM[i][0]));
		const gchar *derecha  = gtk_entry_get_text(GTK_ENTRY(matricesMM[i][1]));	
					
		char ar_izq[2];	
		char ar_der[2];
						
		strcpy(ar_izq,izquierda);
		strcpy(ar_der,derecha);
				
		char datos[20];
		sprintf(datos,"%s,%s\n",ar_izq,ar_der);
		
		strcat(datosCompleto,datos);		
	}
	fprintf(matrices_Mat,"%s",datosCompleto);	
	fclose(matrices_Mat);	
	
	limpiarCamposMM();
	limpiarTablaMM();
	llenarTablaMM();
	
	char message[516];
	sprintf(message,"Se agrego la matriz : %s, con %s matrices",ar_matriz,ar_nMatrices);
	ShowMessage(message,"¡INFORMACIÓN!");	
}

void editarMM(GtkWidget *button,gpointer data)
{
	const gchar *nombreMatrix =     gtk_entry_get_text(GTK_ENTRY(gTexboxMM[0]));
	const gchar *cantMatrices=     gtk_entry_get_text(GTK_ENTRY(gTexboxMM[1]));
	
	
	char ar_matriz[12];
	char ar_nMatrices[2];

	strcpy(ar_matriz,nombreMatrix);
	strcpy(ar_nMatrices,cantMatrices);
	
	
	FILE *matriz,*temp;	
	matriz=fopen("BD Multiplicacion Matrices/matrices registradas.txt","r");
	temp =fopen("BD Multiplicacion Matrices/temp2.txt","w");			
	
	char linea[64];
	while (fgets(linea,64,matriz) != NULL)
	{		
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "mochila" */
		char matriz[12];
		strcpy(matriz,token);
		
		if(!strcmp(ar_matriz,matriz)){}
		else
		{
			fprintf(temp,"%s\n",linea);			
		}
	}			
	char new_matriz[50];
	sprintf(new_matriz,"%s,%s",ar_matriz,ar_nMatrices);
	fprintf(temp,"%s\n",new_matriz);			
	fclose(temp);
	fclose(matriz);
	
	remove("BD Multiplicacion Matrices/matrices registradas.txt");
	rename("BD Multiplicacion Matrices/temp2.txt","BD Multiplicacion Matrices/matrices registradas.txt");
	remove("BD Multiplicacion Matrices/temp2.txt");	
	
	/*Modificar Objetos*/	
	FILE *cant_matrices;
	char archivo[128];
	sprintf(archivo,"BD Multiplicacion Matrices/%s.txt",ar_matriz);
	cant_matrices =fopen(archivo,"w");
	
	char datosCompleto[1024]="";
	
	for (int i=0;i<atoi(ar_nMatrices);i++)
	{				
		const gchar *izquierda  = gtk_entry_get_text(GTK_ENTRY(matricesMM[i][0]));
		const gchar *derecha  = gtk_entry_get_text(GTK_ENTRY(matricesMM[i][1]));	
					
		char ar_izq[12];	
		char ar_der[8];
						
		strcpy(ar_izq,izquierda);
		strcpy(ar_der,derecha);
		
		char datos[512];
		sprintf(datos,"%s,%s\n",ar_izq,ar_der);
		strcat(datosCompleto,datos);	
	}
	fprintf(cant_matrices,"%s",datosCompleto);
	fclose(cant_matrices);	
	limpiarTablaMM();
	llenarTablaMM();
	limpiarCamposMM();
	ShowMessage("Los datos de la matriz fueron modificados correctamente","¡AVISO!");
}

int mostrarChooseFileMM(GtkWidget * button,gpointer ventana)
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
		gtk_entry_set_text(GTK_ENTRY(gTexboxMM[2]),filename);		
	}
	gtk_widget_destroy (dialog);
}

void cargarDatosMM(char archivo[])
{
		FILE *cant_matrices;
		cant_matrices =fopen(archivo,"r");			
		int i=0;char linea[256];	
		
		while (fgets(linea,256,cant_matrices) != NULL)
		{	
			strtok(linea,"\n");
			const char delimiters[] = ",";
			char * running = strdup(linea);
			char * token;

			token = strsep(&running, delimiters);    /* token => "objeto" */
			char izq[2];
			strcpy(izq,token);
			
			token = strsep(&running, delimiters);    /* token => "valor" */
			char der[2];
			strcpy(der,token);
						
			
			gtk_entry_set_text(GTK_ENTRY(matricesMM[i][0]),izq);
			gtk_entry_set_text(GTK_ENTRY(matricesMM[i][1]),der);
						
			gtk_widget_set_sensitive (matricesMM[i][0],TRUE);					
			gtk_widget_set_sensitive (matricesMM[i][1],TRUE);
			
			i+=1;
		}
		for(int j=i;j<10;j++)
		{
			for(int k=0;k<2;k++)
			{
				gtk_widget_set_sensitive (matricesMM[j][k],FALSE);
				gtk_entry_set_text(GTK_ENTRY(matricesMM[j][k]),"");					
			}
		}		
		sprintf(linea,"%d",i);
}

void mostrarArchivoCargadoMM(GtkWidget * button,gpointer ventana)
{	
	gtk_widget_set_sensitive (gButtonMM[1],FALSE);
	gtk_widget_set_sensitive (gButtonMM[0],TRUE);
	FILE *matriz,*temp;
	const gchar *archivo = gtk_entry_get_text(GTK_ENTRY(gTexboxMM[2]));
	char ar_file[512],linea[64];	
	strcpy(ar_file,archivo);
	if(!strlen(ar_file)>0)
	{
		ShowMessage("No se ha selecionado ninguna ruta","¡AVISO!");
		return;
	}
	matriz = fopen(ar_file,"r");
	temp = fopen("temp.txt","w");			
	int i=0;
	while (fgets(linea,64,matriz) != NULL)
	{
		strtok(linea,"\n");
		if(i==0)
		{
			const char delimiters[] = ",";
			char * running = strdup(linea);
			char * token;
		
			token = strsep(&running, delimiters);    /* token => "matriz" */
			char matriz[12];
			strcpy(matriz,token);
			
			token = strsep(&running, delimiters);    /* token => "cant" */
			char nMatrices[12];
			strcpy(nMatrices,token);
						
			
			gtk_entry_set_text(GTK_ENTRY(gTexboxMM[0]),matriz);
			gtk_entry_set_text(GTK_ENTRY(gTexboxMM[1]),nMatrices);			
		}
		else
		{			
			fprintf(temp,"%s\n",linea);			
		}
		i+=1;	
	}
	fclose(temp);
	cargarDatosMM("temp.txt");
	remove("temp.txt");
	gtk_entry_set_text(GTK_ENTRY(gTexboxMM[2]),"");
}

void SelectedChangedMM(GtkWidget *gTable,gpointer dato) 
{
	
	GtkTreeIter iter;
	GtkTreeModel *model;
	gchar *value;	
	char archivo[64];	
	char path[128]="";
	strcat(path,"BD Multiplicacion Matrices/");
	gtk_widget_grab_focus(gTexboxMM[2]);
	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(gSignalMM),&model,&iter)) 
	{	
		gtk_widget_set_sensitive (gButtonMM[0],FALSE);
		gtk_widget_set_sensitive (gButtonMM[1],TRUE);
		gtk_widget_set_sensitive (gTexboxMM[0],FALSE);
		/* Obtiene el Valor  */
		gtk_tree_model_get(model,&iter,LIST_MATRIZ,&value,-1); 		
		 /* Deposita el valor en el entry*/		
		gtk_entry_set_text(GTK_ENTRY(gTexboxMM[0]),value);//Llave
		
		gtk_tree_model_get(model,&iter,LIST_NMATRICES,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexboxMM[1]),value);//Valor
		const gchar	*NomMatriz = gtk_entry_get_text(GTK_ENTRY(gTexboxMM[0]));
		
		g_free(value);
		strcpy(archivo,NomMatriz);	
		strcat(path,archivo);
		strcat(path,".txt");
		cargarDatosMM(path);		
		//fclose(archivo);
	}
}

int gTextBoxVisibleMM(GtkWidget *entry,gpointer puntero)
{
	const gchar * cantidad = gtk_entry_get_text(GTK_ENTRY(entry));
	char cant[2];
	strcpy(cant,cantidad);
	int fin = IS_NUM(cant);
	strtok(cant,"\n");
	if(!strlen(cant))
	{
		ShowMessage("El campo CANTIDAD DE MATRICES no puede ser vacio","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	if(!fin)
	{
		ShowMessage("El campo CANTIDAD DE MATRICES solo acepta numeros enteros positivos","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;	
	}
	else if(atoi(cant)>10)
	{
		ShowMessage("La cantidad de Matrices no puede ser mayor a 10","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<2;j++)
			{	
				gtk_widget_set_sensitive (matricesMM[i][j],TRUE);					
				if(i>=atoi(cant))
				{
					gtk_entry_set_text(GTK_ENTRY(matricesMM[i][j]),"");
					gtk_widget_set_sensitive (matricesMM[i][j],FALSE);					
				}		
			}
		}
		return 0;
	}	
}

int validarNmatriz(GtkWidget *entry,gpointer puntero)
{
	const gchar *valor = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_valor[2];
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

int validarMM(GtkWidget *entry,gpointer puntero)
{
	const gchar *matriz = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_matriz[12];
	
	strcpy(ar_matriz,matriz);
	
	strtok(ar_matriz,"\n");
	
	if(!strlen(ar_matriz)>0)
	{
		ShowMessage("El nombre de la matriz no puede ser vacio","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}	
	else if(IS_NUM(ar_matriz))
	{
		ShowMessage("El nombre de la matriz debe tener al menos un caracter","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}
	else if(existeMM(ar_matriz))
	{
		ShowMessage("Nombre de la matriz ya existe, favor intente con otro nombre","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}	
}


int validarFormatoMM(int n,int array[n][2])
{
	for(int i=0;i<n;i++)
	{
		if(array[i][1]!=array[i+1][0])
		{
			return 1;
		}
	}
	return 0;
}
void formarMatrizMM()
{
	const gchar *nombreMatriz =     gtk_entry_get_text(GTK_ENTRY(gTexboxMM[0]));
	const gchar *NMatrices=     gtk_entry_get_text(GTK_ENTRY(gTexboxMM[1]));
	
	char ar_matriz[12];
	char ar_nMatrices[2];
	
	strcpy(ar_matriz,nombreMatriz);
	strcpy(ar_nMatrices,NMatrices);
	
	int n=atoi(ar_nMatrices)-1;
	
	float matrizM[n+1][n+1];	
	int matrizR[n+1][n+1];	
	char matrizC[n+1][n+1];	
	int array[n][2];
	
	for(int i=0;i<=n;i++)
	{					

		for(int j=0;j<2;j++)
		{
			const gchar  *valor = gtk_entry_get_text(GTK_ENTRY(matricesMM[i][j])); 
			if(strlen(valor)==0)
			{
				ShowMessage("Hay una llave sin definir, Favor llenarla o eliminar la linea","¡ERROR!");
				return;
			}
			else
			{
				array[i][j]=atoi(valor);
				
			}
		}
	}	
		
	if(validarFormatoMM(n,array))
	{
		ShowMessage("Las filas de una matriz no coinciden con las columnas de la otra","¡AVISO!");
		return;
	}		
	//inicializa matrizM y matrizR
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			matrizM[i][j]=0;
			matrizR[i][j]=0;
			matrizC[i][j]='N';
		}
	}
		 
   int par = n*(n+1)/2; // la sumatoria del numero
   int k=0; // contador de la cantidad de vueltas 
     
   int i=0; 
   int jj=1;
   int flag=0; 
   while(k!=par)
   {			
		for(int j=jj;j<=n;j++)
		{			
			float menor = 99999999;
			int res=0;
			for(int k=i;k<j;k++)
			{
				float valor= matrizM[i][k] + matrizM[k+1][j] + (array[i][0]*array[j][1]*array[k][1]);		
				//printf("matrizM[%d][%d] = %f  + matrizM[%d][%d]= %f + (%d * %d * %d) = %f\n",i,k,matrizM[i][k],k+1,j,matrizM[k+1][j],array[i][0],array[j][1],array[k][1],valor);
				if(valor<menor)
				{
					
					menor=valor;
					flag=1;
					res=k+1;
				}
			}			
			if(flag)
			{
				//printf("Menor %f\n",menor);
				matrizM[i][j]=menor;
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
	
	mostrarTablaMM(n,matrizM,matrizR,matrizC,array,ar_matriz);

}

void mostrarTablaMM (int n,float matrizM[n+1][n+1],int matrizR[n+1][n+1],char matrizC[n+1][n+1],int array[n][2],char matriz[])
{
	GtkWidget  * ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),matriz);		
	gtk_window_set_default_size(GTK_WINDOW(ventana),1366,768);
	gtk_widget_set_name(GTK_WIDGET(ventana),"winWhite");
			
	GtkWidget  * sw = gtk_scrolled_window_new(NULL, NULL);	
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_widget_set_size_request(sw,1000,700);
		
	/*Crea un modelo*/
	GtkWidget *modelo= gtk_fixed_new ();	
	/*Carga imagen a la ventana*/
	GtkWidget *image = gtk_image_new_from_file ("BD Multiplicacion Matrices/EncabezadoMM.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);	
	
		
	int x=60;
	int y=280;
	
	char *encabezado[2]={"Matriz","Multiplicación"};
			
	/*Emcabezado de objetos*/
	for(int i=0;i<2;i++)
	{
		char texto[16];
		sprintf(texto, "%s", encabezado[i]);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);	
		x+=90;
	}
	x=60;
	y=310;
	for(int j=0;j<=n;j++)
	{
		char texto[8];
		sprintf(texto, "M%d",j+1);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);
		y+=30;
	}	
	x=180;
	y=310;
	
	/*Mostrar tabla de objetos*/
	
	for(int i=0;i<=n;i++)
	{
		
		char texto[16];
		sprintf(texto, "(%dx%d)", array[i][0],array[i][1]);					
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);		
		y+=30;
	}
				
	char tituloOb[128];
	sprintf(tituloOb,"Multiplicación de matrices %s",matriz);
	GtkWidget *groupTextCargar =gtk_frame_new (tituloOb);	
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,50,240);
	gtk_widget_set_size_request( groupTextCargar , x+150 ,y-220);
	
	char texto[512];
	sprintf(texto, "La cantidad mínima de multiplicaciones es: %0.f",matrizM[0][n]);
	GtkWidget *labelmulti = gtk_label_new(texto);
	gtk_fixed_put(GTK_FIXED(modelo),labelmulti,580,260);	
		
	char texto1[512];
	sprintf(texto1, "El orden de la multiplicación es %s","...");
	GtkWidget *labelorden = gtk_label_new(texto1);
	gtk_fixed_put(GTK_FIXED(modelo),labelorden,580,290);	
		
	char titulores[128];
	sprintf(titulores,"Respuesta a la matriz %s",matriz);
	GtkWidget *groupTextRespuesta =gtk_frame_new (titulores);	
	gtk_fixed_put(GTK_FIXED(modelo),groupTextRespuesta,x+390,240);
	gtk_widget_set_size_request( groupTextRespuesta , 400 ,120);
	
		
	/*Colocando emcabezados de la tabla */	
	x=130;
	
	for(int j=1;j<=n+1;j++)
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
	
	for(int i=0;i<=n;i++)
	{									
		for (int j=0;j<=n;j++)
		{
			char texto[16];
			sprintf(texto, "%.0f", matrizM[i][j]);
			GtkWidget *label1 = gtk_label_new(texto);
			gtk_widget_set_size_request( label1 ,90,30);			
			if(matrizC[i][j]=='V')
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelGreen");
			}
			else if(matrizC[i][j]=='C')
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelLightBlue");
			}
					
			else
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelDark");
			}
			gtk_fixed_put(GTK_FIXED(modelo),label1,x+50,y+80);
			x+=100;;
		}		
		y+=40;
		x=40;
	}
	int posy=y;
	y-=(40*n+1);
	char tituloTab[128];
	sprintf(tituloTab,"Minimo de multiplicaciones de la matriz %s",matriz)	;
	GtkWidget *groupTextTabOptima =gtk_frame_new (tituloTab);
	gtk_fixed_put(GTK_FIXED(modelo),groupTextTabOptima,50,y-20);
	gtk_widget_set_size_request( groupTextTabOptima, 100*(n+1)+50 ,y-270);
		
	x=40;
	posy+=90;
	for(int i=0;i<=n;i++)
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
	sprintf(titulotabR,"Tabla R  de la matriz: %s",matriz)	;
	GtkWidget *groupTextTabR =gtk_frame_new (titulotabR);
	gtk_fixed_put(GTK_FIXED(modelo),groupTextTabR,50,posy);
	gtk_widget_set_size_request( groupTextTabR, 100*(n+1)+50 ,posy-560);
			
	
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



void cuerpoMM(GtkWidget *ventana)
{
	
	/*Crea un modelo*/
	GtkWidget *modelo= gtk_fixed_new ();	
	/*Carga imagen a la ventana*/
	GtkWidget *image = gtk_image_new_from_file ("BD Multiplicacion Matrices/EncabezadoMM.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);	
	
	/*Creando un Gruptext*/
	GtkWidget *groupTextMatrices =gtk_frame_new ("Matrices Registrados");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextMatrices,10,230);
	gtk_widget_set_size_request( groupTextMatrices ,215 ,380);
	
	GtkWidget *groupTextGeneral =gtk_frame_new ("Datos generales de la matriz");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextGeneral,300,230);
	gtk_widget_set_size_request( groupTextGeneral ,400 ,250);
	
	GtkWidget *groupTextNMatrices =gtk_frame_new ("Matrices a multiplicar");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextNMatrices,800,230);
	gtk_widget_set_size_request( groupTextNMatrices ,240 ,370);
	
	GtkWidget *groupTextCargar =gtk_frame_new ("Cargar Archivos");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,300,490);
	gtk_widget_set_size_request( groupTextCargar ,480 ,110);
	
	/*Inicializar tabla*/
	gTableMM = gtk_tree_view_new(); /* Crea la vista de la lista */
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(gTableMM),TRUE); /* Visualiza las cebeceras de la lista */
	gSignalMM = gtk_tree_view_get_selection(GTK_TREE_VIEW(gTableMM));


	/*Posicionar tabla*/
	gtk_fixed_put(GTK_FIXED(modelo),gTableMM,20,250);
	
	/*Etiquetas*/
	GtkWidget *gLabelMatriz,*gLabelnMatrices,*gLabelNomMatriz,*gLabelIzquierda,*gLabelMulti,*gLabeDerecha;
	GtkWidget *gLabelRuta;
	
	/*TextBox*/
	GtkWidget *gTextBoxMatriz,*gTextBoxnMatrice,*gTextBoxRuta;
	
	/*Buttons*/
	GtkWidget *gButtonAgregar,*gButtonEditar,*gButtonVolver,*gButtonCargar,*gButtonBusqueda,*gButtonLimpiar ,*gButtonResolver;
	
	/*Inicializar GtkWidget*/
	gLabelMatriz = gtk_label_new("Nombre de Multiplicación:");
	gLabelnMatrices = gtk_label_new("Numero de matrices:");
	
	gLabelNomMatriz = gtk_label_new("Matriz");
	gLabelIzquierda = gtk_label_new("N");
	gLabelMulti = gtk_label_new("x");
	gLabeDerecha = gtk_label_new("N");
	
	gLabelRuta=gtk_label_new("Ruta:");
	
	gTextBoxMatriz = gtk_entry_new();
	gTextBoxnMatrice = gtk_entry_new();
	
	gTextBoxRuta=gtk_entry_new();
	
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxMatriz),12);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxnMatrice),2);
		
	gtk_widget_set_size_request(gTextBoxRuta ,380,-1);

	gButtonAgregar = gtk_button_new_with_label("Agregar Matriz");
	gButtonEditar = gtk_button_new_with_label("Editar Matriz");
	gButtonVolver = gtk_button_new_with_label("Volver");
	gButtonCargar =gtk_button_new_with_label("Cargar");
	gButtonBusqueda=gtk_button_new_with_label("...");
	gButtonLimpiar=gtk_button_new_with_label("Limpiar");
	gButtonResolver=gtk_button_new_with_label("Resolver");
	
	/*Posicionar GtkWidget*/
	gtk_fixed_put(GTK_FIXED(modelo),gLabelMatriz,320,270);	
	gtk_fixed_put(GTK_FIXED(modelo),gLabelnMatrices,320,300);
		
	gtk_fixed_put(GTK_FIXED(modelo),gLabelNomMatriz,820,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelIzquierda,895,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelMulti,940,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabeDerecha,975,250);	
	
	gtk_fixed_put(GTK_FIXED(modelo),gLabelRuta,320,520);

	
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxMatriz,520,265);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxnMatrice,520,295);
		
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxRuta,360,515);

	
	gtk_fixed_put(GTK_FIXED(modelo),gButtonAgregar,320,400);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonEditar,450,400);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonResolver,400,430);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonLimpiar,620,400);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonVolver,630,440);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonCargar,680,555);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonBusqueda,750,515);
	


	gButtonMM[0]=gButtonAgregar;
	gButtonMM[1]=gButtonEditar;
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
			gtk_entry_set_width_chars(GTK_ENTRY(entry),2);
			gtk_entry_set_max_length(GTK_ENTRY(entry),2);

			if (j==0)//entrys de nombre
			{				
				g_signal_connect (G_OBJECT (entry), "focus-out-event",G_CALLBACK (validarNmatriz), NULL);
				matricesMM[i][j]=entry;
			}
			else if(j==1)//entrys de peso
			{		
				x-=20;		
				char num[2];
				sprintf(num,"M%d",(i+1));
				GtkWidget *gLabelLinea=gtk_label_new(num);
				gtk_fixed_put(GTK_FIXED(modelo),gLabelLinea,xl,y+5);				
				gtk_entry_set_width_chars(GTK_ENTRY(entry),2);
				gtk_entry_set_max_length(GTK_ENTRY(entry),2);
				g_signal_connect (G_OBJECT (entry), "focus-out-event",G_CALLBACK (validarNmatriz),NULL);
				matricesMM[i][j]=entry;
			}			
			gtk_widget_set_sensitive (entry, FALSE);					
			gtk_fixed_put(GTK_FIXED(modelo),entry,x,y);	
			x+=100;
		}
		x=885;
		y+=30;
	}
	
	/*Lista de textbox */
	gTexboxMM[0]=gTextBoxMatriz;
	gTexboxMM[1]=gTextBoxnMatrice;
	gTexboxMM[2]=gTextBoxRuta;
	/*Señales*/
	
	/*Señal para la seleccion*/
	g_signal_connect(gSignalMM,"changed",G_CALLBACK(SelectedChangedMM),NULL); 
	
	/*Señales para los Textbox*/
	g_signal_connect (G_OBJECT (gTextBoxnMatrice), "focus-out-event",G_CALLBACK (gTextBoxVisibleMM),NULL);
	g_signal_connect (G_OBJECT (gTextBoxMatriz), "focus-out-event",G_CALLBACK (validarMM),NULL);
	
	
	/*Señales para los botones*/
	g_signal_connect (G_OBJECT (gButtonAgregar), "clicked",G_CALLBACK (agregarMM),NULL);
	g_signal_connect (G_OBJECT (gButtonEditar), "clicked",G_CALLBACK (editarMM),NULL);
	g_signal_connect (G_OBJECT (gButtonResolver), "clicked",G_CALLBACK (formarMatrizMM),NULL);
	g_signal_connect (G_OBJECT (gButtonBusqueda), "clicked",G_CALLBACK (mostrarChooseFileMM),ventana);
	g_signal_connect (G_OBJECT (gButtonCargar), "clicked",G_CALLBACK (mostrarArchivoCargadoMM),ventana);
	g_signal_connect (G_OBJECT (gButtonLimpiar), "clicked",G_CALLBACK (limpiarCamposMM),ventana);
	g_signal_connect(G_OBJECT(gButtonVolver),"clicked",G_CALLBACK(cerrarVentana),ventana); 

	
	/*Set modelo en la ventana*/
	gtk_container_add(GTK_CONTAINER(ventana),modelo);
	
	/*Mostrar Todo*/
	gtk_widget_show_all(ventana);		

}

int winMultiplicacionMatrices()
{
	/*Crear ventana con sus propiedades*/
	GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Árboles Binarios de Búsqueda Óptimos");		
	gtk_window_set_default_size(GTK_WINDOW(ventana),1366,768);
	gtk_widget_set_name(GTK_WIDGET(ventana),"winWhite");
		
	/*Llama al cuerpo de la ventana*/
	cuerpoMM(ventana);
	iniciarTablaMM();
	llenarTablaMM();
	 /* Muestra la ventana principal con todo su contenido */
	gtk_widget_show_all(ventana);		
	 /* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	/* Termina la aplicación */
	gtk_main(); 
	
	return 1;
}

