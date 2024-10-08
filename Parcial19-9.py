def cantidadVeces(lst, e):
    if lst == []:
        return 0
    if lst[0] == e:
        return 1 + cantidadVeces(lst[1:], e)
    return cantidadVeces(lst[1:], e)

def cantidadVecesRecursiva(lst, e, indice = 0):
    if indice >= len(lst):
        return 0
    if lst[indice] == e:
        return 1 + cantidadVecesRecursiva(lst, e, indice + 1)
    return cantidadVecesRecursiva(lst, e, indice + 1)

def cantidadVeces2(lst, e):
    contador = 0
    if lst == []:
        return 0
    for elem in lst:
        if elem == e:
            contador += 1

    return contador

def elementosDistintos(lst, e):
    rta = []
    if lst == []: 
        return []
    for elem in lst:
        if elem != e:
            if cantidadVeces2(rta, elem) == 0:
                rta.append(elem)
    return rta

def cantidadDistintos(lst, e):
    if lst == []:
        return 0
    if lst[0] != e:
        if cantidadVeces2(lst, lst[0]) == 1:
            return 1 + cantidadDistintos(lst[1:], e)
    return cantidadDistintos(lst[1:], e)

def elementosDistintosRecursiva(lst, e):
    if lst == []:
        return []
    if lst[0] != e:
        if cantidadVeces2(lst, lst[0]) == 1:
            return [lst[0]] + elementosDistintosRecursiva(lst[1:], e)
    return elementosDistintosRecursiva(lst[1:], e)


