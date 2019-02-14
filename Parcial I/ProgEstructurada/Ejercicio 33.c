#include <stdio.h>
/* E.P. que lea 10 números (N) y que determine e imprima los que
sean mayores a 100.*/
int main ()
{
	/*variables*/
	float a;
	int b;
	b=0; /*proceso*/
	while (b<10)
	{
		printf ("Introduzca un numero ");
		scanf ("%f",&a);
		if (a>100)
		{
			/*salida*/
			printf ("EL numero %.2f es mayor a 100 \n",a);
		}
		b++;
	}
}
