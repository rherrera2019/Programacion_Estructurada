#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Problema 64.
Descripción: E.P. que lea una matriz de 15 X 13 elementos y que calcule e imprima lo siguiente:
a) El elemento menor del arreglo. 
b) El total de elementos negativos de la fila 10 a la 13.
c) El mayor elemento del arreglo
Fecha: 12/03/2019
Versión: 1.0 */

int main ()
{
	
	//Declaración de variables
	int i,j;
	float Tmenor,Tmayor;
	int negativos;
	negativos=0;
	Tmenor=0;
	Tmayor=0;
	//declaracion de matriz 
	float matriz[15][13];
		
	//Lectura de datos 
	for (i=1;i<=15;i++) //filas
	{
		for (j=1;j<=13;j++) //columnas 
		{
			printf("\n Dame el elemento de la fila %d en la columna %d : ",i,j);
			scanf("%f",&matriz[i][j]);
			
			//Proceso 
			
			if (i==1&&j==1){ //asigno el primer elemento a ámbos tronos 
				Tmenor=matriz[i][j];
				Tmayor=matriz[i][j];
			}
			
			//inciso c 
			if (matriz[i][j]>Tmayor)
			{
				Tmayor=matriz[i][j];
			}
			else {
				//inciso a
				if (matriz[i][j]<Tmenor)
				{
					Tmenor=matriz[i][j];
				}
			}
			//inciso b 
			if (i>=2&&i<=3){
				if (matriz[i][j]<0)
				{
					negativos++;
				}
			}
		}
	}
	//Salida
	
	printf("\n 	El numero de elementos negativos en la matriz es %d : ",negativos);
	printf("\n 	El elemento mayor de la matriz es %.2f : ",Tmayor);
	printf("\n 	El elemento menor de la matriz es %.2f : ",Tmenor);
	
	return 0; 
}

/*El programa funciona como fue especificado. No se revisan los elementos negativos en las filas especificadas (entre 10 y 13)
Los índices de la matriz empiezan desde cero.
(Se declaran librerías de más ¿?)

Revisó: Javier Chim Cemé

Equipo: SacaChispas

*/
