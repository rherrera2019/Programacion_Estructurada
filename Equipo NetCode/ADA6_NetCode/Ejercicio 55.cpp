#include <stdio.h>
#include <locale.h>
#include <conio.h>
/* 
Nombre del Programa: El elemento negativo
Descripci�n: E.P. que lea un vector de n elementos, el cual se sabe tiene un
elemento negativo y que determine e imprima su posici�n.

Autor: Alan Josue Bar�n Pat & Victor Cauich Davalos
Versi�n: 1.0.0
Fecha: 08/03/2020
*/

int main (){
	setlocale(LC_ALL,"");
	int i, posicion,elementos;
	
	printf ("Bienvenido, este programa determina la posici�n del negativo.\n");
	printf ("Primero, definamos el tama�o del arreglo: ");
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
	//------Identificamos los negativos e imprimimos su posici�n--------
	i=0;
	do{
		if (array[i]<0){
			printf ("\nExiste un negativo en la posici�n %d",i+1);
		}
		i++;
	}while(i<elementos);
	
	getch();
	return 0;
}
