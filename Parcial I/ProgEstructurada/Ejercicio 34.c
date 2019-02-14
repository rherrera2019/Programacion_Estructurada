#include <stdio.h>
/*E.P. que lea 100 números (N) y que los imprima.*/
int main () 
{
	int a;
	float b;
	a=0;
	/*proceso*/
	while (a<100)
	{
		printf ("Escriba un numero ");
		scanf ("%f",&b);
		/*salida*/
		printf("El numero que escribiste fue: %f \n",b);
		a++;
	}
}
