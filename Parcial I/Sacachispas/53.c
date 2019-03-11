/* 53. E.P. que lea un vector de n elementos y que determine el elemento
mayor del arreglo y su posición.
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
	int contador, longitud_vector, posicion_mayor;
	
	float elemento_mayor;
	
	/*Inicilizamos las variables*/
	elemento_mayor = 0;
	posicion_mayor = 0;
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
		
		/*El elemento mayor es el primer elemento del vector*/
		if (contador == 0)
		{
			elemento_mayor = vector_numeros[0];
		}
		
		/*PROCESO*/
		/*Buscamos el trono de los elementos del vector*/
		if (vector_numeros[contador] >= elemento_mayor)
		{
			/*Guardamos el elemento mayor*/
			elemento_mayor = vector_numeros[contador];
			
			/*Guardamos la posición*/
			posicion_mayor = contador + 1;
		}
		
		contador++;
		
	} while X
	
	/*SALIDA de datos*/
	printf("\n\nEl número mayor del arreglo es: %.2f\n\nSu posición es: %i", elemento_mayor, posicion_mayor);
	
	getch();
	
	return 0;
}
/* El programa funciona correctamente
No detecta cuando hay 2 numeros mayores a los demas y que son iguales
valida correctamente la cantidad de elementos, excepto cuando se ingresa un decimal.
Revisó: (PuntoC)*/
