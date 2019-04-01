#include <stdio.h>
#include <stdlib.h>

//Nombre:Numero mayor//
/* E.P. que lea un vector de n elementos y que determine el elemento
mayor del arreglo y su posición.*/
//Fecha: 05/03/19//
//Autor:Josue Torres//
int main () 
{
	//declaracion de variables//
	int n,count,posicion;
	float *elem;
	float candidatom;
	count=0;
	posicion=0;
	//ENTRADA//
	printf("Escriba el numero de elementos que desea capturar: ");
	scanf ("%d",&n);

	elem = (float*) malloc (sizeof(float) * n );
	//PROCESO//
	while (count<n)
	{
		printf ("\nEscriba el numero que desea capturar: ");
		scanf ("%f",&elem[count]);
		count++;
	};
	count=0;
	candidatom=0;
	while (count<n)
	{
		if (candidatom<elem[count])
		{
			candidatom=elem[count];
			posicion=(count+1);
		}
		else
		{
			candidatom=candidatom;
		}
		count++;
	};
	//SALIDA//
	printf ("\nEl el numero mas grande es: %f",candidatom);
	printf ("\n Esta en la posicion: %d",posicion);
}

/*El programa funciona correctamente, la forma en la que se iniciliza el vector es la ideal para evitar errores de compilación.

Revisado por: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

Fecha: 11/03/19 */
