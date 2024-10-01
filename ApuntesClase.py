#Diccionario:
'''
Estructura de Datos indexable, inmutable, no importa orden/repeticion
hasheable
Es inmutable y solo permite almacenar inmutables (de inmutables)

Lo quiero para busquedas rapidas y pocas mutaciones
'''
#a = {(1,[1,2])} GENERA ERROR ya que [1,2] no es inmutable en el inmutable (1,[1,2])
b = {2,3,"N", (2,"hola")}
a = {1,2,2,2,2,2,"Hola", (1,2,3)}
a.union(b) #funcion que retorna, no modifica a "a"
a.add(12) #modifica a
print(a)
a.discard(3) #borra SI hay al 3
print(a)
a.remove(2) #borra NECESARIAMENTE al 2
print(a)
a.update(b) #modifica a con la union de b
print(a)

#Pares Clave/Valor:
d = {"Juani": "Puchelson", "Negro":"NN"}
d["Franco"] = "kkk"
#Claves y valores de cualquier tipo son validas
d[(1,2,3)] = "J"
d["J"] = (1,3,4)
#se accede mediante corchetes
print(d["J"][1])

# for x in d:
#     print(x) #imprime las claves
# for x in d:
#     print(d[x]) #imprime el valor asociado a la clave x
for juani in d:
    print(d[juani])

l = [("a", 1), ("b", 3), ("c", 5)]
c = dict(l)
print(c)
print(type(d.items()))

###Conjuntos
'''
Almacena SOLO elementos unicos INMUTABLES 
Permite busquedas rapidas
No es una estructura ordenada

a = a & b operacion and entre conjuntos
a = a | b operacion or entre conjuntos

'''
#Archivos
'''
f.read()
fopen(./"file.txt")
f.readlines(420)
'''