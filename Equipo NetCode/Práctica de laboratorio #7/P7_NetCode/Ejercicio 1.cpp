#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
/*
Nombre del Programa: Matriz A,Vector X y Vector Z

Descripción: E.P. que lea una matriz A de n x m elementos, así como un vector X de n elementos que contengan números reales. 
Calcular el producto de matriz por vector columna: el producto de la matriz A por el vector X, es un vector Z donde el elemento 1 está dado por 
la sumatoria de los productos del elemento 1 del vector X por cada uno de los elementos de la fila 1 de la matriz A, lo propio para el 2, 3, 4, ..n.
Imprimir la matriz, el vector X y el vector Z, cada arreglo a un lado del otro.

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 10/03/2020
*/

int main (){
	setlocale(LC_ALL,"");
	
	int i,j,n,m;
	int filas,columnas;
	
	//Datos de la matriz A
	printf ("Bienvenido\n");
	printf ("Ingrese los datos de la matriz: \n");
	printf ("Ingrese el total de filas: ");
	scanf ("%d", &filas);
	printf ("Ingrese el total de columnas: ");
	scanf ("%d", &columnas);
	
	double Matriz[filas][columnas];
	//Datos del vector X
	printf ("\n\nAhora ingrese el total de elementos del vector: ");
	do{
		scanf ("%d",&n);
		if (n!=filas){
			printf ("\nEl total de elementos del vector debe coincidir con el total de filas de la matriz\n");
			printf ("Ingrese nuevamente: ");
		}
	}while (n!=filas);
	
	double vector1[n];
	//Generamos el vector Z
	double vector2[n];
	//Lectura de datos
	system ("cls");
	printf ("Ahora ingrese los datos de la matriz: \n");
	for (i=0;i<filas;i++){
		for (j=0;j<columnas;j++){
			printf ("Ingrese el elemento (%d,%d): ",i+1,j+1);
			scanf ("%lf",&Matriz[i][j]);
		}
	}
	printf ("\nAhora ingrese los datos del vector: \n");
	for (i=0;i<n;i++){
		printf ("Ingrese el elemento %d/%d: ",i+1,filas);
		scanf ("%lf",&vector1[i]);
	}
	//Calculamos el vector Z
	double aux;
	
	for (i=0;i<filas;i++){
		aux=0;
		for (j=0;j<columnas;j++){
			aux= aux + (Matriz[i][j]*vector1[i]);
		}
		vector2[i] = aux;
	}
	//Imprimimos los resultados
	system("cls");
	printf ("Ahora imprimiremos los datos....\n");
	printf ("\nLa matriz A es: \n");
	for (i=0;i<filas;i++){
		for (j=0;j<columnas;j++){
			printf ("  %.2lf",Matriz[i][j]);
		}
		printf ("\n");
	}
	
	printf ("\nEl vector X es: \n");
	for (i=0;i<filas;i++){
		printf (" %.2lf\n",vector1[i]);
	}
	
	printf ("\nEl vector generado Z es: \n");
	for(i=0;i<filas;i++){
		printf ("%.2lf\n",vector2[i]);
	}
	
	getchar();
	return 0;
}
