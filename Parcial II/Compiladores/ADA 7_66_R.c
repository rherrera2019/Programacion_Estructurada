#include <stdio.h>
	/*
	66.E.P que lea una matriz de 9 X 12 elementos y que cuente todos
	los elementos negativos de la misma y los cambie por ceros.
	Ciclo utilizado: For
	Fecha:13/Marzo/2019
	Version 1.0
	
	*/
	
int main() {

	/*VARIABLES*/
	
	int fila,columna;
	float Matriz[9][12]; //matriz para guardar los elementos a ingresar
	
	/*DATOS ENTRADA*/
	for(fila=1;fila<=9;fila++){ //filas de la matriz
		for(columna=1;columna<=12;columna++){ //columnas de la matriz
			printf("Ingrese el valor de la posicion (%d,%d): ",fila,columna);
			scanf("%f",&Matriz[fila][columna]);
		}
		
	}
	
	/*DATOS SALIDA*/
	int i,j;
	printf("\n Matriz original: "); //se imprime la matriz ingresada para que se note el cambio de valores
	printf("\n\n ");
	for(i=1;i<=9;i++){ //filas de la matriz
		
		for(j=1;j<=12;j++){ //columnas de la matriz
			printf(" %.2f   ",Matriz[i][j]);
		
		}
		
		printf("\n ");
	}
	/*Proceso para validar si es un numero negativo y cambiar su valor por 0*/
	for(fila=1;fila<=9;fila++){ //filas de la matriz
		for(columna=1;columna<=12;columna++){ //columnas de la matriz
			if(Matriz[fila][columna]<0){ //si el valor de una posicion es menor que 0, es decir es negativa se hace lo que sigue
				Matriz[fila][columna]=0; //se hace el cambio, ahora su valor es 0
				
			}
		}
		
	}
	
	/*DATOS SALIDA*/
	int x,y;
	printf("\n Matriz cambiada: ");
	printf("\n\n ");
	for(x=1;x<=9;x++){ //filas de la matriz
		
		for(y=1;y<=12;y++){ //columnas de la matriz
			printf(" %.2f   ",Matriz[x][y]);
			
		}
		
		printf("\n ");
	}
	
	
	return 0;
}

/*Revisión por: Programadores empedernidos.
-El código funciona bien.
-Las variables tienen nombres representativos.
-Se tomó en cuenta los valores flotantes. */

