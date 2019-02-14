
//Leer las utilidades de una tienda cada mes y ver cuales son mayoes a 2000000 al final del año
//Autor: Programadores Emperdernidos. 
//Fecha: 10/02/19
//Version: 2.0.
//Nombre: 40.c
#include <stdio.h>

int main(){
	//VARIABLES
	int Contador, Acum, Contador2;
	float  Monto, Utilidades, Gastos;
	Contador=1;
	Acum=0;
	//CICLO DE CADA TIENDA
	while(Contador<=5){
		printf("Tienda no. %d", Contador);
		//VARIABLES DEL CICLO ANIDADO 
		Utilidades=0;
		Contador2=1;
		//CICLO DE CADA MES
		while (Contador2 <= 12){
			printf("\nIngrese el monto de venta del mes #%d: ", Contador2);
			scanf("%f", &Monto);
			
			printf("\nIngrese el monto de gastos del mes #%d: ", Contador2);
			scanf("%f", &Gastos);

			Utilidades += (Monto - Gastos);
			printf("A dia de hoy llevas un total de %.2f pesos de utilidades\n", Utilidades);
			Contador2++;
		}
		//COMPARACION PARA SABER CUALES SON MAYORES A 2000000
		if (Utilidades > 2000000){
			Acum++;
		}
		Contador++;
	}
	
	//SALIDA
	printf("\n%d tiendas tuvieron un  monto mayor a 2,000,000", Acum);
	
	return 0;
}



/*
El programa funciona correctamente, sin embargo no resuelve el problema por completo. El ejercicio pedía calcular 
las utilidades a partir de las ventas y costos de cada mes, y aquí simplemente se utilizó el monto de ventas
como utilidad.
Revisó: Picateclas
*/
