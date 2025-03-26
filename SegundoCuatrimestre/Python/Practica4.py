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

def masLarga(frase):
    dic = {}
    lista_frase = frase.split()
    n = len(lista_frase)
    while n>0:
        n-=1
        for letra in lista_frase[n]:
            if letra not in dic.keys():
                dic[letra] = lista_frase[n]
    return dic
def ej7aux(lista):
    sum = 0
    for n in lista:
        sum += n
    return sum / len(lista)
def ej7(calif,estudiante = ""):
    if estudiante != "":
        return ej7aux(calif[estudiante])
    max_prom = 0
    mas_calificado = ""
    for e in calif.keys():
        prom_e = ej7aux(calif[e])
        max_prom = max(max_prom, prom_e)
        if max_prom == prom_e:
            mas_calificado = e
    
    return mas_calificado

def ej8(frase, sinonimos):
    frase_lista = frase.split()
    frase_final = []
    for palabra in frase_lista:
        if palabra in sinonimos.keys():
            x = randint(0, len(sinonimos[palabra])-1)
            frase_final.append(sinonimos[palabra][x] + " ")
        else:
            frase_final.append(palabra + " ")
    return "".join(frase_final)

#print(ej8("Con alto hedor a klave", {"hedor": ["Olor"], "klave" : ["pingo", "Guimpel"]}))
def ej9(precios, cantidades):
    suma_total = 0
    for item in precios.keys():
        suma_total += precios[item] * cantidades[item]

    return suma_total

#print(ej9({"tussi": 450, "pala": 600, "rropo": 150}, {"tussi": 5, "pala":2, "rropo":3}))
def ej10(lista):
    return list(set(lista))
def ej11(c1, c2):
    c1_lista = c1.split()
    c2_lista = c2.split()
    c3 = c1_lista + c2_lista
    palabras = []
    for p in c3:
        palabras.append(p.lower())
    return set(palabras)
def ej12(conj1, conj2):
    conj3 = conj1 & conj2
    exclusi = []
    for elem in conj1 | conj2:
        if elem not in conj3:
            exclusi.append(elem)
    
    return set(exclusi)
def ej13(lista):
    mayor = 0
    for numero in lista:
        mayor = max(mayor, numero)
    listaN = [x for x in range(1, mayor) if x not in lista]
    return listaN
def ej13aux(lista):
    mayor = max(lista)
    a = set(range(1,mayor + 1))
    return ej12(a, set(lista))
def ej14(dias):
    dias_disponibles = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"}
    for dias in dias.values():
        dias_disponibles &= set(dias)
    return dias_disponibles