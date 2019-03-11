
#include <stdio.h>
#include <stdlib.h>
/*
50.E.P que lea un vector de 50 elementos y los imprima
Elaboró: Los compiladores
Ciclo utilizado: while
Fecha:9/Marzo/2019
Version 1.0

*/

int main() {
	int n=2;
	float elementos[n];
	float valor_Ingresado[n];
	int contador=1;
	
	
	while(contador<=n){
		printf("\n Elemento %d",contador);
		printf("\n Ingrese valor: ");
		scanf("%f",&elementos[contador]);
		valor_Ingresado[contador]=elementos[contador];
		
		contador++;
		system("cls");
	}
	contador=1;
	system("cls");
	
	printf("\n ////Valores ingresados/////");
	while(contador<=n){
		
		printf("\n #%d : %.2f",contador,valor_Ingresado[contador]);
		
		contador++;
	}
	
	
	return 0;
}

