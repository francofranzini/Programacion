def data(a):
    try:
        file = open(a)
        linea = file.readline()
        lineas = 0
        caracteres = 0
        palabras = 0
        while linea != '':
            aux = 0
            for c in linea:
                if c == "\n":
                    lineas += 1
                    if aux != 0:
                        palabras += 1
                        aux = 0
                elif c == " " and aux != 0:
                    palabras += 1
                    aux = 0
                else:
                    caracteres += 1
                    aux += 1
            if aux != 0:
                lineas += 1
                palabras += 1
            linea = file.readline()

        '''lineas_archivo = file.readlines()
        lineas = len(lineas_archivo)
        file.seek(0)
        caracteres = len(file.read()) - lineas
        file.seek(0)
        palabras = sum([len(x.split()) for x in lineas_archivo])'''
        file.close()
        return (lineas, palabras, caracteres)
    except:
        print("No se ha encontrado el archivo")
        return(0,0,0)

    
def main():
    a = input("Ingrese el path del archivo: ")
    tresupla = data(a)
    print(f"Lineas: {tresupla[0]}\n Palabras: {tresupla[1]}\nCaracteres: {tresupla[2]}")
    return
if __name__ == "__main__":
    main()