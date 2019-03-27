#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
Nombre: 54_tercer-vector-do-while.c
Autor: Programadores empedernidos
Descripción: E.P. que lea dos vectores de n elementos y que genere e imprima un
tercer vector con la suma de cada uno de los elementos de los dos anteriores.
Fecha: 06/03/2019
Fecha de corrección: 13/03/19.
Versión: 1.1
*/
#define FOR(A,B) for(A=0;A<B;A++)


void inbox(); // Sirve para generar un box inbox(1-3,longitud);printf("contenido \n");

int main(int argc, char *argv[]) {
	/* Se declaran las variables */
	int n,i;
	
	/* Entrada: Se piden los N números de los vectores*/
	printf("Dame la cantidad de n\243meros que sumar\240s: ");
	scanf("%d", &n);
	
	int v1[n], v2[n], v3[n];
	
	printf("Ingresa %d n\243meros del primer vector:\n",n);
	i=0;
	while(i<n){
		printf("%d. ",i+1);
		scanf("%d",&v1[i]);
		i++;
	}
	
	printf("Ingresa %d n\243meros del segundo vector:\n",n);
	i=0;
	while(i<n){
		printf("%d. ",i+1);
		scanf("%d",&v2[i]);
		i++;
	}
	
	/* Proceso: Se valida quien es el mayor y se guarda su posicion*/
	i=0;
	while(i<n){
		v3[i] = v1[i]+v2[i];
		i++;
	}
	/* Salida: */
	inbox(1,11);printf("SUMA:\n");
	FOR(i,n){
		inbox(2,11);
		printf(" %d. %d\n",i+1,v3[i]);
	}
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
Revisado por los compiladores: Jafet Alejandro Fernandez Martinez 
Fecha: 11/03/2019

1.-Funciana bien.
2.-Nombre vectores con nombres logicos.
3.-Falla al usar variables tipo float
*/

