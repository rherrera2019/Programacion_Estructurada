/*
Nombre: 39 - Utilidades mensuales de una cadena de 5 tiendas.c
Autor: Los Compiladores
Fecha : 11Feb19
Entradas: utilidades mensuales de una tienda
Salidas: Tiendas con utilidades mayores a 2,000,000
Procedimiento General: Se determina las utilidades de cada tienda y se imprimen las tiendas que tuvieron utilidades mayores a 2,000,000
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int T=0;
	int M=0; 
	float Ut;
	int C=0;
	do{
		
		printf("\n****************************************************");
		printf("\n****************************************************");
		printf("\n          Veamos la utilidad del mes %d",M+1);
		printf("\n****************************************************");
		
		do{
			//entrada
			printf("\n****************************************************");
			printf("\nDime la utilidad de la tienda %d: ",T+1);
			scanf("%f",&Ut);
			
			if(Ut>2000000.){
				
				printf("La tienda %d a superado la utilidad de $ 2,000,000.",T+1);
				C=C+1;
			}
			
			
			T=T+1;
		} while(T<5);
		printf("\n****************************************************");
		//salida
		printf("\n %d Tiendas Tuvieron utilidades mayor a $ 2,000,000 El %d Mes",C,M+1);
		T=0;
		C=0;
		M=M+1;
	} while(M<12);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
/*Utiliza correctamente los contadores, y las entradas y salidas fueron correctas
El código cumple su función, Itzel Moo (Punto C)*/
