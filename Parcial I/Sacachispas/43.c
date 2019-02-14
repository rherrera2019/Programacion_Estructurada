/* 43.- E.P. que lea 250 números y que determine e imprima cuántos
son positivos y cuántos son negativos

Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé
Fecha: 7/feb/2019
Version: 1.0 */

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Creamos las variables necesarias para el programa*/
	int cont_numeros, cont_positivos, cont_negativos;
	
	float numero_actual;
	
	/*Inicializamos el contador para los números*/
	cont_numeros = 1;
	cont_positivos = 0;
	cont_negativos = 0;
	
	/*Creamos el ciclo do-while para la lectura de los 100 números*/
	do
	{
		/*ENTRADA DE DATOS*/
		printf("\n\nInserte el %i° número ", cont_numeros++);
		scanf("%f", &numero_actual);
		
		/*PROCESO para determinar si el número insertado es positivo o negativo*/
		if (numero_actual > 0)
		{
			cont_positivos++;
			
		} else if (numero_actual < 0)
		{
			cont_negativos++;
		}
		
	} while (cont_numeros <= 250);
	
	/*SALIDA DE DATOS*/
	/*Mostramos los números positivos*/
	printf("\n\nEl número total de positivos es: %i", cont_positivos);
	
	/*Mostramos los números negativos*/
	printf("\n\nEl número total de negativos es: %i", cont_negativos);
	
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}
/*
Revisado por: Los compiladores

El programa termina cuando se ingresa un número con punto decimal.
El codigo es entendible.

*/
