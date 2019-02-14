/*Nombre:40
Autor: Los Compiladores
Fecha : 7Feb19
Entradas: Utilidades
Salidas: Cuantas tiendas tivieron  utilidad mayor a los $ 2,000,000.- al final del año.
Procedimiento General: Ingresar la utilidades por meses durante 12 meses de 5 tiendas 
y te dira cuantas de ellas tuvieron  utilidad mayor a los $ 2,000,000.- al final del año.
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int v=0;
	int vv=0;
	int t=0;
	float Num; 
	float Dinero=0;
	int Ct = 0; 
	do{
		
		do{
			//entrada
			printf("\nDime cunato vendiste en el %d mes:",vv+1);
			scanf("%f",&Num);
			
			Dinero=(Dinero + Num);
			vv++;
			
		} while(vv<2);
		
		if(Dinero>2000000){
			Ct=(Ct+1);
		}
		
		v++;
		vv=0;
		Dinero=0;
		
		if(v<5){
			printf("\n****************************\n");
			printf("\nVamos a cambiar de tienda\n");
			printf("\n****************************\n");
		}
		
	} while(v<2);
	
	//salida
	printf("Hubo un total de %d Tientas que obtuvieron un monto mayor a 2,000,000 pesos",Ct);
	
	
	return 0;
}
/*Al terminar el ciclo de una tienda, te dice que van a cambiar de tienda, sin embargo
si el ciclo es de 2 tiendas , y se termina, vuelve a decir que cambiarán de tienda
pero ya no te pide las utilidades porque el ciclo ha terminado, (FUNCIONA BIEN)*/
