/* Programa: Números negativos.
Descripción: 
E.P. que lea 50 números y que cuente e imprima cuantos son
negativos.
Autor: Picateclas
Integrantes:
- López Madera Fernanda Jacqueline
- Durán Matos Juan José
- González Bautista Noé Alejandro
Versión: 1.0
Fecha: 12/feb/2019 */

#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[]) {
	/*VARIABLES*/
	int ContNeg=0, ContNum=0;
	float num;
	
	/*PROCESO*/
	do{
		/*ENTRADA*/
		ContNum++;
		printf("\nIntroduzca un número:");
		scanf("%f", &num);
		
		//Verifica que sea negativo.
		if(num<0){ 
			ContNeg++;
		}
	} while(ContNum<50);
	
	/*SALIDA*/
	printf("\nLa cantidad de números negativos introducidos son: %i", ContNeg);
	
	getch();
	return 0;
}

/*El programa funciona correctamente, separar un poco el código para que se entienda mejor
Las variables pueden confunden un poco con su función.

Equipo: SacaChispas
Revisó: Javier Alejandro Chim Cemé
Fecha: 13/02/2019*/

