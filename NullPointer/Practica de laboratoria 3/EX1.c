#include <stdio.h>
int mes,cont,vermes, primse,segse;
int main() {
	cont=0;
	//se encarga de preguntar a los 45 alumnos su mes de edad//
	while(cont<45)
	{
		//vermes mantiene 1 si el mes es incorrecto y 0 cuando es correcto//
		vermes=1;
		printf("Introduce tu mes de nacimiento\n");
		scanf("%d",&mes);
		//verfica el mes introducido y si no es correcto, pide otro//
		while(vermes!=0)
		{
			//se encarga del proceso de verificar el mes//
		if(mes>=1){
			if(mes<=12){
				vermes=0;
			} else{
				printf("el mes introducido no existe, introduce uno nuevo\n");
				printf("Introduce tu mes de nacimiento\n");
				scanf("%d",&mes);
			}
		} else{
			printf("el mes introducido no existe, introduce uno nuevo\n");
			printf("Introduce tu mes de nacimiento\n");
			scanf("%d",&mes);
		}
		
		}
		//contador que sirve para llegara a los 45 alumnos//
		cont++;
		//contador de nacidos en que semestre//
		if(mes<7){
			primse+=1;
		} else{
			segse+=1;
		}
	} 
	
	printf("hubieron %d que nacieron en el primer semestre y %d en el segundo semestre",primse,segse);
	return 0;
}

