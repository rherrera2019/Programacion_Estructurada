/* 60. E.P. que lea una matriz de 20 X 30 elementos y que genere e
imprima un vector de 20 elementos que contenga la sumatoria de cada
fila de la matriz.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 11/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define FILAS 20
#define COLUMNAS 30

int main() {
	
	/*Declaramos las variables*/
	int i, j, a = 0;
	
	/*Declaramos el vector y la matriz*/
	float matriz_numeros[FILAS][COLUMNAS], vector_sumas[FILAS];
	
	/*Inicializamos el vector de las sumas*/
	for (i = 0; i < FILAS; i++)
	{
		vector_sumas[i] = 0;
	}
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for (i = 0; i < FILAS; i++)
	{
		for (j = 0; j < COLUMNAS; j++)
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte el número de la fila %i°, columna %i° ", i + 1, j + 1);
			scanf("%f", &matriz_numeros[i][j]);
			
			/*PROCESO para determinar la sumatoria de los elementos de la fila*/
			vector_sumas[a] += matriz_numeros[i][j];
		}
		
		a++;
	}
	
	/*SALIDA de datos*/
	printf("\n\nEl vector con las sumas es:\n\n");
	
	for (i = 0; i < FILAS; i++)
	{
		printf("%i.-[%.2f]\n", i + 1, vector_sumas[i]);
		
	}
	
	getch();
	
	return 0;
}

//Funciona bien
//Revisado por: Abigael Arjona
