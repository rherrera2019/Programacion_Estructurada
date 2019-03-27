/*
Programa: SumaDeVectores_while.C
Nombre equipo: Picateclas
Descripción:  Lee dos vectores de n elementos y genera e imprime
un tercer vector con la suma de cada uno de los elementos de los dos
anteriores.
Version: 1.1
Fecha de creación: 6/mar/2019
*/

#include <stdio.h>
#include <conio.h>


int main(int argc, char *argv[]) {
	int n, i=0;
	printf("Inserte el tamaño de los vectores: ");
	scanf(" %d", &n);
	
	float arreglo_1[n], arreglo_2[n], arreglo_3[n];
	
	//ENTRADA- leer primer vector
	while(i<n){
		printf("\nInserte el elemento %i del primer vector: ", i+1);
		scanf(" %f", &arreglo_1[i]);
		i++;
	}
	
	
	//ENTRADA- leer segundo vector
	i=0;
	while(i<n){
		printf("\nInserte el elemento %i del segundo vector: ", i+1);
		scanf(" %f", &arreglo_2[i]);
		i++; //Por que usar j en esta situacion si en los otros 3 ciclos se utilizó el i
	}
	
	//PROCESO- Calcular la suma de los elementos de los vectores y generar tercer vector
	i=0;
	while(i<n){
		arreglo_3[i]= arreglo_1[i] + arreglo_2[i];
		i++;
	}
	
	//SALIDA- imprimir tercer vector
	printf("\nResultados: \n");
	i=0;
	while(i<n){
		printf("\nLa suma de los vectores en la posición %i es %.3f\n", i+1, arreglo_3[i]);//hubiera preferido si me decia que poscion es que imprima "Posicion %d del arreglo 3"
		i++;
	}
	
	getch();
	return 0;
}

