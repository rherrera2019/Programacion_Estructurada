#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
Nombre: 44.c
Autor: Programadores empedernidos
Descripcion: Los estudiantes de Ingeniería presentaron un examen de admisión con
			100 preguntas.  E.P. que lea el nombre y el número de respuestas 
			correctas para cada una de las 50 personas que presentaron y que
			determine e imprima para cada uno su nombre y su calificación
			basados en la siguiente tabla:
			Respuestas Correctas Calificación Obtenida
			30 > R <= 50 					50
			50 > R <= 60 					60
			60 > R <= 65 					70
			65 > R <= 75 					80
			75 > R <= 90 					90
				 R > 90 					100
Fecha: 09feb2019
Versión: 1.5 */

int main(int argc, char *argv[]) {
	/*se definen las variables*/
	char nombre_alumno[50];
	int respuestas_correctas,calificacion;
	int i = 0; 
	/*entrada: Se solicitan los nombres y califiaciones */
	while (i<50){
		printf("%i/50 Nombre: ",i+1);
		fflush(stdin);
		gets(nombre_alumno);
		// numeros[i] = i-50; //para pruebas
		
		printf("%i/50 Respuestas correctas: ",i+1);
		scanf("%i",&respuestas_correctas);
	}
		/*proceso: Se calcula la calificacion*/
		if (respuestas_correctas>90){
			calificacion=100;
		}
		else if(respuestas_correctas>75){
			calificacion=90;
		}
		else if(respuestas_correctas>65){
			calificacion=80;
		}
		else if(respuestas_correctas>60){
			calificacion=70;
		}
		else if(respuestas_correctas>50){
			calificacion=60;
		}
		else if(respuestas_correctas>30){
			calificacion=50;
		}
		else{
			calificacion=0;
		}
		//Salida
		printf("%s: %i\n",nombre_alumno,calificacion);
		strcpy(nombre_alumno,"");
		i++;
	};
	
/*
Observaciones

Funciona perfectamente, buen uso de comentarios, pero faltó distinguir donde se
encuentra la salida.
	
Revisado por: Equipo Picateclas

	
*/
	return 0;
}

