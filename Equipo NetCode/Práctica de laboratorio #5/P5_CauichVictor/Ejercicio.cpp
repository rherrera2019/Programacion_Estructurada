#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <String.h>
/*
Nombre: CONCURSO INTERNACIONAL DE MATEM�TICAS
Descripci�n: I. Se cuenta con una lista con los resultados de 100 estudiantes en un 
concurso internacional de matem�ticas. Dicha lista contiene la siguiente informaci�n 
de cada estudiante: nombre, nombre de universidad, pa�s de nacimiento, Cal1, Cal2, 
Cal3 y Cal4. Como se observa en los datos, para cada estudiante se tiene la calificaci�n 
que obtuvo en cada uno de los cuatro problemas de que constaba el concurso. 
Tambi�n, se conoce que algunos alumnos participantes en la competencia, son de la UADY. 
E.P. que determine e imprima lo siguiente:
a) N�mero de alumnos de la UADY que participaron.
b) N�mero de participantes que sean mexicanos.
c) Nombre del alumno de la UADY que obtuvo la calificaci�n final m�s alta (s�lo es uno). 
Dicha calificaci�n final, es la suma de las cuatro calificaciones parciales obtenidas en los problemas. 

Autores: Victor Enrique Cauich Davalos
Version: 2.0
Fecha: 18/02/2020
*/

#define Alumnos 100 //Definimos la cantidad de estidiantes
double CalcularCalFinal(double Cal1, double Cal2, double Cal3, double Cal4);//inicializamos la funci�n para validad cada calificaci�n
double CalcularCalMayor(double Calificacion, double CalMayor, int t);//inicializamos la funci�n para c�lcular la calificaci�m mayor

int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	//Declaramos las variables
	char NombreAlumno[30], NombreGanadorUADY[30], NacionalidadOtra[30];
	double Cal1, Cal2, Cal3, Cal4, CALIFICACION = 0, CALIFICACIONMAYOR = 0, temp;
	int ContAlumnosUADY = 0, ContAlumnosMEX = 0, Seleccion = 0, t = 0;
	
	
	printf("EJERCICIO DE UN CONCURSO INTERNACIONAL DE MATEM�TICAS.\n\n");
	for(int i = 0; i < Alumnos; i++)
	{
		//Pedimos nombre al estudiante i
		printf("\nIngrese el nombre del estudiante #%d, por favor: ", i + 1);
		scanf("%s", &NombreAlumno);
		//Validamos la nacionalidad
		do{
			printf("\nAhora seleccione su nacionalidad.");
			printf("\n1. M�xicano.");
			printf("\n2. Estadounidense.");
			printf("\n3. Brasile�o.");
			printf("\n4. Aleman.");
			printf("\n5. Otro...");
			printf("\nSeleecione la opci�n que indique su nacionalidad: ");
			scanf("%d", &Seleccion);
			switch(Seleccion)
			{
				case 1:
					ContAlumnosMEX++;
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					printf("\nEscriba su nacionalidad, por favor: ");
					scanf("%s", &NacionalidadOtra);
					break;
				default:
					printf("\nERROR... Ingrese una opci�n validad indicada, por favor...\n");
					break;
			}
		}while(1 > Seleccion || Seleccion > 5);
		//Validamos la universidad
		do{
			printf("\nAhora seleccione su universidad.");
			printf("\n1. UADY.");
			printf("\n2. UTM.");
			printf("\n3. OXFORT.");
			printf("\n4. Stanford.");
			printf("\n5. Otro...");
			printf("\nSeleecione la opci�n que indique su nacionalidad: ");
			scanf("%d", &Seleccion);
			switch(Seleccion)
			{
				case 1:
					ContAlumnosUADY++;
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					printf("\nEscriba su universidad, por favor: ");
					scanf("%s", &NacionalidadOtra);
					break;
				default:
					printf("\nERROR... Ingrese una opci�n validad indicada, por favor...\n");
					break;
			}
		}while(1 > Seleccion || Seleccion > 5);
		
		//Se le pide al estuidiante cada calificaci�n
		
		printf("\nIngrese la calificaci�n, del parcial 1, por favor: ");
		scanf("%lf", &Cal1);
		printf("\nIngrese la calificaci�n, del parcial 2, por favor: ");
		scanf("%lf", &Cal2);
		printf("\nIngrese la calificaci�n, del parcial 3, por favor: ");
		scanf("%lf", &Cal3);
		printf("\nIngrese la calificaci�n, del parcial 4, por favor: ");
		scanf("%lf", &Cal4);
		//Se suman todas las calificaciones
		CALIFICACION = CalcularCalFinal(Cal1, Cal2, Cal3, Cal4);
		//Calculamos la calificaci�n mas alta entre los alumnos uady
		if(Seleccion == 1)
		{
			t++;
			temp = CALIFICACIONMAYOR;
			CALIFICACIONMAYOR = CalcularCalMayor(CALIFICACION, CALIFICACIONMAYOR, t);
			if(temp != CALIFICACIONMAYOR)
			{
				memcpy(NombreGanadorUADY, NombreAlumno, sizeof(NombreAlumno));//Se guarda el nombre del ganador por ahora...
			}
		}
	}
	//Imprimimos resultados...
	printf("\n\nIMPRIMIMOS LOS RESULTADOS.");
	printf("\nHay %d alumnos de la UADY en el concurso.", ContAlumnosUADY);
	printf("\nHay %d alumnos de nacionalidad mexicana en el concurso.", ContAlumnosMEX);
	printf("\nEl estudiante %s tuvo la calificaci�n mas alta que fue de %.2lf\n", NombreGanadorUADY, CALIFICACIONMAYOR);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//------------------Calcular la calificaci�n final de cada estudiante---------
double CalcularCalFinal(double Cal1, double Cal2, double Cal3, double Cal4)
{
	return Cal1 + Cal2 + Cal3 + Cal4;
}
//------------------Calcular la calificaci�n mayor----------------------------
double CalcularCalMayor(double Calificacion, double CalMayor, int t)
{
	if(t == 1)
	{
		CalMayor = Calificacion;
	}else
	{
		if(Calificacion > CalMayor)
		{
			CalMayor = Calificacion;
		}
	}
	return CalMayor;
}
