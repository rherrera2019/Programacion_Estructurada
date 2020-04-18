/*
	Name: Ejercicio 35
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 06/02/20 21:52
	Description: E.P. que lea 25 números (N) y que imprima los que sean iguales a cero.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float n;
	int i = 0;
	
	while(i<25){
		
		//Entrada
		printf("#%d. Ingrese un numero: ", ++i);
		scanf("%f", &n);
		
		//Proceso,Salida
		if(n == 0){
			printf("Ingresaste un cero\n");
		}
		
		i++;
	}
	return 0;
}
