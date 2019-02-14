/*
44.- Los estudiantes de Ingeniería presentaron un examen de admisión
con 100 preguntas. E.P. que lea el nombre y el número de respuestas 
correctas para cada una de las 50 personas que presentaron y que 
determine e imprima para cada uno su nombre y su calificación basados 
en la siguiente tabla:
Respuestas Correctas Calificación Obtenida
30 > R <= 50                  50
50 > R <= 60                  60
60 > R <= 65                  70
65 > R <= 75                  80
75 > R <= 90                  90
R > 90                        100

Elaboró:Los Compiladores
Fecha:11/02/2019
version 1.0
*/

#include <stdio.h>
#include <conio.h>

int main() {
	//Variables
	char nombre[40];
	float resp,CG;
	float r1,valor;
	r1=0;
	
	
	CG=1;
	
	while(CG<=50){
		
		//Entrada
		printf("\n\n Nombre: ");
		gets(nombre);
		printf("Respuestas correctas: ");
		scanf("%f",&resp);
		
		//determinamos si el valor ingresado es un entero
		r1=(int)resp;
		valor=resp-r1;//si el resultado de valor es >0,sabremos que no corresponde a un entero el valor ingresado
		
		
		
		
		/*se valida el valor ingresado para las respuestas,verificando que no corresponda a 
		un valor <0 ó >100, o que el valor no sea de tipo entero*/
		while(resp<0 || resp>100){
			
			printf("***\n El valor ingresado no es correcto*** ");
			printf("\n Ingrese valores de 0 a 100");
			printf("\n Ingrese nuevamente: ");
			scanf("%f",&resp);
			valor=0;
			r1=(int)resp;
			valor=resp-r1;
		}
		
		while(valor>0){
			printf("\n Ingrese solo valores enteros: ");
			getchar();
			scanf("%f",&resp);
			valor=0;
			r1=(int)resp;
			valor=resp-r1;
		}
		while(resp<0 || resp>100){
			
			printf("***\n El valor ingresado no es correcto*** ");
			printf("\n Ingrese valores de 0 a 100");
			printf("\n Ingrese nuevamente: ");
			scanf("%f",&resp);
			valor=0;
			r1=(int)resp;
			valor=resp-r1;
		}
		while(valor>0){
			printf("\n Ingrese solo valores enteros: ");
			getchar();
			scanf("%f",&resp);
			valor=0;
			r1=(int)resp;
			valor=resp-r1;
		}
	
		getchar();
		
		printf("\n ////RESULTADOS////");
		printf("\n");
		
		//Proceso/Salida
		if(resp>90){
			printf("\n Aspirante: %s",nombre);
			printf("\n Calificaci%cn: 100",162);
		}else if(resp>75){
			printf("\n Aspirante: %s",nombre);
			printf("\n Calificaci%cn: 90",162);
		}else if(resp>65){
			printf("\n Aspirante: %s",nombre);
			printf("\n Calificaci%cn: 80",162);
		}else if(resp>60){
			printf("\n Aspirante: %s",nombre);
			printf("\n Calificaci%cn: 70",162);
		}else if(resp>50){
			printf("\n Aspirante: %s",nombre);
			printf("\n Calificaci%cn: 60",162);
		}else if(resp>30){
			printf("\n Aspirante: %s",nombre);
			printf("\n Calificaci%cn: 50",162);
		}
		CG++;
	}
	
	return 0;
}

