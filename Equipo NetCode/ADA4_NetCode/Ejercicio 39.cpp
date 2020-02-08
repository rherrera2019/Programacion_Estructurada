#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Utilidades
Descripción:  Lee las utilidades de 5 tiendas y determina cuales tuvieron utilidades mayores a $2,000,000
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 04/02/2020
*/
int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int Tienda, Contador;
	double Utilidades;
	Tienda = 0;
	Contador = 0;
	Utilidades = 0.0;
	printf ("Programa que determina si las utilidades son mayores a $2,000,000\n.");
	while (Tienda < 5){
		printf ("\nUtilidades mensuales de la tienda %d", Tienda + 1);
		printf ("\n\nIngrese las utilidades de la tienda: ");
		scanf ("%lf", &Utilidades);
		
		if (Utilidades >2000000){
			printf ("Las utilidades son mayores a $2,000,000\n");
			Contador++;
		}
		
		Tienda++;
	}
	printf ("\nEl número de tiendas con utilidades mayores a $2,000,000 fue de: %d", Contador);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
