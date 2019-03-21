/*60. E.P. que lea una matriz de 20 X 30 elementos y que genere e
imprima un vector de 20 elementos que contenga la sumatoria de cada
fila de la matriz.*/



#include <stdio.h>
#define colum 3//Declaracion de constantes
#define filas 2

int main(int argc, char *argv[]) {
	int M1[filas][colum], M2[filas];//Declaracion de variables
	int i, j, sumatoria=0;
	for (i=0; i<filas; i++){
		for (j=0; j<colum; j++){
			printf ("\n Capture el numero en la posicion %d , %d: ", i+1, j+1);//Entrada
			scanf("%d", &M1[i][j]);
		}
	}
	for (i=0; i<filas; i++){
		for (j=0; j<colum; j++){
			sumatoria=sumatoria+M1[i][j];//Proceso
		}
		M2[i] = sumatoria;
		sumatoria=0;
	}
	
for (i=0;i<filas;i++){
	printf("\n La sumatoria de la fila %d es: ", i+1);//Salida
	printf("\n\n %d ", M2[i]);
	}
	return 0;
}

/*El programa funciona correctamente. Faltan datos al encabezado.
Sugerencia: Separar un poco el código para que sea más fácil enterderlo.

Revisó: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

*/
