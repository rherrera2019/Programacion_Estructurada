/*
64. E.P. que lea una matriz de 15 X 13 elementos y que calcule e
imprima lo siguiente:
a) El elemento menor del arreglo.
b) El total de elementos negativos de la fila 10 a la 13.
c) El mayor elemento del arreglo.
Elaboró: Los compiladores
Ciclo utilizado: For
Fecha:13/Marzo/2019
Version 1.0

*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int p=15;//Filas
	int q=13;//columnas
	int r=10;//control
	int w=13;//control
	
	float Matriz[p][q];//Matriz
	
	float tronomenor=100000000;// Trono menor
	float tronomayor=0;//Trono mayor
	int contneg=0;//contador negativos
	
	int i;//pues i 
	int j;//pues j 
	
	
	//Entrada datos de la matriz
	for(i=0; i<p; i++){
		
		for(j=0; j<q; j++){
			
			printf("Dime el elemento de la Matriz en la pocicion (%d,%d): ",i+1,j+1);
			scanf("%f",&Matriz[i][j]);
			
			
			
		}
		
		
	}
	
	
	for(i=0; i<p; i++){
		
		for(j=0; j<q; j++){
			
			//compara para el trono el numero mas grande
			if(Matriz[i][j]>tronomayor){
				tronomayor=Matriz[i][j];
			}
			//compara para el trono el numero mas pequeño
			if(Matriz[i][j]<tronomenor){
				tronomenor=Matriz[i][j];
			}
			
			//checa cuantos negativos hay entre las filas 10 y 13
			if(i>(r-1)||i<(w+1)){
				
				
				//cuenta los negativos
				if(Matriz[i][j]<0){
				contneg=(contneg+1);
				}
				
				
				
				
				
				
			}
			
			
			
			if(j==0){
				printf("\n");
			}
			
			
			//imprime matriz
			printf("\t%.1f",Matriz[i][j]);
			
			
			
		}
		
		
	}
	//salidas
	printf("\n");
	printf("\nEl dato menor en la matriz es: %.2f",tronomenor);
	printf("\nEl dato mayor en la matriz es: %.2f",tronomayor);
	printf("\nEl total de elementos negativos de la fila %d a la %d es: %d",r,w,contneg);
	
	
	
	
	
	
	
	return 0;
}
/*Revisión por Programadores Empedernidos.

-Tuvieron un error en la línea 97, no llamaron bien a la variable, fuera de eso, el programa
funciona bien si se corrige el error.
-El nombre de las variables es representativo.*/

