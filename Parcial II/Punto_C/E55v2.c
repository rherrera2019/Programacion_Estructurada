#include <stdio.h>
#include <conio.h>

/*Ejercicio 55: Posición de un elementos negativo
Descripción: E.P. que lea un vector de n elementos,
el cual se sabe tiene un elemento negativo y que determine e imprima su posición.
Fecha: 05/03/2019
Versión: 1.0 */


int main () 
{
	int n,i;
	
	//ENTRADA
	printf ("\n ¿Cuantos elementos tiene el vector? : "); 
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
Revisó: Programadores Empedernidos.
-El código cumple su función.
-No se debe poner acentos en el printf, ya que muchos IDE no lo compilan adecuadamente.
-No se tomó en cuenta cuando el usuario no ingresa números positivos.
-Las variables tienen nombres representativos.
*/
