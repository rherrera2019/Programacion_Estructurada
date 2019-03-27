#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/*Problema 65.
Descripción:E.P. que lea dos matrices de M X N elementos y que
 determine e imprima si la diagonal principal de la primera es
 igual a la diagonal principal de la segunda.
Fecha: 12/03/2019
Versión: 2.0 */

int main ()
{
	
	//Declaración de variables
	int i,j,m,n;
	int validador;
	int contador; 
	float elementoA,elementoB; //cada uno corresponde a los elementos de cada matriz
	validador=0;
	contador=0;
	
	//Lectura de datos 
	do{
	printf("\n Dame el numero de filas de los arreglos : ");
	scanf("%d",&m);
	
	printf("\n Dame el numero de columnas de los arreglos : ");
	scanf("%d",&n);
	
	if (m==n)
	{
		validador=1;
	}
	else{
		printf("\n Las matrices no tienen diagonal principal");
		getch () ; 
		system("cls");
	}
	}while(validador==0);

	//creacion de las matrices para imprimir y ejemplificar la diagonal 
	float matrizA[m][n];
	float matrizB[m][n];
	
	for (i=1;i<=m;i++) //filas
	{
		for (j=1;j<=n;j++) //columnas 
		{
			printf("\n Dame el elemento de la fila %d en la columna %d DE LA PRIMERA MATRIZ : ",i,j);
			scanf("%f",&elementoA);
			matrizA[i][j]=elementoA;
			
			printf("\n Dame el elemento de la fila %d en la columna %d DE LA SEGUNDA MATRIZ : ",i,j);
			scanf("%f",&elementoB);
			matrizB[i][j]=elementoB;
			
			//Proceso 
			if (i==j){
				if (matrizA[i][j]==matrizB[i][j])
				{
					contador++;//si el contador es igual a M, las diagonales serán iguales
				}
			}
		}
	}
	//Salida
	if (contador==m)
	{
		printf("\n 	Las diagonales principales son iguales");
	}
	else{
		printf("\n 	Las diagonales no son iguales");
	}
	
	
	return 0; 
}

/*El programa funciona como fue especificado. (Se declaran librerías de más ¿?)

Revisó: Javier Chim Cemé

Equipo: SacaChispas

*/
