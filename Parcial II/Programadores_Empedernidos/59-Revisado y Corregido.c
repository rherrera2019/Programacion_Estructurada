
/*Programa que lee los elementos de una matriz MxN e imprime cuántos pares se ingresaron y cuantos impares.
Autor: Programadores Empedernidos. 
Versión: 1.0 
Fecha: 12/03/19 */
#include <stdio.h>
//Constantes y macros
#define FOR(A,B) for(A=0;A<B;A++)


int main(){
	//declaración de variables.
	int n, m, par=0, impar=0, i, j;
	
	//lectura del tamaño de la matriz
	printf("Ingresa el n\243mero de filas ");
	scanf("%d", &n);
	printf("\nIngresa el n\243mero de columnas ");
	scanf("%d", &m);
	
	int numeros[n][m]; //Matriz resultante.
	
	FOR(i,n){ //entrada de datos.
		FOR(j,m){
			printf("\nDigita el elemento [%d,%d] > ", i+1, j+1);
			scanf("%d", &numeros[i][j]);
			
			if(numeros[i][j] % 2 == 0){//validación de datos.
				par += 1;
			}
			else{
				impar += 1;
			}
		}
	}
	
	printf("\nIngresaste %d pares y %d impares.", par, impar); //salida
		
	return 0;
}
/*Revisado por: Punto C(Erick Cárdenas)
El programa funciona con todos los valores incluyendo cero y numero negativos
Entrada: Una matriz 3x3 con los valores del 1-9
Salida:cunata con 5 impares y 4 pares*/
