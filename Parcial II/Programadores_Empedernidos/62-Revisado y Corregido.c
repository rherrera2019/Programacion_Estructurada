/*Programa que lee una matriz de 5x5 y suma los elementos de la diagonal principal.
Autor: Programadores empedernidos. Versión: 1.0 Fecha: 12/03/19. */

#include <stdio.h>
//Constantes y macros
#define SIZE 5
#define FOR(A,B) for(A=0;A<B;A++)

int main(){
	//Declaración de variables
	float matriz[SIZE][SIZE], sumador=0;
	int i, j;
	
	FOR(i,SIZE){ //entrada de datos
		FOR(j,SIZE){
			printf("Digita el elemento [%d,%d]> ", i+1, j+1);
			scanf("%f", &matriz[i][j]);
			
			if(i==j){ //verificación, si es parte de la diagonal principal, el elemento se agrega al sumador.
				sumador+=matriz[i][j];
			}
		}
	}
	
	printf("\n");
	FOR(i,SIZE){ //impresión de la matriz
		FOR(j,SIZE){
			if(i==j){
				printf(" [%.2f] ", matriz[i][j]);
			}else{
				printf("  %.2f  ", matriz[i][j]);
			}
		}
		printf("\n");
	}
	
	printf("\nLa suma de los elementos de la diagonal principal es: %.2f", sumador); //salida de datos.
	
	return 0;
}
/*Presentación muy elegante y visual, al imprimir y señalar cual es la diagonal 
principal, funciona correctamente, detallado y bien explicado.*/
