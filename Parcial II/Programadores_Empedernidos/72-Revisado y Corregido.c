/*E.P. que cree un archivo de texto (.txt) llamado "Grupo2_LIS para
almacenar los datos de los alumnos de Programación Estructurada y
que contenga el siguiente menú de opciones:
	1. Crear (nombre, Parcial1, Parcial2, Proyecto, calcular y guardar el
	promedio final)
	2. Agregar más contactos (nombre, Parcial1, Parcial 2, Proyecto,
	calcular y guardar el promedio final).
	3. Visualizar toda la información existente en la pantalla.

Autor: Programadores Empedernidos. Fecha: 31/03/19. Versi�n 1.0 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
void color(char color);
void crearAlumno();
void pantallaInicio();
void pantallaFin();

int i, contContactos=0, editContacto, repetido=0, encontrado=0;
char opcion, datosAlumno[256], calif[128], numero[128], lineaArchivo[1024], delim1[]=",", delim2[]=" "; //variable iterativa y variable del tama�o del vector 
FILE *agenda,  *temp; //archivo
//estructura del estudiante
struct estudiante{
        char nombre[30];
        //estructura anidada del promedio
        struct promedio{
            float parcial1;
            float parcial2;
            float proyecto;
            float promedioGeneral;
        } calificacion;
    }estudiante;

int main(){
	
	 //comienzo de la Pantalla de inicio
    pantallaInicio();

    printf("\nPrograma: Agenda de estudiantes");
    printf("\nDescripci%cn: E.P. que cree un archivo de texto (.txt) llamado \"Grupo2_LIS\" para almacenar los datos de los alumnos de Programaci%cn Estructurada y que contenga el siguiente men%c de opciones: \n\t1. Crear (nombre, Parcial1, Parcial2, Proyecto, calcular y guardar el promedio final)\n\t2. Agregar m%cs contactos (nombre, Parcial1, Parcial 2, Proyecto, calcular y guardar el promedio final).\n\t3. Visualizar toda la informaci%cn existente en la pantalla.\n", 162, 162, 163, 160, 162);

    system("pause"); system("cls");
    //fin de la pantalla de inicio
	
	do{
		//menu de las opciones
		system("cls");
		color(3);
		printf("\n\tMenu de opciones:");
		color(5);
		printf("\n1) Crear un nuevo alumno");
		printf("\n2) Editar un alumno");
		printf("\n3) Eliminar un alumno");
		printf("\n4) Ver todos los alumnos registrados");
		printf("\n5) Cerrar el programa");
		printf("\n\nEscriba el numero de la opcion: "); 
		scanf(" %c", &opcion);
		system("cls");
		//entra dependiendo de la opcion dada
		switch (opcion)
		{
			case '1':
				color(2);
				printf("\n\tCREAR UN NUEVO ALUMNO");
				color(15);
				//se leen los datos del estudiante
				//verifica que el nombre del estudiante no este repetido
				strcpy(datosAlumno, "");
				crearAlumno();
				//se añade a la agenda el nuevo estudiante
				agenda = fopen("Grupo2_LIS.txt", "a+");
				fputs(datosAlumno, agenda);
				//se cierra el archivo de la agenda
				fclose(agenda);
				break;
			case '2':

				printf("Dame la posicion del contacto que quieres cambiar: ");
				scanf("%d", &editContacto);
				//se crea un archivo temporal
				temp = fopen("temp.txt", "w+");
				strcpy(datosAlumno, "");
				system("cls");
				//Se leen los datos del estudiante que se va a editar
				color(2);
				printf("\n\tEDITAR UN ALUMNO EXISTENTE");
				fflush(stdin);
				color(15);
				//se piden los datos el alumnos mediante la siguiente funcion
				crearAlumno();
				//se abre el archivo de agenda principal en modo lectura
				agenda = fopen("Grupo2_LIS.txt", "r");
				// se lee cada linea de la agenda
				contContactos=1; //contador para saber en que contacto estamos
				while(fgets(lineaArchivo, 1024, (FILE*) agenda)){
					// si el contacto a editar coincide con nuestro contadorm lo que se escribira en nuestro archivo temporal sera lo que leyo 
					if (contContactos == editContacto) {
						fputs(datosAlumno, temp);
					}
					//en caso de que no, simplementa pasara la linea en la que se encuentra al archivo temporal
					else{
						fputs(lineaArchivo, temp);
					}
			        contContactos++;
				}
				fclose(agenda);
				fclose(temp);
				//se elimina la antigua agenda y el archivo temporal pasa ser la agenda principal
				remove("Grupo2_LIS.txt");
				rename("temp.txt", "Grupo2_LIS.txt");
				color(2);
				printf("\nContacto editado con exito!\n\n");
				color(7);
				system("pause");
				break;
			case '3':
				printf("Dame la posicion del contacto que quieres eliminar: ");
				scanf("%d", &editContacto);

				system("cls");
				color(9);
				printf("\nEliminando al alumno...");
				
				color(15);
				//se abre el archivo de agenda principal en modo lectura
				agenda = fopen("Grupo2_LIS.txt", "r");
				//Se crea un archivo temporal
				temp = fopen("temp.txt", "w+");
				// se lee cada linea de la agenda
				contContactos=1; //contador para saber en que contacto estamos
				encontrado=0;
				while(fgets(lineaArchivo, 1024, (FILE*) agenda)){
					// si el contacto a editar coincide con nuestro contadorm lo que se escribira en nuestro archivo temporal sera lo que leyo 
					if (contContactos != editContacto) {
						fputs(lineaArchivo, temp);
					}
					else{
						encontrado=1;
					}
			        contContactos++;
				}
				fclose(agenda);
				fclose(temp);
				//se elimina la antigua agenda y el archivo temporal pasa ser la agenda principal
				remove("Grupo2_LIS.txt");
				rename("temp.txt", "Grupo2_LIS.txt");
				sleep(3);
				if (encontrado==1) {
					color(2);
					printf("\nContacto eliminado con exito!\n\n");
				}else{
					color(12);
					printf("\nNo se encontro el contacto!\n\n");
				}
				
				color(7);
				system("pause");
				break;
			case '4':
				//se abre el archivo de agenda en modo lectura
				agenda = fopen("Grupo2_LIS.txt", "r");
				i=1;
				//se imprime los datos de cada alumno
				while(fgets(lineaArchivo, 1024, (FILE*) agenda)){
					color(2);
					//al estar guardado en una linea el dato de un alumno, se usa strtok para dividir la informacion e imprimirla bien
					printf("\n\tALUMNO #%d",i);
					char *ptr = strtok(lineaArchivo, delim1); 
					color(15);
					while(ptr != NULL){
			            printf("\n%s", ptr);
			            ptr = strtok(NULL, delim1);
			        }
			        i++;
				}
				fclose(agenda);
				system("pause");
				break;
			case '5':
				//se imprime la pantalla de fin del programa
				color(6);
				pantallaFin();
				system("pause");
				break;
			default:
			//se da error
				color(4);
				printf("Opcion no valida, escoge otra\n\n");
				color(7);
				system("pause");
				break;
		}
	}while (opcion != '5');
	
	color(7);
	return 0;
}
//funciones para aspectos visuales
void crearAlumno(){
	//do while para verificar que el nombre del alumno no se repita, en caso de que si se repita, se vuelve a pedir
	do{
		repetido=0;
		fflush(stdin);
		printf("\nNombre: "); gets(estudiante.nombre);
		agenda = fopen("Grupo2_LIS.txt", "a+");
		while(fgets(lineaArchivo, 1024, (FILE*) agenda)){
			char *ptr= strtok(lineaArchivo, delim1); 
			char *alumno;
    		strtok_r(ptr, delim2, &alumno);
			if(strcmp(ptr, estudiante.nombre) == 0){
				repetido=1;
				color(4);
				printf("\nEl nombre del alumno ingresado ya existe en la agenda, por favor, ingresa otro.\n");
				color(15);
				break; 
			}
		}
		fclose(agenda);
	}while(repetido==1);
	strcpy(datosAlumno, estudiante.nombre);
	strcat(datosAlumno, ",");
	//en cada lectura de las calificaciones, se verifica que no sea negativa, en caso de que lo sea se vuelve a pedir
	//si la calificacion ingresada es mayor a 100, el valor se pasa a 100
	do{
		printf("\nParcial 1: "); 
		scanf("%f", &estudiante.calificacion.parcial1);
		if (estudiante.calificacion.parcial1 < 0) {
			color(4);
			printf("\nNo puedes dar una calificacion menor a cero, ingresa otra...\n");
			color(15);
		}
		if (estudiante.calificacion.parcial1 > 100) {
			estudiante.calificacion.parcial1 = 100;
		}	
	}while (estudiante.calificacion.parcial1 < 0);
	sprintf(numero, "Parcial 1: %.2f", estudiante.calificacion.parcial1);
	strcat(datosAlumno, numero);
	strcat(datosAlumno, ",");
	
	do{
		printf("\nParcial 2: "); 
		scanf("%f", &estudiante.calificacion.parcial2);
		if (estudiante.calificacion.parcial2 < 0) {
			color(4);
			printf("\nNo puedes dar una calificacion menor a cero, ingresa otra...\n");
			color(15);
		}
		if (estudiante.calificacion.parcial2 > 100) {
			estudiante.calificacion.parcial2=100;
		}	
	}while (estudiante.calificacion.parcial2 < 0);
	sprintf(numero, "Parcial 2: %.2f", estudiante.calificacion.parcial2);
	strcat(datosAlumno, numero);
	strcat(datosAlumno, ",");

	do{
		printf("\nProyecto: "); 
		scanf("%f", &estudiante.calificacion.proyecto);
		if (estudiante.calificacion.proyecto < 0) {
			color(4);
			printf("\nNo puedes dar una calificacion menor a cero, ingresa otra...\n");
			color(15);
		}
		if (estudiante.calificacion.proyecto > 100) {
			estudiante.calificacion.proyecto = 100;
		}	
	}while (estudiante.calificacion.proyecto < 0);
	sprintf(numero, "Proyecto: %.2f", estudiante.calificacion.proyecto);
	strcat(datosAlumno, numero);
	strcat(datosAlumno, ",");

	estudiante.calificacion.promedioGeneral = (estudiante.calificacion.parcial1 + estudiante.calificacion.parcial2 + estudiante.calificacion.proyecto)/3;
	sprintf(numero, "Promedio General: %.2f", estudiante.calificacion.promedioGeneral);
	strcat(datosAlumno, numero);
	strcat(datosAlumno, "\n");
}

float crearAlumnoCalificacion();
void color(char color){
	HANDLE cambioDeColor;
	cambioDeColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cambioDeColor, color);
}
void pantallaFin(){
	printf(" _  _   _   ___ _____ _     _   _   _ ___ ___  ___  _ \n| || | /_\\ / __|_   _/_\\   | | | | | | __/ __|/ _ \\| |\n| __ |/ _ \\\\__ \\ | |/ _ \\  | |_| |_| | _| (_ | (_) |_|\n|_||_/_/ \\_|___/ |_/_/ \\_\\ |____\\___/|___\\___|\\___/(_)\n");
}
void pantallaInicio(){
    color(5);
    printf(" ______                                             _\n(_____ \\                                           | |\n _____) )___ ___   ____  ____ _____ ____  _____  __| | ___   ____ _____  ___\n|  ____/ ___) _ \\ / _  |/ ___|____ |    \\(____ |/ _  |/ _ \\ / ___) ___ |/___)\n| |   | |  | |_| ( (_| | |   / ___ | | | / ___ ( (_| | |_| | |   | ____|___ |\n|_|   |_|   \\___/ \\___ |_|   \\_____|_|_|_\\_____|\\____|\\___/|_|   |_____|___/\n                 (_____| \n");
    color(13);
	printf("     _______                       _                   _     _\n    (_______)                     | |                 (_)   | | \n     _____   ____  ____  _____  __| |_____  ____ ____  _  __| | ___   ___\n    |  ___) |    \\|  _ \\| ___ |/ _  | ___ |/ ___)  _ \\| |/ _  |/ _ \\ /___) \n    | |_____| | | | |_| | ____( (_| | ____| |   | | | | ( (_| | |_| |___ |\n    |_______)_|_|_|  __/|_____)\\____|_____)_|   |_| |_|_|\\____|\\___/(___/\n                  |_|\n");
	color(7);
}
