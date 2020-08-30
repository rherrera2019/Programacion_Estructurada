#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: MATRIZ 20X30 Y LA SUMATORIA DE CADA FILA
Descripción: E.P. que lea una matriz de 20 X 30 elementos y 
que genere e imprima un vector de 20 elementos que contenga 
la sumatoria de cada fila de la matriz.
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 11/03/2020
*/

#define N 2//Tamaño de filas
#define M 3//Tamaño de colummas

int IngresarDatosDeMatriz(int Matriz[N][M]);//Función para ingresar datos de la matriz
void ImprimirMatriz(int Matriz[N][M]);//Impresión de Matriz
int InicializarArray(int Array[N]);//Función para inicializar Array
int CalcularSumaFilas(int Matriz[N][M], int Array[N]);//Función para calcular suma de cada fila de la matriz
void ImprimirArray(int Array[N]);//Impresión de la suma de cada fila de la matriz

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	printf("PROGRAMA DE UNA MATRIZ 20X30 Y LA SUMATORIA DE CADA FILA.");
	
	int Matriz[N][M], SumaFilas[N];
	
	//Se llama a la función para ingredar datos de la matriz
	printf("\nIngrese los valores de la matriz...\n");
	//Otorgar valor de cada elemento de la matriz
	
	printf("\nIngrese los valores de la matriz...\n");
	//Otorgar valor de cada elemento de la matriz
	**Matriz = IngresarDatosDeMatriz(Matriz);
	
	//Imprimimos la Matriz
	printf("\nSu Matriz es este:\n");
	ImprimirMatriz(Matriz);
	
	//Calculamos la suma de cada fila de la matriz
	*SumaFilas = InicializarArray(SumaFilas);
	*SumaFilas = CalcularSumaFilas(Matriz, SumaFilas);
	
	//Imprimimos el resultado de la suma de cada fila de la matriz
	printf("\nRESULTADO DE LA SUMA DE CADA FILA DE LA MATRIZ.");
	ImprimirArray(SumaFilas);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//------------------Ingresar datos de la matriz------------------
int IngresarDatosDeMatriz(int Matriz[N][M])
{
	int i = 0, t = 0;
	while(i < N)
	{
		while(t < M)
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

//--------------------Función que imprime la matriz--------------------
void ImprimirMatriz(int Matriz[N][M])
{
	int i = 0, t = 0;
	while(i < N)
	{
		while(t < M)
		{
			printf("%d ", Matriz[i][t]);
			t++;
		}
		printf("\n");
		t = 0;
		i++;
	}
}
//-------------Función para inicializar Array---------------------------
int InicializarArray(int Array[N])
{
	for(int i = 0; i < N; i++)
	{
		Array[i] = 0;
	}
	return *Array;
}
//--------------Función para calcular Suma de filas---------------------
int CalcularSumaFilas(int Matriz[N][M], int Array[N])
{
	int Suma = 0, i, t;
	for(i = 0; i < N; i++)
	{
		for(t = 0; t < M; t++)
		{
			Suma = Suma + Matriz[i][t];
		}
		Array[i] = Suma;
		Suma = 0;	
	}
	return *Array;
}
//-Función para imprimir Array que tiene suma de cada fila de la matriz--
void ImprimirArray(int Array[N])
{
	for(int i = 0; i < N; i++)
	{
		printf("\nLa suma de la fila #%d es: %d.", i + 1, Array[i]);
	}
}
