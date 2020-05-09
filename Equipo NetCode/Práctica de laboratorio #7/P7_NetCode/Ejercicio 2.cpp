#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: EL CUADRADO MÁGICO
Descripción:  E.P. que permita leer una matriz de 3 x 3 elementos 
que contenga números enteros e indique si se trata de un cuadrado mágico.  
Dicho cuadrado mágico es cuando la sumatoria de los elementos 
es 15 por renglones, columnas o diagonales.
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 2.0
Fecha: 9/03/2020
*/

#define N 3 //Tamaño de filas y columnas de la matriz
#define Correct 15//Núnmero que deben de dar las sumatorias de filas, columnas y diagonal

int IngresarDatosDePersonas(int Matriz[N][N]);//Función para ingresar datos de la matriz
bool VerificarFilas(int Matriz[N][N], bool Confirmacion);//Función para verificar suma de filas
bool VerificarColumnas(int Matriz[N][N], bool Confirmacion);//Función para verificar suma de columnas
bool VerificarDiagonales(int Matriz[N][N], bool Confirmacion);//Función para verificar suma de diagonales
void ImprimirMatriz(int Matriz[N][N]);//Impresión de Matriz


int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int Matriz[N][N];
	bool Confirmacion = true;
	printf("PROGRAMA DE CUADRADO PERFECTO.");
	printf("\nIngrese los valores de la matriz...\n");
	//Otorgar valor de cada elemento de la matriz
	**Matriz = IngresarDatosDePersonas(Matriz);
	//Imprimimos la Matriz
	printf("Su Matriz es este:\n");
	ImprimirMatriz(Matriz);
	//Verificamos que la sumatoria de las filan den 15
	Confirmacion = VerificarFilas(Matriz, Confirmacion);
	if(Confirmacion == true)
	{
		//Verificamos columnas
		Confirmacion = VerificarColumnas(Matriz, Confirmacion);
		if(Confirmacion == true)
		{
			//Verificamos diagonales
			Confirmacion = VerificarDiagonales(Matriz, Confirmacion);
			if(Confirmacion == true)
			{
				printf("El cuadrado es Mágico....\n");
			}else
			{
				printf("El cuadrado es inmagico...\n");
			}
		}else{
			printf("El cuadrado es inmagico...\n");
		}
	}else
	{
		printf("El cuadrado es inmagico...\n");
	}
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//------------------Ingresar datos de la matriz------------------
int IngresarDatosDePersonas(int Matriz[N][N])
{
	int i = 0, t = 0;
	while(i < N)
	{
		while(t < N)
		{
			printf("Ingrese el valor de la matriz[%d][%d], por favor: ", i + 1, t + 1);
			scanf("%d", &Matriz[i][t]);
			fflush(stdin);
			t++;
		}
		t = 0;
		i++;
	}
	return **Matriz;
}
//------------------Función para verificar suma de filas------------------
bool VerificarFilas(int Matriz[N][N], bool Confirmacion)
{
	int i = 0, t = 0, Suma = 0;
	while(i < N)
	{
		while(t < N)
		{
			Suma = Suma + Matriz[i][t];
			t++;
		}
		
		if(Suma != Correct)
		{
			Confirmacion = false;
			return Confirmacion;
		}
		Suma = 0;
		t = 0;
		i++;
	}
	
	return Confirmacion;
}
//------------------Función para verificar suma de columnas------------------
bool VerificarColumnas(int Matriz[N][N], bool Confirmacion)
{
	int i = 0, t = 0, Suma = 0;
	while(t < N)
	{
		while(i < N)
		{
			Suma = Suma + Matriz[i][t];
			i++;
		}
		
		if(Suma != Correct)
		{
			Confirmacion = false;
			return Confirmacion;
		}
		Suma = 0;
		i = 0;
		t++;
	}
	
	return Confirmacion;
}
//--------------------Función para verificar suma de diagonales---------------
bool VerificarDiagonales(int Matriz[N][N], bool Confirmacion)
{
	int i = 0, t = 0, Suma = 0;
	
	for(i = 0; i < N; i++)
	{
		Suma = Suma + Matriz[i][i];
	}
	
	if(Suma != Correct)
	{
		Confirmacion = false;
		return Confirmacion;
	}
		
	t = N;
	
	for(i = 0; i < N; i++)
	{
		Suma = Suma + Matriz[i][t];
		t--;
	}
	
	return Confirmacion;
}
//--------------------Función que imprime la matriz---------------
void ImprimirMatriz(int Matriz[N][N])
{
	int i = 0, t = 0;
	while(i < N)
	{
		while(t < N)
		{
			printf("%d ", Matriz[i][t]);
			t++;
		}
		printf("\n");
		t = 0;
		i++;
	}
}

