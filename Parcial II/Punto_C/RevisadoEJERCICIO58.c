/*58. E.P. que lea una matriz de 6 X 4 elementos y que calcule e
	imprima la suma de sus elementos.*/	


#include <stdio.h>

int main(int argc, char *argv[]) {
	//Declaración de Variables
	int MatrizNumeros[2][2];
	int Suma;
	Suma=0;
	//Entrada
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("Dame el número %d, %d:   ", i+1,j+1);
			scanf("%d", &MatrizNumeros[i][j]);
			Suma=Suma+MatrizNumeros[i][j]; //Proceso
		}
	}

	//Salida
	printf("La suma de tus elementos es: %d", Suma);
	
	
	
	
	
	
	
	
	return 0;
}

/*El programa funciona correctamente. Faltan datos al encabezado y se tenía que leer una matriz de 6 x 4 (Usar macros para cambiar rápido los valores).
Sugerencia: Separar un poco el código para que sea más fácil enterderlo.

Revisó: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

*/

