#include <stdio.h> 
#include <conio.h>
#include <math.h>

/*Ejercicio 2 de practica de laboratorio: Supermercado
Descripción:En un supermercado, se realizan descuentos por la compras a partir de unas bolitas de colores: 
verde 20%, amarilla 25%, negra 30%; la blanca no aplica ningún descuento. 
E.P. que lea el importe de la compra y el color de la bolita, determine e imprima cuanto debe pagar un cliente 
Fecha: 05/02/2019
Versión: 1.0 */

int main () 
	
	
{
		
	float pago,bolita;
		
		printf( "\n Dime el costo de la compra : " ) ; 
	scanf ("%f",&pago) ; 
	
	printf( "\n presione 1 si es verde " ) ; 
	printf( "\n presione 2 si es amarilla " ) ; 
	printf( "\n presione 3 si es negra " ) ; 	
	printf( "\n Dime el color de la bolita de descuento : " ) ; 
	scanf ("%f",&bolita) ; 
	
	
	if (bolita==1) 
		printf ("\n El pago es de :  %.2f"  ,pago*0.8 ) ;
	else 
		if (bolita==2)
			printf ("\n El pago es de : %.2f", pago*0.75 ) ;
		else
			if (bolita==3)
				printf ("\n El pago es de : %.2f" , pago*0.70 ) ;
			else 
				printf ("\n no hay descuento, siga participando" ) ; 
	
	getch () ; 
	
	//Hubiese estado bueno que pongan la bola blanca como una opción, pero fuera de eso, funciona bien.	
	
	return 0 ; 
		
}
