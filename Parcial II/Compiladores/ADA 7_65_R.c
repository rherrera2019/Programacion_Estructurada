/*
65. E.P. que lea dos matrices de M X N elementos y que determine e
imprima si la diagonal principal de la primera es igual a la diagonal
principal de la segunda
Elaboró: Los compiladores
Ciclo utilizado: For
Fecha:13/Marzo/2019
Version 1.0


*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	
	int F;//Filas
	int C;//columnas
	int k=0;//bandera
	
	
	int i;//contador
	int j;//contador
	
	int b=1;//bandera
	
	
	
	//Asigno filas y columnas e igual se valida que sea cuadrada 
	do{
		
		printf("Dime el numero de filas: ");
		scanf("%d",&F);
		printf("Dime el numero de columnas: ");
		scanf("%d",&C);
		if(F==C){
			
			if(F>0){
				
				
				k=1;
				
				
			}else{
				
				printf("Dato no valido");
			}
		}else{
			
			printf("Debe ser iguales paraque sea una matriz cuadrada y tenga diagonal");
		}
		
		getchar();
		getchar();
		system("cls");
		
		
	} while(k==0);
	
	
	
	float Matriz[F][C];//Matriz 1
	float BMatriz[F][C];//Matriz 2
	
	//Entrada datos de Matriz 1
	for(i=0; i<F; i++){
		
		for(j=0; j<C; j++){
			
			printf("Dime el elemento de la Matriz en la pocicion (%d,%d): ",i+1,j+1);
			scanf("%f",&Matriz[i][j]);
			
			
			
		}
		
		
	}
	
	
	getchar();
	getchar();
	system("cls");
	
	printf("\n\nCambiamos de Matriz\n\n");
	//Entrada datos Matriz 2
	for(i=0; i<F; i++){
		
		for(j=0; j<C; j++){
			
			printf("Dime el elemento de la Matriz dos en la pocicion (%d,%d): ",i+1,j+1);
			
			scanf("%f",&BMatriz[i][j]);
			
			
			
		}
		
		
	}
	
	//compara diagonales de las Matriz1 y la Matriz 2 
	for(i=0; i<F; i++){
		
		for(j=0; j<C; j++){
			
			if(i==j){
				
				if(BMatriz[i][j]==Matriz[i][j]){
					
					
					
				}else{
					b=2;//en caso que no sean iguales
				}
				
			}
			
			
			
		}
		
		
	}
	
	//decide respecto a la bandera si son iguales o no 
	//salida
	switch(b){
		
	case 1:
		printf("Si son iguales");
		
		break;
		
	case 2: 
		printf("No son iguales");
		break;
	default:
		printf("Holi jajaj ");
		
	}
	
	
	
	
	
	
	
	return 0;
}

/* Revisión por Programadores Empedernidos.

-No pusieron el break; en el caso 2, se imprime el "holi" xD.
-El código es legible y está bien documentado.
-Funciona bien. 
*/
