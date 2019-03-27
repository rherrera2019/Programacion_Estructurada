#include <stdio.h>

	/*
	58.E.P que lea una matriz de 6 X 4 elementos y que calcule e
	imprima la suma de sus elementos
	Ciclo utilizado: For
	Fecha:13/Marzo/2019
	Version 1.0
	
	*/
int main() {

	/*VARIABLES*/
	
	int fila,columna;
	float Matriz[6][4]; //matriz para guardar los elementos a ingresar
	float sum_matriz; //sumador del valor de los elementos

	/*DATOS ENTRADA*/
	for(fila=1;fila<=6;fila++){ //filas de la matriz
		for(columna=1;columna<=4;columna++){ //columnas de la matriz
			printf("Ingrese el valor de la posicion (%d,%d)",fila,columna);
			scanf("%f",&Matriz[fila][columna]);
		}
		
	}
	
	/*Proceso para hacer la suma de los elementos*/
	for(fila=1;fila<=6;fila++){
		for(columna=1;columna<=4;columna++){ 
			sum_matriz=sum_matriz+Matriz[fila][columna]; //sumamos todos los valores
		}
		
	}

	/*DATOS SALIDA*/
	printf("La suma de los valores de la matriz es de %.2f",sum_matriz);
	
	return 0;
}

/*Revisión por Programadores Empedernidos.

-El código falla con valores negativos.
-Se cumple lo que se pide.
-El nombre de las variables es representativo.*/

