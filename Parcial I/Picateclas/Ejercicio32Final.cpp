/*Programa: CaraDelDado.c

Autor: EQUIPO PICATECLAS
López Madera Fernanda Jacqueline
González Bautista Noé Alejandro
Durán Matos Juan José

Descripción: Determina el precio de un seguro de auto de acuerdo al modelo, colo, edad del conductor y años que lleva conduciendo con permiso.
Versión: 1.0
Fecha de creacion: 4/feb/2019
*/


#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void) {
	/*declaración de variables*/
	char modelo, color;
	int edad, tiempoc;
	float precio;
	
	/*ENTRADA. Se solicitan las variables*/
	printf("Ingresa el modelo del auto (A, B o C): ");
	scanf ("%c", &modelo);
	printf("Ingresa el color del auto [Claro (C) u Oscuro (O)]: ");
	scanf (" %c", &color);
	printf("Ingresa la edad del conductor: ");
	scanf ("%i", &edad);
	printf("Ingresa los años que lleva conduciendo: ");
	scanf ("%i", &tiempoc);
	
	/*PROCESO. Se evalúa el precio inicial de acuerdo al modelo y color*/
	switch(modelo){
		case 'A':
	    case 'a':
			switch (color){
				case 'C':				
			    case 'c':
					precio = 3800.0;
				    break;
				case 'O':
			    case 'o':
				    precio = 4340.0;
				    break;
			}
		break;
		case 'B':
		case 'b':
			switch (color){
				case 'C':
			    case 'c':
					precio = 4930.0;
					break;				
			    case 'O':
			    case 'o':
				    precio = 5600.0;
				    break;
			}
		break;
		case 'C':
	    case 'c':
			switch (color){
				case 'C':
		     	case 'c':
					precio = 7570.0;
					break;
				case 'O':
			    case 'o':				
				    precio = 8250.0;
				    break;
			}
		break;
	}
	
	/*PROCESO. Se agrega un adicional dependiendo el rango de edad*/
	if(edad<20){
		precio = precio + precio*0.25;
	}else{
		if(edad<31){
			precio = precio + precio*0.1;
		}else{
			if(edad<66){
				precio = precio;
			}else{
				if(edad>65){
					precio = precio + precio*0.15;
				}
			}
		}
	}
	
	/*PROCESO. Se agrega un adicional dependiendo el tiempo conduciendo*/
	if(tiempoc<2){
		precio = precio + precio*0.25;
	}
	
	/*SALIDA. Imprime el costo del seguro*/
	printf("El precio del seguro es: %.2f", precio);
	getch();
	return 0;
}

/*El programa funciona correctamente. Hay un error en el switch, no se cambiaron algunos precios dependiendo del color

Equipo:
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 6/02/2019*/

