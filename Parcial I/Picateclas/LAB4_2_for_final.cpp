/*Programa: Hamburguesas.C
Descripción: Determina cuánto debe pagar cada uno de los N clientes que llegan al establecimiento. 
También, al final del día, imprime el monto total de las ventas y el total de las comisiones por tarjeta de crédito.
Autor: Picateclas
Fecha: 17/02/2019
Versión: 1.0
*/

#include <stdio.h>
#include <conio.h>


int main(void) {
	//Variables
	float subtotal, total, mventa, mcomision;
	int simple, doble, triple, n, i, pago;
	char metpago;
	subtotal=0;
	total=0;
	mventa=0;
	mcomision=0;
	
	//Entrada. ¿Cuántos clientes son?
	do{
		printf("Ingrese el número de clientes del día: ");
		scanf(" %d", &n);
		if(n<0){
			printf("Cantidad inválida. Ingrese un número entero positivo o 0. \n");
		}
	}while(n<0);
	
	for(i=0; i<n; i++){
		//Entrada. ¿Cuál es el pedido?
		do{
			printf("\n\n¿Qué desea ordenar el cliente?\n");
			printf("Hamburguesa(s) sencilla(s): ");
			scanf(" %d", &simple);
			if(simple<0){
				printf("Cantidad inválida. Ingrese un número positivo o 0. \n");
			}
		}while(simple<0);
		do{
			printf("\nHamburguesa(s) doble(s): ");
			scanf(" %d", &doble);
			if(doble<0){
				printf("Cantidad inválida. Ingrese un número positivo o 0. \n");
			}
		}while(doble<0);
		do{
			printf("\nHamburguesa(s) triple(s): ");
			scanf(" %d", &triple);
			if(triple<0){
				printf("Cantidad inválida. Ingrese un número positivo o 0. \n");
			}
		}while(triple<0);
		
		//Proceso. Empieza a calcular según la cantidad ordenada y su costo.
		subtotal=0;
		if(simple>0){
			subtotal += simple*60;
		}
		if(doble>0){
			subtotal += doble*80;
		}
		if(triple>0){
			subtotal += triple*100;
		}
		
		//Proceso. Determina el método de pago y apllica comisión, en caso necesario.
		do{
			printf("\n¿Cómo desea pagar? [Efectivo(E) o Tarjeta (T)]: ");
			scanf(" %c", &metpago);
			switch(metpago){
			case 'E':
			case 'e':
				pago=1;
				total= subtotal;
				break;
				case'T':
			case 't':
				pago=1;
				mcomision+= subtotal*0.03;
				total= subtotal*(1.03);
				break;
			default:
				pago=0;
				printf("Método inválido. Ingrese de nuevo.\n");
				break;
			}
		}while(pago<1);
		
		//Proceso. Guarda el total del cliente en un acumulador, para obtener las ventas totales del día.
		mventa += total;
		//Salida. Imprime el total del cliente
		printf("\nEl total al pagar es: $%.2f", total);
	}
	//Salida. Imprime el total de ventas del día. Seguido, imprime la sumatoria de la comisión aplicada en cada venta.
	printf("\n\nTotal de ventas del día (incluyendo comisiones): $%.2f", mventa);
	printf("\nTotal de comisiones del día: $%.2f", mcomision);
	getch();
	return 0;
}

/*Revisión:
-El código no cumple con su función.
-Todos los scanf tienen "%i" cuando debería ser un "%d" para leer un entero.
-No imprime acentos, lo que hace que no se entienda en la pantalla.
revisó: Programadores empedernidos
*/

/*Picateclas: Probamos el programa y los acentos sí se imprimen. Suponemos que están usando un 
compilador no compatible, mal configurado o usa un encoding diferente.
El código sí funciona. Se realizaron las pruebas y reacciona igual con %i que con %d, de todas formas hicimos el cambio en ambas versiones. */
