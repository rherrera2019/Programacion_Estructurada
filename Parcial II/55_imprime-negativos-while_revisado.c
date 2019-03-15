#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
Nombre: 55_elemento-negativo-for.c
Autor: Programadores empedernidos
Descripción: E.P. que lea un vector de n elementos, el cual se sabe tiene un elemento negativo y que determine e imprima su posición.
Fecha: 06/03/2019
Fecha de corrección: 13/03/19.
Versión: 1.1
*/

/* Se definen constantes y macros */
void inbox(); // Sirve para generar un box inbox(1-3,longitud);printf("contenido \n");

int main() {
	/* Se declaran las variables */
	int n,i=0;
	
	/* Entrada: Se solicitan los números */
	printf("Dame la cantidad de numeros que leer\240s: ");
	scanf("%d", &n);
	
	int v[n];
	
	
	while(i<n){
		printf("Ingresa el elemento en la posici\242n %d. ", i+1);
		scanf("%d", &v[i]);
		i++;
	}

	/* Proceso y Salida: Se valida el arreglo y se imprime la posicion*/
	inbox(1,15);printf("NEGATIVOS:\n");
	i=0;
	while(i<n){
		if(v[i]<0){
			inbox(2,15);printf(" %i. %i\n",i+1,v[i]);
		}
		i++;
	}
	inbox(3,15);printf("\n");
	
	
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

1.-No hace nada.


*/
