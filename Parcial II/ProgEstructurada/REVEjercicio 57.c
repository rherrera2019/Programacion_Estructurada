#include <stdio.h>
#include <stdlib.h>

/*ADA 7 - Ejercicio 57
Actividad: E.P.  que  lea  una  matriz  de  N  X  M  elementos  y  que  encuentre  e
imprima la posición de los elementos negativos.
Fecha: 13 de Marzo del 2019
*/

int f,c,i,j;//Contadores

//Proceso
int main() {
	
	
	printf("Introduzca la cantidad de filas. ");
	scanf ("%i",&f);//Se le pide al usuario que introduzca la cantidad de filas que tendrá la matriz
	printf("Introduzca la cantidad de columnas. ");
	scanf ("%i",&c);//Se le pide al usuario que introduzca la cantidad de columnas que tendrá la matriz
	
	int matriz[f][c];//Se inicializa la matriz con las dimensiones dadas por el usuario
	
	//Proceso para pedir los elementos de la matriz
	for(i=0;i<f;i++){//Proceso de las filas
		for(j=0;j<c;j++){//Proceso de las columnas
			printf("\nIntroduzca el elemento de la fila %i, columna %i. ",i+1,j+1);
			scanf("%i",&matriz[i][j]);//Se le pide al usuario los elementos de la matriz
		}
	}
	
	system("cls");
	
	//Proceso para obtener los elementos de la matriz que son negativos
	for(i=0;i<f;i++){//Proceso filas
		for(j=0;j<c;j++){//Proceso columnas
			
			if(matriz[i][j]<0){//Condicional para obtener los elementos negativos
				printf("El elemento de la fila %i columna %i es negativo.",i+1,j+1);
			}
			
		}
		printf("\n");//Se imprime un salto de linea
	}
	
	return 0;
}
/*El programa correctamente si el usuario proporciona los datos esperados, pero 
si agregamos valores 0 o negativos, el programa no lo valida, también al momento 
de imprimir la posición de los números negativos, este los imprime corridos, 
creo que hubiera sido más eficiente que lo agregara como coordenadas.
Revisó: Picateclas.*/
