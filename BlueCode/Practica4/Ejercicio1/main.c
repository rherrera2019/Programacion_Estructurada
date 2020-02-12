/*
	Name: Ejercicio I Practica 4
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 11/02/20 10:43
	Description: Programa que imprime la posicion del robot
*/

#include <stdio.h>
#include <stdlib.h>

#define MINMOVIMIENTOS 1

int validarEntrada(int entrada);

int main(int argc, char *argv[]) {
	int movimientos;
	int entrada;
	int x = 0 ,y = 0,i;
	
	printf("Ingrese el numero de movimientos que se realizara: ");
	scanf("%d", &movimientos);
	while(movimientos<MINMOVIMIENTOS){
		printf("Entrada invalida, intenta de nuevo: ");
		scanf("%d", &movimientos);
	}
	
	for(i = 0; i < movimientos ; i++){
		printf("Ingrese su movimiento(8,4,6,2): ");
		scanf("%d", &entrada);
		entrada = validarEntrada(entrada);
		if(entrada == 8){
			y++;
		}else if(entrada == 6){
			x++;
		}else if(entrada == 2){
			y--;
		}else{
			x--;
		}
	}
	
	printf("La posicion del robot despues de %d movimientos es:\n", movimientos);
	printf("X: %d\n", x);
	printf("Y: %d\n", y);
	
	
	return 0;
}

int validarEntrada(int entrada){
	int entradaValidada;
	if(entrada != 4 && entrada != 8 && entrada != 6 && entrada != 2){
		while(entrada != 4 && entrada != 8 && entrada != 6 && entrada != 2){
			printf("Entrada invalida, intenta de nuevo: ");
			scanf("%d", &entrada);
		}
		entradaValidada = entrada;
		
	}else{
		entradaValidada = entrada;
	}
	return entradaValidada;
}
