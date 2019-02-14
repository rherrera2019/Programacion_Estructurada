/*Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.1
Descripcion del programa: Los estudiantes de Ingeniería presentaron un examen de
admisión con 100 preguntas. Se leeran el nombre y el número de respuestas 
correctas para cada una de las 50 personas que presentaron y que determine e 
imprima para cada uno su nombre y su calificación:
Fecha de creacion: 8/feb/2019
*/

#include<stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void){
	/*VARIABLES*/
	char NombrePer[30];
	int preCorrect;
	
	int contPersonas = 0;
	
	
	while(contPersonas<50){		
		/*VARIABLES LOCALES*/
		int flag = 0; //Bandera de validacion
		
		contPersonas++;
		/*ENTRADA*/
		printf("Ingrese el nombre de la persona\n");
		scanf("%s",NombrePer);		
		
		printf("Ingrese el número de preguntas correctas que contestó el usuario (0-100)\n");
		while(flag==0){
		scanf("%d", &preCorrect);
		if(preCorrect>=0 && preCorrect<=100){
			flag = 1;
		}
		else{
			printf("Dato incorrecto, ingrese uno valido\n");
		} 
		} //Termina while de validacion

		/*PROCESO*/
		//Aqui se determina e imprime la calificacion de la persona actual
		printf("\n\t\t\tRESULTADOS\n");
		printf("*************************************************************");
		printf("\nNombre del usuario: %s", NombrePer);
		printf("\nNúmero de preguntas acertadas: %d", preCorrect);
		if(preCorrect<=30){
			printf("\nCalificación obtenida: 0\n");
		}
		else if(preCorrect>30 && preCorrect<=50){
			printf("\nCalificación obtenida: 50\n");
		}
		else if(preCorrect>50 && preCorrect<=60){
			printf("\nCalificación obtenida: 60\n");
		}
		else if(preCorrect>60 && preCorrect<=65){
			printf("\nCalificación obtenida: 70\n");
		}
		else if(preCorrect>65 && preCorrect<=75){
			printf("\nCalificación obtenida: 80\n");
		}
		else if(preCorrect>75 && preCorrect<=90){
			printf("\nCalificación obtenida: 90\n");
		}
		else{
			printf("\nCalificación obtenida: 100\n");
		}
		printf("*************************************************************");
		
		printf("\nPulse otra tecla para continuar la revision");
		getch();
		
		system("cls"); //Cuando la revision de este usuario haya terminado se limpiara la consola para pasar al siguiente
		
	}//Termina ciclo while del contador de personas
	
	system("cls");
	/*SALIDA*/
	printf("La revision ha finalizado");
}

/*El programa funciona correctamente, cumple con los datos solicitados.
El problema pedía el total de aciertos de cada persona, la forma resuelta anteriormente está bien 
aunque se tarda más

Equipo: SacaChispas
Revisó: Senaida Norely Chan Chan
Fecha: 13/02/2019*/
