//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y m�s...
#include <math.h>//Biblioteca lo uso para redondear enteros...
int main()
{
	double i, i2, i3, i4, i5;
	double R1, R2, R3;
	setlocale(LC_ALL,"");
	printf("EJERCICIO 15. lEER E IMPRIMIR 5 N�MEROS ENTEROS Y 3 REALES\n");
	printf("Ingrese 5 valores entero por favor(si ingresa un numero que no sea entero se redonder�): \n");
	printf("Primer n�mero: ");
	scanf("%lf", &i);
	i = round(i);
	printf("\nSegundo n�mero: ");
	scanf("%lf", &i2);
	i2 = round(i2);
	printf("\nTercero n�mero: ");
	scanf("%lf", &i3);
	i3 = round(i3);
	printf("\nCuarto n�mero: ");
	scanf("%lf", &i4);
	i4 = round(i4);
	printf("\nQuinto n�mero: ");
	scanf("%lf", &i5);
	i5 = round(i5);
	
	printf("\nIngrese 3 valores reales por favor: \n");
	printf("Primer n�mero: ");
	scanf("%lf", &R1);
	printf("\nSegundo n�mero: ");
	scanf("%lf", &R2);
	printf("\nTercero n�mero: ");
	scanf("%lf", &R3);
	
	printf("\nN�meros enteros: \n");
	printf("Primero : %.0f, Segundo: %.0f, Tercero: %.0f, Cuarto: %.0f, Quinto: %.0f \n", i, i2, i3, i4, i5);
	printf("N�meros reales: \n");
	printf("Primero : %.2f, Segundo: %.2f, Tercero: %.2f \n", R1, R2, R3);
	printf("Teclee ENTER...");
	fflush(stdin);
	getchar();
	return 0;
}


