#include<stdio.h>

int main()
{
//declaración de la variable num y contador cont1//
    int num,cont1;
    //iniciación del contador//
    cont1=0;
    //procesos//
    do
    {
    //solicitud del numero y lectura//
    printf("Introduce un numero\n");
    scanf("%d",&num);
    fflush(stdin);
    //impresión del numero leído//
    printf("El numero que puso es %d\n\n",num);
    //suma de +1 al contador//
    cont1++;
    //condicion del do-while//
    } while(cont1<100);
    return 0;
}