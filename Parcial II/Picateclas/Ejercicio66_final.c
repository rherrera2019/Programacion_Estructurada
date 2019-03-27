/*
Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.0
Descripcion: Que lea una matriz de 9 X 12 elementos y que cuente todos
los elementos negativos de la misma y los cambie por ceros.
Fecha de creacion: 9/mar/2019
*/

#include <stdio.h>
#include <conio.h>

#define FILA_MAX 9
#define COL_MAX 12

int main(int argc, char *argv[]) {
	
	int Matrix[FILA_MAX][COL_MAX]; //Se define la matriz de 20x20 elementos
	int contadorNeg = 0; //Contador de elementos negativos en las filas 10 a 13
	
	/*ENTRADA*/
	
	for(int f = 0; f<FILA_MAX; f++){ //1er ciclo for que recorrera las filas de la matriz
		for(int c = 0; c<COL_MAX; c++){ //2do ciclo for que recorrera las columnas de la matriz
			printf("Ingrese el elemento del intervalo (%d,%d): ",f+1,c+1);
			scanf("%d",&Matrix[f][c]);
			
			/*PROCESO*/
				if(Matrix[f][c]<0){ //Determina si el elemento ingresado es negativo, en caso de serlo, aumentara una unidad el contador
					contadorNeg++;
					Matrix[f][c] = 0; //Cualquier elemento negativo ingresado se convertira en cero
				}
			}
		}
	
	/*SALIDA*/
	printf("\nMatriz resultante:\n");   
	for (int f = 0; f < FILA_MAX; f++) {  
		for (int c = 0; c < COL_MAX; c++) {  
			printf("%d", Matrix[f][c]); 
			printf("  "); //Espacio despues de cada columna
		}  
		printf("\n");  //Salto de linea por cada fila
	}  
	
	printf("\nEl numero de elementos negativos ingresados fue de: %d", contadorNeg);
	getch();
	
	return 0;
}
/*
QA
El programa funciona correctamente, codigo legible y sencillo,
secciones bien identificadas, es practico a la hora de probar, ya que definieron una macro 
con el tamaño de las filas y las columnas, por lo que se puede cambiar sin tener que buscar donde cambiar, pues esta distribuido
en todo el codigo.
Elaboró:Los compiladores_Carlos Arturo Álvarez Trejo.


*/
