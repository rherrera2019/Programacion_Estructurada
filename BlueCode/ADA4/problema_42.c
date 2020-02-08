#include <stdio.h>
#include <stdlib.h>
/*
Nombre del Programa:
Descripción: E.P. que lea las calificaciones del primer parcial de los estudiantes de programación estructurada
y que cuente e imprima cuantos alumnos obtuvieron calificación mayor a 80.
Autor:LUIS MARIO JUAREZ CHIN
Versión: 1.4

*/
int main()
{
    //ENTRADA
   int student, mayor= 0, nstud = 1, a=0;
    float cal;
    //PROCESO
    printf("Bienvenido al sistema de calificaciones SICEI \n"); // MENSAJE DE BURLA
    printf("por favor, ingrese el numero de alumnos que estan inscritos en el curso:");//SE PIDE EL NUMERO DE ALUMNOS
    scanf("%i", &student);
    printf("ingrese la calificacion para cada alumno\n");
    do { //SE UTILIZA LA ESTRUCTURA SELECTIIVA DO-WHILE

            printf("alumno #%i:", nstud); //SE PIDE LA CALIFICACION DE ALUMNOS Y LUEGO SE INGRESA
            scanf("%f", &cal);
            if (cal > 80){ //SE UTILIZA UNA ESTRUCTURA CONDICIONAL
                mayor++;
            }
            nstud++;
            a++;

    } while (a < student);
    //SALIDA
    if (mayor > 0){ //SE IMPRIME UN RESULTADO QUE DEPENDERÁ DE UNA CONDICION
        printf("la cantidad de alumnos que obtuvieron una calificacion mayor a 80 es: %i", mayor);
    }
    else {
        printf("No hubo alumnos que cuenten con una calificacion mayor a 80 :C");
    }

}
