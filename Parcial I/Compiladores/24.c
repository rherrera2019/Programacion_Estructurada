/*
Nombre:24
Autor: Los Compiladores
Fecha : 6Feb19
Entradas: cuatro claves para estra invitado a la chichareada
Salidas: si estas invitado o no
Procedimiento General: descubriras si la clave que tienes te sirve para entrar a la chichareada
*/
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char Con1[] = "Tienes";
	char Con2[] = "Que";
	char Con3[] = "Estar";
	char Con4[] = "Invitado";
	
	char Pass1[30];
	char Pass2[30];
	char Pass3[30];
	char Pass4[30];
	

	
	printf("Dime la clave de para la chicharreada\n");
	printf("Primera clave: ");
	gets(Pass1);
	
	if(strcmp(Con1,Pass1)==0){
		
		printf("segunda clave: ");
		gets(Pass2);
		
		if(strcmp(Con2,Pass2)==0){
			
			printf("Tercera clave: ");
			gets(Pass3);
			
			if(strcmp(Con3,Pass3)==0){
				
				printf("Cuarta clave: ");
				gets(Pass4);
				
				if(strcmp(Con4,Pass4)==0){
					
					printf("\n");
					printf("\n");
					printf("\n");
					printf("********************************\n");
					printf("Buen provecho\n");
					printf("********************************");
					
				}else printf("\n********************************\n"); printf("Usted no esta invitado\n"); printf("********************************\n");
			}else  printf("\n********************************\n"); printf("Usted no esta invitado\n"); printf("********************************\n");
		}else printf("\n********************************\n"); printf("Usted no esta invitado\n"); printf("********************************\n");
	}else  printf("\n********************************\n"); printf("Usted no esta invitado\n"); printf("********************************\n");
	
	
	return 0;
}

//El programa funciona bien, cuando se le da una palabra incorrecta ya no deja avanzar, el codigo es legible y entendible
//Reviso: Programadores Empedernidos.

