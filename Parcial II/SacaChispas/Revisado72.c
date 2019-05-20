/* 72. E.P. que cree un archivo de texto (.txt) llamado "Grupo2_LIS para
almacenar los datos de los alumnos de Programación Estructurada y
que contenga el siguiente menú de opciones:
1. Crear (nombre, Parcial1, Parcial2, Proyecto, calcular y guardar el
promedio final)
2. Agregar más contactos (nombre, Parcial1, Parcial 2, Proyecto,
calcular y guardar el promedio final).
3. Visualizar toda la información existente en la pantalla.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 20/marzo/2019
Version: 1.0*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*Cambia la dirección antes de revisar*/
#define DIRECCION char direccion[] = "C:\\ArchivosC\\Grupo2_LIS.txt";

/*Prototipo de funciones*/
void crear();
void anadir();
void visualizar();

FILE *fd;

/*Estructura con los datos de los alumnos*/
struct datos_alumno
{
	char nombre[40];
	float parcial1;
	float parcial2;  
	float proyecto;
	float promedio;
	
}datos;

int main() 
{
	/*Declaramos las variables*/
	int opcion, salida = 0;
	char resp[2];
	DIRECCION
	
	/*Abrir el archivo para actualizarlo*/
	fd = fopen(direccion, "at");
	
	/*Si no se encuentra*/
	if(fd == NULL)
	{
		printf("\nNo se puede crear el archivo ");
		
		getch();
		
	}else
	{
		do
		{
			salida = 0;
			
			/*MENÚ*/
			printf("\n1.-Crear\n2.-Añadir\n3.-Visulizar información guardada ");
			printf("\n\nSeleccione una opción ");
			scanf("%i", &opcion);
			
			switch(opcion)
			{
				
			case 1:
				
				crear();
				
				break;
				
			case 2:
				
				crear();
				
				break;
				
			case 3:
				
				visualizar();
				
				break;
				
			default:
				
				printf("\nInsertó una opción NO válida");
				
				break;
				
			}
			
			printf("\n\n¿Desea realizar otra acción? (SI o NO) ");
			fflush(stdin);
			gets(resp);
			
			strlwr(resp);
			
			if(strcmp(resp, "no") == 0)
			{
				salida = 1;
			}
			
			system("cls");
			
		}while(salida == 0);
		
	}
	
	printf("Regresa, te extraño!");
	
	getch();
	
	return 0;
}

void crear()
{
	DIRECCION
	char respuesta[2];
	int validar = 0;
	
	fd = fopen(direccion, "at");
	
	/*ENTRADA  de datos*/
	do
	{
		system("cls");
		
		printf("\nNombre: ");
		fflush(stdin);
		gets(datos.nombre);
		
		printf("\nCalificación del parcial 1: ");
		scanf("%f", &datos.parcial1);
		
		printf("\nCalificación del parcial 2: ");
		scanf("%f", &datos.parcial2);
		
		printf("\nCalificación del proyecto final: ");
		scanf("%f", &datos.proyecto);
		
		datos.promedio = (float)(datos.parcial1 + datos.parcial2 + datos.proyecto)/3;
		
		
		
		printf("\n\nAlumno añadido con éxito");
		
		/*Escribir los datos en el archivo*/
		fprintf(fd, "\n\nNombre: ");
		fwrite(datos.nombre, 1, strlen(datos.nombre), fd);
		
		fprintf(fd, "\nParcial 1: %.2f", datos.parcial1);
		//fwrite(&datos.parcial1, sizeof(datos_alumno), 1, fd);
		
		fprintf(fd, "\nParcial 2: %.2f", datos.parcial2);
		//fwrite(datos.parcial2, 1, 4, fd);
		
		fprintf(fd, "\nProyecto: %.2f", datos.proyecto);
		//fwrite(datos.proyecto, 1, 4, fd);
		
		fprintf(fd, "\nPromedio: %.2f", datos.promedio);
		//fwrite(datos.promedio, 1, 4, fd);
		
		fflush(fd);
		
		printf("\n\n¿Desea añadir otro perfil? (SI o NO) ");
		fflush(stdin);
		gets(respuesta);
		
		strlwr(respuesta);
		
		if(strcmp(respuesta, "no") == 0)
		{
			validar = 1;
		}
		
	}while (validar == 0);
	

}

void visualizar()
{
	int c;
	DIRECCION
	
	fd = fopen(direccion, "rt");
	
	system("cls");
	
	if(fd == NULL)
	{
		printf("\n\nError al tratar de leer el archivo");
		
	} else
	{
		/*SALIDA de datos*/
		while((c = fgetc(fd)) != EOF)
		{
			if(c == '\n')
			{
				printf("\n");
				
			}else
			{
				putchar(c);
			}
		}
		
		fclose(fd);
	}
	
}

/*El programa funciona correctamente, cumple con lo que pedía el ejercicio propuesto
El archivo se genera de manera correcta y sin problemas al ejecutarlo

Buen uso de los comentarios, el código es entendible.

Revisó: Abigael Arjona

Equipo: Programción estructurada

*/
