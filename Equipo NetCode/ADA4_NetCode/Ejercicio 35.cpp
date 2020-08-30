#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Cuenta ceros
Descripci�n: Lee 25 n�meros e imprime los iguales a 0
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 04/02/2020
*/

int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num,A; //Declaraci�n e inicializaci�n de las variables
	num = 0;
	A = 0;
	printf ("\nPrograma que determina los que son igual a 0\n");
	do
	{
		printf ("\nIngrese el n�mero %d: ", num + 1); //Determinamos los valores
		scanf ("%d", &A);
		
		if (A == 0){
			printf ("Es igual a CERO\n"); //Imprime si es igual a Cero el valor introducido
		}
		
		num++;
	}while (num <25);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}

