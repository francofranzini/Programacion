
def sumatoriaN(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return (n + sumatoriaN(n-1))

def sumatoriaNM(n, m):
    m -= 1;
    if m == n:
        return 0
    return (m + sumatoriaNM(n, m))

def concatenarN(str, n):
    if n == 0:
        return ""
    return str + concatenarN(str, n-1)


def suma():
    n = int(input("n: "))
    m = int(input("m: "))

    return n + m
def resta():
    n = int(input("n: "))
    m = int(input("m: "))

    return n - m
def prod():
    n = int(input("n: "))
    m = int(input("m: "))

    return n * m
def div():
    n = int(input("n: "))
    m = int(input("m: "))
    if m == 0:
        return 0
    return n / m

def programaInteractivo():
    print("1. Suma \n2. Resta \n3. Multiplica \n4. Divide \n5. Salir")
    opcion = int(input())
    if opcion == 1:
        rta = suma()
    elif opcion == 2:
        rta = resta()
    elif opcion == 3:
        rta = prod()
    elif opcion == 4:
        rta = div()
    elif opcion == 5:
        return
    
    print("Resultado:", rta)
    
    programaInteractivo()

programaInteractivo()