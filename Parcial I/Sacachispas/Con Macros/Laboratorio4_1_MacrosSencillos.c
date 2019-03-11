/* 1_Laboratorio4. La posición de un robot móvil se controla por medio de comandos numéricos 
introducidos por el teclado de acuerdo a la tabla siguiente. Inicialmente el robot se encuentra en la posición (x=0, y=0). 
E.P. que determine e imprima la posición del robot después de N movimientos. 
El número de movimientos totales se debe solicitar al inicio.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 14/feb/2019
Version: 1.0 (Usando macros sencillos)*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define DERECHA 6
#define IZQUIERDA 4
#define ARRIBA 8
#define ABAJO 2

int main() {
	
	/*Creamos las variables necesarias para el programa*/
	int movimiento_x, movimiento_y, cont_movimientos, movimientos_totales, movimiento;

	/*Inicializamos las variables*/
	movimiento_x = 0;
	movimiento_y = 0;
	cont_movimientos = 1;
	
	
	/*Mostramos un pequeño menú*/
	printf("\n6.- Mover robot a la derecha");
	printf("\n4.- Mover robot a la izquierda");
	printf("\n8.- Mover robot hacia arriba");
	printf("\n2.- Mover robot hacia abajo");
	
	/*Preguntamos el número de movimientos del robot*/
	printf("\n\n¿Cuál es el número de movimientos totales del robot? ");
	scanf("%i", &movimientos_totales);
	
	/*Creamos el ciclo for para la lectura de los movimientos*/
	for (cont_movimientos = 1; cont_movimientos <= movimientos_totales; cont_movimientos++)
	{
		/*ENTRADA DE DATOS para los movimientos del robot*/
		printf("\n\nInserte el movimiento N° %i ", cont_movimientos);
		fflush(stdin); //Limpiamos el caracter que se insertó anteriormente.
		scanf("%i", &movimiento);
		
		/*PROCESO DE LOS DATOS según el tipo de movimiento*/
		switch(movimiento)
		{
			
		case DERECHA:
			
			movimiento_x++;
			
			break;
			
		case IZQUIERDA:
			
			movimiento_x--;
			
			break;
			
		case ARRIBA:
			
			movimiento_y++;
			
			break;
			
		case ABAJO:
			
			movimiento_y--;
			
			break;
			
		default:
			
			printf("\n\nInsertó un número NO válido");
			
			cont_movimientos--; //Disminuimos el contador para que no se salte el movimiento actual 
			
		}
	}
	
	/*SALIDA DE DATOS para las coordenadas finales del robot*/
	printf("\n\nLas coordenadas del robot son:\n\nEje X: %i\n\nEje Y:%i\n\n", movimiento_x, movimiento_y);
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}
/* Calificó: Punto C
-Funciona correctamente, al colocar 6 pasos al robot y colocar los comandos 
6,8,8,8,6,6, el robot queda en x=3 y y=3.
-no valida que el número de pasos sea un entero o cero. Pero una vez que 
lee el número de pasos si valida que correspondan a 2,4,6, u 8.
-Muy interesante al aclarar que el robot se mueve a los lados y no 
según lo planteado en el problema
-El macro funciona correctamente, hace más claro el código según el 
planteamiendo de izquierda, derecha, arriba y abajo. Lo hace más facil de entender
*/
