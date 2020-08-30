#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
/*
Nombre del Programa: Multiplica matrices

Descripción: Dos matrices A y B se pueden multiplicar si el número de columnas de A es igual al número de filas de B. 
En otras palabras, que los vectores fila de A, contengan el mismo número de elementos que los vectores columna de B. 
De tal forma, la multiplicación de matrices se hace multiplicando cada fila de A por cada una de las columnas de B. Por lo tanto, 
E.P. que lea las matrices A y B y si es posible, determinar e imprimir dichas matrices A y B, así como la matriz P,  (resultado de su multiplicación); cada arreglo a un lado del otro.

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 10/03/2020
*/

int main (){
	setlocale (LC_ALL,"");
	int i,j,k,a,b,n,m;
	double suma;
	
	//Capturamos los datos de las Matrices A y B
	printf ("Este programa calcula la multiplicación de matrices sí es posible\n");
	do{
		printf ("\nAhora ingrese las FILAS de la Matriz A: ");
		scanf ("%d",&n);
		printf ("Ahora ingrese las COLUMNAS de la Matriz A: ");
		scanf ("%d",&m);
		printf ("\n\nAhora ingrese las FILAS de la Matriz B: ");
		scanf ("%d",&a);
		printf ("Ahora ingrese las COLUMNAS de la Matriz B: ");
		scanf ("%d",&b);
		if (m!=a){
			printf ("\nNo es posible calcular el producto entre las matrices. Para que sea posible \n");
			printf ("las COLUMNAS de la Matriz A debe ser IGUAL a las FILAS de la Matriz B, ingrese nuevamente: \n");
		}
	}while (m!=a);

	
	double matrizA[n][m],matrizB[a][b],matrizC[n][b];
	
	//Capturamos los datos de ambas matrices
	printf ("\nBien, ahora iniciaremos la captura de los datos de la Matriz A...\n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf ("Ingrese el elemento (%d,%d): ",i+1,j+1);
			scanf ("%lf",&matrizA[i][j]);
		}
	}
	
	printf ("\n\nPor consiguiente capturaremos la Matriz B...\n");
	for (i=0;i<a;i++){
		for (j=0;j<b;j++){
			printf ("Ingrese el elemento (%d,%d): ",i+1,j+1);
			scanf ("%lf",&matrizB[i][j]);
		}
	}
	//Calculamos la nueva matriz C
	for (i=0;i<n;i++){
		for (j=0;j<b;j++){
			suma = 0;
			for (k=0;k<a;k++){
				suma = suma + (matrizA[i][k]*matrizB[k][j]);
			}
			matrizC[i][j] = suma;
		}
	}
	//Imprimimos las matrices
	system ("cls");
	printf ("La Matriz A es: \n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf ("  %.2lf",matrizA[i][j]);
		}
		printf ("\n");
	}
	printf ("\nLa Matriz B es: \n");
	for (i=0;i<a;i++){
		for (j=0;j<b;j++){
			printf ("  %.2lf",matrizB[i][j]);
		}
		printf ("\n");
	}
	
	printf ("\nPor lo tanto, la Matriz C quedaría: \n");
	for (i=0;i<n;i++){
		for (j=0;j<b;j++){
			printf ("  %.2lf", matrizC[i][j]);
		}
		printf ("\n");
	}
	
	
	
	getchar();
	return 0;
}
