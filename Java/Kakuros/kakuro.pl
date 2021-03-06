%%F: enesimoList.
%%E: Una Lista,una Posicion y una variable unbound
%%S: El elemento que se encuentra en la posisicon ingresda
%%O: Retorna el elemento en la posicion ingresada
enesimoList([Y|_], 1, Y).
enesimoList([_|Xs], N, Y):-N2 is N - 1,enesimoList(Xs, N2, Y).

soluciones(X):- X=[
	[-1,"12/ ","7/ ",-1,-1,-1,-1,-1,-1,
	" /15",9,6,"8/ ",-1,-1,"15/ ","5/ ",-1,
	" /6",3,1,2,"17/ ","4/12",8,4,-1,
	-1,-1," /25",6,8,3,7,1,-1,
	-1,-1,-1,"12/6",5,1,-1,-1,-1,
	-1," /12","6/10",7,3,"12/ ",-1,-1,-1,
	" /21",9,2,5,1,4,"5/ ","12/ ",-1,
	" /7",3,4,-1," /21",8,4,9,-1,
	-1,-1,-1,-1,-1," /4",1,3,-1]
	,
	[-1,-1,"9/ ","14/ ",-1,-1,"12/ ","11/ ",-1,
	-1," /13",5,8,"27/0","20/6",4,2,-1,
	-1," /32",4,6,2,3,8,9,-1,
	-1,-1,-1," /15",6,9,-1,-1,-1,
	-1,-1,-1,"17/11",3,8,-1,-1,-1,
	-1,-1," /11",7,4,-1,-1,-1,-1,
	-1,"16/ ","7/15",8,7,"3/ ","11/ ",-1,-1,
	" /27",9,6,2,5,1,4,-1,-1,
	" /8",7,1,-1," /9",2,7,-1,-1]
	,
	[-1,-1,-1,-1,-1,"7/ ","14/ ",-1,-1,
	-1,"8/ ","3/ ",-1,"37/11",2,9,-1,-1,
	" /5",3,2,"5/9",3,1,5,-1,-1,
	" /18",5,1,2,6,4,-1,-1,-1,
	-1,-1," /10",3,7,"6/ ",-1,-1,-1,
	-1,-1,-1,"9/12",8,4,"10/ ","11/ ",-1,
	-1,-1,"9/19",3,9,2,1,4,-1,
	-1," /9",3,2,4," /16",9,7,-1,
	-1," /10",6,4,-1,-1,-1,-1,-1]
	,
	[-1,-1,-1,"13/ ","10/ ",-1,-1,-1,-1,
	-1,"3/ ","11/13",6,7,"6/ ",-1,-1,-1,
	" /19",1,6,7,3,2,"14/ ",-1,-1,
	" /7",2,5,-1,"4/6",1,5,-1,-1,
	-1,-1,"16/ ","11/13",1,3,9,-1,-1,
	-1," /20",9,8,3,-1,"9/ ","17/ ",-1,
	-1," /8",7,1,"15/ ","12/10",2,8,-1,
	-1,-1," /32",2,6,8,7,9,-1,
	-1,-1,-1," /13",9,4,-1,-1,-1]
	,
	[-1,-1,"29/ ","9/ ",-1,-1,"17/ ","9/ ",-1,
	-1," /15",9,6,"14/ ","29/13",9,4,-1,
	-1,"4/38",7,3,6,9,8,5,-1,
	" /7",3,4,"19/15",8,7,"34/ ",-1,-1,
	" /8",1,3,4," /9",5,4,"15/ ",-1,
	-1," /8",6,2,"10/23",8,9,6,-1,
	-1,"11/ ","16/11",8,3,"6/16",7,9,-1,
	" /39",8,9,5,7,4,6,-1,-1,
	" /10",3,7,-1," /10",2,8,-1,-1]
	,
	[-1,-1,"29/ ","17/ ","13/ ",-1,-1,-1,-1,
	-1,"7/14",2,8,4,-1,-1,-1,-1,
	" /19",1,7,9,2,"8/ ",-1,-1,-1,
	" /8",2,6," /10",7,3,"25/ ",-1,-1,
	" /13",4,9,"12/ "," /14",5,9,"20/ ",-1,
	-1," /9",5,4,"7/ "," /5",1,4,-1,
	-1,-1," /12",8,4,"4/15",6,9,-1,
	-1,-1,-1," /13",1,3,2,7,-1,
	-1,-1,-1," /10",2,1,7,-1,-1]
	,
	[-1,"17/ ","7/ ",-1,-1,-1,-1,-1,-1,
	" /9",8,1,"6/ ",-1,-1,"4/ ","5/ ",-1,
	" /17",9,6,2,"15/0","10/4",1,3,-1,
	-1,-1,"0/21",4,5,7,3,2,-1,
	-1,-1,-1,"11/10",7,3,-1,-1,-1,
	-1,"4/ ","9/11",9,2,"11/",-1,-1,-1,
	" /22",3,7,2,1,9,"16/ ","11/ ",-1,
	" /3",1,2,-1," /13",2,7,4,-1,
	-1,-1,-1,-1,-1," /16",9,7,-1]
	,
	[-1,-1,-1,-1,"42/ ","8/ ",-1,-1,-1,
	-1,-1,"8/","17/15",9,6,"12/ ","5/ ",-1,
	-1," /23",3,8,4,2,5,1,-1,
	-1," /18",5,6,7," /11",7,4,-1,
	-1,-1," /8",3,5," /15",-1,-1,-1,
	-1,"7/ ","15/"," /14",6,8,"13/ ",-1,-1,
	" /8",1,7,"4/7",1,2,4,-1,-1,
	" /31",6,8,1,2,5,9,-1,-1,
	-1,-1," /11",3,8,-1,-1,-1,-1]
	,
	[-1,-1,-1,"15/ ","42/ ",-1,"22/ ","17/ ",-1,
	-1,"12/ ","3/10",9,1,"10/13",5,8,-1,
	" /36",7,1,6,2,3,8,9,-1,
	" /7",5,2," /15",5,1,9,-1,-1,
	-1,-1,-1,"8/13",7,6,-1,-1,-1,
	-1,-1,"13/8",2,6,-1,"12/ ","8/ ",-1,
	-1,"17/7",2,1,4,"9/16",9,7,-1,
	" /39",9,7,5,8,6,3,1,-1,
	" /12",8,4," /12",9,3,-1,-1,-1]
	,
	 [-1,-1,-1,-1,"12/ ","24/ ",-1,-1,-1,
	-1,-1,-1,"7/7",3,4,-1,-1,-1,
	-1,"16/ ","16/23",6,9,8,"20/ ",-1,-1,
	" /10",7,2,1,"14/5",3,2,-1,-1,
	" /14",9,5,"24/20",6,9,5,"13/ ",-1,
	-1," /20",3,9,8,"16/9",4,5,-1,
	-1," /11",6,5,"5/24",7,9,8,-1,
	-1,-1," /20",7,4,9,-1,-1,-1,
	-1,-1," /4",3,1,-1,-1,-1,-1]
].

	
tablero(T):- soluciones(X),random(1,10,R),enesimoList(X,R,T),!.
