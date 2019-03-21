/* 63. E.P. que lea una matriz de 20 X 20 elementos y que cuente e
imprima cuantos elementos igual a cero se encuentran en las primeras
10 filas.
Equipo: SacaChispas
Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé
Fecha: 11/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define LONGITUD 20

int main() {
	
	/*Declaramos las variables*/
	int i, j, cont_ceros = 0;
	
	/*Declaramos la matriz*/
	float matriz_numeros[LONGITUD][LONGITUD];
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for (i = 0; i < LONGITUD; i++)
	{
		for (j = 0; j < LONGITUD; j++)
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte el número de la fila %i°, columna %i° ", i + 1, j + 1);
			scanf("%f", &matriz_numeros[i][j]);
			
			/*PROCESO para determinar la cantidad de ceros en las primeras 10 filas*/
			if (i < 10 && matriz_numeros[i][j] == 0)
			{
				cont_ceros++;
			}
		}
	}
	
	/*SALIDA de datos*/
	printf("\n\nLa cantidad de ceros en las primeras 10 filas es: %i", cont_ceros);
	
	getch();
	
	return 0;
}
