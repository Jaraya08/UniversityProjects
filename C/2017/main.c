// Compilacíon : gcc main.c -I/usr/include/libxml2 -lxml2 -o main

//Librerias nativas
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Libreria Libxml2 
#include <libxml/encoding.h>
#include <libxml/parser.h>
#include <libxml/xmlwriter.h>

//Modulos del programa 
#include "manejoXml.h"
#include "ValoresIniciales.h"
#include "familias.h"
#include "Productos.h"
#include "Menu.h"



int main ()
{
	menu();
	return 0;
}
