#include <stdio.h>

/*	Ejercicio: ADA 4, Ejercicio 37.
Descripción: E.P.  que  lea  100  números  y que  cuente  e  imprima  cuantos  son positivos.
Fecha: 11 Febrero 2019
Versión: 1.0
*/

int main() {
	//Entrada
	float num;
	int cont,nump;
	
	cont = 1;
	nump = 0;
	
	//Proceso
	while(cont <= 10){
		printf("\nIntroduzca un número.");
		scanf ("%f",&num);
		
		if(num >= 0){
			nump++;
		}
		
		cont++;
	}
	
	//Salida
	printf("\nLa cantidad de números positivos es de: %i", nump);
	
	return 0;
}

