#include <stdio.h>
#include <conio.h>

/*Ejercicio 55: Posici�n de un elementos negativo
Descripci�n: E.P. que lea un vector de n elementos,
el cual se sabe tiene un elemento negativo y que determine e imprima su posici�n.
Fecha: 05/03/2019
Versi�n: 1.0 */


int main () 
{
	int n,i;
	
	//ENTRADA
	printf ("\n �Cuantos elementos tiene el vector? : "); 
	scanf ("%d",&n);
	int elemento[n]; 
	i=1;
	while (i<=n)
	{
		printf ("\n Dame el elemento numero %d del vector : ", i); 
		scanf ("%d",&elemento[i]);
		i++;
	} 
	//PROCESO
	i=1;
	while(i<=n)
	{
		if (elemento[i]<0)
			printf ("\n El elemento en la posicion %d es negativo",i); //SALIDA
		   i++;
	}
	getch (); 
	return 0; 
}
/*
Revis�: Programadores Empedernidos.
-El c�digo cumple su funci�n.
-No se debe poner acentos en el printf, ya que muchos IDE no lo compilan adecuadamente.
-No se tom� en cuenta cuando el usuario no ingresa n�meros positivos.
-Las variables tienen nombres representativos.
*/
