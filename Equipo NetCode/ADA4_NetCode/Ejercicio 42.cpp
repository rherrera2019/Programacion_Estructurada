#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Calificaciones del 1er parcial 2.0
Descripci�n:  Lee las calificaciones del primer parcial de los estudiantes de P.E y calcule e imprima cu�ntos alumnos sacaron mayor a 80 pts
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 06/02/2020
*/
int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num,alumnos, AlumnosAceptados = 0; //Declaramos e inicializamos las variables 
	double Puntaje;
	num = 0;
	alumnos = 0;
	Puntaje = 0.0;
	printf ("Programa que calcula cu�ntos alumnos sacaron \nmayor a 80 pts en su primer parcial.\n");
	printf ("Ingrese el total de alumnos: "); //Ingresamos el n�mero de alumnos con el cual se determina el promedio;
	scanf ("%d", &alumnos);
	
	if (alumnos<=0){//Si no existe ning�n alumno entonces no hace nada el programa
		printf ("\nTiene que existir alumnos");//Validamos el dato
	} else
	{
		while (num < alumnos){//Se repite el bucle hasta que ingresen todos los alumnos sus puntajes
			printf ("\nIngrese su puntaje alumno %d (entre 0-100): ", num + 1);
			scanf ("%lf", &Puntaje);//Se ingresa el puntaje de cada alumno
			if (Puntaje <0 || Puntaje>100){//Se valida si el puntaje ingresado no sea erroneo
				printf ("\nPuntaje no v�lido\n");//Validamos
			}else{
				num++;//Se pasa al siguiente alumno si es que hay
				if(Puntaje > 80)//Si es mayor a 80 el puntaje entonces cuenta como que un alumno mas cumpli� los requisitos
				{
					AlumnosAceptados++;	
				}
			}
		}
	}
	//Se imprimen cu�ntos alumnos cumplieron el requisito de tener mayor que 80 puntos
	printf("\n\nHay %d alumno(s) que sacaron en el primer parcial \nde programaci�n estructurada mas de 80pts.", AlumnosAceptados);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
