#ifndef _FUNCIONESH_
#define _FUNCIONESH_

//Estructura Familia Producto
struct st_familiaProducto
{
	char IdFamilia[64];
	char Descripcion[64];
};

//Estructura Productos
struct st_productos 
{
	char IdProducto[64];
	char Nombre[64];
	char Descripcion[128];
	char Familia[64];
	char Costo[64];
	char Precio[64];
	char stock[64];
};

struct st_cotizaciones
{
	char id[128];
	char estado[128];
	struct st_productos producto[50];
};
//Prototipos del Menu
void VerificarDatosVacios(char * const mensaje,char * const dato);
int opcionesAdministrativas();
void solicitudDatosFamilia();
void NuevoProducto();
void solicitarDatosProductos();
void modificarProductoMenu();
void selecionarFamilia(char * fami);
void valoresIniciales();
void modificarValoresInicialesMenu();
void familiaDeProductos();
void cargarInventarioMenu();
void opcionesGenerales();
void consultaCatalogoMenu();
void cotizacionesMenu();
int verificarProductoRepetidoMenu(char * idProd,char *productos[],char * stock);
void menu();

//Prototipo de ManejoXML
char * tolowercase(char *string);
char *recortar(char *const s);

void leerXmlValoresIniciales(char * const xml);
void ModificarValoresInicialesXML(char * const xml,char * dato, char *nodo);

void agregarFamiliaXML(struct st_familiaProducto * ptr,char * const xml);
void agregarProductoXML(struct st_productos * ptr,char * const xml);
void modificarProductoXML(char * xml, char* dato, char* hijoNom,char* idProd);
void InventarioProductosXML(char * xmlExtra, char * xmlProd);
int busquedaCatalogoXML(char *xml,char * clave, char * resultado[],char * area);


void eliminarHijoXML(char * const identificado,char * const xml,char * hijoNom);

int validarUsuario(char *const usuario,char * const pass);
int validacion(xmlChar * nodoName, xmlChar *valor);

void verFamiliaProductos(char * const xml,char *array[]);

void visualizarFamiliasXML();
void visualizarProductosXML();

int cantidadHijo(char * const xml);




//Prototipos valores iniciales
void mostarValoresIniciales();

//Prototipo Familia Producto
void agregarFamilia(struct st_familiaProducto *ptr);
void eliminarFamilia(char * const ID);
int cantidadHijoFamilia();
void  InventarioProductos(char * xmlExtra);


//Prototipos productos
void agregarProducto(struct st_productos *ptr);
void eliminarProducto(char * IDprod);
int busquedaCatalogoProductos(char * clave, char* resultado[],char *area);

#endif
