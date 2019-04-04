#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

FILE *fd;
void operaciones (char nombre[50],int parcial_1,int parcial_2,int proyecto,float promedio);
void crear ();
long editar (char nombre[50],int parcial_1,int parcial_2,int proyecto,float promedio);
void ver();
	
struct datos{
	char nombre[50];int parcial_1;int parcial_2;int proyecto;float promedio;}alumno;

char direccion[] =
	"C:\\Users\\(COLOCA TU USUARIO)\\Desktop\\Grupo2_LIS.txt";
int c;

int main ()
{
	int validador,opcion,opcion2,validador2,repetir,repetidor;
	validador=0;
	validador2=0;
	repetidor=0;
	char nombre[50];
	int parcial_1;
	int parcial_2;
	int proyecto;
	float promedio;

	do
	{
	do
	{
		printf("\n ===========================================");  
		printf("\n Presione 1 si desea crear un nuevo archivo");  
		printf("\n Presione 2 si desea agregar informacion");  
		printf("\n Presione 3 si desea ver la informacion");  
		printf("\n ===========================================");  
		printf("\n Digite su opcion :");  
		scanf("%d",&opcion);
		
		if (opcion>0&&opcion<4)
		{
			validador=1;
		}
		else{
			printf("\n Ingrese una opcion valida");
			getch() ;
			system("cls");	
		}
	} while(validador==0);
	

	switch (opcion)
	{
	case 1:
		crear ();
		break;
	case 2:
		do{
		editar (nombre,parcial_1, parcial_2,proyecto,promedio);
		printf("\n 	¿Desea agregar otro alumno? ");
		printf("\n 	Presione 1 si desea agregar uno mas : ");
		printf("\n 	Sino presione 2 : ");
		printf("\n 	Digite su opcion");
		scanf("%d",&repetir);
		if (repetir==1)
		{
			repetidor=0;
		}
		else{
			repetidor=1;
		}
		} while(repetidor==0);
		break;
	case 3:
		ver();
		break;
	}
	printf("\n 	Si desea hacer algo mas presione 1 "); 
	printf("\n 	Sino presione 2 ");
	scanf("%d",&opcion2);
	if(opcion2==1)
	{
		validador2=0;
	}
	else{
		validador2=1;
	}
	}while (validador2==0);
	
	return 0;
}
void operaciones (char nombre[50],int parcial_1,int parcial_2,int proyecto,float promedio)
{
	printf("\n Deme el nombre del alumno");  
	gets(nombre);
	
	printf ("\n Deme el resultado del parcial 1");
	scanf ("%d",&parcial_1);

	printf ("\n Deme el resultado del parcial 2");
	scanf ("%d",&parcial_2);
	
	printf ("\n Deme la calificacion del proyecto");
	scanf ("%d",&proyecto);
	
	promedio=((parcial_1+parcial_2+proyecto)/3);
	printf ("\n El promedio es %f ",promedio);
}
void crear ()
{
	char direccion[] =
		"C:\\Users\\ninja\\Desktop\\Grupo2_LIS.txt";
	
	fd = fopen(direccion,"wt");
	
	if (fd==NULL)
	{
		printf ("\n Error al tratar de crear el archivo");
	}	
	printf ("\n Creando el archivo...");
	fprintf(fd,"\t.:Lista\n");
	printf ("\n Archivo creado");
}
long editar (char nombre[50],int parcial_1,int parcial_2,int proyecto,float promedio)
{
	struct datos{
		char nombre[50];int parcial_1;int parcial_2;int proyecto;float promedio;}alumno;
	
	char direccion[] =
		"C:\\Users\\(COLOCA TU USUARIO)\\Desktop\\Grupo2_LIS.txt";
	
	fd = fopen(direccion,"at");
	
	if (fd==NULL)
	{
		printf ("\n Error al tratar de editar el archivo");
		return 1;
	}
	
	printf("\n\t.:Agregando datos:.\n");
	
	fflush(stdin);
	printf("\nNombre: ");
	gets(alumno.nombre);
	printf("Parcial 1: ");
	scanf("%d",&alumno.parcial_1);
	printf("Parcial 2: ");
	scanf("%d",&alumno.parcial_2);
	printf("Proyecto: ");
	scanf("%d",&alumno.proyecto);
	operaciones (nombre,parcial_1,parcial_2,proyecto,promedio);
	
	fprintf(fd,"\n\nNombre: ");
	fwrite(alumno.nombre,1,strlen(alumno.nombre),fd);
	fprintf(fd,"\nParcial 1: ");
	fwrite(alumno.parcial_1,1,strlen(alumno.parcial_1),fd);
	fprintf(fd,"\nParcial 2: ");
	fwrite(alumno.parcial_2,1,strlen(alumno.parcial_2),fd);

}
void ver()
{
	struct datos{
		char nombre[50];int parcial_1;int parcial_2;int proyecto;float promedio;}alumno;
	int c;
	
	fd=fopen(direccion,"r");

	if (fd==NULL)
	{
		printf("\n No se ha podido abrir el archivo para visualizarlo");
		return 1;
	}
	while((c=fgetc(fd))!=EOF){ 
		if(c=='\n'){ 
			printf("\n"); 
		} else{ putchar(c); } 
	}
	
}
/* revisado: Programacion Estructurada 
Tiene errores
no compila
parece estar bien pensado pero falla
las variables son representativas
esta documentado
quizas pudo estar mas optimizado 
el proceso*/
