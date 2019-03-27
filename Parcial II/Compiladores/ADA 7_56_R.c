#include <stdio.h>
/*
50.E.P que lea una matriz de 3 por 3 elementos y los imprima
Elaboró: Los compiladores
Ciclo utilizado: For
Fecha:13/Marzo/2019
Version 1.0

*/

int main() {
	/*VARIABLES*/
	int Matriz[3][3];//matriz para guardar los elementos a ingresar
	int fila;
	int columna;
	
	/*DATOS ENTRADA*/
	for(fila=1;fila<=3;fila++){ //filas de la matriz
		for(columna=1;columna<=3;columna++){//columnas de la matriz
			printf("Ingrese el valor de la posicion (%d,%d): ",fila,columna);
			scanf("%d",&Matriz[fila-1][columna-1]);;
		}
		
	}
	/*DATOS SALIDA*/
	int i,j;
	printf("\n Matriz ");
	printf("\n\n ");
	for(i=1;i<=3;i++){//filas de la matriz
		
		for(j=1;j<=3;j++){ //columnas de la matriz
			printf(" %d   ",Matriz[i-1][j-1]);
			
		}
		
		printf("\n ");
	}
	return 0;
}
/*Revisión por Programadores Empedernidos.

-El código funciona bien.
-Se cumple lo que se pide.
-El nombre de las variables es representativo.*/
