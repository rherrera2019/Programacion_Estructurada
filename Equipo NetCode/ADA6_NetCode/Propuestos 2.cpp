#include <stdio.h>
#include <conio.h>
#include <locale.h>
/* 
Nombre del Programa: Vector de 20 elementos

Descripción: E.P. que lea un vector de 20 elementos que sean enteros y determine e imprima la suma de los elementos pares y el producto de los elementos impares.

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 07/03/2020
*/

#define N 5//Definimos el número de elementos que tendrá el array

 int main (){
	setlocale (LC_ALL,"");
	int i,array[N];
	int suma,producto,aux,dato;
	printf ("Este programa determina la suma de los elementos pares y el producto de los impares\n");
	printf ("Iniciamos la captura...\n\n");
	//-------------------Capturamos los datos---------------
	for(i=0;i<N;i++){
		printf ("Ingrese el elemento %d/%d: ",i+1, N);
		scanf ("%d", &array[i]);
	}
	//-----------------Determinamos la suma y el producto------------
	suma = 0;
	producto = 1;
	for (i=0;i<N;i++){
		dato = array [i];
		if (dato % 2== 0){
			suma = suma + dato;
		}else{
			producto = producto*dato;
		}
	}
	
	printf ("\nLa suma de los pares es: %d\n",suma);
	printf ("El producto de los impares es: %d", producto);
	getch ();
	return 0;
 }
