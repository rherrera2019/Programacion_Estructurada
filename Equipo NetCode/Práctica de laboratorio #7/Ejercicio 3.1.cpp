#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: 2do REPORTE DE NOMBRE, PESO Y ESTATURA
Descripción: que lea un arreglos de una estructura de arreglos
de n x 3 elementos que contenga el nombre, peso y estatura de 
n personas; determinar el peso y la estatura promedio, así como
imprimir el mismo reporte del anterior ejercicio.
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 2.0
Fecha: 9/03/2020
*/

#define Correct 15//Núnmero que deben de dar las sumatorias de filas, columnas y diagonal

int IngresarDatosDeMatriz(int Matriz, int X, int Y);//Función para ingresar datos de la matriz
int Multiplicacion(int MatrizA, int N, int M, int MatrizB, int L, int K, int MatrizC);//Ffunción para calcular multiplicación
void ImprimirMatriz(int Matriz, int X, int Y);//Impresión de Matriz


int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int N, M, L, K;
	printf("PROGRAMA DE MULTIPLICACIÓN DE MATRICES.");
	//Validando que las columnas de la MatrizA sea igual a las filas de la MatrizA
	printf("Ingrese los datos de las filas y columnas...\n");
	do{
		printf("\nIngrese cuántas filas tendrá la MatrizA, por favor: ");
		scanf("%d", &N);
		printf("\nIngrese cuántas columnas tendrá la MatrizA, por favor: ");
		scanf("%d", &M);
		printf("\nIngrese cuántas filas tendrá la MatrizB, por favor: ");
		scanf("%d", &L);
		printf("\nIngrese cuántas columnas tendrá la MatrizB, por favor: ");
		scanf("%d", &K);
		if(M != L)
		{
			printf("ERROR, el número de columnas de la MatrizA,\nDebe ser igual al número de filas de la matrizB");
		}
	}while(M != L);
	int MatrizA[N][M], MatrizB[L][K], MatrizC[N][K]; 
	//Ingresando los valores de la MatrizA
	printf("\nIngrese los valores de la matriz 1...\n");
	//Ingresando los valores de la MatrizB
	printf("\nIngrese los valores de la matriz 1...\n");
	**MatrizB = IngresarDatosDeMatriz(**MatrizB, L, K);
	//Imprimimos las Matrices
	printf("\nMatrizA: \n");
	ImprimirMatriz(**MatrizA, N, M);
	printf("\nMatrizB: \n");
	ImprimirMatriz(**MatrizB, L, K);
	//Calculando la multiplicación de la MatrizA y MatrizB
	**MatrizC = Multiplicacion(**MatrizA, N, M, **MatrizB, L, K, **MatrizC);
	printf("\nMatrizC(Multiplicación): \n");
	ImprimirMatriz(**MatrizC, N, K);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-------------Ingresando datos de las Matrices---------
int IngresarDatosDeMatriz(int Matriz, int X, int Y)
{
	for(int i = 0; i < X, i++)
	{
		for(int t = 0; t < Y; t++)
		{
			printf("Ingresa el número de la matriz[%d][%d]: ", i + 1, t + 1);
			scanf("%d", &Matriz[i][t]);
			fflush(stdin);
		}
	}
	return **Matriz;
}
//---------Función para calcular la Matriz de multiplicación------
int Multiplicacion(int MatrizA[N][M], int N, int M, int MatrizB[L][K], int L, int K, int MatrizC[N][K])
{
	int H = L;
	for(int i = 0; i < N; i++)
	{
		for(int t = 0; t < K; t++)
		{
			for(int j = 0; j < M; j++)
			{
				MatrizC[i][t] = MatrizC[i][t] + (MatrizA[i][M] * MatrizB[M][t]);
			}
		}
	}
	return **MatrizC;
}
//--------------------Función que imprime la matriz---------------
void ImprimirMatriz(int Matriz[X][Y], int X, int Y)
{
	Matriz[X][Y];
	for(int i = 0; i < X, i++)
	{
		for(int t = 0; t < Y; t++)
		{
			printf("%d ", Matriz[i][t]);
		}
	}
}

