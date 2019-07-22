#include <stdio.h>
/*
E.P.  que  lea  una  matriz  de  15  X  13  elementos  y  que  calcule  eimprima lo siguiente:
a)El elementomenor del arreglo.
b)El total de elementos negativos de la fila 10 a la 13.
c)El mayor elemento del arreglo.
*/
//Fecha:13/03/19
//Josue Torres

int main() 
{
	//declaracion de variables
	int count,count2,fila,columna,negative;
	float vector [15][13];
	float menor,mayor;
	count=0;
	count2=0;
	fila=1;
	columna=1;
	negative=0;
	
	//PROCESO//
	while (count<15)
	{
		while (count2<13)
		{
			printf("\nIntroduce el elemento de la fila:%d y columna:%d:  ",fila,columna);
			scanf ("%f",&vector[count][count2]);
			count2++;
			columna++;
		}
		count++;
		fila++;
		count2=0;
		columna=1;
	}
	count=0;
	fila=1;
	menor=vector[1][1];
	//Ciclo para encontrar el menor//
	while (count<15)
	{
		while (count2<13)
		{
			if (vector[count][count2]<menor)
			{
				menor=vector [count][count2];
			}
			count2++;
		}
		count++;
		count2=0;
	}
	count=0;
	count2=9;
	//ciclo para encontrar los negativos de la fila 10-13
	while (count<15)
	{
		while (count2<13)
		{
			if (vector[count][count2]<0)
			{
				negative=negative+1;
			}
			count2++;
		}
		count++;
		count2=9;
	}
	count=0;
	count2=0;
	mayor=vector[1][1];
	//ciclo para encontrar el mayor
	while (count<15)
	{
		while (count2<13)
		{
			if (vector[count][count2]>mayor)
			{
				mayor=vector [count][count2];
			}
			count2++;
		}
		count++;
		count2=0;
	}
	//SALIDA//
	printf("\nEl elemento menor es %f",menor);
	printf("\nEL elemento mayor es %f",mayor);
	printf("\nEl total de elementos negativos de la fila 10 a 13 es de %d",negative);
	return 0;
}

/*Revisado por: Equipo Picateclas
Observaciones: He ingresado los valores, número mayor del arreglo OK, número menor del
arreglo OK, no incrementa el contador de los elementos negativos de las filas 10 a 13 
Estatus: Issues
*/
