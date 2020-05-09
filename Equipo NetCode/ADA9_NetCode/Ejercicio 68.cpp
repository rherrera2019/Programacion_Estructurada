#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <stdlib.h>

/*
Nombre: ALUMNO CON MAYOR CALIFICACIÓN
Descripción:  E.P. que utilice dos estructuras una llamada 
promedio que tendrá los siguientes miembros: Parcial1, Parcial2 
y Proyecto; y otro llamada alumno que tendrá los siguientes 
miembros: nombre, sexo y equipo; anidar la estructura promedio 
en la estructura alumno, leer los datos para los N alumnos de 
Programación Estructurada, calcular el promedio de cada uno e 
imprimir los datos del alumno con el mejor promedio del grupo.
Autores: Victor Enrique Cauich Davalos & Alan Josue Barón Pat
Version: 1.0
Fecha: 24/03/2020
*/

//Creamos las estructuras
typedef struct Promedio
{
	double Parcial1;
	double Parcial2;
	double Proyecto;
};

typedef struct Alumno
{
	char Nombre[30];
	int Sexo;
	char Equipo[30];
	Promedio Promedio;
};

//prototipo de funciones
int ValidarCantidadAlumnos(int N);//Para validar cuántos alumnos son
void IngresarDatosAlumno(Alumno Alumnos[], int N, double &PromedioMayor);
int IngresarSexo(Alumno E);
double ValidarCalificacion(int i, int Val);
void MostrarAlumnoGanador(Alumno Alumnos[], int N, double PromedioMayor);

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	printf("PROGRAMA QUE CALCULA EL ALUMNO QUE SACÓ EL PROMEDIO MAS ALTO DEL SALÓN\nDE PROGRAMACIÓN ESTRUCTURADA.");
	int N;//cantidad de alumnos
	double PromedioMayor;
	
	//Validar el número de alumnos
	N = ValidarCantidadAlumnos(N);
	
	//Creamos el array de alumnos
	Alumno Alumnos[N];
	
	//Asignar datos de cada alumno
	IngresarDatosAlumno(Alumnos, N, PromedioMayor);
	
	system("cls");
	printf("\n\n");
	MostrarAlumnoGanador(Alumnos, N, PromedioMayor);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-------------------Función que valida cantidad de alumnos---------------
int ValidarCantidadAlumnos(int N)
{
	printf("\nIngrese por favor la cantidad de \nalumnos, por favor: ");
	scanf("%d", &N);
	fflush(stdin);
	if(N > 0)
	{
		return N;
	}else
	{
		printf("\nERROR, debe ingresar un valor mayor a 0.\n Intente de nuevo, por favor...");
		printf("\nTeclea ENTER para continuar, por favor...");
		getchar();
		system("cls");
		N = ValidarCantidadAlumnos(N);
		return N;
	}
}
//-----------------Función para asignar datos de los alumnos-------------
void IngresarDatosAlumno(Alumno Alumnos[], int N, double &PromedioMayor)
{
	PromedioMayor = 0;
	system("cls");
	for(int i = 0; i < N; i++)
	{
		printf("\nIngrese por favor su nombre alumn@ #%d: ", i + 1);
		scanf("%s", &Alumnos[i].Nombre);
		fflush(stdin);
		printf("\nIngrese por favor su nombre de equipo alumn@ #%d: ", i + 1);
		scanf("%s", &Alumnos[i].Equipo);
		fflush(stdin);
		Alumnos[i].Sexo = IngresarSexo(Alumnos[i]);
		Alumnos[i].Promedio.Parcial1 = ValidarCalificacion(i, 1);
		Alumnos[i].Promedio.Parcial2 = ValidarCalificacion(i, 2);
		Alumnos[i].Promedio.Proyecto = ValidarCalificacion(i, 3);
		if(PromedioMayor < ((Alumnos[i].Promedio.Parcial1 + Alumnos[i].Promedio.Parcial2 + Alumnos[i].Promedio.Proyecto) / 3))
		{
			PromedioMayor = (Alumnos[i].Promedio.Parcial1 + Alumnos[i].Promedio.Parcial2 + Alumnos[i].Promedio.Proyecto) / 3;
		}
	}
}
//---------------------Función para validar calificaciones----------------
double ValidarCalificacion(int i, int Val)
{
	double Prueba;
	switch(Val)
	{
		case 1:
			printf("\nIngrese por favor su calificación del parcial 1 alumn@ #%d: ", i + 1);
			scanf("%lf", &Prueba);
			if(Prueba <= 100 && Prueba >= 0)
			{
				return Prueba;
			}else{
				printf("\nERROR, debe ingresar un valor mayor o igual a 0 y menor o igual a 100.\nIntente de nuevo, por favor...");
				printf("\nTeclea ENTER para continuar, por favor...");
				getchar();
				Prueba = ValidarCalificacion(i, 1);
				return Prueba;
			}
			break;
		case 2:
			printf("\nIngrese por favor su calificación del parcial 2 alumn@ #%d: ", i + 1);
			scanf("%lf", &Prueba);
			if(Prueba <= 100 && Prueba >= 0)
			{
				return Prueba;
			}else{
				printf("\nERROR, debe ingresar un valor mayor o igual a 0 y menor o igual a 100.\nIntente de nuevo, por favor...");
				printf("\nTeclea ENTER para continuar, por favor...");
				getchar();
				Prueba = ValidarCalificacion(i, 2);
				return Prueba;
			}
			break;
		case 3:
			printf("\nIngrese por favor su calificación del proyecto alumn@ #%d: ", i + 1);
			scanf("%lf", &Prueba);
			if(Prueba <= 100 && Prueba >= 0)
			{
				return Prueba;
			}else{
				printf("\nERROR, debe ingresar un valor mayor o igual a 0 y menor o igual a 100.\nIntente de nuevo, por favor...");
				printf("\nTeclea ENTER para continuar, por favor...");
				getchar();
				Prueba = ValidarCalificacion(i, 3);
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
//-------------------------Función para validar sexo de cada alumno------
int IngresarSexo(Alumno A)
{
	printf("\nIngrese por favor su sexo, siendo:");
	printf("\n1. Hombre.");
	printf("\n2. Mujer.");
	printf("\nIngrese el número de su opción: ");
	scanf("%d", &A.Sexo);
	fflush(stdin);
	if(A.Sexo != 1 && A.Sexo != 2)
	{
		printf("\nERROR, debe ingresar 1 o 2, como muestra en las opciones.\n Intente de nuevo, por favor...");
		A.Sexo = IngresarSexo(A);
		return A.Sexo;
	}else
	{
		return A.Sexo;
	}
}
//------------------Función para mostrar los datos del alumno con mayor promedio-----------
void MostrarAlumnoGanador(Alumno Alumnos[], int N, double PromedioMayor)
{
	int t = 1;
	printf("\nEL PROMEDIO MAXIMO DE TODO EL GRUPO ES: %.2lf.", PromedioMayor);
	printf("\nA CONTINUACIÓN SE MOSTRARÁN LOS ALUMNOS CON ESE PROMEDIO:\n");
	for(int i = 0; i < N; i++)
	{
		if(PromedioMayor == ((Alumnos[i].Promedio.Parcial1 + Alumnos[i].Promedio.Parcial2 + Alumnos[i].Promedio.Proyecto) / 3))
		{
			printf("\nALUMNO #%d:", t);
			printf("\nEl nombre del/la alumn@ es: %s", Alumnos[i].Nombre);
			if(Alumnos[i].Sexo == 1)
			{
				printf("\nEl sexo del/la alumn@ es: Hombre");
			}else
			{
				printf("\nEl sexo del/la alumn@ es: Mujer");
			}
			printf("\nEl equipo del/la alumn@ es: %s", Alumnos[i].Equipo);
			printf("\nLa calificación del parcial 1 del/la alumn@ es: %.2lf", Alumnos[i].Promedio.Parcial1);
			printf("\nLa calificación del parcial 2 del/la alumn@ es: %.2lf", Alumnos[i].Promedio.Parcial2);
			printf("\nLa calificación del proyecto del/la alumn@ es: %.2lf", Alumnos[i].Promedio.Proyecto);
			t++;
		}
	}
}
