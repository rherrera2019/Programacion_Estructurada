#include<stdio.h>

int main()
{
/*declaración de las variables utilidades y conatos, de los contadores
contadores cont1,cont2,conttie y de un acumulador acumuti*/
    int conttie,cont1,cont2,utilidades,costos,acumuti;
   //iniciación del cont1 que regula el numero de la tienda//
     cont1=1;
//procesos//
//condicion de la condicion del while-do//
    while(cont1<6) {
        printf("Tienda %d\n",cont1);
        //iniciación y reinicio del cont2, regula los meses,y el acumulador//
        cont2=1;
        acumuti=0;
        while(cont2<13) {
        //petición y lectura de las variables utilidades y costos//
            printf("Utilidades del mes %d\n",cont2);
            scanf("%d",&utilidades);
            fflush(stdin);
            printf("Costos del mes %d\n",cont2);
            scanf("%d",&costos);
            fflush(stdin);
            //acumulado de los ingresos de las tiendas//
            acumuti+=utilidades-costos;
            //suma de +1 al contador de meses//
            cont2++;
        }
        /*después de salir del bucle de meses, si cumple la condicion
        se suma +1 al contador de la cantidad de tiendas mayores a 2M*/
        if(acumuti>2000000) {
            conttie++;
        }
//suma de +1 al contador de tiendas//
        cont1++;
    }
//impresión de la cantidad de tiendas mayores a 2M//
    printf("Hay %d con utlidades mayores a $2,000,000",conttie);
    return 0;
}