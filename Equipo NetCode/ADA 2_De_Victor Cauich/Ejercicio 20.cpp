//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y m�s...
#include <string.h>

int main()
{
	setlocale(LC_ALL,"");
	printf("EJERCICIO 20. SABER CU�NTOS A�OS TIENES...\n");
	int Edad;
	printf("Ingresa cu�ntos a�os tienes, por favor: ");
	scanf("%d", &Edad);
	printf("Ahora s� que tienes %d a�os, gracias.", Edad);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
