/*Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1. 0. 0
Descripcion del programa: E.P. que lea las calificaciones de 50 alumnos y que determine e
imprima cuantos tienen calificación mayor al promedio de grupo. 
Fecha de creacion: 17/feb/2019
*/
#include <stdio.h>
#define cantidad 50
#define for(i,cantidad) for(i=0; i<cantidad ; i++)//DEFINIMOS EL CICLO FOR

int main(int argc, char *argv[]) {
	//VARIABLES.
	int i, j, CMP=0;
	float calificacion, SumCal=0, PG;
	//PROCESO.
	for(i,cantidad){//INICIAMOS EL CICLO FOR.
		do{
			printf("\nIngresa la calificación del alumno %i: ", (i+1));//ENTRADA
			scanf("%f", &calificacion);//LEEMOS LA CALIFICACIÓN.
			if(calificacion<0){
				printf("Calificación inválida.");
			}
		} while(calificacion<0);
		SumCal=SumCal+calificacion;//SUMADOR DE CALIFICACIONES
	}
	
	PG=SumCal/cantidad;//PROMEDIO GRUPAL.
	//PROCESO.
	for(i,cantidad){//INCIIAMOS CICLO FOR.
		do{
			printf("\nIngresa la calificación del alumno %i nuevamente: ", (i+1));//ENTRADA
			scanf("%f", &calificacion);//LEEMOS LA CALIFICACIÓN.
			if(calificacion<0){
				printf("Calificación inválida.");
			}
		} while(calificacion<0);
		if(calificacion>PG){//SE VERIFICA QUE LA CALIFICACIÓN SEA MAYOR A LA GRUPAL.
			CMP++;//AUMENTA CONTADOR DE MAYORES AL PROMEDIO GRUPAL.
		}
	}
	//SALIDA.
	printf("\nLa cantidad de alumnos con un promedio mayor al del grupo son: %i", CMP);
	
	return 0;
}


/* Revisión:

-No imprime en consola los acentos.
-Los nombres de las variables podrían ser más representativas.
-El código cumple su función.

revisó: Programadores empedernidos.
*/
//Si imprime los acentos.
