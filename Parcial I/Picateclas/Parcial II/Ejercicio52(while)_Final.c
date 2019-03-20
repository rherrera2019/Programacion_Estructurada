/*
Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.0
Descripcion: Lee un vector de n elementos y calcula e imprime su producto.
Fecha de creacion: 2/mar/2019
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int N; //Numero de elementos
	int pos = 0; //Contador y posicionador del elemento del vector
	float MUL; //Producto de los elementos del vector
	
	//ENTRADA
	/*Se define la variable N e ingresa el numero de elementos que contendra el 
	vector*/
	printf("Ingrese el número de elementos que contendrá el vector: ");
	scanf(" %d",&N);
	
	float V[N]; //Se define el vector de N numeros decimales
	
	//PROCESO
	/*Se leen c/u de los elementos del vector y se van multiplicando y guardando en
	la variable MUL*/
	printf("\nUsted a ingresado un vector de %d elementos", N);
	printf("\nIngrese los %d elementos\n",N);
	
	while(pos<N){
		pos++;
		printf("Elemento %d: ",pos);
		scanf(" %f",&V[pos]);
		
		if(pos == 1){
			MUL = V[pos];
		}
		else{
			MUL *= V[pos];
		}
	}
	
	//SALIDA
	/*Imprime el producto*/
	printf("EL producto de todos elementos ingresados es de: %.2f", MUL);
	return 0;
}

//Creo que en vez de poner un if/else para definir MUl en 1 pudieron poner a MUl=1 se multiplicaba por 1 el primero y daba lo mismo
//Josue Torres
