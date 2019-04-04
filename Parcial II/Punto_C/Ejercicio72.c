/*
Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Versión: 1.0
Descripción: Que cree un archivo de texto (.txt) llamado "Grupo2_LIS para
almacenar los datos de los alumnos de Programación Estructurada y
que contenga el siguiente menú de opciones:
1. Crear (nombre, Parcial1, Parcial2, Proyecto, calcular y guardar el
promedio final)
2. Agregar más contactos (nombre, Parcial1, Parcial 2, Proyecto, calcular y 
guardar el promedio final). 3. Visualizar toda la información existente en la pantalla.
Fecha de creación: 27/mar/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//VARIABLES Y ARREGLOS
int Exit = 0; //Determina cuando la seleccion en el menu termina
char Opcion;

//Se define una estructura de tipo Alumno que contendra sus elementos correspondientes
struct Alumno{
	char nombre[50];
	float parcial1;
	float parcial2;
	float proyecto;
	float promedio;
}alumno;

//PROCESO
//Función que genera el archivo de texto
void generar(){
	/*Nota: Para que pueda generar el archivo correctamente colóquelo en la raíz de su
	memoria USB o SD, o bien, cambie al directorio donde desea crearlo*/
	
	char direccion[] = "F:\\Grupo2_LIS.txt";
	int ExitBucle = 0; //Valor que determina cuando haya deseado terminar con la agregacion de alumnos
	int Validator = 0; //Valida si los datos ingresados en las calificaciones sean correctas
	
	printf("\nGenerando el archivo... \n");
	FILE *fd = fopen(direccion,"wt"); //wt = write text - escribir texto
	
	if(fd == NULL){
		printf("\nError: Ocurrió un problema al generar el archivo");
	}
	
	fprintf(fd,"\tGrupo2_LIS Resultados: \n");
	do{
		fflush(stdin);
		printf("\nIngrese los datos correspondientes al alumno a agregar\n");
		
		printf("Nombre: ");
		gets(alumno.nombre);
		fprintf(fd,"\nNombre: ");
		fwrite(alumno.nombre,1,strlen(alumno.nombre),fd);
		
		printf("Calificación del 1er parcial (0-40): "); Validator = 0;
		while(Validator==0){
		scanf("%f", &alumno.parcial1);
			if(alumno.parcial1>=0 && alumno.parcial1<=40){
			fprintf(fd,"\nParcial 1: %.2f", alumno.parcial1);
			Validator = 1;
			}
			else {
				printf("\nDebe ingresar solo valores de 0 a 40\n");
			}
		}
		
		printf("Calificación del 2do parcial (0-40): "); Validator = 0;
		while(Validator==0){
			scanf("%f", &alumno.parcial2);
			if(alumno.parcial2>=0 && alumno.parcial2<=40){
				fprintf(fd,"\nParcial 2: %.2f", alumno.parcial2);
				Validator = 1;
			}
			else {
				printf("\nDebe ingresar solo valores de 0 a 40\n");
			}
		}
		
		printf("Puntaje obtenido en el proyecto (0-20): "); Validator = 0;
		while(Validator==0){
			scanf("%f", &alumno.proyecto);
			if(alumno.proyecto>=0 && alumno.proyecto<=20){
				fprintf(fd,"\nProyecto: %.2f", alumno.proyecto);
				Validator = 1;
			}
			else {
				printf("\nDebe ingresar solo valores de 0 a 20\n");
			}
		}
		
		//Aqui se calcula el promedio del alumno
		alumno.promedio = alumno.parcial1 + alumno.parcial2 + alumno.proyecto;
		fprintf(fd,"\nPromedio: %.2f", alumno.promedio);
			
		printf("Desea agregar otro alumno (1. Sí 2. No: ");
		scanf("%d",&ExitBucle);
		
		fprintf(fd, "\n____________________________________________");
	}while(ExitBucle != 2);
	
	fclose(fd);
}

//Función que escribe y edita en el archivo de texto
void agregar(){
	char direccion[] = "\\Grupo2_LIS.txt";
	int ExitBucle = 0; //Valor que determina cuando haya deseado terminar con la agregacion de alumnos
	int Validator = 0; //Valida si los datos ingresados en las calificaciones sean correctas
	
	FILE *fd = fopen(direccion,"at"); //at = add text - agregar texto
	
	if(fd == NULL){
		printf("\nError: Ocurrió un problema en la modificación del archivo");
	}
	
	do{
		fflush(stdin);
		printf("\nIngrese los datos correspondientes al alumno a agregar\n");
		
		printf("Nombre: ");
		gets(alumno.nombre);
		fprintf(fd,"\n");
		fwrite(alumno.nombre,1,strlen(alumno.nombre),fd);
		
		printf("Calificación del 1er parcial (0-40): "); Validator = 0;
		while(Validator==0){
			scanf("%f", &alumno.parcial1);
			if(alumno.parcial1>=0 && alumno.parcial1<=40){
				fprintf(fd,"\nParcial 1: %.2f", alumno.parcial1);
				Validator = 1;
			}
			else {
				printf("\nDebe ingresar solo valores de 0 a 40\n");
			}
		}
		
		printf("Calificación del 2do parcial (0-40): "); Validator = 0;
		while(Validator==0){
			scanf("%f", &alumno.parcial2);
			if(alumno.parcial2>=0 && alumno.parcial2<=40){
				fprintf(fd,"\nParcial 2: %.2f", alumno.parcial2);
				Validator = 1;
			}
			else {
				printf("\nDebe ingresar solo valores de 0 a 40\n");
			}
		}
		
		printf("Puntaje obtenido en el proyecto (0-20): "); Validator = 0;
		while(Validator==0){
			scanf("%f", &alumno.proyecto);
			if(alumno.proyecto>=0 && alumno.proyecto<=20){
				fprintf(fd,"\nProyecto: %.2f", alumno.proyecto);
				Validator = 1;
			}
			else {
				printf("\nDebe ingresar solo valores de 0 a 20\n");
			}
		}
		
		//Aqui se calcula el promedio del alumno
		alumno.promedio = alumno.parcial1 + alumno.parcial2 + alumno.proyecto;
		fprintf(fd,"\nPromedio: %.2f", alumno.promedio);
		
		printf("Desea agregar otro alumno (1. Sí 2. No: ");
		scanf("%d",&ExitBucle);
		
		fprintf(fd, "\n____________________________________________");
	}while(ExitBucle != 2);
	
	fclose(fd);
}
//SALIDA
//Función que leer y visualiza el contenido del archivo de texto
void visualizar(){
	char c;
	char direccion[] = "\\Grupo2_LIS.txt";
	
	FILE *fd = fopen(direccion,"r"); //r leer archivo
	if(fd == NULL){
		printf("Error al tratar de leer el archivo");
	}
	while((c=fgetc(fd))!=EOF){
		if(c=='\n'){
			printf("\n");
		}
		else{
			putchar(c);
		}
	}
}

//ENTRADA
int main(int argc, char *argv[]) {
	
	while(Exit!=1){
    system("cls"); //Limpia la pantalla cada vez que vuelva a mostrarse este menu
		
	printf("Administración de calificaciones\n");
	printf("\n¿Que desea usted hacer?");
	printf("\n1. Generar un nuevo archivo ingresando los datos de los alumnos correspondientes");
	printf("2. Agregar nuevos datos de alumnos al archivo actual existente");
	printf("\n3. Ver los datos existentes en el archivo actual");
	printf("\n4. Salir del sistema\n");
	
	printf("\nSeleccione una opcion (1-4): ");
	scanf(" %c", &Opcion);
	
	switch(Opcion){
		case '1':
			system("cls"); //Limpia la pantalla cada vez que se selecciona una opcion
			printf("\nDesea generar un nuevo archivo (Los datos guardados previamente se perderán)");
			printf("\n1. Sí 2. No: ");
			scanf(" %c", &Opcion);
			if(Opcion=='1'){
			generar();
			}
	    break;
		case '2':
			system("cls"); //Limpia la pantalla cada vez que se selecciona una opcion
			agregar();
		break;
	    case '3':
			system("cls"); //Limpia la pantalla cada vez que se selecciona una opcion
			visualizar();
			getch();
		break;
	    case '4':
			Exit = 1;
		break;
	    default:
			system("cls"); //Limpia la pantalla cada vez que se selecciona una opcion
			printf("Seleccion no válida");
			getch();
		break;
	}
	}//Termina verificacion de salida
	
	
	return 0;
}

/*
Revisión 
-Valida corretamente.
-Esta bien documentado.
-realiza corectamente los calculos.
-Genera correctmente el archivo con 
el nombre correcto.
-Realiza lo que se pide. 
-se puede visualizar correctamente.
los datos almacenados.
-solo se logro ejecutar correctamente.
con el uso de usb.
--------------------------------------
Revisado por Punto C
*/
