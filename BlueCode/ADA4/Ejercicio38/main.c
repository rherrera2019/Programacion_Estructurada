/*
	Name: Ejercicio 38
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 08/02/20 12:29
	Description: E.P.  que  lea  el  nombre,  el  sueldo  y  el  número  de  hijos  de  los  20 empleados de la tlapalería “El Sapo Verde”, y que determine e imprima
	el  nombre  de  los  empleados  con  salario  mayor  a  $  1,000.-y  quetengan entre 3 y 7 hijos.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

float leerSueldo();
int leerNumHijos();


int main(int argc, char *argv[]) {
	char nombre[MAX];
	float sueldo;
	int numHijos;
	int tienenEntreTresYSiete = 0;
	int i = 0;
	
	while(i<20){
		
		printf("Ingrese su nombre:");
		scanf("%s", &nombre);
		
		printf("Ingrese su sueldo:");
		sueldo = leerSueldo();
		
		printf("Ingrese el numero de hijos:");
		numHijos = leerNumHijos();
		
		if(sueldo>1000){
			if(numHijos >= 3 && numHijos <= 7){
				printf("%s tiene mas de $1000 de sueldo y tiene entre 3 y 7 hijos.", nombre);
			}
		}
		
		i++;
		
	}
	
	return 0;
}

float leerSueldo(){
	float sueldo;
	scanf("%f", &sueldo);
	while(sueldo<0){
		printf("Entrada invalida, intenta de nuevo:");
		scanf("%f", &sueldo);
	}
	return sueldo;
}

int leerNumHijos(){
	int numHijos;
	scanf("%d", &numHijos);
	while(numHijos<0){
		printf("Entrada invalida, intenta de nuevo:");
		scanf("%d", &numHijos);
	}
	return numHijos;
}



