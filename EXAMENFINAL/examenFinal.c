/*
Autor:             Marco Pérez
Fecha:             Mon 16 May 2022 08:12:35 AM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o examenFinal.out examenFinal.c -lm
Librerías:         stdio, math
Resumen:           Este programa analiza el moviemiento de cohetes
                   y calcula parámetros de vuelo del mismo
*/

//librerias
#include <stdio.h>
#include <math.h>

//Definimos constantes
#define G=0.00000000006693;
#define RT=6378000;
#define MT=5973600000000000000000000;
#define R=287.06;
#define L=0.0065;
#define g0=9.81;
#define T0=288.15;
#define P0=101325;
float t=0;
float y=0;
float cohete[6];

//Definimos características de los cohetes que guardamos en vectores
//Nombre[6]={E0,TSFC,CD,A,m0,mf0}
float AhMun[6]={30000000,0.0003248,61.27,201.06,110000,1500000};
float AhauKin[6]={2700000,0.0002248,61.27,201.06,110000,1500000};
float Chac[6]={25000000,0.0002248,70.25,215,180000,2100000};

//Prototipado de las funciones:

float mc(float t);
float Fa(float y, float t);
float gravedad(float y);
float f(float t, float y);
float heun(int n);

void main(){
    //Para el primer cohete
    cohete[6]=AhMun[6];
    //calculamos el tiempo en el que se quedará sin combustible
    //este tiempo será nuestro punto máximo del rango
    float n=cohete[5]/(0.1*cohete[1]*cohete[0]);
    printf("Por el método de heun: \n",heun(n));
    //Para el segundo cohete
    cohete[6]=AhauKin[6];
    //calculamos el tiempo en el que se quedará sin combustible
    //este tiempo será nuestro punto máximo del rango
    float n=cohete[5]/(0.1*cohete[1]*cohete[0]);
    printf("Por el método de heun: \n",heun(n));
    //Para el tercer cohete
    cohete[6]=Chac[6];
    //calculamos el tiempo en el que se quedará sin combustible
    //este tiempo será nuestro punto máximo del rango
    float n=cohete[5]/(0.1*cohete[1]*cohete[0]);
    printf("Por el método de heun: \n",heun(n));
}

float mc(float t)
{
    /*  esta función nos permite encontrar la masa en función
        del tiempo como la masa del cohete es fija, solo cambia 
        la masa del combustible a razón de -TSFC*E0*t, es decir
        la masa del combustible después de un tiempo t será
        mf(t)=mf(0)-TSFC*E0*t, por lo tanto la masa total de la nave
        será: mc(t)=m0+mf(0)-TSFC*E0*t
    */
   int mc = cohete[4]+cohete[5]-cohete[1]*cohete[0]*t;
   return mc;
}

float Fa(float y, float t)
{
    /*  Función que calcula Fa en función de y y t vel=y/t
        aquí he unificado las ecuaciones de fricción de la atmósfera 
        y la densidad del aire.
    */
    float Fa=0.5*(P0/(R*T0))*(pow((1-(L*y)/T0),(g0/(R*L))))*(cohete[2]*cohete[3]*(y/t)*sqrt(pow(2*y/t,2)));
    return Fa;
}

float gravedad(float y)
{
    //Función que calcula la gravedad en función de la altura
    float g=G*MT/(pow((RT+y),2));
    return g;
}

/*  Segunda ley de Newton aplicada al movimiento del cohete
    esta es nuestra función f(y,t), solo debemos pasar dividiendo
    al otro lado la masa...
*/
float f(float t, float y){
    float rep=0;
    rep = (cohete[0]-Fa(y,t))/mc(t)-gravedad(y);
    return rep;
}
/*  metodo numerico de heun
    h nos lo dá el problema al inicio h=0.1
*/
float heun(int n){
    FILE *pf = fopen("altura","wt");
    float w, t;
    t=0;
    w=0.63;
    float h=0.01;
    for (int i = 0; i < n; i++)
    {
        //incrementa el valor de w valuando con el tiempo actual y el valor de w actual
        w+=(h/4)*(f(t,w)+3*f(t+2*h/3,w+(2*h/3)*f(t,w)));
        //actualizamos el tiempo
        t+=0.01;
        printf("\n La altura en %f segundos es de: %f \n",t,w);
        fprintf(pf,"%.2f\t%.2f\n",t,w);
    }
    fclose(pf);
    system("gnuplot grafica.gp");
    return w;
}