#include <stdio.h>
#include <string.h>
int main() 
{
	int m,e,ac,cc;
	float t;
	/*m=modelo, e=edad, ac=años conduciendo, t=total,cc=costo del color*/
	char color[6];
	printf ("Escribe el Modelo de tu auto\n");
	printf ("(A=1 B=2 C=3) \n");
	/*entradas*/
	scanf ("%d",&m);
	/* proceso:se ve largo pero basicamente es lo mismo en los 3 casos casi casi copie y pegue,solo cambia la variable cc */
	/*lo puse asi porque era molesto que al terminar de escribir todo al principio te dieras cuenta de que escribiste mal algo y tuvieras que volver a empezar */
	switch(m)
	{
	case 1:
		printf ("Escribe el color de tu auto(claro/oscuro)\n");
		scanf ("%s",color);
		if (strcmp(color,"claro")==0)
		{
			cc=3800;
			printf ("\nEscribe cuantos años llevas conduciendo\n");
			scanf ("%d",&ac);
			if (ac<2)
			{
				printf ("\nEscribe tu edad\n");
				scanf ("%d",&e);
				if (e<20) 
				{
					t=(cc*.25)+(cc*.25)+cc;
				}
				else if (e>=20 && e<=30)
				{
					t=(cc*.1)+(cc*.25)+cc;
				}
				else if (e>=31 && e<=65)
				{
					t=(cc*.25)+cc;
				}
				else
					t=(cc*.15)+(cc*.25)+cc;
			}
			else
			printf ("\nEscribe tu edad\n");
			scanf ("%d",&e);
			if (e<20) 
			{
				t=(cc*.25)+cc;
			}
			else if (e>=20 && e<=30)
			{
				t=(cc*.1)+cc;
			}
			else if (e>=31 && e<=65)
			{
				t=cc;
			}
			else
				t=(cc*.15)+cc;
		}
		else if(strcmp(color,"oscuro")==0)
		{
			cc=4340;
				printf ("\nEscribe cuantos años llevas conduciendo\n");
			scanf ("%d",&ac);
			if (ac<2)
			{
				printf ("\nEscribe tu edad\n");
				scanf ("%d",&e);
				if (e<20) 
				{
					t=(cc*.25)+(cc*.25)+cc;
				}
				else if (e>=20 && e<=30)
				{
					t=(cc*.1)+(cc*.25)+cc;
				}
				else if (e>=31 && e<=65)
				{
					t=(cc*.25)+cc;
				}
				else
					t=(cc*.15)+(cc*.25)+cc;
			}
			else
			printf ("\nEscribe tu edad\n");
			scanf ("%d",&e);
			if (e<20) 
			{
				t=(cc*.25)+cc;
			}
			else if (e>=20 && e<=30)
			{
				t=(cc*.1)+cc;
			}
			else if (e>=31 && e<=65)
			{
				t=cc;
			}
			else
				t=(cc*.15)+cc;
		}
		else
		{
			printf ("No existe ese color");
		}
		break;
	case 2:
		printf ("Escribe el color de tu auto(claro/oscuro)\n");
		scanf ("%s",color);
		if (strcmp(color,"claro")==0)
		{
			cc=4930;
			printf ("\nEscribe cuantos años llevas conduciendo\n");
			scanf ("%d",&ac);
			if (ac<2)
			{
				printf ("\nEscribe tu edad\n");
				scanf ("%d",&e);
				if (e<20) 
				{
					t=(cc*.25)+(cc*.25)+cc;
				}
				else if (e>=20 && e<=30)
				{
					t=(cc*.1)+(cc*.25)+cc;
				}
				else if (e>=31 && e<=65)
				{
					t=(cc*.25)+cc;
				}
				else
						 t=(cc*.15)+(cc*.25)+cc;
			}
			else
				printf ("\nEscribe tu edad\n");
			scanf ("%d",&e);
			if (e<20) 
			{
				t=(cc*.25)+cc;
			}
			else if (e>=20 && e<=30)
			{
				t=(cc*.1)+cc;
			}
			else if (e>=31 && e<=65)
			{
				t=cc;
			}
			else
					 t=(cc*.15)+cc;
		}
		else if(strcmp(color,"oscuro")==0)
		{
			cc=5600;
			printf ("\nEscribe cuantos años llevas conduciendo\n");
			scanf ("%d",&ac);
			if (ac<2)
			{
				printf ("\nEscribe tu edad\n");
				scanf ("%d",&e);
				if (e<20) 
				{
					t=(cc*.25)+(cc*.25)+cc;
				}
				else if (e>=20 && e<=30)
				{
					t=(cc*.1)+(cc*.25)+cc;
				}
				else if (e>=31 && e<=65)
				{
					t=(cc*.25)+cc;
				}
				else
						 t=(cc*.15)+(cc*.25)+cc;
			}
			else
				printf ("\nEscribe tu edad\n");
			scanf ("%d",&e);
			if (e<20) 
			{
				t=(cc*.25)+cc;
			}
			else if (e>=20 && e<=30)
			{
				t=(cc*.1)+cc;
			}
			else if (e>=31 && e<=65)
			{
				t=cc;
			}
			else
					 t=(cc*.15)+cc;
		}
		else
				printf ("No existe ese color");
		break;
	case 3:
		printf ("Escribe el color de tu auto(claro/oscuro)\n");
		scanf ("%s",color);
		if (strcmp(color,"claro")==0)
		{
			cc=7570;
			printf ("\nEscribe cuantos años llevas conduciendo\n");
			scanf ("%d",&ac);
			if (ac<2)
			{
				printf ("\nEscribe tu edad\n");
				scanf ("%d",&e);
				if (e<20) 
				{
					t=(cc*.25)+(cc*.25)+cc;
				}
				else if (e>=20 && e<=30)
				{
					t=(cc*.1)+(cc*.25)+cc;
				}
				else if (e>=31 && e<=65)
				{
					t=(cc*.25)+cc;
				}
				else
						 t=(cc*.15)+(cc*.25)+cc;
			}
			else
				printf ("\nEscribe tu edad\n");
			scanf ("%d",&e);
			if (e<20) 
			{
				t=(cc*.25)+cc;
			}
			else if (e>=20 && e<=30)
			{
				t=(cc*.1)+cc;
			}
			else if (e>=31 && e<=65)
			{
				t=cc;
			}
			else
					 t=(cc*.15)+cc;
		}
		else if(strcmp(color,"oscuro")==0)
		{
			cc=8250;
			printf ("\nEscribe cuantos años llevas conduciendo\n");
			scanf ("%d",&ac);
			if (ac<2)
			{
				printf ("\nEscribe tu edad\n");
				scanf ("%d",&e);
				if (e<20) 
				{
					t=(cc*.25)+(cc*.25)+cc;
				}
				else if (e>=20 && e<=30)
				{
					t=(cc*.1)+(cc*.25)+cc;
				}
				else if (e>=31 && e<=65)
				{
					t=(cc*.25)+cc;
				}
				else
						 t=(cc*.15)+(cc*.25)+cc;
			}
			else
				printf ("\nEscribe tu edad\n");
			scanf ("%d",&e);
			if (e<20) 
			{
				t=(cc*.25)+cc;
			}
			else if (e>=20 && e<=30)
			{
				t=(cc*.1)+cc;
			}
			else if (e>=31 && e<=65)
			{
				t=cc;
			}
			else
					 t=(cc*.15)+cc;
		}
		else
				printf ("No existe ese color");
		break;
	default:
		printf ("No esixte ese modelo");
	}
	printf ("\nEl costo total del seguro es de: %.2f",t);
}
