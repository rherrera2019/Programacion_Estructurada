#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Calificaciones del 1er parcial 2.0
Descripción:  Lee las calificaciones del primer parcial de los estudiantes de P.E y calcule e imprima cuántos alumnos sacaron mayor a 80 pts
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 06/02/2020
*/
int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num,alumnos, AlumnosAceptados = 0; //Declaramos e inicializamos las variables 
	double Puntaje;
	num = 0;
	alumnos = 0;
	Puntaje = 0.0;
	printf ("Programa que calcula cuántos alumnos sacaron \nmayor a 80 pts en su primer parcial.\n");
	printf ("Ingrese el total de alumnos: "); //Ingresamos el número de alumnos con el cual se determina el promedio;
	scanf ("%d", &alumnos);
	
	if (alumnos<=0){//Si no existe ningún alumno entonces no hace nada el programa
		printf ("\nTiene que existir alumnos");//Validamos el dato
	} else
	{
		while (num < alumnos){//Se repite el bucle hasta que ingresen todos los alumnos sus puntajes
			printf ("\nIngrese su puntaje alumno %d (entre 0-100): ", num + 1);
			scanf ("%lf", &Puntaje);//Se ingresa el puntaje de cada alumno
			if (Puntaje <0 || Puntaje>100){//Se valida si el puntaje ingresado no sea erroneo
				printf ("\nPuntaje no válido\n");//Validamos
			}else{
				num++;//Se pasa al siguiente alumno si es que hay
				if(Puntaje > 80)//Si es mayor a 80 el puntaje entonces cuenta como que un alumno mas cumplió los requisitos
				{
					AlumnosAceptados++;	
				}
			}
		}
	}
	//Se imprimen cuántos alumnos cumplieron el requisito de tener mayor que 80 puntos
	printf("\n\nHay %d alumno(s) que sacaron en el primer parcial \nde programación estructurada mas de 80pts.", AlumnosAceptados);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
