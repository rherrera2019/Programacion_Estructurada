/* E.P. que determine e imprima si el carácter código asociado a un 
código introducido por teclado, corresponde a un carácter 
alfabético, dígito, de puntuación, especial o no imprimible.

Elaborado por:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 31/ene/2019
Version: 1.0 */

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Declaramos las variables necesarias para el programa*/
	char caracter;
	
	/*Entrada del dato (se procesará dicho caracter dependiendo de su código ASCII))*/
	printf("\nInserte un caracter del teclado ");
	scanf("%c", &caracter);
	
	/*Proceso para determinar cuál tipo de caracter es dependiendo de su código ASCII*/
	if (caracter >= 48 && caracter <= 57)
	{
		printf("\nInsertó un número"); //Mostramos la salida correspodiente
		
	} else if ((caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122)) 
	{
		printf("\nInsertó un caracter alfebético"); //Mostramos la salida correspodiente
		
	} else if ((caracter >= 32 && caracter <= 34) || (caracter >= 44 && caracter <= 46) || (caracter >= 58 && caracter <= 59))
	{
		printf("\nInsertó un caracter de puntuación"); //Mostramos la salida correspodiente
		
	} else if (caracter >= 32 || caracter <= 254) 
	{
		printf("\nInsertó un caracter especial"); //Mostramos la salida correspodiente
		
	} else 
	{
		printf("\nInsertó un caracter no imprimible"); //Mostramos la salida correspodiente
	}
	
	getch(); //Esperamos un caracter del teclado
	
	return 0;
}//En la información faltó poner nombre del programa y aurores.Revisado
