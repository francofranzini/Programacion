def grep(a, b):
    f = open(b)
    for linea in f:
        if a in linea:
            print(linea)
    f.close()

def main():
    a = input("Ingrese una expresion: ")
    b = input("Ingrese el path del archivo: ")
    grep(a, b)
    return
if __name__ == "__main__":
    main()