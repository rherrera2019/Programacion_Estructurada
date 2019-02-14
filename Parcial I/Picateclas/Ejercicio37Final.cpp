/* Programa: ContadorDePositivos.C
Descripción: Lee 100 números y cuenta e imprime cuántos son positivos.
Autor: Picateclas
Integrantes:
- López Madera Fernanda Jacqueline
- Durán Matos Juan José
- González Bautista Noé Alejandro
Versión: 1.0
Fecha: 12/feb/2019 */

#include <stdio.h>
#include <conio.h>

int main(void) {
	/*VARIABLES*/
	int c_general, c_positivos;
	float num;
	c_general=0;
	c_positivos=0;
	
	/*ENTRADA*/
	while(c_general<100){
		c_general=c_general+1;
		printf("\nIngrese el %i", c_general);
		printf("° número: ");
		scanf("%f", &num);
		
		/*PROCESO*/
		if(num>0){
			c_positivos=c_positivos+1;
		}
	}
	
	/*SALIDA*/
	printf("\n\nHay %i", c_positivos);
	printf(" números positivos.");
	getch();
	return 0;
}

/*El programa funciona correctamente, separar un poco el código para que se entienda mejor

Equipo: SacaChispas
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 13/02/2019*/

