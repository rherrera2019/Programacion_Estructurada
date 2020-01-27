/* 71. E.P. que utilice un apuntador de arreglo con datos de tipo float,
pedir el usuario el número de elementos, luego reservar memoria
dinámica con calloc, leer dicho arreglo y posteriormente, imprimir
todos sus elementos; por ultimo, liberar el espacio de memoria
dinámica utilizado.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 20/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() 
{
	/*Declaramos el vector*/
	int n_elementos;
	float *vector;
	
	/*Número de elementos*/
	printf("\nInserte el número de elementos ");
	scanf("%i", &n_elementos);
	
	/*Reservar memoria para el vector*/
	vector = calloc(n_elementos, sizeof(float));
	
	/*ENTRADA de datos*/
	for(int i = 0; i < n_elementos; i++)
	{
		printf("\n\nElemento N° %i ", i + 1);
		scanf("%f", &vector[i]);
	}
	
	system("cls");
	
	/*SALIDA de datos*/
	printf("\n\nLos elementos son\n\n");
	for(int i = 0; i < n_elementos; i++)
	{
		printf("[%.2f] ", vector[i]);
	}
	
	/*Liberar memoria*/
	free(vector);
	
	getch();
	
	return 0;
}

/*El programa funciona correctamente, cumple con lo que pedía el ejercicio propuesto
Buen uso de los comentarios, el código es sencillo y entendible. 

Revisó: Abigael Arjona

Equipo: Programción estructurada

*/
