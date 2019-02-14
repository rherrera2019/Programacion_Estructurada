/*
27 E.P. que lea el peso en gramos (máximo 5,000) y determine e imprima 
el menor número de pesas que hay que poner en una balanza
(con pesos: 1 gr, 2 gr, 5 gr, 50 gr, 100 gr, 200 gr, 500 gr y 1000 gr),
para equilibrar un determinado peso en gramos, introducido por teclado.

Nombre:27
Autor: Los Compiladores
Fecha : 6Feb19
Entradas: peso en gramos
Salidas: el menor número de pesas que hay que poner en una balanza
Procedimiento General: Sequilibrar un determinado peso en gramos, introducido por teclado.



*/
#include <stdio.h>

int main() {
	
	
	int peso,C1,C2,C3,C4,C5,C6,C7,C8;
	
	C1=C2=C3=C4=C5=C6=C7=C8=0;
	//definimos las variables a utilizar y los contadores
	
	printf("\n Ingrese el peso en gramos (maximo 5,000):");
	scanf("%d",&peso);
	//se pide ingresar el valor del peso y se lee y guarda en la variable con el mismo conmbre
	
	//se valida el dato ingresado
	while(peso>5000 || peso<0){
		if(peso>5000){
			printf("\n El valor ingresado supera el maximo (5000gr), ingrese nuevamente: ");
			scanf("%d",&peso);
		}else if(peso<0){
			printf("\n El valor ingresado no es valido, ingrese nuevamente: ");
			scanf("%d",&peso);
		}
	};
	
	/*una vez validado,se determina que pesa se va a usar,haciendo uso de los contadores
	se determinan las veces que se usa esa pesa.
	*/
	while(peso>0){
		
		if(peso>=1000){
			peso=peso-1000;
			C1=C1+1;
		}else if( peso>=500){
			peso=peso-500;
			C2=C2+1;
			
		}else if(peso>=200){
			peso=peso-200;
			C3=C3+1;
			
		}else if(peso>=100){
			peso=peso-100;
			C4=C4+1;
			
		}else if(peso>=50){
			peso=peso-50;
			C5=C5+1;
			
		}else if(peso>=5){
			peso=peso-5;
			C6=C6+1;
			
		}else if(peso>=2){
			peso=peso-2;
			C7=C7+1;
			
		}else if(peso>=1){
			peso=peso-1;
			C8=C8+1;
		}
		
		
	}
	
	
	//Se muestra un mensaje con las pesas y sus respectivas cantidades
	printf("\n Usted necesita colocar las siguientes pesas:");
	printf("\n Pesa de 1000 gr: %d",C1);
	printf("\n Pesa de 500 gr: %d",C2);
	printf("\n Pesa de 200 gr: %d",C3);
	printf("\n Pesa de 100 gr: %d",C4);
	printf("\n Pesa de 50 gr: %d",C5);
	printf("\n Pesa de 5 gr: %d",C6);
	printf("\n Pesa de 2 gr: %d",C7);
	printf("\n Pesa de 1 gr: %d",C8);
	printf("\n Peso: %d" ,peso);
	
	
	return 0;
	
	
}

//El codigo funciona bien, y rechaza numeros no admitidos
//Es legible y entendible
//Reviso: Programadores Empedernidos
