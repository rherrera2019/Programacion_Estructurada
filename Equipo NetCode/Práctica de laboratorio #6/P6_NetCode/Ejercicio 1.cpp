#include <stdio.h>
#include <locale.h>
/*
Nombre del Programa: Reporte de NOMBRE, PESO Y ESTATURA
Descripción:  E.P. que lea un arreglo con los nombres de n personas, un segundo arreglo con el peso y un tercer arreglo con la estatura de dichas personas.
Es decir se contará con tres arreglos: nombres, pesos y estaturas; determinar el peso y la estatura promedio.

Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 09/03/2020
*/

int main (){
	setlocale (LC_ALL,"");
	
	int i,personas;
	double pesoP,estaturaP;
	
	//------------Determinamos el total de elementos------------
	printf ("Bienvenido, ingrese el total de personas a reportar: ");
	do{
		scanf ("%d", &personas);
		if (personas<=0){
			printf ("/nDebe existir gente a reportar, ingrese nuevamente: ");
		}
	}while (personas<=0);
	
	char nombres[personas][30];
	double peso[personas], estatura[personas];
	//-----------------------Capturamos los datos--------------------------
	pesoP = 0;
	estaturaP = 0;
	
	for (i=0;i<personas;i++){
		printf("\nCapturando datos %d/%d\n",i+1,personas);
		printf ("Ingrese su nombre: ");
		scanf("%s", &nombres[i]);
		
		printf ("Ingrese su peso: ");
		scanf ("%lf", &peso[i]);
		pesoP= pesoP + peso[i];
		
		printf ("Ingrese su estatura: ");
		scanf ("%lf", &estatura[i]);
		estaturaP= estaturaP + estatura[i];
	}
	//--------------Determinamos el peso y estatura promedio-----------------
	pesoP= pesoP/personas;
	estaturaP= estaturaP/personas;
	//-------------------------Imprimimos el reporte-------------------------
	printf ("\n                    REPORTE\n");
	printf ("  NOMBRE       PESO(KG)           ESTATURA(CM)\n");
	printf (" Promedio:     %.3lf              %.3lf \n", pesoP, estaturaP);
	printf ("-----------------------------------------------\n");
	i = 0;
	for (i=0;i<personas;i++)
	{
		printf("%s        %.2lf          %.2lf\n", nombres[i], peso[i], estatura[i]);
	}
	printf ("-----------------------------------------------\n");
	
	
	getchar ();
	return 0;
}
