/*52. E.P. que lea un vector de n elementos y que calcule e imprima el
producto de sus elementos. */



#include <stdio.h>
int main()
{
	int NUM;	
	printf("Especificar el tama�o del vector  ");
	scanf ("%d", &NUM);
	int nums [NUM] ;
	int i;
	int total = 1; 
	i=0;
	do 
	{
		printf("Por favor, introduzca el n�mero: ");
		scanf ("%d", &nums [i] ) ;
		i++;
	} while (i<NUM);
	i=0;
	do
	{
		total *= nums [i] ;
		i++;
	}while (i<NUM);
	printf("\nEl porducto de los n�meros es %d",total);
	return 0;
}

/*
Revis�: Programadores Empedernidos.
-El c�digo cumple su funci�n.
-No se debe poner acentos en el printf, ya que muchos IDE no lo compilan adecuadamente.
-Hay una palabra mal escrita en el �ltimo printf.
-El c�digo no est� comentado.
-Las variables tienen nombres representativos.
