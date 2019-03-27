#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
Nombre: 53_posicion-mayor-while.c
Autor: Programadores empedernidos
Descripción: E.P. que lea un vector de n elementos y que determine el elemento mayor del arreglo y su posición.
Fecha de corrección: 13/03/19.
Versión: 1.1
*/


void inbox(); // Sirve para generar un box inbox(1-3,longitud);printf("contenido \n");

int main(int argc, char *argv[]) {
	/* Se declaran las variables */
	int n,i,mayor_valor=0,mayor_posicion=0;
	
	/* Entrada: Se piden los N números del vector*/
	printf("Dame la cantidad de n\243meros que comparar\240s: ");
	scanf("%d", &n);
	
	int v[n];
	
	printf("Ingresa %d numeros a validar:\n", n);
	i=0;
	while(i<n){
		printf("%d. ",i+1);
		scanf("%d",&v[i]);
		i++;
	}
	
	/* Proceso: Se valida quien es el mayor y se guarda su posicion*/
	i=0;
	while(i<n){
		if(mayor_valor<v[i]){
			mayor_valor = v[i];
			mayor_posicion = i;
		}
		i++;
	}
	/* Salida: */
	
	inbox(1,11);printf("MAYOR:\n");
	inbox(2,11);printf("Posici\242n: %i\n Valor: %i\n",mayor_posicion+1,mayor_valor);
	inbox(3,11);printf("\n");
	
	return 0;
}

void inbox(int tipo,int longitud){
	int caracter_inicio, caracter_final, caracter_relleno, x;
	switch(tipo){
	case 1:
		caracter_inicio = 201;
		caracter_final = 187;
		caracter_relleno = 205;
		break;
	case 2:
		caracter_inicio = 186;
		caracter_final = 186;
		caracter_relleno = 32;
		break;
	case 3:
		caracter_inicio = 200;
		caracter_final = 188;
		caracter_relleno = 205;
		break;
	};
	for (x=0;x<longitud+1;x++){
		printf("%c",caracter_relleno);
	};
	printf("%c\r%c",caracter_final,caracter_inicio);
}
/*

------Revision-------
	Nombre Equipo: Los Compiladores
	Revisado por: Chan Chan Norely
	Fecha: 11/03/2019
	Descripción: Los mismos detalles que recomiendo del cual usaron la 53 con for..
	1.- les recomiendo que permitan que el usuario ingrese numeros decimales por comparar ya que si pongo uno de esa manera me bota el programa
	2.- estuvo algo confuso entenderlo porque no decian cual es el numero mayor explicitamente y la posicion
	3.- entonces al imprimir deberian poner, que el numero mayor es ___ 
	4.- y seguidamente impriman la posicion es ____
	
	*/
