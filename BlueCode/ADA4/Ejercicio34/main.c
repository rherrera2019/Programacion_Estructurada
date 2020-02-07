#include <stdio.h>
#include <stdlib.h>

/*
	Name: Ejercicio 34
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 06/02/20 21:11
	Description: Lee 100 numeros y los imprime 
*/


int main(int argc, char *argv[]) {
	float n;
	int i = 0;
	
	while(i<100){
		printf("Ingrese un numero (entradas no numericas terminan el programa): ");
		scanf("%f", &n);
		printf("Numero %d: %.2f\n", ++i, n);
	}
	
	
	return 0;
}
