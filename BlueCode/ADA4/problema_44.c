#include <stdio.h>
#include <stdlib.h>
/*
Nombre del Programa:
Descripción: Los estudiantes de Ingeniería presentaron un examen de admisión con 100 preguntas.  E.P. que lea el nombre y el número de respuestas correctas
para cada una de las 50 personas que presentaron y que determine e imprima para cada uno su nombre y su calificación
Autor:LUIS MARIO JUAREZ CHIN
Versión: 2.3

*/
int main()
{
    //ENTRADA
    int cal, cAnswer, a = 0;
    char name[51];
    //PROCESO
    printf("Bienvenido de nuevo al sistema de calificacion SICEI; la plataforma mas confiable y sin errores creado por ingenieros de la privilegiada universidad de Harvard"); //OTRO MENSAJE DE BURLA
    do { //SE UTILIZA LA ESTRUCTURA REPETITIVA DO-WHILE
            printf("\n\nIngrese el nombre del alumno:"); //SE PIDE EL NOMBRE DEL ALUMNO
            scanf("%s", &name);
            printf("Respuestas correctas:"); //SE INGRESAN LAS RESPUESTAS CORRECTAS
            scanf("%i", &cAnswer);
            if (cAnswer > 90){ //SE EVALUAN 7 CONDICIONES SEGUN SEA EL NUMERO DE RESPUESTAS CORRECTAS Y LUEGO SE IMPRIMEN
                printf("La calificacion de %s es de 100",name);
            }
            else if (cAnswer <=90 && cAnswer > 75) {
                printf("la calificacion de %s es de 90",name);
            }
            else if (cAnswer <=75 && cAnswer > 65){
                printf("La calificacion de %s es de 80",name);
            }
            else if (cAnswer <=65 && cAnswer > 60){
                printf("La calificacion de %s es de 70",name);
            }
            else if (cAnswer <= 60 && cAnswer > 50){
                printf("La calificacion de %s es de 60",name);
            }
            else if (cAnswer <= 50 && cAnswer > 30){
                printf("La calificacion de %s es de 50",name);
            }
            else{
                printf("la calificacion de %s esta por debajo de 30, que pena por el",name);
            }
            a++;

    }while (a < 50);
    //SALIDA
    return 0;
}
