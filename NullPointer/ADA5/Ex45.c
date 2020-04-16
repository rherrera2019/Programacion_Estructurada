#include<stdio.h>
#include<locale.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Miguel Humberto Gonzalez Herrera & Yao Chung Hu
 * @version: 1.1
 * @fecha: 13feb2020
 * Problema 45
 * Una Compañía efectúa cálculos para su reporte anual de utilidades
    y añadirá un pequeño incentivo de antigüedad para sus empleados
    que consiste en un porcentaje de su sueldo, de acuerdo a la siguiente
    tabla:

    Antiguedad      Porcentaje
    De 1 a 3 años   1 %
    De 4 a 6 años   3 %
    De 7 a 9 años   5 %
    De 10 a 15 años 7 %

    E.P. que lea el nombre, la antigüedad y sueldo de cada uno de los 100
    empleados y que calcule e imprima la cantidad que le corresponde a
    cada uno. Además, determinar e imprimir el monto total de dicha
    antigüedad para la empresa.
 */
int main()
{
    //declaración de variables,verificador, contador//
    char nombre[20];
    int antiguedad,key;
    float salario,salarioAux;
    //inicia del veeificador//
    key=0;
    //procedos//
    setlocale(LC_ALL, "");
    for(int i=1; i<101; i++){
        //lectura del nombre, salario y antigüedad//
        printf("Trabajador %d\n",i);
        printf("Introduce tu NOMBRE: ");
        scanf(" %s", nombre);
        printf("Tu antigüedad en la empresa\n");
        scanf("%d",&antiguedad);
        printf("Introduce tu salario\n");
        scanf("%f",&salario);
        salarioAux=salario;
        do{
            if(salario > 0 && antiguedad > 0){
                printf("Verificado*\n");
                key=1;
            }else{
                printf("Algun dato es incorrecta, vuelve a intentar\n");
                printf("Trabajador %d\n",i);
                printf("Tu antigüedad en la empresa\n");
                scanf("%d",&antiguedad);
                printf("Introduce tu salario\n");
                scanf("%f",&salario);
                salarioAux=salario;
            }
        }while(key!=1);
        if(antiguedad <= 3){
            salario*=1.01;
        }else if(antiguedad <= 6){
            salario*=1.03;
        }else if(antiguedad <= 9){
            salario*=1.05;
        } else if(antiguedad <= 15){
            salario*=1.07;
        } else{
            printf("Tu antigüedad no esta considerada\n");
        }
        printf("%s por %d años de antiguedad, con salario %.2f, te corresponde %f\n", nombre, antiguedad, salarioAux, salario);
        fflush(stdin);
    }
    return 0;
}