//Programa que lee las utilidades mensuales de una cadena de 5 tiendas
//y que determina e imprime cuantas tiendas tuvieron utilidades mayor a
//los $ 2,000,000.
//Autor: Programadores Emperdernidos. 
//Fecha: 10/02/19
//Version: 2.0.
//Nombre: 39.c
#include <stdio.h>

int main(){
	//Inicializacion de las variables.
	int Contador=1, Acumulador=0;
	float Utilidades;
	
	//Proceso de lectura de las utilidades
	while(Contador<=5){
		printf("Tienda no. %d\n", Contador);
		printf("Ingrese las utilidades > ");
		scanf("%f", &Utilidades);
		printf("\n");
		
		if (Utilidade s> 2000000){
			Acumulador++;
		}
		
		Contador++;
	}
	
	//Salida
	printf("%d tiendas tuvieron utilidades mayor a $2,000,000.", Acumulador);
	
	return 0;
}

/*
El programa funciona correctamente. Sólo creo que las utilidades deberían ser float en vez de int, pues estamos hablando de 
cantidades de dinero y no siempre son exactas.
Revisó: Picateclas
*/
