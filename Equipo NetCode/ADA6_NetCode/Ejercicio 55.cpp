#include <stdio.h>
#include <locale.h>
#include <conio.h>
/* 
Nombre del Programa: El elemento negativo
Descripción: E.P. que lea un vector de n elementos, el cual se sabe tiene un
elemento negativo y que determine e imprima su posición.

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 08/03/2020
*/

int main (){
	setlocale(LC_ALL,"");
	int i, posicion,elementos;
	
	printf ("Bienvenido, este programa determina la posición del negativo.\n");
	printf ("Primero, definamos el tamaño del arreglo: ");
	do{
		scanf ("%d",&elementos);
		if (elementos>=0){
			printf ("\nTiene que existir elementos en el vector, ingrese nuevamente: ");
		}
	}while(elementos>=0);
	
	double array[elementos];
	//---------------Capturamos los elementos----------------
	i=0;
	do{
		printf ("Ingrese el elemento %d/%d: ",i+1,elementos);
		scanf ("%lf",&array[i]);
		i++;
	}while (i<elementos);
	//------Identificamos los negativos e imprimimos su posición--------
	i=0;
	do{
		if (array[i]<0){
			printf ("\nExiste un negativo en la posición %d",i+1);
		}
		i++;
	}while(i<elementos);
	
	getch();
	return 0;
}
