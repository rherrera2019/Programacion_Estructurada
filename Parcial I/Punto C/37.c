#include <stdio.h> 
#include <conio.h>
#include <math.h>

/*Ejercicio 37: cúantos números positivos (while) 
Descripción: E.P. que lea 100 números y que cuente e imprima cuantos son
positivos. 
Fecha: 11/02/2019
Versión: 1.0 */

int main () 
{
    //declaración de variables 
	float n ; 
	int cont, positivos ;
	cont=0;
	positivos=0;
	
	//Entrada 
	while (cont<3) 
	{
		cont=cont+1; 
		printf ("\n Dame el numero %d:  ", cont ) ;
		scanf ("%f",&n) ;
		
		//proceso
		if (n>=0) {
			positivos=positivos+1;
		}
	}
	
	//Salida
	printf ("\n La  cantidad de numeros positivos es : %d ", positivos ) ;  
	getch (); 
	return 0 ; 
}

/*
-El codigo cumple su función
-Hay partes del codigo que se pueden reducir usando otros operadores ejemplo, el ++ (incremento)
-Es legible y entendible.
-Revisó: Programadores Empedernidos
-Fecha: 13 de febrero del 2019
*/
