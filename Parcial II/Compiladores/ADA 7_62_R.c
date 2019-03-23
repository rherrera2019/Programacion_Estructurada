#include <stdio.h>
/*
62. E.P que lea una matriz de 5 X 5 elementos y que calcule e imprima
la suma de sus elementos que se encuentran en la diagonal principal.
Elaboró:Los compiladores
Fecha:13/Marzo/2019
Version 1.0

*/
int main() {
	//Variables
	float elementos[5][5];//matriz para guardar los elementos a ingresar
	float sum_elemDiagonal;//guarda la sumatoria de los elementos que esten en la diagonal principal
	sum_elemDiagonal=0;//inicializamos el sumador en 0
	
	//Entrada
	int i,j;
	for(i=1;i<=5;i++){//filas de la matriz
		
		for(j=1;j<=5;j++){//columnas de la matriz
			printf("\n ingrese el valor del elemento %d en la posicion (%d),(%d)",i,i,j);
			scanf("%f",&elementos[i-1][j-1]);
			//Proceso
			if(i==j){//si se cumple, indica que el elemento esta en la diagonal principal,de ser asi, se suma el elemento ingresado en la variable sum_elemDiagonal
				sum_elemDiagonal+=elementos[i-1][j-1];
			}
			
		}
		
	}
	//Salida
	printf("\n Suma de la diagonal principal: %.2f ",sum_elemDiagonal);//imprimos la variable sum_elemDiagonal
	
	
	return 0;
}
/*Revisión por Programadores Empedernidos.

-El código funciona bien.
-Se cumple lo que se pide.
-El nombre de las variables es representativo.*/
