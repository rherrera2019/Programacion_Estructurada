/* 66. E.P. que lea una matriz de 9 X 12 elementos y que cuente todos
los elementos negativos de la misma y los cambie por ceros.
Equipo: SacaChispas
Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé
Fecha: 11/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define FILAS 9
#define COLUMNAS 12

int main() {
	
	/*Declaramos las variables*/
	int i, j;
	
	/*Declaramos la matriz*/
	float matriz_numeros[FILAS][COLUMNAS];
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for (i = 0; i < FILAS; i++)
	{
		for (j = 0; j < COLUMNAS; j++)
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte el número de la fila %i°, columna %i° ", i + 1, j + 1);
			scanf("%f", &matriz_numeros[i][j]);
			
			/*PROCESO para cambiar los negativos por ceros*/
			if (matriz_numeros[i][j] < 0)
			{
				matriz_numeros[i][j] = 0;
			}
			
		}
	}
	
	
	//Me hubiera gustado ver la matriz original impresa pero se ahorro unos ciclos for 
	
	
	/*SALIDA de datos*/
	printf("\n\nLa matriz modificada es:\n\n");
	
	for (i = 0; i < FILAS; i++)
	{
		for (j = 0; j < COLUMNAS; j++)
		{
			printf("[%.2f] ", matriz_numeros[i][j]);
			
		}
		
		printf("\n");
	}
	
	getch();
	
	//comentario sobre los comentarios de documentacion no es mas facil ussar dos diagonales si solo se va a usar una linea
	
	return 0;
}
//revisó Daniel encalada
