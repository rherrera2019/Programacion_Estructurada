
/*E.P. que lea las tres calificaciones parciales del semestre de cada
uno de los 50 alumnos y los almacene en una matriz. Deberá imprimir
la posición de los alumnos cuyo promedio final sea mayor al promedio
de grupo
autor: Programadores empedernidos. Versión. 1.0. Fecha: 12/03/19*/
 
#include <stdio.h>

//Constantes y macros
#define ALUMNOS 50
#define EXAMENES 3
#define FOR(A,B) for(A=0;A<B;A++)

int main(){
	//declaración de variables.
	float calificaciones[ALUMNOS][EXAMENES], promAlumnos[ALUMNOS], promGral, sumCalifAlum, sumCalifGral=0;
	int i, j, k, contMayores;
	
	FOR(i,ALUMNOS){
		sumCalifAlum=0;
		FOR(j,EXAMENES){ //lectura de datos
			printf("Ingresa calificaci\242n del examen #%d del alumno #%d> ", j+1, i+1);
			scanf("%d", &calificaciones[i][j]);
			
			sumCalifAlum+=calificaciones[i][j]; //sumador de calificaciones por fila
			sumCalifGral+=calificaciones[i][j]; //sumador general
		}
		promAlumnos[i]=(sumCalifAlum/EXAMENES); //vector que almacena la sumatoria de las calificaciones por fila
	}
	
	//promedio del grupo
	promGral = (sumCalifGral/ALUMNOS*EXAMENES);
	
	FOR(i,ALUMNOS){ //for para ver cuantos alumnos estan arriba del promedio
		if(promAlumnos[i] > promGral){
			contMayores++;
		}
	}
	
	int alumnosMayores[contMayores];
	
	k=0;
	FOR(i,ALUMNOS){ //for para ver cuantos alumnos estan arriba del promedio Y GUARDAR SU POSICION
		if(promAlumnos[i] > promGral){
			alumnosMayores[k] = i+1;
			k++;
		}
	}
	
	FOR(i,contMayores){ //for para ver cuantos alumnos estan arriba del promedio Y GUARDAR SU POSICION
		printf("\nEl alumno #%d tiene un promedio mayor al del grupo", alumnosMayores[i]);
	}
	
	
	return 0;
}
/*Funciona muy bien el código, claro y conciso, muy bien explicado.
Es recomendable no usar macros en los ciclos for, para facilitar la detección
de errores.
