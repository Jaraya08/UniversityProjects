/* Curso :     Investigación de Operaciones
 * Estudiante: Jordan H. Araya Leiva
 * Carné:      2016254282
 * 
 * 
 * Proyecto Programado #2 : Problema de la mochila
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

enum {LIST_MOCHILA=0,LIST_PESO,LIST_OBJ,N_COLUMNAS};



/* Lista de Datos*/
GtkWidget *gTableMochila;

 /* Puntero a la fila seleccionada */
GtkTreeSelection *gSignalSelection;

/*Arreglo de GtkWidget*/
GtkWidget *objetosMochila[10][3];
GtkWidget *gTexboxValMochila[5];
GtkWidget *gButtonList[2];

/*E: NINGUNA.
 *S: INICIALIZA UNA TABLA PARA PODER LLENARSE CON LOS GRAFOS.
 *R: NINGUNA.
 * */
void iniciarTablaMochila() /* Función que inicializa la lista de datos */
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkListStore *store;	

	 /* Establece la columna y la agrega*/
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Mochilas",renderer,"text",LIST_MOCHILA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableMochila),column);
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Peso",renderer,"text",LIST_PESO,NULL);	
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableMochila),column);	 
		
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Max Obj.",renderer,"text",LIST_OBJ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gTableMochila),column);
	
	store = gtk_list_store_new(N_COLUMNAS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW(gTableMochila),GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void llenarTablaMochila()
{		
	FILE *mochila;
	
	GtkListStore *store;
	GtkTreeIter iter;
	
	char linea[256];	
	mochila =fopen("Mochila BD/mochilasRegistradas.txt","r");	
	
	/* Obtiene el modelo de datos */
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableMochila))); 
	
	while (fgets(linea,256,mochila) != NULL)
	{	
		strtok(linea,"\n");
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		token = strsep(&running, delimiters);    /* token => "mochila" */
		char nombre[12];
		strcpy(nombre,token);
		token = strsep(&running, delimiters);    /* token => "peso" */
		char peso[12];
		strcpy(peso,token);
		token = strsep(&running, delimiters);    /* token => "cant" */
		char cant[3];
		strcpy(cant,token);
		token = strsep(&running, delimiters); 	/* token => "rest" */
		char rest[3];
		strcpy(rest,token);				
		
		/* Añade una fila vacia */
		gtk_list_store_append(store, &iter);
		
		/* Cambia los valores de la fila */			
		gtk_list_store_set(store,&iter,LIST_MOCHILA,nombre,-1);
		gtk_list_store_set(store,&iter,LIST_PESO,peso,-1);
		gtk_list_store_set(store,&iter,LIST_OBJ,rest,-1);		
	}
	fclose(mochila);	
}

/*E: NINGUNA
 *S: LIMPIA TODA LA TABLA TREEVIEW_LIST
 *R: NINGUNA.
 * */
void limpiarTablaMochila()
{	
	GtkListStore *store;
	GtkTreeModel *model;
	GtkTreeIter  iter;		
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(gTableMochila)));
	model = gtk_tree_view_get_model(GTK_TREE_VIEW(gTableMochila));
	if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) 
	{
		return;
	}
	/* Limpia toda la lista */	
	gtk_list_store_clear(store); 
}

void limpiarCampos()
{
	gtk_widget_set_sensitive (gButtonList[0],TRUE);
	gtk_widget_set_sensitive (gButtonList[1],FALSE);
	gtk_widget_set_sensitive (gTexboxValMochila[0],TRUE);
	for(int i=0;i<10;i++)
	{
		if(i<4)
		{
			gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[i]),"");
		}
		for (int j=0;j<3;j++)
		{
			gtk_entry_set_text(GTK_ENTRY(objetosMochila[i][j]),"");
			gtk_widget_set_sensitive (objetosMochila[i][j],FALSE);					

		}
	}
}

void agregarTxtMochila(char datos[])
{
	/*Agregar en archivo*/
	FILE *mochila;
	mochila =fopen("Mochila BD/mochilasRegistradas.txt","a");
	strtok(datos,"\n");
	fprintf(mochila, "%s\n",datos);	
	fclose(mochila);
}
void agregarMochilas(GtkWidget *button,gpointer data)
{
	const gchar *nombreMochila=   gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[0]));
	const gchar *pesoMochila=     gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[1]));
	const gchar *cantObjMochila=  gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[2]));
	const gchar *restObjMochila = gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[3]));
		
	char ar_mochila[12];			
	strcpy(ar_mochila,nombreMochila);
	if(!(strlen(ar_mochila))>0)
	{
		ShowMessage("El campo del Nombre de la Mochila no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(gTexboxValMochila[0]);
		return;
	}	
	if(existeMochila(ar_mochila))	
	{
		ShowMessage("Nombre de la mochila ya existe, intente con otro.","¡AVISO!");
		gtk_widget_grab_focus(gTexboxValMochila[0]);
		return;
	}
	char ar_nombre[12];
	char ar_peso[3];
	char ar_cantObj[2];
	char ar_rest[3];
	
	strcpy(ar_nombre,nombreMochila);

	strcpy(ar_peso,pesoMochila);

	strcpy(ar_cantObj,cantObjMochila);

	strcpy(ar_rest,restObjMochila);

	char new_mochila[50];

	sprintf(new_mochila,"%s,%s,%s,%s",ar_nombre,ar_peso,ar_cantObj,ar_rest);

	agregarTxtMochila(new_mochila);
	
	/*Crear Mochila*/
	FILE *mochila;
	char archivo[32];
	sprintf(archivo,"Mochila BD/%s.txt",ar_nombre);
	mochila =fopen(archivo,"w");
	
	char datosCompleto[1024]="";
	
	for (int i=0;i<atoi(ar_cantObj);i++)
	{				
		const gchar *objeto  = gtk_entry_get_text(GTK_ENTRY(objetosMochila[i][0]));
		const gchar *valor  = gtk_entry_get_text(GTK_ENTRY(objetosMochila[i][1]));	
		const gchar *peso  = gtk_entry_get_text(GTK_ENTRY(objetosMochila[i][2]));
		
		char ar_objeto[15];	
		char ar_valor[6];
		char ar_peso[3];
		
		strcpy(ar_objeto,objeto);
		strcpy(ar_valor,valor);
		strcpy(ar_peso,peso);
		char datos[512];
		sprintf(datos,"%s,%s,%s\n",ar_objeto,ar_valor,ar_peso);
		strcat(datosCompleto,datos);		
	}
	fprintf(mochila,"%s",datosCompleto);
	fclose(mochila);	
	limpiarCampos();
	limpiarTablaMochila();
	llenarTablaMochila();
	char message[516];
	sprintf(message,"Se agrego Mochila : %s, con Peso Maximo de: %s, %s objetos y Limite por Objetos de : %s ",ar_nombre,ar_peso,ar_cantObj,ar_rest);
	ShowMessage(message,"¡INFORMACIÓN!");	
}

void editarMochilas(GtkWidget *button,gpointer data)
{
	const gchar *mochilaNom =     gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[0]));
	const gchar *pesoMochila=     gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[1]));
	const gchar *cantObjMochila=  gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[2]));
	const gchar *restObjMochila = gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[3]));
	
	char ar_nombre[12];
	char ar_peso[3];
	char ar_cantObj[2];
	char ar_rest[3];	
	char linea[64];
	
	strcpy(ar_nombre,mochilaNom);
	strcpy(ar_peso,pesoMochila);
	strcpy(ar_cantObj,cantObjMochila);
	strcpy(ar_rest,restObjMochila);
	
	FILE *mochilas,*temp;	
	mochilas=fopen("Mochila BD/mochilasRegistradas.txt","r");
	temp =fopen("Mochila BD/temp2.txt","w");			
	while (fgets(linea,64,mochilas) != NULL)
	{		
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "mochila" */
		char mochilas[12];
		strcpy(mochilas,token);
		
		if(!strcmp(ar_nombre,mochilas)){}
		else
		{
			fprintf(temp,"%s\n",linea);			
		}
	}
			
	char new_mochila[50];
	sprintf(new_mochila,"%s,%s,%s,%s",ar_nombre,ar_peso,ar_cantObj,ar_rest);
	fprintf(temp,"%s\n",new_mochila);			
	fclose(temp);
	fclose(mochilas);
	remove("Mochila BD/mochilasRegistradas.txt");
	rename("Mochila BD/temp2.txt","Mochila BD/mochilasRegistradas.txt");
	remove("Mochila BD/temp2.txt");	
	/*Modificar Objetos*/	
	FILE *mochila;
	char archivo[32];
	sprintf(archivo,"%s.txt",ar_nombre);
	mochila =fopen(archivo,"w");
	
	char datosCompleto[1024]="";
	
	for (int i=0;i<atoi(ar_cantObj);i++)
	{				
		const gchar *objeto  = gtk_entry_get_text(GTK_ENTRY(objetosMochila[i][0]));
		const gchar *valor  = gtk_entry_get_text(GTK_ENTRY(objetosMochila[i][1]));	
		const gchar *peso  = gtk_entry_get_text(GTK_ENTRY(objetosMochila[i][2]));
		
		char ar_objeto[15];	
		char ar_valor[6];
		char ar_peso[3];
		
		strcpy(ar_objeto,objeto);
		strcpy(ar_valor,valor);
		strcpy(ar_peso,peso);
		
		char datos[512];
		sprintf(datos,"%s,%s,%s\n",ar_objeto,ar_valor,ar_peso);
		strcat(datosCompleto,datos);	
	}
	fprintf(mochila,"%s",datosCompleto);
	fclose(mochila);	
	limpiarTablaMochila();
	llenarTablaMochila();
	limpiarCampos();
	ShowMessage("Los datos de la mochila fueron modificados correctamente","¡AVISO!");
}


/*Algoritmo de la mochila normal*/
void mochilaNormal(int cap, int n,int matrizM[cap][n],char matrizC[cap][n],char matrizO[n][3][18],int matrizN[cap][n])
{	
	for(int i=0;i<n;i++)
	{
		for(int m=0;m<n;m++)matrizM[0][m]=0;
		for(int j=1;j<=cap;j++)//j = capacidad actual
		{
			if(i==0)
			{
				if(!(j<atoi(matrizO[i][2])))
				{
					matrizM[j][i]=atoi(matrizO[i][1]);					
					matrizN[j][i]=1;
					matrizC[j][i]='V';	
				}
			}
			else
			{							
				if(j>=atoi(matrizO[i][2]))
				{
					if((atoi(matrizO[i][1])+matrizM[j-(atoi(matrizO[i][2]))][i-1])>matrizM[j][i-1])
					{
						matrizM[j][i]=atoi(matrizO[i][1])+matrizM[j-(atoi(matrizO[i][2]))][i-1];
						matrizC[j][i]='V';
						matrizN[j][i]=1;
					}
					else
					{
				        matrizM[j][i]=matrizM[j][i-1];
					}						
				}
				else
				{
				     matrizM[j][i]=matrizM[j][i-1];
				}
			}
		}
	}			
}
/*Algoritmo de la mochila unbonded*/
void mochilaUnbond(int max, int cap, int n, int matrizM[cap][n],char matrizC[cap][n],char matrizO[n][3][18],int matrizN[cap][n])
{	
	for(int i=0;i<n;i++)
	{
		for(int m=0;m<n;m++)matrizM[0][m]=0;
		int cant=0;
		for(int j=1;j<=cap;j++)//j = capacidad actual
		{
			if(i==0)
			{
				cant=j/atoi(matrizO[i][2]);
				if(cant<=max & j>=atoi(matrizO[i][2]))
				{						
					matrizM[j][i]=atoi(matrizO[i][1])*cant;
					matrizC[j][i]='V';	
					matrizN[j][i]=cant;				
				}						
				else if(cant>max)
				{
					matrizM[j][i]=matrizM[j-1][i];
					matrizN[j][i]=matrizN[j-1][i];
					matrizC[j][i]='V';	
				}				
				
			}
			else
			{		
				cant=j/atoi(matrizO[i][2]);			
				if(cant<=max & j>=atoi(matrizO[i][2])) // Capacidad actual
				{						
					int num=0;
					int mayor=0;						
					for(int k=1;k<=cant;k++)
					{						
						if( ( (atoi(matrizO[i][1])*k) + (matrizM[j-(atoi(matrizO[i][2])*k ) ][i-1]) ) > mayor)
						{
							mayor=( (atoi(matrizO[i][1])*k) + (matrizM[j-(atoi(matrizO[i][2])*k ) ][i-1]) );
							num+=1;
						}
																		
					}
					if(mayor>matrizM[j][i-1])
					{
						matrizM[j][i]=mayor;
						matrizN[j][i]=num;
						matrizC[j][i]='V';	
					}
					else
					{
						matrizM[j][i]=matrizM[j][i-1];
					}									
				}
				else if(matrizM[j-1][i]==0 | matrizM[j-1][i]==matrizM[j][i-1])
				{
					matrizM[j][i]=matrizM[j][i-1];
				}	
				else if(matrizM[j-1][i]>matrizM[j][i-1])
				{
					matrizM[j][i]=matrizM[j-1][i];
					matrizN[j][i]=matrizN[j-1][i];
					matrizC[j][i]='V';	
				}
				else
				{
					matrizM[j][i]=matrizM[j][i-1];	
				}								
			}
		}
	}
}


void formarMatrizMochilas()
{
	const gchar * nombre = gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[0]));
	const gchar * capacidad = gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[1]));
	const gchar * cantObj = gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[2]));
	const gchar * maximo = gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[3]));
		
	char ar_nombre[64];	
	strcpy(ar_nombre,nombre);			
	
	int n=atoi(cantObj); //cantidad de objetos
	int cap =atoi(capacidad); // capacidad de la mochila
	int max =atoi(maximo); // cantidad Maxima de objetos
	
	int  matrizM[cap][n]; // matriz resultado
	int  matrizN[cap][n]; // matriz de cantidades por objeto
	char matrizC[cap][n]; // matriz de colores
	char matrizO[n][3][18]; // matriz de objetos
	
	for(int c=0;c<=cap;c++) // inicializar matrices 
	{ 
		for(int j=0;j<n;j++)
		{  
			matrizM[c][j]=0;
			matrizC[c][j]='R';
			matrizN[c][j]=0;
		}
	}	
	for(int i=0;i<n;i++)
	{					

		for(int j=0;j<3;j++)
		{
			const gchar  *valor = gtk_entry_get_text(GTK_ENTRY(objetosMochila[i][j])); 
			if(strlen(valor)==0)
			{
				ShowMessage("Hay un objeto sin definir, Favor llenarlo o eliminar la linea","¡ERROR!");
				return;
			}
			else
			{
				strcpy(matrizO[i][j],valor);
				
			}
		}
	}
	
	if(max==1)
	{
		ShowMessage("Mochila Normal","Tipo Algoritmo");
		mochilaNormal(cap,n,matrizM,matrizC,matrizO,matrizN);
	}		
	else if(max>cap)
	{
		ShowMessage("Mochila Unbounded.","Tipo Algoritmo");
		mochilaUnbond(999,cap,n,matrizM,matrizC,matrizO,matrizN);
	}
	else
	{
		ShowMessage("Mochila Bounded.","Tipo Algoritmo");
		mochilaUnbond(max,cap,n,matrizM,matrizC,matrizO,matrizN);
	}		
	mostarTablasMochila(ar_nombre,max,cap,n,matrizM,matrizC,matrizO,matrizN);	
}
void formaMatematicaInicial(int max,int cap,int n,char Z[],char sujeto_a[],char maximo[],char matrizO[n][3][18])
{		
	char ar_max[2];
	sprintf(ar_max,"%d",max);
	strcat(maximo,ar_max);
	for(int i=0;i<n;i++)
	{		
		char valoresZ[32];
		char valoresSuj[32];
		if(i==0)
		{
			sprintf(valoresZ,"%sX%c",matrizO[i][1],tolower((matrizO[i][0])[0]));
			sprintf(valoresSuj,"%sX%c",matrizO[i][2],tolower((matrizO[i][0])[0]));
		}
		else
		{
			sprintf(valoresZ,"+ %sX%c",matrizO[i][1],tolower((matrizO[i][0])[0]));
			sprintf(valoresSuj,"+ %sX%c",matrizO[i][2],tolower((matrizO[i][0])[0]));
		}
		strcat(Z,valoresZ);
		strcat(sujeto_a,valoresSuj);
	}
	char res[2];
	sprintf(res," <= %d",cap);
	strcat(sujeto_a,res);
}
void formaMatematicaFinal(int cap, int n,char Z[],char sujeto_a[],char matrizO[n][3][18],int matrizN[cap][n],char matrizC[cap][n],int matrizM[cap][n],int cantidades[])
{	
	
	int optimizacion=matrizM[cap][n-1];	
	int C = 0;;
	n-=1;	
	while(n!=-1)
	{					
		int cant=0; 					
		char valoresZ[32]="";
		char valoresSuj[32]="";	
		
		if(matrizC[cap][n]=='V')
		{					
			
			cantidades[n]=matrizN[cap][n];	
			cant= atoi(matrizO[n][2])*matrizN[cap][n];	
			sprintf(valoresZ,"%sx%d%c +",matrizO[n][1],matrizN[cap][n],tolower((matrizO[n][0])[0]));
		    sprintf(valoresSuj,"%sx%d%c +",matrizO[n][2],matrizN[cap][n],tolower((matrizO[n][0])[0]));		
			cap-=cant;				
			C+=cant;
		}
		else
		{		
			sprintf(valoresZ,"%sx%d%c +",matrizO[n][1],0,tolower((matrizO[n][0])[0]));
			sprintf(valoresSuj,"%sx%d%c +",matrizO[n][2],0,tolower((matrizO[n][0])[0]));		
	    }
		strcat(sujeto_a,valoresSuj);	
		strcat(Z,valoresZ);
		
		n-=1;
	}
	char res[64];
	sprintf(res," = %d",optimizacion);	
	strcat(Z,res);	
	sprintf(res," = %d",C);
	strcat(sujeto_a,res	);
}

void mostarTablasMochila(char nombre[],int max, int cap, int n, int matrizM[cap][n],char matrizC[cap][n],char matrizO[n][3][18],int matrizN[cap][n])
{
	char Zini[1024]="Z = ";
	char sujeto_aIni[1024]="";
	char maximo[16]="X < = ";
	
	char Zfin[1024]="";
	char sujeto_aFin[1024]="";
	
	int cantidades[n];
	for(int i=0;i<=n;i++)cantidades[i]=0;
	
	formaMatematicaInicial(max,cap,n,Zini,sujeto_aIni,maximo,matrizO);
	formaMatematicaFinal(cap,n,Zfin,sujeto_aFin,matrizO,matrizN,matrizC,matrizM,cantidades);
	
	GtkWidget  * ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),nombre);		
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
	GtkWidget *image = gtk_image_new_from_file ("Mochila BD/Encabezado2.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);	
	
		
	int x=130;
	int y=280;
	
	char *encabezado[3]={"Objeto","Valor","Costo/Peso"};
	char *encambLlebar[2]={"objetos","llevar"};
	
	/*Emcabezado de objetos*/
	for(int i=0;i<3;i++)
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
		char texto[8];
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
		for(int j=0;j<3;j++)
		{
			char texto[16];
			sprintf(texto, "%s", matrizO[i][j]);
			if(j==0)
			{
				GtkWidget *label1 = gtk_label_new(texto);
				gtk_fixed_put(GTK_FIXED(modelo),label1,x+395,y);
				
				char cant[16];
				sprintf(cant, "%d", cantidades[i]);
				GtkWidget *cantidades = gtk_label_new(cant);
				gtk_fixed_put(GTK_FIXED(modelo),cantidades,x+520,y);
			}			
			GtkWidget *label1 = gtk_label_new(texto);
			gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);
			x+=100;
		}
		x=130;
		y+=30;
	}
	int yFinTitulo = (y-310)+80;
	char tituloOb[128];
	sprintf(tituloOb,"Objetos de mochila %s",nombre);
	GtkWidget *groupTextCargar =gtk_frame_new (tituloOb);
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,50,240);
	gtk_widget_set_size_request( groupTextCargar , x+220 ,yFinTitulo);
	
	/*Fin de Objetos*/	
	
	/*Encabezado cantidad de objetos*/
	
	GtkWidget *groupTextEmbLlevar =gtk_frame_new ("Objetos a llevar");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextEmbLlevar,450,240);
	gtk_widget_set_size_request( groupTextEmbLlevar, x+120 ,yFinTitulo);
	
	int posx=520;
	int posy=280;
	for(int i=0;i<2;i++)
	{
		char texto[16];
		sprintf(texto, "%s", encambLlebar[i]);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,posx,posy);	
		posx+=120;
	}
	x=480;
	y=310;
	for(int j=1;j<=n;j++)
	{
		char texto[8];
		sprintf(texto, "%d", j);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);
		y+=30;
	}	
	
	/*Colocando formulas matematicas*/
	
	GtkWidget *groupTextFormulas =gtk_frame_new ("Formulas Matematicas Iniciales y finales");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextFormulas,730,240);
	gtk_widget_set_size_request( groupTextFormulas , x+150,yFinTitulo);
	
	GtkWidget *formaMat = gtk_label_new("FORMA MATEMÁTICA INICIAL:");
	gtk_fixed_put(GTK_FIXED(modelo),formaMat,740,270);
	GtkWidget *Zinicial = gtk_label_new(Zini);
	gtk_fixed_put(GTK_FIXED(modelo),Zinicial,765,290);
	GtkWidget *gLabelsujeto = gtk_label_new("SUJETO A:");
	gtk_fixed_put(GTK_FIXED(modelo),gLabelsujeto,740,320);
	GtkWidget *gLabelsujetoA = gtk_label_new(sujeto_aIni);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelsujetoA,765,340);
	
	GtkWidget *gLabelCon = gtk_label_new("CON:");
	gtk_fixed_put(GTK_FIXED(modelo),gLabelCon,740,370);
	GtkWidget *gLabelConX = gtk_label_new(maximo);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelConX,765,390);
	
	GtkWidget *gLabelSolucion = gtk_label_new("SOLUCION:");
	gtk_fixed_put(GTK_FIXED(modelo),gLabelSolucion,740,420);
	
	GtkWidget *gLabelZfinal = gtk_label_new(Zfin);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelZfinal,765,440);
	
	GtkWidget *gLabelsujetoRes = gtk_label_new("SUJETO A:");
	gtk_fixed_put(GTK_FIXED(modelo),gLabelsujetoRes,740,470);
	
	GtkWidget *gLabelsujetoAFin = gtk_label_new(sujeto_aFin);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelsujetoAFin,765,490);
			
	/*Colocando emcabezados de la tabla */	
	x=130;
	y+=50;
	for(int i=0;i<n;i++)
	{
		char texto[16];
		sprintf(texto, "%s", matrizO[i][0]);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);	
		x+=100;
	}
	
	x=70;
	y+=40;
	
	int tabOpY=0;
	
	for(int j=0;j<=cap;j++)
	{
		char texto[16];
		sprintf(texto, "%d", j);
		GtkWidget *label1 = gtk_label_new(texto);
		gtk_fixed_put(GTK_FIXED(modelo),label1,x,y);
		y+=40;
		tabOpY+=40;

	}
	
	y-=(40*cap+1);
	x=y-40;
	int xx=x;
	y=120;
	
	
	for(int i=0;i<n;i++)
	{									
		for (int j=0;j<=cap;j++)
		{
			char texto[16];
			sprintf(texto, "%d", matrizM[j][i]);
			GtkWidget *label1 = gtk_label_new(texto);	
			gtk_widget_set_size_request( label1 ,90,30);
			
			if(matrizC[j][i]=='V')
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelGreen");
				//res = gdk_rgba_parse (&color, "#09ff00");
			}
			else
			{
				gtk_widget_set_name(GTK_WIDGET(label1),"labelRed");
				//res = gdk_rgba_parse (&color, "#ff0040");							
			}			
			//gtk_widget_override_background_color (label1,GTK_STATE_FLAG_NORMAL,&color);
			gtk_fixed_put(GTK_FIXED(modelo),label1,y,x);
			x+=40;
		}
		x=xx;
		y+=100;		
	}
	char tituloTab[128];
	sprintf(tituloTab,"Tabla optima de mochila  %s",nombre)	;
	GtkWidget *groupTextTabOptima =gtk_frame_new (tituloTab);
	gtk_fixed_put(GTK_FIXED(modelo),groupTextTabOptima,50,yFinTitulo+250);
	gtk_widget_set_size_request( groupTextTabOptima, y ,tabOpY+100);
	
	GtkWidget *fin = gtk_label_new(" ");
	gtk_fixed_put(GTK_FIXED(modelo),fin,10,tabOpY+yFinTitulo+380);
	
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

void cuerpoMochila(GtkWidget *ventana)
{
	
	/*Crea un modelo*/
	GtkWidget *modelo= gtk_fixed_new ();	
	/*Carga imagen a la ventana*/
	GtkWidget *image = gtk_image_new_from_file ("Mochila BD/Encabezado.jpg");		
	/*Carga imagen al modelo*/
	gtk_fixed_put(GTK_FIXED(modelo),image,0,0);	
	
	/*Creando un Gruptext*/
	GtkWidget *groupTextMochila =gtk_frame_new ("Mochilas Registradas");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextMochila,10,230);
	gtk_widget_set_size_request( groupTextMochila ,215 ,380);
	
	GtkWidget *groupTextGeneral =gtk_frame_new ("Datos generales de Mochila");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextGeneral,300,230);
	gtk_widget_set_size_request( groupTextGeneral ,400 ,250);
	
	GtkWidget *groupTextObjetos =gtk_frame_new ("Objetos de la Mochila");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextObjetos,800,230);
	gtk_widget_set_size_request( groupTextObjetos ,390 ,370);
	
	GtkWidget *groupTextCargar =gtk_frame_new ("Cargar Archivos");
	gtk_fixed_put(GTK_FIXED(modelo),groupTextCargar,300,490);
	gtk_widget_set_size_request( groupTextCargar ,480 ,110);
	
	/*Inicializar tabla*/
	gTableMochila = gtk_tree_view_new(); /* Crea la vista de la lista */
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(gTableMochila),TRUE); /* Visualiza las cebeceras de la lista */
	gSignalSelection = gtk_tree_view_get_selection(GTK_TREE_VIEW(gTableMochila));


	/*Posicionar tabla*/
	gtk_fixed_put(GTK_FIXED(modelo),gTableMochila,20,250);
	
	/*Etiquetas*/
	GtkWidget *gLabelMochila,*gLabelPeso,*gLabelRestriccion,*gLabelCantObjetos,*gLabelNombreObjeto,*gLabelPesoObjeto,*gLabellinea,*gLabelValor;
	GtkWidget *gLabelRuta;
	
	/*TextBox*/
	GtkWidget *gTextBoxMochila,*gTextBoxPeso,*gTextBoxRestriccion,*gTextBoxCantObjetos,*gTextBoxRuta;
	
	/*Buttons*/
	GtkWidget *gButtonAgregar,*gButtonEditar,*gButtonVolver,*gButtonCargar,*gButtonBusqueda,*gButtonLimpiar ,*gButtonResolver;
	
	/*Inicializar GtkWidget*/
	gLabelMochila = gtk_label_new("Nombre mochila:");
	gLabelPeso = gtk_label_new("Peso de mochila:");
	gLabelRestriccion = gtk_label_new("Restricción cant. objetos:");
	gLabelCantObjetos = gtk_label_new("Cantidad de objetos:");
	gLabellinea = gtk_label_new("Linea");
	gLabelNombreObjeto = gtk_label_new("Nombre Objeto");
	gLabelValor = gtk_label_new("Valor obj.");
	gLabelPesoObjeto = gtk_label_new("Peso Obj.");
	gLabelRuta=gtk_label_new("Ruta:");
	
	gTextBoxMochila = gtk_entry_new();
	gTextBoxPeso = gtk_entry_new();
	gTextBoxRestriccion = gtk_entry_new();
	gTextBoxCantObjetos =gtk_entry_new();
	gTextBoxRuta=gtk_entry_new();
	
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxMochila),10);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxPeso),3);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxCantObjetos),2);
	gtk_entry_set_max_length(GTK_ENTRY(gTextBoxRestriccion),3);
	
	gtk_widget_set_size_request(gTextBoxRuta ,380,-1);

	gButtonAgregar = gtk_button_new_with_label("Agregar mochila");
	gButtonEditar = gtk_button_new_with_label("Editar Mochila");
	gButtonVolver = gtk_button_new_with_label("Volver");
	gButtonCargar =gtk_button_new_with_label("Cargar");
	gButtonBusqueda=gtk_button_new_with_label("...");
	gButtonLimpiar=gtk_button_new_with_label("Limpiar");
	gButtonResolver=gtk_button_new_with_label("Resolver");
	
	/*Posicionar GtkWidget*/
	gtk_fixed_put(GTK_FIXED(modelo),gLabelMochila,320,270);	
	gtk_fixed_put(GTK_FIXED(modelo),gLabelPeso,320,300);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelCantObjetos,320,330);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelRestriccion,320,360);
	gtk_fixed_put(GTK_FIXED(modelo),gLabellinea,820,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelNombreObjeto,880,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelValor,1010,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelPesoObjeto,1100,250);
	gtk_fixed_put(GTK_FIXED(modelo),gLabelRuta,320,520);

	
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxMochila,520,265);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxPeso,520,295);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxCantObjetos,520,325);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxRestriccion,520,355);
	gtk_fixed_put(GTK_FIXED(modelo),gTextBoxRuta,360,515);

	
	gtk_fixed_put(GTK_FIXED(modelo),gButtonAgregar,320,400);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonEditar,450,400);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonResolver,400,430);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonLimpiar,620,400);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonVolver,630,440);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonCargar,680,555);
	gtk_fixed_put(GTK_FIXED(modelo),gButtonBusqueda,750,515);
	


	gButtonList[0]=gButtonAgregar;
	gButtonList[1]=gButtonEditar;
	gtk_widget_set_sensitive (gButtonEditar,FALSE);

		
	/*Iterando Campos de objetos*/	
	int x=885;
	int y=270;
	int xl=830;
	for(int i =0;i<10;i++)
	{			
		for(int j=0;j<3;j++)
		{		
			GtkWidget *entry = gtk_entry_new();
			gtk_entry_set_width_chars(GTK_ENTRY(entry),10);
			gtk_entry_set_max_length(GTK_ENTRY(entry),10);

			if (j==0)//entrys de nombre
			{				
				g_signal_connect (G_OBJECT (entry), "focus-out-event",G_CALLBACK (validarObjeto), NULL);
				objetosMochila[i][j]=entry;
			}
			else if(j==1)//entrys de valor
			{
				x-=30;
				gtk_entry_set_width_chars(GTK_ENTRY(entry),6);
				gtk_entry_set_max_length(GTK_ENTRY(entry),6);
				g_signal_connect (G_OBJECT (entry), "focus-out-event",G_CALLBACK(ValidarValor),NULL);
				objetosMochila[i][j]=entry;
			}
			else if(j==2)//entrys de peso
			{		
				x-=60;		
				char num[2];
				sprintf(num,"%d",(i+1));
				GtkWidget *gLabelLinea=gtk_label_new(num);
				gtk_fixed_put(GTK_FIXED(modelo),gLabelLinea,xl,y+5);				
				gtk_entry_set_width_chars(GTK_ENTRY(entry),3);
				gtk_entry_set_max_length(GTK_ENTRY(entry),3);
				g_signal_connect (G_OBJECT (entry), "focus-out-event",G_CALLBACK (validarPeso),NULL);
				objetosMochila[i][j]=entry;
			}
			gtk_widget_set_sensitive (entry, FALSE);					
			gtk_fixed_put(GTK_FIXED(modelo),entry,x,y);	
			x+=160;
		}
		x=885;
		y+=30;
	}
	
	/*Lista de textbox */
	gTexboxValMochila[0]=gTextBoxMochila;
	gTexboxValMochila[1]=gTextBoxPeso;
	gTexboxValMochila[2]=gTextBoxCantObjetos;
	gTexboxValMochila[3]=gTextBoxRestriccion;	
	gTexboxValMochila[4]=gTextBoxRuta;
	/*Señales*/
	
	/*Señal para la seleccion*/
	g_signal_connect(gSignalSelection,"changed",G_CALLBACK(SelectedChangedMochila),NULL); 
	
	/*Señales para los Textbox*/
	g_signal_connect (G_OBJECT (gTextBoxCantObjetos), "focus-out-event",G_CALLBACK (gTextBoxVisible),NULL);
	g_signal_connect (G_OBJECT (gTextBoxMochila), "focus-out-event",G_CALLBACK (validarMochila),NULL);
	g_signal_connect (G_OBJECT (gTextBoxPeso), "focus-out-event",G_CALLBACK (ValidarPesoMochila),NULL);
	g_signal_connect (G_OBJECT (gTextBoxRestriccion), "focus-out-event",G_CALLBACK (validarRestObjetos),NULL);
	
	/*Señales para los botones*/
	g_signal_connect (G_OBJECT (gButtonAgregar), "clicked",G_CALLBACK (agregarMochilas),NULL);
	g_signal_connect (G_OBJECT (gButtonEditar), "clicked",G_CALLBACK (editarMochilas),NULL);
	g_signal_connect (G_OBJECT (gButtonResolver), "clicked",G_CALLBACK (formarMatrizMochilas),NULL);
	g_signal_connect (G_OBJECT (gButtonBusqueda), "clicked",G_CALLBACK (mostrarChooseFile),ventana);
	g_signal_connect (G_OBJECT (gButtonCargar), "clicked",G_CALLBACK (mostrarArchivoCargado),ventana);
	g_signal_connect (G_OBJECT (gButtonLimpiar), "clicked",G_CALLBACK (limpiarCampos),ventana);
	g_signal_connect(G_OBJECT(gButtonVolver),"clicked",G_CALLBACK(cerrarVentana),ventana); 




	
	/*Set modelo en la ventana*/
	gtk_container_add(GTK_CONTAINER(ventana),modelo);
	
	/*Mostrar Todo*/
	gtk_widget_show_all(ventana);		

}

/*Eventos*/

void mostrarArchivoCargado(GtkWidget * button,gpointer ventana)
{
	limpiarCampos();
	gtk_widget_set_sensitive (gButtonList[1],FALSE);
	gtk_widget_set_sensitive (gButtonList[0],TRUE);
	FILE *mochila,*temp;
	const gchar *archivo = gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[4]));
	char ar_file[512],linea[64];	
	strcpy(ar_file,archivo);
	if(!strlen(ar_file)>0)
	{
		ShowMessage("No se ha selecionado ninguna ruta","¡AVISO!");
		return;
	}
	mochila = fopen(ar_file,"r");
	temp = fopen("temp.txt","w");			
	int i=0;
	while (fgets(linea,64,mochila) != NULL)
	{
		strtok(linea,"\n");
		if(i==0)
		{
			const char delimiters[] = ",";
			char * running = strdup(linea);
			char * token;
		
			token = strsep(&running, delimiters);    /* token => "mochila" */
			char mochilaNom[12];
			strcpy(mochilaNom,token);
			
			token = strsep(&running, delimiters);    /* token => "peso" */
			char mochilaPeso[12];
			strcpy(mochilaPeso,token);
			
			token = strsep(&running, delimiters);    /* token => "cantidad objetos" */
			char mochilaCant[3];
			strcpy(mochilaCant,token);
			
			token = strsep(&running, delimiters);    /* token => "restriccion" */
			char mochilaRest[3];
			strcpy(mochilaRest,token);
			
			gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[0]),mochilaNom);
			gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[1]),mochilaPeso);
			gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[2]),mochilaCant);
			gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[3]),mochilaRest);
		}
		else
		{			
			fprintf(temp,"%s\n",linea);			
		}
		i+=1;	
	}
	fclose(temp);
	cargarDatos("temp.txt");
	remove("temp.txt");
	gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[4]),"");
}

int mostrarChooseFile(GtkWidget * button,gpointer ventana)
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
		gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[4]),filename);		
	}
	gtk_widget_destroy (dialog);
}

void cargarDatos(char archivo[])
{
		FILE *objMochila;
		objMochila =fopen(archivo,"r");			
		int i=0;char linea[256];	
		while (fgets(linea,256,objMochila) != NULL)
		{	
			strtok(linea,"\n");
			const char delimiters[] = ",";
			char * running = strdup(linea);
			char * token;
		
			token = strsep(&running, delimiters);    /* token => "objeto" */
			char nombre[12];
			strcpy(nombre,token);
			
			token = strsep(&running, delimiters);    /* token => "valor" */
			char valor[12];
			strcpy(valor,token);
			
			token = strsep(&running, delimiters);    /* token => "peso" */
			char peso[3];
			strcpy(peso,token);
			
			gtk_entry_set_text(GTK_ENTRY(objetosMochila[i][0]),nombre);
			gtk_entry_set_text(GTK_ENTRY(objetosMochila[i][1]),valor);
			gtk_entry_set_text(GTK_ENTRY(objetosMochila[i][2]),peso);
			
			gtk_widget_set_sensitive (objetosMochila[i][0],TRUE);					
			gtk_widget_set_sensitive (objetosMochila[i][1],TRUE);
			gtk_widget_set_sensitive (objetosMochila[i][2],TRUE);
			i+=1;
		}
		for(int j=i;j<10;j++)
		{
			for(int k=0;k<3;k++)
			{
				gtk_widget_set_sensitive (objetosMochila[j][k],FALSE);
				gtk_entry_set_text(GTK_ENTRY(objetosMochila[j][k]),"");					
			}
		}		
		sprintf(linea,"%d",i);
		gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[2]),linea);
}

void SelectedChangedMochila(GtkWidget *gTable,gpointer dato) 
{
	
	GtkTreeIter iter;
	GtkTreeModel *model;
	gchar *value;	
	char archivo[64];	
	char paht[256]="";
	strcat(paht,"Mochila BD/");
	gtk_widget_grab_focus(gTexboxValMochila[4]);
	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(gTable),&model,&iter)) 
	{	
		gtk_widget_set_sensitive (gButtonList[0],FALSE);
		gtk_widget_set_sensitive (gButtonList[1],TRUE);
		gtk_widget_set_sensitive (gTexboxValMochila[0],FALSE);

		/* Obtiene el Valor  */
		gtk_tree_model_get(model,&iter,LIST_MOCHILA,&value,-1); 		
		 /* Deposita el valor en el entry*/		
		gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[0]),value);//Nombre
		
		gtk_tree_model_get(model,&iter,LIST_PESO,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[1]),value);//peso
		
		gtk_tree_model_get(model,&iter,LIST_OBJ,&value,-1); 				 
		gtk_entry_set_text(GTK_ENTRY(gTexboxValMochila[3]),value);//Restrigccion de Objetos
		
		const gchar	*NomMochila = gtk_entry_get_text(GTK_ENTRY(gTexboxValMochila[0]));
		g_free(value);
		strcpy(archivo,NomMochila);	
		strcat(archivo,".txt");
		strcat(paht,archivo);		
		cargarDatos(paht);
		
		//fclose(archivo);
	}
}

int existeMochila(char mochila[])
{
	FILE *p_mochila;
	char linea[256];	
	p_mochila =fopen("Mochila BD/mochilasRegistradas.txt","r");		
	
	while (fgets(linea,256,p_mochila) != NULL)
	{	
		strtok(linea,"\n");
		
		const char delimiters[] = ",";
		char * running = strdup(linea);
		char * token;
		
		token = strsep(&running, delimiters);    /* token => "mochila" */
		char nombre[12];
		strcpy(nombre,token);
		if(!strcmp(mochila,nombre))
		{
			return 1;
		}
	}
	fclose(p_mochila);
	return 0;
}

int validarMochila(GtkWidget *entry,gpointer puntero)
{
	const gchar *mochila = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_mochila[12];
	
	strcpy(ar_mochila,mochila);
	
	strtok(ar_mochila,"\n");
	
	if(!strlen(ar_mochila)>0)
	{
		ShowMessage("El Campo MOCHILA no puede ser vacio","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}	
	else if(IS_NUM(ar_mochila))
	{
		ShowMessage("El campo MOCHILA debe tener al menos un caracter","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}
	else if(existeMochila(ar_mochila))
	{
		ShowMessage("Nombre de MOCHILA ya existe, favor intente con otro nombre","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}	
}

int validarObjeto(GtkWidget *entry,gpointer puntero)
{
	const gchar *obj = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_obj[12];
	strcpy(ar_obj,obj);
	int val = IS_NUM(ar_obj);
	strtok(ar_obj,"\n");
	if(!strlen(ar_obj)>0)
	{
		ShowMessage("El campo OBJETO no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}
	else if(val)
	{
		ShowMessage("El campo OBJETO debe tener al menos una letra","¡AVISO!");
		gtk_widget_grab_focus(entry);
		return 0;
	}
	return 0;
}

int ValidarValor(GtkWidget *entry,gpointer puntero)
{
	const gchar *valor = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_valor[6];
	strcpy(ar_valor,valor);
	int val = IS_NUM(ar_valor);
	strtok(ar_valor,"\n");
	if(!strlen(ar_valor)>0)
	{
		ShowMessage("El campo VALOR no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(!val)
	{
		ShowMessage("El campo VALOR solo acepta numeros enteros positivos","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	return 0;
}
int ValidarPesoMochila(GtkWidget *entry,gpointer puntero)
{
	const gchar *valor = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_valor[6];
	strcpy(ar_valor,valor);
	int val = IS_NUM(ar_valor);
	strtok(ar_valor,"\n");
	if(!strlen(ar_valor)>0)
	{
		ShowMessage("El campo PESO MOCHILA no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(!val)
	{
		ShowMessage("El campo PESO MOCHILA solo acepta numeros enteros positivos","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(atoi(ar_valor)<1)
	{
		ShowMessage("El campo PESO MOCHILA solo acepta numeros enteros positivos mayores a 0","¡AVISO!");	
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	return 0;
}

int validarPeso(GtkWidget *entry,gpointer puntero)
{
	const gchar *peso = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_peso[3];
	strcpy(ar_peso,peso);
	strtok(ar_peso,"\n");
	int val = IS_NUM(ar_peso);
	if(!strlen(ar_peso)>0)
	{
		ShowMessage("El campo de PESO no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(!val)
	{
		ShowMessage("El campo PESO solo acepta numeros enteros positivos mayores a 0","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(atoi(ar_peso)<1)
	{
		ShowMessage("El campo PESO solo acepta numeros enteros positivos mayores a 0","¡AVISO!");	
		gtk_widget_grab_focus(entry);	
		return 0 ;
	}
	return 0;
}
int validarRestObjetos(GtkWidget *entry,gpointer puntero)
{
	const gchar *peso = gtk_entry_get_text(GTK_ENTRY(entry));
	char ar_peso[3];
	strcpy(ar_peso,peso);
	strtok(ar_peso,"\n");
	int val = IS_NUM(ar_peso);
	if(!strlen(ar_peso)>0)
	{
		ShowMessage("El campo de RESTRICCIÓN CANT. OBJETOS no puede ser vacío","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(!val)
	{
		ShowMessage("El campo RESTRICCIÓN CANT. OBJETOS solo acepta numeros enteros positivos mayores a 0","¡AVISO!");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else if(atoi(ar_peso)<1)
	{
		ShowMessage("El campo RESTRICCIÓN CANT. OBJETOS solo acepta numeros enteros positivos mayores a 0","¡AVISO!");	
		gtk_widget_grab_focus(entry);	
		return 0 ;
	}
	return 0;
}

int gTextBoxVisible(GtkWidget *entry,gpointer puntero)
{
	const gchar * cantidad = gtk_entry_get_text(GTK_ENTRY(entry));
	char cant[3];
	strcpy(cant,cantidad);
	int fin = IS_NUM(cant);
	strtok(cant,"\n");
	if(!strlen(cant))
	{
		ShowMessage("El campo CANTIDAD DE OBJETOS no puede ser vacio","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	if(!fin)
	{
		ShowMessage("El campo CANTIDAD DE OBJETOS solo acepta numeros enteros positivos","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;	
	}
	else if(atoi(cant)>10)
	{
		ShowMessage("La cantidad de objetos no puede ser mayor a 10","!AVISO¡");
		gtk_widget_grab_focus(entry);	
		return 0;
	}
	else
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<3;j++)
			{	
				gtk_widget_set_sensitive (objetosMochila[i][j],TRUE);					
				if(i>=atoi(cant))
				{
					gtk_entry_set_text(GTK_ENTRY(objetosMochila[i][j]),"");
					gtk_widget_set_sensitive (objetosMochila[i][j],FALSE);					
				}		
			}
		}
		return 0;
	}	
}

int winMochila()
{
	/*Crear ventana con sus propiedades*/
	GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER);		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Problema de la Mochila: Knapsack Problem");		
	gtk_window_set_default_size(GTK_WINDOW(ventana),1366,768);
	gtk_widget_set_name(GTK_WIDGET(ventana),"winWhite");
	
	/*GdkRGBA color;
	gboolean res = gdk_rgba_parse (&color, "#ffffff");
	gtk_widget_override_background_color (ventana,GTK_STATE_FLAG_NORMAL,&color);	*/
				
	
	/*Llama al cuerpo de la ventana*/
	cuerpoMochila(ventana);
	iniciarTablaMochila();
	llenarTablaMochila();
	 /* Muestra la ventana principal con todo su contenido */
	gtk_widget_show_all(ventana);		
	 /* Llamada al destructor de la ventana principal */
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	/* Termina la aplicación */
	gtk_main(); 
	
	return 0;
}
	
