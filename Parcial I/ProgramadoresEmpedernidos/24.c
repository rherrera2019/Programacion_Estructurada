
//El maestro Emilio organiza una comida-chicharriza, donde una
//computadora controla el acceso de los invitados a la fiesta, mediante
//cuatro claves (contraseñas); las cuales deben ser proporcionadas una,
//por una, en el orden correcto (cuatro lecturas diferentes). Si la persona
//se equivoca, al menos una vez, en una clave o en el orden, la
//computadora imprimirá "Tú no estás invitado" y no le permitirá el
//acceso. Por el contrario, si las cuatro claves son correctas e
//introducidas en el orden adecuado, el sistema imprimirá "Buen
//provecho". Las claves son (en el orden): 1. Tienes, 2. Que, 3. Estar, 4.
//Invitado. E.P. que controle el acceso, tal como se especifica..

//Autores = programadores empedernidos.
#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(){
	//Variables de las palabras
	char tienes[10], que[10], estar[10], invitado[10];
	
	printf("----------------CHICHARRIZA----------------\n");
	printf("Ingresa la la contrase%ca secreta...\n", 164);
	
	//proceso de preguntas para saber si ingresa correctamente la frase completa
	gets(tienes);
	
	if (strcmp(tienes,"Tienes") == 0 ){ //Se usa la funcion strcmp() para comparar el string
		printf("siguiente palabra...\n");
		gets(que);
		
		if(strcmp(que,"Que") == 0){
			printf("siguiente palabra...\n");
			gets(estar);
			
			if(strcmp(estar,"Estar") == 0){
				printf("siguiente palabra...\n");
				gets(invitado);
				
				if(strcmp(invitado,"Invitado") == 0){
					printf("Pase usted, honorable hombre ;)\n");
				}
				else{
					printf("MEEEEH, palabra incorrecta, intentalo en otro momento ;)");
				}
			}
			else{
				printf("MEEEEH, palabra incorrecta, intentalo en otro momento ;)");
			}
		}
		else{
			printf("MEEEEH, palabra incorrecta, intentalo en otro momento ;)");
		}
	}
	else{
		printf("MEEEEH, palabra incorrecta, intentalo en otro momento ;)");
	}
	
	return 0;
}
