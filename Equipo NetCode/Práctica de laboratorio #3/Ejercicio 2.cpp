#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Concurso de la longitud de un carro
Descripción:  Calcular cuántos participantes hay, determinar e imprimir quién se acercó mas a la longitud y cuál fue la propuesta.
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 06/02/2020
*/

#define LONGITUD 3.85

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int Confirmacion = 0; //Booleano para determinar cuándo ya no se va a ingresar una propuesta
	double Propuesta = 0.0, PropuestaCercana = 0.0, Diferencia;
	int ContParticipantes = 0, ParticipanteCercano = 0;
	printf("CONCURSO DE LA LONGITUD DE UN AUTO.\n\n");
	do 
	{
		ContParticipantes++;
		printf("\nConcursante #%d, ingrese su propuesta: ", ContParticipantes);
		scanf("%lf", &Propuesta);// Lee la propuesta del participante
		if(ContParticipantes == 1) //Si es el primer participante se agrega como que es el ganador por mientras o trono
		{
			if(Propuesta == LONGITUD) 
			{
				PropuestaCercana = Propuesta;
				ParticipanteCercano = ContParticipantes;
				Diferencia = 0;
			}else
			{
				if(Propuesta < LONGITUD){
					Diferencia = LONGITUD - Propuesta;
					PropuestaCercana = Propuesta;
					ParticipanteCercano = ContParticipantes;
				}else
				{
					Diferencia = Propuesta - LONGITUD;
					PropuestaCercana = Propuesta;
					ParticipanteCercano = ContParticipantes;
				}
			}
		}else{
			if(Propuesta == LONGITUD) // Si es exacto la propuesta entonces se pone como trono
			{
				PropuestaCercana = Propuesta;
				ParticipanteCercano = ContParticipantes;
				Diferencia = 0;
			}else
			{
				if(Propuesta < LONGITUD){ //Si no es exacto entonces se calcula si es mas cercano a la longitud del carro
					if(Diferencia > (LONGITUD - Propuesta))
					{
						PropuestaCercana = Propuesta;
						ParticipanteCercano = ContParticipantes;
						Diferencia = LONGITUD - Propuesta;
					}
				}else
				{
					if(Diferencia > (Propuesta - LONGITUD))
					{
						PropuestaCercana = Propuesta;
						ParticipanteCercano = ContParticipantes;
						Diferencia = LONGITUD - Propuesta;
					}
				}
			}	
		}
		printf("Hay alguien más que quiera participar? \n(Escribir 0 si hay mas y  si no hay mas ingrese 1):");
		scanf("%d", &Confirmacion); // Se pregunta si hay mas concursantes y sino se sale del ciclo
	}while(Confirmacion == 0);
	printf("\n\nHubieron %d participantes.", ContParticipantes);// Se imprime el ganador y cuántos participantes fueron...
	printf("\nLa persona que ingresó la longitud más cercana es \n el participante #%d con la longitud %.2lf", ParticipanteCercano, PropuestaCercana);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
