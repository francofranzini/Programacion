from math import sqrt
from random import *
def printnm(n, m):
    for i in range(n, m+1):
        print(i)


def dominos(n = 6):
    for i in range(n + 1):
        print(i, " : ", n)
    if n != 0:
        dominos(n - 1)

def dominos2(n = 6):
    for i in range(n + 1):
        for j in range(i, n + 1):
            print(i, " : ", j)
        
def fact(n):
    result = 1
    for i in range(1, n + 1):
        result = result * i
    return result


def factorialesN(m):
    for i in range(m):
        print(fact(int(input("Ingrese el valor Nº " + str(i+1) + ": "))))


def FtoC(n):
    return (n - 32) * 5 / 9

def convTable():
    for i in range(0, 120, 10):
        print("%.3f\tºF -> %.3f\tºC" % (i, FtoC(i)))


def sum1(n):
    sum = 0
    for i in range(1, n + 1):
        sum = sum + i
    return sum

def sum2(n):
    return (n * (n + 1)) / 2

def triangleN1(n):
    for i in range(1, n + 1):
        print("%d\t - %d" % (i, sum1(i)))

def triangleN2(n):
    for i in range(1, n + 1):
        print("%d\t - %d" % (i, sum2(i)))

def ej7():
    a = -1
    while(a < 0):
        a = input("Ingrese un numero positivo: ")
        
        if not a.isdigit() or int(a) <= 0:
            print("NATURAL Y POSITIVO COJONE' ")
        else:
            a = False

        if(a.isdigit() and int(a) == 4):
                print("TE PUSE")

lista = [1,2,3,4,5,6, 7, 8, 9, 10]
sum = 0

def sumaElemntos(l):
    sum = 0
    while l != []:
        sum += l[0]
        l = l[1:]

    return sum

#l se define localmente con la funcion
#es unico, si lo modifico se modifica para las subsecuentes
#llamadas.
def appendeashei(l = []):
    l = l + ["JOTA"]
    return l
#retorna ["JOTA"] en cada llamada, ya que no se modifica l, porque retorna una nueva lista
#si usara un append l se modificaria pq es un metodo que modifica al *l

def ej8():
    k = -1
    nota = 0
    sumaNotas = 0
    while(nota >= 0):
        k += 1
        nota = int(input("Ingrese una nota o -1 para finalizar: "))
        if(nota >= 0):
            sumaNotas += nota

    return (sumaNotas/k)

def ej9():
    a = 0
    b = 0
    a = int(input("Ingrese el primer numero: "))
    b = int(input("Ingrese el segundo numero: "))
    while(b >= a):
        b = int(input("Ingrese un segundo numero menor que el primero (%d): " % a))

    print(a, b)

def ej10while(a, b):
    mult = 0
    while(a*(mult + 1) < b):
        mult += 1
    return mult

def ej10for(a,b):
    mult = 0
    for i in range(0, b, a):
        mult = mult + 1
    #print(mult - 1)
    return mult - 1

def ej11():
    passwd= "123132"
    userPass = ""
    intentos = 5
    while (userPass != passwd and intentos):
        userPass = input("Ingrese la password: ")
        intentos -= 1

    if (intentos + 1):
        return True
    else:
        return False

def es_primo(n):
    este_tiene_que_dar_cero = 0
    for i in range(2, int(sqrt(n) + 1)):
        if n%i == 0:
            este_tiene_que_dar_cero += 1
    return (este_tiene_que_dar_cero == 0)

def ej12(n):
    rta = []
    for i in range(1,n):
        if(es_primo(i)):
            rta.append(i)
    return rta


def ej13(n):
    while(n//2 > 0):
        n = n / 2
    return n == 1

def ej13b(n,m):
    sum = 0
    for i in range(n, m):
        if (ej13(i)):
            sum += i
        
    return sum

def dados():
    dado = randint(1, 6)
    lista = []
    while(dado != 6):
        lista.append(dado)
        dado = randint(1,6)
    
    lista.append(6)
    
    return lista

tiradas = dados()
print(tiradas, "\nSe lanzo", len(tiradas), "veces.")

def BS(lista, A):
    n = len(lista)
    inicio = 0
    fin = n 
    while(fin - inicio > 1):
        mid = (inicio + fin) // 2
        if(lista[mid] >= A): 
            fin = mid
        else:
            inicio = mid
    if(fin < n and lista[fin] == A):
        return fin
    return -1



print(BS([1,2,3,4,5,5,6,6,6,6,7,8,9], 7))



def tirarNdados():
    n = int(input("Ingrese la cantidad de lanzamientos: "))
    coincidencias = 0
    while n:
        dado1 = randint(1,6)
        dado2 = randint(1,6)
        if dado1 == dado2:
            coincidencias += 1
        n-=1
    return coincidencias

print(tirarNdados())