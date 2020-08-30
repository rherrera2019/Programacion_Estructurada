#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: MODA DEL ARREGLO
Descripci�n: Calcular la moda el arreglo.
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 2.0
Fecha: 9/03/2020
*/

#define N 10//definimos el n�mero de elementos que tendr� el array

void CalcularModa(int Array[], int Repeticiones[]);
int Inicializar(int Repeticiones[]);
void CalcularRepetidas(int Array[], int Repeticiones[]);
int CalcularRepetidas1(int Array[], int Repeticiones[]);


int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int ContModa, Moda, i = 0;
	int Array[N], Repeticiones[N];
	
	while(i < N)
	{
		printf("Ingrese el elemento #%d del array, por favor: ", i + 1);
		scanf("%d", &Array[i]);
		i++;
	}
	
	CalcularModa(Array, Repeticiones);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//----------------------------Funci�n para empezar a calcular moda-----------------------
void CalcularModa(int Array[N], int Repeticiones[N])
{
	CalcularRepetidas(Array, Repeticiones);
}
//-----------------Funci�n para determinar cu�ntas veces se repite cada n�mero-----------
void CalcularRepetidas(int Array[N], int Repeticiones[N])
{
	int i = 0, t = 0, Num;
	
	*Repeticiones = Inicializar(Repeticiones);
	
	//Buscamos las repeticiones
	while(i < N)
	{
		Num = Array[i];
		while(t < N)
		{
			if(Num == Array[t])
			{
				Repeticiones[i] = Repeticiones[i] + 1;
			}
			t++;
		}
		t = 0;
		i++;
	}
	
	int NumMayor = CalcularRepetidas1(Array, Repeticiones);
	
	if(NumMayor != -1)
	{
		printf("\n\nLa moda ser�a el n�mero %d.\n", NumMayor);
	}else
	{
		printf("\n\nNO EXISTE MODA...\n");
	}
}
//-----------------------Vemos cu�l es el n�mero mayor de repeticiones-------------------
int CalcularRepetidas1(int Array[], int Repeticiones[])
{
	int NumMayorRepit = 0, NumMayor, i = 0;
	
	while(i < N)
	{
		if(i == 0)
		{
			NumMayorRepit = Repeticiones[i];
			NumMayor = Array[i];
		}else
		{
			if(Repeticiones[i] > NumMayorRepit)
			{
				NumMayorRepit = Repeticiones[i];
				NumMayor = Array[i];
			}
		}
		i++;
	}
	
	i = 0;
	
	while(i < N)
	{
		if((Repeticiones[i] == NumMayorRepit) && (NumMayor != Array[i]))
		{
			return -1;
		}
		i++;
	}
	
	return NumMayor;
}
//-------------------------------Inicializamos el array de repeticiones-------------------
int Inicializar(int Repeticiones[N])
{
	int i = 0;
	
	while(i < N)
	{
		Repeticiones[i] = 0;
		i++;
	}
	
	return *Repeticiones;
}
