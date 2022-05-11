/*
Autor:             Marco Pérez
Fecha:             Sat 7 May 2022 02:18:55 PM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o Problema1.out Problema1.c 
Librerías:         stdio, stdlib
Resumen:           Problema 1 del Laboratorio 4
*/

//librerias
#include <stdio.h>
#include <stdlib.h>

void main(){
    //Inicializo la variable seleccion
    //es la que me indica el orden (ascendente o des)
    char seleccion;
    //inicializo e ingreso los elementos del vector,
    //A es para ascendente D para descendente
    int n=10;
    int A[n];
    puts("\nVector Inicial\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Elemento n° %d:     ", i+1);
        scanf("%i",&A[i]);
    }
    //Ordenamiento por el método Burbuja
    puts("\nOrdenando");
    int interruptor = 1;
    int pasada, j;
    //bucle que controla la cantidad de pasadas
    for (pasada = 0; pasada < 10-1 && interruptor; pasada++)
    {
        interruptor = 0;
        //maneja el paso por el vector
        for (j = 0; j < 10-pasada-1; j++)
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
    //Creación del menú principal
    interruptor = 1;
    //loop que mantiene al programa dentro del menu
    while (interruptor)
    {
        printf("\nMenú Principal\n");
        printf("\n(a).Ordena el vector ascendentemente\n");
        printf("(d).Ordena el vector descendentemente\n");
        printf("(s).Salir de la aplicación\n");
        printf("\nSelecciona una opción...");
        scanf(" %c",&seleccion);
        //Si presiona a, despliega el vector en órden ascendente
        if (seleccion=='a')
        {
            printf("\nUsted ha seleccionado el órden ascendente:\n");
            for (int i = 0; i < 10; i++)
            {
                printf("\nElemento n° %d: %i\n", i+1, A[i]);    
            }
        }
        //si presiona d, despliega el vector en forma descendente
        else if (seleccion=='d')
        {
            printf("\nUsted ha seleccionado el órden descendente:\n");
            for ( int i = 0; i < 10; i++)
            {
                printf("\nElemento n° %d: %i\n", i+1, A[9-i]);
            }
        }
        //si presiona s, sale del programa
        else if (seleccion=='s')
        {
            interruptor = 0;
        }
        //cualquier otra acción da el mensaje de opción no válida
        else
        {
            printf("\nOpción no válida, vuelva a intentar");
        }
        
    }
}