#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
/*
Nombre del Programa: Ejercicio 64 - La matriz de 15x13 

Descripción: . . E.P. que lea una matriz de 15 X 13 elementos y que calcule e
imprima lo siguiente:
a) El elemento menor del arreglo.
b) El total de elementos negativos de la fila 10 a la 13.
c) El mayor elemento del arreglo.

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 11/03/2020
*/

int main (){
	setlocale(LC_ALL,"");
	int i,j,negativos;
	double matriz[15][13],mayorE,menorE;
	
	printf ("Bienvenido, capturaremos datos de una matriz de 15x13 y se determinará lo siguiente: \n");
	printf ("1.-El menor elemento\n");
	printf ("2.-El mayor elemento\n");
	printf ("3.-El total de negativos de la fila 10 a la 13\n");
	printf ("Iniciando captura....\n\n");
	//Capturamos
	
	
	for (i=0;i<15;i++){
		for (j=0;j<13;j++){
			printf ("Ingrese el elemento (%d,%d): ", i+1,j+1);
			scanf ("%lf", &matriz[i][j]);
		}
	}
	
	/* Para comprobar
	srand (time(NULL));
	for (i=0;i<15;i++){
		for (j=0;j<13;j++){
			matriz[i][j] = -1000+rand()%(1001 - (-1000));
		}
	}
	*/
	
	//Determinamos 
	mayorE= -999999999;
	menorE= 999999999;
	negativos = 0;
	//---Mayor----
	for(i=0;i<15;i++){
		for (j=0;j<13;j++){
			if (matriz[i][j]>mayorE){
				mayorE= matriz[i][j];
			}
		}
	}
	//---Menor------
	for(i=0;i<15;i++){
		for (j=0;j<13;j++){
			if (matriz[i][j]<menorE){
				menorE= matriz[i][j];
			}
		}
	}
	//---Negativos---
	for (i=9;i<13;i++){
		for (j=0;j<13;j++){
			if (matriz[i][j]<0){
				negativos = negativos + 1;
			}
		}
	}

	
	//Imprimimos 
	system ("cls");
	printf ("La matriz es: \n");
	for (i=0;i<15;i++){
		for (j=0;j<13;j++){
			printf ("  %.1lf", matriz[i][j]);
		}
		printf ("\n");
	}
	
	printf ("\nEl mayor elemento del arreglo es: %.2lf\n", mayorE);
	printf ("El menor elemento del arreglo es: %.2lf\n", menorE);
	printf ("El total de negativos de la fila 10 a la 13 fue de: %d", negativos);
	
	getchar ();
	return 0;
}
