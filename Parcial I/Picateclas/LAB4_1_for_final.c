/*Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.1
La posición de un robot móvil se controla por medio de comandos numéricos 
introducidos por el teclado de acuerdo a la tabla siguiente. Inicialmente el 
robot se encuentra en la posición (x=0, y=0). E.P. que determine e imprima la 
posición del robot después de N movimientos. El número de movimientos totales se
debe solicitar al inicio.
Fecha de creacion: 14/feb/2019
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int x = 0;
	int y = 0;
	
	int direccion;
	int NoMovimientos;
	
	/*ENTRADA*/
	printf("Ingrese el número de movimientos\n");
	scanf("%d", &NoMovimientos);
	/*PROCESO*/
	for(int i=0; i<NoMovimientos; i++){
		printf("Dirección actual P(%d, %d)",x,y);
		printf("\nSeleccione una dirección: ");
		scanf("%d", &direccion);
		
		if(direccion==2){
			y = y - 1;
		}
		else if(direccion==8){
			y = y + 1;
		}
		else if(direccion==4){
			x = x - 1;
		}
		else if(direccion==6){
			x = x + 1;
		}
		else{
			printf("\nMovimiento inválido, el robot no se ha movido");
			getch();
		}
		
		system("cls"); //Limpia el contenido anterior de la pantalla
	}
	/*SALIDA*/
	printf("\nTe quedaste en las coord (%d,%d)", x,y);
	getch();
	return 0;
}

/* Revisión.
-No compila.

revisó: Programadores empedernidos */

/*Juan Duran observó: Que raro, he ejecutado el código en 2 compiladores (zinjai
y C4droid) y me compilan correctamente, es posible que el compilador que utilizan
tenga problemas con ciertas librerias
*/
