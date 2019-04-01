#include <stdio.h>

int main() 
{
	//declaracion de variables
	int fila,columna,count,count2,reprobados,numfil,numcol;
	float sumfil,promfil,promgen,sumgen,mayor;
	count=0;
	count2=0;
	sumfil=0;
	promfil=0;
	reprobados=0;
	mayor=0;
	promgen=0;
	numfil=1;
	numcol=1;
	
	//establecimiento de la longitud del vector
	printf ("Escriba el numero de filas:");
	scanf ("%d", &fila);
	printf ("\nEscriba el numero de columnas:");
	scanf ("%d", &columna);
	//vectores
	float vector[fila][columna];
	float prom[fila];
	//PROCESO//
	//estructura para introducir y guardar los numeros
	while (count<fila)
	{
		while (count2<columna)
		{
			printf ("escriba la calificacion del alumno en fila:%d y columna: %d:  ",numfil,numcol);
			scanf ("%f",&vector[count][count2]);
			count2++;
			numcol++;
		}
		numfil++;
		count++;
		count2=0;
		numcol=1;
	}
	count=0;
	count2=0;
	//estructura para saber cuantos reprobados hay
	while (count<fila)
	{
		while (count2<columna)
		{
			if (vector[count][count2]<70)
			{
				reprobados=reprobados+1;
			}
			count2++;
		}
		count2=0;
		count++;
	}
	count=0;
	count2=0;
	//estructura para saber el promedio de cada fila  el cual se guarda en un vector de tamaño"filas"
	while (count<fila)
	{
		while (count2<columna)
		{
			sumfil=sumfil+vector[count][count2];
			count2++;
		}
		promfil=sumfil/columna;
		prom[count]=promfil;
		promfil=0;
		sumfil=0;
		count++;
		count2=0;
	}
	count=0;
	count2=0;
	//estructura para conocer el promedio del grupo se utilizo el vector de promedios por fila
	while (count<fila)
	{
		sumgen=sumgen+prom[count];
		count++;
	}
	promgen=sumgen/fila;
	count=0;
	count2=0;
	//Estructura para saber cual la mayor calificacion
	while (count<fila)
	{
		while (count2<columna)
		{
			if (vector[count][count2]>mayor)
			{
				mayor=vector[count][count2];
			}
			count2++;
		}
		count++;
		count2=0;
	}
	count=0;

	numfil=1;
	numcol=1;
	//SALIDAS//
	printf ("La mayor calificacion es de: %f",mayor);
	printf ("\nLos lugares con mayor calificacion son:\n");
	//estructura para saber cuales personas sacaron la mayor calificaion en caso de empate
	while (count<fila)
	{
		while (count2<columna)
		{
			if (vector[count][count2]==mayor)
			{
				printf ("\nfila:%d y columna:%d",numfil,numcol);
				numcol++;
			}
			count2++;
			numcol++;
		}
		count++;
		count2=0;
		numcol=1;
		numfil++;
	}
	printf ("\nLa cantidad de estudiantes reprobados es de:%d",reprobados);
	printf ("\nEl promedio general del grupo es de:%f",promgen);
	
	count=0;
	numfil=1;
	while (count<fila)
	{
		printf ("\nEL promedio de la fila %d es de:%f",numfil,prom[count]);
		count++;
		numfil++;
	}
}
/*Revisado por: Equipo Picateclas
Observaciones: He definido una matriz de 3x3 y sus elementos, tanto la posición(es)
de la calificación más alta, promedio por fila y grupal, y cantidad de reprobados
funcionan correctamente, es necesario separar el código y agregar un poco más 
de documentación para que sea legible
Estatus: Working
*/
