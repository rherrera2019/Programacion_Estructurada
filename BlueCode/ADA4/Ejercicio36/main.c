/*
	Name: Ejercicio 36
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 06/02/20 21:58
	Description: E.P.  que  lea  50  números  y que  cuente  e  imprima  cuantos  son negativos.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int contadorNegativos = 0;
	float numero;
	int i = 0;
	
	while(i<50){
		
		//Entrada
		printf("%d Ingrese un numero: ", ++i);
		scanf("%f", &numero);
		
		//Proceso
		if(numero<0){
			//printf("%.2f es negativo.\n");
			contadorNegativos++;
		}
		
	}
	
	//Salida
	printf("Ingreso %d numeros negativos.\n", contadorNegativos);
	
	return 0;
}
