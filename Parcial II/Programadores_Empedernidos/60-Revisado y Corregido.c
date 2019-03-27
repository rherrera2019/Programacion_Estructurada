/*Programa que lee una matriz de 20x30 y que genera e imrpime un vector de 20 elementos que contiene
la sumatoria de cada fila.
Autor: Programadores Empedernidos. Versión: 1.0 Fecha: 12/03/19 */

#include <stdio.h>

//Constantes y macros
#define FILAS 20
#define COL 30
#define FOR(A,B) for(A=0;A<B;A++)

int main(){
	float numeros[FILAS][COL]; //declaración de la matriz principal
	float vector[FILAS], sumador; //declaración del vector.
	int  i, j; 
	
	FOR(i,FILAS){
		sumador=0; //se incializa el sumador.
		FOR(j,COL){
			printf("Ingrese el elemento [%d,%d]> ", i+1, j+1); //entrada de datos
			scanf("%f", &numeros[i][j]);
			
			sumador += numeros[i][j]; //se realiza la suma de cada elemento de la fila
		}
		vector[i] = sumador; //se agrega el resultado al vector.
	}
	
	printf("\n\nMatriz resultante:\n"); //impresion de la matriz
	FOR(i,FILAS){
		FOR(j,COL){
			printf(" %.3f", numeros[i][j]);
		}
		printf("\n");
	}

	printf("\nVector:"); //impresión del vector.
	FOR(i,FILAS){
		printf(" [%.3f]", vector[i]);
	}
	
	return 0;
}
/*EL código tiene una correcta estructura, sin embargo no funciona con elementos
decimales, por lo que habría que cambiar la declaración del elemento.*/
