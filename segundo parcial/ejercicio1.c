/*
Autor:             Marco Pérez
Fecha:             Sat 30 Apr 2022 02:18:55 PM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o ejercicio1.out ejercicio1.c -lm
Librerías:         stdio, math
Resumen:           Ejercicio1, segundo parcial, realiza una gráfica y calcula comportamiento
*/

//librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

//inicializo las variables globales

int semana[]={1,2,3,4,5,6,7}, peso[]={20,26,31,38,45,49,54};
//Cálculo el tamaño del vector
int n =sizeof(semana)/sizeof(semana[0]);
//Ésta operación da los bits que ocupa el vector semana dividido 
//  los bits que ocupa el primer valor del vector, el resultado
//  es la cantidad de elementos (n) dentro del vector

//Prototipado de funciones

void imprimir(int datos[]);
float suma(int datos[]);
float sumaMulti(int datos1[],int datos2[]);

void main(){
    //declaramos las variables para nuestra aproximación
    //lineal
    float m, b;
    imprimir(semana);
    imprimir(peso);
    //Cálculo de los datos necesario para nuestra aproximación
    m = (n*sumaMulti(semana,peso)-suma(semana)*suma(peso))/(n*sumaMulti(semana,semana)-suma(semana)*suma(semana));
    b = (suma(peso)-m*suma(semana))/n;
    //Despliega la ecuación lineal buscada
    puts("La aproximación lineal es: ");
    printf("y= %fx + %f\n",m,b);
    puts("\n");
    //Calculo para después de 5 meses (20 semanas)
    printf("El peso alcanzado después de 5 meses es: %f Kg \n",(5*30/7)*m+b);
    //Cálculo para ver si logra pasar la evaluación 10 meses (40 semanas)
    printf("El peso alcanzado después de 10 meses es: %f Kg \n",(10*30/7)*m+b);
    puts("\nPor lo tanto, sí logra pasar la evaluación \n");
    puts("\nPodrá ver la gráfica dándole clik al archivo grafico_ej1.jpg \n");
//Ejecutamos el archivo para graficar la función obtenida
FILE *creaGnuplot = popen ("gnuplot graficador.gp", "w");

}

//Despliega los datos del vector
void imprimir(int datos[]){
    puts("Valores a operar: ");
    for (int i=0; i<n;i++){
        printf("%ld ", datos[i]);
    }
    puts("\n");
}

//Para hacer la sumatoria de elementos de una lista
float suma(int datos[]){
    float sumatoria = 0;
    for (int i=0;i<n;i++){
        sumatoria+=datos[i];
    }
    return sumatoria;
}

//Realiza la sumatoria de la multiplicación de elementos
// de dos vectores
float sumaMulti(int datos1[], int datos2[]){
    float sumatoria =0;
    for (int i=0;i<n;i++){
        sumatoria+=datos1[i]*datos2[i];
    }
    return sumatoria;
}