
//Un vendedor tiene un sueldo base por día de 200 pesos y recibe
//una comisión por venta, que se determina considerando lo siguiente:
//a) Para sus ventas de lunes a viernes, la comisión de venta es el 2.5%
//del monto total de sus ventas.
//b) Para sus ventas de sábado, la comisión es del 4%.
//c) Para sus ventas de domingo, la comisión es del 5%.

//Además, si el monto de sus ventas en un día es mayor a $10,000.00
//tiene un bono adicional de 200 pesos. E.P. que lea las ventas de un
//día, calcule e imprima el ingreso total del vendedor.

//Autores = programadores empedernidos.
#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(){
	//Variables del dia
	char dia[15];
	//variables del sueldo del empleado y las ventas que genero ese dia
	float sueldo, ventas;
	
	printf("Qu%c dia es hoy? Por favor escribelo sin mayusculas ni acentos\n", 130);
	//pregunta el dia
	gets(dia);
	printf("cu%cnto fue tu monto de ventas?", 160);
	scanf("%f", &ventas);
		
	if(ventas > 10000){
		sueldo = 400;
	}
	else{
		sueldo = 200;
	}
	
	if (strcmp(dia,"domingo") == 0 ){ //Se usa la funcion strcmp() para comparar el string
		sueldo += (ventas * .05);
	}
	else if (strcmp(dia,"sabado") == 0 ){
		sueldo += (ventas * .04);
	}
	else {
		sueldo += (ventas * .025);
	}
	
	printf("El dia de hoy, tu sueldo es de %.3f pesos", sueldo);
	
	return 0;
}
