from random import *
def barajar():
    palos = ["Corazones", "Treboles", "Diamantes", "Picas"]
    baraja = []
    for palo in palos:
        for i in range(2,15):
            if i == 11:
                baraja.append(("J", palo))
            elif i == 12:
                baraja.append(("K", palo))
            elif i == 13:
                baraja.append(("Q", palo))
            elif i == 14:
                baraja.append(("As", palo))
            else:
                baraja.append((i, palo))
    return baraja

def cantN(lista, n):
    sol = 0
    for elem in lista:
        if elem == n:
            sol += 1
    
    return sol
def primerN(lista, n):
    sol = 0
    l = len(lista)
    a = 0
    while a < l:
        if lista[a] == n:
            sol = a
            a = l
        else:
            a+=1
    return sol
def posicionesN(lista):
    l = []
    for elem in lista:
        l.append(primerN(lista, elem))
    return l
def maximo(lista):
    if lista == []:
        return -1
    m = lista[0]
    for elem in lista:
        if elem > m:
            m = elem
    
    return m
def maxpos(lista):
    if lista == []:
        return (0,0)
    m = (lista[0], 0)
    a = 0
    while a < len(lista):
        if lista[a] > m[0]:
            m = (lista[a], a)
        else:
            a += 1
    return m
def bsi(lst, e):
    a = 0
    b = len(lst)
    while b-a > 1:
        m = (b + a) // 2
        if lst[m] >= e:
            b = m
        else:
            a = m
    
    if(lst[b] == e):
        return b
    else:
        return b #redundante y aque si insertara el nuevo elemento 
    #estaria entre a y b y b-a 
    
a = {"Jota": "not_sexo", "N": "Brownie", "M": "Fachelson"}
at = [("Jotel", "Pipipipi"), ("Negrelson", "Deboca"), ("Imagine", "SisyphusHappy"), ("Jotel", "Quemaneradedecirboludeces"),("Marxfran", "Algebramefolla")]

def listatupla(tuplas):
    dic = {}
    for (clave, valor) in tuplas:
        if clave in dic.keys():    
            dic[clave] += [valor]
        else:
            dic[clave] = [valor]
        
    return dic


def dicPalabras(cadena):
    palabra = ""
    dic = {}
    for letra in cadena:
        letra = letra.lower()
        if letra != " ":
            palabra += letra
        else:
            if palabra in dic.keys():
                dic[palabra] += 1
            else:
                dic[palabra] = 1
            palabra = ""

    if palabra != "":
        if palabra in dic.keys():
                dic[palabra] += 1
        else:
            dic[palabra] = 1
    return dic

def caracteresFrase(frase):
    dic = {}
    for letra in frase:
        if letra not in dic.keys():
            dic[letra] = 1
        else:
            dic[letra] += 1
    
    return dic
def listaSinDup(lista):
    return list(set(lista))

def cadenas(c1,c2):
    pingo1 = c1.split()
    pingo2 = c2.split()
    pingo3 = pingo1 + pingo2
    pingo4 = set(pingo3)
    return pingo4
