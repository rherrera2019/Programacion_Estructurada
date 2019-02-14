/*Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.0
Descripcion del programa: Se leeran las calificaciones del primer parcial de los
estudiantes de algoritmos y que calculara e imprimira el promedio de todo el 
grupo, ademas el usuario escoge la cantidad de alumnos que tiene el grupo.
Fecha de creacion: 8/feb/2019
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	/*VARIABLES*/
	int contEstudiantes = 0;
	int totalEstudiantes;
	float calParcial;
	float SumadorProm = 0.0;
	
	int flag = 0; //Bandera que determina cuando un dato se ingresa correctamente o no
	
	/*ENTRADA*/
	//Aqui se ingresan la cantidad de estudiantes de un grupo a revisar
	printf("Ingrese la cantidad de estudiantes del grupo\n");
	scanf("%d",&totalEstudiantes);
	
	/*PROCESO*/
    /*Aqui se realiza el bucle de asignacion de las calificaciones del parcial de
	cada alumno hasta que ya se hayan ingresado el de todos los alumnos disponibles*/
	do{
		contEstudiantes++;
		flag = 0;
		
		printf("Ingrese la calificación del parcial del alumno %d: ", contEstudiantes);
		while(flag==0){
			scanf("%f", &calParcial);
		    if(calParcial>100.0 || calParcial<0.0){ //En caso de ingresar un valor fuera de rango se le pedira al usuario volver a ingresar la calificacion
				printf("\nCalificación no válida ingrese solo valores del 0 al 100\n");
		    }
		    else{
				flag = 1;
				SumadorProm = SumadorProm + calParcial;
		    }
		}//Termina While de validacion
		
	} while(contEstudiantes<totalEstudiantes); //Termina Do-While de asignacion de los alumnos
	
	/*SALIDA*/
	//Calcula e imprime el promedio del grupo
	printf("El promedio del grupo es: %f", SumadorProm/(float)totalEstudiantes);
	
	return 0;
}

/*Este problema respondió correcto la copilación, además me gustó porque compara si
la calificacion este en el rango entre 0 y 100 y te vuelve a pedir otra calificacion.
tiene todo los datos que se solicitaron.

Equipo: SacaChispas
Revisó: Senaida Norely Chan Chan
Fecha: 13/02/2019*/


