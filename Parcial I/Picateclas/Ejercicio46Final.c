/*Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1. 0. 0
Descripcion del programa: E.P. que lea 200 números y que calcule e imprima cuantos son
negativos, cuantos son positivos y cuantos fueron iguales a cero.
Fecha de creacion: 17/feb/2019
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	//VARIABLES
	int i, CP=0, CN=0, CC=0;
	float numero;
	//PROCESO.
	for(i=0; i<200; i++){//INICIAMOS EL CICLO FOR
		printf("\nIngrese cualquier número: ");//ENTRADA
		scanf("%f", &numero);//LEEMOS EL NÚMERO.
		if(numero>0){
			CP++;//AUMENTA EL CONTADOR DE NÚMEROS POSITIVOS.
		}else{
			if(numero<0){
				CN++;//AUMENTA EL CONTADOR DE NÚMEROS NEGATIVOS.
			}else{
				CC++;//AUMENTA EL CONTADOR DE NÚMEROS IGUAL QUE 0.
			}
		}
	}
	printf("\n------------------------------------------");
	//SALIDAS
	printf("\nLa cantidad de números positivos son: %i", CP);
	printf("\nLa cantidad de números negativos son: %i", CN);
	printf("\nLa cantidad de números igual a 0 son: %i", CC);
	
	return 0;
}

/* Revisión:
-No imprime los acentos.
-El nombre de las variables podrían ser más representativos.
-El código cumple su función.

revisó: Programadores empedernidos.
*/
//Si impime los acentos.
