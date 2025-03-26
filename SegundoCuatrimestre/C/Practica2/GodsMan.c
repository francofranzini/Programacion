#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i, n) for(int i =0; i<n; i++)
int main(){

int x;

x = 5

mov   a b   //  a  =  b
add   a b   //  a +=  b
store a b   // *a  =  b
load  a b   //  a  = *b

3 + 5
mov r1 3    (r1 = 3 ; r2 = ? ; stack = [])
push r1     (r1 = 3 ; r2 = ? ; stack = [3])
mov r1 5    (r1 = 5 ; r2 = ? ; stack = [3])
pop r2      (r1 = 5 ; r2 = 3 ; stack = [])
add r1 r2   (r1 = 8 ; r2 = 3 ; stack = [])

# dada una expresion
# devuelve un codigo en assembler
# que evalua la expresion
# dejando el valor en r1
valor(variable x)    = if es_array(x):  valor(ampersand (variable x))
                       else:            valor(asterisco (ampersand (variable x)))
valor(literal x)     = "mov r1 x"
valor(suma x y)      = valor(x) ; "push r1" ; valor(y) ; "pop r2" ; "add r1 r2" 
valor(ampersand x)   = ref(x)
valor(asterisco x)   = valor(x) ; "load r1 r1"
valor(corchete x y)  = valor(asterisco (suma x y)) 

int x;
valor (variable "x")
-> valor(asterisco (ampersand (variable "x")))
-> valor(ampersand (variable "x")) ; "load r1 r1"
-> ref(variable "x") ; "load r1 r1"

int a[10];
valor (variable "a")
-> valor(ampersand(variable "a"))
-> ref(variable "a")

*(&x)

()
A[i] -> *(A+i) -> *(&A + i) -> *(&A + *(&i))

A[i]
A[i][j][k]

1 op en C =~ 10 ops en ASM

ref(var "A")
push r1
ref(var "i")
load r1 r1
push r1
mov r1 4
pop r2
mul r1 r2
pop r2
add r1 r2
load r1 r1

# dada una expresion
# devuelve un codigo en assembler
# que evalua la direccion de expresion
# dejando la direccion en r1
ref(variable x)    = ...


    funci( n, longitud);
    funci(&n, longitud);
    
    /* si n es un array */      n == &n
    /* si n es un array */     &n == &(&n)[0]
    /* si p es un puntero */ p[i] == *(p+i)
    return 0;
}