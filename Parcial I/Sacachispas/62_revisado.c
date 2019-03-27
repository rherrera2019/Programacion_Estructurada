/* 62. E.P que lea una matriz de 5 X 5 elementos y que calcule e imprima
la suma de sus elementos que se encuentran en la diagonal principal.
Equipo: SacaChispas
Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé
Fecha: 11/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define X (i = 0; i < 5; i++)
#define Y (j = 0; j < 5; j++)

int main() {
	
	/*Declaramos las variables*/
	int i, j;
	
	/*Declaramos la matriz*/
	float matriz_numeros[5][5], sumatoria_diagonal = 0;
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for X
	{
		for Y
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte el número de la fila %i°, columna %i° ", i + 1, j + 1);
			scanf("%f", &matriz_numeros[i][j]);
			
			/*PROCESO para determinar la sumatoria de los elementos de la diagonal principal*/
			if (i == j)
			{
				sumatoria_diagonal += matriz_numeros[i][j];
			}
		}
	}
	
	/*SALIDA de datos*/
	printf("\n\nLa sumatoria de la diagonal principal es: %.2f", sumatoria_diagonal);
	
	getch();
	
	return 0;
}

/*Nada que agregar,comprimieron el codigo tanto como se podia,tiene variables representativas y funciona*/
//Josue Torres
