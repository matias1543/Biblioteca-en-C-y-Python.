#BIBLIOTECA

libros = {
    "Principito" : ["Titulo: Principito","Genero: Fantasia", "paginas: 20", "Autor: Raul", "Numero ISBN: 12312123", "Año de edicion: 1994", "Editorial: IZI"],
    "El padrino" : ["Titulo: El padrino","Genero:Ficcion", "paginas: 30", "Autor: Lopez", "Numero ISBN: 22312312", "Año de edicion: 1992", "Editorial: PIZI"]
    }


def alta():
    u=input("Ingrese libro: ")
    if u in libros:
        print("El libro ya se encuentra dentro de la biblioteca.")
    else:
        Genero="Genero: "+input("Ingrese genero: ")
        paginas="paginas: "+input("Ingrese cantidad de paginas: ")
        Autor="Autor: "+input("Ingrese autor: ")
        Numero_ISBN="Numero ISBN:"+input("Ingrese Numero ISBN: ")
        Año_de_edicion="Año de edicion: "+input("Ingrese año de edicion: ")
        Editorial="Editorial"+input("Ingrese editorial: ")
    print("Titulo: "+ u + "Genero: "+ Genero + "paginas: "+ paginas + "Autor: "+ Autor + "Numero ISBN: "+ Numero_ISBN + "Año de edicion: "+ Año_de_edicion + "Editorial: "+ Editorial)
    libros[u]=[u, Genero, paginas, Autor, Numero_ISBN, Año_de_edicion, Editorial]


def baja():
    n=input("Ingrese libro: ")
    del libros[n]
    print(libros)


def consultar():
      s=input("Ingrese libro: ")
      existe = 0 
      for libro in libros:
          if s == libro:
              existe = 1

      if (existe == 1):
            print("Tenemos ese libro en la Biblioteca.")
            print(libros[s])
      else:
            print("No tenemos ese libro en la Biblioteca.")
    
    
def modificar():
    m=input("Ingrese libro a modificar: ")
    print("Que desea modificar?")
    print("1.Genero")
    print("2.paginas")
    print("3.Autor")
    print("4.Numero ISBN")
    print("5.Año de edicion")
    print("6.Editorial")
    
    s=int(input("Elegir operacion: "))
    if(s==1):
        libros[m][1]="Genero: "+input("Genero:")
    elif(s==2):
        libros[m][2]="Paginas: "+int(input("Paginas: "))
    elif(s==3):
        libros[m][3]="Autor"+input("Autor: ")
    elif(s==4):
        libros[m][4]="Numero ISBN: "+int(input("Numero ISBN: "))
    elif(s==5):
        libros[m][5]="Año de edicion: "+int(input("Año de edicion: "))
    elif(s==6):
        libros[m][6]="Editorial: "+input("Editorial: ")

    
def listados():
        print("Operaciones de listados.") 
        print("1.Listar todos los autores existentes.") #Listo
        print("2.Listar todos los libros existentes.") #Listo
        print("3.Listar todos los libros de un genero determinado.") #Listo 
        print("4.Listar todos los libros que posee un autor determinado.") #Listo
        print("5.Listar todos los libros de una editorial determinada.") #Listo
        print("6.Listar todos los libros de una editorial determinada en un rango de años de edicion.")
        print("7.Listar Todos los autores de una determinada editorial.")
        print("8.Listar todos los libros que fueron editados en un determinado año.")
        print("9.Listar todos los libros de los autores cuyos apellidos comienzan con una letra determinada.")
        print("10.Listar todos los libros cuyos titulos contengan una palabra determinada.")
        p=int(input("Elegir operacion a realizar: "))
        if(p==1):
            for titulos in libros:
                print(libros[titulos][3])
        if(p==2):
            for titulos in libros:
                print(libros[titulos][0])
        elif(p==3):
            for titulos in libros:
                print(libros[titulos][1])
        elif(p==4):
            s="Autor: "+input("Autor: ")
            for titulos in libros:
                if(s == libros[titulos][3]):
                    print(libros[titulos][3])
        elif(p==5):
            for titulos in libros:
                print(libros[titulos][6])

a=1


while(a!=0):
    print("Operaciones")
    print("1.Dar de alta un libro.") #Listo
    print("2.Dar de baja un libro.") #Listo
    print("3.Consultar por un libro determinado.") #Listo
    print("4.Modificar datos de un libro.") #Listo 
    print("5.Listados:") 
    print("6.Salir.")
    b=int(input("Elejir operacion a realizar: "))
    if(b==1):
        alta()
        print("Desea seguir operando?")
        print("1.Si")
        print("2.No")
        s=int(input("Elegir operacion a realizar: "))
        if(s==1):
            a=1
        else:
            a=0
    elif(b==2):
        baja()
        print("Desea seguir operando?")
        print("1.Si")
        print("2.No")
        s=int(input("Elegir operacion a realizar: "))
        if(s==1):
            a=1
        else:
            a=0
    elif(b==3):
        consultar()
        print("Desea seguir operando?")
        print("1.Si")
        print("2.No")
        s=int(input("Elegir operacion a realizar: "))
        if(s==1):
            a=1
        else:
            a=0
    elif(b==4):
        modificar()
        print("Desea seguir operando?")
        print("1.Si")
        print("2.No")
        s=int(input("Elegir operacion a realizar: "))
        if(s==1):
            a=1
        else:
            a=0
    elif(b==5):
        listados()
        print("Desea seguir operando?")
        print("1.Si")
        print("2.No")
        s=int(input("Elegir operacion a realizar: "))
        if(s==1):
            a=1
        else:
            a=0
    elif(b==6):
        a=0
        

        
        
    
        

