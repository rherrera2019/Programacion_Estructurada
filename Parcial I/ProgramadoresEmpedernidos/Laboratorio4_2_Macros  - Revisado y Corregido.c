#include <stdio.h>

//declaracion de constantes y macros
#define PRECIO_SENCILLA 60
#define PRECIO_DOBLE 80
#define PRECIO_TRIPLE 100
#define COMISION_POR_TARJETA 0.03

#define FOR(A,B) for(A=1; A<=B; A++)
#define NO_NEGATIVO(A) while(A<0)

/*Nombre: laboratorio4_ejercicio2.c
Autor: Programadores empedernidos
Descripcion:
Un restaurante ofrece hamburguesas sencillas, dobles y triples, las cuales tienen un costo de $60.00, $80.00 y $100.00, 
respectivamente. La empresa acepta tarjetas de crédito con un cargo adicional de 3% sobre la compra. Los clientes pueden hacer su 
pedido con cualquier cantidad de hamburguesas de los tipos que deseen comer.  E.P. para determinar cuánto debe pagar cada uno de 
los N clientes que llegan al establecimiento. También, al final del día, se requiere imprimir el monto total de las ventas y el 
total de las comisiones por tarjeta de crédito. Utilizar sólo estructuras repetitivas for.

Fecha: 14feb2019
Versión: 1.0 */

int main(){
	//declaracion de variables
	int i, n, sencilla, doble, triple, tarjeta;
	float gasto, ventas=0, comisionTotal, comision;
	//entrada: se preguntan cuantos clientes hay, se usa DO-WHILE en caso de que el numero no sea aceptable
	do{
		printf("Cuantos clientes hay: ");
		scanf("%d", &n);
		if(n<0){
			printf("No puedes ingresar esa cantidad de clientes\n\n");
		}
	}
	NO_NEGATIVO(n);
	
	//proceso: ciclo for para preguntarle a cada cliente las hamburguesas que pediran
	FOR(i,n){
		gasto=0;
		comision=0;
		//se imprime el numero de cliente
		printf("Cliente #%d\n", i);
		//Se preguta cuantas sencillas va a perdir, en caso de no ser valido, se usa un DO-WHILE para volver a preguntarle
		do{
			printf("Cuantas hamburguesas sencillas pediras?: ");
			scanf("%d", &sencilla);
			if(sencilla<0){
				printf("esa cantidad de hamburguesas no es valida\n\n");
			}
		}
		NO_NEGATIVO(sencilla);
		
		//Se preguta cuantas dobles va a perdir, en caso de no ser valido, se usa un DO-WHILE para volver a preguntarle
		do{
			printf("Cuantas hamburguesas dobles pediras?: ");
			scanf("%d", &doble);
			if(doble<0){
				printf("esa cantidad de hamburguesas no es valida\n\n");
			}
		}
		NO_NEGATIVO(doble);
		
		//Se preguta cuantas triples va a perdir, en caso de no ser valido, se usa un DO-WHILE para volver a preguntarle
		do{
			printf("Cuantas hamburguesas triples pediras?: ");
			scanf("%d", &triple);
			if(triple<0){
				printf("esa cantidad de hamburguesas no es valida\n\n");
			}
		}
		NO_NEGATIVO(triple);
		
		//pregunta si pagara con tarjeta, sino ingresa un numero valido, se lo volvera a preguntar
		do{
			printf("Pagaras con tarjeta? (1=Si - 0=No): ");
			scanf("%d", &tarjeta);
			if(tarjeta!=0 && tarjeta!=1){
				printf("comando no valido\n\n");
			}
		}
		while(tarjeta!=0 && tarjeta!=1);
		
		//calculo del gasto que hizo el cliente
		gasto = (sencilla*PRECIO_SENCILLA) + (doble*PRECIO_DOBLE) + (triple*PRECIO_TRIPLE);
		
		//si el cliente pagara con tarjeta, se hace el proceso del calculo de la comision y se sumara a las comisiones totales asi como al gasto
		if(tarjeta==1){
			comision = gasto * COMISION_POR_TARJETA;
			comisionTotal += comision;
			gasto += comision;
		}
		
		//se suma el gasto de cada cliente al total de ventas que hizo la tienda
		ventas += gasto;
		//se imprime cuanto gasto el cliente del paso del FOR
		printf("Gastaste un total de %.2f pesos\n\n", gasto);
	}	
	//salida: se imprime cuanto se vendio en total y las comisiones totales
	printf("Se vendio un total de %.2f y tienes un total de %.2f de comisiones", ventas, comisionTotal);
	
	return 0;
}

/*El programa funciona correctamente, la estructura es fácil de comprender. Se recomienda corregir las faltas de ortografía presentes en los mensajes
a imprimir (falta de acentos, signos de puntuación y de interrogación, etc). 

Revisó: Picateclas*/
