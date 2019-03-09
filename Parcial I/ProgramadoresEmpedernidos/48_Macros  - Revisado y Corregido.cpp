#include <stdio.h>
#include <conio.h>
#include <string.h>
/* Se definen las contantes */
#define TOTAL_VOTANTES 500
#define FOR(A,B) for(A=1; A<=B; A++)
#define CONTADOR(V,A,B,C) switch(V){case 1: A++; break; case 2: B++; break; default: C++; break;}
#define GANADORA(A,B,G) if (A>B){strcpy(G,"Hortencia");}else if(B>A){strcpy(G,"Anacreta");}else{strcpy(G,"Empate");}


/*
Nombre: 48_srita-simpatia.c
Autor: Programadores empedernidos
Descripcion: Se llevará a cabo en la Universidad el concurso Srita. Simpatía. 
Existen dos candidatas: Hortencia y Anacreta.  E.P. que lea el voto de los 500 
alumnos y que determine e imprima el nombre de la ganadora. Considerar la 
posibilidad de votos nulos y empate en el concurso.

Fecha: 12feb2019
Versión: 1.0 */

int main(int argc, char *argv[]) {
	/* Se definen las variables */
	int voto,i,contador1=0, contador2=0, contadorNulo=0;
	char ganadora[10];
	
	/* Entrada: Se solicita el voto a los alumnos usando macros */
	FOR(i,TOTAL_VOTANTES){
		printf("\n%i. Escribe el número correspodiente a la concursante\n",i+1);
		printf("[1] Hortencia    [2] Anacreta   \n    ]<\r >[");
		scanf("%i",&voto);
		/* Se acumulan los votos en los correspondientes contadores usando macros*/
		CONTADOR(voto,contador1,contador2,contadorNulo);
	}
	/* Se verifica la ganadora o el empate  usando macros*/
	GANADORA(contador1,contador2,ganadora);
	
	/* Salida: Se imprime la ganadora */
	int x; for (x=0;x<42;x++){printf("%c",205);};printf("%c\r%c",187,201);
	printf("\n                                          %c\r",186);
	printf("%c Votos a Hortencia: %i\n                                          %c\r",186,contador1,186);
	printf("%c Votos a Anacreta: %i\n                                          %c\r",186,contador2,186);
	printf("%c Votos Nulos: %i\n                                          %c\r",186,contadorNulo,186);
	printf("%c Ganadora: %s\n                                          %c\r",186,ganadora,188);
	for (x=0;x<42;x++){printf("%c",205);};printf("\r%c\n",200);
	getch();
	return 0;
}

/*El programa funciona correctamente. Se incluyeron bien los macros, buen uso de la función #define. 
No era necesario imprimir la cantidad de votos nulos pero fue un buen detalle.
Se ve bastante bien el recuadro en el que imprimieron los resultados.
Eran 500 votos, pero imagino que pusieron 5 para las pruebas y se les olvidó cambiarlo.

Revisó: Picateclas*/
