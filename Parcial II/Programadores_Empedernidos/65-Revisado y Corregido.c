
/*E.P. que lea dos matrices de M X N elementos y que determine e
imprima si la diagonal principal de la primera es igual a la diagonal
principal de la segunda.

Autor: Programadores Empedernidos. 
Versión: 1.0 
Fecha: 12/03/19 */
#include <stdio.h>
//Constantes y macros
#define FOR(A,B) for(A=0;A<B;A++)


int main(){
	//declaración de variables.
	int n, m, i, j, diagonalesIguales=1; //boleano para ver si se cumple la igualdad
	
	//lectura del tamaño de la matriz
	do{
		printf("Ingresa el n\243mero de filas: ");
		scanf("%d", &n);
		if(n<=0){
			printf("No puedes ingresar numeros menores a 1\n");
		}
	}
	while(n<=0);

	do{
		printf("Ingresa el n\243mero de columnas: ");
		scanf("%d", &m);
		if(m<=0){
			printf("No puedes ingresar numeros menores a 1\n");
		}
	}
	while(m<=0);
	
	
	float numeros1[n][m], numeros2[n][m]; //Matrices resultante.
	
	printf("\n\n--- MATRIZ 1 ---\n"); //lee matriz1
	FOR(i,n){ //entrada de datos.
		FOR(j,m){
			printf("Digita el elemento [%d,%d] > ", i+1, j+1);
			scanf("%f", &numeros1[i][j]);
			
		}
	}
	
	printf("\n\n--- MATRIZ 2 ---\n"); //lee matriz2
	FOR(i,n){ //entrada de datos.
		FOR(j,m){
			printf("Digita el elemento [%d,%d] > ", i+1, j+1);
			scanf("%f", &numeros2[i][j]);
		}
	}
	
	FOR(i,n){ //verifica que la diagonal principal de la matriz1 sea igual al de la matriz2
		FOR(j,m){
			if(i==j){
				if(numeros2[i][j] != numeros1[i][j]){
					diagonalesIguales=0;
					break;
				}
			}
		}
	}
	
	if(diagonalesIguales == 1 ){//salida de datos
		printf("\n\nLas diagonales SON equivalentes");
	}
	else{
		printf("\n\nLas diagonales NO SON equivalentes");
	}
		
	return 0;
}
/*
-El codigo funciona correctamente
-Identifica correctamente si las diagonales son iguales
-Documentado correctamente
-no identifica si se ingresa un valor <=0 al pedir las dimensiones
Revisó:PuntoC*/
