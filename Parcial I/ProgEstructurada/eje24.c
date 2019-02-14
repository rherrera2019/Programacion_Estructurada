#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) 
{
	/* declaracion de variables */
	char a[6],b[3],c[5],d[8];
	printf ("Escriba la primera palabra\n");
	scanf("%s",a);
	/* proceso */
	if (strcmp(a,"Tienes")==0)
	{
		printf("1 de 4 palabras correctas,la siguiente es:\n");
		scanf ("%s",b);
		if (strcmp(b,"Que")==0)
		{
			printf ("2 de 4 palabras correctas,la siguiente es:\n");
			scanf ("%s",c);
			if (strcmp(c,"Estar")==0)
			{
				printf ("3 de 4 palabras correctas,la siguiente es:\n");
				scanf ("%s",d);
				if (strcmp(d,"Invitado")==0)
				{
					printf ("4 de 4 palabras correctas, Bienvenido");
				}
				else
					printf ("No estas invitado");
			}
			else
				printf ("No estas invitado");
		}
		else
			printf ("No estas invitado");
	}
	else
		printf ("No estas invitado");
	return 0;
}

