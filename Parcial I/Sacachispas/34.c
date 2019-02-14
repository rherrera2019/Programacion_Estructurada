/* 34 E.P. que lea 100 números (N) y que los imprima
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
	int cont_numeros;
	float numero_actual;
	
	/*Inicializamos el contador para los números*/
	cont_numeros = 1;
	
	/*PROCESO*/
	/*Creamos el ciclo while para la lectura de los 100 números*/
	while (cont_numeros <= 100)
	{
		/*ENTRADA DE DATOS*/
		printf("\n\nInserte el %i° número ", cont_numeros++);
		scanf("%f", &numero_actual);
		
		/*SALIDA DE DATOS*/
		printf("\n\nEl número que insertó es: %.2f", numero_actual);
	}
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}
/*Revisado por: Compiladores_ Jafet Fernandez
Al usar un floatante se atora y falla
En general bien*/

