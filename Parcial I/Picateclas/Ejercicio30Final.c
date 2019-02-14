/*Programa: CaraDelDado.c

Autor: EQUIPO PICATECLAS
López Madera Fernanda Jacqueline
González Bautista Noé Alejandro
Durán Matos Juan José

Descripción: Lee un número entero correspondiente a una de las caras de un dado e imprime con letras el número de la cara opuesta.
Versión: 1.0
Fecha de creacion: 4/feb/2019
*/
#include <stdio.h>
#include <conio.h>

int main (void){

/*Se define la variable a utilizar*/
int cara;

/*ENTRADA. Se solicita el número de la cara*/
printf("Inserta el número de la cara que salió: ");
scanf("%i", &cara);

/*PROCESO. Se evalúa a cual cara corresponde*/
    switch (cara){

        case 1:
            /*SALIDA. Se imprime la cara correspondiente*/
            printf("La cara opuesta es seis.");
            break;

        case 2:
            /*SALIDA*/
            printf("La cara opuesta es cinco.");
            break;

        case 3:
            /*SALIDA*/
            printf("La cara opuesta es cuatro.");
            break;

        case 4:
            /*SALIDA*/
            printf("La cara opuesta es tres.");
            break;

        case 5:
            /*SALIDA*/
            printf("La cara opuesta es dos.");
            break;

        case 6:
            /*SALIDA*/
            printf("La cara opuesta es uno.");
            break;

        default:
            /*SALIDA*/
            printf("Un dado no tiene ese número.");
            break;
}


return 0;
getch();
}

/*El programa funciona correctamente. 

Equipo:
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 6/02/2019*/
