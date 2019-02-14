/* Programa: TiendasConUtilidad2000000Anual.C
Descripción: Teniendo los montos de costos y ventas, calcula la utilidad mensual.
Determina e imprime cuántas tiendas obtuvieron una utilidad mayor a los $2,000,000 al final del año.
Autor: Picateclas
Integrantes:
- López Madera Fernanda Jacqueline
- Durán Matos Juan José
- González Bautista Noé Alejandro
Versión: 1.0
Fecha: 12/feb/2019 */

#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[]) {
	/*VARIABLES*/
	int cont, mes, sum, c_tiendas;
	float utilidad, ventas, costos;
	cont=0;
	c_tiendas=0;
	
	/*ENTRADA*/
	do{
		sum=0;
		mes=0;
		cont=cont+1;
		printf("\nTienda no. %i", cont);
		
		do{
			mes++;
			printf("\nIngresa las ventas para el mes %i", mes);
			printf(": $");
			scanf("%f", &ventas);
			printf("\nIngresa los costos para el mes %i", mes);
			printf(": $");
			scanf("%f", &costos);
			/*PROCESO*/
			utilidad=ventas-costos;
			sum=sum+utilidad;
		}while(mes<12);
		
		if(sum>2000000){
			c_tiendas=c_tiendas+1;
		}
		
	}while(cont<5);
	
	/*SALIDA*/
	printf("Tiendas con utilidad anual mayor a $2,000,000: %i", c_tiendas);
	getch();
	return 0;
}

/*El programa funciona correctamente, separar el código para que sea más fácil entenderlo.
Los contadores pueden simplificarse (mes++;)
al igual que los sumadores (sum += utiliidad;)

Equipo: SacaChispas
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 13/02/2019*/


