/* 55. E.P. que lea un vector de n elementos, el cual se sabe tiene un
elemento negativo y que determine e imprima su posición.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 1/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define X (contador = 0; contador < longitud_vector; contador++)

int main() {
	
	/*Declaramos las variables*/
	int contador, longitud_vector, posicion_negativo;
	
	posicion_negativo = 0;
	
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
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for X
	{
		/*ENTRADA de datos*/
		printf("\n\nInserte el %i° número ", contador + 1);
		scanf("%f", &vector_numeros[contador]);
		
		/*PROCESO para saber el número negativo*/
		if (vector_numeros[contador] < 0)
		{
			posicion_negativo = contador + 1;
			
		}
	}
	
	/*SALIDA de datos*/
	printf("\n\nLa posición del negativo es: %i", posicion_negativo);
	
	getch();
	
	return 0;
}
/* El programa funciona correctamente
-Identifica corractamente al elemento negativo
-El ciclo para que esta definido con el "define" funciona correctamente.
-valida correctamente la cantidad de elementos, excepto cuando se ingresa un decimal.
Revisó: (PuntoC)*/
