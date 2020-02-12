#include <stdio.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 09feb2020
 * Problema 44
 */
int main() {
    int contador = 1;
    int respuestas;
    while(contador<=50){
        fflush(stdin);
        printf("Introduzca el numero de respuestas correctas para el alumno %d:\n", contador);
        scanf("%d", &respuestas);
        if(respuestas>100 || respuestas<0){
            printf("Respuesta introducido invalido.\n");
            continue;//Saltar lineas de bajo y regresar al inicio del bucle
        }
        int calificacion = 0;
        if(respuestas > 30 && respuestas <= 50){
            calificacion = 50;
        }else if(respuestas > 50 && respuestas <= 60){
            calificacion = 60;
        }else if(respuestas > 60 && respuestas <= 65){
            calificacion = 70;
        }else if(respuestas > 65 && respuestas <= 75){
            calificacion = 80;
        }else if(respuestas > 75 && respuestas <= 90){
            calificacion = 90;
        }else if(respuestas > 90){
            calificacion = 100;
        }
        printf("Tu calificacion final es %d\n", calificacion);
        contador++;
    }
    return 0;
}
