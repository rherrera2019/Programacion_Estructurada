#include <stdio.h>

/*	Ejercicio: ADA 4, Ejercicio 39.
Descripción: E.P. que lea las utilidades mensuales de una cadena de 5 tiendas y 
que determine e imprima cuantas tiendas tuvieron utilidades mayor alos $ 2,000,000.
Fecha: 12 Febrero 2019
Versión: 1.0
*/

int main() {
	
	int cont,contx,contm;
	float util,suma;
	
	cont=1;
	contx=0;
	
	do{
		printf("\nEmpresa %i\n",cont);
		
		suma=0;
		contm=1;
		
		do{
			printf("Introduzca las utilidades obtenidas en el mes %i. ",contm);
			scanf ("%f",&util);
			
			suma += util;
			
			contm++;
			
		}while (contm <= 12);
		
		if(suma > 2000000){
			contx++;
		}
		
		cont++;
		
	}while (cont <= 5);
	
	printf("\nUn total de %i empresas obtuvieron utilidades mayores a $2,000,000 al fianl del año.",contx);
	
	return 0;
}

