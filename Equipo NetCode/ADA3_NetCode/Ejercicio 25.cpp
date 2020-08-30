/*HECHO POR VICTOR ENRIQUE CAUICH DAVALOS y ALAN JOSUE BAR�N PAT
25. Un vendedor tiene un sueldo base por d�a de 200 pesos y recibe una comisi�n por venta, 
que se determina considerando lo siguiente: 
a) Para sus ventas de lunes a viernes, la comisi�n de venta es el 2.5% del monto total de sus ventas. 
b) Para sus ventas de s�bado, la comisi�n es del 4%. 
c) Para sus ventas de domingo, la comisi�n es del 5%.
Adem�s, si el monto de sus ventas en un d�a es mayor a $10,000.00 tiene un bono adicional de 200 pesos. 
E.P. que lea las ventas de un d�a, calcule e imprima el ingreso total del vendedor.
*/
#include <stdio.h>
#include <stdlib.h>//Biblioteca que me sirve para usar la funci�n o m�todo exit, quen me sirve en este programa para un error...
#include <locale.h>//Biblioteca para poder usar acentuaciones y m�s...

#define SUELDOBASE 200 //Definimos el sueldo pase al d�a

void calcularPaga(double Venta, double ComisionPorDia);

int main()
{
	setlocale(LC_ALL,"");//LLamo al metodo de la biblioteca locale.h, para que todas las actuaciones, puedan verse...
	double Venta = 0.0; //Se inicializa la variable para las ventas
	double ComisionPorDia = 0.0; //Se inicializa la variable para la comision por d�a
	printf("EJERCICIO 25. CALCULAR PAGA AL D�A DE UN EMPLEADO.\n\n");//Imprimo los d�as con numeraciones
	printf("D�as:\n");
	printf("1. Lunes.\n");
	printf("2. Martes.\n");
	printf("3. Miercoles.\n");
	printf("4. Jueves.\n");
	printf("5. Viernes.\n");
	printf("6. Sabado.\n");
	printf("7. Domingo.\n");
	printf("Ingrese el n�mero (1 - 7) del d�a de trabajo del empleado, por favor: ");//Se le pide al usuario ingresar el d�a que trabaj�
	int Seleccion; // Se inicializa la variable para la selecci�n del d�a
	scanf("%d", &Seleccion); //Se lee el n�mero de d�a que trabaj� el trabajador
	printf("\nIngresa el total de venta que realizaste este d�a, por favor: ");
	scanf("%lf", &Venta); // Se lee la venta que realiz� en el d�a el trabajador
	if(Seleccion == 7)
	{
		ComisionPorDia = (double)Venta * 0.05;
		calcularPaga(Venta, ComisionPorDia);
	}else
	{
		if(Seleccion == 6)
		{
			ComisionPorDia = Venta * 0.04;
			calcularPaga(Venta, ComisionPorDia);
		}else
		{
			if(Seleccion == 1 || Seleccion == 2 || Seleccion == 3 || Seleccion == 4 || Seleccion == 5)
			{
				ComisionPorDia = Venta * 0.025;
				calcularPaga(Venta, ComisionPorDia);
			}else
			{
				printf("\nNo se puede c�lcular el salario, ya que no se seleccion� correctamente el d�a.\n");
				exit (-1);
			}
		}
	}
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-----------------------------Funci�n para c�lcular el pago--------------------------------------
void calcularPaga(double Venta, double ComisionPorDia)
{
	if(Venta > 10000)
	{
		printf("\nEl salario del empleado es de: $%.3lf pesos. \n Debido a que gan� al d�a en venta mas de $10000, tuvo una comisi�n de $200, de m�s.\n", 200 + ComisionPorDia + SUELDOBASE);
	}else
	{
		if(Venta < 0)
		{
			printf("\nEl salario del empleado es de: $0 pesos.\n");
		}else
		{
			printf("\nEl salario del empleado es de: $%.3lf pesos.\n",  ComisionPorDia + SUELDOBASE);
		}
	}
}
