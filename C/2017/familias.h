#include "Funciones.h"

void agregarFamilia(struct st_familiaProducto *ptr)
{
	agregarFamiliaXML(ptr,"FamiliaProductos.xml");
}
void eliminarFamilia(char * const ID)
{
	eliminarHijoXML(ID,"FamiliaProductos.xml","ID");
}
int cantidadHijoFamilia()
{
	return cantidadHijo("FamiliaProductos.xml");
}



