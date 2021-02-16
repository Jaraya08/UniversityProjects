(*QS World University Rankings SML*)

(*Compilacion : use "C:\\Users\\Jordan Araya\\Desktop\\TC1\\Programa\\Creador.sml"; *)

(*Ubicacion del archivo*)
val pathFile = "C:\\Users\\Jordan Araya\\Desktop\\TC1\\Programa\\QS_Ranking.csv";

(*Funcion printMesage
E: Recibe un string
S: Lo imprime en la consola
R: Ninguna*)
fun printMesage(msj) =
		print(msj);
		
(*Funcion: clearLine
E:Recibe un dato
S:Devuelve un datos vacio para que la estrada del stdin no quede sucia
R:Ninguna*)
fun clearLine dato = 
    let
        val largo = String.size(dato) (*Obtengo el largo del dato*)
        val recorte = String.substring (dato, 0, (largo-1)) (*obtengo el dato hasta la posicion largo-1 es decir sin el salto de linea*)
    in
        recorte
    end;
	
(*Funcion: readFile(fileName)
E:Recibe un nombre de un archivo  
S:Retorna el contenido de ese archivo
R:El archivo debe existir*)
fun readFile(fileName) =
    let 
        val fileOpen = TextIO.openIn fileName
        val content = TextIO.inputAll fileOpen handle e => (TextIO.closeIn fileOpen; raise e)
        val _ = TextIO.closeIn fileOpen
    in 
		content 
    end;  
	
(*Funcion writeFile
E: Recibe un nombre o ubicacion de un archivo 
S: La escritura del datos content en el archivo
R: El dato no puede ser vacio*)
fun writeFile(fileName,content) =
    let 
        val fileOpen = TextIO.openOut fileName
        val _ = TextIO.output (fileOpen, content) handle e => (TextIO.closeOut fileOpen; raise e)
        val _ = TextIO.closeOut fileOpen
    in 
        () 
    end;

(*Funcion: newUniversity_aux
E:Recibe una ruta de archivo
S: Solicita los datos de una nueva universidad
R:Se deben llenar los campos solicitados correctamente*)
fun newUniversity_aux(fileName)=
	let
		val dataFile = readFile(fileName);

        val pos_msj = printMesage("Ingrese la posicion de la universidad: ");
        val v_ranking = valOf(TextIO.inputLine TextIO.stdIn);
        val ranking = clearLine v_ranking;

        val name_msj = printMesage("Ingrese el nombre de la universidad: ");
        val v_name = valOf(TextIO.inputLine TextIO.stdIn);
        val name = clearLine v_name;

        val seg_msj = printMesage("ingrese el nombre del segmento de la universidad: ");
        val v_segment = valOf(TextIO.inputLine TextIO.stdIn);
        val segment = clearLine v_segment;

        val loc_msj = printMesage("Ingrese la localizacion de la universidad: ");
        val v_localization = valOf(TextIO.inputLine TextIO.stdIn);
        val localization = clearLine v_localization;

        val rat_msj = printMesage("Ingrese el rating de la universidad: ");
        val v_rating = valOf(TextIO.inputLine TextIO.stdIn);
        val rating = clearLine v_rating;

        val var_msj = printMesage("Ingrese la variacion de la universidad: ");
        val v_variacion = valOf(TextIO.inputLine TextIO.stdIn);
        val variacion = clearLine v_variacion;
		
        val newLine = ranking ^ "," ^ name ^ "," ^ segment ^ "," ^ localization ^ "," ^ rating ^ "," ^ variacion ^ "\n";

        val addNewValueFile = dataFile ^ newLine;

        val  readFile = writeFile(fileName,addNewValueFile);

        val message = "\nSe ha annadido la universidad " ^ name ^ " satisfactoriamente.\n";
        val prt_message = printMesage(message);
    in
        ()
    end;
	
(*Funcion: newUniversity
E: Ninguna
S:Llama a la Funcion newUniversity_aux
R: Ninguna*)
fun newUniversity() =
	newUniversity_aux(pathFile);

(*Funcion: clearFile
E: Ninguna
S: Limpia todo los datos que tenga el archivo 
R: El Archivo debe existir*)
fun clearFile() = 
    let 
        val deleteData = writeFile(pathFile,"RANKING UNIVERSIDADES,Nombre,Segmento,Localización,Rating,Variacion");
        val masage = printMesage("\n\n*********Los datos han sido borrados satisfactoriamente***********\n\n");
    in
        ()
    end;
	
(*Funcion: menu
E: Un valor
S: llama a la funcion clearFile si se elige 2 y newUniversity si se elige 1
R: Cualquier opcion fuera de esta cierra el programa*)
fun menu(opcion)=
		if opcion = "1"
			then 
				newUniversity()
		else if opcion ="2"
			then 
				clearFile()
		else
			();

(*Funcion main

N: desde aqui se inician todas las funcionalidades el programa*)
fun main()=
	let
		val mensaje = printMesage("Ingrese la opcion que desea realizar\n1-Agregar nueva Universidad\n2-Limpiar archivo\nOpcion:")
		val opcion = valOf(TextIO.inputLine TextIO.stdIn)
		val opcion_rec = clearLine opcion
	in 
		menu(opcion_rec)
	end;