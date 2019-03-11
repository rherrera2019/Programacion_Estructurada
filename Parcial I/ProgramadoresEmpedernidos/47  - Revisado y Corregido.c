#include <stdio.h>
#include <conio.h>
/* Se definen las constantes */
#define TOTAL_ALUMNOS 50

/*
Nombre: 47_mayor-al-promedio.c
Autor: Programadores empedernidos
Descripcion: E.P. que lea las calificaciones de 50 alumnos y que determine e
			imprima cuantos tienen calificación mayor al promedio de grupo.
Fecha: 12feb2019
Versión: 1.0 */
int main(int argc, char *argv[]) {
	/* Se definen las variables */
	int calificacion,i,contador_prom=0, acumulador=0;
	float promedio_de_grupo;
	//Entrada 1: se piden las calificaciones del cada alumno para obtener el promedio
	printf("--------CALIFICACIONES PARA SACAR PROMEDIO---------\n");
	for(i=1;i<=TOTAL_ALUMNOS;i++){
		do{
			printf("[%i/%i] Calificaci%cn: ",i,TOTAL_ALUMNOS,162);
			scanf("%i",&calificacion);
			if(calificacion < 0){
				printf("No puedes ingresar una calificacion negativa\n\n");
			}
		}
		while(calificacion < 0);
		acumulador+=calificacion;
	}
	//Calculo del promedio del grupo
	promedio_de_grupo= acumulador/TOTAL_ALUMNOS;
	printf("\nEl promedio de grupo es %.2f\n", promedio_de_grupo);
	
	/* Entrada 2: las calificaciones se piden de nuevo para saber si estan arriba del promedio*/
	printf("\n---------CALIFICACIONES PARA SABER CUANTOS ESTAN ARRIBA DEL PROMEDIO---------\n");
	for (i=1;i<=TOTAL_ALUMNOS;i++){
		printf("[%i/%i] Calificaci%cn: ",i,TOTAL_ALUMNOS,162);
		scanf("%i",&calificacion);
		/* Proceso: Se verifica si la calificación es mayor al promedio del grupo */
		if (calificacion>promedio_de_grupo){
			contador_prom++;
		}
	}
	
	/* Salida: Se imprime la cantidad de alumnos con califiacion mayor al promedio */
	printf("\n%i alumnos tienen calificaci%cn mayor al promedio del grupo",contador_prom,162);
	getch();
	return 0;
}
//Revisado: Equipo picateclas.
/*Comentarios: No valida si el usuario ingresa valores negativos, por otro lado,
el código funciona correctamente si el usario no ingresa valores negativos.*/
