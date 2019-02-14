/* Programa: Números iguales a 0
Descripción: 
E.P. que lea 25 números (N) y que imprima los que sean iguales a
cero.
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
	do{
		/*ENTRADA*/
		printf("\nIntroduzca un número:");
		scanf("%f", &num);
		CN=CN+1;
		if(num==0){//Verifica que el número sea igual que 0.
			/*SALIDA*/
			printf("El número en la posición %i es igual a 0\n", CN);
		}
	} while(CN<25);
	
	getch();
	return 0;
}

/*El programa funciona correctamente

Equipo: SacaChispas
Revisó: Javier Alejandro Chim Cemé
Fecha: 13/02/2019*/
