/*HECHO POR VICTOR ENRIQUE CAUICH DAVALOS y ALAN JOSUE BAR�N PAT
26. E.P. que determine e imprima la calificaci�n final de un alumno del curso �Programaci�n Estructurada�. 
El desglose de dicha evaluaci�n est� en escala 100 y tiene los siguientes porcentajes: 
40% dos ex�menes parciales, 
30% tareas y trabajos,
20% proyecto final y 
10% participaci�n en clase.

*/
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y m�s...

int main()
{
	setlocale(LC_ALL,"");//LLamo al metodo de la biblioteca locale.h, para que todas las actuaciones, puedan verse...
	printf("EJERCICIO 26. C�LCULAR CALIFICACI�N FINAL DE ALUMNO.\n\n");
	printf("Ingrese por favor el porcenje entre los dos parciales (Vale m�ximo 40%): ");
	float Examenes;
	scanf("%f", &Examenes);
	printf("Ingrese por favor el porcenje entre las tareas y trabajos (Vale m�ximo 30%): ");
	float TareasYTrabajos;
	scanf("%f", &TareasYTrabajos);
	printf("Ingrese por favor el porcenje del proyecto final (Vale m�ximo 20%): ");
	float ProyectoFinal;
	scanf("%f", &ProyectoFinal);
	printf("Ingrese por favor el porcenje de participaciones (Vale m�ximo 10%): ");
	float Participaciones;
	scanf("%f", &Participaciones);
	
	printf("\nLa calificaci�n es: %.2f.\n", Examenes + TareasYTrabajos + ProyectoFinal + Participaciones);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
