/*
Autor:             Marco Pérez
Fecha:             Thu 12 May 2022 06:13:32 PM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o problema5.out problema5.c
Librerías:         stdio
Resumen:           El programa indica los numero primos dentro de un rango dado
*/

//librerias
#include <stdio.h>

//Prototipado de función
int primo(int N);

int main() {
  //Se inicializan las variables
  int N1, N2;
  //Se pide al usuario ingresar los limites del rango
  puts("\nIngrese el límite inferior del rango: \n");
  scanf("%d", &N1);
  puts("\nIngrese el límite superior del rango: \n");
  scanf("%d", &N2);
  puts("\nLos números primos son:  \n");
  //Bucle N1<=i<=N2
  for (int i = N1; i <= N2; i++) {
    //Escribirlo si lo es.
    if (primo(i) == 1) {
      printf("%d   ", i);
    }
  }
  puts("\n");
  return 0;
}

//Función primo
int primo(int N) {
  //Se declaran e inicializan las variables
  int i = 2, primo = 1;
  //Las condiciones a cumplir son: i < N - 1 && primo == 1
  while (i < N - 1 && primo == 1) {
    // N es divisible entre i?
    if (N % i == 0) {
      //Si es divisible, no es primo, primo=0
      primo = 0;
    }
    //aumenta el contador
    i++;
  }
  return primo;
}