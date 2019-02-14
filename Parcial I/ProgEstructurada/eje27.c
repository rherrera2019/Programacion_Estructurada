#include <stdio.h>
#include <conio.h>
int main () 
{
	/* declaracion de variables */
	int peso;
	printf ("Escriba el peso en gramos(maximo 5000): ");
	scanf ("%d",&peso);
	/* el condicional que habia que decia que tenia que ser maximo 5000 */
	if (peso<=5000)
		/* proceso:use el mismo del ejemplo de la plataforma */
	{
		printf ("  %d pesa(s) de 1000g \n", peso /1000);
		peso = peso % 1000;		
		printf ("  %d pesa(s) de 500g\n", peso /500);
		peso = peso % 500;
		printf ("  %d pesa(s) de 200g\n", peso /200);
		peso = peso % 200;
		printf ("  %d pesa(s) de 100g\n", peso /100);
		peso = peso % 100;
		printf ("  %d pesa(s) de 50g\n", peso /50);
		peso = peso % 50;
		printf ("  %d pesa(s) de 5g\n", peso /5);
		peso = peso % 5;
		printf ("  %d pesa(s) de 2g\n", peso /2);
		peso = peso % 2;
		printf ("  %d pesa(s) de 1g\n", peso /1);
		peso = peso % 1;

		
	}
	else
		printf ("No esta dentro del rango aceptado");
}
