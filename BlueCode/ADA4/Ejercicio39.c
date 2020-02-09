#include <stdio.h>
#include <stdlib.h>
/*
descripcion: E.P. que lea las utilidades mensuales de una cadena de 5 tiendas y que determine e imprima
cuantas tiendas tuvieron utilidades mayor a los $ 2,000,000.-.
autor; Luis Mario Juarez Chin
version: 1.0
*/
int main()
{
    //ENTRADA
    int cstore= 1, sum = 0, venta, costo, util, cmayor = 0;
    //PROCESO
    printf("se evaluara la utilidad de 5 tiendas\n");
     do{
                    printf("\nnumero de tienda #%i:", cstore);
                    printf("\ningrese las ventas de la tienda:");
                    scanf("%i", &venta);
                    printf("ingrese los costos:");
                    scanf("%i", &costo);
                    util = venta - costo;
                    sum += util;
                    cstore++;
                    if ( sum > 2000000){
                        cmayor++;
                    }

            }while (cstore < 6);
            //SALIDA
        printf("el numero de tiendas con utilidades que son mayores a 2 millones es: %i", cmayor);
    return 0;
}
