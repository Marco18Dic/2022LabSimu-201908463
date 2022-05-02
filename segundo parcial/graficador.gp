unset label
clear
set terminal jpeg
set output "grafico_ej1.jpg"
set title "Prueba de levantamiento de peso"
set xlabel "Número de Semana"
set ylabel "Peso Levantado"
set grid
set style data linespoint
plot [0:43][0:270]"datos1", (5.785714)*x+14.428572