



def main():
    a = input("Ingrese el archivo de origen: ")
    b = int(input("Ingrese N: "))
    file = open(a) #r por defecto
    linea = file.readline()
    while b > 0 and linea != '':
        print(linea)
        linea = file.readline()
        b-= 1
    file.close()
    return
if __name__ == "__main__":
    main()