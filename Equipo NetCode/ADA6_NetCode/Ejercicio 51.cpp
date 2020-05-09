#include <stdio.h>
#include <locale.h>
#include <conio.h>

/* 
Nombre del Programa: Sumatoria
Descripción: Que lea un vector de N elementos y calcule su sumatoria
Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 08/03/2020
*/

int main (){
	setlocale(LC_ALL,"");
	int i,N;
	double aux;
	
	printf ("Bienvenido, este programa calcula la sumatoria del vector.\n");
	printf ("Ingrese el total de elementos a calcular: ");
	do{
		scanf ("%d", &N);
		if (N<=0){
			printf ("\nTiene que existir elementos en el vector, ingrese nuevamente: ");
		}
	}while (N<=0);	
	double array[N]; //Definimos el tamaño del vector
	
	printf ("\n");
	//Lectura de los datos
	i=0;
	while (i<N){
		printf ("Ingrese el elemento %d/%d: ",i+1,N);
		scanf ("%lf", &array[i]);
		i++;
	}
	//Calculamos la sumatoria 
	i= 0;
	aux= 0;
	while (i<N){
		aux = aux + array[i];
		i++;
	}
	
	//Imprimimos el resultado
	printf ("\nLa sumatoria de sus elementos es: %.4lf", aux);
	
	getch ();
	return 0;
}

