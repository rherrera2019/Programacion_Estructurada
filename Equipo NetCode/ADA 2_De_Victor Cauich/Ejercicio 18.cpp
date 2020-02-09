//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...

int main()
{
	setlocale(LC_ALL,"");
	printf("EJERCICIO 18. LEER UN VALOR C QUE REPRESENTE UN VALOR\n");
	printf("EN GRADOS CENTIGRADOS Y QUE LO CONVIERTA A GRADOS FAHRENHEIT (F)\n\n");
	double C = 0;
	printf("Ingresa por favor el valor Celsius, por favor:");
	scanf("%lf", &C);
	printf("Lo convertimos en Fahrenheit y quedaría: %.2f\n",  C * 1.8 + 32);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
