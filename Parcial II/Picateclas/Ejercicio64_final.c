/*
Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.0.1
Descripcion: Que lea una matriz de 15 X 13 elementos y que calcule e
imprima lo siguiente:
a) El elemento menor del arreglo.
b) El total de elementos negativos de la fila 10 a la 13.
c) El mayor elemento del arreglo.
Fecha de creacion: 9/mar/2019
*/

#include <stdio.h>
#include <conio.h>

#define FILA_MAX 15
#define COL_MAX 13

int main(int argc, char *argv[]) {
	float Matrix[FILA_MAX][COL_MAX]; //Se define la matriz de 20x20 elementos
	int contadorNeg = 0; //Contador de elementos negativos en las filas 10 a 13
	
	float currentMajorElement = -9999999.99;
	float currentMinorElement = 9999999.99;
	
	/*ENTRADA*/
	/*OJO El contador inicia desde 0 por lo que internamente las filas se cuentan del 0-14 y columnas del 0-12
	para enganar al sistema imprimimos f+1 y c+1 para mostrar los intervalos normalmente y por lo tanto los if
	se condicionan desde el contador real y no el mostrado*/
	
	for(int f = 0; f<FILA_MAX; f++){ //1er ciclo for que recorrera las filas de la matriz
		for(int c = 0; c<COL_MAX; c++){ //2do ciclo for que recorrera las columnas de la matriz
			printf("Ingrese el elemento del intervalo (%d,%d): ",f+1,c+1);
			scanf("%f",&Matrix[f][c]);
			
			/*PROCESO*/
			if(Matrix[f][c]>currentMajorElement){ //Determina si el elemento de la matriz es mayor con respecto al ultimo mas grande actual
				currentMajorElement = Matrix[f][c]; //Si la condicion es cierta se sobreescribe el numero mayor actual al anterior
			}
			
			if(Matrix[f][c]<currentMinorElement){ //Determina si el elemento de la matriz es menor con respecto al ultimo mas grande negativo actual
				currentMinorElement = Matrix[f][c]; //Si la condicion es cierta se sobreescribe el numero menor actualal anterior
			}
			
			if(f>=9 && f<13){ //Determina si son las filas 10,11,12 y 13
				if(Matrix[f][c]<0){ //Determina si el elemento ingresado es negativo, en caso de serlo, aumentara una unidad el contador
					contadorNeg++;
				}
			}
		}
	}
	
	/*SALIDA*/
	printf("\nEl numero mayor de la matriz es: %.2f",currentMajorElement);
	printf("\nEl numero menor de la matriz es: %.2f",currentMinorElement);
	printf("\nLa cantidad de numeros negativos entre la fila 10 y 13 fue de: %d",contadorNeg);
	getch();
	
	return 0;
}


/*
Nombre Equipo revisado : Compiladores
Descripcion: El programa funciona correctamente, una recomendacion seria que al momento de
           imprimir los resultados del mayor y menor se deberia usar pocos ceros, con 2 ceros
           despues del punto son mas que suficientes.
Fecha: 21/mar/2019
*/
