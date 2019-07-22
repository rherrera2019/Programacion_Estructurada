/*
63. E.P. que lea una matriz de 20 X 20 elementos y que cuente e
imprima cuantos elementos igual a cero se encuentran en las primeras
10 filas.
Elaboró: Los compiladores
Ciclo utilizado: For
Fecha:13/Marzo/2019
Version 1.0


*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int t=20;//Filas y columnas
	int k=10;//Fila 10
	
	float Matriz[t][t];//Matriz
	
	int Cont=0;//contador
	
	int i;//contador
	int j;//contador
	
	
	//Entrada datos a la Matriz
	for(i=0; i<t; i++){
		
		for(j=0; j<t; j++){
			
			printf("Dime el elemento de la Matriz en la pocicion (%d,%d): ",i+1,j+1);
			scanf("%f",&Matriz[i][j]);
			
			
			
		}
		
		
	}
	
	//imprime Matriz
	for(i=0; i<t; i++){
		
		for(j=0; j<t; j++){
			
			
			
			if(j==0){
				printf("\n");
			}
			
			
			
			printf("\t%.1f",Matriz[i][j]);
			
			
			
		}
		
		
	}
	
	//uso de contador para buscar los datos en la Matriz igual a cero
	for(i=0; i<t; i++){
		
		for(j=0; j<t; j++){
			
			
			if(i<k){
				
				if(Matriz[i][j]==0){
					Cont=(Cont+1);
				}
				
				
			}
			
			
			
		}
		
		
	}
	//Salida de elementos iguales a cero
	printf("\n%d Elementos igual a cero se encuentran en las primeras %d filas.",Cont,k);
	
	
	
	return 0;
}
/*Revisión por Programadores Empedernidos.

-El código funciona bien.
-Se cumple lo que se pide.
-El nombre de las variables es representativo.*/

