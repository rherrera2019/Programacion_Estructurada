/* I. E.P. que solicite al usuario la dimensión de una matriz cuadrada de n x m elementos de tipo real, así como
leer  e imprimir dicho arreglo. Posteriormente, debe solicitar la posición de un elemento dentro de la matriz y 
proceder a dividir todos los elementos, entre dicho elemento ubicado en la posición proporcionada. Por último, 
imprimirá el estado final de la matriz.  Se deberá validar que no se realicen divisiones entre cero.
Equipo: SacaChispas
Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé
Fecha: 13/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <stdlib.h>



int main() 
{
	/*Declaramos las variables*/
	int filas, columnas, fila_posicion, columna_posicion;
	
	
	printf("\nFilas: ");
	scanf("%i", &filas);
	
	printf("\n\nColumnas: ");
	scanf("%i", &columnas);
	
	/*Declaramos la matriz*/
	double matriz[filas][columnas];
	
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			/*ENTRADA de datos*/
			printf("\n\nNúmero en la fila %i, columna %i: ", i + 1, j + 1);
			scanf("%lf", &matriz[i][j]);
			
		}
	}
	
	system("cls");
	
	/*Mostrar en pantalla la matriz después de los datos ingresados*/
	printf("\n\nMatriz resultante:\n\n");
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			printf("[%.2lf] ", matriz[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	int validar = 0;
	double numero_dividir;
	
	printf("\n\nValor a dividir");
	
	do
	{
		/*ENTRADA de datos*/
		printf("\n\nFila:");
		scanf("%i", &fila_posicion);
		
		printf("\n\nColumna:");
		scanf("%i", &columna_posicion);
		
		numero_dividir = matriz[fila_posicion - 1][columna_posicion - 1];
		
		
		if (numero_dividir == 0)
		{
			printf("\n\nElemento NO válido");
			
		} else
		{
			/*PROCESO para hacer la división entre el número que el usuario solicitó*/
			for(int i = 0; i < filas; i++)
			{
				for(int j = 0; j < columnas; j++)
				{
					
					matriz[i][j] /= (double)numero_dividir;
					
				}
			}
			
			validar = 1;
			
		}
		
	} while(validar == 0);
	
	
	/*SALIDA de datos*/
	printf("\n\nMatriz resultante:\n\n");
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			printf("[%.2lf] ", matriz[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	
	return 0;
}

/*ps nada mas que al utilizar 20 decimales la cosa se pone fea si divides entre numeros muy grandes pero de resto nada*/
//Josue Torres
