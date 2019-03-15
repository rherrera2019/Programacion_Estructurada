#include <stdio.h>

// declaracion de constantes
#define SIZE 10
/*
Nombre: laboratorio8_1.c
Problema: La MODA de un vector, es aquél número x del arreglo que se repite con mayor frecuencia. De tal forma, en caso de existir 
más de un número que se repite con igual frecuencia máxima, entonces no existe la moda. E.P. que lea un vector de 10 elementos 
que sean enteros y determine la moda del arreglo. Si no la hay, deberá imprimir no existe la moda. 

Autor: Programadores Empedernidos
Fecha: 8 de febrero del 2019
*/

int main(){
	// declaracion de variables
	int numeros[SIZE], frecuencias[SIZE], cont, i, j, k, l, h, modaRep=0, moda, posModa=0;
	
	//for para leer los valores del vector principal
	for(i=0; i<SIZE; i++){
		printf("Ingresa el dato #%d> ", i+1);
		scanf("%d", &numeros[i]);
	}
	//for para contar las veces que se repite un numero
	printf("\n[Frecuencias de cada numero desde su posicion: ");
	for(j=0; j<SIZE; j++){
		cont=0;
		for(k=j; k<SIZE; k++){
			if(numeros[j] == numeros[k]){
				cont++;
			}
			
		}
		frecuencias[j]=cont;
		printf(" %d ", frecuencias[j]);
	}
	printf("]\n");
	//for para ver cual es la moda 
	moda = frecuencias[0];
	for(l=1; l<SIZE; l++){
		if(moda < frecuencias[l]){
			moda = frecuencias[l];
			posModa = l;
		}
	}
	//for para verificar que no haya modas repetidas (el contador no debe superar la cantidad de 1)
	for(h=0; h<SIZE; h++){
		if(moda == frecuencias[h]){
			modaRep++;
		}	
	}
	
	//imprimir la moda si es que existe
	if(modaRep==1){
		printf("\nLa moda es %d, con un total de %d repeticiones", numeros[posModa], moda);
	}
	else{
		printf("\nNo hay moda");
	}
	return 0;
}
/*
Revisado por los compiladores: Jafet Alejandro Fernandez Martinez
fecha: 11/03/2019

1.- Falla con flotante 
2._No imprime la moda
3.-No imprime el numero de veces que se repite solo la modo 

pobado con 5,4,4,4,4. Dice que No hay moda 





z*/


