/*
	Name: Ejercicio 49	
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 17/02/20 11:46
	Description: 49. Un restaurante ofrece hamburguesas sencillas, dobles y triples, las cuales tienen un costo de $60.00, $80.00 y $100.00, respectivamente.
	La empresa acepta tarjetas de crédito con un cargo adicional de 3% sobre la compra. Los clientes pueden hacer su pedido con cualquier
	cantidad de hamburguesas de los tipos que deseen comer. E.P. para determinar cuánto debe pagar cada uno de los N clientes que llegan al establecimiento. 
	También, al final del día, se requiere imprimir el monto total de las ventas y el total de las comisiones por tarjeta de crédito. 
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Macros
#define COSTOSENCILLA 60
#define COSTODOBLE 80
#define COSTOTRIPLE 100

//Declaracion de funciones
int validarNumClientes(int var);
char validarChar(char entrada);
int validarNumHamburgesas(int numHamburguesas);

//Main
int main(int argc, char *argv[]) {
	bool pagoCredito;
	float totalVentas = 0;
	float totalComisiones = 0;
	int numClientes, numHamburguesas, i;
	char entrada;
	
	//Lee y valida el numero de clientes
	printf("Ingrese el numero de clientes: ");
	scanf("%d", &numClientes);
	numClientes = validarNumClientes(numClientes);
	
	for (i= 0; i<numClientes; i++){
		
		pagoCredito = false;
		
		//Revisa si el usuario va a usar pago con tarjeta
		printf("Pago con tarjeta de credito? (y/n): ");
		scanf("%c", &entrada);
		entrada = validarChar(entrada);
		if(entrada == 'y'){
			pagoCredito = true;
		}
		
		//Lee y valida el numero de hamburguesas sencillas.
		printf("Ingrese cuantas hamburguesas Sencillas desea: ");
		scanf("%d", &numHamburguesas);
		numHamburguesas = validarNumHamburgesas(numHamburguesas);
		
		//Agrega al total de ventas las hamburguesas sencillas que se vendieron.
		totalVentas += numHamburguesas *COSTOSENCILLA;
		
		//El proceso se repite para las hamburguesas dobles y triples
		printf("Ingrese cuantas hamburguesas dobles desea: ");
		scanf("%d", &numHamburguesas);
		numHamburguesas = validarNumHamburgesas(numHamburguesas);
		totalVentas += numHamburguesas * COSTODOBLE;
		
		printf("Ingrese cuantas hamburguesas triples desea: ");
		scanf("%d", &numHamburguesas);
		numHamburguesas = validarNumHamburgesas(numHamburguesas);
		totalVentas += numHamburguesas * COSTOTRIPLE;
		
		//Si se uso tarjeta se agrega el 3% al total de comisiones
		if(pagoCredito){
			totalComisiones += totalVentas * 0.03;
		}
		
	
	}
	
	printf("El total de ventas fue: %.2f\n El total de comisiones fue: %.2f", totalVentas, totalComisiones);
	
	return 0;
}


//Funciones


/*	Entrada: Entero que representa el numero de clientes.
	Proceso: Verifica que sea mayor o igual a 1
	Salida: Entrada validada. 
*/
int validarNumClientes(int entrada){
	int entradaValidada;
	while(entrada < 1){
		printf("Entrada invalida, intenta de nuevo: ");
		scanf("%d", &entrada);
	}
	entradaValidada = entrada;
	return entradaValidada;
}


/*	Entrada: Char que representa la decision de pago con tarjeta
	Proceso: Verifica que sea igual a 'y' o 'n'
	Salida: Entrada validada. 
*/
char validarChar(char entrada){
	char entradaValidada;
	while(entrada!= 'y' && entrada!='n'){
		printf("Entrada invalida, intenta de nuevo: ");
		scanf("%c", &entrada);
	}
	entradaValidada = entrada;
}

/*	Entrada: int que representa el numero de hamburguesas de cierto tipo
	Proceso: Verifica que sea igual o mayor a cero
	Salida: Entrada validada. 
*/
int validarNumHamburgesas(int entrada){
	int entradaValidada;
	while(entrada < 0){
		printf("Entrada invalida, intenta de nuevo: ");
		scanf("%c", &entrada);
	}
	entradaValidada = entrada;
	return entradaValidada;
}

