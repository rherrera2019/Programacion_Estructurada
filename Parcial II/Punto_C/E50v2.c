//50. E.P. que lea un vector de 50 elementos y los imprima.

#include <stdio.h>
#define NUM 5
int main()
{
	int nums [NUM] ;// Declaracion de variables
	int i;
	i=1;
	do 
	{
		i++;
		printf("Por favor, introduzca el número: ");
		scanf ("%d", &nums [i] ) ;//Entrada
	}while (i<NUM);
	printf ("\nVector de números : " ) ;//Salida
	i=1;
	do
	{
		i++;
		printf ("%d ",nums [i] ) ;
	} while(i<NUM);
	return 0;						
}

/*
Revisó: Programadores Empedernidos.
-El código cumple su función.
-No se debe poner acentos en el printf, ya que muchos IDE no lo compilan adecuadamente.
-Las variables tienen nombres representativos.
*/
