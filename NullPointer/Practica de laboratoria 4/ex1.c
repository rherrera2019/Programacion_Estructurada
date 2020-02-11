#include <stdio.h>

int main() {
	/*
	comd=dato que el usuario introduce
	cont1 contador para el for
	posix,posiy, sumadores
	movs cantidad de movimientos
	key verifica si el comando es correcto
	*/
	int comd,cont1,posix,posiy,movs,key;
	//inicializa contadores//
	posix=0;
	posiy=0;
	key=0;
	//lectura de cant de movimientos//
	printf("introduce el numero de movimienos\n");
	scanf("%d",&movs);
	printf("introduce uno de los siguientes comandos:\n 6 Aumenta coordenada x por 1 \n 4 Reduce coordenada x por 1 \n 8 Aumenta coordenada y por 1 \n 2 Reduce coordenada y por 1\n");
	//procesos//
	for(cont1=0;cont1<movs;cont1++){
		//lectura de comando//
		printf("introduce el comando\n");
		scanf("%d",&comd);
		//do-while verifica y aumenta la posicion x o y, sino es correcto, realiza la misma accion hasta confirma//
		do{
			//verifica los comandos//
		} while();
		if(comd==6){
			posix++;
			printf("verificado\n");
			key=1;
		} else if(comd==4){
			posix--;
			printf("verificado\n");
			key=1;
		}else if(comd==8){
			posiy++;
			printf("verificado\n");
			key=1;
		}else if(comd==2){
			posiy--;
			printf("verificado\n");
			key=1;
			//sino es comando, tira el error//
		} else {
			printf("comando incorrecto\n");
			printf("introduce uno de los siguientes comandos:\n 6 Aumenta coordenada x por 1 \n 4 Reduce coordenada x por 1 \n 8 Aumenta coordenada y por 1 \n 2 Reduce coordenada y por 1\n");
			printf("introduce el comando\n");
			scanf("%d",&comd);
		}
		//condicion del while//
		}while (key!=1);
	}
//imprime los resultados//
	printf("la posicion final es x:%d y:%d",posix,posiy);
	return 0;
}
