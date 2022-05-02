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

## Metodología
EL método Newton-Raphson consiste en hacer aproximaciones suscesivas de la pendiente de la función en un punto determinado e ir acercandose cada vez más a la raíz hasta que la diferencia entre una aproximación y la siguiente sea tan pequeña como se desee.

La fórmula que se usa es 

$$x_{n+1}=x_n-\frac{f(x)}{f'(x)}$$

El resultado obtenido se puede tabular en una tabla así...

|Iteración(i)|$x_{i-1}$|$x_i$|Diferencia|
|---:|---:|---:|---:|
|1|$x_0$|$x_1$|$x_0-x_1$|
|2|$x_1$|$x_2$|$x_2-x_1$|
|.|.|.|.|
|.|.|.|.|
|.|.|.|.|

Se habrá llegado a la solución buscada cuando la diferencia sea tan pequeña que podemos despreciarla.

EL método de Newton-Raphson tiene la ventaja de ser muy preciso y metódico pero tiene sus desventajas, la más importante es que debemos tener una idea de por donde empezar, es decir, debemos conocer un punto cercano a la raíz del cual poder partir.

Una buena primera aproximación la podemos obtener por medio de la generación de la gráfica de f(x) en Gnuplot. 

## Variables de entrada y Salida
#### Como se menciono anteriormente debemos proporcionar al programa con un punto de partida, además, debemos indicarle el número de iteraciones máximo que debe realizar así como el error odiferencia minima requerida.

|Entrada|Salida|Tipo|
|:---|:---|:---|
|iteraciones||int|
|xini||float|
|error||float|
||actual|int|   
||solucion|float|

## Diagrama de Flujo
[Diagrama 2](https://github.com/Marco18Dic/2022LabSimu-201908463/blob/main/segundo%20parcial/Duagrama%20de%20Flujo%202.JPG)

## Código
```
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
```

