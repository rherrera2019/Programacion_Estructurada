/*
II. E.P. que lea un vector de 20 elementos que sean enteros y determine e 
imprima la suma de los elementos pares y el producto de los elementos impares.

Elaboró: Los Compiladores
fecha:06/Mar/2019
versión 1.0

*/

#include <stdio.h>

int main() {
	
	int elementos[20];
	int sum_Pares,prod_Impares;
	sum_Pares=0;
	prod_Impares=0;
	int conpares,conimpares,producto;
	producto=1;
	
	conpares=conimpares=0;
	
	int i=0;
	for(i=1;i<=20;i++){
		printf("\n Ingrese el valor para el elemento %d : ",i);
		scanf("%d",&elementos[i]);
		if(elementos[i]%2==0){
			sum_Pares=sum_Pares+elementos[i];
			conpares++;
		}else {
		   prod_Impares= elementos[i]*producto;
		   producto=prod_Impares;
		   conimpares++;
		}
	}
	
	printf("\n N%cmeros pares ingresados: %d",163,conpares);
	printf("\n N%cmeros impares ingresados: %d",163,conimpares);
	
	printf("\n sumatoria de los pares: %d",sum_Pares);
	printf("\n producto de los impares: %d ",prod_Impares);
	
	return 0;
}

