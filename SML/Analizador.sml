(*Compilacion : use "C:\\Users\\Jordan Araya\\Desktop\\TC1\\Programa\\Analizador.sml"; *)
(*C:\Users\Jordan Araya\Desktop\TC1\Programa\QS_Ranking.csv*)


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
        val content = TextIO.inputAll fileOpen
        val _ = TextIO.closeIn fileOpen
    in 
		String.tokens (fn c => c = #"\n") content (*List.last(nombreLista), se utiliza para obtener el final*)
    end;  
	
(*Funcion writeFile
E: Recibe un nombre o ubicacion de un archivo 
S: La escritura del datos content en el archivo
R: El dato no puede ser vacio*)
fun writeFile(fileName,content) =
    let 
        val fileOpen = TextIO.openOut fileName
        val _ = TextIO.output (fileOpen, content)
        val _ = TextIO.closeOut fileOpen
    in 
        () 
    end;
(*
Funcion:dataMatrix
E: un string con formato []
S: formato Lista
R: Tiene que ser formato string []
*)	
fun dataMatrix(dataFile)=
	String.tokens (fn c => c = #",") dataFile;

(*Funcion:createMatrix
E:dataFile = todos los datos del txt, newList= matriz vacia, largo de la lista y el indice
S:una matrix con todos los datos del txt
R: Txt debe tener datos
*)	
fun createMatrix(dataFile,newList,len,i) = 
    if i=len then newList
    else(
        let
            val newElement = List.nth(dataFile,i)(*Método que obtiene un elemento de la lista por su índice*)
            val strList = dataMatrix(newElement)(*Crea listas en donde encuentre ,*)
            val concatList = newList @ [strList](*Concatenación*)
        in
            createMatrix(dataFile,concatList,len,i+1)
        end);
(*
Funcion getDataFile
E:un arhivo
S: los datos de ese archivo en forma de matriz
R: el archivo debe existir
*)		
fun getDataFile(fileName)= (*Saca Los datos del TXT dentro de una lista de lista (matriz)*)
	let
        val dataFile = readFile(fileName) : string list(*Lo lee, pero con una lista, formando un elemento cuando se encuentra un\n*)
        val n_matriz = [[]] : string list list (*Creación de la matriz*)
        val len = List.length(dataFile) (*Obteniendo el largo de la cantidad de lista*)
        val matriz = createMatrix(dataFile,n_matriz,len,0)(*Método que retorna la matriz formada*)
        (*Se cortan para eliminar una lista vacía y las especificaciones de lo que se obtiene*)
        val deletePos = tl matriz
        val deletePos1 = tl deletePos
    in
        (*Retorna la matriz completa*)
        deletePos1
    end;
	
(*
Funcion deleteElemet
E:Eliminar un elemento de una lista en a posicion if
S: Una nueva lista sin el valor que estana en if
R: la lista debe tener valores
*)	
fun deleteElemet(matriz,i)=
		List.take(matriz,i)@List.drop(matriz,i+1);
(*
Funcion printDatasAux
E:una lista 
S: La impresion de esos valores de la lista en forma tabular
R: La lista debe tener valores
*)
fun printDatasAux(lista)=
	let
		val Ranking = "Ranking = " ^ List.nth(lista,0) ^ "  ||  "
		val Nombre = "Nombre = " ^ List.nth(lista,1) ^ "  ||  "
		val Segmento = "Segmento = "^ List.nth(lista,2) ^"  ||  "
		val Localizacion = "Localizacion = "^List.nth(lista,3) ^ "  ||  "
		val Rating = "Rating = "^List.nth(lista,4) ^ "  ||  "
		val Variacion = "Variacion = "^List.nth(lista,5)^"\n"
		val all = Ranking^Nombre^Segmento^Localizacion^Rating^Variacion
	in
		printMesage(all)
	end;
	
(*
Funcion printDatas
E:una matriz y un indice
S: la impresiono de la informacion de todas las sublistas
R: la Matriz debe tener sub listas
*)
fun printDatas(matriz,i)=
	if(i=List.length(matriz))
		then
			()
	else
		let
			val datos = printDatasAux(List.nth(matriz,i))
		in
			printDatas(matriz,i+1)
		end;

(*
Funcion matrixSortMax
E: un elemento , una matriz y un indice
S: Verifica si el elemento es el mayor de la lista
R: El elemento debe existir
*)
fun matrixSortMax(element,matriz,i):bool=
	if(i=List.length(matriz))
		then
			true
	else
		let
			val lista = List.nth(matriz,i)
			val ranking = List.nth(lista,0)
			val valor:int = valOf (Int.fromString ranking)
		in
			if (element<=valor)
				then 
					matrixSortMax(element,matriz,i+1)
			else
				false
		end;
(*
Funcion matrixSortAsc
E: una matriz una matriz vacia y un indice
S: la matriz ordenada Ascendente oor ranking
*)		
fun matrixSortAsc(matriz,res,i)=
	if (i=List.length(matriz))
		then res
	else

		if(matrixSortMax(	valOf (Int.fromString(List.nth(List.nth(matriz,i),0))),matriz,0))
			then	
				matrixSortAsc(deleteElemet(matriz,i),res@[List.nth(matriz,i)],0)
		else
			matrixSortAsc(matriz,res,i+1);
	
(*
Funcion rankingAsc
E: una mtriz
S: la matriz ordenada por el ranking
R: la matriz debe tener mas de un elemento
*)	
fun rankingAsc(matriz:string list list)=
	tl (matrixSortAsc(matriz,[[]],0))

(*
Funcion matrixSortMin
E: un elemento , una matriz y un indice
S: Verifica si el elemento es el menor de la lista
R: El elemento debe existir
*)
fun matrixSortMin(element,matriz,i):bool=
	if(i=List.length(matriz))
		then
			true
	else
		let
			val lista = List.nth(matriz,i)
			val ranking = List.nth(lista,0)
			val valor:int = valOf (Int.fromString ranking)
		in
			if (element>=valor)
				then 
					matrixSortMin(element,matriz,i+1)
			else
				false
		end;
(*
Funcion matrixSortDes
E: una matriz una matriz vacia y un indice
S: la matriz ordenada descendientemente por ranking
*)		
fun matrixSortDes(matriz,res,i)=
	if (i=List.length(matriz))
		then res
	else

		if(matrixSortMin(valOf (Int.fromString(List.nth(List.nth(matriz,i),0))),matriz,0))
			then	
				matrixSortDes(deleteElemet(matriz,i),res@[List.nth(matriz,i)],0)
		else
			matrixSortDes(matriz,res,i+1);
(*
Funcion rankingDes
E: una mtriz
S: la matriz ordenada descendientemente por el ranking
R: la matriz debe tener mas de un elemento
*)			
fun rankingDes(matriz)=
	tl (matrixSortDes(matriz,[[]],0));
		
(*
Funcion matrixVarSortMax
E: un elemento , una matriz y un indice
S: Verifica si el elemento es el mayor de la lista
R: El elemento debe existir
*)
fun matrixVarSortMax(element:real,matriz,i):bool=
	if(i=List.length(matriz))
		then
			true
	else
		let
			val lista = List.nth(matriz,i)
			val ranking = List.nth(lista,5)
			val valor:real = valOf (Real.fromString ranking)
		in
			if (element>=valor)
				then 
					matrixVarSortMax(element,matriz,i+1)
			else
				false
		end;
(*
Funcion matrixVarSortDes
E: una matriz una matriz vacia y un indice
S: la matriz ordenada descendientemente por variacion
*)		
fun matrixVarSortDes(matriz,res,i)=
	if (i=List.length(matriz))
		then res
	else

		if(matrixVarSortMax(valOf (Real.fromString(List.nth(List.nth(matriz,i),5))),matriz,0))
			then	
				matrixVarSortDes(deleteElemet(matriz,i),res@[List.nth(matriz,i)],0)
		else
			matrixVarSortDes(matriz,res,i+1);
(*
Funcion variacionDes
E: una mtriz
S: la matriz ordenada descendientemente por el ranking
R: la matriz debe tener mas de un elemento
*)			
fun variacionDes(matriz)=
	tl (matrixVarSortDes(matriz,[[]],0));

(*
Funcion matrixVarSortMin
E: un elemento , una matriz y un indice
S: Verifica si el elemento es el menor de la lista
R: El elemento debe existir
*)
fun matrixVarSortMin(element:real,matriz,i):bool=
	if(i=List.length(matriz))
		then
			true
	else
		let
			val lista = List.nth(matriz,i)
			val ranking = List.nth(lista,5)
			val valor:real = valOf (Real.fromString ranking)
		in
			if (element<=valor)
				then 
					matrixVarSortMin(element,matriz,i+1)
			else
				false
		end;

(*
Funcion matrixVarSortAsc
E: una matriz una matriz vacia y un indice
S: la matriz ordenada ascedente por variacion
*)			
fun matrixVarSortAsc(matriz,res,i)=
	if (i=List.length(matriz))
		then res
	else

		if(matrixVarSortMin(valOf (Real.fromString(List.nth(List.nth(matriz,i),5))),matriz,0))
			then	
				matrixVarSortAsc(deleteElemet(matriz,i),res@[List.nth(matriz,i)],0)
		else
			matrixVarSortAsc(matriz,res,i+1);

(*
Funcion variacionAsc
E: una mtriz
S: la matriz ordenada ascedente por la Variacion
R: la matriz debe tener mas de un elemento
*)				
fun variacionAsc(matriz)=
	tl (matrixVarSortAsc(matriz,[[]],0));
	
(*
Funcion matrixRatSortMax
E: un elemento , una matriz y un indice
S: Verifica si el elemento es el Mayor de la lista
R: El elemento debe existir
*)
fun matrixRatSortMax(element:real,matriz,i):bool=
	if(i=List.length(matriz))
		then
			true
	else
		let
			val lista = List.nth(matriz,i)
			val ranking = List.nth(lista,4)
			val valor:real = valOf (Real.fromString ranking)
		in
			if (element>=valor)
				then 
					matrixRatSortMax(element,matriz,i+1)
			else
				false
		end;

(*
Funcion matrixRatSortDes
E: una matriz una matriz vacia y un indice
S: la matriz ordenada descendiente por rating
*)			
fun matrixRatSortDes(matriz,res,i)=
	if (i=List.length(matriz))
		then res
	else

		if(matrixRatSortMax(valOf (Real.fromString(List.nth(List.nth(matriz,i),4))),matriz,0))
			then	
				matrixRatSortDes(deleteElemet(matriz,i),res@[List.nth(matriz,i)],0)
		else
			matrixRatSortDes(matriz,res,i+1);
(*
Funcion ratingDes
E: una mtriz
S: la matriz ordenada descendiente por la Ranking
R: la matriz debe tener mas de un elemento
*)				
fun ratingDes(matriz)=
		tl (matrixRatSortDes(matriz,[[]],0));

(*
Funcion matrixRatSortMin
E: un elemento , una matriz y un indice
S: Verifica si el elemento es el menor de la lista
R: El elemento debe existir
*)		
fun matrixRatSortMin(element:real,matriz,i):bool=
	if(i=List.length(matriz))
		then
			true
	else
		let
			val lista = List.nth(matriz,i)
			val ranking = List.nth(lista,4)
			val valor:real = valOf (Real.fromString ranking)
		in
			if (element<=valor)
				then 
					matrixRatSortMin(element,matriz,i+1)
			else
				false
		end;
(*
Funcion matrixRatSortAsc
E: una matriz una matriz vacia y un indice
S: la matriz ordenada ascedente por rating
*)		
fun matrixRatSortAsc(matriz,res,i)=
	if (i=List.length(matriz))
		then res
	else

		if(matrixRatSortMin(valOf (Real.fromString(List.nth(List.nth(matriz,i),4))),matriz,0))
			then	
				matrixRatSortAsc(deleteElemet(matriz,i),res@[List.nth(matriz,i)],0)
		else
			matrixRatSortAsc(matriz,res,i+1);

(*
Funcion ratingAsc
E: una mtriz
S: la matriz ordenada ascedente por la rating
R: la matriz debe tener mas de un elemento
*)			
fun ratingAsc(matriz)=
		tl (matrixRatSortAsc(matriz,[[]],0));

(*
Funcion dataUniversityIndexAux
E:Una matriz, un indix, una matriz vacia, un indice
S: Los elementos de la matriz que seas igual al index que ingreso el usuario 
R: el indice debe exisir en la matriz
*)
fun dataUniversityIndexAux(matriz,index,res,i)=
	if(i=List.length(matriz)-1)
		then
			res
	else
		if(List.nth(List.nth(matriz,i),0)=index)
			then
				dataUniversityIndexAux(matriz,index,res@[List.nth(matriz,i)],i+1)
		else
				dataUniversityIndexAux(matriz,index,res,i+1);

(*
Funcion dataUniversityIndex
E: una matriz y un index ingresado por el usuario 
S: Los elementos de la matriz que seas igual al index que ingreso el usuario 
R: el indice debe exisir en la matriz
*)
fun dataUniversityIndex(matriz,index)=
	tl (dataUniversityIndexAux(matriz,index,[[]],0));
	
(*
Funcion existIndex
E: un matriz, el index ingresado por el usuario y un indice
S: verificar si el indice exite dentro de la matriz
R: el indice debe existir
*)
fun existIndex(matriz,index,i)=
	if(i=List.length(matriz)-1)
		then
			"0"
	else
		if( not (List.nth(List.nth(matriz,i),0)=index))
			then
				existIndex(matriz,index,i+1)
		else
			"1";
(*
Funcion universityIndex
E:Una matriz 
S: los datos que existen por el index que ingreso el usuario 
R. el index debe existir 
*)
fun universityIndex(matriz)=
	let	
		val message = printMesage("Ingrese el numero de index que desea consultar: ");
	    val v_opcion = valOf(TextIO.inputLine TextIO.stdIn);
		val opcion = clearLine v_opcion
		val exist = existIndex(matriz,opcion,0)
	in
		if(exist="1")
			then
				dataUniversityIndex(matriz,opcion)
		else
			universityIndex(matriz)
	end;

(*
Funcion dataUniversitySegmentAux
E:una matriz , una matriz vacia, un segmento y un index
S:todas las universidad que tengas ese segmento
R:la matriz debe estar llena
*)	
fun dataUniversitySegmentAux(matriz,res,segment,i)=
	if(i=List.length(matriz)-1)
		then	
			res
	else
		if(List.nth(List.nth(matriz,i),2)=segment)
			then
				dataUniversitySegmentAux(matriz,res@[List.nth(matriz,i)],segment,i+1)
		else
				dataUniversitySegmentAux(matriz,res,segment,i+1);
(*
Funcion: dataUniversitySegment
E: una matriz y un segmento 
S: una matriz con los elementos que coinciden con el nombre del segmento
*)
fun dataUniversitySegment (matriz,segment)=
		tl (dataUniversitySegmentAux(matriz,[[]],segment,0));

(*
Funcion universitySegment
E: Una matriz con datos 
S: una matriz con los elementos que coinciden con el nombre del segmento
*)		
fun universitySegment(matriz)=
	let	
		val message = printMesage("Ingrese el Segmento que desea Buscar :")
	    val v_opcion = valOf(TextIO.inputLine TextIO.stdIn)
		val opcion = clearLine v_opcion
	in
		dataUniversitySegment(matriz,opcion)
	end;
	
(*
Funcion countUniversityLocate
E: Una mtriz con los datos del archivo, un elemento, indice, counter
S: cuenta la cantidad de elementos que existen que coinciden con el elemento ingresado
R: los elementos deben existir
*)
fun countUniversityLocate(matriz,element,i,res):int=
	if (i=List.length(matriz))
		then 
			res
	else
		if(element=List.nth(List.nth(matriz,i),3))
			then
				countUniversityLocate(matriz,element,i+1,res+1)
		else
			countUniversityLocate(matriz,element,i+1,res);
(*
Funcion pertenece
E: Unn elemento y una lista
S: valor booleano si el elemento existe en la lista 
R: ninguna
*)
fun pertenece(element,lista,i)=
	if(i=List.length(lista))
		then
			false
	else
		if(element <>List.nth(lista,i))
			then
				pertenece(element,lista,i+1)
		else
			true;
(*
Funcion universityLocateAux
E: Una matriz, una lista vacia y un indice 
S: Una lista con todo las localizaciones distintas del archivo
R: solo pueden haber una localizacion en la lista retonarla
*)
fun universityLocateAux(matriz,res,i)=
	if(i=List.length(matriz))
		then
			res
	else
		if(pertenece(List.nth(List.nth(matriz,i),3),res,0))
			then 
				universityLocateAux(matriz,res,i+1)
		else
				universityLocateAux(matriz,res@[List.nth(List.nth(matriz,i),3)],i+1);
(*
Funcion printUniversityLocate
E: un elemento y una cantidad
S: Imprime esos datos en la consola
R:ninguna
*)
fun printUniversityLocate(element,cantidad)=
	let	
		val message = printMesage(element ^ " = " ^ Int.toString (cantidad) ^ "\n")
	in
		()
	end
	
(*
Funcion universityLocateAux2
E: una matriz un indice y un largo
S: la impresion de las localizacion con su respectiva cantidad
R: las localizaciones tienen que ser mayor a 0
*)
fun universityLocateAux2(matriz,i,len)=
	if(i=len)
		then
			()
	else
		let 
			val lista  = universityLocateAux(matriz,[],0)
			val largo = List.length(lista)
			val element = List.nth(lista,i)
			val cantidad = countUniversityLocate(matriz,element,0,0)
			val imprimir = printUniversityLocate(element,cantidad)
		in	
			universityLocateAux2(matriz,i+1,largo)
		end;
(*
Funcion universityLocate
E:Matriz
S:imprime la cantidad de cada lozalizacion
R: ninuna
*)
fun universityLocate(matriz)=
	let
		val ptr = print("\nLocalizacion  || Cantidad\n")
	in
		universityLocateAux2(matriz,0,1)
	end;
	
(*
Funcion countUniversitySegment
E: Una matriz, una lista vacia y un indice 
S: Una lista con todo los segmentos distintas del archivo
R: solo pueden haber una localizacion en la lista retonarla
*)
fun countUniversitySegment(matriz,element,i,res):int=
	if (i=List.length(matriz))
		then 
			res
	else
		if(element=List.nth(List.nth(matriz,i),2))
			then
				countUniversitySegment(matriz,element,i+1,res+1)
		else
			countUniversitySegment(matriz,element,i+1,res);
(*
Funcion universitySegmentAux
E: Una matriz, una lista vacia y un indice 
S: Una lista con todo los segmentos distintas del archivo
R: solo pueden haber una localizacion en la lista retonarla
*)	
fun universitySegmentAux(matriz,res,i)=
	if(i=List.length(matriz))
		then
			res
	else
		if(pertenece(List.nth(List.nth(matriz,i),2),res,0))
			then 
				universitySegmentAux(matriz,res,i+1)
		else
				universitySegmentAux(matriz,res@[List.nth(List.nth(matriz,i),2)],i+1);

(*
Funcion printUniversitySegment
E: un elemento y una cantidad
S: Imprime esos datos en la consola
R:ninguna
*)				
fun printUniversitySegment(element,cantidad)=
	let	
		val message = printMesage(element ^ " || " ^ Int.toString (cantidad) ^ "\n")
	in
		()
	end
(*
Funcion universitySegmentAux2
E: una matriz un indice y un largo
S: la impresion de los segmentos con su respectiva cantidad
R: las localizaciones tienen que ser mayor a 0
*)	
fun universitySegmentAux2(matriz,i,len)=
	if(i=len)
		then
			()
	else
		let 
			val lista  = universitySegmentAux(matriz,[],0)
			val largo = List.length(lista)
			val element = List.nth(lista,i)
			val cantidad = countUniversitySegment(matriz,element,0,0)
			val imprimir = printUniversitySegment(element,cantidad)
		in	
			universitySegmentAux2(matriz,i+1,largo)
		end;
(*
Funcion universitySegment
E:Matriz
S:imprime la cantidad de cada Segmentos
R: ninuna
*)
fun universitySegment(matriz)=
	let
		val ptr = print("\nSegmento    ||  Cantidad\n")
	in
		universitySegmentAux2(matriz,0,1)
	end;
(*
Funcion maxVariacion 
E: Una mtriz 
S: Imprime la informacion de la universidad con mayor variacion 
R: ninguna
*)		
fun maxVariacion(matriz)=
	let 
		val descendiente = variacionDes(matriz);
		val lista = hd descendiente
		val Ranking = "Ranking =" ^ List.nth(lista,0) ^ "\n"
		val Nombre = "Nombre =" ^ List.nth(lista,1) ^ "\n"
		val Segmento = "Segmento ="^ List.nth(lista,2) ^"\n"
		val Localizacion = "Localizacion ="^List.nth(lista,3) ^ "\n"
		val Rating = "Rating ="^List.nth(lista,4) ^ "\n"
		val Variacion = "Variacion ="^List.nth(lista,5)^"\n"
		val all = Ranking^Nombre^Segmento^Localizacion^Rating^Variacion
	in 
		printMesage(all)
	end;
	
(*
Funcion minVariacion 
E: Una mtriz 
S: Imprime la informacion de la universidad con menor variacion 
R: ninguna
*)	
fun minVariacion(matriz)=
	let 
	
		val Ascendente = variacionAsc(matriz);
		val lista = hd Ascendente
		val Ranking = "Ranking =" ^ List.nth(lista,0) ^ "\n"
		val Nombre = "Nombre =" ^ List.nth(lista,1) ^ "\n"
		val Segmento = "Segmento ="^ List.nth(lista,2) ^"\n"
		val Localizacion = "Localizacion ="^List.nth(lista,3) ^ "\n"
		val Rating = "Rating ="^List.nth(lista,4) ^ "\n"
		val Variacion = "Variacion ="^List.nth(lista,5)^"\n"
		val all = Ranking^Nombre^Segmento^Localizacion^Rating^Variacion
	in 
		printMesage(all)
	end;
	
(*
Funcion maxRating 
E: Una mtriz 
S: Imprime la informacion de la universidad con mayor rating 
R: ninguna
*)	
fun maxRating(matriz)=
	let 
	
		val descendiente = rankingDes(matriz);
		val lista = hd descendiente
		val Ranking = "Ranking =" ^ List.nth(lista,0) ^ "\n"
		val Nombre = "Nombre =" ^ List.nth(lista,1) ^ "\n"
		val Segmento = "Segmento ="^ List.nth(lista,2) ^"\n"
		val Localizacion = "Localizacion ="^List.nth(lista,3) ^ "\n"
		val Rating = "Rating ="^List.nth(lista,4) ^ "\n"
		val Variacion = "Variacion ="^List.nth(lista,5)^"\n"
		val all = Ranking^Nombre^Segmento^Localizacion^Rating^Variacion
	in 
		printMesage(all)
	end;
	
(*
Funcion minRating 
E: Una mtriz 
S: Imprime la informacion de la universidad con menor rating 
R: ninguna
*)	
fun minRating(matriz)=
	let 
		val ascedente = rankingAsc(matriz)
		val lista = hd ascedente
		val Ranking = "Ranking =" ^ List.nth(lista,0) ^ "\n"
		val Nombre = "Nombre =" ^ List.nth(lista,1) ^ "\n"
		val Segmento = "Segmento ="^ List.nth(lista,2) ^"\n"
		val Localizacion = "Localizacion ="^List.nth(lista,3) ^ "\n"
		val Rating = "Rating ="^List.nth(lista,4) ^ "\n"
		val Variacion = "Variacion ="^List.nth(lista,5)^"\n"
		val all = Ranking^Nombre^Segmento^Localizacion^Rating^Variacion
	in 
		printMesage(all)
	end;

(*
Funcion Resumen
E:Recibe una matriz
S: la impresion de diferentes informaciones
R: Ninguna
*)	
fun resumen(matriz)=
	let
		val message = print("\n\n****RESUMEN****\n\n")
		val message1 = printMesage("\nCantidad de Universidades = ")
		val countUniversity = print(Int.toString (List.length(matriz)) ^ "\n")
		
		val message2 = print("\n*****Universidad Con mas Variacion******\n")
		val mayorVariacion= maxVariacion(matriz)
		
		val message3 = print("\n******Universidad con menor Variacion*****\n")
		val menorVariacion = minVariacion(matriz)
		
		val message4 = print("\n******Universidad con mayor rating******\n")
		val mayorRating = maxRating(matriz)
		
		val message5 = print("\n*****Universidad con Menor Rating******\n")
		val menorRating = minRating(matriz)
		
		val message6 = print("\n*****Cantidad de universidades por segmento*****\n")
		val encabezado = ("\nSegmento    || Cantidad ")
		val infoSegment = universitySegment(matriz)
	in 
		()
	end;
		
	
(*
Funcion printInfoTab
E: una matriz
S: muestra la informacion tabulada
R: ninguna
*)
fun printInfoTab(matriz)=
	printDatas(matriz,0);
	
fun distribution (opcion,fileName)=
	let
		val message = printMesage("RANKING\t          NOMBRE U\t    SEGMENTO\t               LOCALIZACION\t                     RATING\t      VARIACION\t\n")
	in
		if(opcion = "1")
			then 
				printInfoTab(rankingAsc(getDataFile(fileName)))
		else if (opcion="2")
			then 
				printInfoTab(variacionDes(getDataFile(fileName)))
		else if (opcion="3")
			then 
				printInfoTab(ratingDes(getDataFile(fileName)))
		else if (opcion="4")
			then 
				printInfoTab(universityIndex(getDataFile(fileName)))
		else if (opcion="5")
			then	
				universitySegment(getDataFile(fileName))
		else if(opcion="6")
			then
				universityLocate(getDataFile(fileName))
		else
			()
	end;
		
fun printResumen(fileName)=
	resumen(getDataFile(fileName));
(*
Funcion validation
E:Una opcion del menu
S:Verifica que la opcion digitada exista
R: La opcion tiene que existir
*)
fun validation(opcion)=
		if (opcion = "1") orelse (opcion="2") orelse (opcion="3") orelse (opcion="4") orelse (opcion="5") orelse (opcion="6")
			then	
				"1"
		else
			"0";
			
fun menu (fileName) =
	let 
		val message = printMesage("Ingrese la opcion que desea realizar\n1-Top ranking ascendente\n2-Top por variacion descendente\n3-Top por rating descendente\n4-Detalle Universidad por ranking\n5-Universidad por segmento\n6-Cantidad universidades por localizacion\n7-Resumen\nOpcion:");
		val v_opcion = valOf(TextIO.inputLine TextIO.stdIn);
		val opcion = clearLine v_opcion;
		val valido = validation(opcion);
	in 
		if (opcion="7") 
			then
				printResumen(fileName)
				
		else if (valido="1")
			then
				distribution(opcion,fileName)
		else
			menu(fileName)
	end;
	
fun main()=
	let
		val message = printMesage("Ingrese la ruta del archivo que desea analizar Ejemplo: C:\\Users\\Pc\\Desktop\\QS_Ranking.csv;\nUbicacion:");
		val v_file = valOf(TextIO.inputLine TextIO.stdIn);
		val fName = clearLine v_file;
	in 
		menu(fName)
	end;
	