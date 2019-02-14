#include <stdio.h>
#include <conio.h>
int main () 
{
	/*declaracion de variables */
	int a;
	printf ("Escribe el numero del mes en el que estas\n");
	/* entradas */
	printf ("(Enero es el 1)\n");
	scanf ("%d",&a);
	/* proceso */
	switch(a)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		printf ("El mes tiene 31 dias");
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf ("El mes tiene 30 dias");
		break;
	case 2:
		printf ("El mes tiene 28 dias o 29 si es año bisiesto");
		break;
	default:
		printf ("No existe ese mes");
	}
}
