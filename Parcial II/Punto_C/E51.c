/*51. E.P. que lea un vector de n elementos y que calcule e imprima su
	sumatoria*/
	


#include <stdio.h>
int main()
{
	int NUM;	
	printf("Especificar el tamaño del vector  ");
	scanf ("%d", &NUM);
	int nums [NUM] ;
	int i;
	int total = 0; 

	for (i = 0; i < NUM; i++)
	{
		printf("Por favor, introduzca el número: ");
		scanf ("%d", &nums [i] ) ;
	}
	for (i = 0; i < NUM; i++)
	{
		total += nums [i] ;
	}
	printf("\nLa suma de los números es %d",total);
	return 0;
}

/*
Revisó: Programadores Empedernidos.
-El código cumple su función.
-No se debe poner acentos en el printf, ya que muchos IDE no lo compilan adecuadamente.
-Las variables tienen nombres representativos.
