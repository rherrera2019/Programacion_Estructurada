/*II. Un restaurante ofrece hamburguesas sencillas, dobles y triples, 
las cuales tienen un costo de $60.00, $80.00 y $100.00, respectivamente. 
La empresa acepta tarjetas de crédito con un cargo adicional de 3% sobre la 
compra. Los clientes pueden hacer su pedido con cualquier cantidad de
hamburguesas de los tipos que deseen comer.  E.P. para determinar cuánto
debe pagar cada uno de los N clientes que llegan al establecimiento. 
También, al final del día, se requiere imprimir el monto total de las ventas 
y el total de las comisiones por tarjeta de crédito. Utilizar sólo estructuras
repetitivas for*/

#include <stdio.h>
#include <stdlib.h>
#define Para(x) for(B=1; B<=NoCliente; B++)
#define SubtotalS Pago=Pago+(S*NH);
#define SubtotalD Pago=Pago+(D*NH);
#define SubtotalT Pago=Pago+(T*NH);
int main(int argc, const char * argv[])
{
	int S,D,T, NoCliente, B, NH, Tipo, cont;
	float ITC, Pago, Ventas, ComisionesT;
	
	S=60;
	D=80;
	T=100;
	ITC=.03;
	Ventas=0;
	ComisionesT=0;
	
	printf("Bienvenido a Hamburguer Store, ¿Cuantos clientes tendra? ");
	scanf ("%d", &NoCliente);
	Para(x)
	{
		Pago=0;	
		printf("\n ¿Cuántas hamburguesas simples quiere?: ");
		scanf ("%d", &NH);	
		SubtotalS
		printf("\n ¿Cuántas hamburguesas dobles quiere?: ");
		scanf ("%d", &NH);
		SubtotalD
		printf("\n ¿Cuántas hamburguesas triples quiere?: ");
		scanf ("%d", &NH);		
		SubtotalT
		printf("\n ¿Pagara con tarjeta de credito? (1-Sí, 2-No): ");
		scanf ("%d", &Tipo);	
		system("cls");
		switch (Tipo){
		case 1:
			Pago=Pago+(Pago*ITC);
			ComisionesT=ComisionesT+(Pago*ITC);
			printf("\n El total al pagar de tu cliente es de (Incluye IVA): %f", Pago);
			break;
		default: printf("\n El total al pagar de tu cliente es de: %f", Pago);
		}
		Ventas=Ventas+Pago;
	}
	printf("\n\n Sus ventas totales fueron de: %f", Ventas);
	printf("\n\n Sus ComisionesT fueron de: %f", ComisionesT);
	return 0;
}

/*El programa funciona correctamente. NO está documentado el código y no se entiende el funcionamiento de algunas variables
Buen uso de las macros
Falta información en el encabezado (nombres, equipo, fecha, versión)
Recomendación: Separar el código para que sea más fácil entenderlo

Revisó: Senaida Norely Chan Chan

Equipo: SacaChispas

Fecha 19/02/2019 */

