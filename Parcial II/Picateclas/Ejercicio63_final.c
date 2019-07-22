/*
Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.0.1
Descripcion: Que lea una matriz de 20 X 20 elementos y que cuente e
imprima cuantos elementos igual a cero se encuentran en las primeras
10 filas.
Fecha de creacion: 9/mar/2019
*/

#include <stdio.h>
#include <conio.h>

#define FILA_MAX 20
#define COL_MAX 20

int main(int argc, char *argv[]) {
	
	float Matrix[FILA_MAX][COL_MAX]; //Se define la matriz de 20x20 elementos
	int contadorCeros = 0; //Contador de elementos iguales a cero en las primeras 10 filas
	
	/*ENTRADA*/
	for(int f = 0; f<FILA_MAX; f++){ //1er ciclo for que recorrera las filas de la matriz
		for(int c = 0; c<COL_MAX; c++){ //2do ciclo for que recorrera las columnas de la matriz
			printf("Ingrese el elemento del intervalo (%d,%d): ",f+1,c+1);
			scanf("%f",&Matrix[f][c]);
			
			/*PROCESO*/
			if(f<10){ //Determina si son las primeras 10 filas
				if(Matrix[f][c]==0){ //Determina si el elemento ingresado es igual a cero, en caso de serlo, aumentara una unidad el contador
					contadorCeros++;
				}
			}
		}
	}
	
	/*SALIDA*/
	printf("\nEl numero de elementos iguales a cero de las primeras 10 filas es de: %d",contadorCeros);
	getch();
	
	return 0;
}

/*
Nombre Equipo revisado: Compiladores
Descripcion: El programa esta correcto, tiene los aspectos que el profesor solicita
y funciona de la manera correcta
Fecha: 21/mar/2019
*/
