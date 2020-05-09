#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <stdlib.h>

/*
Nombre: ARCHIVO CON DATOS DE LOS ALUMNOS DE PROGRAMACIÓN ESTRUCTURADA
Descripción:  E.P. que cree un archivo de texto (.txt) llamado 
"Grupo_LIS para almacenar los datos de los alumnos de Programación 
Estructurada y que contenga el siguiente menú de opciones:

1. Crear (nombre, Parcial1, Parcial2, Proyecto, calcular y guardar 
el promedio final) 
2. Agregar más contactos (nombre, Parcial1, Parcial 2, Proyecto, 
calcular y guardar el promedio final). 
3. Visualizar toda la información existente en la pantalla.

Autores: Victor Enrique Cauich Davalos & Alan Josue Barón Pat
Version: 1.0
Fecha: 25/03/2020
*/

//Estructura para almacenar los datos de los alumnos
typedef struct Alumno{
	char Nombre[35];
	double Parcial1;
	double Parcial2;
	double Proyecto;
	double Promedio;
};

//prototipo de funciones
void Cambio(char N[]);
double ValidarCalificacion(int Val);
bool ValidarExistencia(FILE *f);

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	
	int Val;
	char Aux[98];
	bool Val1;
	FILE *f;
	Alumno A;
	
	do{
		system("cls");
		printf("PROGRAMA QUE CREA UN  ARCHIVO CON DATOS DE LOS ALUMNOS DE PROGRAMACIÓN ESTRUCTURADA.\n\n");
		printf("MENÚ:");
		printf("\n1. Crear archivo.");
		printf("\n2. Agregar más contactos al archivo.");
		printf("\n3. Visualizar toda la información existente en la pantalla.");
		printf("\n4. SALIR.");
		printf("\nINGRESE LA OPCIÓN QUE DESEE REALIZAR (EL NÚMERO), POR FAVOR: ");
		scanf("%d", &Val);
		switch(Val)
		{
			case 1:
				system("cls");
				printf("¡ADVERTENCIA!");
				printf("\nSI CONTINUA SE CREARÁ UN ARCHIVO NUEVO PARA INGRESAR\nLOS DATOS DE LOS ALUMNOS.");
				printf("\nSI YA EXISTE UNO, SE TENDRÁ QUE BORRAR, ¿DESEA CONTINUAR?");
				printf("\n1. SI.");
				printf("\n2. NO.");
				printf("\nINGRESE LA OPCIÓN QUE DESEE REALIZAR (EL NÚMERO), POR FAVOR: ");
				scanf("%d", &Val);
				do{
					switch(Val)
					{
						case 1:
							system("cls");
							f = fopen("Grupo_LIS.txt", "w");
							if(f == NULL)
							{
								system("cls");
								printf("¡¡ERROR!!");
								printf("\nNO SE PUEDO CREAR EL ARCHIVO...");
								printf("\n\n\nTeclea ENTER para salir por favor...");
								fflush(stdin);
								getchar();
								exit(-1);
							}
							fprintf(f, "%66s", "ALUMNOS DE PROGRAMACIÓN ESTRUCTURADA");
							printf("Ingrese el nombre del estudiante, por favor: ");
							fflush(stdin);
							fgets(A.Nombre, 35, stdin);
							Cambio(A.Nombre);
							A.Parcial1 = ValidarCalificacion(1);
							A.Parcial2 = ValidarCalificacion(2);
							A.Proyecto = ValidarCalificacion(3);
							A.Promedio = (A.Parcial1 + A.Parcial2 + A.Proyecto) / 3;
							fprintf(f, "\n%-38s%-15s%-15s%-15s%-15s", "Nombres", "Parcial 1", "Parcial 2", "Proyecto", "Promedio");
							fprintf(f, "\n%-38s%-15.2lf%-15.2lf%-15.2lf%-15.2lf", A.Nombre, A.Parcial1, A.Parcial2, A.Proyecto, A.Proyecto);
							fclose(f);
							system("cls");
							printf("CREADO Y GUARDADO CON ÉXITO...");
							printf("\n\n\nTeclea ENTER para regresar al menú, por favor...");
							fflush(stdin);
							getchar();
							Val = 2;
							break;
						case 2:
							system("cls");
							printf("\nENTENDIDO...");
							printf("\n\n\nTeclea ENTER para regresar al menú, por favor...");
							fflush(stdin);
							getchar();
							system("cls");
							break;
						default:
							printf("\n\nERROR... DEBE SELECCIONAR UNA OPCIÓN VALIDA.");
							printf("\nINTENTE DE NUEVO...");
							printf("\n\n\nTeclea ENTER para regresar al menú, por favor...");
							fflush(stdin);
							getchar();
							system("cls");
							break;
					}
				}while(Val != 2);
				break;
			case 2:
				system("cls");
				f = fopen("Grupo_LIS.txt", "a+");
				if(f == NULL)
				{
					system("cls");
					printf("¡¡ERROR!!");
					printf("\nNO SE PUEDO CREAR O ACCEDER AL ARCHIVO...");
					printf("\n\n\nTeclea ENTER para salir por favor...");
					fflush(stdin);
					getchar();
					exit(-1);
				}
				Val1 = ValidarExistencia(f);
				if(Val1 == false){
					printf("NO EXITE EL ARCHIVO, ASÍ QUE SE VA A CREAR COMO NUEVO:");
					fprintf(f, "%66s", "ALUMNOS DE PROGRAMACIÓN ESTRUCTURADA");
					printf("\n\nIngrese el nombre del estudiante, por favor: ");
					fflush(stdin);
					fgets(A.Nombre, 35, stdin);
					Cambio(A.Nombre);
					A.Parcial1 = ValidarCalificacion(1);
					A.Parcial2 = ValidarCalificacion(2);
					A.Proyecto = ValidarCalificacion(3);
					A.Promedio = (A.Parcial1 + A.Parcial2 + A.Proyecto) / 3;
					fprintf(f, "\n%-38s%-15s%-15s%-15s%-15s", "Nombres", "Parcial 1", "Parcial 2", "Proyecto", "Promedio");
					fprintf(f, "\n%-38s%-15.2lf%-15.2lf%-15.2lf%-15.2lf", A.Nombre, A.Parcial1, A.Parcial2, A.Proyecto, A.Proyecto);
					fclose(f);
					system("cls");
					printf("CREADO Y GUARDADO CON ÉXITO...");
					printf("\n\n\nTeclea ENTER para regresar al menú, por favor...");
					fflush(stdin);
					getchar();
				}else
				{
					printf("Ingrese el nombre del estudiante, por favor: ");
					fflush(stdin);
					fgets(A.Nombre, 35, stdin);
					Cambio(A.Nombre);
					A.Parcial1 = ValidarCalificacion(1);
					A.Parcial2 = ValidarCalificacion(2);
					A.Proyecto = ValidarCalificacion(3);
					A.Promedio = (A.Parcial1 + A.Parcial2 + A.Proyecto) / 3;
					fprintf(f, "\n%-38s%-15.2lf%-15.2lf%-15.2lf%-15.2lf", A.Nombre, A.Parcial1, A.Parcial2, A.Proyecto, A.Proyecto);
					fclose(f);
					system("cls");
					printf("CREADO Y GUARDADO CON ÉXITO...");
					printf("\n\n\nTeclea ENTER para regresar al menú, por favor...");
					fflush(stdin);
					getchar();
				}
				fclose(f);
				break;
			case 3:
				system("cls");
				f = fopen("Grupo_LIS.txt", "a+");
				if(f == NULL)
				{
					system("cls");
					printf("¡¡ERROR!!");
					printf("\nNO SE PUEDO CREAR O ACCEDER AL ARCHIVO...");
					printf("\n\n\nTeclea ENTER para salir por favor...");
					fflush(stdin);
					getchar();
					exit(-1);
				}
				Val1 = ValidarExistencia(f);
				if(Val1 == false){
					printf("¡ADVERTENCIA!");
					printf("\nNO EXITE EL ARCHIVO, ASÍ QUE SE VA A CREAR UNO:");
					printf("\nSI CONTINUA SE CREARÁ UN ARCHIVO NUEVO PARA INGRESAR\nLOS DATOS DE LOS ALUMNOS.");
					printf("\n¿DESEA CONTINUAR?");
					printf("\n1. SI.");
					printf("\n2. NO.");
					printf("\nINGRESE LA OPCIÓN QUE DESEE REALIZAR (EL NÚMERO), POR FAVOR: ");
					scanf("%d", &Val);
					do{
						switch(Val)
						{
							case 1:
								system("cls");
								fprintf(f, "%66s", "ALUMNOS DE PROGRAMACIÓN ESTRUCTURADA");
								printf("Ingrese el nombre del estudiante, por favor: ");
								fflush(stdin);
								fgets(A.Nombre, 35, stdin);
								Cambio(A.Nombre);
								A.Parcial1 = ValidarCalificacion(1);
								A.Parcial2 = ValidarCalificacion(2);
								A.Proyecto = ValidarCalificacion(3);
								A.Promedio = (A.Parcial1 + A.Parcial2 + A.Proyecto) / 3;
								fprintf(f, "\n%-38s%-15s%-15s%-15s%-15s", "Nombres", "Parcial 1", "Parcial 2", "Proyecto", "Promedio");
								fprintf(f, "\n%-38s%-15.2lf%-15.2lf%-15.2lf%-15.2lf", A.Nombre, A.Parcial1, A.Parcial2, A.Proyecto, A.Proyecto);
								system("cls");
								printf("CREADO Y GUARDADO CON ÉXITO...\nESTO ES LA INFORMACIÓN QUE SE GUARDÓ.\n");
								rewind(f);
								while(!feof(f))
								{
									fgets(Aux, 98, f);
									printf("%s", Aux);
								}
								printf("\n\n\nLISTO...");
								printf("Teclea ENTER para regresar al menú, por favor...");
								fflush(stdin);
								getchar();
								Val = 2;
								break;
							case 2:
								system("cls");
								printf("\nENTENDIDO...");
								printf("\n\n\nTeclea ENTER para regresar al menú, por favor...");
								fflush(stdin);
								getchar();
								system("cls");
								break;
							default:
								printf("\n\nERROR... DEBE SELECCIONAR UNA OPCIÓN VALIDA.");
								printf("\nINTENTE DE NUEVO...");
								printf("\n\n\nTeclea ENTER para regresar al menú, por favor...");
								fflush(stdin);
								getchar();
								system("cls");
								break;
						}
					}while(Val != 2);
				}else
				{
					printf("ESTO ES LA INFORMACIÓN QUE EXISTE EN EL ARCHIVO.\n");
					rewind(f);
					while(!feof(f))
					{
						fgets(Aux, 98, f);
						printf("%s", Aux);
					}
					printf("\n\n\nLISTO...");
					printf("Teclea ENTER para regresar al menú, por favor...");
					fflush(stdin);
					getchar();
				}
				fclose(f);
				break;
			case 4:
				system("cls");
				printf("ADIÓS...");
				break;
			default:
				printf("\n\nERROR... DEBE SELECCIONAR UNA OPCIÓN VALIDA.");
				printf("\nINTENTE DE NUEVO...");
				printf("\n\n\nTeclea ENTER para regresar al menú, por favor...");
				fflush(stdin);
				getchar();
				system("cls");
				break;
		}
	}while(Val != 4);
	
	
	printf("\n\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-----------------Cambiamos el salto de linea que nos agrega el fgets a Nombre---------
void Cambio(char N[])
{
	for(int i = 0; i < 50; i++)
	{
		if(N[i] == '\n')
		{
			N[i] = '\0';
		}
	}
}
//---------------------Función para validar calificaciones----------------
double ValidarCalificacion(int Val)
{
	double Prueba;
	switch(Val)
	{
		case 1:
			printf("\nIngrese por favor su calificación del parcial 1 alumn@: ");
			scanf("%lf", &Prueba);
			if(Prueba <= 100 && Prueba >= 0)
			{
				return Prueba;
			}else{
				printf("\nERROR, debe ingresar un valor mayor o igual a 0 y menor o igual a 100.\nIntente de nuevo, por favor...");
				printf("\nTeclea ENTER para continuar, por favor...");
				getchar();
				Prueba = ValidarCalificacion(1);
				return Prueba;
			}
			break;
		case 2:
			printf("\nIngrese por favor su calificación del parcial 2 alumn@: ");
			scanf("%lf", &Prueba);
			if(Prueba <= 100 && Prueba >= 0)
			{
				return Prueba;
			}else{
				printf("\nERROR, debe ingresar un valor mayor o igual a 0 y menor o igual a 100.\nIntente de nuevo, por favor...");
				printf("\nTeclea ENTER para continuar, por favor...");
				getchar();
				Prueba = ValidarCalificacion(2);
				return Prueba;
			}
			break;
		case 3:
			printf("\nIngrese por favor su calificación del proyecto alumn@: ");
			scanf("%lf", &Prueba);
			if(Prueba <= 100 && Prueba >= 0)
			{
				return Prueba;
			}else{
				printf("\nERROR, debe ingresar un valor mayor o igual a 0 y menor o igual a 100.\nIntente de nuevo, por favor...");
				printf("\nTeclea ENTER para continuar, por favor...");
				getchar();
				Prueba = ValidarCalificacion(3);
				return Prueba;
			}
			break;
		default:
			system("cls");
			printf("\n\n\nERROR...");
			printf("\nTeclea ENTER para salir por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
			break;
	}
}
//-------------------Función para validar si existe ya un archivo--------------
bool ValidarExistencia(FILE *f)
{
	fseek( f, 0, SEEK_END );
	if (ftell(f) == 0)
	{
		return false;
	}
	return true;
}
