#include <stdio.h>
#include <locale.h>
/*
Nombre del Programa: Matriz de NxM
Descripción:  E.P. que lea una matríz de n x m elementos que contenga números reales, determine su matriz transpuesta e imprima ambas, en formato de matriz (filas/columnas). 
De tal forma, la traspuesta de una matriz de orden m x n es una matriz de orden n x m, que se obtiene intercambiando filas por columnas; 
es decir, el elemento A(i,j) se coloca en B(j,i).

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 09/03/2020
*/

int main (){
	setlocale (LC_ALL,"");
	int i,j,filas,columnas;
	
	printf ("Bienvenido, este programa recibe datos reales en una matriz de NxM e imprime la transpuesta.\n");
	printf ("Primero definamos el tamaño de la misma: \n");
	
	//------------------Calculamos las filas ----------------
	printf ("\nIngrese el total de filas: ");
	scanf ("%d", &filas);
	//-----------------Calculamos las columnas-------------------
	printf ("Ingrese el total de columnas: ");
	scanf ("%d", &columnas);
	//------------Determinamos el tamaño de la matriz-------------
	double matriz[filas][columnas];
	//-----------------Capturamos los datos---------------------
	for (i=0;i<filas;i++){
		for (j=0;j<columnas;j++){
			printf ("Ingrese el elemento (%d,%d): ",i+1,j+1);
			scanf ("%lf", &matriz[i][j]);
		}
	}
	//-------------------Imprimimos la matriz---------------------
	printf ("\nLa matriz es: \n");
	for (i=0;i<filas;i++){
		for (j=0;j<columnas;j++){
			printf (" %.2lf ",matriz[i][j]);
		}
		printf ("\n");
	}
	//---------Imprimimos la transpuesta de la matriz---------------
	printf ("\n\nAhora , la transpuesta de la matriz es: \n");
	for (i=0;i<columnas;i++){
		for (j=0;j<filas;j++){
			printf (" %.2lf ",matriz[j][i]);
		}
		printf ("\n");
	}

	getchar ();
	return 0;	
}
