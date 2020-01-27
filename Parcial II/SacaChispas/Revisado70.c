/* 70. E.P. que reserve memoria para un arreglo de 10 elementos de tipo
float, rellenarlo con datos que digite el usuario, luego utilizar realloc
para ampliar dicho arreglo a 20 elementos e imprimir el arreglo
resultante.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 20/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define LONGITUD 10

int main() 
{
	/*Declaramos el vector*/
	float *vector;
	
	/*Reservar memoria para el vector*/
	vector = malloc(LONGITUD * sizeof(float));
	
	/*ENTRADA de datos*/
	printf("\nInserte los 10 elementos");
	for(int i = 0; i < LONGITUD; i++)
	{
		printf("\n\nElemento N° %i ", i + 1);
		scanf("%f", &vector[i]);
	}
	
	/*Expandir a 20 elementos*/
	vector = realloc(vector, LONGITUD * sizeof(float));
	
	system("cls");
	
	printf("\nSe han añadido espacio para 10 elementos más, insértelos");
	for(int i = LONGITUD; i < LONGITUD * 2; i++)
	{
		printf("\n\nElemento N° %i ", i + 1);
		scanf("%f", &vector[i]);
	}
	
	
	/*SALIDA de datos*/
	printf("\n\nArreglo resultante\n\n");
	for(int i = 0; i < LONGITUD * 2; i++)
	{
		printf("[%.2f] ", vector[i]);
	}
	
	getch();
	
	return 0;
}

/*El programa funciona correctamente, exepto que el vector debe ser para 10 elementos 
Buen uso de los comentarios, el código es sencillo y entendible. 

Revisó: Abigael Arjona

Equipo: Programción estructurada

*/
