#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Lectura e impresi�n de 100 n�meros 
Descripci�n:  Leer 100 n�meros e imprimirlos
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 05/02/2020
*/
int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num = 0.0; //Declaramos e inicializamos la variable
	double A = 0;
	
	printf ("\nPrograma que lee 10 n�meros y determina los mayores a 100\n");
	do{
		printf ("\nProporciona el n�mero %d: ", num + 1); //Iniciamos a determinar
		scanf ("%lf", &A);
		printf ("\n\nEl n�mero %d es: %.2f\n", num + 1, A); //Se imprime el n�mero ingresado
		num++;
	} while (num < 100);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
