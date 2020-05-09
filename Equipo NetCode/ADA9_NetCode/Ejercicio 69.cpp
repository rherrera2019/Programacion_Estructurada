#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <stdlib.h>

/*
Nombre: ASIGNACIÓN DE MEMORIA A UN ARREGLO CON MALLOC
Descripción:  Pedir al usuario el número de elementos para un 
arreglo de números enteros, posteriormente comprobar con malloc 
si hay memoria suficiente (si el puntero es válido, es decir 
diferente de NULL), si la hay, entonces leer  y luego imprimir 
dicho arreglo; si no, indicar un error en la asignación de memoria.
Autores: Victor Enrique Cauich Davalos & Alan Josue Barón Pat
Version: 1.0
Fecha: 24/03/2020
*/

//prototipo de funciones
void ValidarN(int N, int *Vector);//Para validar cuántos elementos tendrá el array
void IngresarDatosDelArray(int N, int *Vector);
void ImprimirArray(int N, int *Vector);

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	printf("PROGRAMA QUE ASIGNA MEMORIA A UN ARREGLO CON MALLOC.");
	int N;//cantidad de alumnos
	int *Vector;
	
	//Vemos si hay memoria suficiente para almacenar todos los elementos del array
	ValidarN(N, Vector);
	
	printf("\n\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-------------------Función que valida cantidad de elementos que tendrá el array---------------
void ValidarN(int N, int *Vector)
{
	printf("Ingrese por favor la cantidad de elementos\nque tendrá el array, por favor: ");
	scanf("%d", &N);
	fflush(stdin);
	
	//Vemos si hay memoria suficiente para almacenar todos los elementos del array
	Vector = (int*)malloc(N*sizeof(int));
	if(Vector == NULL)
	{
		system("cls");
		printf("ERROR, NO SE PUDO ASIGNAR LA MAMORIA\nPOR MEMORIA INSUFICIENTE.");
		printf("\nINTENTE DE NUEVO, POR FAVOR...");
		printf("\nTeclea ENTER para continuar, por favor...");
		getchar();
		system("cls");
		ValidarN(N, Vector);
	}else
	{
		system("cls");
		printf("SI SE PUDO...");
		printf("\nINGRESEMOS LOS VALORES DE CADA ELEMENTO DEL ARRAY:\n");
		IngresarDatosDelArray(N, Vector);
		system("cls");
		printf("LOS ELEMENTOS DEL ARRAY SON:\n");
		ImprimirArray(N, Vector);
	}
}
//-------------------------Función para asignar valores a los elementos del array-------------
void IngresarDatosDelArray(int N, int *Vector)
{
	for(int i = 0; i < N; i++)
	{
		printf("\nIngrese el entero del elemento #%d del array, por favor: ", i + 1);
		scanf("%d", &*(Vector+i));
	}
}
//-------------------------Función para imprimir los elementos del array-----------------------
void ImprimirArray(int N, int *Vector)
{
	for(int i = 0; i < N; i++)
	{
		printf("\nEl entero del elemento #%d del array es: %d.", i + 1, *(Vector+i));
	}
}
