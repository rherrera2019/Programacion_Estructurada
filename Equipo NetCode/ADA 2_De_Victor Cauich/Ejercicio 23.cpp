/*HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
23. Una papelería vende libros a $100, cuadernos a $15.50 y plumas a $2.35. E.P. 
que determine e imprima el monto total de una venta, según el número de artículos vendidos.
*/
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...

void verMayor(double Mayor, double Num3);

int main()
{
	setlocale(LC_ALL,"");//LLamo al metodo de la biblioteca locale.h, para que todas las actuaciones, puedan verse...
	printf("EJERCICIO 23. \n\n");
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
