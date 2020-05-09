#include <stdio.h>
#include <locale.h>
#include <conio.h>

/* 
Nombre del Programa: Vector de N elementos 
Descripción: Que lea N elementos y calcule el producto de sus elementos
Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 06/03/2020
*/
void Datos (){
	int i,elementos; //Contadores
	double aux; 
	//Inicializamos las variables
	i=0;
	aux = 1;
	
	printf ("Bienvenido, ingrese el total de elementos a calcular: ");
	do{
	scanf ("%d", &elementos);
	if (elementos<=0){
		printf ("\nTiene que existir elementos en el vector, ingrese nuevamente: ");
	}
	}while (elementos<=0);
	double array[elementos];
	
	//Lectura de los datos
	while (i<elementos){
		printf ("Ingrese el dato %d/%d: ",i+1,elementos);
		scanf ("%lf", &array[i]);
		i++;//incrementamos el contador
	}
	//Calculo de sus productos
	i=0;
	while (i<elementos){
		aux = aux*array[i];
		i++;
	}
	printf ("\nEl producto entre sus elementos es: %lf", aux); //Imprimimos el resultado
}

int main () {
	setlocale (LC_ALL,""); 
	Datos ();
	getch ();
	return 0;
}
