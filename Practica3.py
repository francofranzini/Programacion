def posicionMultiplo(l,n):
    LR = [l[0]]
    if len(l) <= n:
        return LR
    return LR + posicionMultiplo(l[n:],n)

def posicionMultiplo2(l,n):
    return l[::n]


for i in range(0, 10, 2):
    print(i)


lista = [1,2,3,4,5,6,7]
palabra = "MISSISSIPI"
print (posicionMultiplo(lista, 2))
print(posicionMultiplo2(palabra,2))
