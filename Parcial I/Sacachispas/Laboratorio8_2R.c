/* II. E.P. que lea un vector de 20 elementos que sean enteros y determine
e imprima la suma de los elementos pares y el producto de los elementos impares.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 7/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Declaramos las variables y el vector*/
	int num[20], i, sum = 0, multi = 1, cont_multi = 0;

	/*Creamos un ciclo For para la lectura de los datos*/
	for (i = 0; i < 20; i++)
	{
		/*ENTRADA de datos*/
		printf("\n\nIngrese el número en la posición %i: " , i+1);
		scanf("%i", &num[i]);
		
		/*PROCESO*/
		/*Usamos la función MOD para determinar si el número es par*/
		if (num[i] % 2 == 0)
		{
			sum += num[i];
		}
		else 
		{
			multi *= num[i];
			
			cont_multi++;
		}
	}
	
	/*Si no hay números impares, la multiplicación debe ser 0*/
	if (cont_multi == 0)
	{
		multi = 0;
	}
	
	/*SALIDA de datos*/
	printf("\n\nLa suma de los números pares es: %i", sum);
	
	printf("\n\nLa multiplicación de los números impares es: %i", multi);
	
	getch();
	
	return 0;
}
/*Funciona correctamente para todos los valores
Revisado por: Punto C(Erick Cárdenas)*/
/*Entrada: 1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2 (10 unos y 10 dos)
salida: la suma es 20 y la multiplicacion es 1*/
