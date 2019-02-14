#include <stdio.h>
/*Nombre Equipo: Picateclas
Autores: 
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.1
Descripcion del programa: Determine e imprima la calificación final de un alumno 
del curso “Programación Estructurada”. El desglose de dicha evaluación
está en escala 100 y tiene los siguientes porcentajes: 40%, dos
exámenes parciales, 30%, tareas y trabajos,20%, proyecto final y 10%,
participación en clase.
Fecha de creacion: 1/feb/2019
*/
int main(int argc, char *argv[]) {
	float Parcial1;
	float Parcial2;
	float ADAS;
	float ProyectoFinal;
	float Participacion;
	float CalFinal;
	
	int Dato; //Bandera que indica si se introdujo un dato correcto en el intervalo base 100
	
	printf("Programacion Estructurada\n");
	//Aqui se iran ingresando los datos obtenidos en los examenes, ADAS, proyecto y participacion
	printf("Ingrese la calificacion que obtuvo en su 1er Examen Parcial (base 100)\n");
	Dato = 0;
	while(Dato==0){
	scanf("%f",&Parcial1);
	//En caso de que se ingrese un dato fuera del rango 100 se le pedira de nuevo introducir el dato
	if(Parcial1>100.0 || Parcial1<0.0){
		printf("Dato incorrecto, ingrese el dato de nuevo\n");
	}
	else{
		Dato = 1;
		Parcial1 = Parcial1 * 0.2;
	}
	}
	printf("Ingrese la calificacion que obtuvo en su 2do Examen Parcial (base 100)\n");
	Dato = 0;
	while(Dato==0){
	scanf("%f",&Parcial2);
	//En caso de que se ingrese un dato fuera del rango 100 se le pedira de nuevo introducir el dato
	if(Parcial2>100.0 || Parcial1<0.0){
		printf("Dato incorrecto, ingrese el dato de nuevo\n");
	}
	else{
		Dato = 1;
		Parcial2 = Parcial2 * 0.2;
	}
    }
	printf("Ingrese el puntaje obtenido en las actividades de aprendizaje (base 100)\n");
	Dato = 0;
	while(Dato==0){
		scanf("%f",&ADAS);
		//En caso de que se ingrese un dato fuera del rango 100 se le pedira de nuevo introducir el dato
		if(ADAS>100.0 || ADAS<0.0){
			printf("Dato incorrecto, ingrese el dato de nuevo\n");
		}
		else{
			Dato = 1;
			ADAS = ADAS * 0.3;
		}
	}
	printf("Ingrese el puntaje obtenido en el proyecto final (base 100)\n");
	Dato = 0;
	while(Dato==0){
		scanf("%f",&ProyectoFinal);
		//En caso de que se ingrese un dato fuera del rango 100 se le pedira de nuevo introducir el dato
		if(ProyectoFinal>100.0 || ProyectoFinal<0.0){
			printf("Dato incorrecto, ingrese el dato de nuevo\n");
		}
		else{
			Dato = 1;
			ProyectoFinal = ProyectoFinal * 0.2;
		}
	}
	printf("Ingrese el puntaje obtenido en participacion en clase (base 100)\n");
	Dato = 0;
	while(Dato==0){
		scanf("%f",&Participacion);
		//En caso de que se ingrese un dato fuera del rango 100 se le pedira de nuevo introducir el dato
		if(Participacion>100.0 || Participacion<0.0){
			printf("Dato incorrecto, ingrese el dato de nuevo\n");
		}
		else{
			Dato = 1;
			Participacion = Participacion * 0.1;
		}
	}
	
	CalFinal = Parcial1+Parcial2+ADAS+ProyectoFinal+Participacion;
	
	printf("Su calificacion final es: %f\n",CalFinal);
	//Aqui se determina el estatus del alumno de acuerdo a la calificacion final
	if(CalFinal>=90.0){
		printf("Estatus: Sobresaliente");
	}
	else if(CalFinal>=80.0 && CalFinal<90.0){
		printf("Estatus: Satisfactorio");
	}
	else if(CalFinal>=70.0 && CalFinal<80.0){
		printf("Estatus: Suficiente");
	}
	else{
		printf("No acreditado");
	}
	return 0;
}

/*El programa funciona correctamente. Usó while para validar

Equipo:
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 6/02/2019*/

