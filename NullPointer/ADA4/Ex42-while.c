#include <stdio.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 09feb2020
 * Problema 42
 */
int main() {
    int contador = 1;
    int sumadorAlumnos = 0;
    int calificacion;
    int totalAlumnos;

    printf("Cantidad de Alumnos:\n");
    scanf("%d", &totalAlumnos);
    while(contador<=totalAlumnos){
        fflush(stdin);
        printf("Calificacion del primer parcial Alumno %d:(0-10)\n", contador);
        scanf("%d", &calificacion);
        if(calificacion<0 || calificacion>100){
            printf("Numero introducido invalido.\n");
            continue;//Saltar lineas de bajo y regresar al inicio del bucle
        }
        if(calificacion>80){
            sumadorAlumnos++;
        }
        contador++;
    }
    printf("%d de alumnos sacaron mayor a 80\n", sumadorAlumnos);
    return 0;
}
