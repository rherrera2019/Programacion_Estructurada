/* Programa: Imprimir 100 números.
Descripción: 
E.P. que lea 100 números (N) y que los imprima.
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
	int CN=0;
	float num;
	/*PROCESO*/
	while(CN<100){
		/*ENTRADA*/
		printf("\nIntroduzca un número:");
		scanf("%f", &num);
		CN=CN+1;
		/*SALIDA*/
		printf("%f\n", num);
	}
	/*SALIDA*/
	
	getch();
	return 0;
}

/*El programa funciona correctamente

Equipo: SacaChispas
Revisó: Javier Alejandro Chim Cemé
Fecha: 13/02/2019*/
