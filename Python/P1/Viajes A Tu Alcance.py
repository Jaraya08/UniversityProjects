from tkinter import *
import getpass
######################################################

#E: UNA LISTA
#S: APLANAR LA LISTA
#R. DEBE SER UNA LISTA

def aplanar(lista,):
        if lista == 1:
            return []
        elif isinstance (lista[0],list):
            return aplanar(lista[0]+ aplanar(lista[1:]))
        else:
            return [lista[0]]+aplanar(lista[1:])
        
#E: UN ELEMENTO Y UNA LISTA
#S: UN VALOR BOOLEANO
#R: LA POSICION 2 DEBE SER UNA LISTA
        
def Pertenece(elemento,lista):
        if lista == []:
            False
        else:
            if elemento==lista [0]:
                return True
            else:
                return Pertenece(elemento,lista[1:])
        
#E: EL TXT DE PUERTOS
#S: CANTIDAD DE LINES DEL TXT
#R: NINGUNA
        
def largo_puerto():
    abrir=open("puertos.txt","r")
    leer=(abrir.readlines())
    lista=leer 
    if lista != []:
        return cantidad(lista)
def cantidad(leer):
        if leer== []:
            return 0
        else:
            return 1 + cantidad(leer[1:])
        
#E: EL TXT DE CRUCEROS
#S: CANTIDAD DE LINES DEL TXT
#R: NINGUNA
        
def largo_crucero():
    abrir=open("cruceros.txt","r")
    leer=(abrir.readlines())
    lista=leer 
    if lista != []:
        return cantidad(lista)
def cantidad(leer):
        if leer== []:
            return 0
        else:
            return 1 + cantidad(leer[1:])
        
#E: EL TXT DE CRUCEROS
#S: CANTIDAD DE LINES DEL TXT
#R: NINGUNA
        
def largo_tour():
    abrir=open("tour.txt","r")
    leer=(abrir.readlines())
    lista=leer 
    if lista != []:
        return cantidad(lista)
def cantidad(leer):
        if leer== []:
            return 0
        else:
            return 1 + cantidad(leer[1:])
        
#E: UN STRING
#S: CANTIDAD DE LETRAS DE ESE STRING
#R: DEBE SER STRING
        
def lenn(pal):
    if pal == "":
        return 0
    else:
        return 1 + lenn(pal[1:])
    
#E: UNA LISTA
#S: LA CANTIDAD DE ELEMENTOS DE ESA LISTA
#R: DEBE SER UNA LISTA

def conterDeLista(lista):
        if lista ==[]:
                return 0
        else:
                return 1 + conterDeLista(lista[1:])

####################################INICIO DEL PROGRAMA ##############################################
#E:NOMBRE DEL PAIS, CUIDAD DEL PAIS , ATRACCIONES DEL PAIS
#S:ALMACENA EN EL ARCHIVOS DE TXT LA INFORMACION INGRESADA
#R: LOS ESPACIOS DEBEN TENER INFORMACION

def agregar_puerto(): 
    agregar=Toplevel()
    agregar.state("zoomed")
    imagen=PhotoImage(file="puerto.gif")
    imagen1=Label(agregar,image=imagen).place(x=80,y=0)
    agregar.title("Area De Agregar Puertos")
    campo=Text(agregar)#para agragar el TXT en la pantalla#
    txt=open("puertos.txt","r")
    txtR=txt.read()
    campo.insert(INSERT,txtR)
    txt.close()
    campo.place(x=350,y=30)
    campo.config(state=DISABLED)
    titulo=Label(agregar,text="|ID  |PAIS    |CUIDAD    |ATRACCIONES|",font=("Buxton Sketch",11)).place(x=350,y=0)
    texto1=Label(agregar,text="Agregar Pais:",font=("Buxton Sketch",14),bg="LightCyan").place(x=500,y=450)
    texto2=Label(agregar,text="Agregar Cuidad:",font=("Buxton Sketch",14),bg="LightCyan").place(x=500,y=500)
    texto3=Label(agregar,text="Agregar Atracciones:",font=("Buxton Sketch",14),bg="LightCyan").place(x=500,y=550)
    entrada1=StringVar()
    entrada2=StringVar()
    entrada3=StringVar()
    cuadro1=Entry(agregar,textvariable=entrada1,width=40).place(x=730,y=455)
    cuadro2=Entry(agregar,textvariable=entrada2,width=40).place(x=730,y=505)
    cuadro3=Entry(agregar,textvariable=entrada3,width=40).place(x=730,y=555)
    #S: UN NUMERO CONSECUTIVO QUE SERA ALMACENADO EN EL TXT DE PUERTOS EN LA PRIMERA POSICION
    #R: NINGUNA
    def defi_ID_P():
        AbrirArhivo=open("ID puertos.txt","r")
        LeerArchivo=AbrirArhivo.readlines()
        lista= LeerArchivo
        ID = int(lista[-1])
        ID2= str(ID+1)
        AbrirArhivo.close()
        AbrirArhivo2=open("ID puertos.txt","a")
        leer=AbrirArhivo2.write("\n" + ID2)
        AbrirArhivo.close()
        return ID2

    #E: RECOGE LOS DATOS INGRESADOS POR EL USUARIO
    #S: ALMACENAR LA INFORMACION EN EL TXT DE PUERTO
    #R: LOS DATOS CUADROS DE TEXTO DEBEN CONTENER INFORMACION

    def agre_puerto():
        if entrada1.get()=="" or entrada2.get()=="" or entrada3.get()=="":
            messagebox.askretrycancel("ERROR",message="Todos Los Espacios Deben Contener Informacion")
        else:
            abrir=open("puertos.txt","a")
            x=(entrada3.get()).split(",")
            y=int(defi_ID_P())
            tex=[y,entrada1.get(),entrada2.get(),x]
            abrir.write("%s \n" % tex)
            abrir.close()
            messagebox.showinfo("Guardado",message="informacion Guardada con Exito")
            
    boton1=Button(agregar,text="Guardar",command=agre_puerto,font=("Buxton Sketch",15),bg="LightCyan").place(x=730,y=600)
    boton2=Button(agregar,text="salir",font=("Buxton Sketch",15),command=agregar.destroy,bg="LightCyan").place(x=830,y=600)
    boton3=Button(agregar,text="Refrescar",font=("Buxton Sketch",15),command=agregar_puerto,bg="LightCyan").place(x=930,y=600)
    agregar.mainloop()
    
#E: RECOGE EL NOMBRE DEL CRUCERO, LA CAPACIDAD DE CRUCERO, LA CLASE DEL CRUCERO, LOS PUERTOS QUE VISITA
#S: ALMACENA LOS DATOS EN EL TXT DE CRUCEROS
#R: LOS ESPACIOS DEBEN CONTENER INFORMACION / LOS PUERTOS A AGREGAR DEBEN ESTAR REGISTRADOS EN EL TXT DE PUERTOS
    
def agregar_crucero(): 
    agregar_cruce=Toplevel()
    agregar_cruce.state("zoomed")
    imagen=PhotoImage(file="puerto.gif")
    imagen1=Label(agregar_cruce,image=imagen).place(x=80,y=0)
    agregar_cruce.title("Area De Agregar Cruveros")
    campo=Text(agregar_cruce)#para agragar el TXT en la pantalla#
    txt=open("cruceros.txt","r")
    txtR=txt.read()
    campo.insert(INSERT,txtR)
    txt.close()
    campo.place(x=350,y=30)
    campo.config(state=DISABLED)
    titulo=Label(agregar_cruce,text="|ID  |NOMBRE   |CAPACIDAD |CALSE|   PUERTO|",font=("Buxton Sketch",11)).place(x=350,y=0)
    texto1=Label(agregar_cruce,text="Agregar Nombre Del Crucero:",font=("Buxton Sketch",14),bg="LightCyan").place(x=400,y=450)
    texto2=Label(agregar_cruce,text="Agregar La Capacidad:",font=("Buxton Sketch",14),bg="LightCyan").place(x=400,y=500)
    texto3=Label(agregar_cruce,text="Agregar La/s Clases:",font=("Buxton Sketch",14),bg="LightCyan").place(x=400,y=550)
    texto4=Label(agregar_cruce,text="Agregar Puertos Que Visita:",font=("Buxton Sketch",14),bg="LightCyan").place(x=400,y=600)
    NombreCrucero=StringVar()
    Capacidad=StringVar()
    Clases=StringVar()
    AgregarPuerto=StringVar()
    cuadro1=Entry(agregar_cruce,width=40,textvariable=NombreCrucero).place(x=730,y=455)
    cuadro2=Entry(agregar_cruce,width=40,textvariable=Capacidad).place(x=730,y=505)
    cuadro3=Entry(agregar_cruce,width=40,textvariable=Clases).place(x=730,y=555)
    cuadro4=Entry(agregar_cruce,width=40,textvariable=AgregarPuerto).place(x=730,y=605)
    
    #E: RECIBE LOS NOMBRES DE LOS PUERTOS QUE USUARIO INGRESE
    #S: REVISICAR POR MEDIO DE UN VALOR BOOLEANO SI LOS PUERTOS INGREDOS EXISTE EN EL TXT DE PUERTOS
    #R: NINGUNA
    
    def Comparacion(lista):
        AbrirTXTPuertos=open("puertos.txt","r")
        LeerTXTPuertos=AbrirTXTPuertos.readlines()
        AbrirTXTPuertos.close()
        ListaTXT=LeerTXTPuertos
        LargoTXT=largo_puerto()
        return Comparacion_aux(ListaTXT,lista,LargoTXT,0)
    def Comparacion_aux(ListaTXt,ListaIDS,parada,conter):
            if ListaIDS==[]:
                return False
            elif parada==conter:
                return True 
            else:
                ListaPos=ListaTXt[conter]
                ListaAlista=eval(ListaPos)
                if ListaIDS[0]==ListaAlista[1]:
                   return Comparacion_aux(ListaTXt,ListaIDS[1:],parada,0)
                else:
                   return Comparacion_aux(ListaTXt,ListaIDS,parada,conter+1)
                
    #E: UN ELEMENTO Y UNA LISTA
    #S: UN VALOR BOOLEANO
    #R: LA POSICION 2 DEBE SER UNA LISTA
                
    def PerteneceAqui(elemento,lista):
        if lista == []:
            False
        else:
            if elemento==lista[0]:
                return True
            else:
                return PerteneceAqui(elemento,lista[1:])
        
    #E: LOS NOMBRES DEL LOS PUERTOS INGRESADOS
    #S: LOS IDS DE LOS PUERTOS PARA QUE SEA ALMACENADOS EN EL TXT
    #R: NINGUNA
        
    def Renombrar(Lista):
        ListaPuetos=EscribirPuertosPorIDS()
        LargoTXT=largo_puerto()
        return RenombrarAuxuliar(ListaPuetos,Lista,LargoTXT,0,[])
    def RenombrarAuxuliar(ListaTXT,ListaDelGet,Parada,conter,Resultado):
        if Parada==conter:
           return Resultado
        else:
           PosicionDeLista=ListaTXT[conter]
           PasarLista=eval(PosicionDeLista)
           PosicionPais=PasarLista[1]
           if PerteneceAqui(PosicionPais,ListaDelGet):
                return RenombrarAuxuliar(ListaTXT,ListaDelGet,Parada,conter+1,Resultado+[PasarLista[0]])
           else:
                return RenombrarAuxuliar(ListaTXT,ListaDelGet,Parada,conter+1,Resultado)
        
    #S: EL TXTX EN UNA LISTA
        
    def EscribirPuertosPorIDS():
        AbrirTXT=open("puertos.txt","r")
        LeerTXT=AbrirTXT.readlines()
        AbrirTXT.close()
        ListaTXT=LeerTXT
        return ListaTXT

    #S:UN ID CONSECUTIVO PARA SER ALMACENADO EN EL TXT DE CRUCEROS

    def defi_ID_C():
        abrir=open("ID cruceros.txt","r")
        leer=(abrir.readlines())
        lista= leer
        ID = int(lista[-1])
        ID2= str(ID+1)
        abrir.close()
        abrir2=open("ID cruceros.txt","a")
        leer=abrir2.write("\n" + ID2)
        abrir2.close()
        return ID2

    #E: RECOGE EL NOMBRE DEL CRUCERO, LA CAPACIDAD DE CRUCERO, LA CLASE DEL CRUCERO, LOS PUERTOS QUE VISITA
    #S: ALMACENA LOS DATOS EN EL TXT DE CRUCEROS
    #R: LOS ESPACIOS DEBEN CONTENER INFORMACION / LOS PUERTOS A AGREGAR DEBEN ESTAR REGISTRADOS EN EL TXT DE PUERTOS

    def agre_crucero():
        if NombreCrucero.get()=="" or Capacidad.get()=="" or Clases.get()=="" or AgregarPuerto.get()=="":
            messagebox.askretrycancel("ERROR",message="Todos Los Espacios Deben Contener Informacion")
            return agregar_crucero()
        else:
            if Comparacion((AgregarPuerto.get()).split(",")):
                messagebox.askretrycancel("ERROR",message="Alguno De Los Puertos No Existe En la Lista De Puertos")
                return agregar_crucero
            else:
                AbrirTXT=open("cruceros.txt","a")
                IDconsecutivo=defi_ID_C()
                NombreDeCrucero=NombreCrucero.get()
                try:
                  CapacidadDeCrucero=int(Capacidad.get())
                  MeterEnListaClases=(Clases.get()).split(",")
                  MeterEnListaPuertos=(AgregarPuerto.get()).split(",")
                  CambiarNombresAIDS=Renombrar(MeterEnListaPuertos)
                  tex=[int(IDconsecutivo),NombreDeCrucero,CapacidadDeCrucero,MeterEnListaClases,CambiarNombresAIDS]
                  AbrirTXT.write("%s \n" % tex)
                  AbrirTXT.close()
                  messagebox.showinfo("Guardado",message="informacion Guardada con Exito")
                except:
                  messagebox.showinfo("Error",message="La Capacidad debe ser un numero entero")
    boton1=Button(agregar_cruce,text="Guardar",command=agre_crucero,font=("Buxton Sketch",13),bg="LightCyan").place(x=730,y=650)
    boton2=Button(agregar_cruce,text="salir",command=agregar_cruce.destroy,font=("Buxton Sketch",13),bg="LightCyan").place(x=830,y=650)
    boton3=Button(agregar_cruce,text="Refrescar",command=agregar_crucero,font=("Buxton Sketch",13),bg="LightCyan").place(x=930,y=650)
    agregar_cruce.mainloop()
    
#E: RECOGE EL NOMBRE DEL CRUCERO, LA FECHA DE INICIO Y LLEGADA, LA HORA DE SALIDA, LOS PRECIOS
#S: ALMACENA LOS DATOS EN EL TXT DE TOURS
#R: LOS ESPACIOS DEBEN CONTENER INFORMACION / LOS PUERTOS A AGREGAR DEBEN ESTAR REGISTRADOS EN EL TXT DE PUERTOS
    
def agregar_tour():
    agregar_tou=Toplevel()
    agregar_tou.state("zoomed")
    imagen=PhotoImage(file="puerto.gif")
    imagen1=Label(agregar_tou,image=imagen).place(x=80,y=0)
    agregar_tou.title("Area De Agregar Tours")
    campo=Text(agregar_tou)#para agragar el TXT en la pantalla#
    txt=open("tour.txt","r")
    txtR=txt.read()
    campo.insert(INSERT,txtR)
    txt.close()
    campo.place(x=350,y=30)
    campo.config(state=DISABLED)
    titulo=Label(agregar_tou,text="|NOMBRE  |FECHAS Y HORA |  PRECIOS |",font=("Buxton Sketch",11)).place(x=350,y=0)
    texto2=Label(agregar_tou,text="Nombre Del Crucero:",font=("Buxton Sketch",13),bg="LightCyan").place(x=400,y=450)
    texto3=Label(agregar_tou,text="Fecha De Inicio:",font=("Buxton Sketch",13),bg="LightCyan").place(x=400,y=500)
    texto4=Label(agregar_tou,text="Fecha De Finalizacion:",font=("Buxton Sketch",13),bg="LightCyan").place(x=400,y=550)
    texto5=Label(agregar_tou,text="Hora De partida:",font=("Buxton Sketch",13),bg="LightCyan").place(x=400,y=600)
    texto6=Label(agregar_tou,text="Precio:",font=("Buxton Sketch",13),bg="LightCyan").place(x=400,y=650)
    nombre=StringVar()
    fechaini=StringVar()
    fechasal=StringVar()
    horapa=StringVar()
    precio=StringVar()
    cuadro2=Entry(agregar_tou,width=40,textvariable=nombre).place(x=730,y=455)
    cuadro3=Entry(agregar_tou,width=40,textvariable=fechaini).place(x=730,y=505)
    cuadro4=Entry(agregar_tou,width=40,textvariable=fechasal).place(x=730,y=555)
    cuadro5=Entry(agregar_tou,width=40,textvariable=horapa).place(x=730,y=605)
    cuadro6=Entry(agregar_tou,width=40,textvariable=precio).place(x=730,y=655)
    
    #E EL NOMBRE DEL CRUCERO
    #S. VERIFICAR SI ESE NOMBRE EXISTE EN EL TXT DEL CRUCERO 
    #R: NINGUNA
    
    def AbrirTXTCruceros():
        AbrirTXT=open("cruceros.txt","r")
        LeerTXT=AbrirTXT.readlines()
        AbrirTXT.close()
        ListaTXT=LeerTXT
        LargoTXT=largo_crucero()
        return RevificarCrucero(ListaTXT,LargoTXT,0)
    def RevificarCrucero(ListaTXT,parada,conter):
        if conter==parada:
             messagebox.showinfo("Error",message="El Crucero Al Que Quieres Agregrar No Existe")
             return agregar_tour()
        else:
             ListaStr=ListaTXT[conter]
             ListaALista=eval(ListaStr)
             ListaEnlaposicion=ListaALista[1]
             if nombre.get()==ListaEnlaposicion:
                return identificarIDcrucero()
             else:
                return RevificarCrucero(ListaTXT,parada,conter+1)
        
    #S: ID CONSECUTIVO QUE SE ALMACENATA EN EL TXT DE TOUR
        
    def IDtour():
        abrir=open("ID tour.txt","r")
        leer=(abrir.readlines())
        lista= leer
        ID = int(lista[-1])
        ID2= ID+1
        abrir.close()
        abrir2=open("ID tour.txt","a")
        leer=abrir2.write("\n" + str(ID2))
        abrir.close()
        return (ID2)

    #E: UN ELEMENTO Y UNA LISTA
    #S: UN VALOR BOOLEANO
    #R: LA POSICION 2 DEBE SER UNA LISTA

    def PerteneceCrucero(elemento,lista):
        if lista == []:
            False
        else:
            if elemento==lista [0]:
                return True
            else:
                return PerteneceCrucero(elemento,lista[1:])
        
    #E: LA VERIFICACION DE LA FUNCION AbrirTXTCruceros()
    #S: EL ID DEL CRUCERO INGRESADO POR EL USUARIO
    #R: DEPENDE LA VERIFICACION DE LA FUNCION AbrirTXTCruceros()
        
    def identificarIDcrucero():
        abrirArchivo=open("cruceros.txt","r")
        leerArchivo=abrirArchivo.readlines()
        abrirArchivo.close()
        ArchivoEnLista=leerArchivo
        return identificarIDcrucero_aux(ArchivoEnLista,0)
    def identificarIDcrucero_aux(lista,conter):
        largoLista=largo_crucero()   
        if largoLista==conter:
            messagebox.showinfo("Error",message="El Crecero No Existe")
            return agregar_tour()
        else:
            buscador=lista[conter]
            buscador1=buscador
            buscadorNombre=eval(buscador1)
            NombreCrucero=nombre.get() 
            if PerteneceCrucero(NombreCrucero,buscadorNombre):
                ID=buscadorNombre[0]
                return agre_tour(ID)
            else:
                return identificarIDcrucero_aux(lista,conter+1)
        
    #E: NUMERO DE ID ENVIADO POR LA FUNCION identificarIDcrucero()
    #S: EL ALMACENAMIENTO DE TODOS LOS DATOS INGRESADOS POR EL USUARIO
    #R: DEPENDE DE LA VERIFICACION DE LA FUNCION identificarIDcrucero()
        
    def agre_tour(ID):
        abrir=open("tour.txt","a")
        IDCrucero=ID
        IDTour=IDtour()
        NombreCrucero=nombre.get()
        FechaDeInicio=fechaini.get()
        FechaDeFinalizacion=fechasal.get()
        HoraDePartida=horapa.get()
        try:
          Precio=int(precio.get())
          Texto=[IDTour,IDCrucero,FechaDeInicio,FechaDeFinalizacion,HoraDePartida,Precio]
          abrir.write("%s \n" % Texto)
          abrir.close()
          messagebox.showinfo("Guardado",message="Informacion Almacenada con Exito")
          return agregar_tour()
        except:
          messagebox.showinfo("ERROR",message="El Precio Debe Ser Entero")
        
    boton1=Button(agregar_tou,text="Guardar",command=AbrirTXTCruceros,font=("Buxton Sketch",15),bg="LightCyan").place(x=730,y=700)
    boton2=Button(agregar_tou,text="salir",font=("Buxton Sketch",15),command=agregar_tou.destroy,bg="LightCyan").place(x=850,y=700)
    boton3=Button(agregar_tou,text="Refrescar",font=("Buxton Sketch",15),command=agregar_tou,bg="LightCyan").place(x=950,y=700)
    agregar_tou.mainloop()
    
#E: NOMBRE DEL PAIS
#S: ELIMINAR LA LINEA DEL TXT DONDE SE ENCUENTRA ESE NOMBRE
#R: SI EL PUERTO TIENE ASOCIADO ALGUN CRUCERO NO SE PUEDE ELIMINAR
    
def eliminar_puerto(): #ELIMINAR PUERTOS AL TXT#
    eliminar_puer=Toplevel()
    eliminar_puer.state("zoomed")
    imagen=PhotoImage(file="puerto.gif")
    imagen1=Label(eliminar_puer,image=imagen).place(x=80,y=0)
    eliminar_puer.title("Area De Agregar Puertos")
    #campo=Text(eliminar_puer,width=60) #para agragar el TXT en la pantalla#
    #txt=open("puertos.txt","r")
    #txtR=txt.read()
    #campo.insert(INSERT,txtR)
    #txt.close()
    #campo.place(x=430,y=30)
    #campo.config(state=DISABLED)
    titulo=Label(eliminar_puer,text="|PAIS    |CUIDAD    |ATRACCIONES|",font=("Buxton Sketch",10)).place(x=430,y=0)
    texto1=Label(eliminar_puer,text="Indicar Nombre Del Pais Que Deseas Eliminar:",font=("Buxton Sketch",15),bg="LightCyan").place(x=570,y=450)
    NombreDePais=StringVar()
    cuadro6=Entry(eliminar_puer,width=20,textvariable= NombreDePais).place(x=700,y=500)
    
    #E: NOMBRE DEL PAIS
    #S: NUMERO DE ID DEL PAIS
    #R: EL NOMBRE DEL PUERTO DEBE EXISTIR
    
    def VerificarEliminado():
        AbrirTXTPuertos=open("puertos.txt","r")
        LeerTXTPuertos=AbrirTXTPuertos.readlines()
        AbrirTXTPuertos.close()
        ListaTXT=LeerTXTPuertos
        LargoTXT=largo_puerto()
        return VerificarEliminado_aux(ListaTXT,LargoTXT,0)
    def VerificarEliminado_aux(ListaTXT,parada,conter):
        if parada==conter:
           messagebox.showinfo("ERROR",message="El Puerto Ingresado No existe")
        else:
           ListaPos=ListaTXT[conter]
           ListaAlista=eval(ListaPos)
           Nombre=NombreDePais.get()
           if Nombre==ListaAlista[1]:
               return RevisarConCruceros(ListaAlista[0]) #SALIDA
           else:
                return VerificarEliminado_aux(ListaTXT,parada,conter+1)

    #E: NUMERO DE ID DE LA VERIFICACION DE LA FUNCION VerificarEliminado()
    #S: LA VERIFICACION COMPLETADA DEL ID
    #R: DEPENDE DE LA REVIFICACION DE LA FUNCION VerificarEliminado()
        
    def RevisarConCruceros(ID):
             AbrirTXTCruceros=open("cruceros.txt","r")
             LeerTXTCruceros=AbrirTXTCruceros.readlines()
             AbrirTXTCruceros.close()
             ListaTXT=LeerTXTCruceros
             LargoTXT=largo_crucero()
             return RevisarConCruceros_aux(ListaTXT,LargoTXT,ID,0)
    def RevisarConCruceros_aux(Lista,parada,ID,conter):
             if parada==conter:
                return validarPuerto() #SALIDA
             else:
                ListaPos=Lista[conter]
                ListaAlista=eval(ListaPos)
                if PerteneceID(ID,ListaAlista[-1]):
                   messagebox.showinfo("ERROR",message="EL Puerto Esta Asociado A Un Crucero. NO Puede Ser Eliminado")
                else:
                   return RevisarConCruceros_aux(Lista,parada,ID,conter+1)
                
    #E: UN ELEMENTO Y UNA LISTA
    #S: UN VALOR BOOLEANO
    #R: LA POSICION 2 DEBE SER UNA LISTA
                
    def PerteneceID(elemento,lista):
             if lista == []:
                False
             else:
                if elemento==lista[0]:
                   return True
                else:
                   return PerteneceID(elemento,lista[1:])
                
    #E: NOMBRE DEL PUERTO
    #S: UN NUMERO
    #R: DEPENDE DE LA FUNCION RevisarConCruceros()
        
    def validarPuerto():
        AbrirTXTPuerto= open("puertos.txt","r")
        LeerTXTPuerto=AbrirTXTPuerto.readlines()
        AbrirTXTPuerto.close()
        ListaTXT=LeerTXTPuerto
        LargoTXT=largo_puerto()
        return eliminarInformacionDelPuerto(ListaTXT,LargoTXT,0)
    def eliminarInformacionDelPuerto(ListaTXT,parada,conter):
        if parada==conter:
           messagebox.showinfo("ERROR",message="NO se Encontro Ese nombre")
        else:
           ListaEnpos=ListaTXT[conter]
           ListaAliata=eval(ListaEnpos)
           NombreAEliminar=NombreDePais.get()
           if NombreAEliminar==ListaAliata[1]:
                return EliminarDelTXT(conter) #SALIDA
           else:
                return eliminarInformacionDelPuerto(ListaTXT,parada,conter+1)
        
    #E: EL NUMERO ENVIADO POR LA FUNCION validarPuerto()
    #S: LA ELIMINACION COMPLETAD DE LA LINEA DEL TXT
    #R: DEPENDE DE LA VERIICACION DE LA FUNCION   validarPuerto()
        
    def EliminarDelTXT(pos):
        AbrirTXTCruceros=open("puertos.txt","r")
        LeerTXTCruceros=AbrirTXTCruceros.readlines()
        del LeerTXTCruceros[pos]
        AbrirTXTCruceros.close()
        ArchivoNuevo="".join(LeerTXTCruceros)
        AbrirTXTCruceros2=open("puertos.txt","w")
        AbrirTXTCruceros2.write(ArchivoNuevo)
        AbrirTXTCruceros2.close()
        messagebox.showinfo("Exito",message="Informacion Eliminada Con exito")
        
    boton1=Button(eliminar_puer,text="Eliminar",command=VerificarEliminado,font=("Buxton Sketch",13),bg="LightCyan").place(x=660,y=550)
    boton2=Button(eliminar_puer,text="Cancelar",font=("Buxton Sketch",13),command=eliminar_puer.destroy,bg="LightCyan").place(x=735,y=600)
    boton3=Button(eliminar_puer,text="Refrescar",font=("Buxton Sketch",13),command=eliminar_puerto,bg="LightCyan").place(x=820,y=550)
    eliminar_puer.mainloop()

#E: NOMBRE DEL CRUCERO
#S: ELIMINAR LA INFORMACION DEL CRUCERO INGRESADO
#R: EL CRUCERO NO PUEDE ESTAR ASOCIADO A UN TOUR

def eliminar_crucero(): 
    eliminar_crus=Toplevel()
    eliminar_crus.state("zoomed")
    imagen=PhotoImage(file="puerto.gif")
    imagen1=Label(eliminar_crus,image=imagen).place(x=80,y=0)
    eliminar_crus.title("Area De Eliminar Cruceros")
    #campo=Text(eliminar_puer,width=60) #para agragar el TXT en la pantalla#
    #txt=open("puertos.txt","r")
    #txtR=txt.read()
    #campo.insert(INSERT,txtR)
    #txt.close()
    #campo.place(x=430,y=30)
    #campo.config(state=DISABLED)
    titulo=Label(eliminar_crus,text="|NOMBRE |CAPACIDAD| CLASES|",font=("Buxton Sketch",10)).place(x=430,y=0)
    texto1=Label(eliminar_crus,text="Indicar Nombre Del Crucero Que Deseas Eliminar:",font=("Buxton Sketch",15),bg="LightCyan").place(x=570,y=450)
    EliminarTour=StringVar()
    cuadro6=Entry(eliminar_crus,width=20,textvariable= EliminarTour).place(x=700,y=500)

    #E: NOMBRE DEL CRUCERO
    #S: UN NUMERO
    #R: EL CRUCERO DEBE EXISTIR EN EL TXT DE CRUCEROS
    
    def VerificarEliminadoDecrucero():
        AbrirTXTcrucero=open("cruceros.txt","r")
        LeerTXTcrucero=AbrirTXTcrucero.readlines()
        AbrirTXTcrucero.close()
        ListaTXT=LeerTXTcrucero
        LargoTXT=largo_crucero()
        return VerificarEliminadoDeCrucero_aux(ListaTXT,LargoTXT,0)
    def VerificarEliminadoDeCrucero_aux(ListaTXT,parada,conter):
        if parada==conter:
           messagebox.showinfo("ERROR",message="El Puerto Ingresado No existe")
        else:
           ListaPos=ListaTXT[conter]
           ListaAlista=eval(ListaPos)
           NombreDeCrucero=EliminarTour.get()
           if NombreDeCrucero==ListaAlista[1]:
               return RevisarConTour(ListaAlista[0]) # SALIDA
           else:
                return VerificarEliminadoDeCrucero_aux(ListaTXT,parada,conter+1)
        
    #E: NUMERO DE ID ENVIADO LA FUNCION VerificarEliminadoDecrucero ()
    #S: VERIFICACION COMPLETADA DE LA EXISTENCIA DEL ID
    #R: DEPENDE DE LA FUNCION VerificarEliminadoDecrucero()
        
    def RevisarConTour(ID):
             AbrirTXTTour=open("tour.txt","r")
             LeerTXTCTour=AbrirTXTTour.readlines()
             AbrirTXTTour.close()
             ListaTXT=LeerTXTCTour
             LargoTXT=largo_tour()
             return RevisarConTour_aux(ListaTXT,LargoTXT,ID,0)
    def RevisarConTour_aux(Lista,parada,ID,conter):
             if parada==conter:
                return validarCrucero()#SALIDA
             else:
                ListaPos=Lista[conter]
                ListaAlista=eval(ListaPos)
                if ID==ListaAlista[1]:
                   messagebox.showinfo("ERROR",message="EL Puerto Esta Asociado A Un Crucero. NO Puede Ser Eliminado")
                else:
                   return RevisarConTour_aux(Lista,parada,ID,conter+1)
                
    #E: UN ELEMENTO Y UNA LISTA
    #S: UN VALOR BOOLEANO
    #R: LA POSICION 2 DEBE SER UNA LISTA
                
    def PerteneceIDTour(elemento,lista):
             if lista == []:
                False
             else:
                if elemento==lista[0]:
                   return True
                else:
                   return PerteneceIDTour(elemento,lista[1:])

    #E: VERIFICAR EXISTENCIA DEL ID EN EL TXT DE PUERTOS
    #S: NUMERO DE ID
    #E DEPENDE DE A FUNCION RevisarConTour()
    
    def validarCrucero():
        AbrirTXTCrucero= open("cruceros.txt","r")
        LeerTXTCrucero=AbrirTXTCrucero.readlines()
        AbrirTXTCrucero.close()
        ListaTXT=LeerTXTCrucero
        LargoTXT=largo_crucero()
        return eliminarInformacionDelCrucero(ListaTXT,LargoTXT,0)
    def eliminarInformacionDelCrucero(ListaTXT,parada,conter):
        if parada==conter:
           messagebox.showinfo("ERROR",message="NO se Encontro Ese nombre")
        else:
           ListaEnpos=ListaTXT[conter]
           ListaAliata=eval(ListaEnpos)
           NombreAEliminar=EliminarTour.get()
           if NombreAEliminar==ListaAliata[1]:
                return EliminarDelTXT(conter) #SALIDA
           else:
                return eliminarInformacionDelCrucero(ListaTXT,parada,conter+1)
        
    #E: NUMERO DE POSICION A ELIMINAR
    #S: ELIMINACION EXITOSA DE LA LINEA DEL TXT
    #R: DEPENDE DE LA VERIFICACION DE LA FUNCION validarCrucero()
               
    def EliminarDelTXT(pos):
        AbrirTXTCruceros=open("cruceros.txt","r")
        LeerTXTCruceros=AbrirTXTCruceros.readlines()
        del LeerTXTCruceros[pos]
        AbrirTXTCruceros.close()
        ArchivoNuevo="".join(LeerTXTCruceros)
        AbrirTXTCruceros2=open("cruceros.txt","w")
        AbrirTXTCruceros2.write(ArchivoNuevo)
        AbrirTXTCruceros2.close()
        messagebox.showinfo("Exito",message="Se Elimino Con exito El Crucero")
        return eliminar_crus()

    boton1=Button(eliminar_crus,text="Eliminar",command=VerificarEliminadoDecrucero,font=("Buxton Sketch",13),bg="LightCyan").place(x=710,y=550)
    boton2=Button(eliminar_crus,text="Salir",font=("Buxton Sketch",13),command=eliminar_crus.destroy,bg="LightCyan").place(x=800,y=550)
    eliminar_crus.mainloop()
    
#E: NOMBRE DE CRUCERO Y UNA FECHA
#S: ELIMINAR LA INFORMACION DEL TXT DE TOURS
#R: EL NOMBRE INGRESADO DEBE EXISTIR EN EL TXT DEL CRUCERO
    
def eliminar_tour(): 
    eliminar_tou=Toplevel()
    eliminar_tou.state("zoomed")
    imagen=PhotoImage(file="puerto.gif")
    imagen1=Label(eliminar_tou,image=imagen).place(x=80,y=0)
    eliminar_tou.title("Area De Eliminar Tour")
    #campo=Text(eliminar_tou,width=60) #para agragar el TXT en la pantalla#
    #txt=open("tour.txt","r")
    #txtR=txt.read()
    #campo.insert(INSERT,txtR)
    #txt.close()
    #campo.place(x=430,y=30)
    #campo.config(state=DISABLED)
    titulo=Label(eliminar_tou,text="|CRUCERO |FECHA| MONTO|",font=("Buxton Sketch",10)).place(x=430,y=0)
    texto1=Label(eliminar_tou,text="Indicar Nombre Del Crucero Asociado al Tour Que Deseas Eliminar:",font=("Buxton Sketch",15),bg="LightCyan").place(x=500,y=200)
    texto1=Label(eliminar_tou,text="Ingrese La Fecha Para Buscarlo:",font=("Buxton Sketch",15),bg="LightCyan").place(x=640,y=450)
    NombreCrucero=StringVar()
    FechaDeTour=StringVar()
    CuadroDeTexto=Entry(eliminar_tou,width=20,textvariable=NombreCrucero).place(x=700,y=250)
    CuadroDeTexto=Entry(eliminar_tou,width=20,textvariable=FechaDeTour).place(x=700,y=500)
    
    #E: NOMBRE DEL CRUCERO
    #S: NUMERO DE ID
    #R: EL NOMBRE DEL CRUVERO DEBE EXISTIR EN EL TXT DEL CRUCERO
    
    def BuscarLineaAeliminar():
        AbrirTXTCrucero=open("cruceros.txt","r")
        LeerTXTCrucero=AbrirTXTCrucero.readlines()
        AbrirTXTCrucero.close()
        ListaTXT=LeerTXTCrucero
        LargoTXT=largo_crucero()
        return BuscarLineaAeliminar_aux(ListaTXT,LargoTXT,0)
    def BuscarLineaAeliminar_aux(ListaTXT,parada,conter):
        if parada==conter:
           messagebox.showinfo("ERROR",message="NO Existe El Crucero Ingresado")
        else:
             ListaPosicion=ListaTXT[conter]
             ListaAlista=eval(ListaPosicion)
             Nombre=NombreCrucero.get()
             if Nombre==ListaAlista[1]:
                return VerificarIDConTour(ListaAlista[0]) #SALIDA 
             else:
                return BuscarLineaAeliminar_aux(ListaTXT,parada,conter+1)

    #E: NUMERO DE ID ENVIADO POR LA FUNCION BuscarLineaAeliminar()
    #S: UN NUMERO
    #R: DEPENDE DE LA VERIFICACION DE LA FUNCION BuscarLineaAeliminar()
        
    def VerificarIDConTour(ID):
        AbrirTXTTour=open("tour.txt","r")
        LeerTXTTour=AbrirTXTTour.readlines()
        AbrirTXTTour.close()
        ListaTXT=LeerTXTTour
        LargoTXt=largo_tour()
        return VerificarIDConTour_aux(ListaTXT,LargoTXt,ID,0)
    def VerificarIDConTour_aux(ListaTXT,parada,ID,conter):
        if parada==conter:
           messagebox.showinfo("ERROR",message="No existen Coincidencias")
        else:
           Listapos=ListaTXT[conter]
           ListaAlista=eval(Listapos)
           Fecha=FechaDeTour.get()
           Union=[ID,Fecha]
           if VerificarIDYPrecio(Union,ListaAlista):
              return EliminarDelTXT(conter) #SALIDA
           else:
              return VerificarIDConTour_aux(ListaTXT,parada,ID,conter+1)

    #E: [ID Y LISTA] Y LINEA A VERIFICAR
    #S: VALOR BOOLEANO
        
    def VerificarIDYPrecio(Lista,Texto):
        if Lista[0]==Texto[1] and Lista[1] == Texto[2]:
           return True
        else:
           return False
        
    #E: UN NUMERO ENVIADO POR LA FUNCION VerificarIDConTour()
    #S: ELIMINACION COMPLETADA DEL LA LINEA DEL TXT
    #R: DEPENDE DE LA VERIFICACION DE LA FUNCION VerificarIDConTour()
        
    def EliminarDelTXT(pos):
        AbrirTXTTour=open("tour.txt","r")
        LeerTXTTour=AbrirTXTTour.readlines()
        del LeerTXTTour[pos]
        AbrirTXTTour.close()
        NuevoArchivoDeTour="".join(LeerTXTTour)
        AbrirTXTTour2=open("tour.txt","w")
        AbrirTXTTour2.write(NuevoArchivoDeTour)
        AbrirTXTTour2.close()
        messagebox.showinfo("Exito",message="informacion Elimada Con Existo")
        return eliminar_tou()

    boton1=Button(eliminar_tou,text="Eliminar",command=BuscarLineaAeliminar,font=("Buxton Sketch",13),bg="LightCyan").place(x=710,y=550)
    boton2=Button(eliminar_tou,text="Salir",font=("Buxton Sketch",13),command=eliminar_tou.destroy,bg="LightCyan").place(x=800,y=550)
    eliminar_tou.mainloop()

#E: EL ACCESO A LAS AREAS DE AGREGADOS
#S: APERTURA DE LAS VENTANAS DE LA SELECCION
#R: DEBE PULSARSE UN BUTTON 

def ingreso(): #INGRESO A LAS FUNCIONES DE AGREGAR##
        ingreso=Toplevel()
        ingreso.state("zoomed")
        ingreso.title("Area De Mantenimientos")
        imagen1=PhotoImage(file="mante2.gif")
        imagen2=Label(ingreso,image=imagen1,relief="sunken").place(x=40,y=0)
        imagen3=PhotoImage(file="mante.gif")
        imagen4=Label(ingreso,image=imagen3,relief="sunken").place(x=550,y=180)
        ingreso.config(bg="black")
        boton1=Button(ingreso, text="Agregar Puerto",fg="white",command=agregar_puerto,bg="Cornsilk4",font=("Buxton Sketch",13)).place(x=630,y=230)
        boton2=Button(ingreso, text="Agregar Crucero",fg="white",command=agregar_crucero,bg="Cornsilk4",font=("Buxton Sketch",13)).place(x=622,y=305)
        boton3=Button(ingreso, text="Agregar Tour",fg="white",command=agregar_tour,bg="Cornsilk4",font=("Buxton Sketch",13)).place(x=636,y=377)
        boton4=Button(ingreso, text="Cerrar",fg="white",command=ingreso.destroy,bg="Cornsilk4",font=("Buxton Sketch",13)).place(x=583,y=543)
        ingreso.mainloop()

#E: ACCESO A LAS AREAS DE ELIMINADO
#S: APERTURA DE LAS VENTANAS DE LA SELECCION
#R: DEBE PULSARSE UN BUTTON
        
def ingreso_elim(): #INGRESO A LAS FUNCIONES DE ELIMINAR##
    ingreso_elima=Toplevel()
    ingreso_elima.state("zoomed")
    ingreso_elima.title("Area De Mantenimientos")
    imagen1=PhotoImage(file="mante2.gif")
    imagen2=Label(ingreso_elima,image=imagen1,relief="sunken").place(x=40,y=0)
    imagen3=PhotoImage(file="mante.gif")
    imagen4=Label(ingreso_elima,image=imagen3,relief="sunken").place(x=550,y=180)
    ingreso_elima.config(bg="black")
    boton1=Button(ingreso_elima, text="Eliminar Puerto",fg="white",command=eliminar_puerto,bg="Cornsilk4",font=("Buxton Sketch",14),relief="flat").place(x=633,y=225)
    boton2=Button(ingreso_elima, text="Eliminar Crucero",fg="white",command=eliminar_crucero,bg="Cornsilk4",font=("Buxton Sketch",14),relief="flat").place(x=625,y=300)
    boton3=Button(ingreso_elima, text="Eliminar Tour",fg="white",command=eliminar_tour,bg="Cornsilk4",font=("Buxton Sketch",14),relief="flat").place(x=636,y=377)
    boton4=Button(ingreso_elima, text="Cerrar",fg="white",command=ingreso_elima.destroy,bg="Cornsilk4",font=("Buxton Sketch",14),relief="flat").place(x=588,y=535)
    ingreso_elima.mainloop()

#E: PULSE DE UN BOTTON
#S: INGRESO A LA VENTANA PRICIPAL DEL AGREGADO Y ELIMINADO
#R: DEBE PULSAR EL BUTTON

def agre_elim(): 
    agre_elim=Toplevel()
    agre_elim.state("zoomed")
    agre_elim.title("Que Desea Realziar")
    imagen1=PhotoImage(file="mante2.gif")
    imagen2=Label(agre_elim,image=imagen1,relief="sunken").place(x=40,y=0)
    imagen3=PhotoImage(file="mante.gif")
    imagen4=Label(agre_elim,image=imagen3,relief="sunken").place(x=550,y=180)
    agre_elim.config(bg="black")
    boton1=Button(agre_elim, text="Agregar Datos",fg="white",command= ingreso,bg="Cornsilk4",font=("Buxton Sketch",14),relief="flat").place(x=635,y=225)
    boton2=Button(agre_elim, text="Eliminar Datos",fg="white",command=ingreso_elim,bg="Cornsilk4",font=("Buxton Sketch",14),relief="flat").place(x=635,y=300)
    boton2=Button(agre_elim, text="Cerrar",fg="white",command=agre_elim.destroy,bg="Cornsilk4",font=("Buxton Sketch",14,),relief="flat").place(x=665,y=372)
    agre_elim.mainloop()
    
#E. ENTRADA AL AREA DE MANTENIMIENTO
#S: VENTANAS DEL AREA DE MANTENIMIETO
#R: SE DEBE PRESIONAR UN BOTTON
    
def mantenimiento():
    vmant=Toplevel()
    vmant.geometry("800x300+270+100")
    vmant.title("Acceso Restrigido")
    imagen=PhotoImage(file="clave.gif")
    imagen1=Label(vmant,image=imagen).place(x=0,y=0)
    eti=Label(vmant,text="Digite Su Usuaro Y Contraseña",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=280,y=20)
    eti=Label(vmant,text="Usuario",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=280,y=80)
    eti=Label(vmant,text="Contraseña",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=280,y=130)
    Usuario=StringVar()
    Contraseña=StringVar()
    cuadro=Entry(vmant, width=20,textvariable=Usuario).place(x=400,y=80)
    cuadro=Entry(vmant,show="*" ,width=20,textvariable=Contraseña).place(x=400,y=130)
    def Ingresar():
        AbrirTctUC=open("usuarios y contraseñas.txt","r")
        LeerTxtUc=AbrirTctUC.readlines()
        AbrirTctUC.close()
        ListaTxt=LeerTxtUc
        Largo=conterDeLista(ListaTxt)
        return Ingresar_axu(ListaTxt,Largo,0)
    def Ingresar_axu(Lista,parada,conter):
        if conter==parada:
           messagebox.showinfo("Error",message="Datos Invalidos")
        else:
           Listapos=Lista[conter]
           listaAlista=eval(Listapos)
           ingresoDeUsu=Usuario.get()
           ContraDeUsu=Contraseña.get()
           if ingresoDeUsu==listaAlista[0] and ContraDeUsu==listaAlista[1]:
              return agre_elim()
           else:
              return Ingresar_axu(Lista,parada,conter+1)
        
    def NuevoUsuario():
        Usuario=Toplevel()
        Usuario.geometry("800x300+270+100")
        Usuario.title("Nuevos Usuarios")
        imagen=PhotoImage(file="clave.gif")
        imagen1=Label(Usuario,image=imagen).place(x=0,y=0)
        eti=Label(Usuario,text="Ingrese Los Datos Solicitados",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=50,y=20)
        eti=Label(Usuario,text="Nombre De Usuario:",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=50,y=80)
        eti=Label(Usuario,text="Contraseña:",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=50,y=130)
        eti=Label(Usuario,text="Numero De Cedula:",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=50,y=180)
        eti=Label(Usuario,text="De Ser Extrangero Digite El No. de Pasaporte",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=250,y=210)
        NombreUsuario=StringVar()
        ContraseñaUsuario=StringVar()
        CedulaUsuario=StringVar()
        cuadro=Entry(Usuario, width=20,textvariable=NombreUsuario).place(x=250,y=80)
        cuadro=Entry(Usuario,show=" ", width=20,textvariable=ContraseñaUsuario).place(x=250,y=130)
        cuadro=Entry(Usuario, width=20,textvariable=CedulaUsuario).place(x=250,y=180)
        def AgregarInformacion():
            if NombreUsuario.get()=="" or ContraseñaUsuario.get()=="" or CedulaUsuario.get()=="":
               messagebox.showinfo("Error",message="Todos los espacios deben ser llenados")
            else:
               AbrirTxtUC=open("usuarios y contraseñas.txt","a")
               Nombreus=NombreUsuario.get()
               Contraus=ContraseñaUsuario.get()
               Cedulaus=CedulaUsuario.get()
               Informacion=[Nombreus,Contraus,Cedulaus]
               AbrirTxtUC.write(str(Informacion) + "\n")
               AbrirTxtUC.close()
               messagebox.showinfo("Exito",message="Informacion Almacenada Con Exito")
               return mantenimiento()
        boton1=Button(Usuario,text="Agregar Informacion",command=AgregarInformacion,font=("Batang",11),bg="LightCyan",relief="groove").place(x=250, y=250)
        Usuario.mainloop()
        
    def OlvidoContraseña():
        Olvido=Toplevel()
        Olvido.geometry("800x300+270+100")
        Olvido.title("Nuevos Usuarios")
        imagen=PhotoImage(file="clave.gif")
        imagen1=Label(Olvido,image=imagen).place(x=0,y=0)
        eti=Label(Olvido,text="Ingrese Los Datos Solicitados",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=50,y=20)
        eti=Label(Olvido,text="Incluir Ceros",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=430,y=100)
        eti=Label(Olvido,text="Numero De Cedula:",font=("Batang",11),bg="LightCyan",relief="sunken").place(x=50,y=100)
        MostrarContra=StringVar()
        cuadro=Entry(Olvido, width=20,textvariable=MostrarContra).place(x=230,y=100)
        def BuscarContraseña():
            abrirTxtUC=open("usuarios y contraseñas.txt","r")
            LeerTXtUC=abrirTxtUC.readlines()
            ListaTXt=LeerTXtUC
            LargoTXT=conterDeLista(ListaTXt)
            return BuscarContraseña_aux(ListaTXt,LargoTXT,0)
        def BuscarContraseña_aux(Lista,Parada,conter):
            if Parada==conter:
               messagebox.showinfo("Error",message="La Informacion consultada no se encuentra en la base de datos")
            else:
               Listapos=Lista[conter]
               ListaAlista=eval(Listapos)
               Contra=MostrarContra.get()
               if Contra==ListaAlista[2]:
                  Resultado=str(ListaAlista[1])
                  messagebox.showinfo("Encontrada",message="Su Contraseña Es: " + Resultado)
               else:
                  return BuscarContraseña_aux(Lista,Parada,conter+1)
                
        boton1=Button(Olvido,text="Ver Contraseña",command=BuscarContraseña,font=("Batang",11),bg="LightCyan",relief="groove").place(x=250, y=150)
        Olvido.mainloop()
    def EliminarUsuario():
        messagebox.showinfo("Aviso",message="Disulpas Esta Area Esta En Mantenimiento")
    boton1=Button(vmant,text="Ingresar",command=Ingresar,font=("Batang",11),bg="LightCyan",relief="groove").place(x=320, y=170)
    boton2=Button(vmant,text="Salir",command= vmant.destroy,font=("Batang",11),bg="LightCyan",relief="groove").place(x=425, y=170)
    boton2=Button(vmant,text="Nuevo Usuario",command=NuevoUsuario,font=("Batang",11),bg="LightCyan",relief="groove").place(x=330, y=230)
    boton2=Button(vmant,text="Olvido Su Contraseña",command=OlvidoContraseña,font=("Batang",11),bg="LightCyan",relief="groove").place(x=600, y=230)
    boton2=Button(vmant,text="Eliminar Usuario",command=EliminarUsuario,font=("Batang",11),bg="LightCyan",relief="groove").place(x=30, y=230)
    vmant.mainloop()

#E: DATOS DE BUSQUEDA QUE EL USUARIO DESEA
#S: LOS RESULTADOS DE LA BUSQUEDA
#R: LOS ESPACIOS DEBEN CONTENER INFORMACION

def filtros():
    filtros=Toplevel()
    filtros.geometry("500x400+20+250")
    filtros.maxsize(500,400)
    filtros.minsize(500,400)
    filtros.resizable(width=False, height=False)
    imagen=PhotoImage(file="reserva.gif")
    imagen1=Label(filtros,image=imagen).place(x=-20,y=-250)
    filtros.config(bg="white")
    filtros.title("Filtros")
    Puerto=StringVar()
    Fecha=StringVar()
    Precio=IntVar()
    Cuadro1=Entry(filtros,width=40,textvariable=Puerto).place(x=100,y=210)
    Cuadro2=Entry(filtros,width=40,textvariable=Fecha).place(x=100,y=260)
    Cuadro3=Entry(filtros,width=40,textvariable=Precio).place(x=100,y=310)
    Etiqueta=Label(filtros,text="Esta Ventana Es Esclusiva Para realizar busquecas",bg="Deep Sky Blue",font=("Buxton Sketch",15),relief="flat").place(x=20,y=20)
    Etiqueta=Label(filtros,text="Filtrar Informacion Por",bg="Deep Sky Blue",font=("Buxton Sketch",13),relief="flat").place(x=20,y=120)
    Etiqueta=Label(filtros,text="Puerto",bg="Deep Sky Blue",font=("Buxton Sketch",13),relief="flat").place(x=20,y=200)
    Etiqueta=Label(filtros,text="Fecha",bg="Deep Sky Blue",font=("Buxton Sketch",13),relief="flat").place(x=20,y=250)
    Etiqueta=Label(filtros,text="Precio",bg="Deep Sky Blue",font=("Buxton Sketch",13),relief="flat").place(x=20,y=300)
    
    #E: UN ELEMENTO Y UNA LISTA
    #S: UN VALOR BOOLEANO
    #R: LA POSICION 2 DEBE SER UNA LISTA
    
    def PertenecePuerto(elemento,lista):
        if lista == []:
            False
        else:
            if elemento==lista[0]:
                return True
            else:
                return Pertenece(elemento,lista[1:])
        
    #E: RECIBE EL NUMERO DE ID DE UN CRUCERO
    #S: UNA LISTA CON LOS NOMBRES DE LOS IDS DE LOS PAISES ASOCIADOS A LOS IDS INGRESADOS
    #R: SE DEBE INGRESAR EL ID
        
    def BuscaPais(ID):
        TXTcruceros=open("cruceros.txt","r")
        LeerTXT=TXTcruceros.readlines()
        TXTcruceros.close()
        lista=LeerTXT
        largoTXT=largo_crucero()
        return BuscaPais_aux(lista,ID,0,largoTXT)
    def BuscaPais_aux(lista,ID,conter,parada):
        if parada==conter:
           messagebox.showinfo("Error",message="No existe Tal ID")   
        else:
           Lista1=lista[conter]
           ListaLista=eval(Lista1) 
           if PertenecePuerto(ID,ListaLista):
                Puertos=ListaLista[4]
                return BuscarPais2(Puertos) #SALIDA
                
           else:
                return BuscaPais_aux(lista,ID,conter+1,parada)
        
    #E: LISTA CON LOS IDS DE LOS PAISES ASOCIADO AL ID DEL CRUCERO
    #S: UNA LISTA CON LOS PAISES ASOCIADOS A LOS IDS
    #R: DEPENDE DE LA VERIFICACION DE LA FUNCION BuscaPais()

    def BuscarPais2(lista):
            AbrirTXTpuertos=open("puertos.txt","r")
            LeerTXTpuertos=AbrirTXTpuertos.readlines()
            AbrirTXTpuertos.close()
            TXTenLista=LeerTXTpuertos
            LargoTXT=largo_puerto()
            LargoListaIDpuertos=conterDeLista(lista)
            return BuscarPais3(TXTenLista,lista,0,LargoTXT-1,[])
    def BuscarPais3(ListaDeTXT,ListaDeIDpuertos,ConterTXT,LargoTXT,resultado):  
            if LargoTXT<ConterTXT:
                    if resultado == " ":
                        return False
                    else:
                        return resultado
            else:
                ListaTXTpos=ListaDeTXT[ConterTXT]
                ListaTXTlist=eval(ListaTXTpos)
                PosicionIDpais=ListaTXTlist[0]
                if PertenecePuerto(PosicionIDpais,ListaDeIDpuertos):
                        Nombrepais=ListaTXTlist[1]
                        return BuscarPais3(ListaDeTXT,ListaDeIDpuertos,ConterTXT+1,LargoTXT,resultado+[Nombrepais])
                else:
                        return BuscarPais3(ListaDeTXT,ListaDeIDpuertos,ConterTXT+1,LargoTXT,resultado)
    #E: CAMPO DE TEXTO
    #S: UN VALOR BOOLEANO
    #R: NINGUNA
                
    def verificadorPais(pais):
      if pais=="":
         return False
      else:
         return True

    #E: CAMPO DE TEXTO
    #S: UN VALOR BOOLEANO
    #R: NINGUNA
        
    def VerificadorDeFecha(fecha):
        if fecha=="":
            return False
        else:        
            return True
        
    #E: CAMPO DE TEXTO
    #S: UN VALOR BOOLEANO
    #R: NINGUNA
              
    def VerificadorDePrecio(precio):
        if precio==0:
            return False
        else:
            return True

    #E: UNA LISTA
    #S: LA CANTIDAD DE ELEMENTOS DE ESA LISTA
    #R: DEBE SER UNA LISTA
                       
    def LargoResultado(lista):
        if lista == []:
           return 0
        else:
           return 1 + LargoResultado(lista[1:])

    #E: EL RESULTADO DE LA BUSQUEDA
    #S: PASAR EL RESULTADO A UN STRING PARA SER PRESENTADO EN LA PANTALLA
    #R: DEPENDE DE LA FUNCION buscador()
        
    def Resultadofinal(Lista):
        AbrirTXTCruceros=open("cruceros.txt","r")
        LeerTXTCrueros=AbrirTXTCruceros.readlines()
        AbrirTXTCruceros.close()
        ListaTXT=LeerTXTCrueros
        LargoTXT=largo_crucero()
        return Resultadofinal_aux(ListaTXT,LargoTXT,Lista,0,"")
    def Resultadofinal_aux(ListaTXT,parada,lista,conter,Resultado):
        if parada==conter or lista==[]:
           ResultadoAstring=str(Resultado)
           return ResultadoAstring
        else:
            Listapos=ListaTXT[conter]
            ListaAlista=eval(Listapos)
            if Pertenece(ListaAlista[0],lista[0]):
                return Resultadofinal_aux(ListaTXT,parada,lista[1:],0,Resultado+str([[ListaAlista[1]]+lista[0][2:]])+"\n")
            else:
                return Resultadofinal_aux(ListaTXT,parada,lista,conter+1,Resultado)
        
    #E: LOS DATOS INGRADOS POR EL USUARIO
    #S: LOS RESULTADOS DE BUSQUEDA
    #R: DEPENDE DE LOS DATOS INGRESADOS POR EL USUARIO 
        
    def buscador():
        AbrirTXTtour=open("tour.txt","r")
        LeerTour=AbrirTXTtour.readlines()
        AbrirTXTtour.close()
        ListaTour=LeerTour
        LargoTXT=largo_tour()
        return buscador_aux(ListaTour,0,LargoTXT,[])
    def buscador_aux(lista,conter,parada,RES):
            if parada==conter :
              if RES==[]:
                messagebox.showinfo("Aviso",message="No Hubo Resultados de Busquedas")
              else:
                VentanaEmergente=Toplevel()
                VentanaEmergente.geometry("650x400+20+200")
                VentanaEmergente.title("Resutados De Busqueda")
                ResFinal=Resultadofinal(RES)
                CuadroDeTexto=Text(VentanaEmergente)
                CuadroDeTexto.insert(INSERT,ResFinal)
                CuadroDeTexto.place(x=0,y=0)
                return DatosDeReserva()
                VentanaEmergente.mainloop()
            else:
                listaPos=lista[conter]
                listaAlista=eval(listaPos) 
                Posicion=listaAlista[1] 
                ListaPaises=BuscaPais(Posicion)
                FechaDeTour=Fecha.get()
                PuertoDeTour=Puerto.get()
                PrecioDeTour=Precio.get()
                PosicionPrecio=listaAlista[5]
                PosicionFecha=listaAlista[2]
                if VerificadorDePrecio(PrecioDeTour):
                   if PrecioDeTour>=PosicionPrecio:
                      if VerificadorDeFecha(FechaDeTour):
                         if FechaDeTour==PosicionFecha:
                            if verificadorPais(PuertoDeTour):
                                if Pertenece(PuertoDeTour,ListaPaises):
                                   return buscador_aux(lista,conter+1,parada,RES+[listaAlista])
                                else:
                                   return buscador_aux(lista,conter+1,parada,RES)
                            else:
                                if PrecioDeTour==PosicionPrecio and FechaDeTour==PosicionFecha:
                                  return buscador_aux(lista,conter+1,parada,RES+[listaAlista])
                                else:
                                  return buscador_aux(lista,conter+1,parada,RES)
                         else:
                            return buscador_aux(lista,conter+1,parada,RES) 
                      else:
                         if (not(verificadorPais(PuertoDeTour))):
                            return buscador_aux(lista,conter+1,parada,RES+[listaAlista])
                         elif verificadorPais(PuertoDeTour):
                            if PrecioDeTour==PosicionPrecio and Pertenece(PuertoDeTour,ListaPaises):
                                return buscador_aux(lista,conter+1,parada,RES+[listaAlista])
                            else:
                                return buscador_aux(lista,conter+1,parada,RES)
                         else:
                            return buscador_aux(lista,conter+1,parada,RES+[listaAlista])
                   else:
                        return buscador_aux(lista,conter+1,parada,RES)
                         
                elif VerificadorDeFecha(FechaDeTour):
                     if FechaDeTour==PosicionFecha:
                           if verificadorPais(PuertoDeTour):
                              if Pertenece(PuertoDeTour,ListaPaises):
                                   return buscador_aux(lista,conter+1,parada,RES+[listaAlista])
                              else:
                                return buscador_aux(lista,conter+1,parada,RES)
                           else:
                              return buscador_aux(lista,conter+1,parada,RES+[listaAlista])
                     else:
                        return buscador_aux(lista,conter+1,parada,RES)
                elif verificadorPais(PuertoDeTour)and (not(VerificadorDeFecha(FechaDeTour))) and (not(VerificadorDePrecio(PrecioDeTour))):
                      if Pertenece(PuertoDeTour,ListaPaises):
                         return buscador_aux(lista,conter+1,parada,RES+[listaAlista])
                      else:
                         return buscador_aux(lista,conter+1,parada,RES)
                else:
                   return buscador_aux(lista,conter+1,parada,RES)
                

    Boton1=Button(filtros,text="Buscar",command=buscador,bg="Deep Sky Blue",font=("Buxton Sketch",14),relief="flat").place(x=100,y=350)
    Boton2=Button(filtros,text="Salir",bg="Deep Sky Blue",command=filtros.destroy,font=("Buxton Sketch",14),relief="flat").place(x=250,y=350)
    filtros.mainloop()

#E: NOMBRE DE CRUCERO Y FECHA
#S: UNA RESERVACION
#R: DEPENDE DE LS DATOS INGRESADOS POR EL USUARIO


def DatosDeReserva():
    DatosRecerva=Toplevel()
    DatosRecerva.geometry("400x300+705+500")
    DatosRecerva.maxsize(600,200)
    DatosRecerva.minsize(600,200)
    DatosRecerva.resizable(width=False, height=False)
    imagen=PhotoImage(file="reserva.gif")
    imagen1=Label(DatosRecerva,image=imagen).place(x=-705,y=-500)
    Etiqueta=Label(DatosRecerva,text="Si Deseas Reservar",font=("Buxton Sketch",15),bg="LightCyan").place(x=200,y=10)
    Etiqueta=Label(DatosRecerva,text="Nombre De Crucero",font=("Buxton Sketch",15),bg="LightCyan").place(x=50,y=70)
    Etiqueta=Label(DatosRecerva,text="Fecha",font=("Buxton Sketch",15),bg="LightCyan").place(x=380,y=70)
    NombreCrucero=StringVar()
    FechaTour=StringVar()

    #E: NOMBRE DEL CRUCERO
    #S: EL ID DEL CRUCERO
    #R: EL NOMBRE CRUCERO DEBE EXISTIR EN EL TXT DE CRUCEROS
    
    def CompletarReservacion():
        AbrirTXTcruceros=open("cruceros.txt","r")
        LeerTXTcruceros=AbrirTXTcruceros.readlines()
        AbrirTXTcruceros.close()
        ListaTXT=LeerTXTcruceros
        LargoTXT=largo_crucero()
        return CompletarReservacion_aux(ListaTXT,LargoTXT,0)
    def CompletarReservacion_aux(ListaTXT,parada,conter):
            if parada==conter:
                messagebox.showinfo("ERROR",message="NO Existen Coincidencias En la Base De Datos")
            else:
               ListaTXTPos=ListaTXT[conter]
               ListaAlista=eval(ListaTXTPos)
               PosicionDeNombreDeCrucero=ListaAlista[1]
               NombreCrus=NombreCrucero.get()
               if PosicionDeNombreDeCrucero == NombreCrus:
                  return RevisarDatos(ListaAlista[0]) #SALIDA
               else:
                  return CompletarReservacion_aux(ListaTXT,parada,conter+1)
                
    #E: UN NUMERO DE ID DE LA FUNCION CompletarReservacion()
    #S: UNA LISTA CON LOS DATOS VERIFICADOS
    #R DEPENDE DE LA VERIFICACION DE LA FUNCION CompletarReservacion()
                
    def RevisarDatos(ID):
        AbrirTXTtour=open("tour.txt","r")
        LeerTXTtour=AbrirTXTtour.readlines()
        AbrirTXTtour.close()
        ListaTXT=LeerTXTtour
        LargoTXT=largo_tour()
        return RevisarDatos_aux(ListaTXT,LargoTXT,ID,0)
    def RevisarDatos_aux(ListaTXT,parada,ID,conter):
        if parada==conter:
           messagebox.showinfo("Error",message="Este Crucero No Esta Programado para esta Fecha")
        else:
            ListaPoscion0=ListaTXT[conter]
            ListaAlista=eval(ListaPoscion0)
            PosicionDeIDenTXTtour=ListaAlista[1]
            Fecha=FechaTour.get()
            PosicionDeFechaEnTXT=ListaAlista[2]
            if ID == PosicionDeIDenTXTtour and Fecha==PosicionDeFechaEnTXT:
               return AgregarLaReservacion(ListaAlista) #SALIDA
            else:
               return RevisarDatos_aux(ListaTXT,parada,ID,conter+1)
        
    #E: UNA LISTA DE LA VERIFICACION DE LA FUNCION RevisarDatos()
    #S: UNA RESERCACION EXITO
    #R: DEPENDE DE LA FUNCION RevisarDatos()
        
    def AgregarLaReservacion(Lista):
            AbrirTXTReservaciones=open("Reservaciones.txt","a")
            ListaAStr=str(Lista)
            AbrirTXTReservaciones.write(ListaAStr+"\n")
            AbrirTXTReservaciones.close()
            messagebox.showinfo("Exito",message="Reversacion Completada")
            
    Cuadro1=Entry(DatosRecerva,width=15,textvariable=NombreCrucero).place(x=70,y=120)
    Cuadro2=Entry(DatosRecerva,width=15,textvariable=FechaTour).place(x=360,y=120)
    boton1=Button(DatosRecerva, text="Reservar",command=CompletarReservacion,bg="LightCyan",font=("Buxton Sketch",13),relief="flat").place(x=240,y=150)
    DatosRecerva.title("Reservar")
    DatosRecerva.mainloop()
    
#E: TOQUE DE UN BOTTON
#S: DESPLEGUE DE UNA VENTANA MOSTRANDO LOS TOURES
#R: SE BEBE PRESIONAR EL BOTTON

def VerTures():
    VentanaMuestraTour=Toplevel()
    VentanaMuestraTour.geometry("700x700+705+100")
    VentanaMuestraTour.maxsize(620,300)
    VentanaMuestraTour.minsize(620,300)
    VentanaMuestraTour.resizable(width=False, height=False)
    campo=Text(VentanaMuestraTour,width=75) #para agragar el TXT en la pantalla#
    txt=open("tour.txt","r")
    txtR=txt.readlines()
    MostrarTxt=PasarATXTParaAgregar(txtR)
    campo.insert(INSERT,MostrarTxt)
    campo.place(x=0,y=0)
    txt.close()
    return DatosDeReserva()
    VentanaMuestraTour.mainloop()
def PasarATXTParaAgregar(Lista):
    AbrirTXTcrucero=open("cruceros.txt","r")
    LeerTXTcruceros=AbrirTXTcrucero.readlines()
    ListaTXT=LeerTXTcruceros
    LargoTXT=largo_crucero()
    return PasarATXTParaAgregar_aux(ListaTXT,Lista,LargoTXT,0,"")
def PasarATXTParaAgregar_aux(TXTCruceros,TXTTour,paradaCrucero,ConterCrucero,Res):
    if  TXTTour == []:
        return Res
    else:
        PosTXTCruceros=TXTCruceros[ConterCrucero]
        EvalCrucero=eval(PosTXTCruceros)
        PosTXTTour=TXTTour[0]
        EvalTour=eval(PosTXTTour)
        Pos0Crucero=EvalCrucero[0]
        if Pertenece(Pos0Crucero,EvalTour):
           return PasarATXTParaAgregar_aux(TXTCruceros,TXTTour[1:],paradaCrucero,0,Res+str([EvalCrucero[1]]+EvalTour[2:])+"\n")
        else:
           return PasarATXTParaAgregar_aux(TXTCruceros,TXTTour,paradaCrucero,ConterCrucero+1,Res)
            
        
#E: TOQUE DE UN BOTTON
#S: INGRESO AL AREA DE RESERVACIONES Y VISTAS DE TOURES
#R: SE DEBE PRESIONAR UN BOTTON

def reservar():
    VentanaDeRervar=Toplevel()
    VentanaDeRervar.geometry("1366x768")
    VentanaDeRervar.maxsize(1366,768)
    VentanaDeRervar.minsize(1366,768)
    VentanaDeRervar.resizable(width=False, height=False)
    VentanaDeRervar.config(bg="gray")
    VentanaDeRervar.title("Reservaciones")
    imagen=PhotoImage(file="reserva.gif")
    imagen1=Label(VentanaDeRervar,image=imagen).place(x=0,y=0)
    boton1=Button(VentanaDeRervar, text="Buscar",command=filtros,bg="Deep Sky Blue",font=("Buxton Sketch",20),relief="flat").place(x=200,y=20)
    boton2=Button(VentanaDeRervar, text="Salir",bg="Deep Sky Blue",font=("Buxton Sketch",20),relief="flat",
                  command=VentanaDeRervar.destroy).place(x=210,y=100)
    boton3=Button(VentanaDeRervar,text="Ver Nuestos Toures Disponibles",command=VerTures,bg="Deep Sky Blue",font=("Buxton Sketch",20),relief="flat").place(x=350,y=20)
    VentanaDeRervar.mainloop()

     
#E: TOQUE DEL BOTTON
#S: APERTURA DEL AREA DE MANTENIMIENTO
#R: SE DEBE PRESIONAR UN BOTTON

def reservaciones():
    ventAbrir=Toplevel()
    ventAbrir.geometry("1366x768")
    ventAbrir.maxsize(1366,768)
    ventAbrir.minsize(1366,768)
    ventAbrir.resizable(width=False, height=False)
    ventAbrir.config(bg="gray")
    ventAbrir.title("Area De Reservaciones")
    imagen=PhotoImage(file="reserva.gif")
    imagen1=Label(ventAbrir,image=imagen).place(x=0,y=0)
    boton2=Button(ventAbrir, text="Reservar",command=reservar,bg="Deep Sky Blue",font=("Buxton Sketch",20),relief="flat").place(x=200,y=20)
    boton3=Button(ventAbrir, text="Salir",bg="Deep Sky Blue",font=("Buxton Sketch",20),relief="flat",
                  command=ventAbrir.destroy).place(x=210,y=100)
    ventAbrir.mainloop()

#E: PRESIONAR UN BOTTON
#S: ENTRADA A LA PANTALLA PRINCIPAL DEL PROGRAMA
#R  DEBE PRESIONARSE UN BOTON
    
ventana = Tk()
ventana.geometry("800x500+270+100")
ventana.maxsize(800,500)
ventana.minsize(800,500)
ventana.resizable(width=False, height=False)
ventana.config(bg="gray")
ventana.title("Tour Cruceros")
imagen=PhotoImage(file="fondo.gif")
imagen1=Label(ventana,image=imagen).place(x=0,y=0)
boton1=Button(ventana, text="RESERVACIONES",bg="LightCyan",font=("Buxton Sketch",13),
              command=reservaciones,relief="groove").place(x=100,y=0)
boton2=Button(ventana, text="MANTENIMIENTO",bg="LightCyan",font=("Buxton Sketch",13),
              command=mantenimiento,relief="groove").place(x=500,y=0)
boton3=Button(ventana, text="SALIR",bg="LightCyan",font=("Buxton Sketch",13),
              command=ventana.destroy,relief="groove").place(x=356,y=0)
ventana.mainloop()



         
