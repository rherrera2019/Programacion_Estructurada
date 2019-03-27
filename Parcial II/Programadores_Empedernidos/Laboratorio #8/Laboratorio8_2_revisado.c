/*
Nombre: 51_producto.c
Autor: Programadores empedernidos
Descripción: E.P. que lea un vector de 10 elementos y que calcule e imprima la suma de los numeros pares
y el producto de los numeros impares.
Fecha: 06/03/2019
Versión: 1.0
*/

#include <stdio.h>
#define SIZE 10

int main(){
	int vector[SIZE]; //declación del vector.
	int sumador=0, producto=1, i;
	
	for(i=0; i<SIZE; i++){ //ciclo for para entrada de datos
		printf("Ingresa el elemento #%d del vector> ", i+1);
		scanf("%d", &vector[i]);
		
		if(vector[i] % 2 == 0){ //Proceso de verificación
			sumador+=vector[i]; //suma de números pares
		}
		else{
			producto*=vector[i]; //producto de números impares
		}
	}
	
	//salida.
	printf("\nLa suma de los n\243meros pares es %d y el producto de los numeros impares es %d", sumador, producto);
	
	return 0;
}
/*
QA
funciona correctamente,bien documentado y codigo legible
Revisó:Los Compiladores_Carlos Arturo Álvarez Trejo

*/
