#include <stdio.h>
#include <locale.h>
#include <conio.h>

/* 
Nombre del Programa: Trono del Vector N
Descripción: E.P. que lea un vector de n elementos y que determine el elemento
mayor del arreglo y su posición.

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 08/03/2020
*/

int main (){
	setlocale (LC_ALL,"");
	int i,N,posicion;
	double trono;
	
	
	printf ("Bienvenido, este programa calcula el mayor elemento en el vector.\n");
	printf ("Por ahora definamos el tamaño del vector: ");
	do{
	scanf ("%d", &N);
	if (N<=0){
		printf ("\nTiene que existir elementos en el vector, ingrese nuevamente: ");
	}
	}while (N<=0);
	
	double array[N];
	
	//Lectura de datos
	i = 0;
	do{
		printf ("Ingrese el elemento %d/%d: ", i+1, N);
		scanf ("%lf", &array[i]);
		i++;	
	}while (i<N);
	//Calculamos el mayor 
	posicion = 0;
	i = 0;
	trono = -999999999;
	do {
		if (array[i]>=trono){
			trono = array[i];
			posicion = i+1;
		}
		i++;
	}while (i<N);
	//Imprimimos el resultado
	printf ("\nEl mayor elemento es: %.4lf\n", trono);
	printf ("En la posición: %d",posicion);
	
	getch();
	return 0;
}
