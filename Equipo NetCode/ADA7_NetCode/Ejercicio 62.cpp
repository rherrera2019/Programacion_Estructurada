#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
/*
Nombre del Programa: Ejercicio 62 - Diagonal principal 

Descripción: E.P que lea una matriz de 5 X 5 elementos y que calcule e imprima
la suma de sus elementos que se encuentran en la diagonal principal.


Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 11/03/2020
*/

int main (){
	setlocale (LC_ALL,"");
	int i,j;
	double matriz[5][5],traza; //Proporcionado por el problema
	
	printf ("Este programa calcula la traza de una matriz de 5x5\n");
	printf ("Por ahora le pedimos que rellene los datos de la matriz...\n\n");
	//Capturamos 
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
		printf ("Ingrese el elemento (%d,%d): ", i+1,j+1);
		scanf ("%lf", &matriz[i][j]);		
		}
	}
	//Determinamos la traza
	traza = 0;
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			if (i==j){
				traza = traza + matriz[i][j];
			}
		}
	}
	//Imprimimos los datos 
	system ("cls");
	printf ("La matriz es: \n");
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			printf ("  %.2lf", matriz[i][j]);
		}
		printf ("\n");
	} 
	
	printf ("\nLa suma de la diagonal de la matriz es: %.2lf", traza);
	
	getchar ();
	return 0;
}
