#include <stdio.h>

int main() {
	int c,l,p;
	float r;
	/*entrada de datos*/
	printf ("Introduzca cantidad de libros a comprar \n");
	scanf ("%d",&l);
	printf ("\nIntroduzca cantidad de cuadernos a comprar\n");
	scanf("%d",&c);
	printf("\nIntroduzca cantidad de plumas a comprar\n");
	scanf ("%d",&p);
	/*proceso*/
	if ( l<0 || c<0 || p<0) 
	{
		printf ("No se pueden restar los articulos por favor introduzca los datos otra vez");
	}
	else
	{
		r=(l*100)+(c*15.5)+(p*2.35);
		printf ("\nEl monto total a pagar es de: %.2f",r);
	}
	
	/*Salida de datos*/
	
	return 0;
}

