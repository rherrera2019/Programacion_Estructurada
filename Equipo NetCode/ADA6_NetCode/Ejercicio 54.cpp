#include <stdio.h>
#include <locale.h>
#include <conio.h>
/* 
Nombre del Programa: El 3er Vector
Descripción: Que  lea dos vectores de n elementos y que genere e imprima
un tercer vector con la suma de cada uno de los elementos de los dos
anteriores.
Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 07/03/2020
*/
void Datos (){
	int i,a,b,elementos;
	double array1[elementos], array2[elementos], array3[elementos];
	
	printf ("Bienvenido, ingrese el tamaño de ambos vectores: ");
	do{
		scanf ("%d", &elementos);
		if (elementos <=0){
			printf ("\nTiene que existir elementos en el vector, ingrese nuevamente: ");
		}
	}while(elementos<=0);
	
	
	//-----------------Capturamos el primer vector---------------------------
	a=0;
	do{
		printf ("Ingrese el elemento %d/%d del Vector 1°: ",a+1,elementos);
		scanf ("%lf", &array1[a]);
		a++;
	} while (a<elementos);
	//-----------------Capturamos el segundo vector---------------------------
	b=0;
	printf("\n");
	do{
		printf  ("Ingrese el elemento %d/%d del Vector 2°: ",b+1,elementos);
		scanf ("%lf", &array2[b]);
		b++;
	} while (b<elementos);
	//---------------------Imprimimos los datos------------------------------
	i = 0;
	printf ("\nEl vector generado de la suma del vector 1 y 2 es: \n");
	do{
		array3[i]= (array1[i])+(array2[i]);
		printf ("Elemento %d/%d del Vector 3°: %.4lf\n",i+1,elementos,array3[i]);
		i++;
	} while (i<elementos);
	
}

int main (){
	setlocale(LC_ALL,"");
	Datos();
	getch();
	return 0;
}
