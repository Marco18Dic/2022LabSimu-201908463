/*
Autor:             Marco Pérez
Fecha:             Thu 12 May 2022 05:44:34 PM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o problema3.out problema3.c
Librerías:         stdio
Resumen:           calcula la raiz cuadrada entera de un
                   positivo
*/

//librerias
#include <stdio.h>
int main() {
// Se definen e inicializan las variables
// n    es el numero al que se le quiere sacar la raiz
// r    es la raiz entera
int n=0, r=1;           
// Imponemos la condición de ingresar un numero positivo con un while
    do {                                                    
        puts("Ingrese un número entero positivo:");
        scanf("%d", &n);
    } while (n<=1);
// Vamos aumentando r un entero a lavez hasta que cumpla la condicion r*r<=n
    while (r*r<=n) { r++; }     
// Al encontrar romper la condición saldrá del loop, la raiz será r-1
    printf("\nLa raíz entera de %d es: %d \n",n, r-1);     
return 0;
}
