#!/bin/bash

: <<'Header'
Autor:              Marco Pérez
Fecha:              08/03/2022
Tipo de archivo:    Script de Bash
Ejecución:          ./filegen.sh
Resúmen:            Bash para generar archivos programados en C
Header
#Inicio
echo "Bienvenido al Generador de Archivos C"
#Pregunta por el nombre de archivo
read -p "Ingrese el nombre del archivo: " nombre
if [ -z $nombre ]; then
    echo "No se ha ingresado un nombre válido"
    exit 2
fi
fnombre=$nombre.c"
if [ -e $fnombre ], then
    echo "El archivo ya existe"
    exit 2
fi
salida=$nombre".out"
fecha=$(date)
version=#(gcc --version | head -n )
#Escribimos el Encabezado"
echo "/*" > $fnombre
echo "Autor:             Marco Pérez" >> $fnombre
echo "Fecha:            " $fecha >> $fnombre
echo "Compilafor:       " $version >> $fnombre
echo "Para compilar:    " gcc -o $salida $fnombre >> $fnombre
echo "Librerías:        " stdio >> $fnombre
echo "Resumen:          " >> $fnombre
echo "*/" >> $fnombre
echo "" >> $fnombre
echo "//librerias" >> $fnombre 
echo "#include <stdio.h>" >> $fnombre
echo "Archivo realizado"