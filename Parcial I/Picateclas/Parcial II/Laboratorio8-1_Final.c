/*
Programa: Moda.C
Nombre equipo: Picateclas
Descripción: Lee un vector de 10 elementos que sean enteros y determine la moda del arreglo. 
Si no la hay, deberá imprimir no existe la moda. 
Version: 1.1
Fecha de creación: 6/mar/2019
*/

#include <stdio.h>
#include <conio.h>

//CONSTANTES
#define k 10

int main(int argc, char *argv[]) {
	
	//Se define el arreglo de elementos
	int elementos[k], moda[k]; 
	//VARIABLES
	int contador, trono, bandera, tronomoda;
	trono=0;
	tronomoda=0;

	
	//ENTRADA- leer vector
	for(int i=1; i<=k; i++){
		printf("Ingrese el elemento %d del arreglo: ", i);
		scanf(" %d", &elementos[i]);
	}
	
	//PROCESO- comparar los elementos del arreglo para saber cuántas veces se repiten
	for(int i=1; i<=k; i++){
		contador=0;
		for(int j=1; j<=k; j++){
			if(elementos[i]==elementos[j]){
				contador++;
			}
		}
		moda[i]=contador;
	}
	
	//PROCESO- determina la mayor frecuencia entre los datos
	for(int i=1; i<=k; i++){
		if(moda[i]>tronomoda){
			tronomoda=moda[i];
			trono=elementos[i];
		}
	}

	//PROCESO- leer la cantidad de veces que se repiten los elementos(almacenada en el nuevo vector) y determinar si existe la moda o no
	for(int i=1; i<=k; i++){
		if(tronomoda==moda[i]){
			if(trono==elementos[i]){
				bandera=1;
			}
			else{
				bandera=2;
			}
		}
	}
	
	
	//PROCESO- si el arreglo guarda un solo valor en todas las posiciones, lo toma como moda
	int contador_iguales;
	for(int i=1; i<=k; i++){
		if(elementos[1]==elementos[i])
			contador_iguales++;
	}
	if(contador_iguales==10){
		bandera=1;
	}
	
	//imprimir resultado
	switch(bandera){
	case 1: 
		//SALIDA
		printf("\nLa moda es %d.", trono);
		break;
	case 2:
		//SALIDA
		printf("\nNo existe moda.");
		break;
	}
	
	getch();
	return 0;
}

/*Funciona bien*/
//Revisado por Abigael Arjona
