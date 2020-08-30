#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: MATRIZ 3X3, LEER E IMPRIMIR
Descripci�n: E.P. que lea una matriz de 3 X 3 elementos y los imprima.
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 11/03/2020
*/

#define N 3 //Tama�o de filas y columnas de la matriz

int IngresarDatosDeMatriz(int Matriz[N][N]);//Funci�n para ingresar datos de la matriz
void ImprimirMatriz(int Matriz[N][N]);//Impresi�n de Matriz


int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int Matriz[N][N];
	printf("PROGRAMA DE UNA MATRIZ DE 3X3 DE ENTEROS.");
	printf("\nIngrese los valores de la matriz...\n");
	//Otorgar valor de cada elemento de la matriz
	**Matriz = IngresarDatosDeMatriz(Matriz);
	//Imprimimos la Matriz
	printf("Su Matriz es este:\n");
	ImprimirMatriz(Matriz);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//------------------Ingresar datos de la matriz------------------
int IngresarDatosDeMatriz(int Matriz[N][N])
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

//--------------------Funci�n que imprime la matriz---------------
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
