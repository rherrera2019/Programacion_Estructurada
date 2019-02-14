#include <stdio.h>
/*E.P. que lea 250 números y que determine e imprima cuantos
son positivos y cuantos son negativos.*/
int main () 
{
	/*variables*/
	int mcont,contpos,contneg;
	float d;
	mcont=0;
	contpos=0;
	contneg=0;
	/*proceso*/
	do
	{
		printf ("escriba un numero ");
		/*entrada*/
		scanf ("%f",&d);
		if (d<0)
		{
			contneg++;
		}
		if (d>0)
		{
			contpos=contpos+1;
		}
		if (d==0)
		{
			printf ("El 0 no es negativo ni positivo introduzca otro numero \n");
			mcont--;
		}
		mcont++;
	} while(mcont<5);
	/*salida*/
	printf ("Hubo %d positivos y %d negativos",contpos,contneg);
}
