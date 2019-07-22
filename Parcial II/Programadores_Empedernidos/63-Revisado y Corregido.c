/*Programa que lee una matriz de 20x20 e imprime cuántos ceros se ingresaron en las primeras 10 filas.
Autor: Programadores Empedernidos. Versión: 1.0 Fecha: 12/03/19*/

#include <stdio.h>
#define SIZE 20

int main(){
	//declaración de variables.
	float matriz[SIZE][SIZE];
	int contador=0, i, j;
	
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){ //entrada de datos
			printf("Ingrese el elemento [%d,%d]> ", i+1, j+1);
			scanf("%f", &matriz[i][j]);
			
			if(matriz[i][j]==0 && i<1){ //Validación de datos.
				contador+=1;
			}
		}
	}
	printf("\n"); //Impresión del vector resultante.
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			printf(" %.3f ", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\n En las primeras 10 filas hay %d ceros", contador); //salida de datos.
}
/*No funciona con elementos float, estructura correcta y funciona bien*/
