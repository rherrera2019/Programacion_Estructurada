
/*53. E.P. que lea un vector de n elementos y que determine el elemento
mayor del arreglo y su posici�n*/


#include <stdio.h>
int main()
{
	int NUM;	
	printf("Especificar el tama�o del vector  ");
	scanf ("%d", &NUM);
	int nums [NUM] ;
	int posicion,i;
	int NumMayor = 0;
	i=1;
	while (i <= NUM)
	{
		i++;
		printf("Por favor, introduzca el n�mero: ");
		scanf ("%d", &nums [i] ) ;
	}
	i=0;
	while ( i < NUM)
	{
		i++;
		if (nums[i] > NumMayor){
			NumMayor = nums[i];
			posicion = i+1;
		}
	}
	printf("\nEL numero mayor es %d en la posicion %d",NumMayor, posicion);
	return 0;
}

/*
Revis�: Programadores Empedernidos.
-El c�digo cumple su funci�n.
-No se debe poner acentos en el printf, ya que muchos IDE no lo compilan adecuadamente.
-El c�digo no est� comentado.
-Las variables tienen nombres representativos.
