/*
Nombre: 26- Calificación final “Programación Estructurada”.c
Autor: Los Compiladores
Fecha : 6Feb19
Entradas: Numeros decimales
Salidas: Calificacion correspondiente al porcentaje de cada desgloce
Procedimiento General: Se determina la calificacion en porcentaje de cada desgloce y al final se suman para dar la calificacion final
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	float P1, P2;
	float P;
	float TyT;
	float T;
	float ProFin;
	float PF;
	float ParCla;
	float PC;
	float CF;
	
	printf("--> Calificación final de un alumno del curso Programación Estructurada <-- \n");
	printf( "\n-- Introduzca calificacion del parcial 1: " );
		scanf("%f", &P1); /*Se ingresa el numero a evaluar (Entrada)*/
	
	printf( "-- Introduzca calificacion del parcial 2: " );
		scanf("%f", &P2); /*Se ingresa el numero a evaluar (Entrada)*/
	
	P=(((P1+P2)/2)*40)/100; /*Ahora, se operan los numeros para determinar el porcentaje de calificacion*/
	
	printf("\n>> Dos exámenes parciales: %.2f Porciento \n", P); /*Salida: Imprime el porcentaje de calficacion correspondiente*/
	
	printf( "\n-- Introduzca calificacion de tareas y trabajos: " );
		scanf("%f", &TyT);
	
	T=(TyT*30)/100;
	
	printf("\n>> Tareas y trabajos: %.2f Porciento \n", T);
	
	printf( "\n-- Introduzca calificacion del proyecto final: " );
		scanf("%f", &ProFin);
	
	PF=(ProFin*20)/100;
	
	printf("\n>> Proyecto final: %.2f Porciento \n", PF);
	
	printf( "\n-- Introduzca calificacion de la participación en clase: " );
		scanf("%f", &ParCla);
	
	PC=(ParCla*10)/100;
	
	printf("\n>> Participación en clase: %.2f Porciento \n", PC);
	
	CF=P+T+PF+PC;
	
	printf("\n -> Calificacion Final: %.2f <-", CF);
	
	if ( CF >= 70 ) /*Se verifica que el numero ingresado sea válido*/
	{
		printf( "\n>> APROBADO" );
	}
	else
	{
		printf( "\n>> SUSPENDIDO" );
	}
	/*Salida: Se imprime el resultado obtenido (APROBADO, SUSPENDIDO)*/
	
	return 0;
}
//El codigo funciona bien solo en los casos esperados, si se ingresan valores negativos no hace bien el proceso
//Es legible y se entiende
//Reviso: Programadores Empedernidos

