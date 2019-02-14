/* 39. E.P. que lea las utilidades mensuales de una cadena de 5 tiendas
y que determine e imprima cuantas tiendas tuvieron utilidades mayor a
los $ 2,000,000.-.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 7/feb/2019
Version: 1.0 */

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Creamos las variables necesarias para el programa*/
	int cont_tiendas, cont_mayor_utilidad;
	
	float utilidad_tienda;
	
	/*Inicializamos el contador para las tiendas*/
	cont_tiendas = 1;
	cont_mayor_utilidad = 0;
	
	/*Creamos el ciclo do-while para la lectura de las 5 tiendas*/
	do
	{
		/*ENTRADA DE DATOS*/
		printf("\n\nInserte la utilidad de la tienda %i° ", cont_tiendas++);
		scanf("%f", &utilidad_tienda);
		
		/*PROCESO para determinar si la utilidad de la tienda es mayor a $2,000,000*/
		if (utilidad_tienda > 2000000)
		{
			cont_mayor_utilidad++;
		}
		
	} while (cont_tiendas <= 5);
	
	/*SALIDA DE DATOS*/
	printf("\n\nLas tiendas con mayor utilidad mensual a $2,000,000 fueron: %i", cont_mayor_utilidad);
	
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}

/*Revisado por :Los compilaodres_Jafet Fernandez
En general bien
opcional: Contador iniciar en 0 
*/ 
