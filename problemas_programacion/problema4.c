/*
Autor:             Marco Pérez
Fecha:             Thu 12 May 2022 05:58:53 PM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o problema4.out problema4.c
Librerías:         stdio
Resumen:           Este programa me dice si un numero es primo
*/

//librerias
#include <stdio.h>

int main() {
  //Se declaran e inicializan las variables
  int N, i = 2, primo = 1;
  //Se solicita al usuario ingresar un número entero
  puts("Ingrese un número entero: ");
  scanf("%d", &N);
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
  // si primo=0 no es primo
  if (primo == 0) {
    printf("%d no es un numero primo. \n", N);
  } else {
    //si primo =1, es primo
    printf("%d es un numero primo. \n", N);
  }
  return 0;
}
