//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y m�s...

int main()
{
	setlocale(LC_ALL,"");
	printf("EJERCICIO 17. LEER 3 N�MEROS REALES, DETERMINAR \n");
	printf("E IMPRIMIR LA SUMA, RESTA, MULTIPLICACI�N Y DIVISI�N DE LOS MISMOS\n");
	double Num1 = 0.0, Num2 = 0.0, Num3 = 0.0;
	double div = 0.;
	printf("Ingresa por favor el primer n�mero real: ");
	scanf("%lf", &Num1);
	printf("Ingresa por favor el segundo n�mero real: ");
	scanf("%lf", &Num2);
	printf("Ingresa por favor el tercer n�mero real: ");
	scanf("%lf", &Num3);
	printf("La suma de los n�meros es: %.2f \n", Num1 + Num2 + Num3);
	printf("La resta de los n�meros es: %.2f \n", (Num1 - Num2) - Num3);
	printf("La multiplicaci�n de los n�meros es: %.2f \n", Num1 * Num2 * Num3);
	if(Num2 != 0)
	{
		div = Num1 / Num2;
	}else{
		printf("Como el segundo n�mero real es 0, no se puede dividir un n�mero entre �ste...\n");
		div = Num1;	
	}
	if(Num3 != 0)
	{
		div = div / Num3;
	}else{
		printf("Como el tercer n�mero real es 0, no se puede dividir un n�mero entre �ste...\n");	
	}
	printf("La divisi�n de los n�meros es: %.2f\n", div);
	printf("\nPresione Enter para salir del programa :)\n");
	fflush(stdin);
	getchar();
	return 0;
}

