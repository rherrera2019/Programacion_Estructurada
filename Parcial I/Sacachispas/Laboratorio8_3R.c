/* III. E.P. que lea un vector de 30 elementos que sean enteros y, genere
e imprima  un vector con los elementos negativos y otro vector con los elementos positivos.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 7/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Declaramos las variables y el vector de los 30 números*/
	int num[30], i, j = 0, k = 0, positivos = 0, negativos = 0;
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for (i = 0; i < 30; i++)
	{
		/*ENTRADA de datos*/
		printf("\n\nIngrese el número en la posición %i: " , i+1);
		scanf("%i",&num[i]);
		
		/*PROCESO para determinar la cantidad de positivos y negativos*/
		if(num[i] >= 0)
		{
			
			positivos++;
			
		}
		else
		{
			
			negativos++;
			
		}
	}
	
	/*Declaramos los 2 vectores*/
	int pos[positivos], neg[negativos];
	
	/*PROCESO para guardar cada número en su correspondiente vector*/
	for (i = 0; i < 30; i++)
	{
		if(num[i] >= 0)
		{
			pos[j++] = num[i];
			
		} else 
		{
			neg[k++] = num[i];
			
		}
	}
	
	/*SALIDA de datos*/
	printf("\n\nLos elementos positivos introducidos fueron\n");
	
	for(j = 0; j < positivos; j++)
	{
		printf("\nElemento %i: %i", j + 1, pos[j]);
	}
	
	printf("\n\nLos elementos negativos introducidos fueron\n");
	
	for(j = 0; j < negativos; j++)
	{
		printf("\nElemento %i: %i\n", j + 1, neg[j]);
	}
	
	getch();
	
	return 0;
}
/* Funciona bien con todos los valores
Revisado por: Punto C (Erick Cárdenas)*/
/* Entrada: 20 1's seguidos y y 10 -1's
salida: los negativos son 10 -1's :v*/
