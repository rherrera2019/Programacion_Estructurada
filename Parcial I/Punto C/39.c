#include <stdio.h> 
#include <conio.h>
#include <string.h>

/*Ejercicio 39: utilidad mayor 
Descripción: E.P. que lea las utilidades mensuales de una cadena de 5 tiendas
 y que determine e imprima cuantas tiendas tuvieron utilidades mayor a los $ 2,000,000.-.
Fecha: 11/02/2019
Versión: 1.0 */

int main () 
{
	//declaracion de variables
	int mtiendas;
	int contador;
	int utilidad; 
	contador=1;
	mtiendas=0;
	
	//entradas
	do 
	{
	printf("\n Dame la utilidad de la tienda numero %d : ", contador );
	scanf ("%d",&utilidad);
	fflush (stdin) ;
	
	//proceso
	
	if (utilidad>2000000)
	{
      mtiendas=mtiendas+1 ;
	}
	contador=contador+1;
	
	} while(contador<6);
	
	//salida
	
	printf("\n El numero de tiendas con utilidad mayor a 2,000,000 es:  %d", mtiendas);	
	
	getch () ; 
	return 0;
}

/*
-El codigo cumple su función
-no imprime caracteres especiales
-Es legible.
-Revisó: Programadores Empedernidos
-Fecha: 13 de febrero del 2019
*/
