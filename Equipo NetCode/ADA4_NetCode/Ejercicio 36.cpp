#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Cuenta positivos y negativos 
Descripci�n:  Lee 50 n�meros y determina cuantos son negativos
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 05/02/2020
*/
int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num, Negativos; //Declaramos e inicializamos
	double numero;
	num = 0;
	Negativos = 0;
	numero = 0.0;
	printf ("Programa que lee 50 n�meros y determine e imprima cuantos son negativos.\n\n");
	do {
		printf ("\nIngresa el n�mero %d: ", num + 1);
		scanf ("%lf", &numero);
		if(numero < 0){ //Se determina si el n�mero es negativo, entonces aumenta el contador...
			Negativos++;
		}
		num++;
	}while (num < 50);
	//Imprimimos los resultados
	printf ("\nEl total de NEGATIVOS es de: ");
	printf ("%d", Negativos);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
