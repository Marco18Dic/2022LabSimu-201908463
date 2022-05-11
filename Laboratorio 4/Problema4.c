/*
Autor:             Marco Pérez
Fecha:             Tue 10 May 2022 10:32:16 AM CST
Compilafor:        gcc (Debian 10.2.1-6) 10.2.1 20210110
Para compilar:     gcc -o Problema4.out Problema4.c -lm
Librerías:         stdio, math
Resumen:          
*/

//librerias
#include <stdio.h>
#include <math.h>
void main()
{
    //declaración de variables
    //n: la dimensión de la matriz nxn
    //A, B matrices de entrada C matriz de salida
    //interruptor: bandera que me sirve para salir de un loop
    //selección: indica que operación del menu se requiere realizar
    //a: variable para hacer operaciones
    int n=3;
    double A[n][n],B[n][n],C[n][n];
    int interruptor = 1;
    float a;
    char seleccion;
    puts("\nIngrese el valor de la constante:     ");
    scanf("%f",&a);
    //Para ingresar los componentes de cada matriz
    puts("\nMatriz A(3x3)\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Elemento fila,columna (%d,%d):     ", i+1,j+1);
            scanf("%lf",&A[i][j]);
        }
    }
    puts("\nMatriz B(3x3)\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Elemento fila,columna (%d,%d):     ", i+1,j+1);
            scanf("%lf",&B[i][j]);
        }
    }
    //Creación del menú principal
    interruptor = 1;
    //loop que mantiene al programa dentro del menu
    while (interruptor)
    {
        printf("\nMenú Principal\n");
        printf("\n(a).Matriz A por constante\n");
        printf("(b).Suma de las dos matrices\n");
        printf("(c).Resta de las dos matrices\n");
        printf("(d).Multiplicacion de las dos matrices\n");
        printf("(e).Determinante de Matriz A\n");
        printf("(f).Transpuesta de Matriz B\n");
        printf("(g).Inversa de Matriz A\n");
        printf("(h).Reducción de Gauss de Matriz A\n");
        printf("(i).Reducción de Gauss Jorgan de Matriz B\n");
        printf("(s).Salir de la Aplicación\n");
        printf("\nSelecciona una opción...\n");
        scanf(" %c",&seleccion);
        //Si presiona a, calcula Matriz A por constante
        if (seleccion=='a')
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    C[i][j]=a*A[i][j];
                }
                printf("[%.2lf  %.2lf  %.2lf]\n", C[i][0],C[i][1],C[i][2]);
            }    
        }
        //si presiona b, Suma de las dos matrices
        else if (seleccion== 'b')
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    C[i][j]=A[i][j]+B[i][j];
                }
                printf("[%.2lf  %.2lf  %.2lf]\n", C[i][0],C[i][1],C[i][2]);
            }
        }
        //si presiona c, Resta de las dos matrices
        else if (seleccion=='c')
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    C[i][j]=A[i][j]-B[i][j];
                }
                printf("[%.2lf  %.2lf  %.2lf]\n", C[i][0],C[i][1],C[i][2]);
            }
        }
        //si presiona d, Multiplicacion de las dos matrices
        else if (seleccion=='d')
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int suma =0;
                    for (int k = 0; k < n; k++)
                    {
                        suma +=A[i][k]*B[k][j];
                    }
                    C[i][j]=suma;
                }
            printf("[%.2lf  %.2lf  %.2lf]\n", C[i][0],C[i][1],C[i][2]);
            }
        }
        //si presiona e, calcula el determinante de la matriz A 
        else if (seleccion=='e')
        {
            double Det = A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])-A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])+A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
            printf("\nEl determinande de la matriz A es: %.2lf\n",Det);  
        }
        //si presiona f, calcula la traspuesta de la matriz B
        else if (seleccion=='f')
        {
            for (int i = 0; i < n; i++)
            {
                printf("[%.2lf    %.2lf   %.2lf]\n",B[0][i],B[1][i],B[2][i]);
            }
        }
        //si presiona g, calcula la inversa de la matriz Z
        //para esto estoy usando la fórmula de la adjunta traspuesta
        //dividido el determinante
        else if (seleccion=='g')
        {
            C[0][0]=A[1][1]*A[2][2]-A[1][2]*A[2][1];
            C[1][0]=-A[1][0]*A[2][2]+A[1][2]*A[2][0];
            C[2][0]=A[1][0]*A[2][1]-A[1][1]*A[2][0];
            C[0][1]=-A[0][1]*A[2][2]+A[0][2]*A[2][1];
            C[1][1]=A[0][0]*A[2][2]-A[0][2]*A[2][0];
            C[2][1]=-A[0][0]*A[2][1]+A[0][2]*A[2][0];
            C[0][2]=A[0][1]*A[1][2]-A[0][2]*A[1][1];
            C[1][2]=-A[0][0]*A[1][2]+A[0][2]*A[1][0];
            C[2][2]=A[0][0]*A[1][1]-A[0][1]*A[1][0];
            double Det = A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])-A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])+A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    C[i][j]=C[i][j]/Det;
                }
                printf("[%.2lf    %.2lf   %.2lf]\n",C[i][0],C[i][1],C[i][2]);
            }
        }
        //si presiona h, hace la reducción de Gauss a la matriz A
        else if (seleccion=='h')
        {
            int aux1=A[1][0];
            for (int i = 0; i < n; i++)
            {
                C[0][i]=A[0][i]/A[0][0];
                C[1][i]=C[0][i]*aux1-A[1][i];
                C[2][i]=0;
            }
            C[1][2]=C[1][2]/C[1][1];
            C[2][2]=1;
            C[1][1]=1;
            for (int i = 0; i < n; i++)
            {
                printf("[%.2lf    %.2lf   %.2lf]\n",C[i][0],C[i][1],C[i][2]);
            }
        }
        //si presiona i, hace la reducción de Gauss-Jordan de la matriz B
        else if (seleccion=='i')
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i==j)
                    {
                        C[i][j]=1;
                    }
                    else
                    {
                        C[i][j]=0;
                    }
                }
                printf("[%.2lf    %.2lf   %.2lf]\n",C[i][0],C[i][1],C[i][2]);    
            }
            
        }
        //si presiona s, sale del programa
        else if (seleccion=='s')
        {
            interruptor = 0;
        }
        //cualquier otra acción da el mensaje de opción no válida
        //y regresa al menu
        else
        {
            printf("\nOpción no válida, vuelva a intentar");
        }
    }
}