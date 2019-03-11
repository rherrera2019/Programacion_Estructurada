/* 46. E.P. que lea 200 números y que calcule e imprima cuantos son
negativos, cuantos son positivos y cuantos fueron iguales a cero
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 13/feb/2019
Version: 1.0 (Usando macros sencillos)*/

#include <stdio.h>
#include <conio.h>

#define ALUMNOS 200

int main() {
	
	/*Creamos las variables necesarias para el programa*/
	int cont_numeros, cont_positivo, cont_negativo, cont_cero;
	
	float numero_actual;
	
	/*Inicializamos el contador para los empleados*/
	cont_numeros = 1;
	cont_positivo = 0;
	cont_negativo = 0;
	cont_cero = 0;
	
	
	/*Creamos el ciclo for para la lectura de los 100 empleados*/
	
	for (cont_numeros = 1; cont_numeros <= ALUMNOS; cont_numeros++)
	{
		/*ENTRADA DE DATOS*/
		printf("\n\nInserte el %i° número ", cont_numeros);
		scanf("%f", &numero_actual);
		
		/*PROCESO DE LOS DATOS*/
		if (numero_actual > 0)
		{
			cont_positivo++;
			
		} else if (numero_actual < 0)
		{
			cont_negativo++;
			
		} else 
		{
			cont_cero++;
		}
	}
	
	/*SALIDA DE DATOS*/
	printf("\n\nLa cantidad de positivos es: %i", cont_positivo);
	printf("\nLa cantidad de negativos es: %i", cont_negativo);
	printf("\nLa cantidad de ceros es: %i", cont_cero);
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}
/* Calificó: Punto C
-Los comentarios hacen referencia a otro ejercicio
-El programa funciona correctamente: Al cambiarlo a 10 numeros e 
ingresar los valores 2,7,4,6.4,0,-4.8,-55,0,51,0 nos da 2 ceros,2 negativos 
y 6 positivos
-Buena idea al colocar el (°) para pedir el número
-El macro funciona bien pero el nombramiento hace referencia a otro problema
