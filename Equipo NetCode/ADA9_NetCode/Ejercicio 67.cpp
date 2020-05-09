#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <stdlib.h>

/*
Nombre: EMPLEADO CON MENOR Y MAYOR SALARIO
Descripción:  E.P. que lea un arreglo de estructuras los datos 
de N empleados de una empresa (clave (numérica), nombre, edad, 
salario (real), sexo (numérica) y que determine e imprima los 
datos del empleado con mayor y menor salario
Autores: Victor Enrique Cauich Davalos & Alan Josue Barón Pat
Version: 1.0
Fecha: 23/03/2020
*/

//Creamos nuestra estructura de los datos que tendrán nuestros empleados
typedef struct Empleado
{
	int Clave;
	char Nombre[30];
	int Edad;
	double Salario;
	int Sexo;
};

//prototipo de funciones
int ValidarCantidadEmpleados(int N);//Para validar cuántos empleados son de la empresa
void AsignarDatosEmpleados(Empleado Empleados[], int N);
int IngresarSexo(Empleado E);
double SalarioMinimo(Empleado Empleados[], int N, double SalarioMin);
double SalarioMaximo(Empleado Empleados[], int N, double SalarioMax);
void ImprimirEmpleadoMenorYMayor(Empleado Empleados[], int N, double SalarioMin, double SalarioMax);
void MostrarEmpleado(Empleado Empleados[], int N);

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	printf("PROGRAMA DE EMPLEADO CON MENOR Y MAYOR SALARIO.");
	int N;//cantidad de empleados
	double SalarioMin, SalarioMax;
	
	//Validar el número de empleados
	N = ValidarCantidadEmpleados(N);
	
	//Creamos el array de empleados
	Empleado Empleados[N];
	
	//Asignar datos de cada empleado
	AsignarDatosEmpleados(Empleados, N);
	
	//Determinar cual salario es el menor
	SalarioMin = SalarioMinimo(Empleados, N, SalarioMin);
	
	//Determinar cual salario es el mayor
	SalarioMax = SalarioMaximo(Empleados, N, SalarioMax);
	
	system("cls");
	printf("\n\n");
	if(N > 1)
	{
		ImprimirEmpleadoMenorYMayor(Empleados, N, SalarioMin, SalarioMax);	
	}else
	{
		printf("\nCOMO SOLO HAY 1 EMPLEADO, ENTONCES TIENE EL MAXIMO Y MINIMO SALARIO,\nESTOS SON SUS DATOS:");
		MostrarEmpleado(Empleados, N);
	}
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-------------------Función que valida cantidad de empleados---------------
int ValidarCantidadEmpleados(int N)
{
	printf("\nIngrese por favor la cantidad de \nempleados que tiene la empresa, por favor: ");
	scanf("%d", &N);
	fflush(stdin);
	if(N > 0)
	{
		return N;
	}else
	{
		printf("\nERROR, debe ingresar un valor mayor a 0.\n Intente de nuevo, por favor...");
		printf("\nTeclea ENTER para continuar, por favor...");
		getchar();
		system("cls");
		N = ValidarCantidadEmpleados(N);
		return N;
	}
}
//-----------------Función para asignar datos de los empleados-------------
void AsignarDatosEmpleados(Empleado Empleados[], int N)
{
	for(int i = 0; i < N; i++)
	{
		printf("\nIngrese por favor su clave (numerica) empleado #%d: ", i + 1);
		scanf("%d", &Empleados[i].Clave);
		printf("\nIngrese por favor su nombre empleado #%d: ", i + 1);
		scanf("%s", &Empleados[i].Nombre);
		fflush(stdin);
		printf("\nIngrese por favor su edad empleado #%d: ", i + 1);
		scanf("%d", &Empleados[i].Edad);
		printf("\nIngrese por favor su salario empleado #%d: ", i + 1);
		scanf("%lf", &Empleados[i].Salario);
		Empleados[i].Sexo = IngresarSexo(Empleados[i]);
	}
}
//-------------------------Función para validar sexo de cada empleado------
int IngresarSexo(Empleado E)
{
	printf("\nIngrese por favor su sexo, siendo:");
	printf("\n1. Hombre.");
	printf("\n2. Mujer.");
	printf("\nIngrese el número de su opción: ");
	scanf("%d", &E.Sexo);
	fflush(stdin);
	if(E.Sexo != 1 && E.Sexo != 2)
	{
		printf("\nERROR, debe ingresar 1 o 2, como muestra en las opciones.\n Intente de nuevo, por favor...");
		E.Sexo = IngresarSexo(E);
		return E.Sexo;
	}else
	{
		return E.Sexo;
	}
}
//------------------Función para encontrar el salario minimo----------------
double SalarioMinimo(Empleado Empleados[], int N, double SalarioMin)
{
	SalarioMin = Empleados[0].Salario;
	for(int i = 1; i < N; i++)
	{
		if(SalarioMin > Empleados[i].Salario)
		{
			SalarioMin = Empleados[i].Salario;
		}
	}
	return SalarioMin;
}
//------------------Función para encontrar el salario maximo----------------
double SalarioMaximo(Empleado Empleados[], int N, double SalarioMax)
{
	SalarioMax = Empleados[0].Salario;
	for(int i = 1; i < N; i++)
	{
		if(SalarioMax < Empleados[i].Salario)
		{
			SalarioMax = Empleados[i].Salario;
		}
	}
	return SalarioMax;
}
//-----------------Función para imprimir datos de los empleados con minimo y maximo salario------------
void ImprimirEmpleadoMenorYMayor(Empleado Empleados[], int N, double SalarioMin, double SalarioMax)
{
	
	for(int i = 0; i < N; i++)
	{
		if(SalarioMin == Empleados[i].Salario)
		{
			printf("\n\nDATOS DEL EMPLEADO CON MENOR SALARIO:");
			printf("\n\nLa clave del/la emplead@ %d es: %d", i + 1, Empleados[i].Clave); 
			printf("\nEl nombre del/la emplead@ %d es: %s", i + 1, Empleados[i].Nombre);
			printf("\nLa edad del/la emplead@ %d es: %d", i + 1, Empleados[i].Edad);
			printf("\nEl salario del/la emplead@ %d es: %.2lf", i + 1, Empleados[i].Salario);
			if(Empleados[i].Sexo == 1)
			{
				printf("\nEl sexo del/la emplead@ %d es: Hombre", i + 1);
			}else
			{
				printf("\nEl sexo del/la emplead@ %d es: Mujer", i + 1);
			}
		}
		
		if(SalarioMax == Empleados[i].Salario)
		{
			printf("\n\nDATOS DEL EMPLEADO CON MAYOR SALARIO:");
			printf("\n\nLa clave del/la emplead@ %d es: %d", i + 1, Empleados[i].Clave); 
			printf("\nEl nombre del/la emplead@ %d es: %s", i + 1, Empleados[i].Nombre);
			printf("\nLa edad del/la emplead@ %d es: %d", i + 1, Empleados[i].Edad);
			printf("\nEl salario del/la emplead@ %d es: %.2lf", i + 1, Empleados[i].Salario);
			if(Empleados[i].Sexo == 1)
			{
				printf("\nEl sexo del/la emplead@ %d es: Hombre", i + 1);
			}else
			{
				printf("\nEl sexo del/la emplead@ %d es: Mujer", i + 1);
			}
		}
	}
}
//------------------Función para mostrar los datos si es que solo existe un empleado-----------
void MostrarEmpleado(Empleado Empleados[], int N)
{
	printf("\n\nLa clave del/la emplead@ es: %d", Empleados[0].Clave); 
	printf("\nEl nombre del/la emplead@ es: %s", Empleados[0].Nombre);
	printf("\nLa edad del/la emplead@ es: %d", Empleados[0].Edad);
	printf("\nEl salario del/la emplead@ es: %.2lf", Empleados[0].Salario);
	if(Empleados[0].Sexo == 1)
	{
		printf("\nEl sexo del/la emplead@ es: Hombre");
	}else
	{
		printf("\nEl sexo del/la emplead@ es: Mujer");
	}
}
