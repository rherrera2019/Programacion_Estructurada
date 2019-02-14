#include <stdio.h>
/*30. E.P. que lea un número entero obtenido al lanzar un dado de seis
caras e imprimir el número en letras de la cara opuesta. En las caras
opuestas de un dado de seis caras están los números: 1-6, 2-5 y 3-4.
Si el número del dado capturado es menor que 1 o mayor que 6, se
mostrará: “Un DADO no tiene ese número”. (utilizar switch)*/
int main(void)
{
	int ND;
	printf("Ingrese el número obtenido al lanzar: " );
	scanf ("%d", &ND);
	switch (ND)
	{
	case 1: printf("seis" );
	break;
	case 2: printf("cinco" );
	break;
	case 3: printf("cuatro" );
	break;
	case 4: printf("tres" );
	break;
	case 5: printf("dos" );
	break;
	case 6: printf("uno" );
	break;
	default: printf("Un dado no tiene ese número" );
	}
	
	//Funciona bien.
	
	return 0;
	
}
