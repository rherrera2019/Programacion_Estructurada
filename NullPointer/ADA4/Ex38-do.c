#include <stdio.h>
#include <locale.h>
#include <windows.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 09feb2020
 * Problema 38
 */
int main() {

    int contador = 0;
    char nombre[20];
    float sueldo = 0;
    int numeroDeHijos = 0;

    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    printf("La tlapalería “El Sapo Verde”!\n");
    do{
        fflush(stdin);
        printf("Nombre:\n");
        scanf(" %s", &nombre);
        printf("Sueldo:\n");
        scanf(" %f", &sueldo);
        printf("Numero de hijos:\n");
        scanf(" %d", &numeroDeHijos);
        if(sueldo>1000 && numeroDeHijos >= 3 && numeroDeHijos <= 7){
            printf("Nombre: %s Sueldo: %f Numero De Hijos: %d\n", nombre, sueldo, numeroDeHijos);
        }
        fflush(stdin);
        contador++;
    }while(contador<=20);
    return 0;
}
