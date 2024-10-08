import Practica4 as p4

assert p4.masLarga("Hye HYE HYEEE") == {"H": "HYEEE", "Y": "HYEEE", "E":"HYEEE","y":"Hye", "e":"Hye"}
assert p4.ej7({"Juani": [2,4,6,8], "Negrelson": [10,10,10,10], "El M":[6,6,6,6]}) == "Negrelson"
assert p4.ej7({"Juani": [2,4,6,8], "Negrelson": [10,10,10,10], "El M":[6,6,6,6]}, "Juani") == 5
assert p4.ej10([1,2,2,1,1,2,3,4,5,5,5,6]) == [1,2,3,4,5,6] 
assert p4.ej11("la puta madre", "La Puta Madre") == {"la", "puta", "madre"}
assert p4.ej12({1,2,3,4,5,6},{4,5,6}) == {1,2,3}
assert p4.ej12({1,2,3,4,5,6},set()) == {1,2,3,4,5,6}
assert p4.ej13([1,3,5,7]) == [2,4,6]
assert p4.ej13aux([1,3,5,7]) == {2,4,6}
assert p4.ej14({"OPO":["Lunes", "Miercoles", "Viernes"], "UNTZ":["Lunes", "Martes", "Miercoles"], "MATZFRAN":["Miercoles"]}) == {"Miercoles"}
