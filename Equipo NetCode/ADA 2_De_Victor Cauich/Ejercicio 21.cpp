//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y m�s...

int main()
{
	setlocale(LC_ALL,"");
	printf("EJERCICIO 21. LEE 3 N�MEROS ENTEROS Y SI EL PRIMERO ES POSITIVO\n");
	printf("DETERMINAR E IMPRIMIR EL PRODUCTO DE LOS OTROS DOS VALORES,\n");
	printf("SINO, CALCULAR LA SUMA E IMPRIMIRLO\n");
	int Valor1, Valor2, Valor3;
	printf("\nIngresa el primer n�mero, por favor: ");
	scanf("%d", &Valor1);
	printf("\nIngresa el segundo n�mero, por favor: ");
	scanf("%d", &Valor2);
	printf("\nIngresa el tercer n�mero, por favor: ");
	scanf("%d", &Valor3);
	if(Valor1 > 0)
	{
		printf("Por ser el primer n�mero positivo, se calcular� el producto\n");
		printf("de los otros dos n�meros.\n");
		printf("El producto es: %d\n", Valor2 * Valor3);
	}else
	{
		if (Valor1<0)
		{
			printf("Por ser el primer n�mero negativo, se calcular� la suma\n");
			printf("de los otros dos n�meros.\n");
			printf("La suma es: %d\n", Valor2 + Valor3);	
		}else
		{
			printf("Por ser el primer n�mero 0, y como 0 no es negativo ni positivo\n");
			printf("entonces, no se hace nada...\n");
		}	
	}
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
