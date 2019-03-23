#include <stdio.h>
#include <conio.h>
/*
60. E.P. que lea una matriz de 20 X 30 elementos y que genere e
imprima un vector de 20 elementos que contenga la sumatoria de cada
fila de la matriz.
Elaboró:Los compiladores
Fecha:13/Marzo/2019
version 1.0

*/

int main() {
	//Variables
	int f=20;
	int c=30;
	float elementos[f][c];//matriz de los elementos a ingresar
	float suma[c];// vector para guardar la suma de las filas de la matriz
	float sum_matriz;//suma de las filas
	sum_matriz=0;
	
	//Entrada
	for(int i=1;i<=f;i++){//filas
		
		for(int j=1;j<=c;j++){//columnas
			printf("\n Ingrese el elemento (%d),(%d) de la matriz: ",i,j);
			scanf("%f",&elementos[i-1][j-1]);
			//Proceso
			sum_matriz+=elementos[i-1][j-1];
		}
		suma[i]=sum_matriz;
		sum_matriz=0;
		
	}
	//Salida
	printf("\n***Resultados***");
	int x;
	for(x=1;x<=f;x++){
		printf("\n Sumatoria de fila %d: %.2f",x,suma[x]);
		
		
	}
	
	
	
	return 0;
}

/*Revisión por Programadores Empedernidos.

-El código funciona bien.
-Se cumple lo que se pide.
-El nombre de las variables es representativo.*/
