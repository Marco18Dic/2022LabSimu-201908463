/*
Autor:             Marco Pérez
Fecha:             Sun 01 May 2022 09:32:41 AM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o ejercicio2.out ejercicio2.c -lm
Librerías:         stdio, math, stdlib.h
Resumen:           Ejercicio2 Segundo Exámen Parcial, método de Newton-Raphson
*/

//librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//prototipado de funciones
float fdex(float x);
float derfdex(float x);
void NewRaphson(float xini, float error, int iteraciones, int *actual, float *solucion);

//Programa principal, solamente para entrada/salida y llamado de funciones
void main (void){
    //definimos las variables:  
    //xini = el valor aprox. que creemos es solucion
    //error = la exactitud que deseamos
    //solucion = el resultado
    //actual = la iteración en progreso
    //iteraciones = la cantidad de iteraciones que queremos
    
    float xini, error, solucion;
    int iteraciones, actual;

    //ingreso de datos
    printf("¿Cuál es el valor aproximado para x?   ");
    scanf("%f",&xini);
    printf("Ingrese el error mínimo deseado:   ");
    scanf("%f",&error);
    printf("¿Cuántas iteraciones desea?   ");
    scanf("%d",&iteraciones);
    NewRaphson(xini,error,iteraciones,&actual,&solucion);
    if (actual == iteraciones || isnan(solucion)||xini==1){
        printf("\nLuego de efectuar %d iteraciones, \nno encontré la solución o resulta un numero indefinido\n",actual);
        printf("\nEL método Newton-Raphson falla para x=1 \n");
        }
    else { 
        printf("\nLa solución es %.4f\n",solucion);
        printf("\nEl número de iteraciones es %d \n",actual);
    }
}

//Función que efectúa las iteraciones del método
void NewRaphson(float xini, float tolerancia, int iteraciones, int *actual, float *solucion){
    //Se definen variables locales: xanterior= la aproximación de la iteración anterior
    //                              x=resultado obtenido en la iteración en proceso
    //                              diferencia=x-xanterior
    int i=1;
    float xanterior=xini;
    float x=xanterior-fdex(xanterior)/derfdex(xanterior);
    float diferencia=x-xanterior;
    //Sacamos el valor absoludo a la variable diferencia y lo mostramos
    (diferencia<0)?diferencia=-diferencia:diferencia;
    printf("\n%d xanterior= %f x= %x diferencia= %f\n",i,xanterior,x,diferencia);
    //Loop calcula la fórmula, hasta que se alcance el error máximo o se completen las iteraciones
    while (diferencia>tolerancia && i<iteraciones){
        xanterior=x;
        x=xanterior-fdex(xanterior)/derfdex(xanterior);
        i++;
        diferencia=x-xanterior;
        // Nuevamente se vuelve a sacar valor amsoluto a diferencia y se muestra
        (diferencia<0)?diferencia=-diferencia:diferencia;
        printf("%d xanterior= %f x= %x diferencia= %f\n",i,xanterior,x,diferencia);
    }
    *solucion=x;
    *actual=i;
}

//Función f(x)
float fdex(float x){
    //Defino una variable local con valor arcoseno(x)
    float fx=asin(x);
    return fx;
}

//Función df(x)/dx (derivada de f(x))
float derfdex(float x){
    //Defino una variable local con valor 1/sqrt(1-x²)
    float dfx=1/(sqrt(1-pow(x,2)));
    return dfx;
}