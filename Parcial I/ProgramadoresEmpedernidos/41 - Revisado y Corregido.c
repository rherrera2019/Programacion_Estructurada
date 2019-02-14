/*
Problema: . E.P. que lea las calificaciones del primer parcial de los
estudiantes de algoritmos y que calcule e imprima el promedio de todo
el grupo

Autor: Programadores Emperdernidos. 
Fecha: 10/02/19
Version: 1.5.
Nombre: 41.c
*/

#include <stdio.h>

int main (){
	
	//variables
	int n, i=1, suma=0;
	float calif, prom;
	
	//ciclo do while que se se usa para volver a preguntar la variable n en caso de que no sea válida (0 o negativos)
	do{
		//ENTRADA
		printf("Cu%cntos alumnos son?: ", 160);
		scanf("%d", &n);
		
		if(n <= 0){
			printf("debe ingresar una cantidad v%clida de alumnos\n\n", 160);
		}
	}
	while(n <= 0);
	
	//Ciclo para preguntar las calificaciones
	while(i<=n){
		//PROCESO
		
		//ciclo do while para que se ingrese una calificacion valida (entre 0 y 100)
		do{
			printf("Alumno #%d, cu%cnto sacaste el primer parcial: ", i, 160);
			scanf("%f", &calif);
			if (calif < 0 || calif > 100){
				printf("Debe ingresar una calificaci%cn v%clida\n\n", 162, 160);	
			}
		}
		while (calif < 0 || calif > 100);
		
		
		suma += calif;
		i++;
	}
	//SALIDA
	
	prom = suma/n;
	printf("El promedio del primer parcial es de %.2f", prom);
	return 0;
}

/*Observaciones:
El programa funciona correctamente, algunas variables pueden tener mejor nombre
para distinguir cual es su papel.
Hay un valor innecesario en la linea 23 no afecta la función del programa pero
solo gasta un poco más de memoria

Revisado por: Equipo Picateclas

*/
