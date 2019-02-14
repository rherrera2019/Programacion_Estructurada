#include <stdio.h>

/*	Ejercicio: ADA 4, Ejercicio 38.
Descripción: E.P.  que  lea  el  nombre,  el  sueldo  y  el  número  de  hijos  de  los  20
empleados de la tlapalería “El Sapo Verde”, y que determine e imprima
nombre  de  los  empleados  con  salario  mayor  a  $  1,000. y  que tengan entre 3 y 7 hijos.
Fecha: 11 Febrero 2019
Versión: 1.0
*/

int main() {
	
	int cont, hijos;
	float sueldo;
	char nombre[20];
	
	cont = 1;
	
	printf("\nBienvenidos empleados de El sapo verde.\n");
	
	while(cont <= 4){
		
		printf("\nEmpleado %i",cont);
		
		printf("\nIntroduzca su nombre.");
		scanf ("%s",nombre);
		
		printf("Introduzca su salario.");
		scanf ("%f",&sueldo);
		
		printf("Introduzca la cantidad de hijos que tiene.");
		scanf ("%i",&hijos);
		
		if((sueldo > 1000)&&(hijos>2)&&(hijos<8)){
			printf("\n%s tiene un salario mayor a $1000 y entre 3 y 7 hijos.\n",nombre);
		}
		
		
		cont++;
		
	}
	
	return 0;
}

