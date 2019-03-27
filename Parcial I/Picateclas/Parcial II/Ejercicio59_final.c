/*
Nombre equipo: Picateclas
Descripción: E.P. que lea una matriz de M X N elementos y que cuente e
imprima cuantos elementos son pares y cuantos son impares.
anteriores.
Version: 1.0
Fecha de creación: 13/mar/2019
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	//IDENTIFICADORES
	int fin, n, m, i, j, ContadorPar=0, ContadorImpar=0;
	//ENTRADAS
	do{//Valida que sea números positivos
		fin=1;
		printf("\nIngrese la cantidad de filas de la matriz: ");
		scanf(" %i", &n);//Lee la longitud de la fila.
		if(n<0 || n==0){
			printf("\nNúmero no válido.");
			fin=0;
		}
	} while(fin==0);
	
	do{//Valida que sea números positivos.
		fin=1;
		printf("\nIngrese la cantidad de columnas de la matriz: ");
		scanf(" %i", &m);//Lee la longitud de la columna.
		if(m<0 || m==0){
			printf("\nNúmero no válido.");
			fin=0;
		}
	} while(fin==0);
	int x[n][m];//Matriz de filas "n" y columnas "m".
	
	//PROCESO (lectura).
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("\nIngrese numero fila %d columna %d: ", i+1, j+1);//Ingresar el elemento
			scanf(" %i", &x[i][j]);//Se guarda el valor en la fila "i" y columna "j"
			if(x[i][j]%2==0){
				ContadorPar=ContadorPar+1;
			}else{
				ContadorImpar=ContadorImpar+1;
			}
		}
	}
	printf("\nLa cantidad de números pares es: %i", ContadorPar);
	printf("\nLa cantidad de números impares es: %i", ContadorImpar);
	
	return 0;
}

/*

Revisado por: los compiladores 
-Funciona bien en general
-Falla al usar numeros fraccionarios "El programa no prohibe usarlos solo pide que cuente e
imprima cuantos elementos son pares y cuantos son impares."

*/
