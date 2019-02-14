
//E.P. que determine e imprima la calificación final de un alumno del
//curso “Programación Estructurada”. El desglose de dicha evaluación
//está en escala 100 y tiene los siguientes porcentajes: 40%, dos
//exámenes parciales, 30%, tareas y trabajos,20%, proyecto final y 10%,
//participación en clase..

//Autores = programadores empedernidos.
#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(){
	//Variables del cada apartado de la calificacion final
	float p1, p2, pf, pc, cf, ex, ct;
	int tareas, te;
	
	//pregunta por cada apartado de la calificacion
	printf("cu%cnto obtuviste en el examen parcial 1? (en base a 100)\n", 160);
	scanf("%f", &p1);
	
	printf("cu%cnto obtuviste en el examen parcial 2? (en base a 100)\n", 160);
	scanf("%f", &p2);
	
	printf("cu%cnto cuantas tareas tenias?\n", 160);
	scanf("%d", &tareas);
	
	printf("cu%cnto cuantas tareas entregaste?\n", 160);
	scanf("%d", &te);
	//Si se da que tienes mas tareas entregadas de las que hay, se modifica el valor para que sean iguales y no de un resultado mayor al porcentaje maximo
	if (te > tareas){
		te = tareas;
	}
	
	printf("cu%cnto obtuviste el proyecto final? (en base a 100)\n", 160);
	scanf("%f", &pf);

	printf("cu%cnto obtuviste en participaciones en clase? (en base a 100)\n", 160);
	scanf("%f", &pc);
	
	//operaciones de para sacar la calificacion
	ex = ((p1*20)/100) + ((p2*20)/100);
	ct = (te*30)/tareas;
	cf = ex + ct + ((pf*20)/100) + ((pc*10)/100);
	
	//verifica si aprobo o no el estudiante
	if(cf >= 70 ){
		printf("Aprobaste con %.3f", cf);

	}
	else{
		printf("Reprobaste con %.3f", cf);

	}

	return 0;
}
