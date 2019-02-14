#include <stdio.h>
/*
Nombre: Peso en gramos
Autores: 
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Descripcion: E.P. que lea el peso en gramos (máximo 5,000) y determine e
imprima el menor número de pesas que hay que poner en una balanza
(con pesos: 1 gr, 2 gr, 5 gr, 50 gr, 100 gr, 200 gr, 500 gr y 1000 gr),
para equilibrar un determinado peso en gramos, introducido por
teclado.
Fecha: 06Ene19
Versión: 1.0 */

int main(int argc, char *argv[]) {
	int g,A,B,C,D,E,F,G,H; /*Declaramos el identificador como entero debido a que el problema 
	nos da los gramos como enteros y además así usar la división entero.*/
	
	printf("Introduzca una cantidad de 1g a 5000g: ");
	scanf("%i", &g);/*Se leen los gramos*/
	
	if(g>=0 && g<=5000){
			A=g/1000;
			g=g%1000;
			printf("\nLa cantidad de 1000g es: %i", A);
			B=g/500;
			g=g%500;
			printf("\nLa cantidad de 500g es: %i", B);
			C=g/200;
			g=g%200;
			printf("\nLa cantidad de 200g es: %i", C);
			D=g/100;
			g=g%100;
			printf("\nLa cantidad de 100g es: %i", D);
			E=g/50;
			g=g%50;
			printf("\nLa cantidad de 50g es: %i", E);
			F=g/5;
			g=g%5;
			printf("\nLa cantidad de 5g es: %i", F);
			G=g/2;
			g=g%2;
			printf("\nLa cantidad de 2g es: %i", G);
			H=g/1;
			g=g%1;
			printf("\nLa cantidad de 1g es: %i", H);
	}else{
		printf("\nLa cantidad de gramos no se encuentra entre el intervalo designado.");
	}
	return 0;
}


/*El programa funciona correctamente. No era necesario tantas variables

Equipo:
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 6/02/2019*/
