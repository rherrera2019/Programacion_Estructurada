/* 36. E.P. que lea 50 números y que cuente e imprima cuantos son
negativos.
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
	int cont_numeros, cont_negativos;
	float numero_actual;
	
	/*Inicializamos el contador para los números*/
	cont_numeros = 1;
	cont_negativos = 0;
	
	/*Creamos el ciclo while para la lectura de los 25 números*/
	while (cont_numeros <= 10)
	{
		/*ENTRADA DE DATOS*/
		printf("\n\nInserte el %i° número ", cont_numeros++);
		scanf("%f", &numero_actual);
		
		/*PROCESO para determinar si el número insertado es negativo*/
		if (numero_actual < 0)
		{
			printf("\n\nEste número es negativo");
			
			cont_negativos++;
		}
	}
	
	/*SALIDA DE DATOS*/
	printf("\n\nEl número total de negaivos es: %i", cont_negativos);
	
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}
/*Revisado por: Compiladores_ Jafet Fernandez
Al usar un floatante se atora y falla
En general bien*/

