#include "Funciones.h"

/*Funcion : es_numero(char * str)
 * E:recibe una cadera de caracteres
 * S:1 = si la cadena solo contiene numero, 0 = si almenos un caracter no es numero
 * R:la entrada debe ser numerica
 * */
int es_numero(char * str)
{
	int res=0;
	char numero[128];
	strcpy(numero,str);
	for(int i = 0;numero[i]!='\0';i++)
	{
		if(isdigit(numero[i]))
		{
			res=1;
		}
	}
	return res;
}
/*Funcion : tolowercase(char *string)
 * E: Recibe una cadena de carateres 
 * S:Retorna la misma cadena de carateres con todas las letras minusculas
 * R:Ninguna
 * */
char * tolowercase(char *string)
{
	char array[128];
	strcpy(array,string);
	for(int i =0;array[i]!='\0';i++)
	{
		array[i]=tolower(array[i]);
	}
	sprintf(string,"%s",array);
	return string;
}
/*Funcion:  validarArchicoXML(char * archivo)
 * E: Un archivo de cualquier extención
 * S: Retorna 1 si el documentos se puedo abrir Y retorna 0 si el documentos no se puedo abrir
 * R: El documentos debe existir
 * */
int validarArchicoXML(char * archivo)
{
	FILE *xml;
	xml =fopen(archivo,"r");
	if(xml)
	{
		fclose(xml);
		return 1;
	}
	return 0;
} 

/* Funcion: Recortar(char *s)
 * E: Recibe un char* para quitarle todos los espacios
 * S: Retorna un char* sin espacio 
 * */
char *recortar(char *const s)
{
	char *start = s; 

	//Nos comemos los espacios al inicio 
	while(*start && isspace(*start))  

		++start;

	char *i = start;
	char *end = start;

	//Nos comemos los espacios al final
	while(*i)  
	{
		if(!isspace(*(i++)))
			end = i;
	}
	
	//Escribimos el terminados 
  *end = 0;
  
  return start;
}

/* Funcion leerXml()
 * E: Recibe un char * con el nombre del archivo.XML que se va a leer 
 * S: Informacion dentro del XML
 * */
void leerXmlValoresIniciales(char * const xml)
{
	// puntero de memoria para almacenar el xml	
	xmlDoc *documento;
	
	// punteros para almacenar la raiz y los hijos
    xmlNode *raiz, *primer_hijo;
    
    // metodo para leer el archivo y asignarlo a la memoria. 
	documento = xmlReadFile(xml, NULL, 0); 
	
	// leer la raiz del archivo xml
	raiz = xmlDocGetRootElement(documento);
	
	// se le asigana a primer_hijo todos los hijos de la raiz
	primer_hijo = raiz->children; 	

	xmlNode *hijo; 
	xmlChar *valor;
		
	for(hijo = primer_hijo;hijo;hijo = hijo->next)
	{
		
		// ignora los nodos vacios de tipo 3 (text)
		if ( (hijo->type==3) && (strlen(recortar((char*)xmlNodeGetContent(hijo)))==0))
			continue;
			
		valor = xmlNodeGetContent(hijo);
		printf("***%s : %s\n", hijo->name, recortar((char*)valor)); 		 
	}
}

/*Funcion : ModificarValoresInicialesXML(char * const  xml)
 * E:Recibe el nombre del XML valoresIniciales.xml
 * S:Editar/Escribir los datos iniciales
 * R:
 * */
void ModificarValoresInicialesXML(char * const xml,char * dato, char *nodo)
{
	xmlDoc *documento;
	
	xmlNode *raiz,*hijo;
	
	documento=xmlReadFile(xml,NULL,0);
	
	raiz=xmlDocGetRootElement(documento);
	
	for(hijo = raiz->children;hijo;hijo=hijo->next)
	{
		// ignora los nodos vacios de tipo 3 (text)
		if ( (hijo->type==3) && (strlen(recortar((char*)xmlNodeGetContent(hijo)))==0))
			continue;
			
		if(xmlStrEqual(hijo->name,(xmlChar*)nodo))
		{
			xmlNodeSetContent(hijo,dato);
		}
	}
	xmlSaveFile(xml,documento);
	xmlFreeDoc(documento);
}

/*Funcion: escribirXMLFamiliaProductos(struct familiaProducto * ptr,char * const xml)
 * E:Recibe un puntero de memoria donde esta datos de tipo struct familiaProducto y el nombre del archivo FamiliaProductos.xml
 * S:Agregar una nueva Familia de productos
 * R:La Familia no debe estar registrada (nombre y descripcion)
 * */
void agregarFamiliaXML(struct st_familiaProducto * ptr,char * const xml)
{
	// puntero de memoria para almacenar el xml
	xmlDoc *documento; 	
	
	// punteros para almacenar la raiz y los hijos
    xmlNode *raiz,*padre;	
    
     // metodo para leer el archivo y asignarlo a la memoria.
	documento = xmlReadFile(xml, NULL, 0);    
	
	// leer la raiz del archivo xml
	raiz = xmlDocGetRootElement(documento);	

	// se crea un hijo para insertarlo en la raiz
	padre = xmlNewNode(NULL, BAD_CAST "Familia");	
		
	//se agrega el hizo en la raiz
    xmlAddChild(raiz,padre);	

	//se crean dos hijos para ser insertados en la raiz
    xmlNodePtr ID = xmlNewNode(NULL, BAD_CAST "ID");
    xmlNodePtr Descripcion = xmlNewNode(NULL, BAD_CAST "Descripcion");
    
    // Se insertan los hijos al padre
    xmlAddChild(padre,ID);   
    xmlAddChild(padre,Descripcion);  

	//se agregan los valor a los hijos
    xmlAddChild(ID, xmlNewText(BAD_CAST ptr->IdFamilia));  
    xmlAddChild(Descripcion, xmlNewText(BAD_CAST ptr->Descripcion));

	//se guarda el documento con los nuevos datos
    xmlSaveFile(xml,documento);    
	
	//se liberá la memoria
	xmlFreeDoc(documento);    

}

/*Funcion: eliminarFamiliaXML(char * const identificado,char * const xml)
 * E:Un numero de identificacion del producto y el nombre del archivo FamiliaProductos.xml
 * S:Eliminar la familia del producto del identificador ingresado
 * R:La familia del produtos no puede ser eliminada si esta asosiada a un producto  
 * */
void eliminarHijoXML(char * const identificado,char * const xml,char * hijoNom)
{
	// leer la raiz del archivo xml
	xmlDoc *documento;

	// punteros para almacenar la raiz y los hijos
    xmlNode *raiz, *subhijos,*hijo; 
    
    // metodo para leer el archivo y asignarlo a la memoria.
	documento = xmlReadFile(xml, NULL, 0); 
	
	// leer la raiz del archivo xml
	raiz = xmlDocGetRootElement(documento); 
	 	
	for(hijo =raiz->children ;hijo;hijo=hijo->next)
	{
		
		// ignora los nodos vacios de tipo 3 (text)
		if ((hijo->type==3) && (strlen(recortar((char*)xmlNodeGetContent(hijo)))==0))
			continue;
		for(subhijos=hijo->children;subhijos;subhijos=subhijos->next)
		{
			
			// ignora los nodos vacios de tipo 3 (text)
			if ((subhijos->type==3) && (strlen(recortar((char*)xmlNodeGetContent(subhijos)))==0))
				continue;
				
			if(xmlStrEqual(subhijos->name,(xmlChar*)hijoNom))
			{
				xmlChar* xml_str = xmlNodeGetContent(subhijos);
				if(xmlStrEqual(xml_str,(xmlChar*)identificado))
				{
					xmlUnlinkNode(hijo);
					xmlFreeNode(hijo);
					break;
				}	
			}					
		}
	}
	//se guarda el documento con los nuevos datos
    xmlSaveFormatFile(xml,documento,0);	

	//se liberá la memoria
	xmlFreeDoc(documento);    
}

/*Funcion: agregarProducto(st_productos * ptr,char * const xml)
 * E. Recibe una estructura de tipo st_productos y el nombre de un archivo XML
 * R: Guardar un nuevo producto dentro del XML 
 * R: El producto no de debe existir
 * */
void agregarProductoXML(struct st_productos * ptr,char * const xml)
{
	// puntero de memoria para almacenar el xml
	xmlDoc *documento; 
		
	// punteros para almacenar la raiz y los hijos
    xmlNode *raiz,*padre;
    
    // metodo para leer el archivo y asignarlo a la memoria.
	documento = xmlReadFile(xml, NULL, 0);
	
	// leer la raiz del archivo xml
	
	raiz = xmlDocGetRootElement(documento);	

	// se crea un hijo para insertarlo en la raiz
	padre = xmlNewNode(NULL, BAD_CAST "producto");	
	
	//se agrega el hizo en la raiz
    xmlAddChild(raiz,padre);	

	//se crean los subhijos  para ser insertados en el padre
    xmlNodePtr ID = xmlNewNode(NULL, BAD_CAST "Id");
    xmlNodePtr Nombre = xmlNewNode(NULL, BAD_CAST "nombre");
    xmlNodePtr Descripcion = xmlNewNode(NULL, BAD_CAST "descripcion");
    xmlNodePtr Fam = xmlNewNode(NULL, BAD_CAST "familia");
    xmlNodePtr precioC = xmlNewNode(NULL, BAD_CAST "precioCosto");
    xmlNodePtr precioV = xmlNewNode(NULL, BAD_CAST "precioVenta");
    xmlNodePtr stock = xmlNewNode(NULL, BAD_CAST "stock");
   
    // se insertan los hijos en el padre
    xmlAddChild(padre,ID);	   
    xmlAddChild(padre,Nombre);
    xmlAddChild(padre,Descripcion);	      
    xmlAddChild(padre,Fam);  
    xmlAddChild(padre,precioC);   
    xmlAddChild(padre,precioV);   
    xmlAddChild(padre,stock);

	//Se agregar los valores que viene en la struct productos segun corresponda
    xmlAddChild(ID, xmlNewText(BAD_CAST ptr->IdProducto));    
    xmlAddChild(Nombre, xmlNewText(BAD_CAST ptr->Nombre)); 
	xmlAddChild(Descripcion, xmlNewText(BAD_CAST ptr->Descripcion));    
	xmlAddChild(Fam, xmlNewText(BAD_CAST ptr->Familia));       
	xmlAddChild(precioC, xmlNewText(BAD_CAST ptr->Costo));    
	xmlAddChild(precioV, xmlNewText(BAD_CAST ptr->Precio));    
	xmlAddChild(stock, xmlNewText(BAD_CAST ptr->stock));    
    
    //se guarda el documento con los nuevos datos
    xmlSaveFile(xml,documento);
    
    //se liberá la memoria;
	xmlFreeDoc(documento);    
}

void modificarProductoXML(char * xml, char* dato, char* hijoNom,char* idProd)
{
	printf("Dato Entrante %s\n",dato);
	// puntero de memoria para almacenar el xml
	xmlDoc *documento;
	
	// punteros para almacenar la raiz y los hijos
	xmlNode *raiz,*hijo,*subhijos;
	
    // metodo para leer el archivo y asignarlo a la memoria.
	documento=xmlReadFile(xml,NULL,0);

    // metodo para leer el archivo y asignarlo a la memoria.	
	raiz=xmlDocGetRootElement(documento);
	
	for(hijo = raiz->children;hijo;hijo=hijo->next)
	{
		// ignora los nodos vacios de tipo 3 (text)
		if ( (hijo->type==3) && (strlen(recortar((char*)xmlNodeGetContent(hijo)))==0))
			continue;
		for(subhijos=hijo->children;subhijos;subhijos=subhijos->next)
		{
			// ignora los nodos vacios de tipo 3 (text)
			if ( (subhijos->type==3) && (strlen(recortar((char*)xmlNodeGetContent(subhijos)))==0))
				continue;
			if(xmlStrEqual(subhijos->name,(xmlChar*)"Id"))
			{
				xmlChar* id = xmlNodeGetContent(subhijos);
				if(xmlStrEqual(id,(xmlChar*)idProd))
				{
					while(subhijos)
					{						
						if(xmlStrEqual(subhijos->name,(xmlChar*)hijoNom))
						{							
							xmlNodeSetContent(subhijos,dato);
							break;
						}
						subhijos=subhijos->next;
					}
				}
			}
			continue;
		}
	}
    //se guarda el documento con los nuevos datos
	xmlSaveFile(xml,documento);
	
    //se liberá la memoria;
	xmlFreeDoc(documento);
}

void InventarioProductosXML(char * xmlExtra, char * xmlProd)
{
	xmlDoc  *documentoExtra,*documento;
	
	//Leemos el xml productos y el xml cargados
	documentoExtra=xmlReadFile(xmlExtra,NULL,0);
	documento = xmlReadFile(xmlProd,NULL,0);

	xmlNode *raizExtra,*raiz;

	//Extraemos las raices
	raizExtra=xmlDocGetRootElement(documentoExtra);
	raiz = xmlDocGetRootElement(documento);
	//obtenemos la cantidad de hijos que tiene cada xml
	int cantExtra = cantidadHijo(xmlExtra),cant = cantidadHijo(xmlProd);
	
	//Obtenemos en una lista los datos que contiene el XML
	char *listaExtra[cantExtra*2];
	char *listaProd[cant*7];
	verFamiliaProductos(xmlExtra,listaExtra);
	verFamiliaProductos(xmlProd,listaProd);
	
	int i,j,suma;
	char res[64];
	printf("\n");
	printf("*********INFORME DE RESULTADOS DE LA CARGA DE STOCK*********\n");
	printf("\n");
	for(i=0;i<cantExtra*2;i+=2)
	{
		for(j=0;j<cant*7;j+=7)
		{
			if(!strcmp(listaExtra[i],listaProd[j]))
			{
				suma=atoi(listaExtra[i+1])+atoi(listaProd[j+6]);
				sprintf(res,"%d",suma);
				modificarProductoXML(xmlProd,res,"stock",recortar(listaExtra[i]));
				continue;
			}
		}
	}
	//Liberamos la memoria
	xmlFreeDoc(documentoExtra);
	xmlFreeDoc(documento);
}

/*Funcion: validarUsuario(char *const usuario,char * const pass)
 * E: recibe el nombre de usuario y contraseña 
 * S: 0 = Usuario no Autorizado ; 1= Usuario Autorizado
 * R: Usuario y contraseña deben coincidir
 * */
 
int validarUsuario(char *const usuario,char * const pass)
{
	if(validacion((xmlChar*)"Usuario",(xmlChar*)usuario) & validacion((xmlChar*)"Usuario",(xmlChar*)usuario))
	{
		return 1;
	}
		return 0;
}

/*Funcion: validacion(xmlChar * nodoName, xmlChar *valor)
 * E: recibe un nombre de nodo y un valor 
 * S: verifica que los dos valores sean iguales
 * R: los valores tiene que ser iguales 
 * */
int validacion(xmlChar * nodoName, xmlChar *valor)
{
	// puntero de memoria para almacenar el xml
	xmlDoc *documento; 	

	// punteros para almacenar la raiz y los hijos
    xmlNode *raiz,*hijo; 	
    
    // metodo para leer el archivo y asignarlo a la memoria.
	documento = xmlReadFile("valoresIniciales.xml", NULL, 0);     
	
	// leer la raiz del archivo xml
	raiz = xmlDocGetRootElement(documento);	
	
	int acceso = 0;
	
	for(hijo = raiz->children;hijo;hijo=hijo->next)
	{
		if(xmlStrEqual(hijo->name,nodoName))
		{
			xmlChar* attrValue = xmlNodeGetContent(hijo); 	
			if(xmlStrEqual(attrValue,valor))
			{
				acceso=1;
				return acceso;
			}
		}
	}
	//se liberá la memoria
	xmlFreeDoc(documento);   

	return acceso;
}

/*Funcion: verFamiliaProductos(char * const xml,char *array[])
 * E: Recibe un archivo xml y una arreglo de string
 * S: Imprime todas las Familias disponibles
 * R: Deben Existir al menos 1 familia
 * */
void verFamiliaProductos(char * const xml,char *array[])
{
	// puntero de memoria para almacenar el xml
	xmlDoc *documento;
	
	// punteros para almacenar la raiz y los hijos
	xmlNode *raiz,*hijo,*subhijos;
	
    // metodo para leer el archivo y asignarlo a la memoria.
	documento=xmlReadFile(xml,NULL,0);

    // metodo para leer el archivo y asignarlo a la memoria.	
	raiz=xmlDocGetRootElement(documento);
	
	int i=0;
	for(hijo = raiz->children;hijo;hijo=hijo->next)
	{
		xmlNode * subhijos;
		for(subhijos=hijo->children;subhijos;subhijos=subhijos->next)
		{
			if ((subhijos->type==3) && (strlen(recortar((char*)xmlNodeGetContent(subhijos)))==0))// ignora los nodos vacios de tipo 3 (text)
			continue;
			xmlChar* valor = xmlNodeGetContent(subhijos);
			recortar(valor);
			array[i]=valor;
			i++;
		}
	}
	//se liberá la memoria
	xmlFreeDoc(documento);    
}

int busquedaCatalogoXML(char *xml,char * clave, char * resultado[],char * area)
{
	xmlDoc *documento;
	
	xmlNode *raiz,*hijo,*subhijos,*temp;
	
	documento=xmlReadFile(xml,NULL,0);
	
	raiz=xmlDocGetRootElement(documento);
	int i=0,cant=cantidadHijo(xml);
	if(!strcmp(clave,""))
	{
		i=cant*7;
		verFamiliaProductos(xml,resultado);
	}
	else
	{
		for (hijo=raiz->children;hijo;hijo=hijo->next)
		{
			// ignora los nodos vacios de tipo 3 (text)
			if ((hijo->type==3) && (strlen(recortar((char*)xmlNodeGetContent(hijo)))==0))
				continue;
			
			for(subhijos=hijo->children;subhijos;subhijos=subhijos->next)
			{
				// ignora los nodos vacios de tipo 3 (text)
				if ((subhijos->type==3) && (strlen(recortar((char*)xmlNodeGetContent(subhijos)))==0))
				continue;
				
				int esta=0;
				
				for(temp=subhijos;temp;temp=temp->next)
				{
					if ((temp->type==3) && (strlen(recortar((char*)xmlNodeGetContent(temp)))==0))
						continue;
					xmlChar *valor = xmlNodeGetContent(temp);
					if(strstr(tolowercase(recortar((char*)valor)),tolowercase(clave)))
					{
						esta=1;
						break;
					}
				}
				if(esta)
				{
					int j=i;
					for(temp=subhijos;temp;temp=temp->next)
					{
						if ((temp->type==3) && (strlen(recortar((char*)xmlNodeGetContent(temp)))==0))
							continue;
						xmlChar *valor = xmlNodeGetContent(temp);
						recortar(valor);
						resultado[j]=valor;
						j++;
					}
					i+=7;
				}
				break;
			}
			continue;		
		}
	}
	int k=1;
	i/=7;
	printf("\n");
	printf("\n");

	if(!strcmp(recortar(area),"catalogo"))
	{
		printf("[Linea - ID- Nombre -Descripcion - Familia - Costo-Precio - Precio Venta - stock]\n");
		printf("\n");
		for(int m=0;m<cant*i;m+=7)
		{
			printf("[%d %s - %s - %s - %s - %s - %s]\n",k,resultado[m],resultado[m+1],resultado[m+2],resultado[m+3],resultado[m+4],resultado[m+6]);
			k++;
		}
	}
	else
	{
		printf("[Linea - ID- Nombre -Descripcion - Familia - Costo-Precio - Precio Venta]\n");
		printf("\n");
		for(int m=0;m<cant*i;m+=7)
		{
			printf("[%d %s - %s - %s - %s - %s]\n",k,resultado[m],resultado[m+1],resultado[m+2],resultado[m+3],resultado[m+4]);
			k++;
		}
	}
		
	
	xmlFreeDoc(documento);
	return 0;
}
void cotizacionesXML()
{
	xmlDoc *documento;
	
	xmlNode *raiz,*hijo,*subhijos;
	
	documento=xmlReadFile("cotizaciones.xml",NULL,0);
	
	raiz = xmlDocGetRootElement(documento);
	
	for(hijo=raiz->children;hijo;hijo=hijo->next)
	{
		if ((hijo->type==3) && (strlen(recortar((char*)xmlNodeGetContent(hijo)))==0))
			continue;
			
		for(subhijos=hijo->children;subhijos;subhijos=subhijos->next)
		{
			xmlAttr* atributo = subhijos->properties;
			while(atributo)
			{
				xmlChar* value=xmlGetProp(subhijos, atributo->name);
				printf("Atributo: %s Valor : %s\n",atributo->name,value);
				atributo=atributo->next;
			}
		}
	}
}

void escribirCotizacion()
{
	
	// puntero de memoria para almacenar el xml
	xmlDoc *documento; 	
	
	// punteros para almacenar la raiz y los hijos
    xmlNode *raiz,*padre;	
    
     // metodo para leer el archivo y asignarlo a la memoria.
	documento = xmlReadFile("cotizaciones.xml", NULL, 0);    
	
	// leer la raiz del archivo xml
	raiz = xmlDocGetRootElement(documento);	

	// se crea un hijo para insertarlo en la raiz
	padre = xmlNewNode(NULL, BAD_CAST "cotizacion");
	
	xmlNewProp(padre,"id","2");
	xmlNewProp(padre,"estado","pendiente");
		
	//se agrega el hizo en la raiz
    xmlAddChild(raiz,padre);	

	//se crean dos hijos para ser insertados en la raiz
    xmlNodePtr prod = xmlNewNode(NULL, BAD_CAST "producto");
   	xmlNewProp(prod,"id","AT09");
   	xmlNewProp(prod,"nomre","Atun");
   	xmlNewProp(prod,"descripcion","Tesoro del Mar");
   	xmlNewProp(prod,"costo","1230");
   	xmlNewProp(prod,"venta","1500");
   	xmlNewProp(prod,"cantidad","2");

    // Se insertan los hijos al padre
    xmlAddChild(padre,prod);   

	//se guarda el documento con los nuevos datos
    xmlSaveFile("cotizaciones.xml",documento);    
	
	//se liberá la memoria
	xmlFreeDoc(documento);    
}
/*Funcion cantidadHijo(char * const xml)
 * E: un Archivo XML
 * S: La cantidad de hijos que contiene ese xml
 * R: el Xml debe existir
 * */
int cantidadHijo(char * const xml)
{
	// puntero de memoria para almacenar el xml
	xmlDoc *documento;
	
	//puntero de memoria para asignar raiz e hijos	
	xmlNode *raiz,*hijo;
	
    // metodo para leer el archivo y asignarlo a la memoria.
	documento = xmlReadFile(xml,NULL,0);
	
	// leer la raiz del archivo xml
	raiz = xmlDocGetRootElement(documento);
	
	int count=0;
	hijo=raiz->children;
	for(hijo=raiz->children;hijo;hijo=hijo->next)
	{
		
		// ignora los nodos vacios de tipo 3 (text)
		if ((hijo->type==3) && (strlen(recortar((char*)xmlNodeGetContent(hijo)))==0))
			continue;
		count++;
	}
	 //se liberá la memoria
	xmlFreeDoc(documento); 
	  
	return count;
}

/*Funcion : visualizarFamiliasXML()
 * E: Ninguna
 * S: Impirmie todas las familias disponibles
 * R: Deben existir Familias
 * */
void visualizarFamiliasXML()
{
	// puntero de memoria para almacenar el xml
	xmlDoc *documento;
	
	//puntero de memoria para asignar raiz e hijos
	xmlNode *raiz,*hijo,*subhijos;
	
    // metodo para leer el archivo y asignarlo a la memoria.
	documento = xmlReadFile("FamiliaProductos.xml",NULL,0);
	
	// leer la raiz del archivo xml
	raiz = xmlDocGetRootElement(documento);
	
	//Se saca la cantidad de hijos que tiene el xml.
	int cant = cantidadHijo("FamiliaProductos.xml");
	
	char *familias[cant*2];
	int i=0;
	for (hijo=raiz->children;hijo;hijo=hijo->next)
	{
		
		// ignora los nodos vacios de tipo 3 (text)
		if ((hijo->type==3) && (strlen(recortar((char*)xmlNodeGetContent(hijo)))==0))
			continue;
		
		for(subhijos=hijo->children;subhijos;subhijos=subhijos->next)
		{
			
			// ignora los nodos vacios de tipo 3 (text)
			if ((subhijos->type==3) && (strlen(recortar((char*)xmlNodeGetContent(subhijos)))==0))
			continue;
			xmlChar *valor = xmlNodeGetContent(subhijos);
			recortar(valor);
			familias[i]=valor;
			i++;
		}
	}
	int k=1;
	printf("[Linea - Identidicador -Nombre Familia]\n");
	printf("\n");
	for(int j = 0;j<cant*2;j+=2)
	{
		printf("[%d - %s - %s]\n",k,familias[j],familias[j+1]);
		k++;
	}
	xmlFreeDoc(documento);
}

/*Funcion: visualizarProductosXML()
 * E:Ninguna
 * S:Impresion de los productos disponibles 
 * R:deben exisitir productos
 * */
void visualizarProductosXML()
{
	// puntero de memoria para almacenar el xml
	xmlDoc *documento;

	//puntero de memoria para asignar raiz e hijos
	xmlNode *raiz,*hijo,*subhijos;
	
    // metodo para leer el archivo y asignarlo a la memoria.
	documento = xmlReadFile("productos.xml",NULL,0);
	
	// leer la raiz del archivo xml
	raiz = xmlDocGetRootElement(documento);
	
	//saca la cantidad de hijos del Xml
	int cant = cantidadHijo("productos.xml");
	
	char *familias[cant*7];
	int i=0;
	for (hijo=raiz->children;hijo;hijo=hijo->next)
	{
		
		// ignora los nodos vacios de tipo 3 (text)
		if ((hijo->type==3) && (strlen(recortar((char*)xmlNodeGetContent(hijo)))==0))
			continue;
		
		for(subhijos=hijo->children;subhijos;subhijos=subhijos->next)
		{
			
			// ignora los nodos vacios de tipo 3 (text)
			if ((subhijos->type==3) && (strlen(recortar((char*)xmlNodeGetContent(subhijos)))==0))
			continue;
			
			xmlChar *valor = xmlNodeGetContent(subhijos);
			recortar(valor);
			familias[i]=valor;
			i++;
		}
	}
	int k=1;
	printf("\n");
	printf("[Linea - ID- Nombre -Descripcion - Familia - Costo-Precio - Precio Venta - Stock]\n");
	printf("\n");
	for(int j = 0;j<cant*7;j+=7)
	{
		printf("[%d - %s - %s - %s - %s - %s - %s - %s]\n",k,familias[j],familias[j+1],familias[j+2],familias[j+3],familias[j+4],familias[j+5],familias[j+6]);
		k++;
	}
	xmlFreeDoc(documento);
}

