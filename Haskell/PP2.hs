import System.IO
import Data.Time.Clock



--PROTOTIPOS DE FUNCIONES 
main ::IO()
menu ::[String]->[String]->[String]->[String]->[String]->IO()
opcionesAdministrativas::[String]->[String]->[String]->[String]->[String]->IO()
opcionesGenerales::[String]->[String]->[String]->[String]->[String]->IO()
agregarTipo::[String]->[String]->[String]->[String]->[String]->IO()
agregarTipos::[String]->[String]->[String]->[String]->[String]->IO()
eliminarTipos::[String]->[String]->[String]->[String]->[String]->IO()
agregarNaviera::[String]->[String]->[String]->[String]->[String]->IO()
agregarNavieras::[String]->[String]->[String]->[String]->[String]->IO()
eliminarNavieras::[String]->[String]->[String]->[String]->[String]->IO()
agregarBarcoxNaviera::[String]->[String]->[String]->[String]->[String]->IO()
agregarBarcoxNavieras::[String]->[String]->[String]->[String]->[String]->IO()
registroAtenciones::[String]->[String]->[String]->[String]->[String]->IO()
registrarAtencion::[String]->[String]->[String]->[String]->[String]->IO()
eliminarAtencion::[String]->[String]->[String]->[String]->[String]->IO()
historialAtenciones::[String]->[String]->[String]->[String]->[String]->IO()
consultaAtenciones::[String]->[String]->[String]->[String]->[String]->IO()
imprimirTarifas::[String]->[String]->[String]->[String]->[String]->IO()
cancelarAtencion::[String]->[String]->[String]->[String]->[String]->IO()
--FUNCIONES AUXILIARES 
imprimirTipos::[String]->Int->IO()
imprimirNavieras::[String]->Int->IO()
imprimirBxN::[String]->Int->IO()
imprimirBxNCom::[String]->String->IO()
imprimirAtenciones::[String]->Int->IO()
encontrarIndex::[String]->String->Int->Int->Int	
printHistorialConsultas::[String]->[String]->IO()	
unionHistorialConsultas::[String]->[String]->[String]->[String]
buscarConsidencias::[String]->String->[String]->[String]
imprimirBusquedas::[String]->Int->IO()
mostarTarifas::[String]->IO()
montoTRB::Integer -> Double
montoPasajeros::Double->Double
montoRemolque::Double->Int->Double
montoCTN1::Double->Double
montoCTN2::Double->Double
montoVEH1::Double->Double
montoVEH2::Double->Double
replaceNth::Int->String->[String]->[String]
imprimirFactura::[String]->IO()

--E:NINGUNA
--S:LA EJECUCION COMPLETA DEL SISTEMA DE GESTION PORTUARIA
--R:SEGUN RESTRICCIONES DE LAS FUNCIONES 
--O:RESOLUCION DEL SISTEMA DE GESTION PORTUARIA
main=
  menu [] [] [] [] [];

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:DESPLEGUE DEL MENU PRINCIPAL 
--R:SEGUN RESTRICCIONES DE LAS FUNCIONES
--O:MENU ENCARGADO DE SOLICITAR TODOS LOS DATOS AL USUARIO
menu list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
   putStrLn "\n***** BIENVENIDO AL SISTEMA DE GESTION PORTUARIA *****\n"
   putStr "1-Opciones Administrativas\n2-Opciones Generales\n3-Salir\nIngrese la opcion que desea ingresar: "
   opcion <- getLine
   if(opcion=="1") 
     then opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if (opcion=="2") 
     then opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if (opcion=="3") 
     then putStrLn "\n***** GRACIAS POR UTILIZAR EL SISTEMA****\n"
   else 
     menu list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	 
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:DESPLEGUE DEL MENU DE LAS OPCIONES GENERALES*****\n
--R:PARA CONTINUAR SE DEBE SELECCIONAR UNA OPCION VALIDA
--O:DESPLEGA EL MENU DE LAS OPCIONES GENERALES PARA LA SOLICITUD DE DATOS
opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
  putStrLn "\n***** BIENVENIDOS A OPCIONES ADMINISTRATIVAS*****\n"
  putStrLn "1-Registro de tipos de barco\n2-Registro de naviera\n3-Registro de barcos por naviera"
  putStr "4-Consulta de barco\n5-Registro de atenciones\n6-Consultar historial de atenciones\n7-Consultar de facturas\n8-Volver al Menu\nIngrese la opcion que desea realizar: "
  opcion <- getLine
  if(opcion=="1") 
     then 
	   agregarTipo list_barco list_naviera list_bxn  list_atenciones  list_ConFact
  else if(opcion =="2")
	  then 
		agregarNaviera list_barco list_naviera list_bxn  list_atenciones  list_ConFact
  else if(opcion=="3")
	  then
	    agregarBarcoxNaviera list_barco list_naviera list_bxn  list_atenciones  list_ConFact
  else if (opcion=="4")
	  then
		consultaBarco list_barco list_naviera list_bxn  list_atenciones  list_ConFact
  else if(opcion=="5")
	  then 
	    registroAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact
  else if (opcion=="6")
	  then 
	     historialAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact
  else if (opcion =="7")
	then	
		consultaFacturas list_barco list_naviera list_bxn  list_atenciones  list_ConFact
  else if(opcion=="8")
	   then
		  menu list_barco list_naviera list_bxn  list_atenciones  list_ConFact
  else
   opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:MENU DE TIPO DE BARCOS, QUE SOLICITA LOS DATOS
--R:SE DEBE SELECIONAR UNA OPCION VALIDAD PARA PODER CONTINUAR
--O:DESPLEGAR UN MENU AL USUARIO PARA INTERACTUAR CON EL AREA DE TIPOS DE BARCOS
agregarTipo list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
   putStrLn "\n***** BIENVENIDO A REGISTRO DE TIPOS DE BARCOS*****\n"
   putStrLn "1-Agregar Tipo de Barco\n2-Eliminar Tipo de Barco\n3-Volver"
   putStr "Ingrese la opcion que desea realizar: "
   opcion<-getLine
   if opcion=="1" then agregarTipos list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if opcion=="2" then eliminarTipos list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if opcion =="3" then opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else agregarTipo list_barco list_naviera list_bxn  list_atenciones  list_ConFact

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:LA INCLUCIÓN DE UN NUEVO TIPO DE BARCO EN EL SISTEMA
--R:EL TIPO DE BARCO NO PUEDE SER REPETIDO
--O:INCLUIR UN NUEVO TIPO DE BARCO EN EL REGISTO DEL SISTEMA   
agregarTipos list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
   putStrLn "\n*****MOSTRADO TIPOS REGISTRADOS*****\n"
   imprimirTipos list_barco 1
   putStr "Ingrese la Descripcion del tipo de Barco: "
   descripcion <- getLine
   if descripcion==""
	then do
		putStrLn"\n***** CAMPO VACIO, SE DEBEN INGRESAR DATOS*****\n"
		agregarTipo  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if elem descripcion list_barco
		then
		do
			putStrLn ("\n***** EL TIPO "++descripcion++" YA SE ENCUENTRA REGISTRADO*****\n")
			agregarTipo  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else
	do
		let agregar = list_barco++[descripcion]
		putStrLn ("\n***** TIPO "++descripcion++" AGREGADO CORRECTAMENTE*****\n")
		putStrLn "\n*****MOSTRADO TIPOS REGISTRADOS*****\n"
		imprimirTipos agregar 1
		agregarTipo  agregar list_naviera list_bxn  list_atenciones  list_ConFact

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:LA ELIMINACION DE UN TIPO DE BARCO DEL SISTEMA
--R:EL TIPO A ELIMINAR NO PUEDE EXISTIR EN UN BARCO
--O:ELIMINAR UN TIPO DE BARCO DEL REGISTRO DEL SISTEMA
eliminarTipos list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
	if(length list_barco )==0 
		then do
		putStrLn "\n***** NO HAY TIPOS REGISTRADOS *****\n"
		agregarTipo  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else
		do
		putStrLn "\n*****MOSTRADO TIPOS REGISTRADOS*****\n"
		imprimirTipos list_barco 1
		putStr "Ingrese el Tipo que desea eliminar: "
		opcion<-getLine
		if elem opcion list_bxn
			then do
				putStrLn "\n***** TIPO ASOSIADO A UN BARCO, NO PUEDE SER ELIMINADO*****\n"
				agregarTipo  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
		else if elem opcion list_barco
			then do
			let indice = encontrarIndex list_barco opcion 0 1
			let eliminar = (take indice list_barco) ++ (drop (indice+1) list_barco)
			putStrLn ("\n***** TIPO: "++opcion++" ELIMINADO EXITOSAMENTE*****\n")
			putStrLn "\n*****MOSTRADO TIPOS REGISTRADOS*****\n"
			imprimirTipos eliminar 1
			agregarTipo  eliminar list_naviera list_bxn  list_atenciones  list_ConFact
		else
			do
			putStrLn "\n***** TIPO SELECIONADO NO EXISTE *****\n"
			agregarTipo  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
			
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:DESPLEGAR UN MENU PARA INTERACTUAR CON EL AREA DE NAVIERAS
--R:SE DEBE SELECIONAR UNA OPCION VALIDA PARA CONTINUAR CON EL FLUJO NORMAL DEL SISTEMA
--O:DESPLEGAR UN MENU PARA INTERACTUAR CON EL AREA DE NAVIERAS			
agregarNaviera  list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
   putStrLn "\n***** BIENVENIDO A REGISTRO DE NAVIERAAS *****\n"
   putStrLn "1-Agregar Nueva Naviera \n2-Eliminar Naviera\n3-Volver"
   putStr "Ingrese la opcion que desea realizar: "
   opcion<-getLine
   if opcion=="1" then agregarNavieras list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if opcion=="2" then eliminarNavieras list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if opcion =="3" then opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else agregarNaviera list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:EL REGISTRO DE UNA NUEVA NAVIERA
--R:LA NAVIERA INGRESADA NO PUEDE TIENE QUE EXISTIR
--O:INCLUIR UNA NUEVA NAVIERA EN LOS REGISTROS DEL SISTEMA
agregarNavieras  list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
	putStrLn "\n***** MOSTRADO NAVIERAS REGISTRADAS *****\n"
	putStrLn "Linea | Nombre | Slogan"
	imprimirNavieras list_naviera 1
	putStr "Ingrese el Nombre de la naviera: "
	nombre <-getLine
	putStr "Ingrese el slogan de la naviera: "
	naviera<-getLine
	if elem nombre list_naviera
		then
			do
			putStrLn ("\n***** NAVIERA: "++nombre++" YA SE ENCUENTRA REGISTRADA*****\n")
			agregarNaviera  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else
		do
		let agregar = list_naviera++[nombre]++[naviera]
		putStrLn "\n***** NAVIERA REGISTRADA CORRECTAMENTE *****\n"
		putStrLn "\n***** MOSTRADO NAVIERAS REGISTRADAS *****\n"
		putStrLn "Linea | Nombre | Slogan"
		imprimirNavieras agregar 1
		agregarNaviera  list_barco agregar list_bxn  list_atenciones  list_ConFact
		
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:LA ELIMINAR DE UNA NAVIERA DEL REGISTRO DEL SISTEMA
--R:LA NAVIERA NO DEBE ESTAR INCLUIDA EN UN BARCO 
--O:ELIMINAR UNA NAVIERA DE LOS REGISTRO DEL SISTEMA
eliminarNavieras list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
	if(length list_naviera )==0 
		then do
		putStrLn "\n***** NO HAY NAVIERAS REGISTRADAS *****\n"
		agregarNaviera  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else
		do
		putStrLn "\n*****MOSTRADO NAVIERAS REGISTRADOS*****\n"
		putStrLn "Linea | Nombre | Slogan"
		imprimirNavieras list_naviera 1
		putStr "Ingrese el NOMBRE de la Naviera que desea eliminar: "
		opcion<-getLine
		if elem opcion list_bxn
			then do
				putStrLn "\n***** NAVIERA ASOSIADO A UN BARCO, NO PUEDE SER ELIMINADO*****\n"
				agregarNaviera  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
		else if elem opcion list_naviera
			then do
			let indice = encontrarIndex list_naviera opcion 0 2
			let eliminar = (take indice list_naviera) ++ (drop (indice+2) list_naviera)
			putStrLn ("\n***** NAVIERA: "++opcion++" ELIMINADO EXITOSAMENTE*****\n")
			putStrLn "\n*****MOSTRADO NAVIERAS REGISTRADOS*****\n"
			putStrLn "Linea | Nombre | Slogan"
			imprimirNavieras eliminar 1
			agregarNaviera  list_barco eliminar list_bxn  list_atenciones  list_ConFact
		else
			do
			putStrLn "\n***** NAVIERA SELECIONADO NO EXISTE *****\n"
			agregarNaviera  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
			
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:UN MENU DE INTERACCION CON EL AREA DE BARCOS POR NAVIERAS
--R:SE DEBE ELEGIR UNA OPCION VALIDA PARA CONTINUAR CON EL FLUJO NORMAL DEL SISTEMA
--O:MOSTRAR UN MENU QUE MUESTRAS LAS OPCIONES DEL AREA BARCOS POR NAVIERA 			
agregarBarcoxNaviera list_barco list_naviera list_bxn  list_atenciones  list_ConFact =do
	putStrLn "\n*****BIENVENIDO A BARCOS POR NAVIERAS*****\n"
	putStrLn "1-Agregar Barco\n2-Eliminar Barco\n3-Volver"
	putStr "Ingrese la opcion de desea realizar: "
	opcion<-getLine
	if(opcion=="1") then agregarBarcoxNavieras list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else if opcion=="2" then eliminarBarcoxNavieras list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else if(opcion=="3")then  opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact 
	else agregarBarcoxNaviera list_barco list_naviera list_bxn  list_atenciones  list_ConFact 

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:LA INCLUCION DE UN NUEVO BARCO AL LOS REGISTROS DEL SISTEMA 
--R:EL BARCO NO DEBE EXISTIR
--O:AGREGAR UN NUEVO BARC POR NAVIERA A LOS REGISTROS DEL SISTEMA
agregarBarcoxNavieras list_barco list_naviera list_bxn  list_atenciones  list_ConFact =do
	if length list_barco ==0|| length list_naviera==0
		then do
			putStrLn "\n***** NO HAY TIPOS DE BARCOS O NAVIERA REGISTRADAS *****\n"
			agregarBarcoxNaviera  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else do
	putStrLn "\n***** MOSTRAR BARCOS POR NAVIERAS *****\n"
	putStrLn "Linea | No. Registro | Tipo de Barco | Naviera "
	imprimirBxN list_bxn 10
	putStr "Ingrese el Numero de registro: "
	registro <-getLine
	if elem registro list_bxn
		then do
		putStrLn "\n***** No. DE REGISTRO YA SE ENCUENTRA REGISTRADO*****\n"
		agregarBarcoxNaviera  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else do
		putStrLn "\n**Mostrando Listado de Tipos de Barco**\n"
		imprimirTipos list_barco 1
		putStr "Ingrese el tipo de barco por la linea: "
		tipo <-getLine
		let nTipo = read tipo::Int
		let tipoBar= (list_barco!!(nTipo-1))
		putStrLn "\n** Mostrando Listado de Navieras**\n"
		imprimirNavieras list_naviera 1
		putStr "Ingrese la Naviera por la linea: "
		naviera<-getLine
		let nNaviera = read naviera::Int
		let agNaviera = (list_naviera!!((nNaviera-1)*2))
		putStr "Ingrese la Eslora: "
		eslora<-getLine
		putStr "Ingrese el calado: "
		calado<-getLine
		putStr "Ingrese el TRB: "
		trb<-getLine
		putStr "Ingrese la cantidad de contenedores: "
		cantCTN<-getLine
		putStr "Ingrese la cantidad de vehiculos: "
		cantVEH<-getLine
		putStr "Ingrese la cantidad de pasajeros: "
		cantPAS<-getLine
		putStr "Ingrese la cantidad de remolques necesarios: "
		cantREM <-getLine
		let agregar = list_bxn++[registro]++[tipoBar]++[agNaviera]++[eslora]++[calado]++[trb]++[cantCTN]++[cantVEH]++[cantPAS]++[cantREM]
		putStrLn ("\n***** REGISTRO No."++registro++" AGREGADO EXITOSAMENTE")
		putStrLn "\n***** MOSTRAR BARCOS POR NAVIERAS *****\n"
		putStrLn "Linea | No. Registro | Tipo de Barco | Naviera "
		imprimirBxN agregar 1
		agregarBarcoxNaviera  list_barco list_naviera agregar  list_atenciones  list_ConFact
		
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:LA ELIMINACION DE UN BARCO DE LOS REGISTRO DEL SISTEMA
--R:EL BARCO NO PUEDE ESTAR REGISTRADO EN UNA ATENCION
--O:ELIMINAR UN BARCO POR NAVIERA DE LOS REGISTRO DEL SISTEMA
eliminarBarcoxNavieras 	list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
    if (length list_bxn)==0
      then do
         putStrLn "\n***** NO HAY BARCOS REGISTRADOS ******\n"
         agregarBarcoxNaviera list_barco list_naviera list_bxn  list_atenciones  list_ConFact
    else do
       putStrLn "\n***** MOSTRAR BARCOS POR NAVIERAS *****\n"
       putStrLn "Linea | No. Registro | Tipo de Barco | Naviera "
       imprimirBxN list_bxn 10
       putStr "Ingrese el numero de registro que desea eliminar: "
       registro<-getLine
       if elem registro list_atenciones
          then do
            putStrLn "\n***** EL BARCO ESTA INCLUIDO EN UNA ATENCION, NO PUEDE SER ELIMINADO ******\n"
            agregarBarcoxNaviera list_barco list_naviera list_bxn  list_atenciones  list_ConFact
        else if not (elem registro list_bxn)
            then do
            putStrLn "\n***** EL NUMERO DE REGISTRO NO EXISTE ******\n"
            agregarBarcoxNaviera list_barco list_naviera list_bxn  list_atenciones  list_ConFact
        else do
            let indice = encontrarIndex list_bxn registro 0 10
            let indiceExacto = indice*10
            let eliminar = (take indiceExacto list_bxn) ++ (drop (indiceExacto+10) list_bxn)
            putStrLn ("\n***** BARCO "++registro++" FUE ELIMINADO EXITOSAMENTE*****\n")
            putStrLn "\n***** MOSTRAR BARCOS POR NAVIERAS *****\n"
            putStrLn ("Linea | No. Registro | Tipo de Barco | Naviera ")
            imprimirBxN eliminar 10
            agregarBarcoxNaviera list_barco list_naviera eliminar  list_atenciones  list_ConFact

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:IMPIRMIR LOS DATOS COMPLETOS DE UN BARCO REGISTRADO, SEGUN LO SELECCIONE EL USUARIO
--R:LA LISTA DE BARCOS NO DEBE SER VACIA Y EL BARCO DEBE EXISTIR
--O:LA IMPRESION EN PANTALLA DE TODOS LOS DATOS DE UN BARCO ESPECIFICADO POR EL USUARIO
consultaBarco list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
	if (length list_bxn) ==0
		then
			do
			putStrLn "\n***** NO EXISTEN BARCOS AGREGADOS *****\n"
			opcionesAdministrativas  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else
		do
		putStrLn "\n****** MOSTRANDO BARCOS AGREGADOS***** '\n"
		putStrLn "Linea | No. Registro | Tipo Barco | Naviera"
		imprimirBxN list_bxn 1
		putStr "Ingrese el Numero de registro que desea consultar: "
		registro <-getLine
		if (not (elem registro list_bxn))
			then
				do
				putStrLn "\n***** EL REGISTRO INGRESADO NO SE ENCUENTRA EN LA LISTA *****\n"
				opcionesAdministrativas  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
		else
			do
			putStrLn "\n****** MOSTRANDO RESULTADOS***** '\n"
			imprimirBxNCom list_bxn registro
			opcionesAdministrativas  list_barco list_naviera list_bxn  list_atenciones  list_ConFact

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:DESPLEGAR EL MENU DEL AREA DE ATENCIONES 
--R: SE DEBE SELECCIONAR OPCION VALIDA PARA CONTINUAR CON EL FLUJO NORMAL DEL SISTEMA
--O:MOSTRAR EL MENU DE ATECIONES AL USUARIO
registroAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact =do
	putStrLn "***** BIENVENIDO A REGRITRO DE ANTECIONES *****\n"
	putStrLn "1-Registrar Antecion\n2-Eliminar Atencion\n3-Volver"
	putStr "Ingrese la opcion que desea realizar: "
	opcion<-getLine
	if opcion =="1" then registrarAtencion list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else if opcion=="2" then eliminarAtencion list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else if opcion=="3"then opcionesAdministrativas  list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else registroAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:REGISTRAR UNA ATENCION A UN BARCO
--R:DEBEN EXISTIR BARCOS PARA PODER DARLES ATENCIONES	
registrarAtencion list_barco list_naviera list_bxn  list_atenciones  list_ConFact =do
	if (length list_bxn)==0
		then do
			putStrLn "\n***** NO HAY BARCOS REGISTRADOS PARA DARLES ATENCION *****\n"
			registroAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else do
		let id= ("AT"++(show ((length list_atenciones) +1)))
		putStrLn "\n**Mostrando Listado de barcos**\n"
		putStrLn "Linea | No. Registro | Naviera | Tipo"
		imprimirBxN list_bxn 1
		putStr "Seleciones un barco por la LINEA: "
		registro<-getLine 
		let nRegistro = read registro::Int
		let numRegistro = list_bxn!!((nRegistro-1)*10)
		putStr "Ingrese el puerto de Inicio: "
		ptoInicio<- getLine
		putStr "Ingrese el puerto de procedencia: "
		ptoProc <-getLine
		putStr "Ingrese el puerto de destino:"
		ptoDes <-getLine
		fechaHora<- fmap show getCurrentTime
		let agregar = list_atenciones++[id]++[numRegistro]++[ptoInicio]++[ptoProc]++[ptoDes]++[fechaHora]++["Pendiente"]
		putStrLn "*****ATENCION REGISTRADA CORRECTAMENTE*****\n"
		putStrLn "\n***** MOSTRANDO ATENCIONES *****\n"
		putStrLn " Linea | ID | No. Registro | Pto. Inicio | Pto. Procedencia | Pto.Destino | Fecha y Hora | Estado"
		imprimirAtenciones agregar 1
		registroAtenciones  list_barco list_naviera list_bxn  agregar  list_ConFact

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:ELIMINAR UNA ATENCION
--R:LA ATENCION A ELIMINAR NO PUEDE ESTAR ASOCIADA A UNA FACTURA 
--O:ELIMINAR UNA ATENCION DE LOS REGISTROS DEL SISTEMA
eliminarAtencion list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
   if (length list_atenciones)==0
         then do
            putStrLn "\n***** NO HAY ATENCIONES REGISTRADAS*****\n"
            registroAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else do
        putStrLn "\n***** MOSTRANDO ATENCIONES *****\n"
        putStrLn " Linea | No. Atencion | No. Registro | Pto. Inicio | Pto. Procedencia | Pto.Destino | Fecha y Hora | Estado"
        imprimirAtenciones list_atenciones 1
        putStr "Ingrese el NUMERO de atencion que desea eliminar: "
        atencion<-getLine
        if (elem atencion list_ConFact)
             then 
			 do
                putStrLn "\n***** ATENCION FACTURADA O CANCELADA, NO PUEDE SER ELIMINADA*****\n"
                registroAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact
        else if not(elem atencion  list_atenciones)
            then 
			do
                putStrLn "\n***** LA ATENCION SELECIONADA NO EXISTE*****\n"
                registroAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact
        else 
			do
            let indice = encontrarIndex list_atenciones atencion 0 7
            let indiceExacto = (indice*7)
            let eliminar = (take indiceExacto list_atenciones) ++ (drop (indiceExacto+7) list_atenciones)
            putStrLn ("\n***** ATENCION :"++atencion++" SE ELIMINO EXITOSAMENTE*****\n")
            putStrLn ("\n***** MOSTRANDO ATENCIONES *****\n")
            putStrLn ("Linea | No Atencion | No Registro | Pto Inicio | Pto Procedencia | Pto Destino | Fecha y Hora | Estado")
            imprimirAtenciones eliminar 1
            registroAtenciones list_barco list_naviera list_bxn  eliminar  list_ConFact
		
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:IMPRIMIR EN PANTALLA LAS ATENCIONES DISPONIBLES
--R:DEBEN EXISTIR ATENCIONES REGISTRADAS
historialAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
	if (length list_atenciones)==0
		then do
		putStrLn "\n***** NO EXISTEN ATENCIONES REGISTRADAS *****\n"
	else do
		putStrLn "\n***** MOSTRADO HISTORIAL DE ATENCIONES *****\n"
		putStrLn "ID | Fecha y Hora | Naviera |No. Registro | Tipo Barco | Pto Procedencia | Pto. Destino | Estado"
		printHistorialConsultas list_atenciones list_bxn
		opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:IMPRIMIR EN PATANTALLA LOS DATOS DE UNA FACTURA INGRESADA POR EL USUARIO
--R:LA FACTURA A CONSULTA DEBE EXISTIR Y DEBEN EXISTIR FACTURAS EN LA LISTA	
--O:MOSTAR LA INFORMACION DE UNA FACTURA ESPECIFICADA POR EL USUARIO
consultaFacturas list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
	if (length list_ConFact)==0
		then do
			putStrLn "\n***** NO HAY FACTURAS PARA MOSTRAR *****\n"
			opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else
		do
		putStrLn "\n***** MOSTRANDO FACTURAS *****\n"
		putStrLn "ID | Fecha y Hora | Naviera |No. Registro | Tipo Barco"
		mostrarFacturas list_ConFact
		putStr "Ingrese el Numero de Factura que desea Consultar: "
		numero<-getLine
		if not (elem numero list_ConFact) 
			then do
				putStrLn "\n***** LA FACTURA SELECIONADA NO EXISTE *****\n"
				opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact
		else do
			let indice = encontrarIndex list_ConFact numero 0 30
			putStrLn ("Indice "++(show indice))
			let indiceExacto = indice*30
			let listDer = (drop indiceExacto list_ConFact)
			let listFinal = take 30 listDer
			imprimirFactura listFinal
			opcionesAdministrativas list_barco list_naviera list_bxn  list_atenciones  list_ConFact
		
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:MOSTAR EL MENU DE OPCIONES GENERALES
--R:SE DEBE SELECCIONAR UNA OPCION VALIDA PARA CONTINUAR EL FLUJO NORMAL DEL SISTEMA
--O:MOSTAR EN PANTALLA EL MENU DEL AREA DE OPCIONES GENERALES.
opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do 
  putStrLn "\n*****BIENVENIDO A OPCIONES GENERALES*****\n";
  putStrLn "1-Consulta de Atenciones\n2-Impresion de Tarifas\n3-Facturacion de Antecion a barcos\n4-Cancelación de atención\n5-Volver Al Menu"
  putStr "Ingrese la opcion desea utilizar: "
  opcion<-getLine
  if(opcion=="1")
	then	
		consultaAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact
  else if(opcion=="2")
	then
		imprimirTarifas list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if(opcion=="3")
	then
		facturarAtencion list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if(opcion=="4")
	then
		cancelarAtencion list_barco list_naviera list_bxn  list_atenciones  list_ConFact
   else if (opcion=="5")
	then
		menu list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else
	opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:IMPRIMIR LAS ATENCIONES SEGUN EL FILTRO INGRESADO POR EL USUARIO
--R:LA LISTA DE ATENCIONES DEBE TENER DATOS
--O:MOSTAR LOS DATOS COMPLETOS DE UNA ATENCION AL USUARIO SEGUN SU FILTRO
consultaAtenciones list_barco list_naviera list_bxn  list_atenciones  list_ConFact =do
	if length list_atenciones ==0
		then
			do
			putStrLn "\n*****NO HAY ATENCIONES QUE MOSTRAR******\n"
			opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else do
		putStrLn "\n***** MOSTRANDO ATENCIONES REGISTRADAS*****\n"
		putStrLn ("Linea | No Atencion | No Registro | Pto Inicio | Pto Procedencia | Pto Destino | Fecha y Hora | Estado")
		imprimirAtenciones list_atenciones 1
		putStr "Filtar por Tipo - Naviera - Estado : "
		consulta <-getLine
		let info = unionHistorialConsultas list_atenciones list_bxn []
		let resultado = buscarConsidencias info consulta []
		putStrLn "\n***** MOSTRANDO RESULTADO DE BUSQUEDA*****\n"
		putStrLn "Linea | No. Atencion | Fecha Hora Zona | Naviera | No. Registro | Tipo Barco | Pto Procedencia | Pto Destino | Estado "
		imprimirBusquedas resultado 1
		opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:IMPRIMIR LAS TARIFAS DE LAS ATENCIONES
--R:NINGUNA
--O:IMPRIMIR LAS TARIFAS DE LAS ATENCIONES
imprimirTarifas list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
	putStrLn "\n*****MOSTRANDO TARIFAS*****\n"
	putStrLn "Codigo | Descripcion | Unidad Medida | Monto en $ | Gravado IV\n"
	let lista =[]
	let naves1 = lista++["1,1","Cuota fija buque más de 300 TRB","UND","836.59","SI"]
	let naves2 = naves1++["1,2","Cuota fija buque hasta 300 TRB","UND","110.75", "SI"]
	let pas1 = naves2++["2,1","Pasajeros en tránsito","UND","2.09","SI"]
	let rem1 = pas1++["3,1","Remolcaje con 1","T.R.B","0.27","NO"]
	let rem2 = rem1++["3,2","Remolcaje con 2","T.R.B","0.53","NO"]
	let rem3 = rem2++["3,3","Remolcaje con 3","T.R.B","0.8","NO"]
	let ctn1 = rem3++["4,1","Carga y descarga Cont. y Furg","CONT","16.98","NO"]
	let ctn2 = ctn1++["4,2","Recibo y despacho contenedores","CONT","18.86","NO"]
	let veh1 = ctn2++["5,1","Carga y descarga Vehiculos","CONT" ,"8.46","NO"]
	let veh2 = veh1++["5,2","Recibo y despacho vehiculos","CONT","9.43","NO"]
	mostarTarifas veh2
	opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:FACTURAR UNA ATENCIONES SELECIONADA POR EL USUARIO
--R:LA LISTA DE ATENCIONES NO DEBE SER VACIA, NI ESTAR FACTURA 
--O:FACTURAR UNA ATENCION SELECCINADA POR EL USUARIO	
facturarAtencion list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
	if (length list_atenciones) ==0
		then
			do
			putStrLn "\n****** NO HAY ATENCIONES PARA FACTURAR ******\n"
			opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else
		do
		putStrLn "\n***** MOSTRANDO ATENCIONES DISPONIBLES*****\n"
		putStrLn ("Linea | No Atencion | No Registro | Pto Inicio | Pto Procedencia | Pto Destino | Fecha y Hora | Estado")
		imprimirAtenciones list_atenciones  1
		putStr "Ingrese el NUMERO de la atencion que desea facturar: "
		atencion<-getLine
		let todaInfo = unionHistorialConsultas  list_atenciones list_bxn []
		let indice = encontrarIndex todaInfo atencion 0 8
		let indiceExacto=indice*8
		if todaInfo!!(indiceExacto+7)=="Cancelado" || todaInfo!!(indiceExacto+7)=="Facturado"
			then
			do
				putStrLn "\n***** ATENCION YA ESTA CANCELADA O FACTURADA *****\n"
				opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
		else if not(elem atencion list_atenciones)
			then do
				putStrLn "\n***** ATENCION YA ESTA CANCELADA O FACTURADA *****\n"
				opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
		else
			do
			let idxValores = encontrarIndex list_bxn (todaInfo!!(indiceExacto+3)) 0 10
			let idFact = "FC"++  show((div (length list_ConFact) 30)+1)
			let idAtencion = atencion
			let naviera = todaInfo!!(indiceExacto+2)
			let registro =todaInfo!!(indiceExacto+3)
			let listDer = drop ((idxValores*10)+5) list_bxn
			let listFinal = take 5 listDer
			let tipo = todaInfo!!(indiceExacto+4)
			let fecha =todaInfo!!(indiceExacto+1)
			let costoTRB = montoTRB (read (listFinal!!0)::Integer)
			let costoCTN1 = montoCTN1 (read(listFinal!!1)::Double)
			let costoCTN2 = montoCTN2 (read(listFinal!!1)::Double)
			let costoVEH1 = montoVEH1 (read(listFinal!!2)::Double)
			let costoVEH2 = montoVEH2 (read(listFinal!!2)::Double)
			let costoPAS = montoPasajeros (read(listFinal!!3)::Double)
			let costoRMQ = montoRemolque (read (listFinal!!0)::Double) (read (listFinal!!4)::Int)
			let subTotal = costoTRB+costoCTN1+costoCTN2+costoVEH1+costoVEH2+costoPAS+costoRMQ
			let impuestos = subTotal*0.13
			let total = subTotal+impuestos
			let naves1 = ["1","Atención a naves",(show costoTRB)]
			let pas1 = naves1++["2","Pasajeros",(show costoPAS)]
			let rem2 = pas1++["3","Remolcador ",(show costoRMQ)]
			let ctn1 = rem2++["4,1","Carga y descarga Cont. y Furg",(show costoCTN1)]
			let ctn2 = ctn1++["4,2","Recibo y despacho contenedores",(show costoCTN2)]
			let veh1 = ctn2++["5,1","Carga y descarga Vehiculos",(show costoVEH1 )]
			let veh2 = veh1++["5,2","Recibo y despacho vehiculos",(show costoVEH2)]
			let factura = [idFact]++[idAtencion]++[naviera]++[registro]++[tipo]++[fecha]++[(show subTotal)]++[(show impuestos)]++[(show total)]++veh2 
			let agregar = list_ConFact++factura 
			let idxCambio = encontrarIndex list_atenciones atencion 0 7
			let cambioEstado= replaceNth ((idxCambio*7)+6) "Facturado" list_atenciones  
			imprimirFactura factura
			opcionesGenerales list_barco list_naviera list_bxn  cambioEstado  agregar

--E:LISTA DE TIPOS DE BARCOS - LISTA DE NAVIERA - LISTA DE BARCOS POR NAVIERA - LISTA DE ATENCIONES - LISTA DE FACTURAS
--S:CAMBIO DE ESTA DE UNA ATENCION A "CANCELADO"
--R:LA ATENCION DEBE EXISTIR Y DEBE ESTAR EN ESTATO FACTURADO
--O:CANCELAR UNA ATENCION INGRESADA POR EL CLIENTE
cancelarAtencion list_barco list_naviera list_bxn  list_atenciones  list_ConFact=do
	if (length list_atenciones) ==0
		then do
			putStrLn "\n*****NO HAY ATENCIONES*****\n"
			opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
	else
		do
		putStrLn "\n***** MOSTRANDO ATENCIONES***** \n"
		putStrLn "Linea | No. Atencion | No. Registro | Pto Inicio | Pto Procedencia | Pto. Destino | Fecha | Estado"
		imprimirAtenciones list_atenciones 1
		putStr "Ingrese el el NUMERO de Atencion que desea Cancelar: "
		atencion<-getLine
		if not (elem atencion list_atenciones)
			then
				do
				putStrLn "\n***** LA ATENCION NO EXISTE *****\n"
				opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
		else
			do
				let indice = encontrarIndex list_atenciones atencion 0 7
				let indiceExacto = indice*7
				let estado = list_atenciones!!(indiceExacto+6)
				if estado =="Cancelado"
					then
					 do
					  putStrLn "\n***** LA ATENCION YA FUE CANCELADA *****\n"
					  opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
				else if estado =="Pendiente"
					then do	
						putStrLn "\n***** LA FACTURA AUN  NO HA SIDO FACTURADA *****\n"
						opcionesGenerales list_barco list_naviera list_bxn  list_atenciones  list_ConFact
				else
				  do
				   let cambioEstado = replaceNth (indiceExacto+6) "Cancelado" list_atenciones
				   putStrLn "\n***** MOSTRANDO ATENCIONES***** \n"
				   putStrLn "Linea | No. Atencion | No. Registro | Pto Inicio | Pto Procedencia | Pto. Destino | Fecha | Estado"
				   imprimirAtenciones cambioEstado 1
				   opcionesGenerales list_barco list_naviera list_bxn  cambioEstado  list_ConFact

--E:INDICE - VALOR - LISTA
--S:MODIFICACION DE LA LISTA INGRESADA POR EL VALOR EN EL INDICE INGRESADO
--R:EL INDICE DEBE EXISTIR
--O:MODIFICAR UNA POSICION DE LA LISTA INGRESADA				   
replaceNth n newVal (x:xs)
     | n == 0 = newVal:xs
     | otherwise = x:replaceNth (n-1) newVal xs	

--E:LISTA DE BARCOS 
--S:IMPIRIMIR LOS TIPOS DE BARCOS
--R:DEBEN EXISTIR TIPOS DE BARCOS REGISTRADOS
--O:MOSTRARLE AL USUARIO LOS BARCOS REGISTRADOS
imprimirTipos list_barco num=do
	if list_barco ==[]
		then 
			putStrLn ""
	else
		do
		let tipo = (head list_barco) 
		let numeracion = (show num)
		putStrLn (numeracion++" - "++tipo)
		imprimirTipos (tail list_barco) (num+1);

--E:LISTA DE NAVIERA Y UN NUMERO
--S:IMPRIMIR EN PANTALLA LAS NAVIERA REGISTRADAS NUMERADAS
--R:LA LISTA DE NAVIERA DEBE ESTAR LLENA
--O:MOSTRARLE AL USUARIO LAS NAVIERAS REGISTRADAS
imprimirNavieras list_naviera num=do
	if list_naviera ==[]
		then 
			putStrLn ""
	else
		do
		let nombre = list_naviera!!0
		let slogan = list_naviera!!1
		let numeracion = (show num)
		putStrLn (numeracion++" | "++nombre++" | "++slogan)
		imprimirNavieras (drop 2 list_naviera) (num+1);

--E:LISTA DE BARCOS - Numero
--S:IMPRIMIR EN PANTALLA LOS BARCOS REGISTRADOS , NUMERADOS
--R:LA LISTA DEBE TENER DATOS
--O:MOSTRARLE AL USUARIO LOS BARCOS REGISTRADOS
imprimirBxN list_BxN num=do
   if list_BxN ==[]
    then 
     putStrLn ""
   else do 
     let registro = (list_BxN!!0)
     let tipo = (list_BxN!!1)
     let naviera = (list_BxN!!2)
     let numeracion = (show num)
     putStrLn (numeracion++"  |  "++registro++"  |  "++tipo++"  |  "++naviera)
     imprimirBxN (drop 10 list_BxN) (num+1);
	 
--E:LISTA DE BARCOS Y UN REGISTRO 
--S:IMPRIMIR LOS DATOS DE UN BARCO DE UN REGISTRO ESPECIFICO 
--R:EL REGISTRO DEBE EXISTIR 
--O:MOSTRARLE AL USUARIO LOS DATOS DE UN BARCO, COMPLETOS
imprimirBxNCom list_BxN registro=do
	if (list_BxN!!0) ==registro
		then do
		let registro = (list_BxN!!0)
		let tipo = (list_BxN!!1)
		let naviera = (list_BxN!!2)
		let eslora = (list_BxN!!3)
		let calado = (list_BxN!!4)
		let trb = (list_BxN!!5)
		let cantCTN = (list_BxN!!6)
		let cantVEH = (list_BxN!!7)
		let cantPAS = (list_BxN!!8)
		let cantREM = (list_BxN!!9)
		putStrLn "No. Registro || Tipo Barco || Naviera || Eslora || Calado || TRB || Cant. CTN || cant. PASS || cant. REM"
		putStrLn (registro++"  ||  "++tipo++"  ||  "++naviera++"  ||  "++eslora++"  ||  "++calado++"  ||  "++trb++"  ||  "++cantCTN++"  ||  "++cantVEH++"  ||  "++cantPAS++"  ||  "++cantREM++"\n")
	else 
		do
		imprimirBxNCom (drop 10 list_BxN) registro;

--E:LISTA DE ATENCIONES - Numero
--S:IMPIRIMIR EN PANTALLA LAS ATENCIONES REGISTRADAS
--R:LA LISTA DE ATENCIONES DEBE TENER DATOS
--O:MOSTRARLE AL USUARIO LAS ATENCIONES EXISTENTES
imprimirAtenciones list_atenciones num =do
    if list_atenciones ==[]
      then 
       putStrLn ""
    else do 
     let id = (list_atenciones!!0)
     let registro = (list_atenciones!!1)
     let ptoInicio = (list_atenciones!!2)
     let ptoProc = (list_atenciones!!3)
     let ptoDes = (list_atenciones!!4)
     let fecha = (list_atenciones!!5)
     let estado =(list_atenciones!!6)
     let numeracion = (show num)
     putStrLn (numeracion++"  |  "++id++"  |  "++registro++"  |  "++ptoInicio++" | "++ptoProc++" | "++ptoDes++"  |  "++fecha++" | "++estado)
     imprimirAtenciones (drop 7 list_atenciones) (num+1);

--E:LISTA X - ELEMENTO - CONTADOR - LARGO DE LISTA
--S:UN NUMERO DE INDICE DONDE SE ENCONTRO EL REGISTRO 
--R:EL REGISTRO DEBE EXISTIR
--O:DEVOLVER UN INDICE EN LA POSISICION DEL REGISTRO
encontrarIndex list_BxN elemento count len=do
	if (list_BxN!!0)==elemento
		then
			count
	else
		encontrarIndex (drop len list_BxN) elemento (count+1) len
--E:LISTA DE ATENCIONES LISTA DE BARCOS		
--S:IMPRIMIR UNA LISTA CON LOS DATOS COMPLETOS DONDE SEAS IGUALES LOS REGISTROS DE BARCOS EN LA LISTA DE ATENCIONES Y BARCOS
--R:LOS REGISTROS DEBEN EXISTIR 
--O:MOSTRAS AL USUARIO LOS DATOS COMPLETOS DE UNA ATENCION
printHistorialConsultas list_atenciones list_bxn=do
	if list_atenciones==[]
		then
			putStrLn ""
	else
		do
		let indice = encontrarIndex list_bxn (list_atenciones!!1) 0 10
		let indiceExacto = indice*10
		let resultado= ( (list_atenciones!!0) ++" | "++(list_atenciones!!5)++" | "++(list_bxn!!(indiceExacto+2))++" || "++(list_bxn!!(indiceExacto))++" | "++(list_bxn!!(indiceExacto+1))++" | "++(list_atenciones!!3)++" | "++(list_atenciones!!4)++" | "++(list_atenciones!!6))
		putStrLn resultado
		printHistorialConsultas (drop 7 list_atenciones) list_bxn

--E:LISTA ANTECIONES LISTA BARCOS
--S:LA UNION DE LA LISTA DE ANTECIONES Y BARCOS DONDE SON IGUALES LOS REGISTROS
--R:LOS REGISTROS DEBEN EXISTIR EN LAS DOS TABLAS
--O:UNIR DOS LISTAS PARA RETORNAR UNA SOLA DONDE LOS REGISTROS DEL BARCOS SON IGUALES		
unionHistorialConsultas list_atenciones list_bxn res=do
    if list_atenciones==[]
		then
			res
	else
		do
		let indice = encontrarIndex list_bxn (list_atenciones!!1) 0 10
		let indiceExacto = indice*10
		let id = list_atenciones!!0
		let fecha = list_atenciones!!5
		let naviera = list_bxn!!(indiceExacto+2)
		let registro = list_bxn!!(indiceExacto)
		let tipo = list_bxn!!(indiceExacto+1)
		let ptoProc = list_atenciones!!3
		let ptoDes=list_atenciones!!4
		let estado = list_atenciones!!6
		let resultado= res++[id]++[fecha]++[naviera]++[registro]++[tipo]++[ptoProc]++[ptoDes]++[estado]
		unionHistorialConsultas (drop 7 list_atenciones) list_bxn resultado

--E:LISTA DE ATENCIONES - ELEMENTO - LISTA VACIOS
--S:RETORNAR UNA LISTA CON LOS DATOS DE LA LISTA DE ATENCIONES DONDE CONTENGA EL ELEMENTO INGRESADO
--R:EL REGISTRO DEBE EXISTIR EN LA LISTA DE ATENCIONES
--O:DEVOLVER UNA LISTA CON CON LOS DATOS DE LA LISTA DE ATENCIONES DONDE CONTENGA EL ELEMENTO		
buscarConsidencias list_atenciones elemento res=do
   if list_atenciones==[]
     then 
       res
   else
     if ((list_atenciones!!2)==elemento) || ((list_atenciones!!4)==elemento) || ((list_atenciones!!7)==elemento)
       then 
          do
          let id= list_atenciones!!0
          let fecha= list_atenciones!!1
          let naviera = list_atenciones!!2
          let registro = list_atenciones!!3
          let tipo = list_atenciones!!4
          let ptoProc = list_atenciones!!5
          let ptoDes = list_atenciones!!6
          let estado = list_atenciones!!7
          let resultado = res++[id]++[fecha]++[naviera]++[registro]++[tipo]++[ptoProc]++[ptoDes]++[estado]
          buscarConsidencias (drop 8 list_atenciones) elemento resultado
    else
      buscarConsidencias (drop 8 list_atenciones) elemento res

--E:LISTA DE ATENCIONES Y UN NUMERO 
--S:IMPRIMIR LAS ATENCIONES CON LOS DATOS COMPLETOS (LISTA ATENCIONES MAS LISTA DE BARCOS)
--R:LA LISTA DE ATENCIONES DEBE TENER DATOS
--O:MOSTRARLE AL USUARIO LOS DATOS COMPLETOS DE LAS ATENCIONES
imprimirBusquedas list_atenciones num =do
	if list_atenciones==[]
		then 
			putStrLn ""
	else do
		let id= list_atenciones!!0
		let fecha= list_atenciones!!1
		let naviera = list_atenciones!!2
		let registro = list_atenciones!!3
		let tipo = list_atenciones!!4
		let ptoProc = list_atenciones!!5
		let ptoDes = list_atenciones!!6
		let estado = list_atenciones!!7
		let numeracion = show num
		let resultado = (numeracion ++" | "++id++" | "++fecha++" | "++naviera++" | "++registro++" | "++tipo++" | "++ptoProc++" | "++ptoDes++" | "++estado)
		putStrLn resultado
		imprimirBusquedas (drop 8 list_atenciones) (num+1)
		
--E:LISTA DE TARIFAS
--S:IMPIRMIR LA LISTA DE TARIFAS
--R:NINGUNA
--O_MOSTARLE AL USUARIO LAS TARIFAS DE LAS ATENCIONES		
mostarTarifas list_tarifa =do
	if list_tarifa==[]
		then
			putStrLn ""
	else
		do
		let clm1 = list_tarifa!!0
		let clm2 = list_tarifa!!1
		let clm3 = list_tarifa!!2
		let clm4 = list_tarifa!!3
		let clm5 = list_tarifa!!4
		let resultado = (clm1++" | "++clm2++" | "++clm3++" | "++clm4++" | "++clm5)
		putStrLn resultado
		mostarTarifas (drop 5 list_tarifa)

--E:TRB DE BARCOS
--S:LA TARIFA DEL TRB SEGUN EL TRB
--R:NINGUNA
--O:DEVOVER LA TARIFA DEL TRB DE UN BARCO		
montoTRB trb =do
	if trb > 300
		then
			( 836.59)-( 836.59*(0.13))
	else
		 110.75-(110.75*(0.13))

--E:NUMERO DE PASAJEROS
--S:PRECIO POR LA CANTIDAD DE PASAJEROS
--R:NINGUNA
--O:DEVOLVER EL MONTO TOTAL POR LOS PASAJEROS QUE LLEVA EL BARCO
montoPasajeros num = ((num*2.09)-((num*2.09)*0.13))


--E: TRB Y CANTIDAD DE REMOLQUES 
--S:EL MONTO DEL REMOLCAJE SEGUN TRB
--R:NINGUNA
--O:DEVOLVER EL MONTO DEL REMOLCAJE
montoRemolque trb num=do
   if num>2 then (trb*0.8)
   else if num==1then (trb*0.27)
   else if num==2 then (trb*0.53)
   else 0.0
   
--E:NUMERO DE CONTENEDORES
--S:EL MONTO DE LA CANTIDAD DE CONTENEDORES
--R:NINGUNA
--O:DEVOLVER EL MONTO DE LA CANTIDAD DE CONTENDORES QUE LLEVAR EL BARCO
montoCTN1 ctn =(ctn*16.98)
montoCTN2 ctn =(ctn*18.86)

--E:NUMERO DE Vehiculos
--S:EL MONTO DE LA CANTIDAD DE Vehiculos
--R:NINGUNA
--O:DEVOLVER EL MONTO DE LA CANTIDAD DE CONTENEDORES QUE LLEVA EL BARCO
montoVEH1 veh =(veh*8.46)
montoVEH2 veh =(veh*9.43)
	
--E:LISTA DE FACTURAS
--S:LA IMPRESION DE UNA FACTURA 
--R:NINGUNA
--O:MOSTARLE AL USUARIO LOS DATOS DE UNA FACTURA
imprimirFactura list_ConFact=do
	putStrLn "\n***** MOSTRANDO FACTURA *****\n"
	putStrLn ("No. Factura :"++(list_ConFact!!0)++" No Atencion: "++(list_ConFact!!1))
	putStrLn ("Naviera: "++(list_ConFact!!2) ++" No. Registro Barco: "++(list_ConFact!!3) ++" Tipo Barco: "++(list_ConFact!!4))
	putStrLn ("Fecha : "++(list_ConFact!!5))
	putStrLn "\n*** MOSTRANDO DETALLE DE FACTURA ****\n"
	putStrLn "Codigo | Detalle | Monto UDS "
	imprimirDetalle (drop 9 list_ConFact)
	putStrLn ("SubTotal : "++list_ConFact!!6)
	putStrLn ("Impuesto :"++list_ConFact!!7)
	putStrLn ("Total : "++list_ConFact!!8)

--E:DETALLE DE LA FACTURA
--S:IMPRIMIR EL DETALLE DE LA FACTURA INGRESADA	
--R:EL DETALLE DEBE TENER DATOS 
--O:MOSTAR EN PANTALLA EL DETALLE DE UNA FACTURA
imprimirDetalle list_ConFact=do
	if list_ConFact==[]
		then
			putStrLn""
	else
		do
		let id = list_ConFact!!0
		let detalle = list_ConFact!!1
		let monto = list_ConFact!!2
		putStrLn (id++" | "++detalle++" | "++monto)
		imprimirDetalle (drop 3 list_ConFact)
		
--E:LISTA DE FACTURAS
--S:MOSTRAR LAS FACTURAS QUE EXISTEN EN SISTEMA 
--R:NINGUNA
--O:MOSTRARLE AL USUARIO LAS FACTURAS QUE EXISTEN EN EL SISTEMA
mostrarFacturas list_ConFact =do
	if list_ConFact ==[] 
		then putStrLn ""
	else do 
		let numFac = list_ConFact!!0
		let idAtencion = list_ConFact!!1
		let naviera = list_ConFact!!2
		let registro = list_ConFact!!3
		let tipo = list_ConFact!!4
		putStrLn (numFac++" | "++idAtencion++" | "++naviera++" | "++registro++" | "++tipo)
		mostrarFacturas (drop 30 list_ConFact)	