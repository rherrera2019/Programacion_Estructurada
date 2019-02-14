/* 41.- E.P. que lea las calificaciones del primer parcial de los
estudiantes de algoritmos y que calcule e imprima el promedio de todo
el grupo.

Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé
Fecha: 7/feb/2019
Version: 1.0 */

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	
	/*Creamos las variables necesarias para el programa*/
	int cont_estudiantes, ciclo;
	
	float sumatoria, calificacion_actual;
	
	char validar[2]; //Nos sirve para saber si hay más estudiantes (SI o NO)
	
	/*Inicializamos el contador para los estudiantes*/
	cont_estudiantes = 1;
	sumatoria = 0;
	calificacion_actual = 0;
	ciclo = 1; /*No sabemos el número de estudiantes que hay, esta variable nos ayuda a romper el ciclo cuando ya no hayan más*/
	
	/*Creamos el ciclo do-while para la lectura de los estudiantes*/
	do
	{
		/*ENTRADA DE DATOS*/
		printf("\n\nInserte la calificación del %i° alumno ", cont_estudiantes++);
		
		do //Usamos un do-while para verificar que la calificación no sea negativa
		{
			scanf("%f", &calificacion_actual);
			
			if (calificacion_actual < 0)
			{
				printf("\n\nInsertó una calificación NO válida, inténtalo otra vez\n\nCalificación ");
			}
			
		} while (calificacion_actual < 0);
		
		/*PROCESO para determinar el promedio general*/
		sumatoria += calificacion_actual; //Sumatoria total de la calificación de los estudiantes los estudiantes
		
		printf("\n\n¿Hay más alumnos? (SI o NO) "); //Preguntamos si hay más alumnos
		fflush(stdin); //Evitamos la lectura del enter
		gets(validar);
		
		if (strcmp(validar, "no") == 0)
		{
			ciclo = 0; //Si no hay más alumnos el ciclo se romperá
		}
		
	} while (ciclo);
	
	/*SALIDA DE DATOS*/
	printf("\n\nEl promedio general es: %.2f", (float)sumatoria/(cont_estudiantes - 1));
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}

/*
Revisado por: Los compiladores

El programa funciona bien , el codigo es ententible
No se valido para no poder ingresar calificaciones negativas 


*/
