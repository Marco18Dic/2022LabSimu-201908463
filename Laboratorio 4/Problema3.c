/*
Autor:             Marco Pérez
Fecha:             Tue 10 May 2022 09:16:16 AM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o Problema3.out Problema3.c -lm
Librerías:         stdio, math
Resumen:           Problema 3 del Laboratorio 4
                   Este programa solicita dos vectores en 3d
                   y realiza varias operaciones entre ellos
                   a) magnitud
                   b) suma
                   c) producto escalar
                   d) producto vectorial
*/

//librerias
#include <stdio.h>
#include <math.h>
void main(){
    //declaración de variables
    //n: la dimensión del vector
    //A, B vectores de entrada C vector de salida
    //interruptor: bandera que me sirve para salir de un loop
    //selección: indica que operación del menu se requiere realizar
    int n=3;
    double A[n],B[n],C[n];
    int interruptor = 1;
    char seleccion;
    //Para ingresar los componentes (x,y,z) de cada vector
    puts("\nVector A(x,y,z)\n");
    for (int i = 0; i < n; i++)
    {
        printf("Elemento n° %d:     ", i+1);
        scanf("%lf",&A[i]);
    }
    puts("\nVector B(x,y,z)\n");
    for (int i = 0; i < n; i++)
    {
        printf("Elemento n° %d:     ", i+1);
        scanf("%lf",&B[i]);
    }
    //Creación del menú principal
    interruptor = 1;
    //loop que mantiene al programa dentro del menu
    while (interruptor)
    {
        printf("\nMenú Principal\n");
        printf("\n(a).Magnitud de cada Vector\n");
        printf("(b).Suma de los Vectores\n");
        printf("(c).Producto Escalar\n");
        printf("(d).Producto Vectorial\n");
        printf("(s).Salir de la aplicación\n");
        printf("\nSelecciona una opción...");
        scanf(" %c",&seleccion);
        //Si presiona a, calcula la magnitud de los vectores A y B
        if (seleccion=='a')
        {
            double M1=sqrt(pow(A[0],2)+pow(A[1],2)+pow(A[2],2));
            printf("\nLa Magnitud del Vector A es = %.2lf;",M1);
            double M2=sqrt(pow(B[0],2)+pow(B[1],2)+pow(B[2],2));
            printf("  B es = %.2lf",M2);
        }
        //si presiona b, suma los vectores A y B
        else if (seleccion=='b')
        {
            for (int i = 0; i < n; i++)
            {
                C[i]=A[i]+B[i];
            }
            
            printf("\nLa Suma de los Vectores es C(x,y,z) = (%.2lf,%.2lf,%.2lf)",C[0],C[1],C[2]);
        }
        //si presiona c, hace el producto escalar de A y B
        else if (seleccion=='c')
        {
            for (int i = 0; i < n; i++)
            {
                C[i]=A[i]*B[i];
            }
            printf("\nEl Producto Escalar de A·B =(%.2lf,%.2lf,%.2lf)",C[0],C[1],C[2]);
        }
        //si presiona d, hace el producto vectorial de A y B
        else if (seleccion=='d')
        {
            C[0]=A[1]*B[2]-A[2]*B[1];
            C[1]=A[2]*B[0]-A[0]*B[2];
            C[2]=A[0]*B[1]-A[1]*B[0];
            printf("\nEl Producto Vectorial de AXB =(%.2lf,%.2lf,%.2lf)",C[0],C[1],C[2]);
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