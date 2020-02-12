#include <stdio.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 09feb2020
 * Problema 39
 */
int main() {
    int contadorTiendas = 1;
    float utilidad;
    int cantidadTiendasMayorUtilidad = 0;
    while(contadorTiendas<=5){
        printf("Introduzca la utilidad de la tienda %d : \n", contadorTiendas);
        scanf("%f", &utilidad);
        if(utilidad>2000000){
            cantidadTiendasMayorUtilidad++;
        }
        contadorTiendas++;
    }
    printf("%d tiendas tuvieron utilidad mayor que $2000000\n", cantidadTiendasMayorUtilidad);
    return 0;
}
