#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Cuenta positivos y negativos 
Descripción:  Lee 250 números y determina cuantos son positivos y negativos
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 04/02/2020
*/
int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num,Positivos,Negativos; //Declaramos e inicializamos
	double numero;
	num = 0;
	Positivos = 0;
	Negativos = 0;
	numero = 0.0;
	printf ("Programa que lee 250 números y determina cuantos son positivos y negativos");
	while (num < 250){
		printf ("\nIngresa el número %d: ", num + 1);
		scanf ("%lf", &numero);
		if (numero > 0){ //Determina su tipo
			Positivos++;
		}else {
			if(numero < 0){
				Negativos++;
			}else
			{
				printf("El 0 no se cuenta como positivo ni negativo, por lo tanto no se cuenta...");
			}
		}
		num++;
	}
	//Imprimimos los resultados
	printf ("\nEl total de POSITIVOS es de: ");
	printf ("%d", Positivos);
	printf ("\nEl total de NEGATIVOS es de: ");
	printf ("%d", Negativos);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
