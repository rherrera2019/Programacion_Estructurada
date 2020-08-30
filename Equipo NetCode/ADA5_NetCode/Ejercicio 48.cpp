#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <stdlib.h>//Se usa esta librer�a para usar la funci�n de limpiar la pantalla...
/*
Nombre: Concurso Srita. Simpat�a.
Descripci�n:  Leer votos de 500 alumnos e imprimir qui�n es la ganadora.
Autores: Victor Enrique Cauich Davalos & Alan Josue Bar�n Pat
Version: 2.0
Fecha: 12/02/2020
*/

#define Alumnos 500 //Definimos cu�ntos alumnos votar�n

int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	//Declaramos votos de todas las cantidatas y votos nulos
	int VotosHortencia = 0, VotosAnacreta = 0, VotosNulos = 0, Voto = 0;
	printf("PROGRAMA PARA C�LCULAR QUI�N ES LA GANADORA DE SRITA. SIMPAT�A.\n\n");
	//For para que recorra a todos los votantes y que se vaya asignando sus votos
	for(int i = 0; i < Alumnos; i)
	{
		printf("\nHola persona #%d, es hora de decidir su voto...", i + 1);
		printf("\n1. Votar por Hortencia.");
		printf("\n2. Votar por Anacreta.");
		printf("\n3. Anular su voto.");
		printf("\nIngrese el npumero de la opci�n que quiere, por favor: ");
		scanf("%d", &Voto);
		//Es un switch para que se seleccione el voto a elecci�n
		switch(Voto)
		{
			case 1://Voto para Hortencia se suma el contador para los votos de ella
				i++;//Se aumenta i para pasar al siguiente votante
				system("cls");//funci�n para limpiar la pantalla
				VotosHortencia++;
				break;
			case 2://Voto para Anacreta se suma el contador para los votos de ella
				i++;//Se aumenta i para pasar al siguiente votante
				system("cls");//funci�n para limpiar la pantalla
				VotosAnacreta++;
				break;
			case 3://Voto nulo, es decir que se aumenta el contador de votos nulos (votantes que decidieron anular sus votos)
				i++;//Se aumenta i para pasar al siguiente votante
				system("cls");//funci�n para limpiar la pantalla
				VotosNulos++;
				break;
			default://Se usa este "caso default", si se ingresa cualquier otro dato que no sean las opciones ofrecidas
				system("cls");//funci�n para limpiar la pantalla
				printf("\n\nERROR, SELECCI�N INVALIDA...");
				printf("\nIngrese de nuevo su selecci�n, por favor...\n");
				break;
		}
	}
	
	//If's concatenados para determinbar qui�n gan�
	
	if(VotosNulos == Alumnos)//Si nadie gan�
	{
		printf("\n\nNi Hortencia ni Anacreta ganaron, debido a que todos los votantes anularon sus votos...\n");
	}else
	{
		if(VotosHortencia == VotosAnacreta)//Si quedaron en un empate
		{
			printf("\n\nHortencia y Anacreta tienen los mismos votos, por lo tanto \nquedaron en un emp�te con %d votos...\n", VotosHortencia);
		}else
		{
			if(VotosHortencia > VotosAnacreta)//Si Hortencia gan�
			{
				printf("\n\nHortencia gana a Anacreta con %d votos, y %d votos de diferencia...\n", VotosHortencia, VotosHortencia - VotosAnacreta);
			}else//Si Anacreta gan�
			{
				printf("\n\nAnacreta gana a Hortencia con %d votos, y %d votos de diferencia...\n", VotosAnacreta, VotosAnacreta - VotosHortencia);
			}
		}
	}
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
