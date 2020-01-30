/*
 * Practica de laboratoria 2
 *
 * problema:
 * Un beisbolista tiene cuatro oportunidades de batear en un juego. Por cada turno al bate, se registra si el batazo del jugador es "hit", "out" o "base por bola". Se quiere saber, en un juego, cuántas veces el jugador batea un "hit", cuántas veces es "out" y cuántas veces recibe "base por bola". Además, se desea calcular el porcentaje de bateo por juego del jugador, lo cual se calcula dividiendo el número de veces que batea un hit, entre las oportunidades de bateo que no son "base por bola". E.P. que calcule e imprima lo siguiente:
    a) Cuántas veces se batea un hit, cuántas veces un out y cuántas veces base por bola,
    b) Cuál es el porcentaje de bateo del juego para el jugador.
 * equipo: NullPointer
 * author: Yao Chung Hu
 * version: 1.0
 * fecha: 28ene2020
 */

#include <stdio.h> // Standard I/O

int hit, out, bola; //Variables enteros para guardar las cantidad de veces que sucedio cada accion
/* Funcion para leer que tipo de accion se realizo y se suma a los variables para dicho seleccion, por si acaso el
 * usuario introduzca otro numero que no esta en las correspondientes entra la recursividad para que seleccionen de
 * nuevo.
 */
void leerTipo(void){
    int seleccion;
    printf("Introduzca 1 para un 'hit', 2 para un 'out' o 3 para un 'base por bola'\n");
    scanf("%d", &seleccion);
    if(seleccion==1){
        hit++;
    }else if(seleccion==2){
        out++;
    }else if(seleccion==3){
        bola++;
    }else{
        printf("Seleccion invalid intenta de nuevo\n");
        leerTipo();
    }
}
/*
 * Imprimir los resultados finales de las cantidad de acciones y que porcentaje de xxxx xd
 */
void imprimirResultados(void){
    printf("Hits: %d\n", hit);
    printf("Outs: %d\n", out);
    printf("Base por bola: %d\n", bola);
    printf("Porcentaje de bateo: %f%", (float)hit/(out+hit));
}

int main() {
    leerTipo();// Leer la primera accion
    leerTipo();// Leer la segunda accion
    leerTipo();// Leer la tercera accion
    leerTipo();// Leer la cuarta accion
    imprimirResultados();// Calcula e imprime los resultados
    return 0;
}

