def data(a):
    file = open(a)
    lineas = len(file.readlines())
    file.seek(0)
    caracteres = len(file.read()) - lineas
    file.seek(0)
    palabras = sum([len(x.split()) for x in file.readlines()])
    file.close()
    return (lineas, palabras, caracteres)
def main():
    a = input("Ingrese el path del archivo: ")
    tresupla = data(a)
    print(f"Lineas: {tresupla[0]}\n Palabras: {tresupla[1]}\nCaracteres: {tresupla[2]}")
    return
if __name__ == "__main__":
    main()