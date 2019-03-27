/*52. E.P. que lea un vector de n elementos y que calcule e imprima el
producto de sus elementos. */



#include <stdio.h>
int main()
{
	int NUM;	
	printf("Especificar el tamaño del vector  ");
	scanf ("%d", &NUM);
	int nums [NUM] ;
	int i;
	int total = 1; 
	i=0;
	do 
	{
		printf("Por favor, introduzca el número: ");
		scanf ("%d", &nums [i] ) ;
		i++;
	} while (i<NUM);
	i=0;
	do
	{
		total *= nums [i] ;
		i++;
	}while (i<NUM);
	printf("\nEl porducto de los números es %d",total);
	return 0;
}

/*
Revisó: Programadores Empedernidos.
-El código cumple su función.
-No se debe poner acentos en el printf, ya que muchos IDE no lo compilan adecuadamente.
-Hay una palabra mal escrita en el último printf.
-El código no está comentado.
-Las variables tienen nombres representativos.
