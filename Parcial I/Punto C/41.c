/*41.- E.P. que lea las calificaciones del primer parcial de los
estudiantes de algoritmos y que calcule e imprima el promedio de todo
el grupo.
Fecha: 11/02/2019
Versión: 1.0 */

#include <stdio.h>

int main() 
{
	//ENTRADA//
	int CC,NoAlum;
	float sumCalif, calif, promedio;
	CC=0;
	sumCalif=0;
	
	printf("\n Bienvenido a tu promediador grupal");
	printf("\n ¿De cuántos alumnos es tu grupo?: ");
	scanf("%d", &NoAlum);
	//PROCESO//
	do
	{
		CC=CC+1;
		printf("Dime la calificación del primer parcial de tu alumno %d: ", CC);
		scanf("%f", &calif);
		sumCalif=sumCalif+calif;
	}while(CC!=NoAlum);  
	promedio=sumCalif/NoAlum;
	//SALIDA//
	printf("El promedio de tu grupo es de: %.2f", promedio);
	return 0;
}

/*
-El codigo cumple su función
-no imprime caracteres especiales
-Hay partes del codigo que se pueden reducir usando otros operadores ejemplo, el ++ (incremento)
-Es legible.
-Revisó: Programadores Empedernidos
-Fecha: 13 de febrero del 2019
*/
