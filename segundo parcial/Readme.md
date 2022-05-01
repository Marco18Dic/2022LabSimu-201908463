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
