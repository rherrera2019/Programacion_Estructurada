/*
Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.1
Descripcion: Lee un vector de n elementos y calcula e imprime su sumatoria.
Fecha de creacion: 2/mar/2019
*/

#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[]) {
	
	int N; //Número de elementos
	int pos; //Contador y posicionador del elemento del vector
	float sumador = 0.0; //Sumador de los elementos del vector
	
	//ENTRADA
    /*Se define la variable N e ingresa el número de elementos que contendrá el 
	vector*/
	printf("Ingrese el número de elementos que contendrá el vector: ");
	scanf(" %d",&N);
	
	float V[N]; //Se define el vector de N números decimales
	
	//PROCESO
	/*Se leen c/u de los elementos del vector y se van sumando y guardando en
	la variable SUM*/
	printf("\nUsted ha ingresado un vector de %d elementos", N);
	printf("\nIngrese los %d elementos.\n",N);
	for(pos = 1;pos<=N;pos++){
		printf("Elemento %d: ",pos);
		scanf(" %f",&V[pos]);
		
		sumador+=V[pos];
	}
	
	//SALIDA
	/*Imprime la suma*/
	printf("La suma de todos elementos ingresados es de: %.2f", sumador);
	getch();
	return 0;
}

//Estar cambiando entre mayusculas para las variables creo que es un tanto molesto pero de ahi en mas nada,aun asi entiendo que es para resaltarlos
//Josue Trres

