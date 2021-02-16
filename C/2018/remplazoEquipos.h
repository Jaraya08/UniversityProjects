/* Curso :     Investigación de Operaciones
 * Estudiante: Jordan H. Araya Leiva
 * Carné:      2016254282
 * 
 * 
 * Proyecto Programado #3 : Remplazo de equipos
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

enum {LIST_EQUIPO=0,LIST_COSTO,LIST_PLAZO,LIST_VIDA,LIST_INFLACION,N_COLUMNSEQ};



/* Lista de Datos*/
GtkWidget *gTableEquipos;

 /* Puntero a la fila seleccionada */
GtkTreeSelection *gSignalTableEquipos;

/*Arreglo de GtkWidget*/
GtkWidget *gTexBoxsCostosAnuales[10][2];
GtkWidget *gTexBoxsDatosEquipo[6];
GtkWidget *gButtonsRemplazoEquipos[2];

/*E: NINGUNA.
 *S: INICIALIZA UNA TABLA PARA PODER LLENARSE CON LOS EQUIPOS.
 *R: NINGUNA.
 * */
void iniciarTablaEquipos() /* Función que inicializa la lista de datos */
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkListStore *store;	

	 /* Establece la columna y la agrega*/
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Equipo",renderer,"text",LIST_EQUIPO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableEquipos),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Costo",renderer,"text",LIST_COSTO,NULL);	
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableEquipos),column);	 
		
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Plazo",renderer,"text",LIST_PLAZO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableEquipos),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Vida útil",renderer,"text",LIST_VIDA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableEquipos),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Inflación",renderer,"text",LIST_INFLACION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableEquipos),column);
	
	store = gtk_list_store_new(N_COLUMNSEQ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW(gTableEquipos),GTK_TREE_MODEL(store));
	
	g_object_unref(store);

}

//llena la tabla con los datos que haya en el archivo de texto Equipos Registrados.txt
void llenarTablaEquipos()
{		
	FILE *equipo;
	
	GtkListStore *store;
	GtkTreeIter iter;
	
	char linea[256];		
	equipo =fopen("Remplazo Equipos BD/Equipos Registrados.txt","r");	
	
	/* Obtiene el modelo de datos */
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableEquipos))); 
	
	int count=0;
	while (fgets(linea,256,equipo) != NULL)
	{	
		strtok(linea,"\n");
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "Equipo" */
		char equipo[12];
		strcpy(equipo,token);
		
		token = strsep(&running, delimiters);    /* token => "Costo" */
		char costo[8]; // maximo 99.999.999
		strcpy(costo,token);
		
		token = strsep(&running, delimiters);    /* token => "Plazo" */
		char plazo[2]; // maximo 30
		strcpy(plazo,token);
		
		token = strsep(&running, delimiters); 	/* token => "Vida útil" */
		char vidaUtil[2]; // maximo 10 años
		strcpy(vidaUtil,token);				
		
		token = strsep(&running, delimiters); 	/* token => "inflación" */
		char inflacion[3]; // maximo 100%
		strcpy(inflacion,token);				
				
		
		/* Añade una fila vacia */
		gtk_list_store_append(store, &iter);
		
		/* Cambia los valores de la fila */			
		gtk_list_store_set(store,&iter,LIST_EQUIPO,equipo,-1);
		gtk_list_store_set(store,&iter,LIST_COSTO,costo,-1);
		gtk_list_store_set(store,&iter,LIST_PLAZO,plazo,-1);		
		gtk_list_store_set(store,&iter,LIST_VIDA,vidaUtil,-1);
		gtk_list_store_set(store,&iter,LIST_INFLACION,inflacion,-1);
		
	}
	fclose(equipo);	
}

/*E: NINGUNA
 *S: LIMPIA TODA LA TABLA gTableEquipos
 *R: NINGUNA.
 * */
void limpiarTablaEquipos()
{	
	GtkListStore *store;
	GtkTreeModel *model;
	GtkTreeIter  iter;		
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableEquipos)));
	model = gtk_tree_view_get_model(GTK_TREE_VIEW(gTableEquipos));
	if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) 
	{
		return;
	}
	/* Limpia toda la lista */	
	gtk_list_store_clear(store); 
}


//limpia todos los campos de la pantalla
void limpiarCamposEquipos()
{
	gtk_widget_set_sensitive (gButtonsRemplazoEquipos[0],TRUE); // boton de agregar equipo Enadable TRUE
	gtk_widget_set_sensitive (gButtonsRemplazoEquipos[1],FALSE); // boton de Editar enable FALSE
	gtk_widget_set_sensitive (gTexBoxsDatosEquipo[0],TRUE); // campo nombre Equipo Enable TRUE	
	
	for(int i=0;i<10;i++)
	{
		if(i<5)
		{
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[i]),"");
		}
		for (int j=0;j<2;j++)
		{
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][j]),"");
			gtk_widget_set_sensitive (gTexBoxsCostosAnuales[i][j],FALSE);					

		}
	}
}

//Abre el buscador de archivo para cargar un archivo al programa
int ChooseFileEquipos(GtkWidget * button,gpointer ventana)
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
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[5]),filename);		
	}
	gtk_widget_destroy (dialog);
}

// activa la cantidad campos segun el numero ingresdo en el campo vida util del equipo
int gTextBoxVisibleEquipos(GtkWidget *entry,gpointer puntero)
{
		
	const gchar * annos = gtk_entry_get_text(GTK_ENTRY(entry));
	char cant[2];
	strcpy(cant,annos);
	int fin = IS_NUM(cant);
	strtok(cant,"\n");
	if(!strlen(cant))
	{
		ShowMessage("El campo Vida útil del equipo no puede ser vacío","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	if(!fin)
	{
		ShowMessage("El campo Vida Útil del Equipo solo acepta numeros enteros positivos","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;	
	}
	else if(atoi(cant)>10)
	{
		ShowMessage("La vida util del equipo no puede ser mayor a 10","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<2;j++)
			{	
				gtk_widget_set_sensitive (gTexBoxsCostosAnuales[i][j],TRUE);					
				if(i>=atoi(cant))
				{
					gtk_entry_set_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][j]),"");
					gtk_widget_set_sensitive (gTexBoxsCostosAnuales[i][j],FALSE);					
				}		
			}
		}
		return 0;
	}
}

//verifica la existencia de un equipo en la base de datos de equipo
int existeEquipo(char equipo[])
{
	FILE *p_equipo;
	char linea[256];	
	p_equipo =fopen("Remplazo Equipos BD/Equipos Registrados.txt","r");		
	
	while (fgets(linea,256,p_equipo) != NULL)
	{	
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => Equipo */
		char nombre[12];
		strcpy(nombre,token);
		if(!strcmp(equipo,nombre))
		{
			return 1;
		}
	}
	fclose(p_equipo);
	return 0;
}

//agrega un nuevo equipo al archivo de texto Equipos Registrados.txt
void agregarTxtEquipo(char datos[])
{
	/*Agregar en archivo*/
	FILE *equipo;
	equipo =fopen("Remplazo Equipos BD/Equipos Registrados.txt","a");
	strtok(datos,"\n");
	fprintf(equipo,"%s\n",datos);	
	fclose(equipo);
}


//agrega un nuevo equipo con todas su variables 
void agregarEquipo(GtkWidget *button,gpointer data)
{
	const gchar *nombreEquipo=   gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[0]));
	const gchar *costoEquipo=     gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[1]));
	const gchar *plazoEquipo=  gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[2]));
	const gchar *vidaUtilEquipo = gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[3]));
	const gchar *infalcionEquipo = gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[4]));
		
	char ar_equipo[12];			
	strcpy(ar_equipo,nombreEquipo);
	if(!(strlen(ar_equipo))>0)
	{
		ShowMessage("El campo del Nombre del equipo no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(gTexBoxsDatosEquipo[0]);
		return;
	}	
	if(existeEquipo(ar_equipo))	
	{
		ShowMessage("Nombre del equipo ya existe, intente con otro.","¡AVISO!");
		gtk_widget_grab_focus(gTexBoxsDatosEquipo[0]);
		return;
	}
	char ar_nombre[12];
	char ar_costo[8];
	char ar_plazo[2];
	char ar_vida[2];
	char ar_inflacion[3];
	
	strcpy(ar_nombre,nombreEquipo);

	strcpy(ar_costo,costoEquipo);

	strcpy(ar_plazo,plazoEquipo);

	strcpy(ar_vida,vidaUtilEquipo);
	
	strcpy(ar_inflacion,infalcionEquipo);

	char new_equipo[128];
	
	//nombre,costo,plazo,vida util,inflacion
	sprintf(new_equipo,"%s,%s,%s,%s,%s",ar_nombre,ar_costo,ar_plazo,ar_vida,ar_inflacion);

	agregarTxtEquipo(new_equipo);
	
	/*Crear equipo*/
	FILE *equipo;
	char archivo[64];
	sprintf(archivo,"Remplazo Equipos BD/%s.txt",ar_nombre);
	equipo =fopen(archivo,"w");
	
	char datosCompleto[1024]="";
	
	for (int i=0;i<atoi(ar_vida);i++)
	{				
		const gchar *mant  = gtk_entry_get_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][0]));
		const gchar *reventa  = gtk_entry_get_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][1]));			
		
		char ar_mantenimiento[12];	
		char ar_reventa[12];		
		
		strcpy(ar_mantenimiento,mant);
		strcpy(ar_reventa,reventa);		
		char datos[512];
		sprintf(datos,"%s,%s\n",ar_mantenimiento,ar_reventa);
		strcat(datosCompleto,datos);		
	}
	fprintf(equipo,"%s",datosCompleto);
	fclose(equipo);	
	limpiarCamposEquipos();
	limpiarTablaEquipos();
	llenarTablaEquipos();
	char message[1024];
	sprintf(message,"Se agregó un/una %s, con Costo de: %s , Plazo de:  %s años, Vida util de: %s años inflación de %s",ar_nombre,ar_costo,ar_plazo,ar_vida,ar_inflacion);
	ShowMessage(message,"¡INFORMACIÓN!");	
}


//edita todos los campos de un equipo seleccionado 
void editarEquipo(GtkWidget *button,gpointer data)
{
	const gchar *nombreEquipo =     gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[0]));
	const gchar *costoEquipo=     gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[1]));
	const gchar *plazoEquipo=  gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[2]));
	const gchar *vidaUtilEquipo = gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[3]));
	const gchar *inflacionEquipo = gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[4]));
	
	char ar_nombre[12];
	char ar_costo[8];
	char ar_plazo[2];
	char ar_vida[2];	
	char ar_inflacion[3];	
	char linea[64];
	
	strcpy(ar_nombre,nombreEquipo);
	strcpy(ar_costo,costoEquipo);
	strcpy(ar_plazo,plazoEquipo);
	strcpy(ar_vida,vidaUtilEquipo);
	strcpy(ar_inflacion,inflacionEquipo);
	
	FILE *equipo,*temp;	
	equipo =fopen("Remplazo Equipos BD/Equipos Registrados.txt","r");
	temp =fopen("Remplazo Equipos BD/temp2.txt","w");			
	while (fgets(linea,128,equipo) != NULL)
	{		
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "equipo" */
		char equipos[12];
		strcpy(equipos,token);
		
		if(!strcmp(ar_nombre,equipos)){}
		else
		{
			fprintf(temp,"%s\n",linea);			
		}
	}			
	char new_equipo[64];
	sprintf(new_equipo,"%s,%s,%s,%s,%s",ar_nombre,ar_costo,ar_plazo,ar_vida,ar_inflacion);
	fprintf(temp,"%s\n",new_equipo);			
	fclose(temp);
	fclose(equipo);
	remove("Remplazo Equipos BD/Equipos Registrados.txt");
	rename("Remplazo Equipos BD/temp2.txt","Remplazo Equipos BD/Equipos Registrados.txt");
	remove("Remplazo Equipos BD/temp2.txt");	
	
	/*Modificar Objetos*/	
	FILE *equipos;
	char archivo[64];
	sprintf(archivo,"Remplazo Equipos BD/%s.txt",ar_nombre);
	equipos =fopen(archivo,"w");
	
	char datosCompleto[1024]="";
	
	for (int i=0;i<atoi(ar_vida);i++)
	{				
		const gchar *mantenimiento  = gtk_entry_get_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][0]));
		const gchar *reventa  = gtk_entry_get_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][1]));			
		
		char ar_matenimiento[8];	
		char ar_reventa[8];		
		
		strcpy(ar_matenimiento,mantenimiento);
		strcpy(ar_reventa,reventa);
					
		char datos[512];
		sprintf(datos,"%s,%s\n",ar_matenimiento,ar_reventa);
		strcat(datosCompleto,datos);	
	}
	fprintf(equipos,"%s",datosCompleto);
	fclose(equipos);	
	limpiarTablaEquipos();
	llenarTablaEquipos();
	limpiarCamposEquipos();
	ShowMessage("Los datos del Equipo fueron modificados correctamente","¡AVISO!");
}


//carga los datos de un archivo txt a la pantalla 
void cargarDatosEquipos(char archivo[])
{

		FILE *AnoosEquipos;
		AnoosEquipos =fopen(archivo,"r");			
		int i=0;char linea[256];	
		while (fgets(linea,256,AnoosEquipos) != NULL)
		{	
			strtok(linea,"\n");
			const char delimiters[] = ",";
			char * running = strdup(linea);
			char * token;
		
			token = strsep(&running, delimiters);    /* token => "mantenimiento" */
			char mantenimiento[12];
			strcpy(mantenimiento,token);
			
			token = strsep(&running, delimiters);    /* token => "Reventa" */
			char reventa[12];
			strcpy(reventa,token);
															
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][0]),mantenimiento);
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][1]),reventa);			
			
			gtk_widget_set_sensitive (gTexBoxsCostosAnuales[i][0],TRUE);					
			gtk_widget_set_sensitive (gTexBoxsCostosAnuales[i][1],TRUE);

			i+=1;
		}

		for(int j=i;j<10;j++)
		{
			for(int k=0;k<2;k++)
			{
				gtk_widget_set_sensitive (gTexBoxsCostosAnuales[j][k],FALSE);
				gtk_entry_set_text(GTK_ENTRY(gTexBoxsCostosAnuales[j][k]),"");					
			}
		}		
		sprintf(linea,"%d",i);
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[3]),linea);
}

//muestras el archivo cargado en pantalla
void mostrarArchivoCargadoEquipo(GtkWidget * button,gpointer ventana)
{
	limpiarCamposEquipos();
	gtk_widget_set_sensitive (gButtonsRemplazoEquipos[1],FALSE);
	gtk_widget_set_sensitive (gButtonsRemplazoEquipos[0],TRUE);
	FILE *equipo,*temp;
	const gchar *archivo = gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[5]));
	char ar_file[512],linea[128];	
	strcpy(ar_file,archivo);
	if(!strlen(ar_file)>0)
	{
		ShowMessage("No se ha selecionado ninguna ruta","¡AVISO!");
		return;
	}
	equipo = fopen(ar_file,"r");
	temp = fopen("temp.txt","w");			
	int i=0;
	while (fgets(linea,64,equipo) != NULL)
	{
		strtok(linea,"\n");
		if(i==0)
		{
			const char delimiters[] = ",";
			char * running = strdup(linea);
			char * token;
		
			token = strsep(&running, delimiters);    /* token => "Equipo" */
			char equipo[12];
			strcpy(equipo,token);
			
			token = strsep(&running, delimiters);    /* token => "Costo" */
			char costo[12];
			strcpy(costo,token);
			
			token = strsep(&running, delimiters);    /* token => "Plazo" */
			char plazo[3];
			strcpy(plazo,token);
			
			token = strsep(&running, delimiters);    /* token => "Vida util" */
			char vidaUtil[3];
			strcpy(vidaUtil,token);
			
			token = strsep(&running, delimiters);    /* token => "Inflacion" */
			char inflacion[3];
			strcpy(inflacion,token);
			
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[0]),equipo);
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[1]),costo);
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[2]),plazo);			
			gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[4]),inflacion);
		}
		else
		{			
			fprintf(temp,"%s\n",linea);			
		}
		i+=1;	
	}
	fclose(temp);
	cargarDatosEquipos("temp.txt");
	remove("temp.txt");
	gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[5]),"");
}

//llena los campos con la informacion de un equipo selecionado en la tabla 
void SelectedChangedEquipo(GtkWidget *gTable,gpointer dato) 
{
	GtkTreeIter iter;
	GtkTreeModel *model;
	gchar *value;	
	char archivo[64]="";	
	char path[64]="";
	
	gtk_widget_grab_focus(gTexBoxsDatosEquipo[5]);
	
	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(gTable),&model,&iter)) 
	{	
		gtk_widget_set_sensitive (gButtonsRemplazoEquipos[0],FALSE);
		gtk_widget_set_sensitive (gButtonsRemplazoEquipos[1],TRUE);
		gtk_widget_set_sensitive (gTexBoxsDatosEquipo[0],FALSE);

		/* Obtiene el Valor  */
		gtk_tree_model_get(model,&iter,LIST_EQUIPO,&value,-1); 		
		/* Deposita el valor en el entry*/				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[0]),value);//Nombre
		
		gtk_tree_model_get(model,&iter,LIST_COSTO,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[1]),value);//Costo
		
		gtk_tree_model_get(model,&iter,LIST_PLAZO,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[2]),value);//Plazo
		
		gtk_tree_model_get(model,&iter,LIST_INFLACION,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexBoxsDatosEquipo[4]),value);//Inflacion
		
		const gchar	*NomEquipo = gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[0]));
	
		g_free(value);
		
		strcat(path,"Remplazo Equipos BD/");
		strcpy(archivo,NomEquipo);	
		strcat(archivo,".txt");
		strcat(path,archivo);
		cargarDatosEquipos(path);
	}
}

//Saca los costos anuales de cada gt
void costosAnuales(int anno,int costo, int costosAnuales[anno][2],int res[],struct st_costosAnuales tiempos[])
{
	int mant=costosAnuales[0][0];
	
	char tiempo[512];
	for(int i=0;i<anno;i++)
	{		
		struct st_costosAnuales costos;
		sprintf(tiempo,"costo a %d años =  %d + %d - %d = %d\n",i+1,costo,mant,costosAnuales[i][1],((costo+mant)-costosAnuales[i][1]));
		strcpy(costos.costo,tiempo);
		res[i]=((costo+mant)-costosAnuales[i][1]);
		mant+=costosAnuales[i+1][0];
		tiempos[i]=costos;
	}		
}

//Recursividad que saca los datos
int remplazo(int costosAnuales[],int count,int plazo,int i)
{		
	if(count==plazo)
	{
		return 0;
	}	
	else
	{
		return remplazo(costosAnuales,count+1,plazo,i+1)+costosAnuales[i];
	}
	
}

//forma la lista que se presenta en la interfaz de resultado 
void remplazoEquipos(int vidaUtil,int costosAnuales[],int plazo,struct st_GT arrayFinal[]) // Sacando los G(tx) Menores.
{	
	int Gtx=1;// variable para llevar los gtx que debe hacer 	
	int cant=1; // la cantidad de posiciones que se va sumando al arreglo final	
	struct st_GT GTS0;	
	char GT0[8];
	sprintf(GT0,"G(%d)",plazo);	
	strcpy(GTS0.GT,GT0);
	GTS0.valor=0;		
	arrayFinal[0]=GTS0;											
										
	for(int i=(plazo-1);i!=-1;i--)
	{
		char GT[8];
		char Gs[8];		
		char ar_menor[8];
				
		struct st_GT GTS;
		
		if(Gtx>vidaUtil)
		{
			Gtx=vidaUtil;			
		}								
		int menor=9999999;
					
		for(int j=1;j<=Gtx;j++)
		{			
								
			int resGtx= remplazo(costosAnuales,(i+j),plazo,0)+costosAnuales[j-1];			
			if(resGtx<menor)
			{				
				menor=resGtx;
				sprintf(Gs,"%d",i+j);//el gtx Menor de todos.				
			}	
	
		}		
		sprintf(GT,"G(%d)",i);						
		sprintf(ar_menor,"%d",menor);		
				
		strcpy(GTS.GT,GT);
		GTS.valor=menor;
			
		int menores=0	;				
		for(int j=1;j<=Gtx;j++)
		{								
			int resGtx= remplazo(costosAnuales,(i+j),plazo,0);					
			char GsTemp[8];			
			sprintf(GsTemp,"%d",i+j);//el gtx Menor de todos.								
			if(resGtx==menor & !!(strcmp(Gs,GsTemp)))
			{								
				GTS.menores[j-1]=i+j;				
				menores+=1;		
			}									
		}
		GTS.cantMenores=menores;	
		arrayFinal[cant]=GTS;											
		Gtx+=1;
		cant+=1;				
	}
}


//muestas los tiempos en pantalla junto con todos los datos del equipo
void mostarTiemposEquipo(int costo,struct st_GT GTS[],int vidaUtil, int plazo,int tiempos[],char nombreEquipo[64],int matrizMantRevent[vidaUtil][2],struct st_costosAnuales tiemposChar[])
{
	/*Crear ventana con sus propiedades*/	
	GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Tiempos de remplazo óptimos");		
	gtk_window_set_default_size(GTK_WINDOW(ventana),1366,768);
	gtk_widget_set_name(GTK_WIDGET(ventana),"winWhite");
	
	/*GdkRGBA color;
	gboolean res = gdk_rgba_parse (&color, "#ffffff");
	gtk_widget_override_background_color (ventana,GTK_STATE_FLAG_NORMAL,&color);*/
	
	/*Crea un modelo*/
	GtkWidget *modelo= gtk_fixed_new ();	
	/*Carga imagen a la ventana*/
	GtkWidget *image = gtk_image_new_from_file ("Remplazo Equipos BD/EncabezadoEquiposTiempo.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);	
	
	GtkWidget  * sw = gtk_scrolled_window_new(NULL, NULL);	
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_widget_set_size_request(sw,1000,700);
	
	int x=20;
	int y=270;
	
	char texto[16];	
	GtkWidget *labelNombreEqui = gtk_label_new("Nombre equipo:");
	gtk_fixed_put(GTK_FIXED(modelo),labelNombreEqui,x,y);					
	GtkWidget *labelNombre = gtk_label_new(nombreEquipo);
	gtk_fixed_put(GTK_FIXED(modelo),labelNombre,x+130,y);			
	
	GtkWidget *labelCostoEqui = gtk_label_new("Costo Equipo:");
	gtk_fixed_put(GTK_FIXED(modelo),labelCostoEqui,x,y+30);		
	sprintf(texto,"%d",costo);
	GtkWidget *labelCosto = gtk_label_new(texto);
	gtk_fixed_put(GTK_FIXED(modelo),labelCosto,x+130,y+30);
				
	GtkWidget *labelPlazoEqui = gtk_label_new("Plazo Equipo:");
	gtk_fixed_put(GTK_FIXED(modelo),labelPlazoEqui,x,y+60);
	sprintf(texto,"%d",plazo);
	GtkWidget *labelPlazo = gtk_label_new(texto);
	gtk_fixed_put(GTK_FIXED(modelo),labelPlazo,x+130,y+60);
		
		
	GtkWidget *labelVidaEqui = gtk_label_new("Vida Útil:");
	gtk_fixed_put(GTK_FIXED(modelo),labelVidaEqui,x,y+90);
	sprintf(texto,"%d",vidaUtil);
	GtkWidget *labelVidaUtil = gtk_label_new(texto);
	gtk_fixed_put(GTK_FIXED(modelo),labelVidaUtil,x+130,y+90);	
	
	char *arrayTitulo[3]={"Años","Mantenimiento","Reventa"};
	
	for(int j=0;j<3;j++)
	{
		GtkWidget *labelTitulo = gtk_label_new(arrayTitulo[j]);
		gtk_fixed_put(GTK_FIXED(modelo),labelTitulo,x,y+130);
		x+=120;
	}
	y+=160;	
	x=20;
	for(int i=0;i<vidaUtil;i++)
	{	
		sprintf(texto,"%d",i+1);
		GtkWidget *labelannos = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),labelannos,x,y);
		x+=130;	
		for(int j=0;j<2;j++)
		{		
			sprintf(texto,"%d",matrizMantRevent[i][j]);
			GtkWidget *labelMan = gtk_label_new(texto);
			gtk_fixed_put(GTK_FIXED(modelo),labelMan,x,y);									
			x+=130;
		}
		x=20;
		y+=30;

	}	
	/*Creando un Gruptext*/
	GtkWidget *groupTextEquiposResg =gtk_frame_new ("Datos del Equipo");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextEquiposResg,10,230);
	gtk_widget_set_size_request( groupTextEquiposResg ,360 ,y-230);
	
	x=400;
	y=270;
	
	for(int i=0;i<vidaUtil;i++)
	{		
		GtkWidget *labelMan = gtk_label_new(tiemposChar[i].costo);
		gtk_fixed_put(GTK_FIXED(modelo),labelMan,x+10,y);									
		y+=30;
	}		
	int Gtx=1;// variable para llevar los gtx que debe hacer 							
	int cant=1;
	char text[512];
	x=400;
	
	sprintf(text,"%s menor = %d ",GTS[0].GT,GTS[0].valor);
	GtkWidget *labelGT = gtk_label_new(text);
	gtk_fixed_put(GTK_FIXED(modelo),labelGT,x+5,y+30);									
	y+=30;
	
	for(int i=(plazo-1);i!=-1;i--)
	{				
		sprintf(text,"%s menor = %d ",GTS[cant].GT,GTS[cant].valor);
		GtkWidget *labelGT = gtk_label_new(text);
		gtk_fixed_put(GTK_FIXED(modelo),labelGT,x+30,y+30);									
		y+=30;
		
		if(Gtx>vidaUtil)
		{
			Gtx=vidaUtil;			
		}														
		for(int j=1;j<=Gtx;j++)
		{			
			char labelsTiempos[1024];
			char gtxs[8];
			sprintf(gtxs,"G(%d)",i+j);
			for(int k=0;k<plazo+1;k++)
			{
				if(!strcmp(GTS[k].GT,gtxs))
				{
					sprintf(labelsTiempos,"G %d %d + %s %d = %d",i,i+j,gtxs,GTS[k].valor,(GTS[k].valor+tiempos[j-1]));
					GtkWidget *labelGtx = gtk_label_new(labelsTiempos);
					gtk_fixed_put(GTK_FIXED(modelo),labelGtx,x+50,y+30);									
					y+=30;
					break;
				}
			}						
		}																					
		Gtx+=1;	
		cant+=1;	
	}	
		
	GtkWidget *groupTextEquiposGastos =gtk_frame_new ("Ecuaciones de Gastos Anuales");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextEquiposGastos,400,230);
	gtk_widget_set_size_request( groupTextEquiposGastos ,400 ,y-210);
	
	
	gtk_container_add(GTK_CONTAINER(sw),modelo);
	gtk_container_add(GTK_CONTAINER(ventana),sw);	
	
	gtk_widget_show_all(ventana);		
	 /* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	/* Termina la aplicación */
	gtk_main(); 
	
}


// forma las matrices previas a la respuesta 
void mostrarResultado()
{
	const gchar * nombreEquipo =gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[0]));
	const gchar * costoEquipo =gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[1]));
	const gchar * plazoEquipo =gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[2]));
	const gchar * vidaUtilEquipo =gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[3]));
	const gchar * inflacionEquipo =gtk_entry_get_text(GTK_ENTRY(gTexBoxsDatosEquipo[4]));
	
	char nombre[12];
	char costo[8];
	char plazo[2];
	char vida[2];
	char inflacion[3];
	
	strcpy(nombre,nombreEquipo);
	strcpy(costo,costoEquipo);
	strcpy(plazo,plazoEquipo);
	strcpy(vida,vidaUtilEquipo);
	strcpy(inflacion,inflacionEquipo);
	
	int i_plazo=atoi(plazo);
	int i_vidautil=atoi(vida);
	int i_costo =atoi(costo);
	int res[i_vidautil];

	int matrizMantRevent[i_vidautil][2];
	for(int i=0;i<i_vidautil;i++)
	{
		const gchar * p_mantenimiento = gtk_entry_get_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][0]));
		const gchar * p_reventa = gtk_entry_get_text(GTK_ENTRY(gTexBoxsCostosAnuales[i][1]));
		
		if(strlen(p_mantenimiento)==0 	| strlen(p_reventa)==0 )
			{
				ShowMessage("Hay datos incompletos, Favor llenarlo o eliminar la linea","¡ERROR!");
				return;
			}
		
		matrizMantRevent[i][0]=atoi(p_mantenimiento);
		matrizMantRevent[i][1]=atoi(p_reventa);				
	}
	struct st_costosAnuales tiemposChar[i_vidautil];
	
	costosAnuales(i_vidautil,i_costo,matrizMantRevent,res,tiemposChar);			
	struct st_GT arrayFinal[i_plazo+1];
	remplazoEquipos(i_vidautil,res,i_plazo,arrayFinal);
	mostarTiemposEquipo(i_costo,arrayFinal,i_vidautil,i_plazo,res,nombre,matrizMantRevent,tiemposChar);
}

//valida que el campo de texto solo tenga numeros enteros positivos 
int validarCampoEquipoNum(GtkWidget *entry,gpointer puntero)
{
	const gchar *valor = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_valor[8];
	strcpy(ar_valor,valor);
	int val = IS_NUM(ar_valor);
	strtok(ar_valor,"\n");
	if(!strlen(ar_valor)>0)
	{
		ShowMessage("Este campo no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(!val)
	{
		ShowMessage("Este campo solo acepta numeros enteros positivos","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	return 0;
}

//valida que los datos del nombre del equipo esten correctos 
int validarEquipo(GtkWidget *entry,gpointer puntero)
{
	const gchar *equipo = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_equipo[12];
	
	strcpy(ar_equipo,equipo);
	
	strtok(ar_equipo,"\n");
	
	if(!strlen(ar_equipo)>0)
	{
		ShowMessage("El Campo Nombre Equipo no puede ser vacio","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}	
	else if(IS_NUM(ar_equipo))
	{
		ShowMessage("El Campo Nombre Equipo debe tener al menos un caracter","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}
	else if(existeEquipo(ar_equipo))
	{
		ShowMessage("Nombre del Equipo ya existe, favor intente con otro nombre","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}	
}

void cuerpoRemplazoEquipos(GtkWidget *ventana)
{
	
	/*Crea un modelo*/
	GtkWidget *modelo= gtk_fixed_new ();	
	/*Carga imagen a la ventana*/
	GtkWidget *image = gtk_image_new_from_file ("Remplazo Equipos BD/EncabezadoEquipos.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);	
	
	/*Creando un Gruptext*/
	GtkWidget *groupTextEquiposResg =gtk_frame_new ("Equipos Registrados");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextEquiposResg,10,230);
	gtk_widget_set_size_request( groupTextEquiposResg ,360 ,500);
	
	GtkWidget *groupTextGeneral =gtk_frame_new ("Datos generales del Equipo");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextGeneral,400,230);
	gtk_widget_set_size_request( groupTextGeneral ,400 ,280);
	
	GtkWidget *groupTextPlazos =gtk_frame_new ("Datos de ---");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextPlazos,900,230);
	gtk_widget_set_size_request( groupTextPlazos ,320 ,400);
	
	GtkWidget *groupTextCargar =gtk_frame_new ("Cargar Archivos");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,400,520);
	gtk_widget_set_size_request( groupTextCargar ,480 ,110);
	
	/*Inicializar tabla*/

	gTableEquipos = gtk_tree_view_new(); /* Crea la vista de la lista */
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(gTableEquipos),TRUE); /* Visualiza las cebeceras de la lista */
	gSignalTableEquipos = gtk_tree_view_get_selection(GTK_TREE_VIEW(gTableEquipos));

	/*Posicionar tabla*/
	gtk_fixed_put(GTK_FIXED(modelo),gTableEquipos,20,250);
	
	/*Etiquetas*/
	GtkWidget *gLabelEquipo,*gLabelCosto,*gLabelPlazo,*gLabelVidaUtil,*gLabelInflacion,*gLabelAnnos,*gLabelMatenimiento,*gLabelReventa;
	GtkWidget *gLabelRuta;
	
	/*TextBox*/
	GtkWidget *gTextBoxEquipo,*gTextBoxCosto,*gTextBoxPlazo,*gTextBoxVidaUtil,*gTextBoxInflacion,*gTextBoxRuta;
	
	/*Buttons*/
	GtkWidget *gButtonAgregar,*gButtonEditar,*gButtonVolver,*gButtonCargar,*gButtonBusqueda,*gButtonLimpiar ,*gButtonResolver;
	
	/*Inicializar GtkWidget*/
	gLabelEquipo = gtk_label_new("Nombre Equipo:");
	gLabelCosto = gtk_label_new("Costo del Equipo:");
	gLabelPlazo = gtk_label_new("Plazos del Equipo:");
	gLabelVidaUtil = gtk_label_new("Vida útil del Equipo:");
	gLabelInflacion = gtk_label_new("Inflacion anual del Equipo:");
	
	gLabelAnnos = gtk_label_new("Años");
	gLabelMatenimiento = gtk_label_new("Mantenimiento");
	gLabelReventa = gtk_label_new("Reventa");
	
	gLabelRuta=gtk_label_new("Ruta:");
	
	gTextBoxEquipo = gtk_entry_new();
	gTextBoxCosto = gtk_entry_new();
	gTextBoxPlazo = gtk_entry_new();
	gTextBoxVidaUtil =gtk_entry_new();
	gTextBoxInflacion=gtk_entry_new();
	gTextBoxRuta =gtk_entry_new();
	
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxEquipo),12);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxCosto),8);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxPlazo),2);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxVidaUtil),2);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxInflacion),3);
	
	gtk_widget_set_size_request(gTextBoxRuta ,380,-1);
	
	gButtonAgregar = gtk_button_new_with_label("Agregar Equipo");
	gButtonEditar = gtk_button_new_with_label("Editar Equipo");
	gButtonVolver = gtk_button_new_with_label("Volver");
	gButtonCargar =gtk_button_new_with_label("Cargar");
	gButtonBusqueda=gtk_button_new_with_label("...");
	gButtonLimpiar=gtk_button_new_with_label("Limpiar");
	gButtonResolver=gtk_button_new_with_label("Resolver");
	
	/*Posicionar GtkWidget*/
	gtk_fixed_put(GTK_FIXED(modelo),gLabelEquipo,420,270);	
	gtk_fixed_put(GTK_FIXED(modelo),gLabelCosto,420,300);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelPlazo,420,330);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelVidaUtil,420,360);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelInflacion,420,390);

	
	gtk_fixed_put(GTK_FIXED(modelo),gLabelAnnos,920,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelMatenimiento,980,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelReventa,1110,250);
		
	gtk_fixed_put(GTK_FIXED(modelo),gLabelRuta,420,550);

	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxEquipo,620,265);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxCosto,620,295);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxPlazo,620,325);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxVidaUtil,620,355);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxInflacion,620,385);
	
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxRuta,460,545);

	gtk_fixed_put(GTK_FIXED(modelo),gButtonAgregar,420,430);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonEditar,550,430);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonResolver,500,460);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonLimpiar,720,430);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonVolver,730,470);
	
	gtk_fixed_put(GTK_FIXED(modelo),gButtonCargar,780,585);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonBusqueda,850,545);
	

	gButtonsRemplazoEquipos[0]=gButtonAgregar;
	gButtonsRemplazoEquipos[1]=gButtonEditar;
	gtk_widget_set_sensitive (gButtonEditar,FALSE);

		
	/*Iterando Campos de objetos*/	
	int x=990;
	int y=280;
	int xl=930;
	for(int i =0;i<10;i++)
	{					
		char num[2];
		sprintf(num,"%d",(i+1));
		GtkWidget *gLabelLinea=gtk_label_new(num);
		gtk_fixed_put(GTK_FIXED(modelo),gLabelLinea,xl,y+5);								
		for(int j=0;j<2;j++)
		{		
			GtkWidget *entry = gtk_entry_new();
			gtk_entry_set_width_chars(GTK_ENTRY(entry),8);
			gtk_entry_set_max_length(GTK_ENTRY(entry),8);

			if (j==0)//entrys de nombre
			{				
				g_signal_connect (G_OBJECT (entry), "focus-out-event",G_CALLBACK (validarCampoEquipoNum), NULL);
				gTexBoxsCostosAnuales[i][j]=entry;
			}
			else if(j==1)//entrys de valor
			{
				x-=50;				
				gtk_entry_set_width_chars(GTK_ENTRY(entry),8);
				gtk_entry_set_max_length(GTK_ENTRY(entry),8);
				g_signal_connect (G_OBJECT (entry), "focus-out-event",G_CALLBACK(validarCampoEquipoNum),NULL);
				gTexBoxsCostosAnuales[i][j]=entry;
			}			
			gtk_widget_set_sensitive (entry, FALSE);					
			gtk_fixed_put(GTK_FIXED(modelo),entry,x,y);	
			x+=160;
		}
		x=990;
		y+=33;
	}
	
	/*Lista de textbox */
	gTexBoxsDatosEquipo[0]=gTextBoxEquipo;
	gTexBoxsDatosEquipo[1]=gTextBoxCosto;
	gTexBoxsDatosEquipo[2]=gTextBoxPlazo;
	gTexBoxsDatosEquipo[3]=gTextBoxVidaUtil;	
	gTexBoxsDatosEquipo[4]=gTextBoxInflacion;	
	gTexBoxsDatosEquipo[5]=gTextBoxRuta;
	
	/*Señales*/
	
	/*Señal para la seleccion*/
	g_signal_connect(gSignalTableEquipos,"changed",G_CALLBACK(SelectedChangedEquipo),NULL); 
	
	/*Señales para los Textbox*/
	g_signal_connect (G_OBJECT (gTextBoxVidaUtil), "focus-out-event",G_CALLBACK (gTextBoxVisibleEquipos),NULL);
	g_signal_connect (G_OBJECT (gTextBoxCosto), "focus-out-event",G_CALLBACK (validarCampoEquipoNum),NULL);
	g_signal_connect (G_OBJECT (gTextBoxPlazo), "focus-out-event",G_CALLBACK (validarCampoEquipoNum),NULL);
		g_signal_connect (G_OBJECT (gTextBoxEquipo), "focus-out-event",G_CALLBACK (validarEquipo),NULL);

	
	/*Señales para los botones*/
	g_signal_connect (G_OBJECT (gButtonAgregar), "clicked",G_CALLBACK (agregarEquipo),NULL);
	g_signal_connect (G_OBJECT (gButtonEditar), "clicked",G_CALLBACK (editarEquipo),NULL);
	g_signal_connect (G_OBJECT (gButtonResolver), "clicked",G_CALLBACK (mostrarResultado),NULL);
	g_signal_connect (G_OBJECT (gButtonBusqueda), "clicked",G_CALLBACK (ChooseFileEquipos),ventana);
    g_signal_connect (G_OBJECT (gButtonCargar), "clicked",G_CALLBACK (mostrarArchivoCargadoEquipo),ventana);
	g_signal_connect (G_OBJECT (gButtonLimpiar), "clicked",G_CALLBACK (limpiarCamposEquipos),ventana);
	g_signal_connect(G_OBJECT(gButtonVolver),"clicked",G_CALLBACK(cerrarVentana),ventana); 

	/*Set modelo en la ventana*/
	gtk_container_add(GTK_CONTAINER(ventana),modelo);
	
	/*Mostrar Todo*/
	gtk_widget_show_all(ventana);		

}



int winRemplazoEquipos()
{
	/*Crear ventana con sus propiedades*/
	GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Problema de Rempleazo de Equipos");		
	gtk_window_set_default_size(GTK_WINDOW(ventana),1366,768);
	gtk_widget_set_name(GTK_WIDGET(ventana),"winWhite");

	
	/*GdkRGBA color;
	gboolean res = gdk_rgba_parse (&color, "#ffffff");
	gtk_widget_override_background_color (ventana,GTK_STATE_FLAG_NORMAL,&color);*/	
				
	
	/*Llama al cuerpo de la ventana*/
	cuerpoRemplazoEquipos(ventana);
	iniciarTablaEquipos();
	llenarTablaEquipos();
	 /* Muestra la ventana principal con todo su contenido */
	gtk_widget_show_all(ventana);		
	 /* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	/* Termina la aplicación */
	gtk_main(); 
	
	return 0;
}
