#include<stdio.h>
#include<locale.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Miguel Humberto Gonzalez Herrera & Yao Chung Hu
 * @version: 1.1
 * @fecha: 13feb2020
 * Problema 47
 * Se llevará a cabo en la Universidad el concurso Srita. Simpatía. Existen dos candidatas: Hortencia y Anacreta. E.P. que lea el voto de los 500 alumnos y que determine e imprima el nombre de la ganadora. Considerar la posibilidad de votos nulos y empate en el concurso.
 */
int main(){
    //declaración del verificador, variable, acumulador y del trono//
    int king,cali,key;
    float caligru;
    //iniciación del verificador y trono//
    king=0;
    key=0;
    //procesos//
    setlocale(LC_ALL, "");
    for(int cont1=1; cont1<51; cont1++) {
        //lectura de la calificación//
        printf("Calificación del alumno %d\n",cont1);
        scanf("%d",&cali);
        fflush(stdin);
        //verifica que sea igual/mayor a 0 la calificación//
        do {
            if(cali<0) {
                printf("Calificación erronea\n");
                printf("Calificación del alumno %d\n",cont1);
                scanf("%d",&cali);
            } else {
                printf("Verificado*\n");
                key=1;
            }
        } while(key!=1);
        //acumula la calificación ind//
        caligru+=cali;
        //determina el alumno con mayor calificación//
        if(king<cali) {
            king=cali;
        }
    }
    //promedio de la calificación grupal//
    caligru/=50;
    //determina el caso de que todos tengan la misma calificación//
    if(caligru==king) {
        printf("Todos tienen la misma calificación \n Promedio grupal %.2f\n Calificación mayor %d",caligru,king);
    } else {
        printf("La calificación grupal fue %.2f, y el mayor promedio es %d",caligru,king);
    }
    return 0;
}