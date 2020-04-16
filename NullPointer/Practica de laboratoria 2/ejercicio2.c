/*
 * Practica de laboratoria 2
 *
 * problema:
 * En un supermercado, se realizan descuentos por la compras a partir de unas bolitas de colores: verde 20%, amarilla 25%, negra 30%; la blanca no aplica ningún descuento. E.P. que lea el importe de la compra y el color de la bolita, determine e imprima cuanto debe pagar un cliente.
 * equipo: NullPointer
 * author: Miguel Humberto Gonzalez Herrera
 * version: 1.0
 * fecha: 29ene2020
 */

#include<stdio.h>
#include<string.h>
int main()
{
    char bol[8];
    int bolV,bolA,bolN,bolB;
    float comp;
    printf("¿Cual fue tu monto de compra?\n");
    scanf("%f",&comp);

    printf("¿Que bola tiene?\nverde \namarillo \nnegro \nblanco \nescribirlo en MINUSCULAS\n");
    scanf("%s",&bol);
    bolV=strcmp(bol,"verde");
    bolA=strcmp(bol,"amarillo");
    bolN=strcmp(bol,"negro");
    bolB=strcmp(bol,"blanco");

    switch(bolV){
        case 0:
            comp*=.8;
            printf("Su monto de compra,incluyendo el descuento, es de: $%.2f",comp);
            break;
        default:
            break;
    }

    switch(bolA){
        case 0:
            comp*=.75;
            printf("Su monto de compra,incluyendo el descuento, es de: $%.2f",comp);
            break;
        default:
            break;
    }

    switch(bolN){
        case 0:
            comp*=.7;
            printf("Su monto de compra,incluyendo el descuento, es de: $%.2f",comp);
            break;
        default:
            break;
    }

    switch(bolB){
        case 0:
            printf("Su monto de compra (BLANCA no da descuento) es de: $%.2f",comp);
            break;
        default:
            break;
    }

    return 0;
}