/*
Autor:             Marco Pérez
Fecha:             Wed 11 May 2022 01:30:27 PM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o Problema5.out Problema5.c -lm
Librerías:         stdio, math
Resumen:           Problema 5 del Laboratorio 4
                   Se pide realizar la función factorial
*/

//librerias
#include <stdio.h>
int main(){
    //declaracion de las variables
    //n valor de numero al que queremos ejecutar el factorial
    int n;
    long resultado=1;
    //limitar al usuario a mis condiciones n>0
    do
    {
        puts("Ingrese un valor entero positivo para n: ");
        scanf("%d",&n);
    } while (n < 0);
    //ejecucion de la operación recurrente "resultado"
    if (n==0||n==1)
    {
        printf("\nEl factorial de %d es:  %ld\n",n,resultado);
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            resultado=resultado*i;
        }
        printf("\nEl factorial de %d es:  %ld\n",n,resultado);
    }
    return 0;
}