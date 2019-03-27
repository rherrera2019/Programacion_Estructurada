/*Programa que solicita al usuario la dimensión de una matriz cuadrada de n x m elementos de tipo real, 
así como lee  e imprime dicho arreglo. Posteriormente, solicita la posición de un elemento dentro de la matriz y procede a 
dividir todos los elementos, entre dicho elemento ubicado en la posición proporcionada. 
Por último, imprime el estado final de la matriz.  Y se valida que no se realicen divisiones entre cero. */

#include <stdio.h>

int main(){
	//Declaración de variables
	int N, fila, columna, i, j, k, l; 
	float divisor;
	printf("Ingresa el tamanio de la matriz> "); //Lectura del tamaño de la matriz
	scanf("%d", &N);
	float matriz[N][N]; //asignación del tamaño de la matriz
	float segundaMatriz[N][N]; //segunda matriz que se imprime hasta el final
	
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){ //Entrada de datos.
			printf("\nIngresa el elemento [%d,%d]> ", i+1, j+1);
			scanf("%f", &matriz[i][j]);
		}
	}
	
	printf("\n");
	for(i=0; i<N; i++){ //Impresión de la matriz principal
		for(j=0; j<N; j++){
			printf("  %f  ", matriz[i][j]);
		}
		printf("\n\n");
	}
	

	printf("\nIngrese el # de fila> "); //Petición de una posición.
	scanf("%d", &fila);
	printf("\nIngrese el # de columna> ");
	scanf("%d", &columna);
		
	if(matriz[fila-1][columna-1]!=0){ //Se valida que sea diferente de cero.
		divisor=matriz[fila-1][columna-1];
		printf("\n%f\n", divisor);
	}else{
		printf("\nEl elemento elegido es cero. No se puede dividir entre cero.");
		printf("\nIngrese otro n\243mero.\n\n");
	}

	

	for(k=0; k<N; k++){ //asignación de los valores de la segunda matriz.
		for(l=0; l<N; l++){
			segundaMatriz[k][l]=(matriz[k][l]/divisor);
		}
	}	
	
	for(k=0; k<N; k++){ //Impresión de la sgunda matriz.
		for(l=0; l<N; l++){
			printf("  %f  ", segundaMatriz[k][l]);
		}
		printf("\n\n");
	}
	

}
/*
-El codigo funciona correctamente
-Identifica correctamente el numero que servirá para dividir los elementos
-realiza los calculos de forma correcta
-Documentado correctamente
-Imprime correctamente la matriz las 2 veces que se pide
Revisó:PuntoC*/
