/*HECHO POR VICTOR ENRIQUE CAUICH DAVALOS y ALAN JOSUE BARÓN PAT
26. E.P. que determine e imprima la calificación final de un alumno del curso “Programación Estructurada”. 
El desglose de dicha evaluación está en escala 100 y tiene los siguientes porcentajes: 
40% dos exámenes parciales, 
30% tareas y trabajos,
20% proyecto final y 
10% participación en clase.

*/
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...

int main()
{
	setlocale(LC_ALL,"");//LLamo al metodo de la biblioteca locale.h, para que todas las actuaciones, puedan verse...
	printf("EJERCICIO 26. CÁLCULAR CALIFICACIÓN FINAL DE ALUMNO.\n\n");
	printf("Ingrese por favor el porcenje entre los dos parciales (Vale máximo 40%): ");
	float Examenes;
	scanf("%f", &Examenes);
	printf("Ingrese por favor el porcenje entre las tareas y trabajos (Vale máximo 30%): ");
	float TareasYTrabajos;
	scanf("%f", &TareasYTrabajos);
	printf("Ingrese por favor el porcenje del proyecto final (Vale máximo 20%): ");
	float ProyectoFinal;
	scanf("%f", &ProyectoFinal);
	printf("Ingrese por favor el porcenje de participaciones (Vale máximo 10%): ");
	float Participaciones;
	scanf("%f", &Participaciones);
	
	printf("\nLa calificación es: %.2f.\n", Examenes + TareasYTrabajos + ProyectoFinal + Participaciones);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
