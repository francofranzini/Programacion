def cifrarCaracter(letra):
    o = (ord(letra)-ord("a") + 13) % 26 + ord("a")
    return chr(o)


def cifrar_linea(linea):
    linea_cifrada = []
    for letra in linea:
        if letra.isalpha():
            linea_cifrada.append(cifrarCaracter(letra))
        else:
            linea_cifrada.append(letra)
    
    return "".join(linea_cifrada)
def rot13(a,b):
    f = open(a)
    d = open(b, "w")
    for linea in f:
        d.write(cifrar_linea(linea))
    f.close()
    d.close()


def main():
    a = input("Ingrese el path del archivo: ")
    b = input("Ingrese el path de destino: ")
    rot13(a,b)
    return
if __name__ == "__main__":
    main()