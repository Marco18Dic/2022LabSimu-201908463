# Segundo Parcial

## Primer Problema:
#### Un atleta necesita pasar la evaluación física para poder ingresar a la selección de su equipo. Como mínimo debe poder de realizar diez sentadillas con 250 Kg de peso. 10 meses antes de la evaluación sufre un desgarre en el cuadricep derecho, lo que le permitió obtener la siguiente evolución
|semana|peso(Kg)|
| ---:|---:|
|1|20|
|2|26|
|3|31|
|4|38|
|5|45|
|6|49|
|7|54|
|||
Le solicitan que genere un programa el cual cumpla con las siguientes condiciones
- Una gráfica que compare los valores tabulados y la recta que mejor aproxima el crecimiento.
- Estima el peso que logra levantar el atleta después de 5 meses, este logra pasar la prueba para ingresar al equipo.
## Metodología
#### Se usó una aproximación de mínimos cuadrados.
Se calcula la pendiente con la fórmula:

$$m=\frac{n\sum xy-\sum x \sum y}{m\sum x² -\left(\sum x\right)²}$$
$$b=\frac{\sum y-m\sum x}{n}$$ 

se plotean los puntos y la aproximación lineal obtenida en Gnuplot para obtener información del rendimiento futuro del atlata.
Se ingresan a la fórmula los datos del plazo de tiempo y con ello se responda a la pregunta ¿Logrará el atleta, levantar 250Kg en 10 meses plazo?
## Variables de entrada y salida
#### se usaron vectores como variable de entrada tipo entero y la salida son variables tipo flotante.
|entrada|salida|
|:---|:---|
|entero|flotate|
|semana|m|
|peso|b|
|||
## Diagrama de Flujo
[Diagrama 1](https://github.com/Marco18Dic/2022LabSimu-201908463/blob/main/segundo%20parcial/Diagrama%20de%20Flujo%201.JPG)
## Código
```
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
```
## Segundo Problema
#### Utilizando un método numérico, encuentra la raiz de la ecuación

$$f(x)=\arcsin(x)$$

#### Debe de realizar la gráfica de la ecuación y compara el resultado obtenido con el programa realizado en C.



