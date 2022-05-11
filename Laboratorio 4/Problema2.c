/*
Autor:             Marco Pérez
Fecha:             Tue 10 May 2022 08:54:59 AM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o Problema2.out Problema2.c
Librerías:         stdio, stdlib
Resumen:           Problema 2 del Laboratorio 4
                   Solicita 5 numros, los guarda y los ordena
*/

//librerias
#include <stdio.h>
#include <stdlib.h>

void main(){
    int n=5;
    int A[n];
    puts("\nVector Inicial\n");
    for (int i = 0; i < n; i++)
    {
        printf("Elemento n° %d:     ", i+1);
        scanf("%i",&A[i]);
    }
    //inicia el ordenamiento Burbuja
    puts("\nOrdenando");
    int interruptor = 1;
    int pasada, j;
    //bucle que controla la cantidad de pasadas
    for (pasada = 0; pasada < n-1 && interruptor; pasada++)
    {
        interruptor = 0;
        //maneja el paso por el vector
        for (j = 0; j < n-pasada-1; j++)
        {
            //validando que el seleccionado sea mayor al siguiente
            if (A[j] > A[j+1])
            {
                int aux;
                printf("cambio %i %i a ",A[j],A[j+1]);
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                printf("%i %i \n",A[j],A[j+1]);
            }
            interruptor = 1;
        }   
    }
    printf("\nEl Vector en órden ascendente:\n");
        for (int i = 0; i < n; i++)
        {
            printf("\nElemento n° %d: %i", i+1, A[i]);    
        }
    printf("\n\n");
}