#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: MATRIZ NXM Y SUS IMPARES Y PARES
Descripción: E.P. que lea una matriz de N X M elementos 
y que cuente e imprima cuantos elementos son pares y 
cuantos son impares.
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 11/03/2020
*/

int ValidarFilasOColumnas();//Función para validar el número de filas y columnas

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	printf("PROGRAMA DE UNA MATRIZ DE NXM Y SUS IMPARES Y PARES.");
	
	//Ingresamos cuántas filas habrán
	printf("\nIngresamos el número de filas...");
	int N = ValidarFilasOColumnas();
	
	//Ingresamos cuántas columnas habrán
	printf("\nIngresamos el número de columnas...");
	int M;
	M = ValidarFilasOColumnas();
	
	//Se llama a la función para ingredar datos de la matriz
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
	
	//Calculamos la cantidad de números pares e impares que hay
	int Pares = 0, Impares = 0;
	
	for(i = 0; i < N; i++)
	{
		for(t = 0; t < M; t++)
		{
			if(Matriz[i][t]%2 == 0)
			{
				Pares++;
			}else
			{
				Impares++;
			}
		}
	}
	
	//Imprimimos cuántos pares e impares hay
	printf("\n\nHay %d Pares en la matriz.", Pares);
	printf("\nHay %d Impares en la matriz.", Impares);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-------------Validamos el número de filas o columnas-----------
int ValidarFilasOColumnas()
{
	int X;
	do
	{
		printf("\nIngrese el número por favor: ");
		scanf("%d", &X);
		if(X < 1)
		{
			printf("\nERROR, ingrese un número mayor a 0...");
		}
	}while(X < 1);
	return X;
}
