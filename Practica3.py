def posicionMultiplo(l,n):
    LR = [l[0]]
    if len(l) <= n:
        return LR
    return LR + posicionMultiplo(l[n:],n)

def posicionMultiplo2(l,n):
    return l[::n]

def ej6(lista):
    if lista == []:
        return []
    lista.sort()
    n = len(lista)
    rta = [lista[0]]
    for i in range(1,n):
        if lista[i] != lista[i-1]:
            rta.append(lista[i])

    return rta

def ej7(lista):
    return len(ej6(lista))

lista = [1,2,2,2,3,3,3,4,5,6,7,7,7,8,8]
#print(ej7(lista))

def BSp(lista, A):
    if lista == []:
        return -1
    a = 0
    n = len(lista)
    b = n
    while(b-a>1):
        m = (b + a) //2
        if lista[m] >= A:
            b = m
        else:
            a = m
    if b < n and lista[b] == A:
        return b
    return -1

juanindm = ["jota", "jotelson", "json", "jbalvin", "jquery", "jijiji"]
juanindm.sort()

def chainDeRoque(chain):
    n = len(chain) - 1
    while n+1:
        print(chain[n])
        n-=1

#print(BSp(juanindm, "jijiji"))
def vocales(chain):
    As = 0
    Es = 0
    Is = 0
    Os = 0 
    Us = 0
    for letra in chain:
        if letra == "a" or letra == "A":
            As += 1
        if letra == "E" or letra =="e":
            Es +=1
        if letra == "i" or letra == "I":
            Is += 1
        if letra == "o" or letra =="O":
            Os += 1
        if letra == "u" or letra == "U":
            Us += 1

    endl = "\n"
    print(" A:", As, endl,
          "E:", Es, endl,
          "I:", Is, endl,
          "O:", Os, endl,
          "U:", Us)

#vocales("queremilporongaesunamilla")
def contarl(palabra, letra):
    count = 0
    for l in palabra:
        if letra == l:
            count += 1
    
    return count

def cuantas_mas_5(cadena = ""):
    contador = 0
    pmas5 = 0
    for letra in cadena:
        contador += 1
        if letra == " ":
            contador = 0
        if contador == 5:
            pmas5 += 1
    return pmas5
print(cuantas_mas_5())
