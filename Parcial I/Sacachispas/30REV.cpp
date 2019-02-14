/* E.P. que lea un número entero obtenido al lanzar un dado de seis caras e imprimir 
el número en letras de la cara opuesta. En las caras opuestas de un dado de seis caras están los números: 1-6, 2-5 y 3-4. 
Si el número del dado capturado es menor que 1 o mayor que 6, se mostrará: “Un DADO no tiene ese número”. (utilizar switch)

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
	int num_dado;
	
	/*Pedimos la entrada*/
	printf("\nInserté el número del dado ");
	scanf("%i", &num_dado); //Leemos el número del dado
	
	switch(num_dado) //Evaluamos dicho número en el switch
	{
	case 1: printf("\nLa cara opuesta es seis"); //Salida según el número del dado
		break;
		
	case 2: printf("\nLa cara opuesta es cinco");
		break;
		
	case 3: printf("\nLa cara opuesta es cuatro");
		break;
		
	case 4: printf("\nLa cara opuesta es tres");
		break;
		
	case 5: printf("\nLa cara opuesta es dos");
		break;
		
	case 6: printf("\nLa cara opuesta es uno");
		break;
		
	default: printf("\nUn DADO no tiene ese número"); //El número del dado no fue válido
 
	}
	
	getch(); //Esperamos un caracter del teclado
	
	return 0;
}

/*El programa funciona correctamente, sin embargo no resuelve el problema propuesto: la salida imprime el número DE letras 
del número en la cara opuesta, pero lo que se debía imprimir es el número EN letras de la cara opuesta.
Así, si el número obtenido era 1, la salida debió ser "La cara opuesta es seis".
El código está bien dividido en secciones, pero no tiene los nombres de autores en el encabezado.*/
