
/*
E.P. que lea una matriz de 9 X 12 elementos y que cuente todos
los elementos negativos de la misma y los cambie por ceros.

Autor: Programadores empedernidos. 
Versión: 1.0 
Fecha: 12/03/19. */

#include <stdio.h>
//Constantes y macros
#define FILAS 9
#define COL 12
#define FOR(A,B) for(A=0;A<B;A++)

int main(){
	//Declaración de variables
	float matriz[FILAS][COL];
	int i, j, contNegativos=0;
	
	FOR(i,FILAS){ //entrada de datos
		FOR(j,COL){
			printf("Digita el elemento [%d,%d]> ", i+1, j+1);
			scanf("%f", &matriz[i][j]);
			
			if(matriz[i][j] < 0){ //cuenta cuantos negativos hay
				contNegativos++;
			}
		}
	}
	printf("--- Matriz sin modificar: ");
	FOR(i,FILAS){ //entrada de datos
		printf("\n");
		FOR(j,COL){
			if(matriz[i][j] < 0){ //si es negativo lo imprime con corchetes
				printf("  [%.3f]  ", matriz[i][j]);
			}
			else{
				printf("   %.3f   ", matriz[i][j]);
			}
		}
	}
	
	FOR(i,FILAS){ //entrada de datos
		FOR(j,COL){
			if(matriz[i][j] < 0){ // si es negativo, se reemplaza con un 0
				matriz[i][j] = 0;
			}
		}
	}
	
	printf("\n\n--- Matriz modificada: ");
	FOR(i,FILAS){ //entrada de datos
		printf("\n");
		FOR(j,COL){
			printf("   %.3f   ", matriz[i][j]);
		}
	}
	
	printf("\n\nHabia un total de %d negativos", contNegativos);
	return 0;
}
/*
-El codigo funciona correctamente
-Identifica correctamente los negativos y los cambia por ceros
-Documentado correctamente
-seria bueno separar las lineas de texto para identificar
mejor cuando arroja un nuevo resultado(separar la lectura de
datos de la matriz sin modificar al imprimirlo)
Revisó:PuntoC*/
