#include <stdio.h>
#include <conio.h>
/* Se definen las constantes */
#define TOTAL_NUMEROS 200

/*
Nombre: 46_pos-neg-ceros-con-for.c
Autor: Programadores empedernidos
Descripcion: E.P. que lea 200 números y que calcule e imprima cuantos son 
			negativos, cuantos son positivos y cuantos fueron iguales a cero.
Fecha: 12feb2019
Versión: 1.0 */
int main(int argc, char *argv[]) {
	/* Se definen las variables */
	int numero,i,contador_positivos=0,contador_negativos=0,contador_ceros=0;
	
	/* Entrada: Se solicita al usuario los números */
	for (i=1;i<=TOTAL_NUMEROS;i++){
		printf("[%i/%i] Introduce un número: ",i,TOTAL_NUMEROS);
		scanf("%i",&numero);
		
		//se compara el numero dado con 0 para saber si es positivo, negativo o 0 e ir contando
		if (numero>0){
			contador_positivos++;
		} else if (numero<0){
			contador_negativos++;
		} else {
			contador_ceros++;
		};
	};
	/* Salida: Se imprime cuantos números fueron positivos, negativos o cero */
	int x; for (x=0;x<42;x++){printf("%c",205);};printf("%c\r%c",187,201);
	printf("\n                                          %c\r",186);
	printf("%c Números positivos: %i\n                                          %c\r",186,contador_positivos,186);
	printf("%c Números negativos: %i\n                                          %c\r",186,contador_negativos,186);
	printf("%c Ceros: %i\n                                          %c\r",186,contador_ceros,188);
	for (x=0;x<42;x++){printf("%c",205);};printf("\r%c\n",200);
	getch();
	return 0;
}
//Revisado: Equipo picateclas.
//Comentarios: Se documenta todas las partes, buen diseño al imprimir los resultados, y al leer los datos te dice por donde va.
