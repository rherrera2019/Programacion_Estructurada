/*
Programa: Ejercicio 56
Nombre equipo: Picateclas
Descripción: E.P. que lea una matriz de 3 X 3 elementos y los imprima.
Version: 1.0
Fecha de creación: 13/mar/2019
*/
#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[]) {
	//IDENTIFICADOR.
	float x[3][3];//ARREGLO.
	int i, j;
	
	//LECTURA.
	for(i=0;i<3;i++){//Se tuvo que inicializar en 0, ya que el programa daba un error al ejecutarlo.
		for(j=0;j<3;j++){
			printf("\nIngrese número de la fila %d, columna %d: ", i+1, j+1);//Ingresar el elemento
			scanf(" %f",&x[i][j]);//Se guarda el valor en la fila "i" y columna "j"
		}
	}
	
	//PROCESO (para imprimir matriz).
	for(i=0;i<3;i++){
		printf("\n");//Salto para que al imprimir quede como una matriz.
		for(j=0;j<3;j++){
			//SALIDAS.
			printf(" %.2f", x[i][j]);
		}
	}
	
	getch();
	
	return 0;
}

/*
Revisado por: los compiladores 
-Funciona bien en general


*/
