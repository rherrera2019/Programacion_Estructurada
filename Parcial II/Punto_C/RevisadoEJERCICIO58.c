/*58. E.P. que lea una matriz de 6 X 4 elementos y que calcule e
	imprima la suma de sus elementos.*/	


#include <stdio.h>

int main(int argc, char *argv[]) {
	//Declaraci�n de Variables
	int MatrizNumeros[2][2];
	int Suma;
	Suma=0;
	//Entrada
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("Dame el n�mero %d, %d:   ", i+1,j+1);
			scanf("%d", &MatrizNumeros[i][j]);
			Suma=Suma+MatrizNumeros[i][j]; //Proceso
		}
	}

	//Salida
	printf("La suma de tus elementos es: %d", Suma);
	
	
	
	
	
	
	
	
	return 0;
}

/*El programa funciona correctamente. Faltan datos al encabezado y se ten�a que leer una matriz de 6 x 4 (Usar macros para cambiar r�pido los valores).
Sugerencia: Separar un poco el c�digo para que sea m�s f�cil enterderlo.

Revis�: Ricardo Nicol�s Canul Ibarra

Equipo: SacaChispas

*/

