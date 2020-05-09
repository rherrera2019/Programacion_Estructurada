#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
/*
Nombre del Programa: Ejercicio 63 - La matriz de 20x20 

Descripción: . E.P. que lea una matriz de 20 X 20 elementos y que cuente e
imprima cuantos elementos igual a cero se encuentran en las primeras
10 filas.


Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 11/03/2020
*/

int main (){
	setlocale (LC_ALL, "");
	int i,j,ceros;
	double matriz[20][20]; //Proporcionado por el problema
	
	printf ("Este programa cuenta el total de ´0´ en las primeras 10 filas de una matriz de 20x20\n");
	printf ("Iniciando captura...\n");
	//Capturamos datos
	for (i=0;i<20;i++){
		for (j=0;j<20;j++){
			printf ("Ingrese el elemento (%d,%d): ",i+1,j+1);
			scanf ("%lf",&matriz[i][j]);
		}
	}
	//Determinamos el total de ceros
	ceros = 0;
	for (i=0;i<20;i++){
		for (j=0;j<20;j++){
			if (matriz[i][j]==0){
				ceros = ceros + 1;
			}
		}
	}
	//Imprimimos
	printf ("\nLa matriz es: \n");
	for (i=0;i<20;i++){
		for (j=0;j<20;j++){
			printf ("  %.2lf", matriz[i][j]);
		}
		printf ("\n");
	}
	
	printf ("\nEl total de ´0´ en las primeras 10 filas es: %d", ceros);
	
	getchar ();
	return 0;
}
