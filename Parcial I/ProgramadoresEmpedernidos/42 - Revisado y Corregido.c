/*
Problema: E.P. que lea las calificaciones del primer parcial de los
estudiantes de algoritmos y que cuente e imprima cuantos alumnos
obtuvieron calificación mayor a 80

Autor: Programadores Emperdernidos. 
Fecha: 10/02/19
Version: 1.5.
Nombre: 42.c
*/

#include <stdio.h>

int main (){
	
	//variables
	int n, i=1, cont=0;
	float calif;
	
	//ciclo do while que se se usa para volver a preguntar la variable n en caso de que no sea válida (0 o negativos)
	do{
		//ENTRADA
		printf("Cu%cntos alumnos son?: ", 160);
		scanf("%d", &n);
		
		if(n <= 0){
			printf("debe ingresar una cantidad v%clida de alumnos\n\n", 160);
		}
	}
	while(n <=0);
	
	//Ciclo para preguntar las califaciones
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
		
		if (calif > 80){
			cont++;	
		}
		i++;
	}
	//SALIDA
	
	printf("Hubo un total de %d alumnos que sacaron m%cs de 80", cont, 160);
	return 0;
	
	/*Observaciones:
	El programa funciona correctamente, algunas variables pueden tener mejor nombre
	para distinguir cual es su papel.
	Hay un valor innecesario en la linea 23 no afecta la función del programa pero
	solo gasta un poco más de memoria
	
	Revisado por: Equipo Picateclas
	
	*/
}
