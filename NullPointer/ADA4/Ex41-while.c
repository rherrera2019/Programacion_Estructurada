#include <stdio.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 09feb2020
 * Problema 41
 */
int main() {
    int contador = 1;
    int sumadorCalificaciones = 0;
    int calificacion;
    int totalAlumnos;
    float promedioGrupal;

    printf("Cantidad de Alumnos:\n");
    scanf("%d", &totalAlumnos);
    while(contador<=totalAlumnos){
        fflush(stdin);
        printf("Calificacion del primer parcial Alumno %d:(0-10)\n", contador);
        scanf("%d", &calificacion);
        if(calificacion<0 || calificacion>10){
            printf("Numero introducido invalido.\n");
            continue;//Saltar lineas de bajo y regresar al inicio del bucle
        }
        sumadorCalificaciones+=calificacion;
        contador++;
    }
    promedioGrupal = sumadorCalificaciones/totalAlumnos;
    printf("El promedio grupal es de %f\n", promedioGrupal);
    return 0;
}
