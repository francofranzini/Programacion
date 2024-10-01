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

print(maxpos([1,2,3,4,55,4,6,22,3333,1]))