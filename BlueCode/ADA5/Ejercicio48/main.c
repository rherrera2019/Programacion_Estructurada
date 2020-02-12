/*
	Name: Ejercicio 48
	Copyright: BlueCode
	Author: Guillermo Canto
	Date: 11/02/20 17:32
	Description: Se  llevará  a  cabo  en  la  Universidad  el  concurso  Srita.  Simpatía. Existen dos candidatas: Hortencia y Anacreta.  
	E.P. que lea el voto de los 500 alumnos y que determine e imprima el nombre de la ganadora. Considerar la posibilidad de votos nulos y empate en el concurso.
*/

#include <stdio.h>
#include <stdlib.h>

#define NUMVOTOS 500


char validarEntrada(char entrada);
void determinarGanador(int v1, int v2);

int main(int argc, char *argv[]) {
	int i;
	char voto;
	int votosHortencia = 0;
	int votosAnacreta = 0;
	
	for(i=0; i<NUMVOTOS; i++){
		printf("CONCURSO SRITA SIMPATIA.\nIngrese su voto:\n1) Hortencia\n2) Anacreta\nPara anular su voto ingrese 0\n");
		scanf("%c", &voto);
		voto = validarEntrada(voto);
		switch(voto){
			case '0':
				printf("Has anulado tu voto.\n");
				break;
			case '1': 
				printf("Has votado por Hortencia.\n");
				votosHortencia++;
				break;
			case '2':
				printf("Has votado por Anacreta.\n");
				votosAnacreta++;
				break;
			default:
				printf("Ha ocurrido un error.\n");
		}
		fflush(stdin);
		system("PAUSE");
		system("CLS");
	}
	determinarGanador(votosHortencia,votosAnacreta);
	system("PAUSE");
	return 0;
}

char validarEntrada(char entrada){
	while(entrada != '0' && entrada != '1' && entrada != '2'){
		printf("Entrada invalida, intenta de nuevo: ");
		scanf("%c", &entrada);
	}
	return entrada;
}

void determinarGanador(int v1, int v2){
	if(v1 == v2){
		printf("Hay un empate entre Hortencia y Anacleta, quienes han juntado %d votos.\n", v1);
	}else if(v1 > v2){
		printf("Ha ganado Hortencia con %d votos!\n", v1);
	}else{
		printf("Ha ganado Anacreta con %d votos!\n", v2);
	}
}
