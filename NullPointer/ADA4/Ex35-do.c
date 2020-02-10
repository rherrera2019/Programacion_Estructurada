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
    //petición y lectura de la variable//
    printf("Introduce un numero\n");
    scanf("%d",&num);
    fflush(stdin);
    //si es igual a 0, entonces imprime, de lo contrario imprime otro cosa//
    if(num==0){
    printf("El numero que puso es %d, es igual a 0\n\n",num);
    } else{
   printf("El numero que puso es %d, no es igual a 0\n\n",num);
}
    //suma de +1 al contador//
    cont1++;
    //condicion del do-while//
    } while(cont1<25);
    return 0;
}