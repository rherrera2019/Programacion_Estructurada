#include <stdio.h>
#include <stdlib.h>

/*E.P. que lea dos vectores de n elementos y que genere e imprima
un tercer vector con la suma de cada uno de los elementos de los dos
anteriores.*/
//Autor:Josue Torres//
//Fecha:05/03/19//

int main () 
{
	//declaracion de variables//
	float *elem;
	float *vector;
	float *resultados;
	int count,count2,n;
	count=0;
	count2=0;
	
	//ENTRADA//
	printf("Escriba el numero de elementos que desea capturar: ");
	scanf ("%d",&n);
	
	elem = (float*) malloc (sizeof(float) * n );
	vector = (float*) malloc (sizeof(float) * n );
	resultados = (float*) malloc (sizeof(float) * n );
	
	//PROCESO//
	while (count<n)
	{
		printf ("\nEscriba el numero que desea capturar en el primer vector: ");
		scanf ("%f",&elem[count]);
		count++;
	};
	count=0;
	while (count<n)
	{
		printf ("\nEscriba el numero que desea capturar en el segundo vector: ");
		scanf ("%f",&vector[count]);
		count++;
	};
	count=0;
	while (count<n)
	{
		resultados[count]=(vector[count]+elem[count]);
		count++;
	};
	count=0;
	count2=1;
	
	//SALIDA//
	while (count<n)
	{
		printf ("\nPosicion numero: %d ",count2);
		printf ("\nEl numero es: %f",resultados[count]);
		count++;
		count2++;
	};
}

/*El programa funciona correctamente, la forma en la que se inicilizan los vectores es la ideal para evitar errores de compilación.

Revisado por: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

Fecha: 11/03/19 */
