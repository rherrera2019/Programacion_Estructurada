/* En un supermercado, se realizan descuentos por la compras a partir de unas bolitas de colores: 
verde 20%, amarilla 25%, negra 30%; la blanca no aplica ningún descuento. 
E.P. que lea el importe de la compra y el color de la bolita, determine e imprima cuanto debe pagar un cliente. 

Elaborado por:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 31/ene/2019
Version: 1.0rev 
Revisado por: Equipo picateclas
Observaciones: Cumple con los requisitos, funciona correctamente y sin vulnerabilidades, buen uso de comentarios
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	
	/*Creamos e inicilizamos los string para comparar  más adelante según el color de la bolita*/
	char verde[] = "verde", amarilla[] = "amarilla", negra[] = "negra", blanca[] = "blanca", color[10];
	
	/*Variable para guardar  el importe de la compra*/
	float importe_compra;
	
	/*Ya que un switch no accepta strings (sólamente caracteres y enteros) debemos transformar el color de la bolita en un número*/
	int n;
	
	/*Pedimos los datos de entrada (color de la bolita e importe de la compra)*/
	printf("\nInserte el importe de la compra ");
	scanf("%f", &importe_compra);
	
	fflush ( stdin ); //Usamos la función fflush para evitar la lectura del enter
	
	printf("\n\nInserte el color de la bolita (verde, amarilla, negra o blanca) ");
	gets(color);
	
	/*Proceso para darle un valor a n*/
	if (strcmp(color, verde) == 0) //Usamos la función strcmp para comparar dos strings
	{
		n = 1; //Si el color insertado es verde, n tomará el valor de 1 para poder procesar los datos en el switch
		
	} else if (strcmp(color, amarilla) == 0) //Usamos la función strcmp para comparar dos strings
	{
		n = 2; //Si el color insertado es amarilla, n tomará el valor de 2 para poder procesar los datos en el switch
		
	} else if (strcmp(color, negra) == 0) //Usamos la función strcmp para comparar dos strings
	{
		n = 3; //Si el color insertado es negra, n tomará el valor de 3 para poder procesar los datos en el switch
		
	} else if (strcmp(color, blanca) == 0) //Usamos la función strcmp para comparar dos strings
	{
		n = 4; //Si el color insertado es blanca, n tomará el valor de 4 para poder procesar los datos en el switch
		
	} else 
	{
		n = 5; //Si el color insertado no es válido, n tomará el valor de 5 para poder procesar los datos en el switch
	}
	
	/*Procesamos el valor de n*/
	switch (n)
	{
		
	case 1: (float)(importe_compra *= 0.8);
		break;
		
	case 2: (float)(importe_compra *= 0.75);
		break;
		
	case 3: (float)(importe_compra *= 0.7);
		break;
			
	case 4: (float)(importe_compra *= 1);
		break;
		
	case 5: printf("\n\nInsertaste un color incorrecto"); //Mostramos que se insertó un color no válido
		break;
	}
	
	/*Mostramos el importe de la compra según el valor que n haya tomado*/
	if (n != 5)
	{
		printf("\n\nTu importe de compra es de: %.2f", importe_compra);
	}
	
	getch(); //Esperamos caracter del teclado
	
	return 0;
}

