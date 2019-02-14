/*El importe anual del seguro de un coche depende del modelo del
	vehículo, del color, de la edad del conductor y el tiempo que tiene
	conduciendo. Son tres modelos de coche (A, B y C) y los precios del
	seguro según el color:
	
	Si el conductor tiene menos de 20 años, el precio se incrementa 25%;
si tiene entre 20 y 30 años se incrementa 10%; si tiene entre 31 y 65
	años el precio no se modifica; si tiene más de 65 años el precio se
	incrementará 15%. Además, en todos los casos si el conductor tiene
	menos de 2 años conduciendo con permiso, el precio se incrementará
	25% adicional. E.P: que calcule e imprima el precio del seguro para un
	determinado modelo y un determinado conductor.
*/
/*
Nombre:32
Autor: Los Compiladores
Fecha : 6Feb19
Entradas: Cuantos años llevan manejando y la edad, aparte de la eleccion de la tabla
Salidas: Cuanto van a pagar por el seguro
Procedimiento General: Se determinara el coste de un seguro 
*/


#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int Modelo;
	float Mo;
	
	int   Digito; 
	int   Anos;
	int   AA=0;
	int   Edad;
	int  ED=0;
	
	int c=1;
	float AT=0;
	float AU=0;
	printf("\n************************************************************\n");
	printf("   |Digito| |Modelo| |Color| |Precio| |Color| |Precio|\n");
	printf("\n    1:         A      Claro    $3800   Oscuro  $4340");
	printf("\n    2:         B      Claro    $4930   Oscuro  $5600");
    printf("\n    3:         C      Claro    $7570   Oscuro  $8250");
	printf("\n************************************************************\n");
	
	//Escoje el modelo deseado
	do{
		printf("\nDime el Digito del Modelo deseado: ");
		scanf("%d",&Digito);
		
		if(Digito<4 && Digito>0){
			
			c=0;
			
		}else printf("***Digito no valido***\n");

		
	} while(c==1);
	
	printf("\n\n");
	//Valida el tiempo que lleva manejando para ver si le hacemos promocion
	c=1;
	do{
		printf("ingrese la cantidad de Años que lleva manejando con Permiso ");
		scanf("%d",&Anos);
		
		if(Anos>0 && Anos<100 ){
			if(Anos<2){
				printf("Sele aplicara un aumento del 25 porciento");
				AA=1;
				c=0;
				
			}else if(Anos!=2){
				printf("**No se les aplicara aumento por tiempo manejando**"); 
				AA=0;
				c=0;
			 
			}
			
			
		}else printf("Nadie puede tener esa Edad\n");
		
		
	} while(c==1);
	printf("\n\n");
	//solicita y valida la edad del conductor para aplicar promocion 
	do{
		c=1;
		printf("\nEdad del conductor: ");
		scanf("%d",&Edad);
		
		if(Edad<110 && Edad>0){
			
			if(Edad<20){
				
				ED=1;
				printf("Se le aplicara un 25 porciento extra \n");
				c=0;
				
			}else if(Edad>=20 && Edad<=30){
				
				ED=2;
				printf("Se le aplicara un 10 porciento extra \n");
				c=0;
				
			}else if(Edad>=31 && Edad<=65){
				
				ED=3;
				printf("no se aplica extra \n");
				c=0;
				
			}else if(Edad>65){
				
				ED=4;
				printf("Se le aplicara un 15 porciento extra \n");
				c=0;
				
			}else printf("***Digito no valido***\n");
			
			
			
			
		}else printf("***Digito no valido***\n");
		
		
	} while(c==1);
	
	
	
	printf("\n\n");
	
	
	//inicio de salidas
	
	switch(Digito){
		
	case 1:
		
		printf("\n**************************************\n");
		printf("Usted a escojodo el modelo A:\n");
		do{
			c=1;
			printf("Que Color desea\n");
			printf("1: Claro  2: oscuro\n");
			scanf("%d",&Modelo);
			
			if(Modelo==1){
				printf("\nusted a escojido el claro\n");
				Mo=3800;
				c=0;
			}else if(Modelo==2){
				printf("usted a escojido el oscuro\n");
				Mo=4340;
				c=0;
			}else printf("No hay el modelo que escojio\n");
		} while(c==1);
		
		
		if(AA==1){
			
			AU=(Mo*.25);
			
		}else if(AA!=1){
			
			AU=AU;
			
		}
		
		switch(ED){
			
		case 1:
			
			AT=(AT + (Mo*.25));
			
			break;
			
		case 2:
			
			AT=(AT + (Mo*.10));
			
			break;
			
		case 3:
			

			break;
			
		case 4:
			
			AT=(AT + (Mo*.15));
			
			break;
			
		default:
			printf("No se registro bien");
			break;
			
		}
		
		printf("%.2f,%.2f,%.2f\n",Mo, AT, AU);
		Mo = (Mo + AT + AU);
		
		
		
		//salida
		printf("\nEL seguro les va a costar :$ %.2f",Mo);
		
		printf("\n**************************************\n");
		
		break;
		
	case 2:
		
		printf("\n**************************************\n");
		printf("Usted a escojodo el modelo B:\n");
		do{
			c=1;
			printf("Que Color desea\n");
			printf("1: Claro  2: oscuro\n");
			scanf("%d",&Modelo);
			
			if(Modelo==1){
				printf("\nusted a escojido el claro\n");
				Mo=4930;
				c=0;
			}else if(Modelo==2){
				printf("usted a escojido el oscuro\n");
				Mo=5600;
				c=0;
			}else printf("No hay el modelo que escojio\n");
		} while(c==1);
		
		
		if(AA==1){
			
			AU=(Mo*.25);
			
		}else if(AA!=1){
			
			AU=AU;
			
		}
		
		switch(ED){
			
		case 1:
			
			AT=(AT + (Mo*.25));
			
			break;
			
		case 2:
			
			AT=(AT + (Mo*.10));
			
			break;
			
		case 3:
			
			
			break;
			
		case 4:
			
			AT=(AT + (Mo*.15));
			
			break;
			
		default:
			printf("No se registro bien");
			break;
			
		}
		
		printf("%.2f,%.2f,%.2f\n",Mo, AT, AU);
		Mo = (Mo + AT + AU);
		
		
		
		//salida
		printf("\nEL seguro les va a costar :$ %.2f",Mo);
		
		printf("\n**************************************\n");
		
		break;
		
	case 3:
		printf("\n**************************************\n");
		printf("Usted a escojodo el modelo C:\n");
		do{
			c=1;
			printf("Que Color desea\n");
			printf("1: Claro  2: oscuro\n");
			scanf("%d",&Modelo);
			
			if(Modelo==1){
				printf("\nusted a escojido el claro\n");
				Mo=7570;
				c=0;
			}else if(Modelo==2){
				printf("usted a escojido el oscuro\n");
				Mo=8250;
				c=0;
			}else printf("No hay el modelo que escojio\n");
		} while(c==1);
		
		
		if(AA==1){
			
			AU=(Mo*.25);
			
		}else if(AA!=1){
			
			AU=AU;
			
		}
		
		switch(ED){
			
		case 1:
			
			AT=(AT + (Mo*.25));
			
			break;
			
		case 2:
			
			AT=(AT + (Mo*.10));
			
			break;
			
		case 3:
			
			
			break;
			
		case 4:
			
			AT=(AT + (Mo*.15));
			
			break;
			
		default:
			printf("No se registro bien");
			break;
			
		}
		
		printf("%.2f,%.2f,%.2f \n",Mo, AT, AU);
		
		Mo = (Mo + AT + AU);
		
		
		
		//salida
		printf("\nEL seguro les va a costar :$ %.2f",Mo);
		
		printf("\n**************************************\n");
		
		break;
		
	default:
		printf("Error");
		
		break;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

//El codigo es legible
//Si se ingresan letras en lugar de numeros el ciclo se hace infinito
//Funciona en los casos de error "esperados"
//Reviso: Programadores Empedernidos


