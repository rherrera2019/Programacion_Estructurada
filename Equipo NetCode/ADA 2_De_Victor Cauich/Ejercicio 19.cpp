//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...
#include <string.h>

int main()
{
	setlocale(LC_ALL,"");
	printf("EJERCICIO 19. CALCULAR CUÁNTO LE PAGAN A UN TRABAJADOR\n");
	printf("POR METRIO CUADRADO\n\n");
	char Nombre[20], Apellido[20];
	int Seleccion;
	double MetroCuadrado;
	bool Val = false;
	while(Val == false)
	{
		printf("MENÚ:\n");
		printf("1. Calcular cuánto gana un trabajador.\n");
		printf("2. Salir.\n");
		printf("Selecciona la opción que quieras realizar: ");
		scanf("%d", &Seleccion);
		switch(Seleccion)
		{
			case 1:
				printf("Ingresa por favor el PRIMER NOMBRE del trabajador: ");
				scanf("%s", Nombre);
				printf("Ingresa por favor el PRIMER APELLIDO del trabajador: ");
				scanf("%s", Apellido);
				printf("Ingresa la superficie que ha realizado (por metro cuadrado): ");
				scanf("%lf", &MetroCuadrado);
				printf("\nA %s %s se le deberá pagar de salario $%.2f pesos.\n\n", Nombre, Apellido, MetroCuadrado * 300);
				MetroCuadrado = 0;
				break;
			case 2:
				Val = true;
				break;
			default :
				printf("\n\nERROR, SELECCIÓN INVALIDA\n\n");
				break;
		}
	}
	printf("\nAdiós, que tenga un buen día...");
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
