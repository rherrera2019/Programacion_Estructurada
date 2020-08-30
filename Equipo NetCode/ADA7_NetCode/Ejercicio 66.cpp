#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

/*
Nombre del Programa: Ejercicio 66 - Matriz 9x12

Descripción: E.P. que lea una matriz de 9 X 12 elementos y que cuente todos
los elementos negativos de la misma y los cambie por ceros.

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 11/03/2020
*/

int main (){
	setlocale (LC_ALL,"");
	
	int i,j,negativos;
	double array[9][12];
	
	printf ("Este programa cambia los negativos por ´0´ en una matriz de 9x12\n\n");
	//Capturamos 
	
	for (i=0;i<9;i++){
		for (j=0;j<12;j++){
			printf ("Ingrese los datos del elemento (%d,%d): ", i+1,j+1);
			scanf ("%lf", &array[i][j]);
		}
	}
	
	//Para comprobar
	/*
	srand (time(NULL));
	for (i=0;i<9;i++){
		for (j=0;j<12;j++){
			array[i][j] = -60+rand()%(61 - (-60));
		}
	}
	*/
	//Imprimimos la original
	system ("cls");
	printf ("La matriz original es: \n");
	for (i=0;i<9;i++){
		for (j=0;j<12;j++){
			printf ("  %.2lf", array[i][j]);
		}
		printf ("\n");
	}
	//Cambiamos los negativos
	negativos= 0;
	for (i=0;i<9;i++){
		for (j=0;j<12;j++){
			if (array[i][j]<0){
				negativos = negativos + 1;
				array[i][j] = 0;
			}
		}
	}
	//Imprimimos la nueva matriz
	printf ("\nLa nueva matriz es: \n");
	for (i=0;i<9;i++){
		for (j=0;j<12;j++){
			printf ("  %.2lf", array[i][j]);
		}
		printf ("\n");
	}
	
	printf ("\nEl total de negativos fue de: %d", negativos);
	
	
	
	getchar ();
	return 0;
}
