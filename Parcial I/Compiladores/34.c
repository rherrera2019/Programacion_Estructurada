
/*Nombre:34
Autor: Los Compiladores
Fecha : 7Feb19
Entradas: 100 numeros
Salidas: 100 numeros
Procedimiento General: Leera 100 numeros e imprimirlos
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	
	float Num;
	int v=0;
	
	while(v<100){
		//entrada
		printf("\nDime un numero: ");
		scanf("%f",&Num);
		//salida
		printf("El numero insertado en la pocicion %d fue:",v+1);
		printf("%.2f",Num);
		
		
		v++;
		
		
	}
	
	
	return 0;
}

/* Q\A:

Funciona bien el programa 
quizas seria bueno que las lineas que imprime esten separadas para 
que se vea un poco mas claro 

Revisado por AlbertoMarín (punto c) */
