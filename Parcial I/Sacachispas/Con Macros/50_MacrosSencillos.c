/* 50.Se llevará a cabo en la Universidad el concurso Srita. Simpatía. 
Existen dos candidatas: Hortencia y Anacreta.  
E.P. que lea el voto de los 500 alumnos y que determine e imprima el nombre de la ganadora. 
Considerar la posibilidad de votos nulos y empate en el concurso.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 13/feb/2019
Version: 1.0 (Usando macros sencillos)*/

#include <stdio.h>
#include <string.h>
#include <conio.h>

#define HORTENCIA "Hortencia"
#define ANACLETA "Anacleta"
#define ALUMNOS 500

int main() {
	
	/*Creamos las variables necesarias para el programa*/
	int cont_hortencia, cont_anacleta, cont_alumnos;
	
	char candidata;
	
	/*Inicializamos el contador para los alumnos y las candidatas*/
	cont_alumnos = 1;
	cont_hortencia = 0;
	cont_anacleta = 0;
	
	printf("\nH por Hortencia, A por Anacleta o N por nulo");
	
	/*Creamos el ciclo for para la lectura de los 500 alumnos*/
	for (cont_alumnos = 1; cont_alumnos <= ALUMNOS; cont_alumnos++)
	{
		/*ENTRADA DE DATOS*/
		printf("\n\nInserte la inicial de la candidata ");
		fflush(stdin);
		scanf("%c", &candidata);
		
		switch (candidata)
		{
			
		case 'h':
		case 'H': 
			
			printf("\n\nVotaste por %s", HORTENCIA);
			
			cont_hortencia++;
			
			break;
			
		case 'a':
		case 'A':
			
			printf("\n\nVotaste por %s", ANACLETA);
			
			cont_anacleta++;
			
			break;
			
		case 'n':
		case 'N':
			
			printf("\n\nTu voto fue nulo");
			
			break;
			
		default:
			
			printf("\n\nInsertaste una letra NO válida, inténtalo de nuevo");
			
			cont_alumnos--; //Se reduce el contador para evitar el salto del alumno actual
			
		}
	}
	
	/*SALIDA DE DATOS*/
	if (cont_hortencia > cont_anacleta)
	{
		printf("\n\nLa ganadora fue %s", HORTENCIA);
		
	} else if (cont_anacleta > cont_hortencia)
	{
		printf("\n\nLa ganadora fue %s", ANACLETA);
		
	} else
	{
		printf("\n\nHubo un empate");
	}

	getch(); //Esperar un caracter del teclado
	
	return 0;
}
/* Calificó: Punto C
-Según el problemario corregido este deberia ser el problema número 48 
-El programa funciona correctamente, detecta como ganadora a cada una 
cuando llevan la mayoria de votos independientemente de la cantidad total de 
estos, marca un empate incluso cuando el resultado es empate a cero(cosa que esta bien)
-Buena idea al considerar mayusculas y minusculas en el switch
-Disminuir el contador en el default puede estar de más ya que solo aumenta si 
el voto fue alguno de los que estan considerados en el problema 
-Para que quede un poco más elegante se podría agregar una función para borrar
pantalla debido a la cantidad de operaciones que se van a realizar, o bien colocar 
algo que marque el inicio de la lectura de un nuevo voto. 
-Valida correctamente 
-Bien al ejemplificar con el macro que se puede utilizar para imprimir 
algo especifico en el printf 
-El macros funciona correctamente y esta bien definido
*/
