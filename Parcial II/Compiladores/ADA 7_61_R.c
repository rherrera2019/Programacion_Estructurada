#include <stdio.h>
#include <stdlib.h>
/*
61. E.P. que lea las tres calificaciones parciales del semestre de cada
uno de los 50 alumnos y los almacene en una matriz. Deberá imprimir
la posición de los alumnos cuyo promedio final sea mayor al promedio
de grupo.
Elaboró:Los compiladores
Fecha:13/Marzo/2019
version 1.0

*/

int main() {

	
	//Variables
	int i,j,x,p;/*Varibales usadas en el ciclo for*/
	int alumnos=50;
	int parciales=3;
	float calificaciones[alumnos][parciales];//matriz de calificaciones por alumno y parcial
	float promedios[alumnos];//vector de los promedios obtenidos de todos los alumnos
	float prom_grupo;//promedio del grupo
	float sum_grupo;//sumador de los promedios de los alumnos
	sum_grupo=0;
	float sum_calificaciones;//sumador de calificaciones
	sum_calificaciones=0;
	float promedio;//promedio por alumno
	promedio=0;
	int band;//verificamos que la calificacion sea mayor que 0
	int alumnos_proFinalMayor;//Alumnos que tuvieron un promedio mayor al del grupo 
	alumnos_proFinalMayor=0;
	
	
	//Entrada
	
	for(i=1;i<=alumnos ;i++){//alumnos
		
		for(j=1;j<=parciales;j++){//parciales
			printf("\n Ingrese la calificacion del parcial %d del alumno %d : ",j,i);
			scanf("%f",&calificaciones[i-1][j-1]);
			//validacion de los datos ingresados
			if(calificaciones[i-1][j-1]<0){
				band=1;
			}
			while(band==1){
				printf("\n El valor ingresado para la calificaci%cn no es valido");
				printf("\n Ingrese nuevamente: ");
				scanf("%f",&calificaciones[i-1][j-1]);
				if(calificaciones[i-1][j-1]>0){
					band=0;
				}
			//-----------------------------------------
		
			
			}
			//Proceso
			sum_calificaciones+=calificaciones[i-1][j-1];
			system("cls");
		}
		promedio=sum_calificaciones/parciales;
		sum_grupo+=promedio;
		sum_calificaciones=0;
		promedios[i-1]=promedio;
	}
	prom_grupo=sum_grupo/alumnos;
	
	for(x=1;x<=alumnos;x++){
			
		if(promedios[x-1]>prom_grupo){//buscamos cuantos alumnos tienen un promedio mayor al del grupo
			alumnos_proFinalMayor++;
		}
		
	}
	int posicion_fila[alumnos_proFinalMayor];//vector para indicar la posicion del alumno con promedio mayor al del grupo,con el contador de alumnos con promedio mayor,definimos el tamaño del vector
	//Salida
	printf("\n***Resultados***");
	printf("\n\n Promedio de grupo: %.2f ",prom_grupo);//se imprime el promedio del grupo
	
	if(alumnos_proFinalMayor==0){
		printf("\n No hay ningun alumno con promedio mayor al promedio de grupo");
	}else {
	printf("\n-----------------------------------------");
	printf("\n\n Alumnos con promedio mayor al grupo: ");}
	
	for(p=0;p<alumnos;p++){
		
			if(promedios[p]>prom_grupo){//Encontramos al alumnos con un promedio mayor y guardamos su posicion
				posicion_fila[p]=(p+1);
				printf("\n Alumno %d ",posicion_fila[p]);
			}
		

	}
	
	
	return 0;
}
/*Revisión por Programadores Empedernidos.

-El código funciona bien.
-Se cumple lo que se pide.
-El nombre de las variables es representativo.
-Nos agradó la forma en cómo se imprimen los resultados. Muy limpio.*/

