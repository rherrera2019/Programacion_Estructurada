/*4.- Los estudiantes de Ingeniería presentaron un examen de
admisión con 100 preguntas. E.P. que lea el nombre y el número de
respuestas correctas para cada una de las 50 personas que
presentaron y que determine e imprima para cada uno su nombre y su
calificación basados en la siguiente tabla:
Respuestas Correctas Calificación Obtenida
30 > R <= 50 50
50 > R <= 60 60
60 > R <= 65 70
65 > R <= 75 80
75 > R <= 90 90
R > 90 100*/
/*Fecha: 11/02/2019
	Versión: 1.0 */
#include <stdio.h>

int main() 
{
	//ENTRADA//
	char nombre[20];
	int NRC, CC, calif;
	CC=0;
	do{
		
		CC=CC+1;
		printf("\n\n ¿Cuál es tu nombre?: ");
		scanf("%s", &nombre);
		printf("\n ¿Cuántas respuestas correctas obtuviste?: ");
		scanf("%d", &NRC);
		//PROCESO//
		if(NRC>30&& NRC<=50)
		{
			calif=50;
		} else {
			if (NRC<=60)
			{
				calif=60;	
			} else {
				if (NRC<=65)
				{
					calif=70;
				} else {
					if (NRC<=75)
					{
						calif=80;
					} else{
						if(NRC<=90)
						{
							calif=90;
						} else
						   calif=100;
					}
				}
			}
		}
		//SALIDA//
		printf("\n %d-Nombre: %s",CC, nombre);
		printf("\n Calificación: %d", calif);
	} while(CC!=50);
	
	
	
	return 0;
}
