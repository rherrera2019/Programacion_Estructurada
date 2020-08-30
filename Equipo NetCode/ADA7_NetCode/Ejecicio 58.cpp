#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: MATRIZ 6X4 Y LA SUMA DE SUS ELEMENTOS
Descripción: E.P. que lea una matriz de 6 X 4 elementos y 
que calcule e imprima la suma de sus elementos.
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 11/03/2020
*/

#define N 6 //Tamaño de filas
#define M 4//Tamaño de columnas

int IngresarDatosDeMatriz(int Matriz[N][M]);//Función para ingresar datos de la matriz
void ImprimirMatriz(int Matriz[N][M]);//Impresión de Matriz
int CalcularSuma(int Matriz[N][M]);//Se calcula la suma de los elementos

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int Matriz[N][M];
	printf("PROGRAMA DE UNA MATRIZ DE 6X4 DE ENTEROS Y SU SUMA.");
	
	printf("\nIngrese los valores de la matriz...\n");
	//Otorgar valor de cada elemento de la matriz
	**Matriz = IngresarDatosDeMatriz(Matriz);
	
	//Imprimimos la Matriz
	printf("Su Matriz es este:\n");
	ImprimirMatriz(Matriz);
	
	int Suma = CalcularSuma(Matriz);
	
	printf("\n\nLa Suma de sus elementos es: %d", Suma);
	
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

//--------------------Función que imprime la matriz---------------
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
//-----------Función para calcular suma de elementos---------------
int CalcularSuma(int Matriz[N][M])
{
	int Suma = 0;
	int i = 0, t = 0;
	while(i < N)
	{
		while(t < M)
		{
			Suma = Suma + Matriz[i][t];
			t++;
		}
		t = 0;
		i++;
	}
	return Suma;
}
