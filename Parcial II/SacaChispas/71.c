/*Nombre del programa: Reservar y liberar memoria
Descripción: 71. E.P. que utilice un apuntador de arreglo con datos de tipo float,
pedir el usuario el número de elementos, luego reservar memoria
dinámica con calloc, leer dicho arreglo y posteriormente, imprimir
todos sus elementos; por ultimo, liberar el espacio de memoria
dinámica utilizado.
Autor: Equipo "Sacachispas"
Versión: 1.0
Fecha: 30/03/2019*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	//Desclaración de variables
	
	int i, n;
	float *numeros;
	
	//Entrada
	
	printf("Ingrese la cantidad de números deseado: ");
	scanf("%i", &n);
	
	//Proceso 
	
	numeros = calloc(n, sizeof(float));
	
	system("cls");
	printf("Ingrese los valores \n\n");
	
	for(i=0; i<n; i++){
		printf("%i° elemento: ", i+1);
		scanf("%f", &numeros[i]);
		system("cls");
	}
	
	//Salida
	
	printf("Elementos ingresados \n");
		
	for(i=0; i<n; i++){
		printf("%i° elemento: %.1f \n", i+1, numeros[i]);
	}
	
	//Liberación de memoria del puntero
	
	free(numeros);
	
	return 0;
}
