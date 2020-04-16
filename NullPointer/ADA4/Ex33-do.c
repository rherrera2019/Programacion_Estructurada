#include<stdio.h>

int main()
{
//declaración de variable num, y contador cont1//
    int num,cont1;
    //iniciación del contador//
    cont1=0;
    //proceso//
    do
    {
    printf("Introduce un numero\n");
    scanf("%d",&num);
    fflush(stdin);
    //Si cumple la condicion, imprime el valor//
    if(num>100){
    printf("%d es mayor a 100\n\n",num);
    }
    //suma de +1 al contador//
    cont1++;
    //condición del do-while//
    } while(cont1<10);
    return 0;
}