/*
Autor:             Marco Pérez
Fecha:             Wed 11 May 2022 03:51:47 PM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o Problema6.out Problema6.c -lm
Librerías:         stdio, math
Resumen:           Problema 6 del Laboratorio 4
                   Operaciones con sumatorias y series
*/

//librerias
#include <stdio.h>
#include <math.h>

void main(){
    //declaracion de las variables
    //n valor de numero al que queremos ejecutar las series
    int n, interruptor=1;
    float resultado;
    char seleccion;
    //limitar al usuario a mis condiciones n>0
    do
    {
        puts("Ingrese un valor entero positivo para n: ");
        scanf("%i",&n);
    } while (n < 1);
    while (interruptor)
        {
        resultado=0.00;
        //Menú Principal
        printf("\nMenú Principal\n");
        printf("\n(a).Sumatoria Σ k^2(k-3)\n");
        printf("(b).Sumatoria Σ 3/(k-1)\n");
        printf("(c).Sumatoria\n"); 
        printf("    Σ (1/sqrt(5))*((1+sqrt(5))/2)^n-(1/sqrt(5))*((1-sqrt(5))/2)^n\n");
        printf("(d).Sucesión de Bode: Sumatoria Σ 0.1*(3*2^(k-2)+4)\n");
        printf("(s).Salir de la aplicación\n");
        printf("\nSelecciona una opción...");
        scanf(" %c",&seleccion);
        //Si presiona a, Sumatoria k^2(k-3)
        if (seleccion=='a')
        {
            for (int i = 1; i <= n; i++)
            {
                resultado+=pow(i,2)*(i-3);
                }
            printf("El resultado de la sumatoria a) es: %.2f",resultado);
        }
        //si presiona b, Sumatoria 3/(k-1)
        else if (seleccion=='b')
        {
            for (int i = 2; i <= n; i++)
            {
                resultado+=(3.00/(i-1));
                printf("%.2f\n",resultado);
            }
            printf("El resultado de la sumatoria b) desde k=2 es: %.2f",resultado);
        }
        //si presiona c, Sumatoria (1/sqrt(5))*((1+sqrt(5))/2)^n-(1/sqrt(5))*((1-sqrt(5))/2)^n
        else if (seleccion=='c')
        {
            resultado+=n*(1.00/sqrt(5))*(pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n));
            printf("El resultado de la sumatoria c) es: %.2f",resultado);
        }
        //si presiona d, Sucesión de Bode: Sumatoria 0.1*(3*2^(k-2)+4)
        else if (seleccion=='d')
        {
            for (int i = 2; i <= n; i++)
            {
                resultado+=0.1*(3*pow(2,(i-2))+4);
            }
            printf("El resultado de la sumatoria d) es: %.2f",resultado);
        }
        //si presiona s, sale del programa
        else if (seleccion=='s')
        {
            interruptor = 0;
        }
        //cualquier otra acción da el mensaje de opción no válida
        //y regresa al menu
        else
        {
            printf("\nOpción no válida, vuelva a intentar");
        }
    }
}