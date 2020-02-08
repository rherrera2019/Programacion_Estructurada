#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Lectura e impresión de 100 números 
Descripción:  Leer 100 números e imprimirlos
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 05/02/2020
*/
int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num = 0.0; //Declaramos e inicializamos la variable
	double A = 0;
	
	printf ("\nPrograma que lee 10 números y determina los mayores a 100\n");
	do{
		printf ("\nProporciona el número %d: ", num + 1); //Iniciamos a determinar
		scanf ("%lf", &A);
		printf ("\n\nEl número %d es: %.2f\n", num + 1, A); //Se imprime el número ingresado
		num++;
	} while (num < 100);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
