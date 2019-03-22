/*E.P. que lea una matriz de N X M elementos y que encuentre e
imprima la posición de los elementos negativos.

Autor: Programadores empedernidos. 
Versión: 1.0. 
Fecha; 12/03/19. */

#include <stdio.h>
//Declaracion de constantes y macros
#define FOR(A,B) for(A=0;A<B;A++)

int main(){
	int filas, col; //declaración de las variables del tamaño de la matriz.
	int i, j, k, contNegativos=0;
	
	printf("Cuantas filas tiene tu matriz?: ");
	scanf("%d", &filas);
	printf("Cuantas columnas tiene tu matriz?: ");
	scanf("%d", &col);
	
	int numeros[filas][col]; //Se inicia la matriz con las variables
	
	FOR(i,filas){
		FOR(j,col){
			printf("Ingrese el elemento [%d,%d] > ", i+1, j+1); //Entrada de datos.
			scanf("%d", &numeros[i][j]);
			
			if(numeros[i][j] < 0){
				contNegativos++;
			}
		}
	}
	int filaNegativo[contNegativos], colNegativo[contNegativos]; //Vectores para guardar la fila y columna de cada negativo
	
	k=0;
	FOR(i,filas){
		FOR(j,col){
			if(numeros[i][j] < 0){
				filaNegativo[k] = i+1;
				colNegativo[k] = j+1;
				k++;
			}
		}
	}
	printf("\n");
	FOR(i,contNegativos){
		printf("El negativo #%d esta en la posicion (%d,%d)\n", i+1, filaNegativo[i], colNegativo[i]);
	}
	
	return 0;
}
/*Revisado por: Punto C(Erick Cardenas)
EL progrma funciona bien y encuentra los numero negativos
pero no veo en donde se usan MAX_C y MAX_F en el programa
y eliminarlos no cambia en nada al programa*/
