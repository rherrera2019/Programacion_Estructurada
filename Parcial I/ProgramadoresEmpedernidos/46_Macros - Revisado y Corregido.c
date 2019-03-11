#include <stdio.h>
#include <conio.h>
/* Se definen las constantes */
#define TOTAL_NUMEROS 200
#define FOR(A,B) for(A=1; A<=B; A++)
#define CONTADOR_TIPO(N,A,B,C) if(N>0){A++;}else if(N<0){B++;}else {C++;};

/*
Nombre: 46_pos-neg-ceros-con-for_macros.c
Autor: Programadores empedernidos
Descripcion: E.P. que lea 200 números y que calcule e imprima cuantos son 
			negativos, cuantos son positivos y cuantos fueron iguales a cero.
Fecha: 12feb2019
Versión: 1.0 */
int main(int argc, char *argv[]) {
	/* Se definen las variables */
	int numero,i,contador_positivos=0,contador_negativos=0,contador_ceros=0;
	
	/* Entrada: Se solicita al usuario los números */
	FOR(i, TOTAL_NUMEROS){//MACROS del for
		printf("[%i/%i] Introduce un n%cmero: ",i,TOTAL_NUMEROS, 163);
		scanf("%i",&numero);
		
		//se compara el numero dado con 0 para saber si es positivo, negativo o 0 e ir contando, esto, usando MACROS
		CONTADOR_TIPO(numero,contador_positivos,contador_negativos,contador_ceros);
	};
	/* Salida: Se imprime cuantos números fueron positivos, negativos o cero */
	int x; for (x=0;x<42;x++){printf("%c",205);};printf("%c\r%c",187,201);//for para imprimir partes visuales de la ficha
	printf("\n                                          %c\r",186);
	printf("%c N%cmeros positivos: %i\n                                          %c\r",186,163,contador_positivos,186);
	printf("%c N%cmeros negativos: %i\n                                          %c\r",186,163,contador_negativos,186);
	printf("%c Ceros: %i\n                                          %c\r",186,contador_ceros,188);
	for (x=0;x<42;x++){printf("%c",205);};printf("\r%c\n",200);//for para imprimir partes visuales de la ficha
	getch();
	return 0;
}
//Revisado: Equipo picateclas.
//Comentarios: Se documenta todas las partes, buen diseño al imprimir los resultados, y al leer los datos te dice por donde va, usa define correctamente.
