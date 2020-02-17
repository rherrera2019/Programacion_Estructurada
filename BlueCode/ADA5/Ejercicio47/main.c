/*
	Name: Ejercicio 47
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 10/02/20 14:45
	Description: Lee las calificaciones de 50 alumnos y determina e imprime cuantos tienen calificación mayor al promedio de grupo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define NUMALUMNOS 50

float validarCalificacion(float c);

int main(int argc, char *argv[]) {
	//Variables
	int i;
	int alumnosMayoresAlPromedio = 0;
	float calificaciones[NUMALUMNOS];
	float entrada, promedio;
	float sumCalificaciones = 0;
	
	setlocale(LC_ALL,"");
	
	//Proceso
	for(i = 0; i < NUMALUMNOS; i++){
		
		//Entrada
		printf("Alumno %d, ingrese su calificación: ", i+1);
		scanf("%f", &entrada);
		calificaciones[i] = validarCalificacion(entrada);
		sumCalificaciones += calificaciones[i];
	}
	
	promedio = sumCalificaciones/NUMALUMNOS;
	
	for(i = 0; i<NUMALUMNOS; i++){
		if(calificaciones[i] > promedio){
			alumnosMayoresAlPromedio++;
		}
	}
	
	//Salida
	printf("El numero de alumnos mayores al promedio, que es de %.2f es: %d\n", promedio, alumnosMayoresAlPromedio);
	system("pause");
	
	return 0;
}

//Funciones
float validarCalificacion(float c){
	float calificacionValidada;
	if(c<0||c>100){
		do{
			printf("Entrada inválida, intenta de nuevo: ");
			scanf("%f", &c);
		}while(c<0||c>100);
		calificacionValidada = c;
	}else{
		calificacionValidada = c;
	}
	return calificacionValidada;
}
