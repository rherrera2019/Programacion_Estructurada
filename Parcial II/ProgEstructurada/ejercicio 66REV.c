#include <stdio.h>
/*E.P.que  lea  una  matriz  de  9  X  12  elementos  y  que  cuente 
 todos los elementos negativos de la misma y los cambie por ceros.*/
//Fecha:14/03/19
//Nombre:Josue Torres
int main() 
{
	//Declaracion de variables
	float vector [9][12];
	int count,count2,fila,columna,negativo;
	count=0;
	count2=0;
	fila=1;
	columna=1;
	negativo=0;
	//PROCESO//
	//Entrada de cantidades en el vector
	while (count<9)
	{
		while (count2<12)
		{
			printf ("\nIntroduzca el numero para la fila:%d y columna:%d: ",fila,columna);
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
	count2=0;
	//ciclo para contar los negativos y convertir las cantidades en 0
	while(count<9)
	{
		while (count2<12)
		{
			if(vector[count][count2]<0)
			{
				negativo=negativo+1;
				vector[count][count2]=0;
			}
			count2++;
		}
		count++;
		count2=0;
	}
	//SALIDA//
	printf ("\nLa cantidad de numeros negativos es de: %d",negativo);
}

/*Revisado por: Equipo Picateclas
Observaciones: He ingresado 4 valores negativos, cambia los valores a cero pero no
los muestra, sólo te imprime cuantos valores negativos se ingresaron.
Estatus: Issues
*/
