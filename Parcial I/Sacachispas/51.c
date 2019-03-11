/* 51. E.P. que lea un vector de n elementos y que calcule e imprima su
sumatoria.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 1/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define X (contador < longitud_vector)

int main() {
	
	/*Declaramos las variables*/
	int contador, longitud_vector;
	
	float sumatoria;
	
	sumatoria = 0;
	contador = 0;
	
	/*Pedimos la longitud del vector*/
	printf("\n¿Cuántos números insertará? ");
	
	/*Validamos dicha longitud con un Do-While*/
	do
	{
		scanf("%i", &longitud_vector);
		
		if (longitud_vector <= 0)
		{
			printf("\n\nInsertó una cantidad NO válida, inténtelo de nuevo\n\nCantidad de números ");
		}
		
	} while(longitud_vector <= 0);
	
	/*Declaramos el vector*/
	float vector_numeros[longitud_vector];
	
	/*Creamos un ciclo While para la lectura de los datos*/
	while X
	{
		/*ENTRADA de datos*/
		printf("\n\nInserte el %i° número ", contador + 1);
		scanf("%f", &vector_numeros[contador]);
		
		/*PROCESO*/
		sumatoria += vector_numeros[contador];
		
		contador++;
		
	}
	
	/*SALIDA de datos*/
	printf("\n\nLa sumatoria de los números es: %.2f", sumatoria);
	
	getch();
	
	return 0;
}

/* El programa funciona correctamente
El programa lee correctamente, calcula correctamente con negativos y decimales.
valida correctamente la cantidad de elementos, excepto cuando se ingresa un decimal.
Revisó: (PuntoC)*/ 
