/*51. E.P. que lea un vector de n elementos y que calcule e imprima su
sumatoria*/



#include <stdio.h>
int main()
{
	int NUM;	
	printf("Especificar el tama�o del vector  ");
	scanf ("%d", &NUM);
	int nums [NUM] ;
	int i;
	i=1;
	int total = 0; 

	while (i<=NUM)
	{
		i++;
		printf("Por favor, introduzca el n�mero: ");
		scanf ("%d", &nums [i] ) ;
		total += nums [i] ;
	}
	printf("\nLa suma de los n�meros es %d",total);
	return 0;
}
/*
Revis�: Programadores Empedernidos.
-El c�digo cumple su funci�n.
-No se debe poner acentos en el printf, ya que muchos IDE no lo compilan adecuadamente.
-El c�digo no est� comentado.
-Las variables tienen nombres representativos.
