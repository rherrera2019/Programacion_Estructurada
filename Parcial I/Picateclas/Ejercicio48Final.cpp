/*Programa: SritaSimpatia.C
Descripción: Lee el voto de los 500 alumnos e imprime el nombre de la ganadora. Acepta votos nulos y empate.
Autor: Picateclas
Fecha: 17/02/2019
Versión: 1.0
*/

#include <stdio.h>
#include <conio.h>

int main(void) {
	//Variables
	int Cont_A, Cont_H, i;
	char voto;
	Cont_A= 0;
	Cont_H= 0;
	
	printf("Recordatorio: Si escribe una opción diferente, su voto será anulado");
	for(i=0; i<500; i++){
		//Entrada. Lee el voto.
		printf("\n¿Por cuál candidata desea votar? [Anacreta (A o a) u Hortencia (H o h)]: ");
		scanf(" %c", &voto);
		//Proceso. Determina si es para Anacreta u Hortencia y lo suma al contador.
		switch(voto){
		case 'a':
		case 'A':
			Cont_A++;
			break;
		case 'h':
		case 'H':
			Cont_H++;
			
		}
	}
	
	//Proceso. Determina quién ganó o si fue un empate.
	if(Cont_H>Cont_A){
		//Salida si gana Hortencia.
		printf("\nGanadora: HORTENCIA");
	}else{
		if(Cont_A>Cont_H){
			//Salida si gana Anacreta.
			printf("\nGanadora: ANACRETA");
		}else{
			//Salida si hay empate.
			printf("\nEMPATE. ");
		}
	}
	getch();
	return 0;
}

/* Revisión:
-No se imprimen los acentos en consola.
-EL código cumple con su función.

Revisó: programadores empedernidos.
*/

//Ctrl V + Ctrl C:
/*Picateclas: Probamos el programa y los acentos sí se imprimen. Suponemos que están usando un 
compilador no compatible, mal configurado o usa un encoding diferente*/
