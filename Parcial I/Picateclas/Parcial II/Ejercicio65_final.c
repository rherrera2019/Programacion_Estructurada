/*
Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.1
Descripcion: Que lea dos matrices de M X N elementos y que determine e
imprima si la diagonal principal de la primera es igual a la diagonal
principal de la segunda.
Fecha de creacion: 9/mar/2019
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
	int m; //Variable que define el tamano de la fila de las 2 matrices
	int n; //Variable que define el tamano de la columna de las 2 matrices
	
	int c; //Representa columnas
	int f; //Representa filas
	
	int flag = 0; //Bandera que determina si las diagonales de las matrices sus elementos son iguales
	int flag2 = 0; //Bandera que valida si las dimensiones de las matrices ingresadas sean positivas y que la matriz sea cuadrada
	
	int i;
    
	while(flag2==0){ //El proceso no terminará hasta que se ingrese una matriz cuadrática
	
	printf("Ingrese el numero de filas\n"); flag2 = 0;
	while(flag2==0){ //Valida que no se ingrese una dimension negativa
		scanf("%d",&m);
		if(m<0){
			printf("\nDimensión incorrecta, vuelve a ingresar el numero de filas: ");
		}
		else{
			flag2 = 1; 
		}
	}
	printf("Ingrese el numero de columnas\n"); flag2 = 0;
	while(flag2==0){ //Valida que no se ingrese una dimension negativa
		scanf("%d",&n);
		if(n<0){
			printf("\nDimensión incorrecta, vuelve a ingresar el numero de columnas: ");
		}
		else{
			flag2 = 1;
		}
	}

	
	//Se definen las 2 matrices
	float a[m][n]; 
	float b[m][n];
	
	/*Primero se determina si la matriz es cuadrática*/
	
	if (m==n) {
		/*ENTRADA*/
		
		printf("Ingrese los elementos de la matriz A\n");
		for (f=0;f<m;f++) {
			for (c=0;c<n;c++) {
				printf("Ingrese el elemento de la matriz A(%d, %d)\n",f+1,c+1);
				scanf("%f",&a[f][c]);
			}
		}
		
		printf("Ingrese los elementos de la matriz B\n");
		for (f=0;f<m;f++) {
			for (c=0;c<n;c++) {
				printf("Ingrese el elemento de la matriz B(%d, %d)\n",f+1,c+1);
				scanf("%f",&b[f][c]);
			}
		}
		
		/*PROCESO*/
		for (i=0;i<m;i++) { //Determina si las diagonales son diferentes y en caso de serlo dara la bandera 1
			if (a[i][i]!=b[i][i]) {
				flag = 1;
			}
		}
		
		/*SALIDA*/
		if (flag==0) { //Si la bandera es 0, significa que el valor de sus diagonales de ambas matrices son iguales
			printf("\nLas diagonales principales de ambas matrices son iguales\n");
		} 
		else { //Caso contrario si la bandera es 1, no son iguales
			printf("\nLas diagonales principales de ambas matrices no son iguales\n");
		}
	}
	
	else {
		system("cls"); //Limpia consola
		printf("No es cuadratica\n");
		flag2 = 0;
	}
	} //Termina ciclo while de validacion cuadrática
    
	getch();
	
	return 0;
}

/*
Nombre Equipo revisado : Compiladores
Descripcion: 1.- El programa no valida si se ingresan numeros negativos para las filas y columnas
             2.- El programa compara las filas y columnas para validar si la matriz es cuadrada
                pero no pide de nuevo los datos.
Fecha: 21/mar/2019
*/
