#!/bin/bash
:<<'Header'
Autor:              Marco Perez
Fecha:              06/03/2022
Tipo de Archivo:    Script de bash
Ejecucion:          ./ejercicio2.sh
Resumen:            Ejercicio 2 Laboratorio 3
Header
now=$(date)
echo ¿ Cuál es el nombre del archivo ?
read archivo
echo Escriba un breve resumen:
read resumen
echo Entradas del Programa:
read entrada
echo Salidas del Programa:
read salida
if [ -z $archivo ]
then 
    echo El nombre de archivo está vacío
else 
    echo El nombre del archivo es: $archivo
    touch $archivo.c
    echo -e "/* \nAutor: $HOSTNAME \nCompilator: GCC Version 10.2.1 \nCompilado: gcc $archivo.c -o $archivo \nFecha: $now \nLibrerias: stdio, (otras) \nResume: $resumen \nEntrada: $entrada \nSalida: $salida \n*/ \n \n//Librerias \n#include <stdio.h> \n//numerar los pasos del pseudocodigo" >> $archivo.c
fi