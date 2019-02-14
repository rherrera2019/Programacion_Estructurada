/* E.P. que determine e imprima la calificación final de un alumno del curso “Programación Estructurada”. 
El desglose de dicha evaluación está en escala 100 y tiene los siguientes porcentajes: 40%, dos exámenes parciales, 
30%, tareas y trabajos,20%, proyecto final y 10%, participación en clase.

Elaborado por:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 31/ene/2019
Version: 1.0rev
Revisado por: Equipo Picateclas
Observaciones:  El programa cumple con los requisitos dados, buen uso de comentarios, funciona correctamente.
*/


#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Declaramos las variables necesarias para el programa*/
	float calif_parcial1, calif_parcial2, calif_tareas, calif_parciales, calif_proyecto, calif_participacion;
	
	/*Entrada de datos para los parciales*/
	printf ("\nInserte la calificación del primer parcial ");
	scanf("%f", &calif_parcial1);
	
	printf ("\nInserte la calificación del segundo parcial ");
	scanf("%f", &calif_parcial2);
	
	/*Proceso para determinar su porcentaje en relación con la calificación final*/
	calif_parciales = (float)(calif_parcial1 + calif_parcial2) * 40 / 200;
	
	
	/*Entrada de datos para las tareas y trabajos*/
	printf ("\nInserte la calificación de las tareas y trabajos ");
	scanf("%f", &calif_tareas);
	
	/*Proceso para determinar su porcentaje en relación con la calificación final*/
	calif_tareas *= (float) 30 / 100;
	
	
	/*Entrada de datos para el proyecto final*/
	printf ("\nInserte la calificación del proyecto final ");
	scanf("%f", &calif_proyecto);
	
	/*Proceso para determinar su porcentaje en relación con la calificación final*/
	calif_proyecto *= (float) 20 / 100;
	
	
	/*Entrada de datos para la participación*/
	printf ("\nInserte la calificación de la participación ");
	scanf("%f", &calif_participacion);
	
	/*Proceso para determinar su porcentaje en relación con la calificación final*/
	calif_participacion *= (float) 10 / 100;
	
	/*Salida del porcentaje final según lo obtenido*/
	printf ("\nLa calificación final en base a 100 es: %.2f", calif_parciales + calif_tareas + calif_proyecto + calif_participacion);
	
	getch();
	
	return 0;
}

