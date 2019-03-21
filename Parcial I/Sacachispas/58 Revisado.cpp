/* 58. E.P. que lea una matriz de 6 X 4 elementos y que calcule e
imprima la suma de sus elementos.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 11/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define X (i = 0; i < 6; i++)
#define Y (j = 0; j < 4; j++)

int main() {
	
	/*Declaramos las variables*/
	int i, j;
	
	float sumatoria = 0;
	
	/*Declaramos la matriz*/
	float matriz_numeros[6][4];
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for X
	{
		for Y
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte el número de la fila %i°, columna %i° ", i + 1, j + 1);
			scanf("%f", &matriz_numeros[i][j]);
			
			/*PROCESO para determinar la sumatoria de los elementos de la matriz*/
			sumatoria += matriz_numeros[i][j];
			
		}
	}
	
	/*SALIDA de datos*/
	printf("\n\nLa sumatoria es: %.2f", sumatoria);
	
	getch();
	
	return 0;
}

//El programa funciona bien
//Revisado por: Abigael Arjona
