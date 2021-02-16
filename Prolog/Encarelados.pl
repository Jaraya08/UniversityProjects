%%F: lenList.
%%E: Una lista,Contador,Variable unbound.
%%S: El largo de la lista ingresada.
%%R: La lista debe tener elementos.
%%O: Retornar el largo de una lista ingresada.
lenList([], L, L).
lenList([_|Xs], N, L):- N2 is N + 1, lenList(Xs, N2, L).

%%F: HeadList.
%%E: Un lista y una variable unbound.
%%S: El primer elementos de la lista.
%%R: La lista debe tener elementos.
headList([A|_],A).
headList([_|B],X):- headList(B,X).

%%F: lastList.
%%E: Una lista y una variable unbound.
%%S: El ultimo elementos de la lista
%%O: Retornar el ultimo elementos de la lista
lastList([Y], Y).
lastList([_|Xs],Y):- lastList(Xs,Y).

%%F: enesimoList.
%%E: Una Lista,una Posicion y una variable unbound
%%S: El elemento que se encuentra en la posisicon ingresda
%%O: Retorna el elemento en la posicion ingresada
enesimoList([Y|_], 1, Y).
enesimoList([_|Xs], N, Y):-N2 is N - 1,enesimoList(Xs, N2, Y).

%%F: pertenece
%%E: Un elemento,una lista y una variable unbound
%%S: Valor booleano si el elemento ingresado es igual al primero de la lista
%%R: la lista de causas de un preso.
%%O: Retorna la lista de causas de un preso.
pertenece(Elem,[H|T],Res):- Elem == H,Res = T.

%%F: miembro.
%%E: Un elemento,una lista, y una variable unbound.
%%S: Un valor booleano si el elemento existe en la lista.
%%R: El elemento debe existir.
%%O: Saber si un elemento si un elemento existe en la lista
miembro(Elem,[],Res).
miembro(Elem,[H|T],Res) :- pertenece(Elem,H,Res);miembro(Elem,T,Res).

%%F: existe.
%%E: Una lista,elemento.
%%S: Saber si un elemento existe en la lista.
%%R: El elemento debe exitir.
%%O: Saber si un elemento existe en la lista
existe([H|T],X):- H == X;existe(T,X).

%%####################################################PARTE1####################################################

%%F: nuevaCarcel.
%%E: Nombre de la carcel y una lista de presos.
%%S: Ingresar una nueva carcel al la base de conocimientos del sistema.
%%R: Los datos deben existir.
%%O: Agregar una nueva carcel a la base de conocimientos del sistema.  
nuevaCarcel(Nombre,Presos):- assert(carcel(Nombre,Presos)).

%%####################################################PARTE2####################################################

%%F: 1- primerPreso.
%%E: Nombre de una carcel.
%%S: El nombre del primeror preso de una carcel.
%%R: El preso debe existir en la base de conocimientos.
%%O: Retornar el primer preso de la carcel ingresada.
primerPreso(Carcel):- 
carcel(Carcel,Presos),headList(Presos,R),headList(R,X),write("Primer preso :"),write(X),!.

%%F: 2- cantidadCausas.
%%E: Nombre de una carcel y nombre de un preso.
%%S: La cantidad de causas del preso ingresado
%%R: El preso debe existir.
%%O: Retornar la cantidad de causas que tiene el preso ingresado.
cantidadCausas(Carcel,Nombre):- 
carcel(Carcel,Presos),miembro(Nombre,Presos,R),headList(R,Res),lenList(Res,0,Len),write("Cantidad causas de "),write(Nombre),write(":"),write(Len),!.

%%F: 3-cantidadCausasUltimo.
%%E: Nombre de una carcel.
%%S: La cantidad de causas del ultimo preso.
%%R: La carcel debe tener presos registrados.
%%O: Retornar la cantidad de causas que tiene el ultimo preso.
cantidadCausasUltimo(Carcel):- 
carcel(Carcel,Presos),lastList(Presos,Res),lastList(Res,Del),lenList(Del,0,Len),write("Cantidad causas ultimo preso: "),write(Len),!.

%%F: 4-agregarPreso.
%%E: Nombre de una carcel,nombre de un preso y la edad
%%S: El registro de un nuevo preso en la base de conocimiento.
%%O: Agregar un nuevo preso a la carcel ingresada.
agregarPreso(Carcel,Nombre,Edad):- 
append([Nombre],[Edad],X),append(X,[[]],X2),carcel(Carcel,Presos),append(Presos,[X2],R),retract(carcel(Carcel,Presos)),nuevaCarcel(Carcel,R),write(R),!.

%%F: 5-porRobo
%%E: Una carcel y un nombre de un preso.
%%S: Saber si un preso esta detenido por robo.
%%R: El preso debe existir en la base de conocimiento.
%%O: Saber si un preso esta aprendido por robos.
porRobo(Carcel,Nombre):- 
carcel(Carcel,Presos),miembro(Nombre,Presos,Res),lastList(Res,X),!,existe(X,"Robos"),!.

%%F: 6-nombrePreso
%%E: Nombre de una carcel,una posicion
%%S: El nombre del preso en la enesima posicion.
%%R: La posicion debe existir.
%%O: Retornar el nombre de un preso en la enesima posicion.
nombrePreso(Carcel,Pos):- 
carcel(Carcel,Presos),enesimoList(Presos,Pos,Res),headList(Res,R),write("Nombre preso: "),write(R),!.

%%####################################################PARTE3####################################################

%%F: 1-sinDelitos
%%E: Nombre de una carcel.
%%S: Saber si una carcel tiene presos sinn delitos.
%%R: La carcel debe existir en la base de conocimientos.
%%O: Retorna un valor booleano si hay un preso sinn delitos.
listaDelitosAux(T):-lastList(T,R),lenList(R,0,L),L=:=0.
listaDelitos([H|T]):- listaDelitosAux(H);listaDelitos(T).
sinDelitos(Carcel):- carcel(Carcel,Presos),listaDelitos(Presos),!.

%%F: 2-mayoresDeEdad
%%E: Nombre de una carcel.
%%S: true: todo los presos son mayores de edad false: si noo
%%R: La carcel debe tener presos.
%%O: Saber si todos los presos de una carcel con mayores de edad
mayoresDeEdadAux2(L):-enesimoList(L,2,Res),Res>17.
mayoresDeEdadAux([]).
mayoresDeEdadAux([H|T]):- mayoresDeEdadAux2(H),mayoresDeEdadAux(T).
mayoresDeEdad(Carcel):- carcel(Carcel,Presos),mayoresDeEdadAux(Presos),!.

%%F: 3-causasPar
%%E: una carcel.
%%S: devuele los presos que tengan cuasas par. 
%%R: la carcel debe existir.
%%R: Retornar una lista con los nombres de todos los presos que tengas causas par.
causasParAux([],LN,LN).
causasParAux2([H|T],Res):- lastList(T,R),lenList(R,0,L),mod(L,2)=:=0,Res = H,!.
causasParAux([H|T],LN,Res):- causasParAux2(H,N),append([N],LN,X2),write(X2);causasParAux(T,X2,Res).
causasPar(Carcel):- carcel(Carcel,Presos),causasParAux(Presos,[],R),!.

%%F: 4- sumatoria.
%%E: El nombre de una carcel.
%%S: La sumatoria de todas las causas de todos los presos
%%R: La carcel debe tener presos.
%%O: Retorna la sumatoria de todas las causas de los presos.
sumatoriaAux([],S,S).
sumatoriaAux([H|T],S,Res):- lastList(H,D),lenList(D,0,L),X2 is S+L,sumatoriaAux(T,X2,Res).
sumatoria(Carcel):- carcel(Carcel,Presos),sumatoriaAux(Presos,0,Res),write("Suma de delitos: "),write(Res),!.

%%F: 5-limpiarHistorialAux.
%%E: Nombre de una carcel.
%%S: La limpieza de todas las causas de los presos.
%%R: La carcel debe existir.
%%O: Limpiar los delitos de todos los presos de una carcel.
limpiarHistorialAux([],LN,LN).
limpiarHistorialAux([H|T],LN,Res):-
enesimoList(H,1,R1),enesimoList(H,2,R2),append([R1],[R2],X),append(X,[[]],X2),append(LN,[X2],X3),limpiarHistorialAux(T,X3,Res).
limpiarHistorial(Carcel):- 
carcel(Carcel,Presos), limpiarHistorialAux(Presos,[],Res),retract(carcel(Carcel,Presos)),nuevaCarcel(Carcel,Res),!.

%%F: 6-
%%####################################################PARTE4####################################################

%%F: 1-mayoresDeEdadInd.
%%E: Un nombre de una carcel
%%S: true: si todos los presos son mayores de edad , false: si noo
%%R: La carcel debe existir.
%%O: Saber si todos los presos de una carcel son mayores de edad
mayoresDeEdadIndAux2(L,Edad):-enesimoList(L,2,Res),Res>Edad.
mayoresDeEdadIndAux([],Edad).
mayoresDeEdadIndAux([H|T],Edad):- mayoresDeEdadIndAux2(H,Edad),mayoresDeEdadIndAux(T,Edad).
mayoresDeEdadInd(Carcel,Edad):- carcel(Carcel,Presos),mayoresDeEdadIndAux(Presos,Edad),!.

%%F: 2-limpiarHistorialCantidad. 

%%F: 0000-porDelito
%%E: Una carcel un preso y un delito.
%%S: true si el preso tiene ese delito false si no. 
%%R: La carcel debe existir.
%%O: Saber si un preso esta detenido por un causa especifica.
porDelito(Carcel,Nombre,Delito):- carcel(Carcel,Presos),miembro(Nombre,Presos,Res),lastList(Res,X),!,existe(X,Delito),!.

%%F: 3-cantidadPresosPorDelito.
%%E: Una carcel y un delito.
%%S: la cantidad de presos que tengas un delito en especifico.
%%R: la carcel debe existir.
%%O: retornar la cantidad de presos que tenga un delito especifico en sus lista de delistos.
contador([],S,D,S).
contador([H|T],S,D,Res):- X2 is S+1,lastList(H,R),existe(R,D),write(X2);contador(T,X2,D,Res).
cantidadPresosPorDelito(Carcel,Delito):- carcel(Carcel,Presos),contador(Presos,0,Delito,R),!.


%%[["Jordan",32,["Robos","Violacion","Asaltos"]],["Angelo",18,["Estocion","Estafa"]],["Anderson",18,["Pajitas","Robos","Pijas Gigantes"]],["Nahun",15,["Defrausadacion","Contrabando"]]].
%%[["Allan",32,["Trafico","Robos"]],["Esteban",20,["Drogas"]],["Jose",18,["Hacker"]],["Heiner",15,["Violacion"]]].
%%[["Alonso",32,["Trafico","Robos"]],["Eduardo",20,["Drogas"]],["Herwin",18,["Hacker"]],["Salomon",43,["Violacion"]]]
%%[["Natalia",32,["Trafico","Robos"]],["Mellisa",20,["Drogas"]],["Camila",18,["Hacker"]],["Yolanda",43,["Violacion"]]]
%%[["Derian",32,["Trafico","Robos"]]]
