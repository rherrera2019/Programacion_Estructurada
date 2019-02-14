/*42.- E.P. que lea las calificaciones del primer parcial de los
estudiantes de algoritmos y que cuente e imprima cuantos alumnos
obtuvieron calificación mayor a 80.
Fecha: 11/02/2019
Versión: 1.0 */
#include <stdio.h>

int main() 
{
	//ENTRADA//
	float calif;
	int CC, May, NoAlum;
	CC=0;
	May=0;
	printf("¿Cuántos alumnos tienes?: ");
	scanf("%d", &NoAlum);
	//PROCESO//
	do{
		CC=CC+1;
		printf("¿Qué calificación tiene el alumno %d: ",CC);
		scanf("%f", &calif);
		if(calif>80)
		{
		May=May+1;	
		};
		
		
	}
	//SALIDA//
	while (CC!=NoAlum);
	printf("Los alumnos que tuvieron una calificación arriba de 80 fueron: %d ",May);
	return 0;
}
