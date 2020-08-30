#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Contador de 10 n�meros
Descripci�n: Lee 10 n�meros y determina los mayores a 100
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 04/02/2020
*/

int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num,A; //Declaramos e inicializamos la variable
	num = 0;
	A = 0;
	
	printf ("\nPrograma que lee 10 n�meros y determina los mayores a 100\n");
	do{
		printf ("\nProporciona el n�mero %d: ", num + 1); //Iniciamos a determinar
		scanf ("%d", &A);
		
		if (A>100){
			printf ("El n�mero es mayor a 100\n"); //Imprime si es mayor a 100
		}
		
		num++;
	} while (num < 10);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}

