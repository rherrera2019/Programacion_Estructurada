/*Nombre:33
Autor: Los Compiladores
Fecha : 07Feb19
Entradas: 10 numeros 
Salidas: Los numeros mayores a 100
Procedimiento General: Leer 10 numeros e imprimir los mayores a 100 
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int Num; 
	int v=0; //seria comodo que la variable tenga mas relacion con la palabra *contador*
	int i=0;
	
	
	
	do{  
		//entrada
		printf("Dime un numero: ");
		scanf("%d",&Num);
		
		if(Num>100){
			//salida
			printf("*************************************\n");
			printf("El numero %d es mayor a 100",Num);
			printf("\n*************************************\n");
		}
		
		v++;
	} while(v<10);
	
	
	
	
	
	return 0;
}

/* Q\A:

Funciona correctamente, realiza correctamente lo que se pide
Hay una variable que no se esta utilizando 

Revisado por AlbertoMarín (punto c) */
