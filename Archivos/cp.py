def cp(origen, destino):
    for linea in origen:
        destino.write(linea)#la "flecha" apunta al final de cada linea
def main():
    a = input("Ingrese el archivo de origen: ")
    b = input("Ingrese el archivo de destino: ")
    origen = open(a, "r")
    destino = open(b, "w")
    cp(origen, destino)
    origen.close()
    destino.close()
    return
if __name__ == "__main__":
    main()