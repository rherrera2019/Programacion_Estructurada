/*
Problema:Pedir al usuario el número de elementos para un arreglo de
números enteros, posteriormente comprobar con malloc si hay
memoria suficiente (si el puntero es válido, es decir diferente de
NULL), si la hay, entonces leer y luego imprimir dicho arreglo; si no,
indicar un error en la asignación de memoria.
Equipo:Los Compiladores
Fecha: 31/marzo/2019
Version: 1.0 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *pe;
	int tam;
	int f;
	/*ENTRADA */
	printf("Cuantos elementos tendra el vector: "); //leemos los elementos del vector
	scanf("%i",&tam);
	pe=malloc(tam*sizeof(int)); //reservamos memoria para n elementos
	while(pe == NULL){
		printf("\nError en la Asignacion de memoria"); //se indicar un error en la asignación de memoria
		printf("\nCuantos elementos tendra el vector: "); //se pide de nuevo el total de elementos que tendra el vector
		scanf("%i",&tam);
		pe=malloc(tam*sizeof(int)); //reservamos memoria para n elementos
	}
	system("pause");
	system("cls");
	/*ENTRADA */
		for(f=0;f<tam;f++) //leemos los valores del vector
		{
			printf("\nIngrese elemento %d: ",f+1);
			scanf("%i",&pe[f]);
		}
		system("cls");
		/*SALIDA*/
		printf("\n\nContenido del vector: ");
		for(f=0;f<tam;f++) //se imprime los valores del vector
		{
			printf("\n Elemento %d: %i ",f+1,pe[f]);
		}
		free(pe);
		getchar();

		
	return 0;
}


/*Revisó: Programadores empedernidos. Fecha: 01/04/19

-El programa funciona bien.
-Nos gustó que cuando muestra el error en la asignación de memoria se preguntara al usuario
otra vez el tamaño del vector.
-Nombre de variables representativas.
*/
