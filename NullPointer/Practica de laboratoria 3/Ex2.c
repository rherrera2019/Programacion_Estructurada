#include <stdio.h> // Standard I/O
#include <conio.h> // Console I/O

/*
 * Equipo: NullPointer
 * Practica de Laboratorio 3
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 06feb2020
 * Problema
 * En un concurso se solicitará a un número no determinado de personas, que intenten adivinar la longitud exacta en metros de un vehículo. Cada persona tiene una sola oportunidad para participar. E.P. que permita leer las longitudes propuestas por dichas personas y que determine la diferencia con la longitud correcta que es 3.85 mts. También, debe capturar las propuestas de todos los que quieran participar y, cuando ya no haya más participantes, imprimir tanto el número del participante más cercano a la longitud correcta, como la longitud propuesta por dicho participante. Además, se imprimirá el número total de participantes. Utilizar sólo estructuras repetitivas do-while.
 */
    
int main(void) {
 	int contador = 1; // Contador para N personas
 	int numeroDePersonas = 0; // N Personas
 	double valorIntroducido = 0; // Guarda el valor introducido
 	const double valor = 3.85; // Valor constante
 	double tempValor = 0; // Guarda el valor mas cercana a 0 o a 0
 	double tempMasCercana = 0; // Guarda el valor mas cercana a 0
 	int tempNumeroDePersona = 0; // Guarda el numero del participante mas cercana a 0 o a 0
 	
	printf("Introducir la cantidad de personas que participara:\n");
	scanf("%d", &numeroDePersonas);
	do{
	    printf("Participante #%d, ingresar tu valor:\n", contador);
		fflush(stdin); //Descartar buffer
		scanf("%lf", &valorIntroducido);
		// Trono Checador
		if(contador == 1){// Guarda la primera sin importar que valor es
			tempValor = (float)valorIntroducido;
			tempNumeroDePersona = contador;
			if(valorIntroducido>valor && valorIntroducido-valor != 0){
				tempMasCercana = (float)(valorIntroducido-valor);
			}else if(valorIntroducido<valor && valor-valorIntroducido != 0){
				tempMasCercana = (float)(valor-valorIntroducido);
			}else if(valor-valorIntroducido == 0){
				tempMasCercana = 0;
			}
		}
		if(valorIntroducido == valor){ // Checa si el valor es igual al constante 'valor'
			tempValor = valorIntroducido;
			tempNumeroDePersona = contador;
			tempMasCercana = 0;
		}else{
			//Checa si el 'valorIntroducido' es mayor o menor que 'valor' luego hace los calculos
			if(valorIntroducido>valor && tempMasCercana != 0){
				if(valorIntroducido-valor < tempMasCercana){
					tempValor = (float)valorIntroducido;
					tempNumeroDePersona = contador;
					tempMasCercana = (float)(valorIntroducido-valor);
				}
			}else if(valorIntroducido<valor && tempMasCercana != 0){
				if(valor-valorIntroducido < tempMasCercana){
					tempValor = (float)valorIntroducido;
					tempNumeroDePersona = contador;
					tempMasCercana = (float)(valor-valorIntroducido);
				}
			}
		}
		contador++;
	}while(numeroDePersonas >= contador);
	printf("El Participante #%d fue el mas cercano al valor %lf con el valor %lf",tempNumeroDePersona, valor, tempValor); // Imprime el participante mas cercano y el valor que introducio
	return 0;
}