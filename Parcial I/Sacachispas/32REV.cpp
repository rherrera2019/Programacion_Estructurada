/*E.P: que calcule e imprima el precio del seguro para un determinado modelo y un determinado conductor.

Elaborado por:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 31/ene/2019
Version: 1.0 */

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	
	/*Creamos e inicilizamos los string para comparar  más adelante según el color del auto*/
	char modelo, color_1[] = "claro", color_2[] = "obscuro", color[15];
	
	/*Declaramos las variables enteras necesarias para el programa*/
	int edad_conductor, tiempo_conduciendo; 
	
	/*Declaramos la variable para el precio final del auto*/
	float precio_total, precio;
	
	/*Pedimos las entradas para cálcular el precio final*/
	printf("\nInserte el modelo del auto (A, B o C) ");
	scanf("%c", &modelo); //Leemos el modelo
	
	/*Pedimos el color del auto*/
	printf("\n\nInserte el color del auto (claro u obscuro) ");
	fflush( stdin ); //Usamos la función fflush para evitar la lectura del enter
	gets(color); //Leemos el color
	
	/*Pedimos la edad del coductor*/
	printf("\n\nInserte su edad ");
	fflush( stdin ); //Usamos la función fflush para evitar la lectura del enter
	scanf("%i", &edad_conductor);//Leemos la edad del conductor
	
	/*Pedimos el tiempo que se ha conducido*/
	printf("\n\nInserte el tiempo que ha conducido ");
	fflush( stdin ); //Usamos la función fflush para evitar la lectura del enter
	scanf("%i", &tiempo_conduciendo); //Leemos el tiempo conduciendo
	
	/*Proceso para determinar el costo total del auto(puede ser reducido usando una función)
	el proceso que se realiza en todos los casos es similiar, lo único que cambia es el precio*/
	switch (modelo) //Procesamos el switch según el modelo 
	{
		
	case 'A':
	case 'a': 
		
		if (strcmp(color_1, color) == 0) //Usamos la función strcmp para comparar el color insertado con los disponibles.
		{
			precio = 3800;
			
		} else if (strcmp(color_2, color) == 0)
		{
			precio = 4340;
			
		} else
		{
			printf("\n\nInsertó un color no válido"); //Salida por si se insertó un color no válido
		}
		
		break;
		
	case 'B':
	case 'b': 
		
		if (strcmp(color_1, color) == 0)
		{
			precio = 4930;
			
		} else if (strcmp(color_2, color) == 0)
		{
			precio = 5600;
			
		} else
		{
			printf("\n\nInsertó un color no válido");
		}
		
		break;
		
	case 'C':
	case 'c':
		
		if (strcmp(color_1, color) == 0)
		{
			precio = 7570;
			
		} else if (strcmp(color_2, color) == 0)
		{
			precio = 8250;
			
		} else
		{
			printf("\n\nInsertó un color no válido");
		}
		
		break;
		
	default: printf("\n\nInsertó un tipo no válido"); //Salida por si se insertó un tipo de auto no válido
	break;
	
	}
	
	/*Proceso para determinar el costo total del auto según la edad y el tiempo que se tiene conduciendo*/
	
	if (edad_conductor < 20)
	{
		precio_total = (float)precio * 1.25;
		
	} else if (edad_conductor >= 20 && edad_conductor <= 30)
	{
		precio_total = (float)precio * 1.1;
		
	} else if (edad_conductor >= 31 && edad_conductor <= 65)
	{
		precio_total = precio;
		
	}else
	{
		precio_total = (float)precio * 1.15;
	}
	
	if (tiempo_conduciendo < 2)
	{
		precio_total *= 1.25;
	}
	
	/*Salida del precio final del auto*/
	printf ("\n\nEl precio total es $%.2f", precio_total);
	
	getch(); //Esperamos un caracter del teclado
	
	return 0;
	
}

/* Q\A: El programa funciona correctamente, sólo en la documentación faltó el nombre de los autores. 
Sería bueno que al ingresar el color, acepte también que sea escrito con mayúsculas en lugar de minúsculas (igual que como lo hicieron con el modelo)*/
