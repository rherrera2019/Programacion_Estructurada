/*Programa: SumatoriaDeFila.c
Descripción: Lee una matriz de 20 X 30 elementos y genera e
imprime un vector de 20 elementos que contenga la sumatoria de cada
fila de la matriz.
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
	float elemento[20][30], sumatoria[20], sum;
	int f, c;
	
	//ENTRADA- Lee la matriz
	FOR(f,20){
		sum=0;
		FOR(c,30){
			printf("Ingrese el elemento de la fila %i, columna %i >> ", f+1, c+1);
			scanf(" %f", &elemento[f][c]);
			//PROCESO- Realiza la sumatoria de los elementos de la fila
			sum+=elemento[f][c];
		}
		//PROCESO- Guarda la sumatoria en un vector
		sumatoria[f]=sum;
		system("cls");
	}
	
	//SALIDA- Imprime el vector generado con las sumatorias de cada fila
	printf("La sumatoria de cada fila es: ");
	FOR(f,20){
		printf("\n %f", sumatoria[f]);
	}
	
	
	
	getch();
	return 0;
}
/*
QA
El programa funciona correctamente,c odigo sencillo y legible,
secciones bien identificadas, uso de variables con nombres representativos.
Revisó:Los compiladores_Carlos Artueo Álvarez Trejo
*/
