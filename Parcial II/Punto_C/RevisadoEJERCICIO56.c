//56. E.P. que lea una matriz de 3 X 3 elementos y los imprima.


#include <stdio.h>

int main(int argc, char *argv[]) {
	float Matriz[3][3];
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("Dame el n�mero %d, %d:   ", i+1,j+1);
			scanf("%f", &Matriz[i][j]);
			
	 		
		}
	}
	for(int i=0;i<3;i++){
		printf("\n");
		for(int j=0;j<3;j++){
			printf(" %.1f",Matriz[i][j]);
			
		}
	}	
	printf("\n");

	
	return 0;
}


/*El programa funciona correctamente. El c�digo NO est� documentado y le faltan datos al encabezado.
Sugerencia: Separar un poco el c�digo para que sea m�s f�cil enterderlo.

Revis�: Ricardo Nicol�s Canul Ibarra

Equipo: SacaChispas

*/

