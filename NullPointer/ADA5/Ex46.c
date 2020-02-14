#include<stdio.h>
#include<locale.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Miguel Humberto Gonzalez Herrera & Yao Chung Hu
 * @version: 1.1
 * @fecha: 13feb2020
 * Problema 46
 * E.P. que lea 200 números y que calcule e imprima cuantos son negativos, cuantos son positivos y cuantos fueron iguales a cero.
 */
int main(){
    float numero;
    int positivos = 0, negativos = 0,zero = 0;
    setlocale(LC_ALL, "");
    for(int contador = 1; contador<3; contador++) {
        printf("(%d)Introduce un numero\n", contador);
        scanf("%f",&numero);
        if(numero < 0) {
            negativos++;
        }else if(numero > 0){
            positivos++;
        }else{
            zero++;
        }
    }
    printf("Hubieron:\n %d negativos\n %d igual a 0\n %d positivos", negativos, zero, positivos);
    fflush(stdin);
    return 0;
}