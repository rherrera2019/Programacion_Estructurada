/* E.P. que lea el peso en gramos (máximo 5,000) y determine e imprima el menor número de pesas que hay que poner en una balanza 
(con pesos: 1 gr, 2 gr, 5 gr, 50 gr, 100 gr, 200 gr, 500 gr y 1000 gr), 
para equilibrar un determinado peso en gramos, introducido por teclado.

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
	int gramos;
	
	/*Entrada de datos para los gramos*/
	printf("\nIntrodice el peso en gramos (máximo 5000) ");
	scanf("%i", &gramos); //Leemos los gramos
	
	/*Proceso para determinar el número de pesas en relación a los gramos*/
	if (gramos <= 5000 && gramos >= 0) //Validamos que los gramos no sean mayores a 5000 o menores a 0
	{
		printf("\n\nPesas de 1000 gramos %i", gramos / 1000); //Mostramos el número de pesas de 1000 que se necesitan
		
		gramos %= 1000; //Guardamos el residuo en la variable gramos, esto se repite en toda la parte del proceso
		
		
		printf("\n\nPesas de 500 gramos %i", gramos / 500);
		
		gramos %= 500;
		
		
		printf("\n\nPesas de 200 gramos %i", gramos / 200);
		
		gramos %= 200;
		
		
		printf("\n\nPesas de 100 gramos %i", gramos / 100);
		
		gramos %= 100;
		
		
		printf("\n\nPesas de 50 gramos %i", gramos / 50);
		
		gramos %= 50;
		
		
		printf("\n\nPesas de 5 gramos %i", gramos / 5);
		
		gramos %= 5;
		
		
		printf("\n\nPesas de 2 gramos %i", gramos / 2);
		
		gramos %= 2;
		
		
		printf("\n\nPesas de 1 gramo %i", gramos);
		
	} else 
	{
		printf("\nCantidad de gramos no válida");
	}
	
	getch(); //Esperamos un caracter del teclado
	
	return 0;
}//En la información faltó poner nombre del programa y aurores. Revisado
