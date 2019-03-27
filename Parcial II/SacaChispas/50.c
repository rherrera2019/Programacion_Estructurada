/*Nombre del programa: Vector de 50 elementos
Descripción: 50. E.P. que lea un vector de 50 elementos y los imprima.

Autor: Equipo "Sacachispas"

Versión: 1.0

Fecha: 10/03/2019*/

#include <stdio.h>

int main() {
	
	
	int num[50], i, n = 50;
	
	/*Declaramos las variables*/
	for(i = 0; i < n; i++)
	{
		/*Entrada de datos*/
		printf("Ingrese el %i° elemento(número):\n", i+1);
		scanf("%i",&num[i]);
	}
	
	/*SALIDA de datos*/
	printf("\n\nEstos fueron los %i elementos ingresados:\n",n);
	
	for(i = 0; i < n; i++)
	{
		
		printf("%i\n",num[i]);
	}
	
	return 0;
}

/* El programa funciona correctamente
El programa genera correctamente el vector con numeros y lo imprime
Revisó: (PuntoC)*/ 
