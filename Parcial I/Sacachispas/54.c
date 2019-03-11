/* 54. E.P. que lea dos vectores de n elementos y que genere e imprima
un tercer vector con la suma de cada uno de los elementos de los dos
anteriores.
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
	int contador, longitud_vector;
	
	/*Pedimos las longitud de los 2 vectores*/
	printf("\n¿Cuántos números insertará para los 2 vectores? ");
	
	/*Validamos dicha longitud con un Do-While*/
	do
	{
		scanf("%i", &longitud_vector);
		
		if (longitud_vector <= 0)
		{
			printf("\n\nInsertó una cantidad NO válida, inténtelo de nuevo\n\nCantidad de números ");
		}
		
	} while(longitud_vector <= 0);
	
	/*Declaramos los 3 vectores*/
	float vector_numeros1[longitud_vector], vector_numeros2[longitud_vector], vector_resultante[longitud_vector];
	
	/*Creamos un ciclo For para la lectura del vector 1*/
	for X
	{
		/*ENTRADA de datos*/
		printf("\n\nInserte el %i° número del vector 1 ", contador + 1);
		scanf("%f", &vector_numeros1[contador]);
	}
	
	/*Creamos un segundo ciclo For para la lectura del vector 2*/
	for X
	{
		/*ENTRADA de datos*/
		printf("\n\nInserte el %i° número del vector 2 ", contador + 1);
		scanf("%f", &vector_numeros2[contador]);
		
		/*PROCESO para calcular el vector resultante*/
		vector_resultante[contador] = vector_numeros1[contador] + vector_numeros2[contador];
	}
	
	/*SALIDA de datos*/
	printf("\n\nEl vector resultante es:\n\n");
	
	/*Ciclo For para mostrar el vector resultante*/
	for X
	{
		printf("[%.2f] ", vector_resultante[contador]);
		
	}
	
	getch();
	
	return 0;
}
/* El programa funciona correctamente
-Lee los vectores y genera bien el tercero con la suma, pero sería mejor si lo imprimiera
en una sola columna.Sobre todo porque puede comfundir un poco ya que imprime el tercer
vector con los ceros, haciendolo parecer más una coordenada.
-El ciclo para que esta definido con el "define" funciona correctamente.
-valida correctamente la cantidad de elementos, excepto cuando se ingresa un decimal.
Revisó: (PuntoC)*/
