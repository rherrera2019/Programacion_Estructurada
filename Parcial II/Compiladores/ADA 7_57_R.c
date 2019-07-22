/*
57. E.P. que lea una matriz de N X M elementos y que encuentre e
imprima la posición de los elementos negativos.
Elaboró: Los compiladores
Ciclo utilizado: For
Fecha:13/Marzo/2019
Version 1.0

*/


#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	
	
	int F;//Filas
	int C;//Columnas
	int k=0;//bandera
	
	int i;//contador
	int j;//contador
	

	
	
	//Entrada de numero de  Filas y columnas para la matriz 
	do{
		
		printf("Dime el numero de filas: ");
		scanf("%d",&F);
		printf("Dime el numero de columnas: ");
		scanf("%d",&C);
		
		if(F>0){
			if(C>0){
				k=1;
			}else{
				printf("Las columnas no pueden ser negativas");
			}
		}else{
			printf("Las Filas no pueden ser negativas");
		}
		
		getchar();
		getchar();
		system("cls");
		
		
	} while(k==0);
	
	float Matriz[F][C];//Matriz a usar
	
	//Rellena matriz 
	for(i=0; i<F; i++){
		
		for(j=0; j<C; j++){
			
			printf("Dime el dato en la pocicion (%d,%d) de la Matriz : ",i+1,j+1);
			scanf("%f",&Matriz[i][j]);
			
			
		}
		
	}
	
	getchar();
	getchar();
	system("cls");
	
	
	//imprime Matriz
	for(i=0; i<F; i++){
		
		for(j=0; j<C; j++){
			
			if(j==0){
				printf("\n");
				
			}
			
			
			printf("\t%.2f",Matriz[i][j]);
			
			
		}
		
	}
	
	printf("\n");
	//imprime la pocicion de los negativos //Salidas
	printf("Los negativos estan en las posiciónes  ");
	
	for(i=0; i<F; i++){
		
		for(j=0; j<C; j++){
			
			if(Matriz[i][j]<0){
				printf("\n");
				printf("(%d,%d)",i+1,j+1);
				
				
			}
			
			
			
			
			
		}
		
	}
	
	
	
	return 0;
}
/*Revisión por Programadores Empedernidos.

-Mi recomendación sería que se agregue un "presiona cualquier tecla" en los getchar para que sea más entendible
para el usuario.
-El código funciona bien.
-Se cumple lo que se pide.
-El nombre de las variables es representativo.*/


