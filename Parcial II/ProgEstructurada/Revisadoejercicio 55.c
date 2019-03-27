#include <stdio.h>


int main(int argc, char *argv[]) 
{
	
	int i=0,n=0;
	int num[n];
	
	printf ("Qué tan grande sera su vector?\n");
	scanf ("%d",&n);
	for (i=0;i<4;i++)
	{
		printf("Numero %d",i);
		scanf("%d",&num[i]);
	}
	for (i=0;i<4;i++)
	{
		if (num[i]<0)
		{
			printf ("El numero negativo esta en la posicion %d",i);
		}
		return 0;
	}
}

/*El programa funciona correctamente, NO está documentado y le faltan datos a la cabecera.
En los ciclos debe llegar a n-1, pero sólo llega hasta 4

Revisado por: Javier Chim Cemé

Equipo: SacaChispas

Fecha: 11/03/19 */
