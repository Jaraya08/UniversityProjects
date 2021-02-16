from tkinter import *
from bs4 import BeautifulSoup
import urllib.request as ur
import requests
import html
import datetime
import time
from tkinter import ttk
from reportlab.pdfgen import canvas
import os

#E: RECIBE UNA PALABRA CLAVE, UN PAIS , UN AÑO Y UN MES
#S: RETORNA DE LA WEB LO QUE EL USUARIO SOLICITO CON LA PALABRA CLAVE
#R: DEPENDE DE LA PALABRA CLAVE ENVIADA

def FiltrarDatos(Exacto,Pais,año,mes):
    if Exacto=="Dias del mes":#este if saca todos los dias  del mes en una lista(pos[0]=Numero del dia,pos[1]=Nombre del dia#
        url="http://www.cuandoenelmundo.com/calendario/"+Pais+"/"+año+"/"+mes+""
        abrir=ur.urlopen(url).read()
        leer=BeautifulSoup(abrir,"html.parser")
        res=[]
        for Saca in leer.find_all("td",{"class","wday","dayno"}):
            res+=[Saca.text]
        return res
    elif Exacto=="Dias Festivos": #Este Elif saca todo los dias festivos del año correspondiente al año y Pais ingresado#
        url= "http://www.cuandoenelmundo.com/calendario/"+Pais+"/"+año+""
        abrir=ur.urlopen(url).read()
        leer=BeautifulSoup(abrir,"html.parser")
        for linea in leer.find_all("div",{"class":"calyr"}):
            for resultado in linea.find_all("table",{"class":"hdays"}):
                res=[]
                for ver in resultado.find_all("td"):
                    ver="".join(ver.text)
                    res+=[ver]
        Depurar=CortarUltimaPos(res)
        return Depurar
    elif Exacto=="Dias festivos por mes":#Este Elif saca todo los dias festivos del mes correspondiente al año y Pais ingresado#
        if Pais=="" or año=="" or mes=="":#Estas lineas del if se encargan de actualizar el programa al arranque##
            url= "http://www.cuandoenelmundo.com/calendario/costa-rica/"+str(datetime.datetime.now().year)+""
            abrir=ur.urlopen(url).read()
            leer=BeautifulSoup(abrir,"html.parser")
            for linea in leer.find_all("div",{"class":"calyr"}):
                for resultado in linea.find_all("table",{"class":"hdays"}):
                    res=[]
                    for ver in resultado.find_all("td"):
                        ver="".join(ver.text)
                        res+=[ver]
            Depurar=CortarUltimaPos(res)
            ConcatenarDatos=UnirDatos(0,3,res)
            FestividadesDelDia=Pertenece(mes,ConcatenarDatos)
            UnirDatos2=UnirDatos(0,3,FestividadesDelDia)
            return UnirDatos2 
        else:
            url= "http://www.cuandoenelmundo.com/calendario/"+Pais+"/"+año+""
            abrir=ur.urlopen(url).read()
            leer=BeautifulSoup(abrir,"html.parser")
            for linea in leer.find_all("div",{"class":"calyr"}):
                for resultado in linea.find_all("table",{"class":"hdays"}):
                    res=[]
                    for ver in resultado.find_all("td"):
                        ver="".join(ver.text)
                        res+=[ver]
            Depurar=CortarUltimaPos(res)
            ConcatenarDatos=UnirDatos(0,3,Depurar)
            FestividadesDelDia=Pertenece(mes,ConcatenarDatos)
            UnirDatos2=UnirDatos(0,3,FestividadesDelDia)
            return UnirDatos2

#:E EL NOMBRE DE UN MES 
#:S EL NOMBRE DEL MES ACTUAL
#:R NINGUNA

def verifivacionDeMes(mes,texto):
    DiaDelMes=datetime.datetime.now().month
    Meses=["enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"]
    NumeroMes=Meses.index(mes)+1
    if texto =="Mas":
        if NumeroMes>DiaDelMes:
            return True
    elif texto=="Hoy":
        if NumeroMes==DiaDelMes:
            return True
    
#E: NINGUNA
#S: EL MES ACTUAL
#R: DEPENDE DEL MES DEL AÑO
        
def MesActual():
    DiaDelMes=datetime.datetime.now().month
    Meses=["enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"]
    return Meses[DiaDelMes-1]


#E: UNA LISTA CON LOS DIAS FESTIVOS DEL MES 
#S: UNA NUEVA LISTA CON DIAS EN NUMEROS ENTEROS
#R: DEBE SER UNA LISTA

def SacarDias(Lista):
    if Lista ==[]:
        return []
    else:
        res=[]
        while Lista!=[]:
            res+=[int(Lista[0][0])]
            Lista=Lista[1:]
        return sorted(set(res))

#E: UNA LISTA CON LOS DIAS DEL MES 
#S: UNA LISTA CON LOS COLORES QUE PERTENECEN AL CALENDARIO
#R: DEPENDE DEL LOS DIAS FESTIVOS DEL MES 
    
def AsignarColoresAlCalendario(ListaDelosDias):
    DiasDelMes=FiltrarDatos("Dias festivos por mes",Pais.get().lower(),Año.get(),Mes.get().lower())
    SoloDias=SacarDias(DiasDelMes)
    res=[]
    while SoloDias!=[]:
        if SoloDias[0]==ListaDelosDias[0]:
            res+=["Coral"]
            SoloDias=SoloDias[1:]
            ListaDelosDias=ListaDelosDias[1:]
        else:
            res+=["Snow2"]
            ListaDelosDias=ListaDelosDias[1:]
    if ListaDelosDias!=[]:
        RestoDeColor=[]
        while ListaDelosDias!=[]:
            RestoDeColor+=["Snow2"]
            ListaDelosDias=ListaDelosDias[1:]
        return res+RestoDeColor
    if SoloDias==[]:
        RestoDeColor=[]
        while ListaDelosDias!=[]:
            RestoDeColor+=["Snow2"]
            ListaDelosDias=ListaDelosDias[1:]
        return RestoDeColor
    
#E: NINGUNA
#S: RECORDATORIO DE EVENTOS
#R: DEBEN HABER EVENTOS

def Recordatorios():
    RevisarActualidad=[str(datetime.datetime.now().day),MesActual().capitalize(),str(datetime.datetime.now().year)]
    VerTXT=AbrirTXT("Eventos.txt")
    for Recordar in VerTXT:
        ListaAlista=eval(Recordar)
        Recortar=ListaAlista[0:3]
        if list(RevisarActualidad)==list(Recortar):
            return messagebox.showinfo("Recordatorio",message="Hoy Tienes un evento:  "+ListaAlista[3]+"")
    return True
    
#E: RECIBE UN MES Y UNA LISTA 
#S: RETORNA UNA NUEVA LISTA CON LOS DATOS QUE TIENEN EL MES EN COMUN
#R: DEBE SER UNA LISTA Y EL MES UN STRING

def Pertenece(mes,Lista):
    res=[]
    while Lista!=[]:
        if mes==Lista[0][1]:
            res+=Lista[0]
            Lista=Lista[1:]
        else:
            Lista=Lista[1:]
    return res

#E: RECIBE UNA LISTA
#S: RETORNA LA LISTA SIN LA ULTIMA POSICION EN CASO DE SER VACIA
#R: DEBE SER UNA LISTA

def CortarUltimaPos(Lista):
    while Lista[-1]=="":
        Lista=Lista[:-1]
    return Lista
    

#E: TIENE UNA UNICA ENTRADA UN URL PREDETERMINADO
#S: DIAS FESTIVOS DE CADA PAIS 
#R: DEBE TENER ACCESO A INTERNET

def UnirDatos(Inicio,Final,Lista):
    Resultado=[]
    while Lista!= []:
        Resultado+=[Lista[Inicio:Final]]
        Lista=Lista[Final:]
    return Resultado

#E: RECIBE UNA LISTA CON LOS DIAS DEL MES 
#S: EL ULTIMO NUMERO DEL MES DEL AÑO
#R: DEPENDE DEL PARAMETRO ENVIADO

def UltimoDiaDelMes(res):
    return res[-1][0]

#E: RECIBE UNA LISTA CON LOS DIAS DEL MES 
#S: EL DIA CON EL QUE ARRANCA ESE MES
#R: DEPENDE DEL PARAMETRO ENVIADO

def DiaDeInicio(res):
    return res[0][1]

#E: RECIBE EL NUMERO DE LA FUNCION UltimoDiaDelMes() 
#S: RETORNA EN UNA LISTA CON  LOS DIAS QUE CORRESPONDEN A ESE MES
#R: DEPENDE DEL LA FUNCION UltimoDiaDelMes ()

def DefinirDiasDelMes(numero):
    res=[]
    for numeros in range(1,numero+1):
        res+=[numeros]
    return res

#E: UN TXT
#S: EL TXT EN FORMA DE LISTA MEDIANTE ATRIBUTO READLINES
#R: DEBE SER UN TXT

def AbrirTXT(txt):
    Abrir=open(txt,"r")
    LeerTXt=Abrir.readlines()
    Abrir.close()
    return LeerTXt

#E: RECIBE UN DIA Y LOS DIAS DEL MES
#S: EN VALOR BOOLEANO SI EL DIA PERTENECE A LA LISTA DE DIAS DEL MES
#R: EL DIA DEBE PERTENECER A LA LIST DE DIAS DEL MES 

def ConfirmarDiaEnElMes(dia,lista):
    while lista!=[]:
        if int(dia)==lista[0]:
            return True
        else:
            lista=lista[1:]
    return False
    
        
#E: EL PRIMER DIAS DEL MES Y UNA LISTA CON LOS DIAS CORRESPONDIENTES AL MES
#S: LOS DIAS DEL MES ORDENADOS SEGUN EL PRIMER DIA DEL MES
#R: LA LISTA DEBE TRAER NUMEROS ENTEROS Y EL DIA DEBE SER UN STRING

def OrdenerCalendario(dia,res):
    if dia =="lunes": 
        return res+[X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X]
    elif dia=="martes":
        return [X]+res+[X,X,X,X,X,X,X,X,X,X,X,X,X,X,X]
    elif dia=="miércoles":
        return [X,X]+res+[X,X,X,X,X,X,X,X,X,X,X,X,X,X]
    elif dia=="jueves":
        return [X,X,X]+res+[X,X,X,X,X,X,X,X,X,X,X,X]
    elif dia=="viernes":
        return [X,X,X,X]+res+[X,X,X,X,X,X,X,X,X,X,X,X]
    elif dia=="sábado":
        return [X,X,X,X,X]+res+[X,X,X,X,X,X,X,X,X,X,X,X,X]
    elif dia=="domingo":
        return [X,X,X,X,X,X]+res+[X,X,X,X,X,X,X,X,X,X]

#E: RECIBE LOS STRINGVAR QUE ESTEN EN LOS TEXTVARIABLES
#S: RETORNA EL CALENDARIO ORDENADO SEGUN AÑO, ES Y PAIS 
#R: DEPENDE DE LOS DATOS INGRESADOS POR EL USUARIO 

def saca(Pais,año,mes):
    global Calendario
    global ColorDeFestivos
    try:
        if Pais=="" or año=="" or mes=="": # Este es una funcion prederminada de inicio
            url="http://www.cuandoenelmundo.com/calendario/costa-rica/2016/"+MesActual()+""
            abrir=ur.urlopen(url).read()
            leer=BeautifulSoup(abrir,"html.parser")
            res=[]
            for Saca in leer.find_all("td",{"class","wday","dayno"}):
                res+=[Saca.text]
            recortar=UnirDatos(0,2,res)
            PrimerDia=DiaDeInicio(recortar)#Dia de donde Arance el mes#
            DiaFinalDelMes=UltimoDiaDelMes(recortar)#Ultimo Dia del mes#
            DiasDelMes=DefinirDiasDelMes(int(DiaFinalDelMes))#Los dias que comprenden el mes#
            Calendario=OrdenerCalendario(PrimerDia,DiasDelMes)#Los dias del mes ordenados en una lista#
            ColorDeFestivos=AsignarColoresAlCalendario(Calendario)
            TodaLaPasta=TableDeCalendario(Calendario,ColorDeFestivos)#Ordenar los dias en los botones#
        else:
            ResltadoDebusqueda=FiltrarDatos("Dias del mes",Pais,año,mes)
            recortar=UnirDatos(0,2,ResltadoDebusqueda)
            PrimerDia=DiaDeInicio(recortar)#dia de donde Aranca el mes
            DiaFinalDelMes=UltimoDiaDelMes(recortar)#ultimo Dia del mes
            DiasDelMes=DefinirDiasDelMes(int(DiaFinalDelMes))#los dias que comprender el mes
            Calendario=OrdenerCalendario(PrimerDia,DiasDelMes)#Los dias del mes ordenados en una lista#
            ColorDeFestivos=AsignarColoresAlCalendario(Calendario)
            ColoesDeEventos=AsiganerColoresDeEventos()
            TodaLaPasta=TableDeCalendario(Calendario,ColorDeFestivos)#Ordenar los dias en los botones#
    except:
        messagebox.showerror("ERROR",message="No se puedo conectar con el servidor intente de nuevo")
        
#E: NINGUNA
#S: ASIGANA COLORES AL CALENDARIO SEGUN LOS EVENTOS QUE HAYA EN ESE MOMENTO
#R: DEBEN EXISTIR EVENTOS

def AsiganerColoresDeEventos():
    VerTXT=AbrirTXT("Eventos.txt")
    while VerTXT!=[]:
        ListaAlista=eval(VerTXT[0])
        Recorte=ListaAlista[0:3]
        Verificar=[ListaAlista[0],Mes.get(),Año.get()]
        if Mes.get()==ListaAlista[1]:
            Dias=DiasEventos()
            Posiciones=PosicionesDeEventosEnCalendario(Dias)
            TodosLosDelMes=ColoresDeEventosDelMes(Posiciones)
            return TodosLosDelMes  
        else:
            VerTXT=VerTXT[1:]    
    return ColorDeFestivos

#E: EL MES QUE INGRESE EL USUARIO
#S: LOS DIAS DEL MES QUE TIENEN EVENTOS
#R: DEBEN EXISTIR DIAS CON EVENTO ESE MES

def DiasEventos():
    VerTXT=AbrirTXT("Eventos.txt")
    res=[]
    while VerTXT!=[]:
        ListaAlista=eval(VerTXT[0])
        if Mes.get()==ListaAlista[1] and Año.get()==ListaAlista[2]:
            res+=[ListaAlista[0]]
            VerTXT=VerTXT[1:]
        else:
            VerTXT=VerTXT[1:]
    return res
    
#E: UNA LISTA CON LOS DIAS QUE TIENEN EVENTOS
#S: UNA NUEVA LISTA CON LAS POSICIONES EN LA LISTA DE ESOS DIAS
#R: LA LISTA DEBE CONTENER NUMEROS ENTEROS

def PosicionesDeEventosEnCalendario(Lista):
    res=[]
    while Lista!=[]:
        if ConfirmarDiaEnElMes(Lista[0],Calendario):
            Poscis=Calendario.index(int(Lista[0]))
            res+=[Poscis]
            Lista=Lista[1:]
        else:
            Lista=Lista[1:]
    return res

#E: UNA LISTA CON LA POSICION DE LOS DIAS QUE TIENEN EVENTOS
#S: UNA LISTA DE COLORES ACTUALIZADA
#R: NINGUNA

def ColoresDeEventosDelMes(Lista):
    while Lista!=[]:
        ColorDeFestivos[int(Lista[0])]="Chartreuse"
        Lista=Lista[1:]
    return ColorDeFestivos     

#E: LOS DIAS DEL MES Y COLORES DE EVENTO Y FESTIVIDAD
#S: BOTONES CON LOS DIAS ORDENADOS SEGUN EL PARAMETRO REIBIDO // SENCIBLE A AÑOS BISIESTOS
#R: Depende del año y el mes ingresado // 

def TableDeCalendario(orden,color):
    Etiqueta=Label(AgendaVirtual,text="Calendario",font=("Lucida Handwriting",20)).place(x=845,y=20)
    botonL=Button(AgendaVirtual,text="L",width=4,height=2,relief="sunken",bg="LightCyan",).place(x=800,y=60)
    botonM=Button(AgendaVirtual,text="K",width=4,height=2,relief="sunken",bg="LightCyan").place(x=840,y=60)
    botonK=Button(AgendaVirtual,text="M",width=4,height=2,relief="sunken",bg="LightCyan").place(x=880,y=60)
    botonJ=Button(AgendaVirtual,text="J",width=4,height=2,relief="sunken",bg="LightCyan").place(x=920,y=60)
    botonV=Button(AgendaVirtual,text="V",width=4,height=2,relief="sunken",bg="LightCyan").place(x=960,y=60)
    botonS=Button(AgendaVirtual,text="S",width=4,height=2,relief="sunken",bg="LightCyan").place(x=1000,y=60)
    botonD=Button(AgendaVirtual,text="D",width=4,height=2,relief="sunken",bg="Orange Red").place(x=1040,y=60)
    boton1=Button(AgendaVirtual,text=orden[0],width=4,height=2,relief="sunken",bg=color[0]).place(x=800,y=102)
    boton2=Button(AgendaVirtual,text=orden[1],width=4,height=2,relief="sunken",bg=color[1]).place(x=840,y=102)
    boton3=Button(AgendaVirtual,text=orden[2],width=4,height=2,relief="sunken",bg=color[2]).place(x=880,y=102)
    boton4=Button(AgendaVirtual,text=orden[3],width=4,height=2,relief="sunken",bg=color[3]).place(x=920,y=102)
    boton5=Button(AgendaVirtual,text=orden[4],width=4,height=2,relief="sunken",bg=color[4]).place(x=960,y=102)
    boton6=Button(AgendaVirtual,text=orden[5],width=4,height=2,relief="sunken",bg=color[5]).place(x=1000,y=102)
    boton7=Button(AgendaVirtual,text=orden[6],width=4,height=2,relief="sunken",bg=color[6]).place(x=1040,y=102)
    boton8=Button(AgendaVirtual,text=orden[7],width=4,height=2,relief="sunken",bg=color[7]).place(x=800,y=144)
    boton9=Button(AgendaVirtual,text=orden[8],width=4,height=2,relief="sunken",bg=color[8]).place(x=840,y=144)
    boton10=Button(AgendaVirtual,text=orden[9],width=4,height=2,relief="sunken",bg=color[9]).place(x=880,y=144)
    boton11=Button(AgendaVirtual,text=orden[10],width=4,height=2,relief="sunken",bg=color[10]).place(x=920,y=144)
    boton12=Button(AgendaVirtual,text=orden[11],width=4,height=2,relief="sunken",bg=color[11]).place(x=960,y=144)
    boton13=Button(AgendaVirtual,text=orden[12],width=4,height=2,relief="sunken",bg=color[12]).place(x=1000,y=144)
    boton14=Button(AgendaVirtual,text=orden[13],width=4,height=2,relief="sunken",bg=color[13]).place(x=1040,y=144)
    boton15=Button(AgendaVirtual,text=orden[14],width=4,height=2,relief="sunken",bg=color[14]).place(x=800,y=186)
    boton16=Button(AgendaVirtual,text=orden[15],width=4,height=2,relief="sunken",bg=color[15]).place(x=840,y=186)
    boton17=Button(AgendaVirtual,text=orden[16],width=4,height=2,relief="sunken",bg=color[16]).place(x=880,y=186)
    boton18=Button(AgendaVirtual,text=orden[17],width=4,height=2,relief="sunken",bg=color[17]).place(x=920,y=186)
    boton19=Button(AgendaVirtual,text=orden[18],width=4,height=2,relief="sunken",bg=color[18]).place(x=960,y=186)
    boton20=Button(AgendaVirtual,text=orden[19],width=4,height=2,relief="sunken",bg=color[19]).place(x=1000,y=186)
    boton21=Button(AgendaVirtual,text=orden[20],width=4,height=2,relief="sunken",bg=color[20]).place(x=1040,y=186)
    boton22=Button(AgendaVirtual,text=orden[21],width=4,height=2,relief="sunken",bg=color[21]).place(x=800,y=228)
    boton23=Button(AgendaVirtual,text=orden[22],width=4,height=2,relief="sunken",bg=color[22]).place(x=840,y=228)
    boton24=Button(AgendaVirtual,text=orden[23],width=4,height=2,relief="sunken",bg=color[23]).place(x=880,y=228)
    boton25=Button(AgendaVirtual,text=orden[24],width=4,height=2,relief="sunken",bg=color[24]).place(x=920,y=228)
    boton26=Button(AgendaVirtual,text=orden[25],width=4,height=2,relief="sunken",bg=color[25]).place(x=960,y=228)
    boton27=Button(AgendaVirtual,text=orden[26],width=4,height=2,relief="sunken",bg=color[26]).place(x=1000,y=228)
    boton28=Button(AgendaVirtual,text=orden[27],width=4,height=2,relief="sunken",bg=color[27]).place(x=1040,y=228)
    boton29=Button(AgendaVirtual,text=orden[28],width=4,height=2,relief="sunken",bg=color[28]).place(x=800,y=270)
    boton30=Button(AgendaVirtual,text=orden[29],width=4,height=2,relief="sunken",bg=color[29]).place(x=840,y=270)
    boton31=Button(AgendaVirtual,text=orden[30],width=4,height=2,relief="sunken",bg=color[30]).place(x=880,y=270)
    boton32=Button(AgendaVirtual,text=orden[31],width=4,height=2,relief="sunken",bg=color[31]).place(x=920,y=270)
    boton33=Button(AgendaVirtual,text=orden[32],width=4,height=2,relief="sunken",bg=color[32]).place(x=960,y=270)
    boton34=Button(AgendaVirtual,text=orden[33],width=4,height=2,relief="sunken",bg=color[33]).place(x=1000,y=270)
    boton35=Button(AgendaVirtual,text=orden[34],width=4,height=2,relief="sunken",bg=color[34]).place(x=1040,y=270)
    boton36=Button(AgendaVirtual,text=orden[35],width=4,height=2,relief="sunken",bg=color[35]).place(x=800,y=312)
    boton37=Button(AgendaVirtual,text=orden[36],width=4,height=2,relief="sunken",bg=color[36]).place(x=840,y=312)
    boton38=Button(AgendaVirtual,text=orden[37],width=4,height=2,relief="sunken",bg=color[37]).place(x=880,y=312)
    boton39=Button(AgendaVirtual,text=orden[38],width=4,height=2,relief="sunken",bg=color[38]).place(x=920,y=312)
    boton40=Button(AgendaVirtual,text=orden[39],width=4,height=2,relief="sunken",bg=color[39]).place(x=960,y=312)
    boton41=Button(AgendaVirtual,text=orden[40],width=4,height=2,relief="sunken",bg=color[40]).place(x=1000,y=312)
    boton42=Button(AgendaVirtual,text=orden[41],width=4,height=2,relief="sunken",bg=color[41]).place(x=1040,y=312)
    
    
############################################AGENDA UNIVERSAL##########################################

AgendaVirtual=Tk()
AgendaVirtual.title("Agenda Universal")
AgendaVirtual.geometry("1200x600+80+50")
AgendaVirtual.resizable(width=False, height=False)
Etiqueta=Label(AgendaVirtual,text="Dias Festivos // Eventos",font=("Lucida Handwriting",20)).place(x=50,y=10)
Etiqueta=Label(AgendaVirtual,text="| Dia  | Mes  |  Festividad | // | Dia  | Mes  |  Año | Evento ",font=("Lucida Handwriting",10)).place(x=18,y=60)
Etiqueta1=Label(AgendaVirtual,text="Escoja un Pais",font=("Lucida Handwriting",15)).place(x=590,y=80)
Etiqueta2=Label(AgendaVirtual,text="Escoja un Año:",font=("Lucida Handwriting",15)).place(x=590,y=150)
Etiqueta3=Label(AgendaVirtual,text="Escoja el Mes:",font=("Lucida Handwriting",15)).place(x=590,y=230)
Etiqueta4=Label(AgendaVirtual,text="Crear un evento:",font=("Lucida Handwriting",15)).place(x=580,y=410)
Etiqueta4=Label(AgendaVirtual,text="Area Exclusiva Para Eventos",font=("Lucida Handwriting",11)).place(x=800,y=370)
Etiqueta4=Label(AgendaVirtual,text="___________________________________________________________________________",
                font=("Lucida Handwriting",11)).place(x=580,y=390)
Etiqueta5=Label(AgendaVirtual,text="Dia:",font=("Lucida Handwriting",15)).place(x=580,y=450)
Etiqueta6=Label(AgendaVirtual,text="Mes:",font=("Lucida Handwriting",15)).place(x=780,y=450)
Etiqueta7=Label(AgendaVirtual,text="Año:",font=("Lucida Handwriting",15)).place(x=980,y=450)
Etiqueta=Label(AgendaVirtual,text="Estimados usuario para crear o eliminar un evento puede usar los mismos botones"
               ,font=("Baskerville Old Face",12)).place(x=650,y=550)
Etiqueta=Label(AgendaVirtual,text="Dia - Año - Mes",font=("Baskerville Old Face",12)).place(x=870,y=570)
Pais=StringVar()
Año=StringVar()
Mes=StringVar()
Eventos=StringVar()
Dia=StringVar()
AñoEvento=StringVar()
MesesEvento=StringVar()
Combobox1=ttk.Combobox(AgendaVirtual,width=20,textvariable=Pais,state="readonly")
Combobox2=ttk.Combobox(AgendaVirtual,width=20,textvariable=Año,state="readonly")
Combobox3=ttk.Combobox(AgendaVirtual,width=20,textvariable=Mes,state="readonly")
Combobox4=ttk.Combobox(AgendaVirtual,width=15,textvariable=Dia,state="readonly")
Combobox5=ttk.Combobox(AgendaVirtual,width=15,textvariable=AñoEvento,state="readonly")
Combobox6=ttk.Combobox(AgendaVirtual,width=15,textvariable=MesesEvento,state="readonly")
CuadroDeTexto=Entry(AgendaVirtual,textvariable=Eventos,width=55).place(x=800,y=417)
Combobox1.config(value=("Argentina","Belgica","Bolivia","Brasil","Canada","Chile","Colombia","Costa-Rica",
                        "Cuba","Dinamarca","Ecuador","El-Salvador","Espana","Estados-Unidos","Finlandia",
                        "Francia","Guatemala","Honduras","Islandia","Mexico","Nicaragua",
                        "Noruega","Paises-Bajos","Panama","Paraguay","Peru", "Portugal",
                        "Republica-Dominicana","Suecia","Uruguay","Venezuela"))
Combobox2.config(value=("1990","1991","1992","1993","1994","1995","1996","1997","1998",
                        "1999","2000","2001","2002","2003","2004","2005","2006","2007","2008",
                        "2009","2010","2011","2012","2013","2014","2015","2016","2017","2018","2019","2020"))
Combobox3.config(value=("Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre",
                        "Octubre","Noviembre","Diciembre"))
Combobox4.config(value=("1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21",
                        "22","23","24","25","26","27","28","29","30","31"))
Combobox5.config(value=("2016","2017","2018","2019","2020"))
Combobox6.config(value=("Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre",
                        "Octubre","Noviembre","Diciembre"))
Combobox1.place(x=600,y=120)
Combobox2.place(x=600,y=200)
Combobox3.place(x=600,y=280)
Combobox4.place(x=655,y=455)
Combobox5.place(x=1055,y=455)
Combobox6.place(x=855,y=455)

#E: RECIBE EL NOMBRE DEL PAIS, AÑO, Y MES
#S: DIAS FESTIVOS DEL MES INGRESADO
#R: LOS ESPACIOS DEBEN ESTAR LLENOS

def DiasFestivos():
    if Pais.get()=="" or Año.get()=="" or Mes.get()=="":
        messagebox.showinfo("ADVERTENCIA",message="Favor llenar todos los espacios de esta columna")
    else:
        FestivosDelMes=FiltrarDatos("Dias festivos por mes",Pais.get().lower(),Año.get(),Mes.get().lower())
        lis=Listbox(AgendaVirtual,width=70,height=27)
        lis2=Listbox(AgendaVirtual,width=70,height=27)
        if FestivosDelMes==[]:
            saca(Pais.get().lower(),Año.get(),Mes.get().lower())
            lis2.insert(0,"No hay dias Festivos")
            lis2.place(x=20,y=90)
            messagebox.showinfo("AVISO",message="Este mes no tiene dias Festivos")
        else:
            for Dias in FestivosDelMes:
                lis.insert(END,str(Dias[0]+"  |  "+Dias[1]+" |  "+Dias[2])+"\n")
            lis.place(x=20,y=90)
            saca(Pais.get().lower(),Año.get(),Mes.get().lower())

#E: DATOS INGRESADOS POR EL USUARIO
#S: TODOS LOS DIAS FESTIVOS Y FESTIVIDADES DEL AÑO Y PAIS INGRESADO POR EL USUARIO
#R: DEPENDE DE LA FUENTE DE INTENET

def VerFestivosAnuales():
    if Pais.get()=="" or Año.get()=="": 
        messagebox.showinfo("ADVERTENCIA",message="LLenar los espacios Pais y Año")
    else:
        DiasFestivos=FiltrarDatos("Dias Festivos",Pais.get().lower(),Año.get(),Mes.get().lower())
        ConcatenarDatos=UnirDatos(0,3,DiasFestivos)
        lis=Listbox(AgendaVirtual,width=70,height=27)
        for Anuales in ConcatenarDatos:
            lis.insert(END,str(Anuales[0]+"  |  "+Anuales[1]+" |  "+Anuales[2])+"\n")
        lis.place(x=20,y=90)
        saca(Pais.get().lower(),Año.get(),Mes.get().lower())
            
        
#E: AÑO, MES, DIA Y EL EVENTO 
#S: GUARDAR EL ENVENTO DENTRO DE UN TXT
#R: POR SER EN TIEMPO REAL LOS EVENTOS DEBEN AGREGARSE EN DIA ACTUAL O SUPERIOS A ESE DIA DE LO CONTRARIO NO SE GUARDARA EL EVENTO
 
def CrearEvento():
    AñoActual=datetime.datetime.now().year
    DiaActual=datetime.datetime.now().day
    if AñoEvento.get()=="" or MesesEvento.get()==""or Dia.get()=="":
        messagebox.showinfo("Aviso",message="Se deben llenar todos los espacios de la fila de abajo")
    else:
        if int(AñoEvento.get())>AñoActual:
            if Eventos.get()!="":
                if VerificarEventoRepetido():
                    return GuardarEvento()
                else:
                    messagebox.showinfo("Aviso",message="No se puede guardar mas de un evento por dia")
            else:
                messagebox.showinfo("Aviso",message="El campo de texto de evento debe tener caracteres")
        else:
            if int(AñoEvento.get())==AñoActual:
                if verifivacionDeMes(MesesEvento.get().lower(),"Mas"):
                    if Eventos.get()!="":
                        if VerificarEventoRepetido():
                            return GuardarEvento()
                        else:
                            messagebox.showinfo("Aviso",message="No se puede guardar mas de un evento por dia")
                    else:
                        messagebox.showinfo("Aviso",message="El campo de texto de evento debe tener caracteres")
                else:
                    if verifivacionDeMes(MesesEvento.get().lower(),"Hoy"):
                        if int(Dia.get())>=DiaActual:
                            if Eventos.get()!="":
                                if VerificarEventoRepetido():
                                    return GuardarEvento()
                                else:
                                    messagebox.showinfo("Aviso",message="No se puede guardar mas de un evento por dia")
                            else:
                                messagebox.showinfo("Aviso",message="El campo de texto de evento debe tener caracteres")
                        else:
                            messagebox.showinfo("Aviso",message="No puedes guardar eventos en el pasado")
                    else:
                        messagebox.showinfo("Aviso",message="No puedes guardar eventos en el pasado")
                                       
#E: DEPENDE DE LA FUNCION CrearEvento()
#S: ACTUALIZACION DEL COLOR DEL DIA DEL MES DONDE SE AGREGO EL EVENTO
#R: DEPENDE DE LA FUNCION CrearEvento()

def GuardarEvento():
    saca("costa-rica",AñoEvento.get(),MesesEvento.get().lower())
    if ConfirmarDiaEnElMes(Dia.get(),Calendario):
        Evento=str([Dia.get(),MesesEvento.get(),AñoEvento.get(),Eventos.get().capitalize()])
        AbrirTXT=open("Eventos.txt","a")
        Escribir=AbrirTXT.write(Evento+"\n")
        AbrirTXT.close()
        MostrarEventos()
        messagebox.showinfo("Aviso",message="Evento guardado con exito")
    else:
        messagebox.showinfo("Aviso",message="El dia escogido no existe en este mes")

#E: AÑO, MES, DIA
#S: UN VALOR BOOLEANO, FALSE SI EL EVENTO EXISTE Y TRUE SI NO EXISTE 
#R: NINGUNA
    
def VerificarEventoRepetido():
    VerTXT=AbrirTXT("Eventos.txt")
    Conter=0
    while len(VerTXT)>Conter:
        ListaAlista=eval(VerTXT[Conter])
        if ListaAlista[2]==AñoEvento.get() and ListaAlista[1]==MesesEvento.get() and ListaAlista[0]==Dia.get():
            return False
        Conter+=1
    return True

#E: ACCION DE UN BOTON 
#S: LOS EVENTOS DISPONIBLES
#R: DEBEN EXISTIR EVENTOS

def MostrarEventos():
    VerTXT=AbrirTXT("Eventos.txt")
    if VerTXT==[]:
        messagebox.showinfo("Aviso",message="No hay eventos")
    else:   
        lis=Listbox(AgendaVirtual,width=70,height=27)
        for Evento in VerTXT:
            Eventos=eval(Evento)
            lis.insert(END,str(Eventos[0]+"  |  "+Eventos[1]+" |  "+Eventos[2])+"  |  "+Eventos[3]+"\n") 
        lis.place(x=20,y=90)

#E: AÑO MES Y DIA
#S: ELIMINAR UN EVENTO DEL TXT
#R: EL EVENTO DEBE EXISTIR

def EliminarEvento():
    if Dia.get()=="" or AñoEvento.get()=="" or MesesEvento.get=="":
        messagebox.showinfo("Aviso",message="Se deben llenar los espacios de Dia-Año-Mes")
    else:
        VerTXT=AbrirTXT("Eventos.txt")
        if VerTXT==[]:
            messagebox.showinfo("Aviso",message="No hay eventos")
        else:       
            Eliminar=[Dia.get(),MesesEvento.get(),AñoEvento.get()]
            Conter=0
            for Listas in VerTXT:
                ListaAlista=eval(Listas)
                ParteDeLista=ListaAlista[0:3]
                if Eliminar==ParteDeLista:
                    del VerTXT[Conter]
                    Nuevo="".join(VerTXT)
                    AbrirTXT2=open("Eventos.txt","w")
                    Escribir=AbrirTXT2.write(Nuevo)
                    AbrirTXT2.close()
                    VolverAAbrir=AbrirTXT("Eventos.txt")
                    lis=Listbox(AgendaVirtual,width=70,height=27)
                    for EventosNuevos in VolverAAbrir:
                        Eventos=eval(EventosNuevos)
                        lis.insert(END,str(Eventos[0]+"  |  "+Eventos[1]+" |  "+Eventos[2])+"  |  "+Eventos[3]+"\n") 
                    lis.place(x=20,y=90)
                    messagebox.showinfo("Aviso",message="Eliminado con exito")
                    break
                else:
                    Conter+=1
            else:
                messagebox.showinfo("Aviso",message="No existen considencias")
                
#E: NINGUNA
#S: UN PDF CON LOS EVENTOS DEL AÑO SOLICITADO
#R: DEBEN EXISTIR EVENTOS 

def CreacionDePDF():
    if Año.get()=="":
        messagebox.showinfo("Aviso",message="Favor indicar un año")
    else:
        CrearPDF = canvas.Canvas("Eventos Del Año "+Año.get()+".pdf")
        CrearPDF.drawString(450,800,"Fecha:  "+str(datetime.datetime.now().day)+"/"+str(datetime.datetime.now().month)+"/"+str(datetime.datetime.now().year))
        CrearPDF.drawString(50,800,"Resumen De Eventos Del Año "+Año.get()+"")
        CrearPDF.drawString(50,780,"______________________________________________________________________")
        CrearPDF.drawString(50,760,"| Fecha De Eventos "+"     |  "+"   Evento   ")
        CrearPDF.drawString(50,755,"______________________________________________________________________")
        if SacarEventosDelAño(Año.get().lower()):
            Izquierda=750
            for lineas in SacarEventosDelAño(Año.get().lower()):
                Dia=lineas[0]
                Mes=lineas[1]
                Años=lineas[2]
                Evento=lineas[3]
                Izquierda-=18
                if len(Dia)==1:
                    CrearPDF.drawString(50,Izquierda,"|  "+"0"+Dia+"/"+Mes+"/"+Años+"")
                    CrearPDF.drawString(175,Izquierda,"|")
                    CrearPDF.drawString(190,Izquierda,Evento)
                    CrearPDF.drawString(50,Izquierda-4,"______________________________________________________________________")
                    
                else:
                    CrearPDF.drawString(50,Izquierda,"|  "+Dia+"/"+Mes+"/"+Años+"")
                    CrearPDF.drawString(175,Izquierda,"|")
                    CrearPDF.drawString(190,Izquierda,Evento)
                    CrearPDF.drawString(50,Izquierda-4,"______________________________________________________________________")
            try:
                CrearPDF.save()
                abrir=os.popen("Eventos Del Año "+Año.get()+".pdf")
                #messagebox.showinfo("Exportacion exitosa",message="Podras ver el PDF en la carpeta donde esta el programa")
            except:
                messagebox.showerror("ERROR",message="Existe un archivo de PDF abierto con el mismo nombre, favor cerrarlo")
        else:
            messagebox.showinfo("Aviso",message="No existen eventos para el año selecionado")

#E: UN AÑO ESCOGIDO POR EL USUARIO
#S: UNA LISTA DE LISTAS CON LOS EVENTOS GUARDADOS DE ESE AÑO
#R: DEBEN EXISTIR EVENTOS EN EL AÑO SELECCIONADO

def SacarEventosDelAño(año):
    Vertxt=AbrirTXT("Eventos.txt")
    res=[]
    indice=0
    while len(Vertxt)>indice:
        ListaAlista=eval(Vertxt[indice])
        if Año.get()==ListaAlista[2]:
            res+=[ListaAlista]
            indice+=1
        else:
            indice+=1
    if res==[]:
        return False
    else:
        return res

def VerManual():
    archivo = os.popen('Manual de Usuario.pdf')
    
boton1=Button(AgendaVirtual,text="Festivos Por Mes",command=DiasFestivos,font=("Lucida Handwriting",13)).place(x=590,y=330)
boton2=Button(AgendaVirtual,text="Ver Festividades Anuales",font=("Lucida Handwriting",13),command=VerFestivosAnuales).place(x=10,y=550)
boton3=Button(AgendaVirtual,text="Exportar PDF de Eventos",font=("Lucida Handwriting",13),command=CreacionDePDF).place(x=270,y=550)
boton4=Button(AgendaVirtual,text="✔",font=("Lucida Handwriting",10),command=CrearEvento).place(x=1138,y=413)
boton5=Button(AgendaVirtual,text="Eliminar Eventos",font=("Lucida Handwriting",13),command=EliminarEvento).place(x=650,y=500)
boton6=Button(AgendaVirtual,text="Ver Eventos",font=("Lucida Handwriting",13),command=MostrarEventos).place(x=950,y=500)
boton7=Button(AgendaVirtual,text="Salir",font=("Lucida Handwriting",13),command=AgendaVirtual.destroy).place(x=1100,y=10)
saca(Pais.get().lower(),Año.get(),Mes.get())
BarraMenu=Menu(AgendaVirtual)
archivo=Menu(BarraMenu)
archivo.add_command(label="Ver Manual",command=VerManual)
BarraMenu.add_cascade(label="Manual de usuario",menu=archivo)
AgendaVirtual.config(menu=BarraMenu)
Recordatorios()
AgendaVirtual.mainloop()

#####FINAL DEL PROYECTO###
