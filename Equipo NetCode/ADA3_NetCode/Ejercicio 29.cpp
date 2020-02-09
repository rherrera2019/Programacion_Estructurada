#include <stdio.h>
#include <locale.h> //Para las acentuaciones

/*
Nombre: Meses del año
Descripción: Ingresa un número de algún mes (1-12) e imprime el total de dias que contiene ese mes 
Autor: Alan Josue Barón Pat
Version: 1.0
Fecha: 02/02/2020
*/

int main () {
	int mes;
	
	printf ("Consulta el número de dias que tiene algun mes en el año\n");
	printf ("Ingrese un número del 1-12\n");
	scanf ("%d", &mes); //Se introduce el "mes" a consutar (Entrada)
	
	if (mes >12 | mes <1){
		printf ("\nIngrese un valor válido"); //Validamos
	}
	else
	{ 
		switch (mes) //Se muestra el "mes" consultado (Salida)
		{
			case 1:
				printf ("\nEnero tiene: 31 dias");
				break;
			case 2:
				printf ("\nFebrero tiene: 28 dias y en bisiesto 29 dias");
				break;
			case 3:
				printf ("\nMarzo tiene: 31 dias");
				break;
			case 4:
				printf ("\nAbril tiene: 30 dias");
				break;
			case 5: 
				printf ("\nMayo tiene: 31 dias");
				break;
			case 6:
				printf ("\nJunio tiene: 30 dias");
				break;
			case 7:
				printf ("\nJulio tiene: 31 dias");
				break;
			case 8:
				printf ("\nAgosto tiene: 31 dias");
				break;
			case 9:
				printf ("\nSeptiembre tiene: 30 dias");
				break;
			case 10:
				printf ("\nOctubre tiene: 31 dias");
				break;
			case 11:
				printf ("\nNoviembre tiene: 30 dias");
				break;
			case 12:
				printf ("\nDiciembre tiene: 31 dias");
				break;
		}
	}
	printf("\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
