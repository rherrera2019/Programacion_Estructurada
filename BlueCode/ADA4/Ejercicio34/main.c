/*
	Name: Ejercicio 34
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 06/02/20 21:11
	Description: Lee 100 numeros y los imprime 
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float n;
	int i = 0;
	
	//Proceso
	while(i<100){
		
		//Entrada
		printf("Ingrese un numero (entradas no numericas terminan el programa): ");
		scanf("%f", &n);
		
		//Salida
		printf("Numero %d: %.2f\n", ++i, n);
	}
	
	
	return 0;
}
