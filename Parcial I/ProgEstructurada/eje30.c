#include <stdio.h>

int main () 
{
	int a;
	printf ("Escriba el numero que obtuvo en el dado: ");
	scanf("%d",&a);
	switch(a)
	{
	case 1:
		printf ("SEIS");
		break;
	case 6:
		printf ("UNO");
		break;
	case 2:
		printf ("CINCO");
		break;
	case 5:
		printf ("DOS");
		break;
	case 3:
		printf ("CUATRO");
		break;
	case 4:
		printf ("TRES");
		break;
	default:
		printf ("Un DADO no tiene ese numero");
	}
}
