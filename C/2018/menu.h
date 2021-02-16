/* Curso :     Investigación de Operaciones
 * Estudiante: Jordan H. Araya Leiva
 * Carné:      2016254282
 * 
 * 
 * Proyecto Programado #0 : Menú de Programas de Programación Dinámica
 * 
 * INSTRUCCIONES DE COMPILACIÓN
 * 
 * 	Comando 1 para compilar con interfaz gtk.
 *  		--> gcc main.c -o main `pkg-config --cflags --libs gtk+-3.0`  		
 * 	Ejecutar 
 * 			--> ./main 
 * */

/*Include's*/
#include "funciones.h"

int IS_NUM(char num[6])
{
	for(int i=0;num[i]!='\0';i++)
	{
		if(!isdigit(num[i]))
		{
			return 0;
		}
	}
	return 1;
}

void ShowMessage(const char* mensaje, char *titulo)
{
	GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
	GtkWidget  * dialog = gtk_message_dialog_new (NULL,
                                  flags,
                                  GTK_MESSAGE_INFO,
                                  GTK_BUTTONS_OK,
                                  "%s",titulo);
	gtk_message_dialog_format_secondary_text (GTK_MESSAGE_DIALOG (dialog), "%s", mensaje);
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}

/*LLama la ventana del algoritmo de Floyd*/
void rutaMasCortaWin(GtkWidget *widget,gpointer datos) 
{
	winFloyd();
}

void problemaMochilaWin(GtkWidget *widget,gpointer datos)
{
	winMochila();
}

void reemplazoEquiposWin(GtkWidget *widget,gpointer datos)
{
	winRemplazoEquipos();
}

void arbolesBinBusqOptimaWin(GtkWidget *widget,gpointer datos)
{
	winArbonBinario();
}

void seriesDeportivasWin(GtkWidget *widget,gpointer datos)
{
	winSeriesDeportivas();
}

void multiplicacionMatricesWin(GtkWidget *widget,gpointer datos)
{	
	winMultiplicacionMatrices();
}

void cuerpoMenu(GtkWidget *box) /* Crea el cuerpo del formulario */
{
	/* La Tabla para los componentes*/
	GtkWidget *tabla; 
	
	 /* Almacena la tabla de los botones */
	GtkWidget *tButtons;
	
	/* Lista de botones segun su nombre */
	GtkWidget *rutasMasCortas; 
	GtkWidget *problemaMochila;
	GtkWidget *reemplazoEquipos;
	GtkWidget *arbolesBinBusqOptima;
	GtkWidget *seriesDeportivas;
	GtkWidget *multiplicacionMatrices;	
	GtkWidget *salir;	
	GtkWidget *buttonBox;
	
	/* Crea la caja para los botones */
	tButtons = gtk_box_new(TRUE,7); 
	
	/* Mete la caja Tbuttons en la caja principal */
	gtk_container_add(GTK_CONTAINER(box),tButtons); 
	
	tabla =  gtk_grid_new(); /* Crea la tabla */
	
	/* Crea la caja para los botones */
	buttonBox = gtk_box_new(TRUE,10); 
	
	/* Mete la caja de botones en la caja de la tabla */
	gtk_container_add(GTK_CONTAINER(tButtons),buttonBox); 
	
	/* Crea los botones */
	rutasMasCortas = gtk_button_new_with_label("Rutas Óptimas (Algoritmo de Floyd)"); 
	problemaMochila = gtk_button_new_with_label("Problema de la Mochila");
	reemplazoEquipos = gtk_button_new_with_label("Reemplazo de Equipos"); 
	arbolesBinBusqOptima = gtk_button_new_with_label("Árboles Binarios de Búsqueda Óptimos");
	seriesDeportivas = gtk_button_new_with_label("Series Deportivas");
	multiplicacionMatrices = gtk_button_new_with_label("Multiplicación de Matrices");
	salir = gtk_button_new_with_label("Salir");
	
	/* Mete los botones en su caja */
	gtk_box_pack_start(GTK_BOX(buttonBox),rutasMasCortas,TRUE,TRUE,3); 
	gtk_widget_set_tooltip_text(rutasMasCortas, "Rutas Óptimas (Algoritmo de Floyd) Descripcion: Algoritmo utilizado para obtener las rutas mas cortas entre nos nodos de un grafo");
	
	gtk_box_pack_start(GTK_BOX(buttonBox),problemaMochila,TRUE,TRUE,3);
	gtk_widget_set_tooltip_text(problemaMochila, "Problema de la Mochila Descripción: Es un problema de optimización combinatoria, es decir, que busca la mejor solución entre un conjunto finito de posibles soluciones a un problema.");
	
	gtk_box_pack_start(GTK_BOX(buttonBox),reemplazoEquipos,TRUE,TRUE,3);
	gtk_widget_set_tooltip_text(reemplazoEquipos, "Reemplazo de Equipos Descripción: un algoritmo que busca encontrar las plenes optimos de remplazos de equipos en los tiempos adecuados");
	
	gtk_box_pack_start(GTK_BOX(buttonBox),seriesDeportivas,TRUE,TRUE,3);
	gtk_widget_set_tooltip_text(seriesDeportivas, "Series Deportivas Descripción: Un algoritmo utilizo para calcular la probabilidad que tiene un equipo de ganar un partido, dependiendo de las probabilidades que tiene al jugar de visita o local");
	
	gtk_box_pack_start(GTK_BOX(buttonBox),arbolesBinBusqOptima,TRUE,TRUE,3);
	gtk_widget_set_tooltip_text(arbolesBinBusqOptima, "Árboles Binarios de Búsqueda Óptimos Descripción : Algoritmo de promedio mínimo de un árbol con n llaves, balancea el árbol según el promedio y ayuda a optimizar las consultas");
	
	gtk_box_pack_start(GTK_BOX(buttonBox),multiplicacionMatrices,TRUE,TRUE,3);
	gtk_widget_set_tooltip_text(multiplicacionMatrices, "Multiplicación de Matrices Estado: En Construcción");
	
	gtk_box_pack_start(GTK_BOX(buttonBox),salir,TRUE,TRUE,3);
	gtk_widget_set_tooltip_text(salir, "Finalizar el programa");
	
	/* Establece las llamadas para cada boton */
	g_signal_connect(G_OBJECT(rutasMasCortas),"clicked",G_CALLBACK(rutaMasCortaWin),NULL); 
	g_signal_connect(G_OBJECT(problemaMochila),"clicked",G_CALLBACK(problemaMochilaWin),NULL);
	g_signal_connect(G_OBJECT(reemplazoEquipos),"clicked",G_CALLBACK(reemplazoEquiposWin), NULL);
	g_signal_connect(G_OBJECT(arbolesBinBusqOptima),"clicked",G_CALLBACK(arbolesBinBusqOptimaWin),NULL);
	g_signal_connect(G_OBJECT(seriesDeportivas),"clicked",G_CALLBACK(seriesDeportivasWin),NULL);
	g_signal_connect(G_OBJECT(multiplicacionMatrices),"clicked",G_CALLBACK(multiplicacionMatricesWin),NULL);
	g_signal_connect(G_OBJECT(salir),"clicked",G_CALLBACK(gtk_main_quit), NULL);
}

int winMenu(int argc, char *argv[]) /* Función principal del menu*/
{	
	GtkWidget *ventana;
	
	GtkWidget *caja; /* La caja principal */
	
	gtk_init(&argc,&argv); /* Inicializa gtk */
	
	GtkCssProvider *provider = gtk_css_provider_new();
	GdkDisplay *display = gdk_display_get_default();
	GdkScreen *screen = gdk_display_get_default_screen(display);
	GError *error=0;
	gtk_style_context_add_provider_for_screen(screen,GTK_STYLE_PROVIDER(provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	gtk_css_provider_load_from_file(provider,g_file_new_for_path("Archivos css/colores.css"),&error);	
	g_object_unref(provider);
	
	ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);/* Crea la ventana */
		
	gtk_window_set_position(GTK_WINDOW(ventana),GTK_WIN_POS_CENTER); /* Centra la ventana */
		 
	gtk_window_set_title(GTK_WINDOW(ventana),"Menu Principal");/* Añade el titulo de la ventana */
		
	gtk_window_set_default_size(GTK_WINDOW(ventana),400,400); /* Dimensiones de la ventana */
		
	gtk_container_set_border_width(GTK_CONTAINER(ventana),50); /* Establece el borde de la ventana */
		
	caja = gtk_box_new(TRUE,7); /* Crea la caja principal */
		
	gtk_container_add(GTK_CONTAINER(ventana),caja); /* Mete la caja principal en la ventata principal*/
	
	cuerpoMenu(caja); /*Crea la interfaz*/

	gtk_widget_show_all(ventana); /* Muestra la ventana principal con todo su contenido */
	
	g_signal_connect(ventana,"destroy",G_CALLBACK(gtk_main_quit),NULL); /* Llamada al destructor de la ventana principal */

	gtk_main(); /* Termina la aplicación */
	
	return 0;	
}

