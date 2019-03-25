/*
Programa: Ejercicio 58
Nombre equipo: Picateclas
Descripción: E.P. que lea una matriz de 6 X 4 elementos y que calcule e
imprima la suma de sus elementos.
Version: 1.0
Fecha de creación: 13/mar/2019
*/
#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[]) {
	float x[6][4], SUM=0;
	int i, j;
	
	//PROCESO (lectura).
	for(i=0;i<6;i++){
		for(j=0;j<4;j++){
			printf("\nIngrese numero fila %d columna %d: ", i+1, j+1);//Ingresar el elemento
			scanf(" %f",&x[i][j]);//Se guarda el valor en la fila "i" y columna "j"
			SUM=SUM+x[i][j];
		}
	}
	printf("\nLa suma de los elementos de la matriz es: %f", SUM);
	getch();
	return 0;
}

/*
Revisado por: los compiladores 
-Funciona bien en general
-al iprimir la sumatoria imprime muchos ceros 

*/
