/*38. E.P. que lea el nombre, el sueldo y el número de hijos de los 20
empleados de la tlapalería “El Sapo Verde”, y que determine e imprima el nombre 
de los empleados con salario mayor a $ 1,000.- y que
tengan entre 3 y 7 hijos.
Fecha: 11/02/2019
Versión: 1.0 */

#include <stdio.h>

int main() 
{
	//Entrada
	char Nombre[10] ;
	float S;
	int NH,CC;
	CC=0;
	//Proceso
	while (CC<20) {
		CC=CC+1;
		printf("\n\n ¿Cuál es tú nombre?: ");
		scanf ("%s", &Nombre);
		printf("\n ¿Cuál es sueldo?: ");
		scanf ("%f", &S);
		printf("\n ¿Cuántos hijos tienes?: ");
		scanf ("%d", &NH);
		if (S>1000 && NH>3 && NH<7)
		{
			//salida
		printf("\n\n -El empleado con sueldo mayor a 1000 y que tenga de 4 a 6 hijos se llama: %s", Nombre);
		}
		}
	return 0;
	}
	
	
/*
-no imprime caracteres especiales
-El nombre de las variables no es representativo y confunde a primera vista.
-El programa pedía que se imprima el nombre de los empleados y su código solo imprime el nombre de un empleado,
sin embargo el código funciona.
-Hay partes del codigo que se pueden reducir usando otros operadores ejemplo, el ++ (incremento)
-Es legible.
-Revisó: Programadores Empedernidos
-Fecha: 13 de febrero del 2019
*/
