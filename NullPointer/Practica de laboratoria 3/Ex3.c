#include<stdio.h>
//Declaramos variables globales//
int ct1,ct2,numtra,acumtra,salind,acumsal;
float promsal;
int main()
{
//iniciamos el contador de empresas//
    ct1=1;
    //primer while: controla el numero de empresas//
    while(ct1<11)
    {
    //lee el numero de empleados, acumula estos ultimos, y reinicia el contador del segundo while//
    printf("Introduce el numero de empleados en la empresa %d\n",ct1);
    scanf("%d",&numtra);
    acumtra+=numtra;
    ct2=0;
    //dependiendo del resultado numtra, sera el num. limite para el contador//
    while(ct2<numtra)
    {
    //lee el salario, y lo almacena en acumsal//
    printf("Introduce tu salario\n");
    scanf("%d",&salind);
    acumsal+=salind;
    ct2++;
    }
    
    ct1++;
    }
    //el float convierte los valores de adentro en floats//
    promsal=(float)acumsal/acumtra;
    printf("El promedio salarial es $%.2f pesos",promsal);
    return 0;
}