#include <stdio.h>
/*Los estudiantes de Ingeniería presentaron un examen de
admisión con 100 preguntas. E.P. que lea el nombre y el número de
respuestas correctas para cada una de las 50 personas que
presentaron y que determine e imprima para cada uno su nombre y su
calificación*/
int main () 
{
	/*variables*/
	int per,rescor;
	char nom[50];
	per=0;
	rescor=0;
	/*proceso*/
	do 
	{
		printf ("Escribe tu nombre: ");
		fgets (nom,50,stdin);
		printf ("Escriba el numero de respuestas correctas: ");
		scanf ("%d",&rescor);
		/*salida*/
		printf ("%s",nom);
		if (rescor>30 && rescor<=50) 
		{
			printf ("La calificacion total es de: 50 \n");
		}
		if (rescor>50 && rescor<=60) 
		{
			printf ("La calificacion total es de: 60 \n");
		}
		if (rescor>60 && rescor<=65) 
		{
			printf ("La calificacion total es de: 70 \n");
		}
		if (rescor>65 && rescor<=75) 
		{
			printf ("La calificacion total es de: 80 \n");
		}
		if (rescor>75 && rescor<=90) 
		{
			printf ("La calificacion total es de: 90 \n");
		}
		if (rescor>90) 
		{
			printf ("La calificacion total es de: 100 \n");
		}
		if (rescor<30) 
		{
			printf ("No hay calificacion \n");
		}
		fgets (nom,50,stdin);
		per++;
	} while(per<50);
	
}
