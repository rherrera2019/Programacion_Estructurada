#include<stdio.h>

int main()
{
//declaración de la variable num y los contadores cont1 y contneg//
    int num,cont1,contneg;
    //iniciación de los contadores//
    contneg=0;
    cont1=0;
    //procesos//
    do
    {
    //petición y lectura de la variable//
    printf("Introduce un numero\n");
    scanf("%d",&num);
    fflush(stdin);
    //si el numero es menor a 0, el contador de negativos suma +1//
    if(num<0){
    contneg++;
    }
    //suma de +1 al contador//
    cont1++;
    //condicion del do-while//
    } while(cont1<50);
    //impresión de la cantidad de números negativos//
    printf("Introdujo %d numero(s) negativo(s)",contneg);
    return 0;
}