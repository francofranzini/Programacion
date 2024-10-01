from random import *

a = {"Jota": "not_sexo", "N": "Brownie", "M": "Fachelson"}
at = [("Jotel", "Pipipipi"), ("Negrelson", "Deboca"), ("Imagine", "SisyphusHappy"), ("Jotel", "Quemaneradedecirboludeces"),("Marxfran", "Algebramefolla")]

def listatupla(tuplas):
    dic = {}
    for (clave, valor) in tuplas:
        if clave in dic.keys():    
            dic[clave] += [valor]
        else:
            dic[clave] = [valor]
        
    return dic

print(listatupla(at))

def dicPalabras(cadena):
    palabra = ""
    dic = {}
    for letra in cadena:
        letra = letra.lower()
        if letra != " ":
            palabra += letra
        else:
            if palabra in dic.keys():
                dic[palabra] += 1
            else:
                dic[palabra] = 1
            palabra = ""

    if palabra != "":
        if palabra in dic.keys():
                dic[palabra] += 1
        else:
            dic[palabra] = 1
    return dic

print(dicPalabras("Que lindo dia lindo que hace hoy"))

def caracteresFrase(frase):
    dic = {}
    for letra in frase:
        if letra not in dic.keys():
            dic[letra] = 1
        else:
            dic[letra] += 1
    
    return dic

print(caracteresFrase("que remil poronga es una milla"))