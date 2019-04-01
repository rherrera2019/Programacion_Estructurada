#include <stdio.h>
#include <stdlib.h>

/*ADA 7 - Ejercicio 58
Actividad: E.P.  que  lea  una  matriz  de  6  X  4  elementos  y  que  calcule  e
imprima la suma de sus elementos.
Fecha: 13 de Marzo del 2019
*/

int matriz[6][4];//Se inicializa la matriz
int i,j,suma=0;//Contadores y se inicia la variable para la suma

//Proceso
int main() {
	
	for(i=0;i<6;i++){//Proceso de las filas
		for(j=0;j<4;j++){//Proceso de las columnas
			printf("Introduzca el elemento de la fila %i columna %i. ",i+1,j+1);
			scanf ("%i",&matriz[i][j]);//Se pide al usuario el elemento de la matriz
			
			suma+=matriz[i][j];//Se suman los elementos de la matriz
			
		}
	}
	
	system("cls");
	
	//salida
	printf("La suma de toda la matriz es: %i",suma);//Se imprime el resultado de la suma
	
	return 0;
}
/*El programa funciona correctamente, hace la suma de los elementos, limpia la pantalla
y tiene la información que se pide por parte del profesor.
Revisó: Picateclas.*/
