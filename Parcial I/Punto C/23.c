/*23 Una papelería vende libros a $100, cuadernos a $15.50 y plumas a
$2.35. E.P. que determine e imprima el monto total de una venta,
según el número de artículos vendidos.*/
#include <stdio.h>

int main() {
	int libros, cuadernos, plumas;
	float total;
	total=0;
	printf ("Inserte la cantidad de libros que vendió: ");
	scanf("%d", &libros);
	printf ("inserte la cantidad de cuadernos que vendió: ");
	scanf("%d", &cuadernos);
	printf ("inserte la cantidad de plumas que vendió: ");
	scanf("%d", &plumas);
	if (libros != 0)
		total =total+(libros*100) ;
	if (cuadernos != 0)
		total = total +(cuadernos * 15.50);
	if (plumas !=0)
		total = total+(plumas * 2.35);
	printf(" su total es: %.2f", total);
	return 0;
}

