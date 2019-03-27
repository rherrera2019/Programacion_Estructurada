/* 64. E.P. que lea una matriz de 15 X 13 elementos y que calcule e
imprima lo siguiente:
a) El elemento menor del arreglo.
b) El total de elementos negativos de la fila 10 a la 13.
c) El mayor elemento del arreglo.
Equipo: SacaChispas
Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé
Fecha: 11/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define FILAS 15
#define COLUMNAS 13

int main() {
	
	/*Declaramos las variables*/
	int i, j, cont_negativos = 0;
	
	/*Declaramos la matriz*/
	float matriz_numeros[FILAS][COLUMNAS], numero_menor, numero_mayor; //numero mayor y menor deberian ser inicialiazados en 0 aquí
	
	//El programa no funciona, no imprime bien lo que tiene
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for (i = 0; i < FILAS; i++)
	{
		for (j = 0; j < COLUMNAS; j++)
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte el número de la fila %i°, columna %i° ", i + 1, j + 1);
			scanf("%f", &matriz_numeros[i][j]);
			
			numero_mayor = matriz_numeros[0][0]; // cada ves que vuelva a empezar el ciclo reinicia el valor aquí
			
			numero_menor = matriz_numeros[0][0]; // lo mismo aquí
			
			/*PROCESO para determinar el número mayor*/
			if (matriz_numeros[i][j] > numero_mayor)
			{
				numero_mayor = matriz_numeros[i][j];
				
			} 
			
			/*PROCESO para determinar el número menor*/
			if (matriz_numeros[i][j] < numero_menor)
			{
				numero_menor = matriz_numeros[i][j];
				
			}
			
			/*PROCESO para determinar los negativos*/
			if ((i >= 9 && i <= 12) && matriz_numeros[i][j] < 0)
			{
				cont_negativos++;
			}
		}
	}
	
	/*SALIDA de datos*/
	printf("\n\nEl número mayor es: %.2f\n\nEl número menor es: %.2f", numero_mayor, numero_menor); //numeros incorrectis
	printf("\n\nEl total de elementos negativos entre la fila 10 y 13 son: %i", cont_negativos);
	
	getch();
	
	return 0;
}
