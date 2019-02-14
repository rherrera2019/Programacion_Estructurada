/* 23 Una papelería vende libros a $100, cuadernos a $15.50 y plumas a $2.35. 
E.P. que determine e imprima el monto total de una venta, según el número de artículos vendidos. 

Elaborado por:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 31/ene/2019
Version: 1.0rev

Revisado por: Equipo Picateclas
Observaciones: El programa cumple con los requisitos dados, funciona correctamente.
 */

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Inicializamos las variables necesarias para el programa*/
	int total_libros, total_cuadernos, total_plumas;
	
	/*Pedimos que se inserte el total de libros*/
	printf("\nInserte el número de libros vendidos ");
	scanf("%i", &total_libros); //Leemos el total de libros
	
	/*Pedimos que se inserte el total de cuadernos*/
	printf("\nInserte el número de cudernos vendidos ");
	scanf("%i", &total_cuadernos); //Leemos el total de cuadernos
	
	/*Pedimos que se inserte el total de plumas*/
	printf("\nInserte el número de plumas vendidos ");
	scanf("%i", &total_plumas); //Leemos el total de plumas
	
	/*Mostramos la salida y, dentro de la misma, se encuentra el calculo para el resultado*/
	printf("\nEl total de la venta es de: $%.2f", (float)total_libros * 100 + total_cuadernos * 15.5 + total_plumas * 2.35);
	
	getch();
	
	return 0;
}

