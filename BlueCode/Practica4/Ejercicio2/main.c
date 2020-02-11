/*
	Name: Ejercicio 2 Practica 4
	Copyright: BlueCode
	Author: Luis Juarez
	Date: 11/02/20 11:12
	Description: 
*/

#include <stdio.h>
#include <stdlib.h>

#define NUMTIENDAS 3
#define ANIOS 5
#define MESES 12

float mayor(float a, float b);
void mayorUtilidadTotal(float a, float b, float c);

int main(int argc, char *argv[]) {
	float utilidadTotal_tienda1 = 0 , utilidadTotal_tienda2 = 0 , utilidadTotal_tienda3 = 0, utilidadAnual, utilidadAnualTrono;
	float ventas, costo;
	int i,j,k, anioTrono;
	
	for(i = 0; i < NUMTIENDAS; i++){
		for(j = 0; j < ANIOS; j++){
			utilidadAnual = 0;
			for(k = 0; k < MESES; k++){
				printf("Tienda #%d\n", i+1);
				printf("Ingrese ventas del mes %d", k+1);
				scanf("%f", &ventas);
				printf("Ingrese costos del mes %d", k+1);
				scanf("%f", &costo);
				switch(i){
					case 0:
						utilidadTotal_tienda1 += ventas - costo;
						utilidadAnual += ventas - costo;
						break;
					case 1:
						utilidadTotal_tienda2 += ventas - costo;
						utilidadAnual += ventas - costo;
						break;
					case 2:
						utilidadTotal_tienda3 += ventas - costo;
						utilidadAnual += ventas - costo;
						break;
				}
			}
			
			if(i == 0){
				utilidadAnualTrono = utilidadAnual;
				anioTrono = j+1;
			}else{
				utilidadAnualTrono = mayor(utilidadAnualTrono, utilidadAnual);
				anioTrono = j+1;
			}
		}
	}
	
	mayorUtilidadTotal(utilidadTotal_tienda1,utilidadTotal_tienda2,utilidadTotal_tienda3);
	printf("La mayor utilidad anual fue &.2f, en el anio %d", utilidadAnualTrono, anioTrono);

	return 0;
}


float mayor(float a, float b){
	float mayor;
	if(a > b){
		mayor = a;
	}else{
		mayor = b;
	}
	return mayor;
}


void mayorUtilidadTotal(float a, float b, float c){
	if(a>b){
		if(a > c){
			printf("La mayor utilidad pertenece a la tienda 1 con %.2f", a);
		}else{
			printf("La mayor utilidad pertenece a la tienda 3 con %.2f", c);
		}
	}else if(b > c){
			printf("La mayor utilidad pertenece a la tienda 2 con %.2f", b);
	}else{
		
		printf("La mayor utilidad pertenece a la tienda 3 con %.2f", c);
	}
}
