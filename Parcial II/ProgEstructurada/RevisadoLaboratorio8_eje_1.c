#include <stdio.h>

int main()
{
	int vector[10];
	int count,countseg,prueba,prueba2,prueba3,numdef;
	count=0;
	countseg=0;
	prueba=0;
	prueba2=0;
	prueba3=0;
	while (count<10)
	{
		printf ("\nEscriba el un numero: ");
		scanf ("%d",&vector[count]);
		count++;
	}
	count=0;
	while  (count<10)
	{
		while (countseg<10)
		{
			if (vector[count]==vector[countseg])
			{
				prueba=prueba+1;
			}
			countseg++;;
		}
		if(prueba>prueba2)
		{
			numdef=vector[count];
			prueba2=prueba;
			
		}
		else
		{
			prueba3=prueba;
		}
		countseg=0;
		count++;
		prueba=0;
	}
	if (prueba3==prueba2)
	{
		printf ("No hay moda");
	}
	else
	{
		printf ("la moda es: %d",numdef);
	}
}

/*El programa funciona correctamente, NO está documentado y NO tiene cabecera

Revisado por: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

Fecha: 11/03/19 */
