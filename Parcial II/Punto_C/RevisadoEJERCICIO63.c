#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Problema 63.
Descripción: E.P. que lea una matriz de 20 X 20 
elementos y que cuente e imprima cuantos elementos
 igual a cero se encuentran en las primeras 10 filas.
Fecha: 12/03/2019
Versión: 1.0 */

int main ()
{
	
//Declaración de variables
	
	int ceros;
	int Matrizelemento[20][20];
	ceros=0;
	
//Lectura de datos 
	for (int i=0;i<20;i++) //filas
	{
		for (int j=0;j<20;j++) //columnas 
		{
			printf("\n Dame el elemento de la fila %d en la columna %d : ",i+1,j+1);
			scanf("%d",&Matrizelemento[i][j]);
			
			//Proceso 
			if (i<10){
				
				if (Matrizelemento[i][j]==0) {
					ceros++;
				}
			  }
			}
		}
	}
//Salida

	printf("\n 	El numero de ceros en la matriz es: %d  ",ceros);

	return 0; 
 }
 
 /*El programa funciona como fue especificado. (Se declaran librerías de más ¿?)
 
 Revisó: Javier Chim Cemé
 
 Equipo: SacaChispas
 
 */
 
