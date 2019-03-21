#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Problema 66.
Descripci�n: E.P. que lea una matriz de 9 X 12 elementos
 y que cuente todos los elementos negativos de la misma y 
los cambie por ceros.
Fecha: 12/03/2019
Versi�n: 1.0 */

float Matriz[9][12];
int main ()
{
	
	//Declaraci�n de variables
	int i,j;
	int negativos;
	float elemento;
	negativos=0;
	
	//Lectura de datos 
	for (i=1;i<=9;i++) //filas
	{
		for (j=1;j<=12;j++) //columnas 
		{
			printf("\n Dame el elemento de la fila %d en la columna %d : ",i,j);
			scanf("%f",&Matriz[i][j]);
			
			//Proceso 
			if (Matriz[i][j]<0){
				Matriz[i][j]=0;
				negativos++;
			}
		}
	}
	//Salida
	
	printf("\n 	El numero de elementos cambiados fue de %d : ",negativos);
	printf("\n La Matriz es: ");
	for (i=1;i<=3;i++) //filas
	{
		printf("\n");
		for (j=1;j<=3;j++) //columnas 
		{
			printf(" %.0f",Matriz[i][j]);
			
		}
	}
	printf("\n");
	return 0; 
}

/*El programa funciona como fue especificado. En el �ltimo ciclo FOR, falt� cambiar los l�mites (a [9][12]) 
(Se declaran librer�as de m�s �?)

Revis�: Javier Chim Cem�

Equipo: SacaChispas

*/
