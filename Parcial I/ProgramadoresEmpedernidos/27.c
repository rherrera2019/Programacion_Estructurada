
//E.P. que lea el peso en gramos (máximo 5,000) y determine e
//imprima el menor número de pesas que hay que poner en una balanza
//(con pesos: 1 gr, 2 gr, 5 gr, 50 gr, 100 gr, 200 gr, 500 gr y 1000 gr),
//para equilibrar un determinado peso en gramos, introducido por
//teclado.

//Autores = programadores empedernidos.
#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(){
	//Variable del peso
	int peso;
	
	//lee el peso
	printf("cu%cl es el peso\n", 160);
	scanf("%d", &peso);
	
	//comprueba si es menor o igual a 5000g
	if (peso <= 5000){
		if(peso >= 1000){	//verifica si esta en el rango para hacer una division con residuo... en dado caso de que no, salta a la siguiente
			printf("Son un total de %d pesas de 1000g\n", peso/1000);
			peso = peso%1000;
		}
		if(peso >= 500){
			printf("Son un total de %d pesas de 500g\n", peso/500);
			peso = peso%500;
		}
		if(peso >= 200){
			printf("Son un total de %d pesas de 200g\n", peso/200);
			peso = peso%200;
		}
		if(peso >= 100){
			printf("Son un total de %d pesas de 100g\n", peso/100);
			peso = peso%100;
		}
		if(peso >= 50){
			printf("Son un total de %d pesas de 50g\n", peso/50);
			peso = peso%50;
		}
		if(peso >= 5){
			printf("Son un total de %d pesas de 5g\n", peso/5);
			peso = peso%5;
		}
		if(peso >= 2){
			printf("Son un total de %d pesas de 2g\n", peso/2);
			peso = peso%2;
		}
		if(peso >= 1){
			printf("Son un total de %d pesas de 1g\n", peso/1);
			peso = peso%1;
		}
	}
	else{
		printf("El peso debe ser menor a 5000 gramos");
	}
	

	return 0;
}
