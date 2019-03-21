/*59. E.P. que lea una matriz de M X N elementos y que cuente e
imprima cuantos elementos son pares y cuantos son impares.*/


#include <stdio.h>

int main(int argc, char *argv[]) {
	int colum, filas;//Declaracion de variables y constantes
	printf("\n ¿Cuantas columnas?: ");
	scanf("%d", &colum);
	printf("\n ¿Cuantas filas?: ");
	scanf("%d", &filas);
	int M1[filas][colum];
	int i, j, par=0, impar=0;
	for (i=0; i<filas; i++){
		for (j=0; j<colum; j++){
			printf ("\n Capture el numero en la posicion %d, %d  \n", i+1, j+1);//Entrada
			scanf("%d", &M1[i][j]);
		}
	}
	for (i=0; i<filas; i++){//Proceso
		for (j=0; j<colum; j++){
		if (M1[i][j] % 2 == 0){
			par++;
		}
		else{
			impar++;
		}
		}
	}
		printf("existen %d numeros pares \n", par);//Salida
		printf("existen %d numeros impares ", impar);
	return 0;
}

/*El programa funciona correctamente. Faltan datos al encabezado y no se valida la dimensión de la matriz.
Sugerencia: Separar un poco el código para que sea más fácil enterderlo.

Revisó: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

*/
