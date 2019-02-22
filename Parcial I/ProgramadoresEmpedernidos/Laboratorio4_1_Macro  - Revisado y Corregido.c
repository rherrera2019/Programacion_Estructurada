
#include <stdio.h>

//MACROS
#define FOR(A,B) for(A=1; A<=B; A++)
/*
Nombre: laboratorio4_ejercicio1_macros.c
Autor: Programadores empedernidos
Descripcion:
La posición de un robot móvil se controla por medio de comandos numéricos introducidos por el teclado de acuerdo a la tabla siguiente. Inicialmente 
el robot se encuentra en la posición (x=0, y=0). E.P. que determine e imprima la posición del robot después de N movimientos. El número de movimientos
totales se debe solicitar al inicio.  Utilizar sólo estructuras repetitivas for. 

Comando numérico          Acción
        6           Aumenta coordenada x por 1
		4			Reduce coordenada x por 1
		8			Aumenta coordenada y por 1
		2			Reduce coordenada y por 1


Fecha: 14feb2019
Versión: 1.0rev */

int main (){
	//declaracion de las variables
	int n, comando, x=0, y=0, error=0, i;
	//entrada: # de movimientos que va a realizar el robot, se usa DO-WHILE para repetir la lectura de la varible n en caso de que sea invalido
	do{
		printf("cuantos movimientos haras\n");
		scanf("%d", &n);
		if(n<=0){
			printf("debes hacer al menos un movimiento\n");
		}
	}
	while (n<=0);
	
	//impresion del pseudomenu
	printf("Moverte 1 en X - Pulsa 6\n");
	printf("Moverte -1 en X - Pulsa 4\n");
	printf("Moverte 1 en Y - Pulsa 8\n");
	printf("Moverte -1 en Y - Pulsa 2\n");
		
		
	//proceso: ciclo for en el cual se leera el tipo de movimiento que hara el robot
	FOR(i,n){
		//DO-WHILE en caso de que sea incorrecto el tipo de movimiento que realizara el robot
		do{
			printf("Movimiento #%d: ", i);
			fflush(stdin);
			scanf("%d", &comando);
			
			switch(comando){
				//en cada case se reinicia la variable de error para que no cause problemas en el siguiente paso
				case 6:
					x++;
					error=0;
					break;
				case 4:
					x--;
					error=0;
					break;
				case 8:
					y++;
					error=0;
					break;
				case 2:
					y--;
					error=0;
					break;
				default:
					error=1;
					printf("El comando no es válido, ingresa uno que sea valido");
					break;				
			}	
		}
		while(error == 1);
	}
	
	//salida, se imprime la posicion de robot en coordenadas
	printf("Estas en la coordenada (%d,%d)", x,y);
	
	return 0;
/*Observaciones
Funciona perfectamente, excelente documentacion, permite al sistema recuperarse 
en caso de un movimiento invalido
	
Revisado por: Equipo Picateclas
	
*/
}
