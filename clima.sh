#!/bin/bash

: << 'Header'
Autor:              Marco Perez
Fecha:              06/03/2022
Tipo de Archivo:    Script de bash
Ejecucion:          ./clima.sh
Resumen:            Ejercicio 1 Laboratorio 3
Header

curl -s wttr.in/Guatemala >  archivonuevo
head -7 archivonuevo
rm archivonuevo
