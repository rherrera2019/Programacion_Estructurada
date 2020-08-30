#include <stdio.h>
#include <locale.h> //Para las acentuaciones 
#include <stdlib.h> //Para limpiar la consola en este caso
/*
Nombre: El robot móvil
Descripción: El desplazamiento de un robot se ve afectado por medio de comandos numericos
Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Version: 1.0
Fecha: 11/02/2020
*/
int main (){
	setlocale (LC_ALL,""); //Aplicamos la libreria <locale.h>
	int Movimientos,i; //Contadores
	int x,y,Comando; //Posición
	x = 0;
	y = 0;
	//Inicio
	printf ("Este programa calcula las cordenadas en (x,y) de un robot");
	printf ("\nLa posición del robot se ve afectada por comandos numéricos\n");
	printf ("\nPor favor ingrese el total de movimientos que va a realizar en el robot: ");
	scanf ("%d", &Movimientos); //Entrada principal
	
	while (Movimientos <1){ //Validamos los movimientos
		printf ("\nDebe existir movimientos, ingrese nuevamente: ");
		scanf ("%d", &Movimientos);
	}
	
	for (i=0;i<Movimientos;i++){
		system ("cls"); //Aplicamos la libreria <stdlib.h>
		//Proceso
		printf ("\nLos comandos numéricos para mover el robot son: \n");
		printf ("\n6.- Incrementa x en 1\n");
		printf ("4.- Decrementa x en 1\n");
		printf ("8.- Incrementa y en 1\n");
		printf ("2.- Decrementa y en 1\n");
		printf ("\nLa posición actual del robot es de (%d,%d).", x, y); //"Salida"
		printf ("\nIngrese el comando %d/%d: ",i+1,Movimientos);
		scanf ("%d", &Comando);
		
		while (Comando != 6 & Comando != 4 & Comando!=8 & Comando !=2 ){ //Validamos que el comando sean los establecidos
			printf ("Comando no establecido,ingrese nuevamente: ");
			scanf ("%d", &Comando);
		}
		//Determinamos la posición
		switch (Comando){
			case 6:
				x++;
				break;
			case 4:
				x--;
				break;
			case 8:
				y++;
				break;
			case 2:
				y--;
				break;
		}
	}
	printf ("\nLa posición final del robot fue de (%d,%d).", x, y); //"Salida final"
}
