#include <stdio.h>
#include <stdlib.h>
/*
Nombre del Programa:
Descripción: E.P. que lea 250 números y que determine e imprima cuantos son positivos y cuantos son negativos
Autor:LUIS MARIO JUAREZ CHIN
Versión: 1.9

*/
int main()
{
    //ENTRADA
    int nposit = 0, negativ = 0, neutral = 0, number, a = 0;
    //PROCESO
    do{ // SE UTILIZA LA ESTRUCTUA REOPETITIVA DO-WHILE
      printf("ingresa un numero:");
      scanf("%i", &number);
      if (number > 0 ){ //SE UTILIZA LA ESTRUCTURA SELECTIVA IF-ELSE
        nposit++;
      }
      else if (number < 0){
        negativ++;
      }
      else { // SON TRES CONDICIONES ESTABLECIDAS
        neutral++;
      }
      a++;
    } while (a < 250);
    //SALIDA
    if (nposit > 0){ //A PARTIR DE LAS CONDICIONES, SE ESPERAN DOS POSIBLES RESPUESTAS PARA CADA TIPO DE NUMERO
        printf("\nla cantidad de numeros positivos es de: %i", nposit);
    }
    else {
        printf("\nno hay numeros psitivos :C");
    }
    if (negativ > 0){
        printf("\nla cantidad de numeros negativos es de: %i", negativ);
    }
    else {
        printf("\n no existen numeros negativos, Acaso sera algo bueno?");
    }
    if (neutral > 0){
        printf("\nla cantidad de numeros iguales a cero es de: %i", neutral);
    }
    else {
        printf("\nNo existen numeros neutros... debemos suponer que es un dato bueno...");
    }
    return 0;
}
