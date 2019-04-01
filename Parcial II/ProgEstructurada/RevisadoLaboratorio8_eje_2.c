#include <stdio.h>

int main()
{
	int vector[20];
	int count,suma,producto;
	count=0;
	suma=0;
	producto=1;
	
	while (count<20)
	{
		printf ("\nEscriba el un numero: ");
		scanf ("%d",&vector[count]);
		count++;
	}
	count=0;
	while  (count<20)
	{
		if (vector[count] % 2)
		{
			producto=producto*vector[count];
		}
		else
		{
			suma=suma+vector[count];
		}
		count++;
	}
	printf("\nLa suma de los elementos pares es: %d",suma);
	printf ("\nEl producto de los elementos impares es: %d",producto);
}

/*El programa funciona correctamente, NO está documentado y le faltan datos a la cabecera
Está al revés la condición(los pares deben sumarse y los impares multiplicarse)

Revisado por: Javier Chim Cemé

Equipo: SacaChispas

Fecha: 11/03/19 */
