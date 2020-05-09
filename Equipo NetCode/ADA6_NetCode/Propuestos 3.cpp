#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: SEPARAR NEGATIVOS Y POSITIVOS EN DOS ARREGLOS
Descripción: Leer 30 elementos en un arreglo y dividir los positivoos y negativos en arreglos separados.
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 2.0
Fecha: 9/03/2020
*/

#define N 30//definimos el número de elementos que tendrá el array

int Inicializar(int Array[]);
int CalcularLosPositivos(int Array[N], int ArrayPositivos[N]);
int CalcularLosNegativos(int Array[N], int ArrayNegativos[N]);
void ImprimirArray(int Array[N]);

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int i = 0;
	int Array[N], ArrayPositivos[N], ArrayNegativos[N];
	
	while(i < N)
	{
		printf("Ingrese el elemento #%d del array, por favor: ", i + 1);
		scanf("%d", &Array[i]);
		i++;
	}
	
	*ArrayPositivos = Inicializar(ArrayPositivos);
	*ArrayNegativos = Inicializar(ArrayNegativos);
	*ArrayPositivos = CalcularLosPositivos(Array, ArrayPositivos);
	*ArrayNegativos = CalcularLosNegativos(Array, ArrayNegativos);
	printf("\nNUMEROS POSITIVOS:");
	ImprimirArray(ArrayPositivos);
	printf("\nNUMEROS NEGATIVOS:");
	ImprimirArray(ArrayNegativos);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-------------------------------Inicializamos los Arras-------------------
int Inicializar(int Array[N])
{
	int i = 0;
	
	while(i < N)
	{
		Array[i] = 0;
		i++;
	}
	
	return *Array;
}
//-----------------Función para calcular los números positivos-------------
int CalcularLosPositivos(int Array[N], int ArrayPositivos[N])
{
	int i = 0, t = 0;
	while(i < N)
	{
		if(Array[i] > 0)
		{
			ArrayPositivos[t] = Array[i];
			t++;
		}
		i++;
	}
	return *ArrayPositivos;
}
//-----------------Función para calcular los números negativos-------------
int CalcularLosNegativos(int Array[N], int ArrayNegativos[N])
{
	int i = 0, t = 0;
	while(i < N)
	{
		if(Array[i] < 0)
		{
			ArrayNegativos[t] = Array[i];
			t++;
		}
		i++;
	}
	return *ArrayNegativos;
}
//-----------------Función para imprimir Arrays-----------------------------
void ImprimirArray(int Array[N])
{
	int i = 0;
	while(i < N)
	{
		if(Array[i] != 0)
		{
			printf("\nEl #%d es: %d", i + 1, Array[i]);
		}
		i++;
	}
}
