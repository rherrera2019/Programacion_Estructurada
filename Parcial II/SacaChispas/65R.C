/* 65. E.P. que lea dos matrices de M X N elementos y que determine e
imprima si la diagonal principal de la primera es igual a la diagonal
principal de la segunda.
Equipo: SacaChispas
Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé
Fecha: 11/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define X (i = 0; i < filas; i++)
#define Y (j = 0; j < columnas; j++)

int main() {
	
	/*Declaramos las variables*/
	int filas, i, columnas, j, cont_diagonal = 0;
	
	printf ("\nInserte las filas ");
	
	/*Validamos dicha longitud con un Do-While*/
	do
	{
		scanf ("%i", &filas);
		
		if (filas <= 0)
		{
			printf("\n\nInsertó una cantidad NO válida, inténtelo de nuevo\n\nFilas ");
		}
		
	} while (filas <= 0);
	
	printf ("\nInserte las columnas ");
	
	/*Validamos dicha longitud con un Do-While*/
	do
	{
		scanf ("%i", &columnas);
		
		if (columnas <= 0)
		{
			printf("\n\nInsertó una cantidad NO válida, inténtelo de nuevo\n\nColumnas ");
		}
		
	} while (columnas <= 0);
	
	/*Declaramos las matrices*/
	float matriz_numeros1[filas][columnas], matriz_numeros2[filas][columnas];
	
	/*Creamos un ciclo For para la lectura de la primera matriz*/
	for X
	{
		for Y
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte el número de la fila %i°, columna %i° de la 1° matriz ", i + 1, j + 1);
			scanf("%f", &matriz_numeros1[i][j]);
			
		}
	}
	
	
	//lo ideal seria imprimir la matriz para poder verla y tner esa ayuda de comparacion visual
	
	printf("\n\n**************************************************************");
	
	/*Creamos un ciclo For para la lectura de la segunda matriz*/
	for X
	{
		for Y
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte el número de la fila %i°, columna %i° de la 2° matriz ", i + 1, j + 1);
			scanf("%f", &matriz_numeros2[i][j]);
			
			/*PROCESO para determinar si las diagonales son iguales*/
			if (i == j && matriz_numeros1[i][j] == matriz_numeros2[i][j])
			{
				cont_diagonal++;
			}
			
		}
	}
	
	/*SALIDA de datos*/
	if (cont_diagonal == filas)
	{
		printf("\n\nLas diagonales principales tienen los mismos elementos");
		
	} else 
	{
		printf("\n\nLas diagonales principales NO tienen los mismos elementos");
	}
	//pudo comparar ambas matrices en un for en lugar de usar ese contador
	getch();
	
	return 0;
}
