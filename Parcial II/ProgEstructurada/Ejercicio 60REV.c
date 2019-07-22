#include <stdio.h>
#include <stdlib.h>

/*ADA 7 - Ejercicio 60
Actividad: E.P.  que  lea  una  matriz  de  20  X  30  elementos  y  que  genere  e
imprima un vector de 20 elementos que contenga la sumatoria de cada fila de la matriz.
Fecha: 13 de Marzo del 2019
*/

int matriz[20][30];//Se inicializa la matriz
int vectorsuma[20];//Se inicializa el vector
int i,j;//Contadores

//Proceso
int main() {
	
	//Proceso para obtener los elementos de la matriz
	for(i=0;i<20;i++){//Proceso filas
		for(j=0;j<30;j++){//Proceso columnas
			printf("Introduzca el elemento de la fila %i, columna %i. ",i+1,j+1);
			scanf ("%i",&matriz[i][j]);//Se pide al usuario que introduzca los elementos de la matriz
			
			vectorsuma[i]+=matriz[i][j];//Se suman los elementos de cada fila y se ponen en el vector
			
		}
	}
	
	system("cls");
	
	//Salida
	for(i=0;i<20;i++){//Proceso vector
		printf("%i.- %i\n",i+1,vectorsuma[i]);//Se imprime el resultado de las sumas por fila colocadas en el vector
	}
	
	return 0;
}

/*Revisó:	 Picateclas

-El programa funciona correctamente
-El código es legible y claro
-Las variables son representativas

*/
