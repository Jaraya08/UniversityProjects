from tkinter import *
from tkinter import ttk
import random
import time

#E: Un archivo de texto
#S: El Txt en formato Lista 
#R: Debe ser un txt 

def Abrir_TXT(txt):
    Abrir=open(txt,"r")
    Leer=Abrir.readlines()
    Abrir.close()
    return Leer

#E: Las posiciones de cada boton 
#S: Un valor Boleano indicando si el movimiento es valido
#R: La posiciones deben ser  numeros

def movimientos(lista,lista2):
    abrir=Abrir_TXT("Movimientos.txt")
    for pos in abrir:
        pos1=eval(pos)
        if pos1[0]==lista[0]:
            pos1=pos1[1:]
            if lista2[0] in pos1:
                return True
            else:
                return False

#E: Cantidad De jugadores y un numero verificador 
#S: Verificar el turno de cada jugador  
#R: La cantidad y el numero verificador debe ser entero positivo

def turnos(cantidad,verificador):
    abrir=open("Siguiente.txt","r")
    turno=abrir.readlines()
    abrir.close()
    contador=0
    if verificador==0:
        for lista in turno:
            lista1=eval(lista)
            if len(lista1)==cantidad:
                lista1+=[lista1[0]]
                lista1=lista1[1:]
                del turno[contador]
                turno+=[lista1]
                abrir=open("Siguiente.txt","w")
                for turn in turno:
                    abrir.write(str(turn))
                abrir.write("\n")
                abrir.close()
                return lista1
            contador+=1
    else:
        for lista in turno:
            lista1=eval(lista)
            if len(lista1)==cantidad:
                return lista1

#E: Color que corresponde a la maquina / cantidad de jugadores / el turno del jugador / el txt de colores actual
#S: Un movimiento hecho automaticamente por el algoritmo 
#R: Deben existir maquinas jugando 

def maquina(color,cantidad,jugadores,txt):
    abrir=Abrir_TXT(txt+".txt")
    abrir1=eval(abrir[0])
    cont=0
    res=[]
    for elemento in abrir1:
        if elemento==color:
            res+=[cont]
        cont+=1
        abrir1=abrir1[1:]
    return maquina_aux(res,cantidad,color,jugadores,txt)

def maquina_aux(lista,cantidad,color,jugadores,txt):
    elegido=random.choice(lista)
    abrir=Abrir_TXT("Movimientos.txt")
    for posicion in abrir:
        lista1=eval(posicion)
        if lista1[0]==elegido:
            mov=random.choice(lista1)
            break
    abrir2=Abrir_TXT(txt+".txt")
    abrir=list(abrir2)
    abrir1=eval(abrir[0])
    if abrir1[mov]=="White":
        abrir1[mov]=color
        abrir1[elegido]="White"
        abrir=open(txt+".txt","w")
        abrir.write(str(abrir1))
        turno=turnos(cantidad,0)
        abrir.close()
        return ventana_tablero(cantidad,1,turno,jugadores,txt)
    else:
        return maquina_aux(lista,cantidad,color,jugadores,txt)
#E: El txt de los Jugadores (maquina o Humano) y cantidad de jugadores
#S: Guardar la partida actual
#R: se debe presionar el boton de Guardar partida

def guardar(jugadores,cantidad):
    ven=Toplevel()
    ven.geometry("400x300+500+200")
    ven.title("Nombre de Partida")
    imagen=PhotoImage(file="TableroIni.gif")
    imagen1=Label(ven,image=imagen).place(x=-50,y=-20)
    var=StringVar()
    label=Label(ven,text="Digite un nombre para su partida").place(x=120,y=70)
    caja=Entry(ven,textvariable=var).place(x=150,y=100)
    boton=Button(ven,text="Guardar",command=lambda:guardar_aux(var.get(),jugadores,cantidad)).place(x=220,y=150)
    salir=Button(ven,text="Cancelar",command=ven.destroy).place(x=150,y=150)
    ven.mainloop()
    
def guardar_aux(nombre,jugadores,cantidad):
    abrir=open("Partidas.txt","a")
    abrir.write(str([nombre,jugadores,cantidad])+"\n")
    abrir.close()
    abrir=Abrir_TXT(str(cantidad)+".txt")
    crear=open(nombre+".txt","w")
    crear.write("".join(abrir))
    crear.close()
    abrir1=open(str(cantidad)+"O.txt","r")
    abrir2=abrir1.readlines()
    abrir=open(str(cantidad)+".txt","w")
    abrir.write("".join(abrir2))
    abrir.close()
    abrir1.close()
    abrir=open("Maquinas.txt","w")
    abrir.close()
    messagebox.showinfo("Guardado",message="Partida guardada con éxito")
    ventana_tab.destroy()
    inicio()
    


#E: cantidad de jugadores y la ventana que esta abierta en ese momento
#S:  Reinicia todos los valores 
#R: Se bebe precionar el boton de salir obligatoriamente para que se reinicien los valores 

def salir(ventana,cantidad):
    abrir1=open(str(cantidad)+"O.txt","r")
    abrir2=abrir1.readlines()
    abrir=open(str(cantidad)+".txt","w")
    abrir.write("".join(abrir2))
    abrir.close()
    abrir1.close()
    abrir=open("Maquinas.txt","w")
    abrir.close()
##    AbrirTXT=open("Siguiente.txt","w")
##    AbrirTXT.close()
    ventana.destroy()
    inicio()
    
#E: Las ventanas que se abriran y cerraran, ademas la cantidad de jugadores , los colores, si el maquina o humano
#S: llamar a otra funcion y cerrar la ventana anterior
#R: debe recibir ventanas TK o Top Level
    
def cerrar(ventana,ventana2,cantidad,color,jugadores,txt):
    ventana.destroy()
    return ventana2(cantidad,0,color,jugadores,txt)

#E: Cantidad de jugadores, verificador , colores y los txt con los jugadores (maquina o humano) 
#S: Encargada de hacer funcionar el juego 
#R: Los txt deben estar llenos 

def ventana_tablero(cantidad,verificador,color,jugadores,txt):
    global ventana_tab
    if verificador==0:
        ventana_tab=Tk()
        ventana_tab.geometry("1000x600+170+20")
        ventana_tab.resizable(width=False, height=False)
        imagen=PhotoImage(file="Juego.gif")
        imagen1=Label(ventana_tab,image=imagen).place(x=-300,y=-300)
        tablero(cantidad,jugadores,txt)
        print(color)
        label1=Label(ventana_tab,text="Turno de").place(x=10,y=10)
        label2=Label(ventana_tab,bg=color[0],width=2).place(x=80,y=10)
        abrir=open("Maquinas.txt","a")
        lista=[]
        cont=0
        for jugador in jugadores:
            if jugador=="Máquina":
                lista+=[color[cont]]
            cont+=1
        abrir.write(str(lista))
        abrir.close()       
    else:
        abrir=Abrir_TXT("Maquinas.txt")
        tablero(cantidad,jugadores,txt)
        label1=Label(ventana_tab,text="Turno de").place(x=10,y=10)
        label2=Label(ventana_tab,bg=color[0],width=2).place(x=80,y=10)
        abrir1=eval(abrir[0])
        if color[0] in abrir1:
            maquina(color[0],cantidad,jugadores,txt)
        else:
            pass
    guardarp=Button(ventana_tab,text="Guardar Partida",command=lambda:guardar(jugadores,cantidad)).place(x=100,y=100)
    salirp=Button(ventana_tab,text="Salir",command=lambda:salir(ventana_tab,cantidad)).place(x=100,y=200)
    ventana_tab.mainloop()

#E: posiciones x y y / posicion numerica 7 txt de colres para ordenar
#S: Un boton en la posicion indicada
#R: Debe recibir posiciones X y Y

def Crear_botones(posx,posy,num,cantidad,jugadores,txt):
    a=Button(ventana_tab,width=2,bg=ListaAlistaNum[num])
    a.config(command=lambda:botones(num,ListaAlistaNum[num],cantidad,jugadores,txt))
    a.place(x=posx,y=posy)

#E: recibe parametros enviador la funcion Crear_botones()
#S: cambiar los colores del tablero en cada movimiento
#R: se deben presionar los botones
    
def botones(NumBoton,color,cantidad,jugadores,txt):
    Valores=[NumBoton,color]
    Escribir=open("Turnos.txt","a")
    Escribir.write(str(Valores)+"\n")
    Escribir.close()
    AbrirTXT=Abrir_TXT("Turnos.txt")
    PrimerToque=eval(AbrirTXT[0])
    if len(AbrirTXT)==1:
        turno=turnos(cantidad,1)
        if PrimerToque[1]=="White":
            Borrar1=open("Turnos.txt","w")
            Borrar1.close()
            messagebox.showinfo("Movimiento Inválido","No es una ficha")
        elif PrimerToque[1]!=turno[0]:
            Borrar1=open("Turnos.txt","w")
            Borrar1.close()
            messagebox.showinfo("Movimiento Inválido",message="No corresponde su movimiento")            
    if len(AbrirTXT)==2:
        SegundoToque=eval(AbrirTXT[1])
        if PrimerToque[1]!="White" and SegundoToque[1]=="White":
            if movimientos(PrimerToque,SegundoToque):
                x=list(ListaAlistaNum)
                x[int(PrimerToque[0])]=SegundoToque[1]
                x[int(SegundoToque[0])]=PrimerToque[1]
                Borrar=open(str(cantidad)+".txt","w")
                Borrar.close()
                Escribir=open(str(cantidad)+".txt","a")
                Escribir.write(str(x))
                Escribir.close()
                Borrar1=open("Turnos.txt","w")
                Borrar1.close()
                turno=turnos(cantidad,0)
                return ventana_tablero(cantidad,1,turno,jugadores,txt)
            else:
                turno=turnos(cantidad,1)
                Borrar1=open("Turnos.txt","w")
                Borrar1.close()
                messagebox.showinfo("Movimiento Inválido",message="No es un movimiento válido")
        elif PrimerToque[1]==SegundoToque[1]:
            Borrar1=open("Turnos.txt","w")
            Borrar1.close()
            messagebox.showinfo("Movimiento Inválido","Ya tiene una ficha en esa posición")
        else:
            Borrar1=open("Turnos.txt","w")
            Borrar1.close()
            messagebox.showinfo("Movimiento Inválido","Ya se encuentra una ficha contraria en esta posición")
            
#E: Cantidad de jugadores y el TXT de los colores de la cantidad de jugadores que van a jugar
#S: la forma del tablero de damas chinas
#R: ninguna

def tablero(cantidad,jugadores,txt):
    global ListaAlistaNum
    Tablero=open("tablero.txt","r")
    LeeTablero=Tablero.readlines()
    Tablero.close()
    Numeros=open(txt+".txt","r")
    LeeNumeros=Numeros.readlines()
    Numeros.close()
    ListaAlistaNum=eval(LeeNumeros[0])
    cont=0
    while LeeTablero!=[]:
        ListaAListaTab=eval(LeeTablero[0])
        posx=ListaAListaTab[0]
        posy=ListaAListaTab[1]
        for Botones in range(0,ListaAListaTab[2]):
            Crear_botones(posx,posy,cont,cantidad,jugadores,txt)
            posx+=24
            cont+=1
        LeeTablero=LeeTablero[1:]
    
#E: Ninguna
#S: Busca las partidad guardas
#R: Deben existir partidas guardadas

        
def partidas():
    abrir=Abrir_TXT("Partidas.txt")
    lista=[]
    for partida in abrir:
        abrir1=eval(partida)
        lista+=["".join(abrir1[0])]
    return lista

#E:  El nombre de una partida guardada
#S: Carga la partida Escodiga
#R: Deben existir partidas guardadas

def verificar(escogido):
    abrir=Abrir_TXT("Partidas.txt")
    lista=[]
    for partida in abrir:
        abrir1=eval(partida)
        if abrir1[0]==escogido:
            turno=turnos(abrir1[2],1)
            return cerrar(ven_cargar,ventana_tablero,abrir1[2],turno,abrir1[1],abrir1[0])
    
#E: Una ventana
#S: El nombre de una partida almacenada
#R: Ninguna

def cargar_partida(ventana):
    global ven_cargar
    ventana.destroy()
    ven_cargar=Tk()
    ven_cargar.geometry("460x300+470+200")
    ven_cargar.title("Cargar partida")
    imagen=PhotoImage(file="TableroIni.gif")
    imagen1=Label(ven_cargar,image=imagen).place(x=-50,y=-20)
    label1=Label(ven_cargar,text="Elija la partida que desea cargar").place(x=50,y=50)
    var=StringVar()
    caja1=ttk.Combobox(ven_cargar,textvariable=var,state="readonly")
    lista=partidas()
    caja1.config(value=(lista))
    caja1.place(x=50,y=90)
    cargar=Button(ven_cargar,text="Cargar",command=lambda:verificar(var.get())).place(x=50,y=120)
    ven_cargar.mainloop()

#E: Cantidad de jugadores y parametros sin importancia
#S: Una ventana para escoger los tipos de jugadores
#R: ninguna
    
def nueva_partida(cantidad,impar,bol,bol2,bol3):
    ventana1=Tk()
    ventana1.geometry("500x400+500+100")
    ventana1.title("Escoja sus jugadores")
    imagen=PhotoImage(file="TableroIni.gif")
    ventana1.resizable(width=False, height=False)
    imagen1=Label(ventana1,image=imagen).place(x=-50,y=-20)
    Label(ventana1,text="Elegir los tipos de jugadores").place(x=50,y=20)
    if cantidad==0:
        messagebox.showinfo("Error",message="Debe escoger la cantidad de jugadores")
    else:
        if cantidad==2:
            var1=StringVar()
            var2=StringVar()
            caja1=ttk.Combobox(ventana1,textvariable=var1,state="readonly")
            caja1.config(value=("Jugador"))
            caja2=ttk.Combobox(ventana1,textvariable=var2,state="readonly")
            caja2.config(value=("Jugador","Máquina"))
            caja1.place(x=50,y=70)
            caja2.place(x=50,y=100)
            turno=turnos(cantidad,1)
            jugar=Button(ventana1,text="Jugar",command=lambda:cerrar(ventana1,ventana_tablero,cantidad,turno,[var1.get(),var2.get()],str(cantidad))).place(x=200,y=300)
        elif cantidad==3:
            var1=StringVar()
            var2=StringVar()
            var3=StringVar()
            caja1=ttk.Combobox(ventana1,textvariable=var1,state="readonly")
            caja1.config(value=("Jugador"))
            caja2=ttk.Combobox(ventana1,textvariable=var2,state="readonly")
            caja2.config(value=("Jugador","Máquina"))
            caja3=ttk.Combobox(ventana1,textvariable=var3,state="readonly")
            caja3.config(value=("Jugador","Máquina"))
            caja1.place(x=50,y=70)
            caja2.place(x=50,y=100)
            caja3.place(x=50,y=130)
            turno=turnos(cantidad,1)
            jugar=Button(ventana1,text="Jugar",command=lambda:cerrar(ventana1,ventana_tablero,cantidad,turno,[var1.get(),var2.get(),
                                                                                                              var3.get()],str(cantidad))).place(x=200,y=300)
        elif cantidad==4:
            var1=StringVar()
            var2=StringVar()
            var3=StringVar()
            var4=StringVar()
            caja1=ttk.Combobox(ventana1,textvariable=var1,state="readonly")
            caja1.config(value=("Jugador"))
            caja2=ttk.Combobox(ventana1,textvariable=var2,state="readonly")
            caja2.config(value=("Jugador","Máquina"))
            caja3=ttk.Combobox(ventana1,textvariable=var3,state="readonly")
            caja3.config(value=("Jugador","Máquina"))
            caja4=ttk.Combobox(ventana1,textvariable=var4,state="readonly")
            caja4.config(value=("Jugador","Máquina"))
            caja1.place(x=50,y=70)
            caja2.place(x=50,y=100)
            caja3.place(x=50,y=130)
            caja4.place(x=50,y=160)
            turno=turnos(cantidad,1)
            jugar=Button(ventana1,text="Jugar",command=lambda:cerrar(ventana1,ventana_tablero,cantidad,turno,[var1.get(),var2.get(),
                                                                                                              var3.get(),var4.get()],str(cantidad))).place(x=200,y=300)
        elif cantidad==6:
            var1=StringVar()
            var2=StringVar()
            var3=StringVar()
            var4=StringVar()
            var5=StringVar()
            var6=StringVar()
            caja1=ttk.Combobox(ventana1,textvariable=var1,state="readonly")
            caja1.config(value=("Jugador"))
            caja2=ttk.Combobox(ventana1,textvariable=var2,state="readonly")
            caja2.config(value=("Jugador","Máquina"))
            caja3=ttk.Combobox(ventana1,textvariable=var3,state="readonly")
            caja3.config(value=("Jugador","Máquina"))
            caja4=ttk.Combobox(ventana1,textvariable=var4,state="readonly")
            caja4.config(value=("Jugador","Máquina"))
            caja5=ttk.Combobox(ventana1,textvariable=var5,state="readonly")
            caja5.config(value=("Jugador","Máquina"))
            caja6=ttk.Combobox(ventana1,textvariable=var6,state="readonly")
            caja6.config(value=("Jugador","Máquina"))
            caja1.place(x=50,y=70)
            caja2.place(x=50,y=100)
            caja3.place(x=50,y=130)
            caja4.place(x=50,y=160)
            caja5.place(x=50,y=190)
            caja6.place(x=50,y=220)
            turno=turnos(cantidad,1)
            jugar=Button(ventana1,text="Jugar",command=lambda:cerrar(ventana1,ventana_tablero,cantidad,turno,[var1.get(),var2.get(),
                                                                                                              var3.get(),var4.get(),
                                                                                                              var5.get(),var6.get()],str(cantidad))).place(x=200,y=300)
    ventana1.mainloop()
#E: Ninguna
#S: Un numero entero de la cantidad de jugadores elegidos
#R: Ninguna

def escoger(a,b,c,d,e):
    ven_escoger=Tk()
    ven_escoger.geometry("300x300+500+250")
    ven_escoger.resizable(width=False, height=False)
    imagen=PhotoImage(file="TableroIni.gif")
    imagen1=Label(ven_escoger,image=imagen).place(x=-150,y=-40)
    Label(ven_escoger,text="Elegir cantidad de jugadores").place(x=75,y=50)
    cant=StringVar()
    caja1=ttk.Combobox(ven_escoger,textvariable=cant,state="readonly")
    caja1.config(value=(2,3,4,6))
    caja1.place(x=80,y=80)
    seguir=Button(ven_escoger,text="Seguir",command=lambda:cerrar(ven_escoger,nueva_partida,int(cant.get()),True,True,True)).place(x=120,y=130)
    ven_escoger.mainloop()

#E: ningun
#S: una Tk de Inicio 
#R: Ninguna

def inicio():
    ventana=Tk()
    ventana.geometry("500x400+400+200")
    ventana.title("Damas Chinas")
    ventana.resizable(width=False, height=False)
    imagen=PhotoImage(file="TableroIni.gif")
    imagen1=Label(ventana,image=imagen).place(x=-50,y=-20)
    nueva=Button(ventana,text="Nueva Partida",command=lambda:cerrar(ventana,escoger,True,True,True,True)).place(x=200,y=100)
    cargar=Button(ventana,text="Cargar Partida",command=lambda:cargar_partida(ventana)).place(x=200,y=150)
    salir=Button(ventana,text="Salir del Juego",command=ventana.destroy).place(x=200,y=200)
    ventana.mainloop()
inicio()
