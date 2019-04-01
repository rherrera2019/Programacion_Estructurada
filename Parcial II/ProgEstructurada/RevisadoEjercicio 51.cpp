#include <stdio.h>

/*	Ejercicio: ADA 6, Ejercicio 51.
Descripción: E.P. que lea un vector de n elementos y que calcule e imprima susumatoria
Versión: 1.0
*/

int n,i=0;
float suma=0;

int main() {
	
	printf("Introduzca la cantidad de números a sumar: ");
	scanf("%i",&n);
	
	float v[n];
	
	do{
		
		printf("\nIntroduzca el %i° número. ",i+1);
		scanf("%f",&v[i]);
		
		i++;
		
	} while(i < n);
	
	i=0;
	
	do{
		
		suma+=v[i];
		
		i++;
		
	} while(i < n);
	
	printf("\nLa sumatoria de todos los números es: %.2f",suma);
	
	return 0;
}

/*El programa funciona correctamente, NO está documentado y le faltan datos a la cabecera

Revisado por: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

Fecha: 11/03/19 */

