//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...

int main()
{
	setlocale(LC_ALL,"");
	printf("EJERCICIO 21. LEE 3 NÚMEROS ENTEROS Y SI EL PRIMERO ES POSITIVO\n");
	printf("DETERMINAR E IMPRIMIR EL PRODUCTO DE LOS OTROS DOS VALORES,\n");
	printf("SINO, CALCULAR LA SUMA E IMPRIMIRLO\n");
	int Valor1, Valor2, Valor3;
	printf("\nIngresa el primer número, por favor: ");
	scanf("%d", &Valor1);
	printf("\nIngresa el segundo número, por favor: ");
	scanf("%d", &Valor2);
	printf("\nIngresa el tercer número, por favor: ");
	scanf("%d", &Valor3);
	if(Valor1 > 0)
	{
		printf("Por ser el primer número positivo, se calculará el producto\n");
		printf("de los otros dos números.\n");
		printf("El producto es: %d\n", Valor2 * Valor3);
	}else
	{
		if (Valor1<0)
		{
			printf("Por ser el primer número negativo, se calculará la suma\n");
			printf("de los otros dos números.\n");
			printf("La suma es: %d\n", Valor2 + Valor3);	
		}else
		{
			printf("Por ser el primer número 0, y como 0 no es negativo ni positivo\n");
			printf("entonces, no se hace nada...\n");
		}	
	}
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
