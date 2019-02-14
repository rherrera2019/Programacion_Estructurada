/* 44.- Los estudiantes de Ingeniería presentaron un examen de
admisión con 100 preguntas. E.P. que lea el nombre y el número de
respuestas correctas para cada una de las 50 personas que
presentaron y que determine e imprima para cada uno su nombre y su
calificación basados en la tabla.

Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé
Fecha: 7/feb/2019
Version: 1.0 */


#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Creamos las variables necesarias para el programa*/
	int cont_personas, aciertos_actual;
	
	char nombre[40];
	
	/*Inicializamos el contador para los números*/
	cont_personas = 1;
	
	/*Creamos el ciclo do-Swhile para la lectura de los 100 números*/
	do
	{
		/*ENTRADA DE DATOS*/
		printf("\n\nInserte su nombre ");
		fflush(stdin);
		gets(nombre);
		
		printf("\n\nInserte sus aciertos ");
		fflush(stdin);
		scanf("%i", &aciertos_actual);
		
		cont_personas++;
		
		/*PROCESO para determinar la calificación del estudiante*/
		if (aciertos_actual > 90 && aciertos_actual <= 100)
		{
			printf("\n\n%s tiene una calificación es de 100", nombre); /*SALIDA DE DATOS*/
			
		} else if (aciertos_actual > 75 && aciertos_actual <= 90)
		{
			printf("\n\n%s tiene una calificación es de 90", nombre); /*SALIDA DE DATOS*/
			
		} else if (aciertos_actual > 65 && aciertos_actual <= 75)
		{
			printf("\n\n%s tiene una calificación es de 80", nombre); /*SALIDA DE DATOS*/
			
		} else if (aciertos_actual > 60 && aciertos_actual <= 65)
		{
			printf("\n\n%s tiene una calificación es de 70", nombre); /*SALIDA DE DATOS*/
			
		} else if (aciertos_actual > 50 && aciertos_actual <= 60)
		{
			printf("\n\n%s tiene una calificación es de 60", nombre); /*SALIDA DE DATOS*/
			
		} else if (aciertos_actual > 30 && aciertos_actual <= 50)
		{
			printf("\n\n%s tiene una calificación es de 50", nombre); /*SALIDA DE DATOS*/
			
		} else if (aciertos_actual >= 0 && aciertos_actual <= 30)
		{
			printf("\n\n%s, te fue muy mal", nombre); /*SALIDA DE DATOS*/
			
		} else 
		{
			printf("\n\n%s, insertaste una cantidad no válida. Vuelve a intentarlo ", nombre); /*SALIDA DE DATOS*/
			
			cont_personas--;
		}
	} while (cont_personas <= 50);
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}

/*
Revisado por: Los compiladores

El programa funciona aun ingresado valores de punto flotante,cuando no deberia de ser asi
ya que no existiria la poibilidada de ingresar 96.5 respuestas correctas
Reducir  las condiciones del if:Recomendacion

*/
