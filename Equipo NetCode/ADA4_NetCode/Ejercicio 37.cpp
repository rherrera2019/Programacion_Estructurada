#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Cuenta positivos
Descripci�n:  Lee 100 n�meros y determina si es positivo y lo imprime
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 04/02/2020
*/

int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num,contador; //Declaramos e inicializamos las variables
	double A;
	num = 0;
	contador = 0;
	A = 0.0;
	printf ("\nPrograma que determina si es positivo\n");
	do{
		printf ("\nIngrese el n�mero %d: ", num + 1); 
		scanf ("%lf", &A); //se escanea el n�mero en�simo
		
		if (A > 0){
			printf ("El n�mero es POSITIVO\n"); //Imprime si es positivo 
			contador = contador + 1; //Contabilizamos los positivos introducidos
		}
		num++;
	}while (num < 100);
	
	printf ("\nEl n�mero de positivos fue de: "); //Imprime cuantos fueron positivos
	printf ("%d", contador);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
