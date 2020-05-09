#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <stdlib.h>

/*
Nombre: ASIGNACIÓN DE MEMORIA A UN ARREGLO CON MALLOC Y REDIMENCIONAR CON REALLOC
Descripción:  E.P. que reserve memoria para un arreglo de 10 elementos de tipo float, 
rellenarlo con datos que digite el usuario, luego utilizar realloc para ampliar 
dicho arreglo a 20 elementos e imprimir el arreglo resultante.
Autores: Victor Enrique Cauich Davalos & Alan Josue Barón Pat
Version: 1.0
Fecha: 24/03/2020
*/

//prototipo de funciones
void ValidarN(int N, float *Vector);//Para validar cuántos elementos tendrá el array
void IngresarDatosDelArray(int N, float *Vector);
void ImprimirArray(int N, float *Vector);

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	printf("PROGRAMA QUE ASIGNA MEMORIA DE 10 ELEMENTOS A UN ARREGLO \nCON MALLOC Y REDIMENCIONAR CON REALLOC A 20 ELEMENTOS.");
	int N = 10;//cantidad de alumnos
	float *Vector;
	
	//Vemos si hay memoria suficiente para almacenar todos los elementos del array
	ValidarN(N, Vector);
	
	printf("\n\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-------------------Función que valida cantidad de elementos que tendrá el array---------------
void ValidarN(int N, float *Vector)
{
	//Vemos si hay memoria suficiente para almacenar todos los elementos del array
	Vector = (float*)malloc(N*sizeof(float));
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
		N = 20;
		Vector = (float*)realloc(Vector, N*sizeof(float));//redimencionamos el vector
		printf("LOS ELEMENTOS DEL ARRAY SON:\n");
		ImprimirArray(N, Vector);
	}
}
//-------------------------Función para asignar valores a los elementos del array-------------
void IngresarDatosDelArray(int N, float *Vector)
{
	for(int i = 0; i < N; i++)
	{
		printf("\nIngrese el entero del elemento #%d del array, por favor: ", i + 1);
		scanf("%f", &*(Vector+i));
	}
}
//-------------------------Función para imprimir los elementos del array-----------------------
void ImprimirArray(int N, float *Vector)
{
	for(int i = 0; i < N; i++)
	{
		printf("\nEl entero del elemento #%d del array es: %.2f.", i + 1, *(Vector+i));
	}
}
