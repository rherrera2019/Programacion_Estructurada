#include <stdio.h>
#include <locale.h>
#include <conio.h>

/* 
Nombre del Programa: Vector de 50 elementos 
Descripción: Que lea 50 elementos y los imprima
Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 07/03/2020
*/

#define N 50//definimos cuántos elementos tendrá el array

void Datos (){
	int Elementos[N];
	int i,contador;
	
	printf ("Ingrese los datos del arreglo\n\n");
	i = 0;
	while (i<N){
		printf ("Ingrese el elemento %d/50: ",i+1);
		scanf ("%d", &Elementos[i]);
		i++;
	}
	//Imprimimos los datos
	contador = 0;
	while (contador < N){
		printf ("\nElemento %d es: %d",contador+1,Elementos[contador]);
		contador++;
	}
	
}

int main() {
	setlocale (LC_ALL, "");
	Datos();
	getch ();
	return 0;
}
