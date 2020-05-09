#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*
Nombre del Programa: Ejercicio 65 - Igualdad de diagonales

Descripción: E.P. que lea dos matrices de M X N elementos y que determine e
imprima si la diagonal principal de la primera es igual a la diagonal
principal de la segunda.

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 11/03/2020
*/

int main (){
	setlocale (LC_ALL,"");
	int i,j,n,m,igualdad;
	
	printf ("Este programa determina si la diagonal principal de ambas matrices son iguales\n" );
	printf ("\nIngrese las FILAS de ambas matrices: ");
	scanf ("%d",&n);
	printf ("Ingrese las COLUMNAS de ambas matrices: ");
	scanf ("%d", &m);
	
	double matrizA[n][m], matrizB[n][m];
	//Capturamos
	printf ("\nIngrese los datos de la matriz A: \n\n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf ("Ingrese el elemento (%d,%d): ",i+1,j+1);
			scanf ("%lf", &matrizA[i][j]);
		}
	}
	
	printf ("\nAhora ingrese los datos de la matriz B: \n\n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf ("Ingrese el elemento (%d,%d): ",i+1,j+1);
			scanf ("%lf", &matrizB[i][j]);
		}
	}
	
	//Imprimimos previamente
	system ("cls");
	printf ("La matriz A es: \n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf ("  %.2lf",matrizA[i][j]);
		}
		printf ("\n");
	}
	
	printf ("\nLa matriz B es: \n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf ("  %.2lf",matrizB[i][j]);
		}
		printf ("\n");
	}
	
	//Determinamos la igualdad
	printf ("\n");
	igualdad = 0;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if (i==j){
				if (matrizA[i][j] != matrizB[i][j]){
					printf ("La diagonal es diferente en la posición (%d,%d): ",i+1,j+1);
					igualdad = igualdad + 1;
				}
			}
		}
		printf ("\n");
	}
	
	if (igualdad>0){
		printf ("\nEn conclusión las diagonales NO SON IGUALES");
	}else{
		printf ("\nLas diagonales SON IGUALES");
	}
	
	
	
	getchar ();
	return 0;
}
