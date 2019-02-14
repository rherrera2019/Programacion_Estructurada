/*Nombre:36
Autor: Los Compiladores
Fecha : 7Feb19
Entradas: 25 numeros
Salidas: Cuantos de ellos son negativos
Procedimiento General: Leera 25 numeros e imprime la cantidad de negativos que hay 
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int v=0;
	float Num; 
	int Neg=0;
	
	
	while(v<25){
		//entrada
		printf("Dime un nuemro:");
		scanf("%f",&Num);
		
		if(Num<0){
			
			Neg=(Neg+1);
		}
		
		v++;
	}
	//salida
	printf("Hubo un total de %d Numeros egativos",Neg);
	
	
	return 0;
}

/* Q\A:

Funciona correctamente .
Hay uno que otro error de dedo al imprimir .
Seria bueno indicar en que ciclo se está para saber cuando se esta 
por terminasr el codigo. 

Revisado por AlbertoMarín (punto c) */
