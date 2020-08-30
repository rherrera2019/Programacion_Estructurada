#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: MATRIZ NXM, IMPRIMIR POSICI�N DE ELEMENTOS NEGATIVOS
Descripci�n: E.P. que lea una matriz de N X M elementos y 
que encuentre e imprima la posici�n de los elementos negativos.
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 11/03/2020
*/

int ValidarFilasOColumnas();//Funci�n para validar el n�mero de filas y columnas

int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	printf("PROGRAMA DE UNA MATRIZ NXM, IMPRIMIR POSICI�N DE ELEMENTOS NEGATIVOS.");
	
	//Ingresamos cu�ntas filas habr�n
	printf("\nIngresamos el n�mero de filas...");
	int N = ValidarFilasOColumnas();
	
	//Ingresamos cu�ntas columnas habr�n
	printf("\nIngresamos el n�mero de columnas...");
	int M;
	M = ValidarFilasOColumnas();
	
	//Se llama a la funci�n para ingredar datos de la matriz
	printf("\nIngrese los valores de la matriz...\n");
	//Otorgar valor de cada elemento de la matriz
	int Matriz[N][M];
	int i = 0, t = 0;
	while(i < N)
	{
		while(t < M)
		{
			printf("\nIngrese el valor de la matriz[%d][%d], por favor: ", i + 1, t + 1);
			scanf("%d", &Matriz[i][t]);
			t++;
		}
		t = 0;
		i++;
	}
	
	bool confirm = false;
	//Imprimimos la Matriz
	printf("\nSu Matriz es este:\n");
	i = 0, t = 0;
	while(i < N)
	{
		while(t < M)
		{
			printf("%d ", Matriz[i][t]);
			if(Matriz[i][t] < 0)
			{
				confirm = true;
			}
			t++;
		}
		printf("\n");
		t = 0;
		i++;
	}
	
	//Determinamos los n�meros negativos (sus posiciones)
	if(confirm == true)
	{
		printf("\nPOSICIONES DE LOS N�MEROS NEGATIVOS...");
		for( i = 0; i < N; i++)
		{
			for( t = 0; t < M; t++)
			{
				if(Matriz[i][t] < 0)
				{
					printf("\nPosici�n [%d][%d].", i, t);
				}
			}
		}
	}else
	{
		printf("\n\nNO HAY N�MEROS NEGATIVOS...");
	}
	
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-------------Validamos el n�mero de filas o columnas-----------
int ValidarFilasOColumnas()
{
	int X;
	do
	{
		printf("\nIngrese el n�mero por favor: ");
		scanf("%d", &X);
		if(X < 1)
		{
			printf("\nERROR, ingrese un n�mero mayor a 0...");
		}
	}while(X < 1);
	return X;
}
