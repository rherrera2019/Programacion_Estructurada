#include <stdio.h>
#include <conio.h>

int main() 
{
	/* declaracion de variables */
	int dia;
	float ctv,s;
	/* vd=ventas del dia, ctv=costo total de ventas, s=sueldo */
	printf ("\n");
	printf ("Considere el Lunes como dia 1 \n");	
	printf ("Escriba el numero de dia; \n");
	scanf ("%d",&dia);
	printf ("Escriba el ingreso total por ventas \n");
	scanf ("%f",&ctv);
	/*proceso: use switch por su capacidad para unir varios casos en uno */
	switch(dia)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		s=200+(.025*ctv);
		if (ctv>10000) 
		{
			s+=200;
			printf ("El sueldo total es de:%.2f",s);
		}
		else
			printf ("El sueldo total es de:%.2f",s);
		break;
	case 6:
		s=200+(.04*ctv);
		if (ctv>10000) 
		{
			s+=200;
			printf ("El sueldo total es de:%.2f",s);
		}
		else
			printf ("El sueldo total es de:%.2f",s);
		break;
	case 7:
		s=200+(.05*ctv);
		if (ctv>10000) 
		{
			s+=200;
			printf ("El sueldo total es de:%.2f",s);
		}
		else
			printf ("El sueldo total es de:%.2f",s);
		break;
	default:
		printf ("Error la semana solo tiene 7 dias");
	}
}
