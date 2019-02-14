/* 40.- Una cadena de 5 tiendas determina para cada una, al final del mes los montos de sus ventas y costos.   
E.P. que determine e imprima cuántas tiendas obtuvieron una utilidad mayor a los $ 2,000,000.- al final del año.

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
	int cont_tiendas, cont_meses, cont_tiendas_utilidad;
	
	float utilidad_tienda_anual, costos, ventas;
	
	/*Inicializamos los contadores*/
	cont_tiendas = 1;
	cont_meses = 1;
	cont_tiendas_utilidad = 0;
	
	utilidad_tienda_anual = 0; //Variable para guardar la utilidad anual de una tienda 
	
	/*Creamos el primer ciclo do-while para la iteración de las 5 tiendas*/
	do
	{
		/*Creamos el segundo ciclo do-while para la iteración de los meses para cada tienda*/
		do
		{
			/*ENTRADA DE DATOS*/
			printf("\n\nInserte los costos del %i° mes de la tienda %i° ", cont_meses, cont_tiendas);
			fflush(stdin);
			scanf("%f", &costos);
			
			printf("\n\nInserte las ventas del %i° mes de la tienda %i° ", cont_meses, cont_tiendas);
			fflush(stdin);
			scanf("%f", &ventas);
			
			/*PROCESO para determinar la utilidad de una tienda*/
			utilidad_tienda_anual += ventas - costos;
			
			cont_meses++;
			
		} while (cont_meses <= 12);
		
		/*Preguntamos si la utilidad de la tienda actual es mayor a $2000000*/
		if (utilidad_tienda_anual > 2000000)
		{
			cont_tiendas_utilidad++;
		}
		
		utilidad_tienda_anual = 0; //Reiniciamos la variable para calcular la utilidad de la siguiente tienda
		
		cont_meses = 1; //Reiniciamos el contador meses
		
		cont_tiendas++; //aumentamos el contador de las tiendas
		
	} while (cont_tiendas <= 5);
	
	/*SALIDA DE DATOS*/
	printf("\n\nLas tiendas que tienen una utilidad mayor a $2000000 son: %i ", cont_tiendas_utilidad);
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}
/*Revisado por :Los compilaodres_Carlos Alvarez
En general bien
*/ 
