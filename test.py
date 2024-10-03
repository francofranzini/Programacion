import Practica4 as p4

assert p4.masLarga("Hye HYE HYEEE") == {"H": "HYEEE", "Y": "HYEEE", "E":"HYEEE","y":"Hye", "e":"Hye"}
assert p4.ej7({"Juani": [2,4,6,8], "Negrelson": [10,10,10,10], "El M":[6,6,6,6]}) == "Negrelson"
assert p4.ej7({"Juani": [2,4,6,8], "Negrelson": [10,10,10,10], "El M":[6,6,6,6]}, "Juani") == 5 
