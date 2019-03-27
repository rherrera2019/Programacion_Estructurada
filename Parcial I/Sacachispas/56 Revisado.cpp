/* 56. E.P. que lea una matriz de 3 X 3 elementos y los imprima.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 11/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Declaramos las variables*/
	int i, j;
	
	/*Declaramos la matriz*/
	float matriz_numeros[3][3];
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte el número de la fila %i°, columna %i° ", i + 1, j + 1);
			scanf("%f", &matriz_numeros[i][j]);
		}
	}
	
	/*SALIDA de datos*/
	printf("\n\nLa matriz es:\n\n");
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("[%.2f] ", matriz_numeros[i][j]);
		}
		
		printf("\n");
	}
	
	getch();
	
	return 0;
}

//Funciona bien
//Revisado por: Abigael Arjona

