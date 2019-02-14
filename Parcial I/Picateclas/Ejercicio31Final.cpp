/*Programa: PocisiónDeLetra.c

Autor: EQUIPO PICATECLAS
López Madera Fernanda Jacqueline
González Bautista Noé Alejandro
Durán Matos Juan José

Descripción: Lee una letra mayúscula o minúscula e imprime su pocisión en el abecedario.
Versión: 1.2
Fecha de creacion: 4/feb/2019
*/

#include <stdio.h>
#include <locale.h>

int main(){
	/*Se declara la variable*/
    char letra;
	
	/*ENTRADA. Aquí se solicita la letra para determinar su posición*/
    printf("\nIngresa una letra (mayúscula o minúscula): ");
    scanf("%c", &letra);

	/*PROCESO. Evalúa la posición según la letra*/
    switch(letra){
    case 'A':
    case 'a':
		/*SALIDA. Imprime la posición de la letra*/
        printf("\nLa posición de la letra es 1.");
        break;

    case 'B':
    case 'b':
		/*SALIDA*/
        printf("\nLa posición de la letra es 2.");
        break;

    case 'C':
    case 'c':
		/*SALIDA*/
        printf("\nLa posición de la letra es 3.");
        break;

    case 'D':
    case 'd':
		/*SALIDA*/
        printf("\nLa posición de la letra es 4.");
        break;

    case 'E':
    case 'e':
		/*SALIDA*/
        printf("\nLa posición de la letra es 5.");
        break;

    case 'F':
    case 'f':
		/*SALIDA*/
        printf("\nLa posición de la letra es 6.");
        break;

    case 'G':
    case 'g':
		/*SALIDA*/
        printf("\nLa posición de la letra es 7.");
        break;

    case 'H':
    case 'h':
		/*SALIDA*/
        printf("\nLa posición de la letra es 8.");
        break;

    case 'I':
    case 'i':
		/*SALIDA*/
        printf("\nLa posición de la letra es 9.");
        break;

    case 'J':
    case 'j':
		/*SALIDA*/
        printf("\nLa posición de la letra es 10.");
        break;

    case 'K':
    case 'k':
		/*SALIDA*/
        printf("\nLa posición de la letra es 11.");
        break;

    case 'L':
    case 'l':
		/*SALIDA*/
        printf("\nLa posición de la letra es 12.");
        break;

    case 'M':
    case 'm':
		/*SALIDA*/
        printf("\nLa posición de la letra es 13.");
        break;

    case 'N':
    case 'n':
		/*SALIDA*/
        printf("\nLa posición de la letra es 14.");
        break;

    case 'O':
    case 'o':
		/*SALIDA*/
        printf("\nLa posición de la letra es 15.");
        break;

    case 'P':
    case 'p':
		/*SALIDA*/
        printf("\nLa posición de la letra es 16.");
        break;

    case 'Q':
    case 'q':
		/*SALIDA*/
        printf("\nLa posición de la letra es 17.");
        break;

    case 'R':
    case 'r':
		/*SALIDA*/
        printf("\nLa posición de la letra es 18.");
        break;

    case 'S':
    case 's':
		/*SALIDA*/
        printf("\nLa posición de la letra es 19.");
        break;

    case 'T':
    case 't':
		/*SALIDA*/
        printf("\nLa posición de la letra es 20.");
        break;

    case 'U':
    case 'u':
		/*SALIDA*/
        printf("\nLa posición de la letra es 21.");
        break;

    case 'V':
    case 'v':
		/*SALIDA*/
        printf("\nLa posición de la letra es 22.");
        break;

    case 'W':
    case 'w':
		/*SALIDA*/
        printf("\nLa posición de la letra es 23.");
        break;

    case 'X':
    case 'x':
		/*SALIDA*/
        printf("\nLa posición de la letra es 24.");
        break;

    case 'Y':
    case 'y':
		/*SALIDA*/
        printf("\nLa posición de la letra es 25.");
        break;

    case 'Z':
    case 'z':
		/*SALIDA*/
        printf("\nLa posición de la letra es 26.");
        break;
	
	default:
		/*SALIDA*/
		printf("\nIngrese un caracter válido (letra de A - Z, a excepción de ñ).");
		break;
    }


return 0;
}

/*El programa funciona correctamente. 

Equipo:
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 6/02/2019*/
