/*62. E.P que lea una matriz de 5 X 5 elementos y que calcule e imprima
la suma de sus elementos que se encuentran en la diagonal principal.*/



#include <stdio.h>
#define colum 5
#define filas 5//Declaracion de constantes

int main(int argc, char *argv[]) {
	int M1[filas][colum];//Declaracion de variables
	int i, j, sumatoria=0;
	for (i=0; i<filas; i++){
		for (j=0; j<colum; j++){
			printf ("\nCapture el numero en la posicion %d,%d: ", i+1, j+1);//Entrada
			scanf("%d", &M1[i][j]);
		}
	}
	for (i=0; i<filas; i++){
		for (j=0; j<colum; j++){//Proceso
			if(i==j){
			sumatoria=sumatoria+M1[i][j];
			}
		}
	}
	printf("\n La sumatoria de la diagonal es: ");//Salida
		printf("%d ", sumatoria);
	return 0;
}

/*El programa funciona correctamente. Faltan datos al encabezado.
Sugerencia: Separar un poco el código para que sea más fácil enterderlo.

Revisó: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

*/
