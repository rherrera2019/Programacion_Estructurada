/* 61. E.P. que lea las tres calificaciones parciales del semestre de cada
uno de los 50 alumnos y los almacene en una matriz. Deberá imprimir
la posición de los alumnos cuyo promedio final sea mayor al promedio
de grupo.
Equipo: SacaChispas
Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé
Fecha: 11/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

#define FILAS 5
#define COLUMNAS 10

#define X (i = 0; i < FILAS; i++)
#define Y (j = 0; j < COLUMNAS; j++)

int main() {
	
	/*Declaramos las variables*/
	int i, j;
	
	/*Declaramos la matriz*/
	float matriz_calificaciones[FILAS][COLUMNAS], sum = 0, calificacion_actual = 0, promedio_general = 0;
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for X
	{
		for Y
		{
			/*ENTRADA de datos*/
			printf("\n\nInserte la calificación 1 del alumno en la fila %i, columna %i ", i + 1, j + 1);
			scanf("%f", &calificacion_actual);
			
			sum += calificacion_actual;
			
			printf("\n\nInserte la calificación 2 del alumno en la fila %i, columna %i ", i + 1, j + 1);
			scanf("%f", &calificacion_actual);
			
			sum += calificacion_actual;
			
			printf("\n\nInserte la calificación 3 del alumno en la fila %i, columna %i ", i + 1, j + 1);
			scanf("%f", &calificacion_actual);
			
			sum += calificacion_actual;
			
			/*PROCESO para determinar el promedio de cada alumno*/
			sum /= (float)3;
			
			matriz_calificaciones[i][j] = sum;
			
			/*PROCESO para determinar el promedio general*/
			promedio_general += sum;
			
			sum = 0;
		}
	}
	
	promedio_general /= (float)(FILAS * COLUMNAS);
	
	/*SALIDA de datos*/
	printf("\n\nLas posiciones de los alumnos mayores al promedio del grupo son: ");
	for X
	{
		for Y
		{
			if (matriz_calificaciones[i][j] > promedio_general)
			{
				printf("\n\n[%i, %i]", i + 1, j + 1);
			}
		}
	}
	
	
	
	
	
	return 0;
}

/*Ps son variables con nombre muy largo pero no dejan duda de a que se refieren por lo tanto es una por otra*/
//Josue Torres
