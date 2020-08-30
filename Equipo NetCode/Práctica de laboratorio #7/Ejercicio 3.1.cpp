#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: 2do REPORTE DE NOMBRE, PESO Y ESTATURA
Descripci�n: que lea un arreglos de una estructura de arreglos
de n x 3 elementos que contenga el nombre, peso y estatura de 
n personas; determinar el peso y la estatura promedio, as� como
imprimir el mismo reporte del anterior ejercicio.
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 2.0
Fecha: 9/03/2020
*/

#define Correct 15//N�nmero que deben de dar las sumatorias de filas, columnas y diagonal

int IngresarDatosDeMatriz(int Matriz, int X, int Y);//Funci�n para ingresar datos de la matriz
int Multiplicacion(int MatrizA, int N, int M, int MatrizB, int L, int K, int MatrizC);//Ffunci�n para calcular multiplicaci�n
void ImprimirMatriz(int Matriz, int X, int Y);//Impresi�n de Matriz


int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int N, M, L, K;
	printf("PROGRAMA DE MULTIPLICACI�N DE MATRICES.");
	//Validando que las columnas de la MatrizA sea igual a las filas de la MatrizA
	printf("Ingrese los datos de las filas y columnas...\n");
	do{
		printf("\nIngrese cu�ntas filas tendr� la MatrizA, por favor: ");
		scanf("%d", &N);
		printf("\nIngrese cu�ntas columnas tendr� la MatrizA, por favor: ");
		scanf("%d", &M);
		printf("\nIngrese cu�ntas filas tendr� la MatrizB, por favor: ");
		scanf("%d", &L);
		printf("\nIngrese cu�ntas columnas tendr� la MatrizB, por favor: ");
		scanf("%d", &K);
		if(M != L)
		{
			printf("ERROR, el n�mero de columnas de la MatrizA,\nDebe ser igual al n�mero de filas de la matrizB");
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
	//Calculando la multiplicaci�n de la MatrizA y MatrizB
	**MatrizC = Multiplicacion(**MatrizA, N, M, **MatrizB, L, K, **MatrizC);
	printf("\nMatrizC(Multiplicaci�n): \n");
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
			printf("Ingresa el n�mero de la matriz[%d][%d]: ", i + 1, t + 1);
			scanf("%d", &Matriz[i][t]);
			fflush(stdin);
		}
	}
	return **Matriz;
}
//---------Funci�n para calcular la Matriz de multiplicaci�n------
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
//--------------------Funci�n que imprime la matriz---------------
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

