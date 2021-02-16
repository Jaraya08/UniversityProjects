#include "Funciones.h"

void mostarValoresIniciales()
{
	leerXmlValoresIniciales("valoresIniciales.xml");
}

void modificarValoresIniciales(char * const data,char * const nodo)
{
	ModificarValoresInicialesXML("valoresIniciales.xml",data,nodo);
}
