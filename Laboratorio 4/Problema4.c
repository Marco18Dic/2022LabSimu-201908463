/*
Autor:             Marco Pérez
Fecha:             Tue 10 May 2022 10:32:16 AM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o Problema4.out Problema4.c -lm
Librerías:         stdio, math
Resumen:          
*/

//librerias
#include <stdio.h>
#include <math.h>
void main(){
    //declaración de variables
    //n: la dimensión de la matriz nxn
    //A, B matrices de entrada C matriz de salida
    //interruptor: bandera que me sirve para salir de un loop
    //selección: indica que operación del menu se requiere realizar
    //a: variable para hacer operaciones
    int n=3;
    double A[n][n],B[n][n],C[n][n];
    int interruptor = 1;
    float a;
    char seleccion;
    scanf("\nIngrese el valor de la constante:%f",a);
    //Para ingresar los componentes de cada matriz
    puts("\nMatriz A(3x3)\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Elemento fila,columna (%d,%d):     ", i+1,j+1);
            scanf("%lf",&A[i][j]);
        }
    }
    puts("\nMatriz B(3x3)\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Elemento fila,columna (%d,%d):     ", i+1,j+1);
            scanf("%lf",&B[i][j]);
        }
    }
    //Creación del menú principal
    interruptor = 1;
    //loop que mantiene al programa dentro del menu
    while (interruptor)
    {
        printf("\nMenú Principal\n");
        printf("\n(a).Matriz A por constante\n");
        printf("(b).Suma de las dos matrices\n");
        printf("(c).Resta de las dos matrices\n");
        printf("(d).Multiplicacion de las dos matrices\n");
        printf("(e).Determinante de Matriz A\n");
        printf("(f).Transpuesta de Matriz B\n");
        printf("(g).Inversa de Matriz A\n");
        printf("(h).Reducción de Gauss de Matriz A\n");
        printf("(i).Resta de las dos matrices\n");
        printf("(s).Reducción de Gauss Jorgan de Matriz B\n");
        printf("\nSelecciona una opción...");
        scanf(" %c",&seleccion);
        //Si presiona a, calcula Matriz A por constante
        if (seleccion=='a')
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    C[i][j]=a*A[i][j];
                    printf("Elemento fila,columna (%d,%d):     %.2lf", i+1,j+1,C[i][j]);
                }
            }    
        }
        //si presiona b, Suma de las dos matrices
        else if (seleccion=='b')
        {
            
        }
        //si presiona c, Resta de las dos matrices
        else if (seleccion=='c')
        {
            
        }
        //si presiona d, Multiplicacion de las dos matrices
        else if (seleccion=='d')
        {
        
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