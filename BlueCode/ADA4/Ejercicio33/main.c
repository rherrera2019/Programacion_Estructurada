/*
	Name: Ejercicio 33
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 06/02/20 21:11
	Description: Lee  10  números  y  que  determina  e  imprime los  que sean mayores a 100. 
*/

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
	
	float entrada;
	int i = 0;
	
	while(i<10){
		
		//Entrada
		printf("Ingrese un numero: ");
		scanf("%f", &entrada);
		
		//Proceso
		if(entrada > 100){
			
			//Salida
			printf("%.2f es mayor a 100\n", entrada);
		}
		
		i++;
	}
	
	return 0;
}

