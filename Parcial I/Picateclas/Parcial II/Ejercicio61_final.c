/*Programa: AlumnosDestacados.c
Descripción: Lee las tres calificaciones parciales del semestre de cada
uno de los 50 alumnos y los almacena en una matriz. Imprimir
la posición de los alumnos cuyo promedio final sea mayor al promedio
de grupo.
Autor: Picateclas
Integrantes:
-López Madera Fernanda Jacqueline
-Durán Matos Juan José
-Gonzalez Bautista Noé Alejandro
Versión: 1.0
Fecha de creación: 13/marzo/2019*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//MACROS
#define FOR(A,B) for(A=0; A<B; A++)

int main(int argc, char *argv[]) {
	//VARIABLES
	float promedios[50][4], prom_gral=0, sum=0;
	int f, c;
	
	//ENTRADA- lee las calificaciones, almacenándolas en la matriz
	FOR(f,50){
		printf("\nAlumno %i", f+1);
		FOR(c,3){
			do{
			printf("\nCalificación del parcial %i >> ", c+1);
			scanf(" %f", &promedios[f][c]);
			if(promedios[f][c]<0){
				printf("\nCalificación no válida. Ingrese de nuevo.\n");
			}
			}while(promedios[f][c]<0);
			//PROCESO- guarda la calificación en un sumador que servirá para calcular el promedio grupal
			sum+=promedios[f][c];
		}
		//PROCESO- calcula el promedio del alumno
		promedios[f][4]=(promedios[f][0]+promedios[f][1]+promedios[f][2])/3;
		if(f==9||f==19||f==29||f==39){
			system("cls");//limpia pantalla cada 10 alumnos
		}
	}
	//PROCESO- calcula el promedio del grupo
	prom_gral=sum/150;
	
	system("cls");
	//SALIDA- Imprime las posiciones de los alumnos cuyo promedio supera al del grupo
	printf("\nAlumnos con promedio final mayor al promedio de grupo: ");
	FOR(f,50){
		if(promedios[f][4]>prom_gral){
			printf("\nAlumno %i.", f+2);
		}
	}
	
	getch();
	return 0;
}
/*
El programa permite el ingreso de calificaciones negativas, fuera de ello
funciona correctamenmte,secciones bien identificadas y codigo sencillo,
buena idea la de limpiar la pantalla cada determinado numero de iteraciones.
Revisó:Los compiladores_Carlos Arturo Álvarez Trejo
*/

