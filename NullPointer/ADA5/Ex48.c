#include<stdio.h>
#include<locale.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Miguel Humberto Gonzalez Herrera & Yao Chung Hu
 * @version: 1.1
 * @fecha: 13feb2020
 * Problema 48
 * Se llevará a cabo en la Universidad el concurso Srita. Simpatía. Existen dos candidatas: Hortencia y Anacreta. E.P. que lea el voto de los 500 alumnos y que determine e imprima el nombre de la ganadora. Considerar la posibilidad de votos nulos y empate en el concurso.
 */
int main()
{
    //declara contadores, y variable//
    int votoHortencia = 0, votoAnacreta = 0, nulo = 0, voto;
    //procesos//
    setlocale(LC_ALL, "");
    for(int cont1=1; cont1<501; cont1++) {
        //lectura de la variable//
        printf("Alumno %d\n",cont1);
        printf("Escribe:\n 1 para votar por Hortencia\n 2 para votar por Anacleta\n");
        scanf("%d",&voto);
        //determina el voto entre anacleta, hortencia o nulo//
        if(voto==1) {
            votoHortencia++;
        } else if(voto==2) {
            votoAnacreta++;
        } else {
            nulo++;
        }
    }
    //valida cualquier de los 3 casos posibles//
    if(votoHortencia > votoAnacreta) {
        printf("Gano Hortencia con %d\n %d votos nulos", votoHortencia, nulo);
    } else if(votoAnacreta > votoHortencia) {
        printf("Gano Anacleta con %d\n %d votos nulos", votoAnacreta, nulo);
    } else {
        printf("No hay ganadoras\n %d nulos", nulo);
    }
    return 0;
}