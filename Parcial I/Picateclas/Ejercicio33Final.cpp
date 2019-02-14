/* Programa: Números mayores a 100
Descripción:  
E.P. que lea 10 números (N) y que determine e imprima los que
sean mayores a 100.
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
	int CN=0;//Contador de numeros
	float num;
	/*PROCESO*/
	while(CN<10){
		/*ENTRADA*/
		printf("\nIntroduzca un número:");
		scanf("%f", &num);
		CN=CN+1;
		if(num>100){//Verifica que sean mayores a 100.
			/*SALIDA*/
			printf("El número %f es mayor que 100\n", num);
		}
	}
	getch();
	return 0;
}

/*El programa funciona correctamente  

Equipo: SacaChispas
Revisó: Javier Alejandro Chim Cemé
Fecha: 13/02/2019*/
