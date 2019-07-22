
/*E.P. que lea una matriz de 15 X 13 elementos y que calcule e
imprima lo siguiente:
  a) El elemento menor del arreglo.
  b) El total de elementos negativos de la fila 10 a la 13.
  c) El mayor elemento del arreglo.
  
Autor: Programadores empedernidos. 
Versión: 1.0 
Fecha: 12/03/19. */

#include <stdio.h>
//Constantes y macros
#define FILAS 15
#define COL 2
#define FOR(A,B) for(A=0;A<B;A++)

int main(){
	//Declaración de variables
	float matriz[FILAS][COL], mayorMatriz=0, menorMatriz;
	int i, j, contNegativos=0;
	
	FOR(i,FILAS){ //entrada de datos
		FOR(j, COL){
			printf("Digita el elemento [%d,%d]> ", i+1, j+1);
			scanf("%f", &matriz[i][j]);
			
			if(matriz[i][j] > mayorMatriz){ //busca el elemento mayor de la matriz
				mayorMatriz = matriz[i][j];
			}
			if(matriz[i][j] < 0 && i>8 && i<=12 ){
				contNegativos++;
			}
		}
	}
	menorMatriz = matriz[0][0]; //se asigna como el menor el primero de la matriz
	FOR(i,FILAS){ //entrada de datos
		FOR(j, COL){
			if(menorMatriz > matriz[i][j]){//se busca el elemento menor de la matriz en base a la varible menorMatriz asignada anteriormente
				menorMatriz = matriz[i][j];
			}
		}
	}
	
	printf("\n\n>> El mayor numero de la matriz es el %.2f", mayorMatriz); //salida de datos.
	printf("\n>> El menor numero de la matriz es el %.2f", menorMatriz); 
	printf("\n>> Hay un total de %d numeros negativos en la fila 10 a la 13", contNegativos); 

	
	return 0;
}
//No funciona con elementos float, pero el codigo es correcto con números enteros
//Bien documentado
//Buena presentación
