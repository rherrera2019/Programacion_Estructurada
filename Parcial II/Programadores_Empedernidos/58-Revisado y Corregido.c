/*Programa que lee una matriz 6x4 e imprime la suma de sus elementos.
Autor: Programadores empedernidos. 
Versión: 1.0. 
Fecha; 12/03/19. */

#include <stdio.h>
//Declaracion de constantes y macros
#define MAX_F 6
#define MAX_C 4
#define FOR(A,B) for(A=0;A<B;A++)

int main(){
	int numeros[MAX_F][MAX_C]; //declaración de la matriz principal.
	int sumador; //declaración del sumador de elementos.
	int i,j;
	
	FOR(i,MAX_F){
		FOR(j,MAX_C){
			printf("Ingrese el elemento [%d,%d] > ", i+1, j+1); //Entrada de datos.
			scanf("%d", &numeros[i][j]);
			
			sumador += numeros[i][j]; //sumador de datos.
		}
	}
	
	printf("\nLa suma de los elementos de la matriz es %d", sumador); //Salida de datos
	
	return 0;
}
/*Revisado por: Punto C(Erick Cárdenas)
El programa no funciona, siempre imprime basura y el mismo número(419xxxx)*/

//--comentario del equipo autor: se probó el programa en Zinjai y Dev-C, y en los 2 funciona correctamente, nada que corregir
