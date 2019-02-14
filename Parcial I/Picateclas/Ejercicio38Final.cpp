/* Programa: EmpleadosElSapoVerde.C
Descripción:  Lee el nombre, el sueldo y el número de hijos de los 20 empleados de la 
tlapalería “El Sapo Verde”, y determina e imprime el nombre de los empleados con 
salario mayor a $ 1,000 y que tengan entre 3 y 7 hijos.
Autor: Picateclas
Integrantes:
- López Madera Fernanda Jacqueline
- Durán Matos Juan José
- González Bautista Noé Alejandro
Versión: 1.0
Fecha: 12/feb/2019 */

#include <stdio.h>
#include <conio.h>

int main() {
	/*VARIABLES*/
	char nombre[40];
	float sueldo;
	int c_general, hijos;
	c_general=0;
	
	/*ENTRADA*/
	do{
		c_general=c_general+1;
		printf("\nEmpleado no. %i", c_general);
		printf("\nNombre: ");
		scanf("%s", nombre);
		printf("\nSueldo: $");
		fflush(stdin);
		scanf("%f", &sueldo);
		printf("\nHijos: ");
		fflush(stdin);
		scanf("%i", &hijos);
		/*PROCESO*/
		if(sueldo>1000.0){ //Determina si el sueldo del empleado es mayor a 1000
			if(hijos>=3){   //Determina si el numero de hijos esta entre 3 y 7
				if(hijos<=7){
					/*SALIDA*/
					printf("\n ");
					printf("%s", nombre);
					
				}
			}
		}
	}while(c_general<20);
	getch();
	return 0;
}

/*El programa funciona correctamente, separar el código para que sea más fácil entenderlo.
Indicar de manera más clara cuando un empleado cumple con lo se pide en el problema

Equipo: SacaChispas
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 13/02/2019*/

