#include <stdio.h>
#include <stdlib.h>

/*ADA 7 - Ejercicio 56
Actividad: E.P. que lea una matriz de 3 X 3 elementos y los imprima.
Fecha: 13 de Marzo del 2019
*/

int matriz[3][3]; //Se inicializa la matriz
int i,j; //Contadores

//Proceso
int main() {
	
	for(i=0;i<3;i++){//Proceso de las filas
		for(j=0;j<3;j++){//Proceso de las columnas
			printf("\nIntroduzca el elemento de la fila %i, columna %i. ",i+1,j+1);
			scanf("%i",&matriz[i][j]);//Se le pide al usuario que introduzca los elementos
		}
	}
	
	system("cls");
	
	//Salida
	//Se imprime la matriz
	for(i=0;i<3;i++){//Proceso de las filas
		for(j=0;j<3;j++){//Proceso de las columnas
			printf("%i ",matriz[i][j]);//Se imprime el elemento correspondiente a esa posición de la matriz
		}
		printf("\n");
	}
	
	return 0;
}
/*El programa funciona correctamente, lee bien los datos, los imprime en una 
matriz de 3x3. Limpia la pantalla para que se aprecie mejor la matriz con los datos que ingresó el usuario.
Revisó: Picateclas.*/
