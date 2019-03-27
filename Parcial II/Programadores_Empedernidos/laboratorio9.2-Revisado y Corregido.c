/*
Un maestro que imparte un curso de Programación Estructurada, entrega calificaciones (tipo real), del segundo parcial a sus alumnos. 
Éstos, se sientan en un rectángulo dentro del laboratorio de cómputo, formado por N filas y M columnas de sillas . Se desea como 
conocer la posición (fila, columna), de los estudiantes, que tienen la mayor calificación del grupo. Además, se desea conocer cuántos 
reprobaron (es decir, obtuvieron menos de 70 puntos). Finalmente, se desea determinar cuál es el promedio del grupo y generar un vector 
que contenga el promedio de las calificaciones de cada fila.    E.P. que realice lo solicitado. 
*/
#include <stdio.h>

//macros
#define FOR(A,B) for(A=0;A<B;A++)

int main(){
	int n, m, i, j, k, reprobados=0, mayorCalif=0, contMayores=0;
	float sumaCalif=0, sumaFila=0, prom;
	
	printf("Cuantas filas hay: ");
	scanf("%d", &n);
	printf("Cuantas columnas hay: ");
	scanf("%d", &m);
	
	float parcial[n][m], promFilas[n];
	FOR(i,n){
		sumaFila=0;
		FOR(j,m){
			printf("Dame la calificacion del alumno de la fila #%d, columa #%d: ", i+1, j+1);
			scanf("%f", &parcial[i][j]);			
			
			sumaCalif += parcial[i][j];
			sumaFila += parcial[i][j];
			
			if(parcial[i][j] < 70){
				reprobados++;
			}
			if(mayorCalif < parcial[i][j]){
				mayorCalif = parcial[i][j];
			}
			
		}
		promFilas[i] = sumaFila/m;
	}
	
	//imprimir calificaciones
	printf("\nCalificaciones: \n");
	FOR(i,n){
		FOR(j,m){
			printf("  %.2f", parcial[i][j]);
		}
		printf("\n");
	}
	//promedio
	prom = sumaCalif/(n*m);
	
	FOR(i,n){
		FOR(j,m){
			if(parcial[i][j] == mayorCalif){
				contMayores++;
			}
		}
	}
	int filaMayorAlumnos[contMayores], colMayorAlumnos[contMayores];
	
	k=0;
	FOR(i,n){
		
		FOR(j,m){
			if(parcial[i][j] == mayorCalif){
				filaMayorAlumnos[k]=i;
				colMayorAlumnos[k]=j;
				k++;
			}
		}
	}
	
	//imprimir alumnos con mayor calif
	printf("El promedio del grupo es %.2f\n\n", prom);
	FOR(i,n){
		printf("El promedio de la fila #%d es %.2f\n", i+1, promFilas[i]);
	}
	printf("\nHay un total de %d reprobados\n\n", reprobados);
	FOR(i,contMayores){
		printf("Alumno con mayor calif #%d esta en la pos (%d,%d)\n", i+1, filaMayorAlumnos[i]+1, colMayorAlumnos[i]+1);
	}

}
/*
-El codigo funciona correctamente
-Identifica el promedio de las filas y la calificacion mayor
-Imprime correctamente la matriz
Revisó:PuntoC*/
