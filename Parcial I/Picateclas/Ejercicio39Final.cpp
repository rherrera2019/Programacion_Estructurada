/* Programa: TiendasConUtilidad2000000Mensual.C
Descripción: Lee las utilidades mensuales de una cadena de 5 tiendas
y determina e imprime cuántas tiendas tuvieron utilidades mayor a $ 2,000,000
Autor: Picateclas
Integrantes:
- López Madera Fernanda Jacqueline
- Durán Matos Juan José
- González Bautista Noé Alejandro
Versión: 1.0
Fecha: 12/feb/2019 */

#include <stdio.h>
#include <conio.h>

int main(void) {
	/*VARIABLES*/
	int c_general, c_tiendas;
	float utilidad;
	c_general=0;
	c_tiendas=0;
	
	/*ENTRADA*/
	while(c_general<5){
		c_general=c_general+1;
		printf("\nTienda %i", c_general);
		printf("\nIngrese las utilidades: $");
		scanf("%f", &utilidad);
		
		/*PROCESO*/
		if(utilidad>2000000){
			c_tiendas=c_tiendas+1;
		}
	}
	
	/*SALIDA*/
	printf("\nTiendas con utilidad mayor a $2,000,000: %i", c_tiendas);
	getch();
	return 0;
}

/*El programa funciona correctamente, separar el código para que sea más fácil entenderlo.

Equipo: SacaChispas
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 13/02/2019*/

