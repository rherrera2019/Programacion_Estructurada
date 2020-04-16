#include<stdio.h>
#include<locale.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 13feb2020
 * Problema 49
 * Un restaurante ofrece hamburguesas sencillas, dobles y triples, las
    cuales tienen un costo de $60.00, $80.00 y $100.00, respectivamente.
    La empresa acepta tarjetas de crédito con un cargo adicional de 3%
    sobre la compra. Los clientes pueden hacer su pedido con cualquier
    cantidad de hamburguesas de los tipos que deseen comer. E.P. para
    determinar cuánto debe pagar cada uno de los N clientes que llegan al
    establecimiento. También, al final del día, se requiere imprimir el
    monto total de las ventas y el total de las comisiones por tarjeta de
    crédito.
 */
int main(){
    int numeroClientes;
    float ventaFinal = 0, comisionFinal = 0;
    setlocale(LC_ALL, ""); // Multi locales
    printf("Introduzca la cantidad de clientes:\n");
    scanf("%d",&numeroClientes);
    for(int contadorClientes = 0; contadorClientes<numeroClientes; contadorClientes++){
        int tipoDePago, sencillas, dobles, triples;
        printf("\n\n\n\nCliente #%d\n", contadorClientes+1);
        printf("Hamburguesa Sencilla: $60.00, Hamburguesa Dobles: $80.00 y Hamburguesa Triples: $100.00\n");
        printf("Introduzca la cantidad de hamburguesas sencillas:\n");
        scanf("%d",&sencillas);
        printf("Introduzca la cantidad de hamburguesas dobles:\n");
        scanf("%d",&dobles);
        printf("Introduzca la cantidad de hamburguesas triples:\n");
        scanf("%d",&triples);
        printf("Introduzca el tipo de pago:(1. Efectivo, 2. Tarjeta de Credito)\n");
        scanf("%d",&tipoDePago);
        if(tipoDePago==1){
            printf("Pago por Efectivo. El monto total es de $.2f\n", sencillas*60.0+dobles*80.0+triples*100.0);
            ventaFinal+=sencillas*60.0+dobles*80.0+triples*100.0;
        }else if(tipoDePago==2){
            printf("Pago por Tarjeta de Credito. Subtotal de $%.2f. Comision de 3%% que es $.2f. El monto total es de $.2f\n",sencillas*60.0+dobles*80.0+triples*100.0, (sencillas*60.0+dobles*80.0+triples*100.0)*0.03, (sencillas*60.0+dobles*80.0+triples*100.0)*1.03);
            ventaFinal+=sencillas*60.0+dobles*80.0+triples*100.0;
            comisionFinal+=(ventaFinal+=sencillas*60.0+dobles*80.0+triples*100.0)*0.03;
        }
    }
    printf("\nTotal de Ventas: $%.2f\n", ventaFinal);
    printf("Total de Comisiones por Tarjeta de Credito: $%.2f\n", comisionFinal);
    return 0;
}
