/*HECHO POR VICTOR ENRIQUE CAUICH DAVALOS y ALAN JOSUE BARÓN PAT
25. Un vendedor tiene un sueldo base por día de 200 pesos y recibe una comisión por venta, 
que se determina considerando lo siguiente: 
a) Para sus ventas de lunes a viernes, la comisión de venta es el 2.5% del monto total de sus ventas. 
b) Para sus ventas de sábado, la comisión es del 4%. 
c) Para sus ventas de domingo, la comisión es del 5%.
Además, si el monto de sus ventas en un día es mayor a $10,000.00 tiene un bono adicional de 200 pesos. 
E.P. que lea las ventas de un día, calcule e imprima el ingreso total del vendedor.
*/
#include <stdio.h>
#include <stdlib.h>//Biblioteca que me sirve para usar la función o método exit, quen me sirve en este programa para un error...
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...

#define SUELDOBASE 200 //Definimos el sueldo pase al día

void calcularPaga(double Venta, double ComisionPorDia);

int main()
{
	setlocale(LC_ALL,"");//LLamo al metodo de la biblioteca locale.h, para que todas las actuaciones, puedan verse...
	double Venta = 0.0; //Se inicializa la variable para las ventas
	double ComisionPorDia = 0.0; //Se inicializa la variable para la comision por día
	printf("EJERCICIO 25. CALCULAR PAGA AL DÍA DE UN EMPLEADO.\n\n");//Imprimo los días con numeraciones
	printf("Días:\n");
	printf("1. Lunes.\n");
	printf("2. Martes.\n");
	printf("3. Miercoles.\n");
	printf("4. Jueves.\n");
	printf("5. Viernes.\n");
	printf("6. Sabado.\n");
	printf("7. Domingo.\n");
	printf("Ingrese el número (1 - 7) del día de trabajo del empleado, por favor: ");//Se le pide al usuario ingresar el día que trabajó
	int Seleccion; // Se inicializa la variable para la selección del día
	scanf("%d", &Seleccion); //Se lee el número de día que trabajó el trabajador
	printf("\nIngresa el total de venta que realizaste este día, por favor: ");
	scanf("%lf", &Venta); // Se lee la venta que realizó en el día el trabajador
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
				printf("\nNo se puede cálcular el salario, ya que no se seleccionó correctamente el día.\n");
				exit (-1);
			}
		}
	}
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-----------------------------Función para cálcular el pago--------------------------------------
void calcularPaga(double Venta, double ComisionPorDia)
{
	if(Venta > 10000)
	{
		printf("\nEl salario del empleado es de: $%.3lf pesos. \n Debido a que ganó al día en venta mas de $10000, tuvo una comisión de $200, de más.\n", 200 + ComisionPorDia + SUELDOBASE);
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
