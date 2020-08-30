#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Calificaci�n de alumnos de 100 preguntas
Descripci�n:  Leer cu�ntas preguntas de 100 contestaron bien los alumnos e imprimir cu�l es su calificaci�n
Autores: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 07/02/2020
*/

int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	int Alumnos = 50, Preguntas = 100, i = 0, t = 0; //Declaramos e inicializamos las variables
	int PreguntasContestadas;
	char Nombre[30];
	printf ("Programa que calcula cu�l es el puntaje de los alumnos.\n");
	while(i < Alumnos){
		printf("\nIngrese el primer nombre del alumno #%d, por favor: ", i + 1);
		scanf("%s", &Nombre);//Se pide ingresar el nombre del alumno
		fflush(stdin);//Se limpia el buffer del escaneer
		printf("Ingrese cu�ntas preguntas contest� bien el alumno #%d, por favor: ", i + 1);
		scanf("%d", &PreguntasContestadas);//Se leen cu�ntas preguntas contest� el alumno
		fflush(stdin);
		if(PreguntasContestadas < 0 || PreguntasContestadas > 100)//Se valida si las preguntas que ingres� son entre 0 y 100, sino se pide insertar todo de nuevo
		{
			printf("\nLas preguntas contestadas son invalidad, ingrese un valor entre 0 y 100...\n");
		}else
		{
			i++;//Ya que se haya validado las preguntas, entonces ya se podr�a aumentar el contador hacia el siguiente alumno
			if(PreguntasContestadas <= 30)//Se calcula si las preguntas ingresadas son menor o igual a 30, si es entonces se imprime lo siguiente...
			{
				printf("\nEl alumno tiene 0 de calificaci�n o no tiene calificaci�n...\n");
			}else
			{
				if(PreguntasContestadas <= 50)//Se calcula si las preguntas ingresadas son menor o igual a 50, si es entonces se imprime lo siguiente...
				{
					printf("\nEl alumno %s sac� 50 puntos con %d preguntas contestadas.\n", Nombre, PreguntasContestadas);
				}else
				{
					if(PreguntasContestadas <= 60)//Se calcula si las preguntas ingresadas son menor o igual a 60, si es entonces se imprime lo siguiente...
					{
						printf("\nEl alumno %s sac� 60 puntos con %d preguntas contestadas.\n", Nombre, PreguntasContestadas);
					}else
					{
						if(PreguntasContestadas <= 65){//Se calcula si las preguntas ingresadas son menor o igual a 65, si es entonces se imprime lo siguiente...
							printf("\nEl alumno %s sac� 70 puntos con %d preguntas contestadas.\n", Nombre, PreguntasContestadas);
						}else
						{
							if(PreguntasContestadas <= 75)//Se calcula si las preguntas ingresadas son menor o igual a 75, si es entonces se imprime lo siguiente...
							{
								printf("\nEl alumno %s sac� 80 puntos con %d preguntas contestadas.\n", Nombre, PreguntasContestadas);
							}else
							{
								if(PreguntasContestadas <= 90)//Se calcula si las preguntas ingresadas son menor o igual a 90, si es entonces se imprime lo siguiente...
								{
									printf("\nEl alumno %s sac� 90 puntos con %d preguntas contestadas.\n", Nombre, PreguntasContestadas);
								}else//Si las preguntas son entre 91 y 100, entonces se imprime lo siguiente...
								{
									printf("\nEl alumno %s sac� 100 puntos con %d preguntas contestadas.\n", Nombre, PreguntasContestadas);
								}
							}
						}
					}
				}
			}
		}
	}
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
