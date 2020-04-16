#include<stdio.h>

int main()
{
//declaración de la variable num y contadores cont1 y contpos//
    int num,cont1,contpos;
    //iniciación de los contadores//
    contpos=0;
    cont1=0;
    //procesos//
    do
    {
    //petición y lectura de la variable//
    printf("Introduce un numero\n");
    scanf("%d",&num);
    fflush(stdin);
    //si el numero es mayor a 0 se le suma +1 al contpos//
    if(num>0){
    contpos++;
    }
    //suma de +1 al contador//
    cont1++;
    //condicion del do-while//
    } while(cont1<100);
    //impresión de la cantidad de números positivos//
    printf("Introdujo %d numero(s) negativo(s)",contpos);
    return 0;
}