/*
50.Se llevará a cabo en la Universidad el concurso Srita. Simpatía.
Existen dos candidatas: Hortencia y Anacreta. E.P. que lea el voto de
los 500 alumnos y que determine e imprima el nombre de la ganadora.
Considerar la posibilidad de votos nulos y empate en el concurso.
Nombre:50
Autor: Los Compiladores
Fecha : 13Feb19
Entradas: 500 Votos
Salidas: Ganadora del concurso Srita. Simpatía.
Procedimiento General:Leer los votos y tomar la decicion de quien gano

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int i; 
	int voto_H=0; 
	int Voto_A=0; 
	int Voto_N=0;
	float Eleccion; 
	
	for(i=0; i<500; i++){
		//Cartel
		printf("*****************************\n");
		printf(" Hortencia : 1\n");
		printf(" Anacreta  : 2\n");
		printf(" Voto Nulo : cualquier numero que no sea 1 o 2\n");
		printf("*****************************\n");
		
		//Entrada de datos
		printf("Voto del estudiante numero %d:   ",i+1);
		scanf("%f",&Eleccion);
		
		//sumadores
		if(Eleccion==1){
			
			voto_H =(voto_H+1); 
			
		}else if(Eleccion==2){
			
			Voto_A = (Voto_A + 1);
			
		}else{
			
			Voto_N = (Voto_N +1);
			
		}
		system("cls");
		
	}
	
	//salida ganador
	
	if(Voto_A>voto_H){
		
		printf("La ganadora es Anacreta con %d",Voto_A);
		
	}else if(Voto_A<voto_H){
		
		printf("La ganadora es Hortencia con %d",voto_H);
		
	}else if(Voto_A==voto_H){
		
		printf("Hubo un empate con %d Votos para Anacreta y  %d Votos para Hortencia ",Voto_A , voto_H );
		
	}else{
		printf("Nunca deberia entrar aqui, contactar a soporte");
	}

	
	
	
	
	return 0;
}

