/*
48. E.P. que lea 200 números y que calcule e imprima cuantos son
negativos, cuantos son positivos y cuantos fueron iguales a cero.Nombre:48
Autor: Los Compiladores
Fecha : 13Feb19
Entradas: 200 numeros
Salidas: Cuantos son positivos, cuanos negativos y cuantos igual a cero
Procedimiento General:Leer el numero y decidir si es positivo, negativo o igual a cero 
*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	float Num; 
	int Pos = 0; 
	int Neg=0; 
	int Cer=0; 
	
	
	for(int i=0; i<200; i++){
		//Entradas de datos
		printf("Vuelta numero %d dime un numero: ", i+1);
		scanf("%f",&Num);
		//Decicion de colocar el numero
		if(Num <0){
			Neg = (Neg +1);
		}else if(Num>0){
			Pos=(Pos+1);
		}else if(Num==0){
			Cer=(Cer+1);
		}
		
		
		system("cls");
	}
	
	//salidas de resultados
	printf("*****************************************\n");
	printf("La cantidad de posivos son %d\n",Pos);
	printf("La cantidad de Negativos son %d\n",Neg);
	printf("La cantidad de Ceros son %d\n",Cer);
	printf("*****************************************");
	
	
	
	
	return 0;
}

