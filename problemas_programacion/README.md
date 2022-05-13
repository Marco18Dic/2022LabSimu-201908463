# Problemas de Programación

## Problema 1

### Enunciado:
Desarrolle un programa que lea tres números reales del teclado y escriba por pantalla la media aritmética únicamente de los números positivos. Realice la programación para los siguientes dos diseños.

### Metodología:
Se le pide al usuario que ingrese tres números y el programa programa deberá descartar los valores no admitidos (negativos) y realizar la media del resto. Para ello usamos instrucciones while y instrucciones if else.

### Variables de entrada y salida:
Entrada: 

x (almacena el numero que se está ingresando).

Salida: 

med (se almacena la media de los numeros validos)

Variables: 

n (cuenta la cantidad de numeros validos ingresados)

i (las pasadas del while que son 3)

### Diagrama de flujo:

![Problema1](https://github.com/Marco18Dic/2022LabSimu-201908463/blob/main/problemas_programacion/imagenes/Problema1.JPG)

          
# Problema 2

### Enunciado

Desarrolle un programa que lea un número indeterminado de alturas, que pare cuando se ingrese una negativa y calcule la media, máximo y mínimo

### Metodología:

Se le pide al usuario que ingrese la primera altura, esta se aloja en variables para guardar el valor máximo y minimo, luego se are un loop while y dentro se suma el valor a la variable med, cada pasada, se añade el valor a med y se compara con los valores maximo y minimo, si existe un nuevo maximo o minimo se sustituye este valor en la variable, se vuelve a solicitar al usuario ingrese una nueva altura y se repite el ciclo, al ingresar una altura negativa, se rompe el loop, se divide el valor med dentro del numero de pasadas válidas y se imprime el resultado de la media, del valor máximo y del mínimo.

### Variables de entrada y salida:

Entrada:

x es donde se almacena la altura

Salida:

max "en esta varible se almacena la altura máxima hasta el momento"
min "lo mismo pero para el valor minimo"
med "se van sumando las alturas y al final se divide por el numero de ciclos"

Variables:

n "el numero de ciclos del loop while"

### Diagrama de flujo:

![Problema2](https://github.com/Marco18Dic/2022LabSimu-201908463/blob/main/problemas_programacion/imagenes/Problema2.JPG)

# Problema 3

### Enunciado:

Desarrolle un programa que calcule la raiz cuadrada entera por defecto de un número N positivo dado, R > 0, tal que R<sup>2</sup> <= N.

### Metodología:

Se pide al usuario que ingrese un número y se le impone que este sea positivo por medio de un loop while. En un nuevo loop se se multiplica un numero, comenzando por el uno, por si mismo y se compara con el número ingresado, si es menor se aumenta una unidad y se realiza un nuevo ciclo.  El ciclo se rompe cuando el numero del conteo por sí mismo es mayor al numero ingresado.  Por último se muestra el resultado.

### Variables de entrada y salida:

Entrada:

n El número al que se le sacará la raíz entera.

Salida:

r La raíz, esta va aumentando su valor de uno en uno.

### Diagrama de flujo:

![Problema3](https://github.com/Marco18Dic/2022LabSimu-201908463/blob/main/problemas_programacion/imagenes/Problema3.JPG)

# Problema 4

### Enunciado:

Desarrolle un programa que lea un número mayor que uno y determine si es primo.

### Metodología:

Se le pide al usuario ingresar un número entero, se abre un loop while en donde se hace residuo de la división del número ingresado dentro de un contador que empieza en dos hasta el número menos uno, si el residuo es cero indica que el número es divisible y por lo tanto no es primo.

### Variables de entrada y salida:

Entrada:

n es el número del que se quiere sabe si es primo

Salida:

primo "es la variable que nos indica 1 si es primo y 0 si no lo es.

### Diagrama de flujo:

![Problema4](https://github.com/Marco18Dic/2022LabSimu-201908463/blob/main/problemas_programacion/imagenes/Problema4.JPG)

# Problema 5

### Enunciado:

Desarrolle un programa que lea dos números enteros para generar un rango y que muestre todos los números primos en ese rango

### Metodología:

Para este problema usaremos recursividad con el código del problema anterior que calcula numeros primos.  El programa principal lee los dos números que formarán el rango y al igual que el problema anterior, se hace un bucle que empiece en el principio del rango y que vaya subiendo de uno en uno cada pasada hasta llegar al final del rango, el bucle llamará a la función "primo" para comprobar si el número que corresponde a cada pasada es primo o no, si lo es lo muestra en pantalla. El resultado final es una lista con todos los números primos dentro del rango.

### Variables de entrada y salida:

Entrada:

N1 rango inferior
N2 rango superior

Salida:

primo "esta variable es uno o cero dependiendo si el número es primo o no respectivamente.

Función:

primo() función que dice si un número es primo o no

### Diagrama de flujo:

![Problema5](https://github.com/Marco18Dic/2022LabSimu-201908463/blob/main/problemas_programacion/imagenes/Problema5.JPG)

