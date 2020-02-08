//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...
#include <string.h>

int main()
{
	setlocale(LC_ALL,"");
	printf("EJERCICIO 20. SABER CUÁNTOS AÑOS TIENES...\n");
	int Edad;
	printf("Ingresa cuántos años tienes, por favor: ");
	scanf("%d", &Edad);
	printf("Ahora sé que tienes %d años, gracias.", Edad);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
