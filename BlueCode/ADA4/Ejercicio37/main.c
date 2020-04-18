/*
	Name: Ejercicio 37
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 08/02/20 12:21
	Description: E.P.  que  lea  100  números  y  que  cuente  e  imprima  cuantos  son positivos.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int contadorPositivos = 0;
	int i = 0;
	float numero;
	
	while(i<100){
		
		//Entrada
		printf("%d Ingrese un numero: ", ++i);
		scanf("%f", &numero);
		
		//Proceso
		if(numero>0){
			contadorPositivos++;
		}
	}
	
	//Salida
	printf("Ha ingresado %d numeros positivos\n", contadorPositivos);
	
	return 0;
}
