#include <stdio.h>
#include <stdlib.h>
/*
descripcion: Una cadena de 5 tiendas determina para cada una, al final del mes los montos de sus ventas y costos.
E.P. que determine e imprima cuántas tiendas obtuvieron una utilidad mayor a los $ 2,000,000.- al final del año.
autor: LUIS MARIO JUAREZ CHIN
version: 1.5
*/
int main()
{
    //ENTRADA
    int util, cstore = 0, cmes = 1, sum = 0, cmayor = 0, costo, venta;
    //PROCESO
    printf("el total de tiendas a evaluar es de 5 \n");
    do {
            printf("tienda #%i", cstore);
            cmes = 1;
            sum = 0;
            do{
                    printf("\nmes #%i", cmes);
                    printf(" ingrese las ventas de la tienda:");
                    scanf("%i", &venta);
                    printf("ingrese los costos:");
                    scanf("%i", &costo);
                    util = venta - costo;
                    sum += util;
                    cmes++;
                    if ( sum > 2000000){
                        cmayor++;
                    }

            }while (cmes < 13);

            cstore++;
    }while (cstore < 5);
    //SALIDA
    printf("el total de las tiendas con una uitlidad mayor a los 2 millones es: %i",cmayor);
    return 0;
}
