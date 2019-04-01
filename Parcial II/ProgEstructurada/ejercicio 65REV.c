#include <stdio.h>
/*E.P.que lea dos matrices de M X N elementos y que determine eimprima  si  la  diagonal
  principal de  la  primera  es  igual  a  la  diagonal principal dela segunda.*/
//Fecha:14/03/19
//Nombre:Josue Torres
int main() 
{
	//Declaracion de variables
	int f,c,count,count2,fila,columna;
	count=0;
	count2=0;
	fila=1;
	columna=1;
	printf ("Introduzca el numero de filas de la matriz a crear:");
	scanf ("%d",&f);
	printf ("\nIntroduzca el numero de columnas de la matriz a crear:");
	scanf ("%d",&c);
	//vectores
	float vector[f][c];
	float matriz[f][c];
	//PROCESO//
	//entradas al primer vector
	while (count<f)
	{
		while (count2<c)
		{
			printf ("\nEscriba el numero para la fila:%d y columna:%d   :",fila,columna);
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
	count2=0;
	fila=1;
	columna=1;
	
	//entradas al segundo vector
	while (count<f)
	{
		while (count2<c)
		{
			printf ("\nEscriba el numero para la fila:%d y columna:%d   :",fila,columna);
			scanf ("%f",&matriz[count][count2]);
			count2++;
			columna++;
		}
		count++;
		fila++;
		count2=0;
		columna=1;
	}
	count=0;
	count2=0;
	fila=1;
	columna=1;
	//Ciclo para ver si son iguales o no
	while (count<f)
	{
		if (vector[count][count]==matriz[count][count])
		{
			count=count+1;
		}
		else 
		{
			count=(f+1);
		};
	}
	//SALIDA//
	if (count==(f+1))
	{
		printf ("\nLa diagonal principal no es igual");
	}
	else 
	{
		printf ("\nLa diagonal principal es igual");
	};
}
/*Revisado por: Equipo Picateclas
Observaciones: Funciona correctamente, es necesario un poco más de documentación
para entender que hacen algunas variables
Estatus: Working
*/
