//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y m�s...

void verMayor(double Mayor, double Num3);

int main()
{
	setlocale(LC_ALL,"");
	printf("EJERCICIO 22. LEER 3 N�MEROS DIFERENTES Y QUE DETERMINE E INPRIMA EL MAYOR\n\n");
	double Num1, Num2, Num3, Mayor;
	printf("Ingresa el primer n�mero: ");
	scanf("%lf", &Num1);
	printf("Ingresa el segundo n�mero: ");
	scanf("%lf", &Num2);
	printf("Ingresa el tercer n�mero: ");
	scanf("%lf", &Num3);
	if(Num1 > Num2){
		Mayor = Num1;
		verMayor(Mayor, Num3);
	} else
	{
		Mayor = Num2;
		verMayor(Mayor, Num3);
	}
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-------------------------C�lcular el mayor----------------------------------
void verMayor(double Mayor, double Num3)
{
	if(Mayor > Num3)
	{
		printf("\nEl n�mero mayor es: %.2f", Mayor);
	}else
	{
		Mayor = Num3;
		printf("\nEl n�mero mayor es: %.2f", Mayor);	
	}
}
