def ver(lala):
    abrir=open(lala,"r")
    leer=abrir.readlines()
    abrir.close()
    return leer

def hola():
    x=ver("cruceros.txt")
    y=x[1]
    z=eval(y)
    print(z)
hola()
