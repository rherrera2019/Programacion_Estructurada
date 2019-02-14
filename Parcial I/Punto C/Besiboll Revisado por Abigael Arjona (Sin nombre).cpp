/*1) Un beisbolista tiene cuatro oportunidades de batear en un juego.
Por cada turno al bate, se registra si el batazo del jugador es "hit", 
"out" o "base por bola". Se quiere saber, en un juego, cuántas veces
jugador batea un "hit", cuántas veces es "out" y cuántas veces recibe
"base por bola". Además, se desea calcular el porcentaje de bateo por
juego del jugador, lo cual se calcula dividiendo el número de veces que batea un hit,
entre las oportunidades de bateo que no son "base por bola". 
E.P. que calcule e imprima lo siguiente:
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	
	char Jug[7];
	int Chit,COut,CBB;
	float PB;
	Chit=0;
	COut=0;
	CBB=0;
	printf ("Jugadas (Hit, Out, BB) \n");
	printf ("Que jugada hizo en el turno 1? \n");
	scanf("%s", &Jug);
	if (strcmp(Jug, "Hit") == 0) {
		Chit=Chit+1;
	} else {
		if (strcmp(Jug, "Out") == 0) {
			COut=COut+1;
		}
		else {
			CBB=CBB+1;
		}
		
	}
	printf ("Que jugada hizo en el turno 2? \n");
	scanf("%s", &Jug);
	if (strcmp(Jug, "Hit") == 0) {
		Chit=Chit+1;
	} else {
		if (strcmp(Jug, "Out") == 0) {
			COut=COut+1;
		}
		else {
			CBB=CBB+1;
		}
		
	}
	printf ("Que jugada hizo en el turno 3? \n");
	scanf("%s", &Jug);
	if (strcmp(Jug, "Hit") == 0) {
		Chit=Chit+1;
	} else {
		if (strcmp(Jug, "Out") == 0) {
			COut=COut+1;
		}
		else {
			CBB=CBB+1;
		}
		
	}
	printf ("Que jugada hizo en el turno 4? \n");
	scanf("%s", &Jug);
	if (strcmp(Jug, "Hit") == 0) {
		Chit=Chit+1;
	} else {
		if (strcmp(Jug, "Out") == 0) {
			COut=COut+1;
		}
		else {
			CBB=CBB+1;
		}
		
	}
	PB=Chit+COut;
	PB=Chit/PB;
	printf("Metió %d Hits \n", Chit);
	printf("Metió %d Outs \n", COut);
	printf("Metió %d Base por Bola \n", CBB);
	printf("El porcentaje de bateo es: %f \n", PB);
	
	//Al poner Base por Bola en las 4 oportunidades, sale: "El porcentaje de bateo es: -1.#IND00"
	
	/*Caso
	Jugadas (Hit, Out, BB)
	Que jugada hizo en el turno 1?
	BB
	Que jugada hizo en el turno 2?
	BB
	Que jugada hizo en el turno 3?
	BB
	Que jugada hizo en el turno 4?
	BB
	Metió 0 Hits
	Metió 0 Outs
	Metió 4 Base por Bola
	El porcentaje de bateo es: -1.#IND00
	*/
	
	return 0;
}
