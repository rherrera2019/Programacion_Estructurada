#include <stdio.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 09feb2020
 * Problema 43
 */
int main() {
    int contador = 1;
    int num;
    int positivos = 0, negativos = 0;
    while(contador<=250){
        fflush(stdin);
        printf("Introduzca un numero entero:\n");
        scanf("%d", &num);
        if(num>0){
            positivos++;
        }else if(num<0){
            negativos++;
        }
        contador++;
    }
    printf("Cantidad de numeros postivos: %d\n", positivos);
    printf("Cantidad de numeros negativos: %d\n", negativos);
    return 0;
}
