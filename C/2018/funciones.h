#ifndef _FUNCIONESH_
#define _FUNCIONESH_

struct st_GT
{
	char GT[8];
	int valor;
	int menores[8];
	int cantMenores;
};
struct st_costosAnuales
{
	char costo[1024];	
};

/*Funciones del Menu*/
int IS_NUM(char num[6]);
void ShowMessage(const char* mensaje, char *titulo);
void rutaMasCortaWin(GtkWidget *widget,gpointer datos) ;
void cuerpoMenu(GtkWidget *box);
int menu(int argc, char *argv[]);

/*Funciones Rutas mas Cortas*/
void formarMatriz(int tam,char *grafo,int matriz[][tam]);
void helpMessage(GtkWidget *widget,gpointer datos);
void cuerpoFloyd(GtkWidget *box);
int winFloyd();

/*Funciones Mochila*/
int winMochila();
void limpiarCampos();
void mostarTablasMochila(char nombre[],int max, int cap, int n, int matrizM[cap][n],char matrizC[cap][n],char matrizO[n][3][18],int matrizN[cap][n]);
int existeMochila(char mochila[]);
void SelectedChangedMochila(GtkWidget *gTable,gpointer dato) ;
int validarMochila(GtkWidget *entry,gpointer puntero);
int validarObjeto(GtkWidget *entry,gpointer puntero);
int mostrarChooseFile(GtkWidget * button,gpointer ventana);
int ValidarValor(GtkWidget *entry,gpointer puntero);
int validarPeso(GtkWidget *entry,gpointer puntero);
int ValidarPesoMochila(GtkWidget *entry,gpointer puntero);
void mostrarArchivoCargado(GtkWidget * button,gpointer ventana);
void cargarDatos(char archivo[]);
int validarRestObjetos(GtkWidget *entry,gpointer puntero);
int gTextBoxVisible(GtkWidget *entry,gpointer puntero);


/*Funciones remplazo equipos*/
int winRemplazoEquipos();

/*Funciones Series Deportivas*/
int winSeriesDeportivas();
int algoritmoSD(int tam,int n,char formato[], float matrizM[tam+1][tam+1], char matrizC[tam+1][tam+1],float f_Ph, float f_Pr);
void mostrarTablaSD(char formato[64],char juego[],int tam, int n, float matrizM[tam+1][tam+1],char matrizC[tam+1][tam+1],char equipo1[],char equipo2[],float Ph, float Pr);

/*Funciones arboles binarios de busqueda optimo*/
int winArbonBinario();
int gTextBoxVisibleAB(GtkWidget *entry,gpointer puntero);
void mostrarTablaAB (float total,int n,float matrizA[n+1][n+1],int matrizR[n+1][n+1],char matrizC[n+1][n+1],float probabilidades[],char array[n][2][12],char arbol[]);

/*Multiplicacion de matrices*/
int winMultiplicacionMatrices();
void mostrarTablaMM (int n,float matrizM[n+1][n+1],int matrizR[n+1][n+1],char matrizC[n+1][n+1],int array[n][2],char matriz[]);
#endif
