/*
41.E.P. que lea las calificaciones del primer parcial de los estudiantes 
de algoritmos y que calcule e imprima el promedio de todo el grupo.

Elaboró: Los Compiladores
fecha:11/02/2019
version 1.0

*/

#include <stdio.h>

int main() {
	
	//Variables
	float cali,prom,sumC;
	int n,CG;
	//se inicializan los contadores y sumadores a 0
	prom=0;
	sumC=0;
	CG=1;
	
	//Entrada
	printf("\n N%cmero de alumnos que hay en el grupo: ",163);
	scanf("%d",&n);
	
	//se valida el valor ingresado para el número de alumnos
	while(n<=0){
		printf("\n El n%cmero ingresado no es valido,ingrese nuevamente: ",163);
		scanf("%d",&n);
	}
	//proceso
	while(CG<=n){
		printf("\n Ingrese la calificaci%cn del alumno %d :",162,CG);
		scanf("%f",&cali);
		while(cali<0){
			printf("\n La calificaci%cn ingresada no es valida,ingrese de nuevo",162);
			printf("\n : ");
			scanf("%f",&cali);
		}
		sumC=sumC+cali;
		CG++;
	}
	prom=sumC/n;
	
	//salida
	printf("\n/////////////////////////////////////////////////////////");
	printf("\n///            Promedio de grupo: %.2f             ///",prom);
	printf("\n///////////////////////////////////////////////////////");
	
	return 0;
}
//Entrada:3 alumnos
//cali: 100, 30, 70
//Salida: 66.67
//EL programa funciona muy bien y sin errores.
//Revisado por: Erick Cárdenas, Equipo Punto C
