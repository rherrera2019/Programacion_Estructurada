/*Nombre:35
Autor: Los Compiladores
Fecha : 7Feb19
Entradas: 25 numeros
Salidas: Los numeros iguaes a cero
Procedimiento General: Leer 25 numeros e imprima los que sean iguales a cero
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	float Num; 
	int v=0; 
	
	while(v<25){
		//entrada
		printf("Dime un numero:");
		scanf("%f",&Num);
		
		if(Num==0){
			//salida
			printf("El numero en la pocicion %d es igual a cero\n",v+1); //aprendi algo nuevo en esta linea de codigo, el v+1 no modifica el contador asi que esta correcto 
			
		}
		
		v++;
		
	}
	
	
	
	
	return 0;
}

/* Q\A:
Funciona correctamente.
Tengo la costumbre de indicar que numero se va a leer
para saber cuando voy a llegar al ciclo numero 25 

Revisado por AlbertoMarín (Punto c) */
