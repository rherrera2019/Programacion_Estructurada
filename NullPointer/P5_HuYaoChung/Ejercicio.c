#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
/*
 * Practica de Laboratorio 5
 * @author: Yao Chung Hu
 * @fecha: 18feb2020
 * @version: 1.0
 *
 * Problema:
 * I. Se cuenta con una lista con los resultados de 100 estudiantes en un concurso internacional de matemáticas. Dicha lista contiene la siguiente información de cada estudiante: nombre, nombre de universidad, país de nacimiento, Cal1, Cal2, Cal3 y Cal4. Como se observa en los datos, para cada estudiante se tiene la calificación que obtuvo en cada uno de los cuatro problemas de que constaba el concurso. También, se conoce que algunos alumnos participantes en la competencia, son de la UADY.

E.P. que determine e imprima lo siguiente:

a) Número de alumnos de la UADY que participaron.

b) Número de participantes que sean mexicanos.

c) Nombre del alumno de la UADY que obtuvo la calificación final más alta (sólo es uno). Dicha calificación final, es la suma de las cuatro calificaciones parciales obtenidas en los problemas.

Implementar al menos dos funciones con paso de parámetros por valor o por referencia, tal como: ingresarDatos;  calcularCalFinal; verificarNacionalidad; verificarUniversidad;  imprimirResultados.
 */

char nombre[20], tronoNombre[20];
char universidad[40];
char pais[20];
float cal1, cal2, cal3, cal4, tronoCalFinal = 0;
int contadorUADY, contadorMexicanos;

void ingresarDatos(int index);
float calcularCalFinal();
void verificarNacionalidad();
void verificarUniversidad();
void calcularCalFinalMasAlta();
void imprimirResultados();

int main() {
    for(int contadorEstudiante = 0; contadorEstudiante < 100; contadorEstudiante++){
        ingresarDatos(contadorEstudiante+1);
        verificarNacionalidad();
        verificarUniversidad();
    }
    imprimirResultados();
    return 0;
}

void ingresarDatos(int index){
    printf("Participante %d, Ingrese su nombre:\n", index);
    scanf("%s", &nombre);
    printf("Participante %d, Ingrese su universidad:\n", index);
    scanf("%s", &universidad);
    printf("Participante %d, Ingrese su pais:\n", index);
    scanf("%s", &pais);
    printf("Participante %d, Ingrese su calificacion 1:\n", index);
    scanf("%f", &cal1);
    printf("Participante %d, Ingrese su calificacion 2:\n", index);
    scanf("%f", &cal2);
    printf("Participante %d, Ingrese su calificacion 3:\n", index);
    scanf("%f", &cal3);
    printf("Participante %d, Ingrese su calificaion 4:\n", index);
    scanf("%f", &cal4);
}

float calcularCalFinal(){
    return cal1+cal2+cal3+cal4;
}

void verificarNacionalidad(){
    if(strcasecmp("Mexico", pais) == 0){
        contadorMexicanos++;
    }
}

void verificarUniversidad(){
    if(strcasecmp("UADY", universidad) == 0){
        calcularCalFinalMasAlta();
        contadorUADY++;
    }
}

void calcularCalFinalMasAlta(){
    if(tronoCalFinal<calcularCalFinal()){
        tronoCalFinal = calcularCalFinal();
        strcpy(tronoNombre, nombre);
    }
}

void imprimirResultados(){
    printf("Número de alumnos de la UADY que participaron es %d\n", contadorUADY);
    printf("Número de participantes que sean mexicanos es %d\n", contadorMexicanos);
    printf("Alumno de la UADY con la calificacion final mas alta es %s con la calificacion final de %f\n", tronoNombre, tronoCalFinal);
}