#include <stdio.h>
#include <stdlib.h> 

/*
Nombre del Programa: Mayores a 100
Descripción: E.P. que  lea  10  números  (N)  y  que  determine  e  imprima  los  que sean mayores a 100.
Autor: Guillermo Canto
Versión: 1.0
Fecha: 06/02/2020
*/

int main(int argc, char *argv[]) {
	
	float entrada;
	int i = 0;
	
	while(i<10){
		
		printf("Ingrese un numero: ");
		scanf("%f", &entrada);
		
		if(entrada > 100){
			printf("%.2f es mayor a 100\n", entrada);
		}
		
		i++;
	}
	
	return 0;
}

