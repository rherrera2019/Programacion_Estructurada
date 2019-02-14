#include <stdio.h>
#include <conio.h>

/*
Nombre: 34.c
Autor: Programadores empedernidos
Descripcion: E.P. que lea 100 números (N) y que los imprima.
Fecha: 09feb2019
Versión: 1.0 */

int main(int argc, char *argv[]) {
	/*se definen las variables*/
	int n;
	int i = 0; 
	/*entrada: Se solicitan los 100 numeros */
	printf("Introduce 100 números: \n");
	do{
		printf("%i/100 %c ",i+1,62);
		scanf("%i",&n);
		/*salida: Imprime el mismo número que se ingreso */
		printf("\n [%i] \n\n",n);
		i++;
	}
	while(i<100);
	
	return 0;
}/*Revisó Picateclas. Código legible y comprensible.
Muestra cuales son las variables, entrada(s) y salida(s).*/
