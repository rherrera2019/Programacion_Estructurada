#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <math.h>

/*
Nombre: Papeleria
Descripción: Calcula el total de articulos comprados y después proporciona la cantidad total a pagar 
Autor: Alan Josue Barón Pat
Version: 1.0
Fecha: 02/02/2020
*/

int main () {
	
	int Seleccion;
	int libros,cuadernos,plumas ;
	Seleccion= 0;
	libros= 0;
	cuadernos= 0;
	plumas= 0;

	
	printf ("Bienvenido a la papeleria\n");
	printf ("Libros: $100\n");
	printf ("Cuadernos: $15.50\n");
	printf ("Plumas: $2.35\n");
	
	printf ("\nDesea comprar?, 1.- Si / 2.- No\n");
	scanf ("%d",&Seleccion);
	
	if (Seleccion == 1) {
		printf ("Cuantos libros va a llevar?\n");
		scanf ("%d",&libros);
		printf ("Cuantos cuadernos va a llevar?\n");
		scanf ("%d",&cuadernos);
		printf ("Cuantas plumas va a llevar?\n");
		scanf ("%d",&plumas);
				
		printf ("%.2lf", (double)((libros*100)+(cuadernos*15.50)+(plumas*2.35)));
	}
	else {
		printf ("Hasta luego");
	}
	printf("\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}


