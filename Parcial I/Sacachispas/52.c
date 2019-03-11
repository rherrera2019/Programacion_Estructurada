/* 52. E.P. que lea un vector de n elementos y que calcule e imprima el
producto de sus elementos.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 1/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define X (contador < longitud_vector);

int main() {
	
	/*Declaramos las variables*/
	int contador, longitud_vector;
	
	float producto_elementos;
	
	producto_elementos = 1;
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
	
	/*Creamos un ciclo Do-While para la lectura de los datos*/
	do
	{
		/*ENTRADA de datos*/
		printf("\n\nInserte el %i° número ", contador + 1);
		scanf("%f", &vector_numeros[contador]);
		
		/*PROCESO*/
		producto_elementos *= vector_numeros[contador];
		
		contador++;
		
	} while X
	
	/*SALIDA de datos*/
	printf("\n\nEl producto de los números es: %.2f", producto_elementos);
	
	getch();
	
	return 0;
}
/* El programa funciona correctamente
El programa lee y opera bien los elementos dados.
valida correctamente la cantidad de elementos, excepto cuando se ingresa un decimal.
Revisó: (PuntoC)*/
