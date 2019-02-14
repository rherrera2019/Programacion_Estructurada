/*Nombre:45
Autor: Los Compiladores
Fecha : 7Feb19
Entradas: 	250 números 
Salidas:  cuantos numeros son positivos y cuantos son negativos.
Procedimiento General:Ingresar 250 numeros e imprimir cuantos son negativos y cuantos positivos 
*NOTA: contador de nuls agregado*
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int Cneg=0; 
	int Cpos=0;
	int Cdc=0;
	int v=0; 
	float Num; 
	
	250 números 
	do{
		//entrada
		printf("Dime un numero: ");
		scanf("%f",&Num);
		
		if(Num<0){
			
			Cneg=(Cneg+1);
			
		}else if(Num>0){
			Cpos=(Cpos +1);
			
		}else {
			Cdc=(Cdc +1);
		}
		
		
		v++; 
		
	} while(v<10);
	
	//salida
	printf("La cantidades de numeros positivos son %d \n", Cpos);
	printf("La cantidades de numeros Negativos son %d\n", Cneg);
	printf("La cantidades de numeros iguales a cero son %d ", Cdc);
	
	
	
	
	
	
	
	
	return 0;
}


//La linea 19 hace que el programa no corra pero al quitarlo el programa corre bien.
//Revisado por: Erick Cárdenas, Equipo Punto C
