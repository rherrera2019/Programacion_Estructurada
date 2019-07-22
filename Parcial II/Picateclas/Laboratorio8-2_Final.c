/*Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1. 0. 0
Descripcion del programa:E.P. que lea un vector de 20 elementos que sean enteros 
y determine e imprima la suma de los elementos pares y el producto de los 
elementos impares.
Fecha de creacion: 10/Marzo/2019
*/

#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[]) {
	//IDENTIFICADORES
	int elementos[20];//ARREGLO
	int sum=0, mul=1;
	
	//PROCESOR FOR.
	for (int i=0; i<20; i++){
		//ENTRADA
		printf("\nIngrese el elemento %i: ", i+1);
		scanf(" %i", &elementos[i]);//Lectura del elemento.
		if (elementos[i]%2==0){//Identifica si es par
			printf("Es par\n");
			sum=sum+elementos[i];//SUMA
		}else{//Si no es par, entonces es impar.
			printf("Es impar\n");
			mul=mul*elementos[i];//PRODUCTO
		}
	}
	//SALIDAS
	printf("\nLa suma de los elementos pares es: %i", sum);
	printf("\nEl productos de los elementos impares es: %i", mul);
	
	getch();
	
	return 0;
}

//Funciona bien
