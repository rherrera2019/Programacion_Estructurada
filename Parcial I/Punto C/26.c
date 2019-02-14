#include <stdio.h> 
#include <conio.h>
#include <math.h>

/*Ejercicio 26: Desglose de calificación 
Descripción: E.P. que determine e imprima la calificación final de un alumno del
curso “Programación Estructurada”. El desglose de dicha evaluación
está en escala 100 y tiene los siguientes porcentajes: 40%, dos
exámenes parciales, 30%, tareas y trabajos,20%, proyecto final y 10%,
participación en clase. 
Fecha: 05/02/2019
Versión: 1.0 */

int main ()
	{
	float P1,P2,TE,PF,P,CF ; 
	float PP,PT ;
	float Tareas ;
	
	printf( "\n Calificacion del parcial 1 : " ) ; 
	scanf ("%f", &P1) ;
	
	printf( "\n Calificacion del parcial 2 : " ) ; 
	scanf ("%f", &P2) ;
	
	printf( "\n Numero de tareas del semestre : " ) ; 
	scanf ("%f", &Tareas) ;
	
	printf( "\n Numero de tareas entregadas : " ) ; 
	scanf ("%f", &TE) ;
	
	printf( "\n Calificacion del proyecto final sobre 20 : " ) ; 
	scanf ("%f", &PF) ;
	
	printf( "\n Numero de participaciones en clase (maximo 10) : " ) ; 
	scanf ("%f", &P) ; 
	
	printf( "\n ----------------------------------------------------- : " ) ; 
	
	PP=(P1+P2)/5 ; 
	PT=(TE*20)/Tareas ; 
	CF=PP+PT+PF+P ; 
	
	printf( "\n Porcentaje de parciales  : %.2f ", PP ) ;
	printf( "\n Porcentaje por tareas : %.2f ", PT ) ;
	printf( "\n Porcentaje del proyecto final : %.2f ", PF ) ;
	printf( "\n porcentaje de paricipaciones : %.2f ", P ) ;
	printf( "\n Calificacion final : %.2f ", CF ) ;
	
	printf( "\n ----------------------------------------------------- : " ) ; 
	
	if (CF>=70)
		printf( "\n Alumno aprobado  " ) ; 
	else if (CF<70)
		printf( "\n Alumno reprobado  " ) ;
		
	getch () ;
	
	return 0; 
	
	
	
}
