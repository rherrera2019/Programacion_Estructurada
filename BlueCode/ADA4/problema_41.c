#include <stdio.h>
#include <stdlib.h>
/*
Nombre del Programa:
Descripción:  E.P. que lea las calificaciones del primer parcial de los estudiantes de programación estructurada
y que calcule e imprima el promedio de todo el grupo
Autor:LUIS MARIO JUAREZ CHIN
Versión: 1.7

*/
int main()
{
    //ENTRADA
    int student, nstud = 1, a=0;
    float cal,promed, sum = 0;
    //PROCESO
    printf("Bienvenido al sistema de calificaciones SICEI \n");
    printf("por favor, ingrese el numero de alumnos que estan inscritos en el curso:");
    scanf("%i", &student);
    printf("ingrese la calificacion para cada alumno\n");
    do { //SE USA LA ESTRUCTURA REPETITIVA DO-WHILE
            printf("alumno #%i:", nstud); //EL # DE ALUMNOS IRÁ INCREMENTANDO
            scanf("%f", &cal);
            sum += cal;
            nstud++; //FUNCION QUE INCREMENTA EL NUMERO DE ALUMNOS
            a++;

    } while (a < student); //LA ITERACION SE REALIZA MIENTRAS EL VALOR DE LA VARIABLE "A" SEA MENOR AL VALOR DE LA VARIABLE "STUDENT"
    //SALIDA
    promed = sum/student;
    printf("El promedio total del grupo es: %.2f", promed); // SE IMPRIME EL RESULTADO
    return 0;
}
