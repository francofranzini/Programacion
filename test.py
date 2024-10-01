import Practica4 as p4

assert p4.listatupla([("Jotel", "Pipipipi"), ("Negrelson", "Deboca"), ("Imagine", "SisyphusHappy"), ("Jotel", "Quemaneradedecirboludeces"),("Marxfran", "Algebramefolla")]) == {'Jotel': ['Pipipipi', 'Quemaneradedecirboludeces'], 'Negrelson': ['Deboca'], 'Imagine': ['SisyphusHappy'], 'Marxfran': ['Algebramefolla']}