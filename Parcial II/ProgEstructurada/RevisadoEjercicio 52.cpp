#include <stdio.h>

/*	Ejercicio: ADA 6, Ejercicio 52.
Descripción: E.P. que lea un vector de n elementos y que calcule e imprima el producto de sus elementos.
Versión: 1.0
*/

int n,i=0;
float prod=1;

int main() {
	
	printf("Introduzca la cantidad de números a multiplicar: ");
	scanf("%i",&n);
	
	float v[n];
	
	do{
		
		printf("\nIntroduzca el %i° número. ",i+1);
		scanf("%f",&v[i]);
		
		i++;
		
	} while(i < n);
	
	i=0;
	
	do{
		
		prod*=v[i];
		
		i++;
		
	} while(i < n);
	
	printf("\nEl producto de todos los números es: %.2f",prod);
	
	return 0;
}

/*El programa funciona correctamente, NO está documentado y le faltan datos a la cabecera

Revisado por: Javier Chim Cemé

Equipo: SacaChispas

Fecha: 11/03/19 */

