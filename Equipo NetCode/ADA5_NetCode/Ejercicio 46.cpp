#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Determina Tipos 
Descripción:  Captura 200 números y calcula cuantos fueron positivos, negativos e iguales a cero
Autor: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 06/02/2020
*/

//Definimos funciones
int ClasificadorP (double number){
	int Positivos;
	Positivos = 0;
	if (number>0){
		Positivos++;
	}
	return Positivos;
}

int ClasificadorN (double number){
	int Negativos;
	Negativos = 0;
	if (number<0){
		Negativos++;
	}
	return Negativos;
}

int ClasificadorC (double number){
	int Ceros;
	Ceros = 0;
	if (number == 0){
		Ceros++;
	}
	return Ceros;
}

int main (){
	setlocale (LC_ALL, ""); //Aplicamos la libreria <locale.h>
	int i,Positivos,Negativos,Ceros, Lim = 200; //Declaración e inicialización de las variables 
	double number;
	Positivos = 0;
	Negativos = 0;
	Ceros = 0;
	number = 0.0;
	printf ("Programa que clasifica los positivos, negativos e iguales a cero de 200 números\n");
	for (i=0;i<Lim;i++){
		printf ("\nCaptura: %d/%d", i+1, Lim);
		printf ("\nIngrese un número: "); //Captura del dato a clasificar, ENTRADA
		scanf ("%lf", &number);
		//Clasificamos , PROCESO
		Positivos = Positivos + ClasificadorP (number);
		Negativos = Negativos + ClasificadorN (number);
		Ceros = Ceros + ClasificadorC (number);
	}
	//SALIDA
	printf ("\nEl total de POSITIVOS es de: %d", Positivos);
	printf ("\nEl total de NEGATIVOS es de: %d", Negativos);
	printf ("\nEl total de CEROS es de: %d", Ceros);
	
	return 0;
}

