#include "Funciones.h"

void agregarProducto(struct st_productos *ptr)
{
	agregarProductoXML(ptr,"productos.xml");
}

void eliminarProducto(char * IDprod)
{
	eliminarHijoXML(IDprod,"productos.xml","Id");
}

void modificarProducto(char * dato, char * nodoNom,char * idprod)
{
	modificarProductoXML("productos.xml",dato,nodoNom,idprod);
}

int cantidadHijoProducto()
{
	return cantidadHijo("productos.xml");
}

void  InventarioProductos(char * xmlExtra)
{
	InventarioProductosXML(xmlExtra,"productos.xml");
}
int busquedaCatalogoProductos(char * clave, char* resultado[],char *area)
{
	return busquedaCatalogoXML("productos.xml",clave,resultado,area);
}
