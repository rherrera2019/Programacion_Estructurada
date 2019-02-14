
// Una papelería vende libros a $100, cuadernos a $15.50 y plumas a
// $2.35. E.P. que determine e imprima el monto total de una venta,
// según el número de artículos vendidos.

//Autores = programadores empedernidos.
#include <stdio.h>
#include <conio.h>
int main(){
	//Variables de cantidad de objetos
	int cuadernos, libros, plumas;
	//Variable el monto total de la venta
	float monto=0;
	
	printf("----------------PAPELERIA PEPE TO%cO----------------\n", 165);
	
	//proceso de preguntas para saber cuanto compro de cada cosa
	printf("\nCu%cntos libros compraste?\n", 160);
	scanf("%d", &libros);
	//Verifica que sea mayor a 0, para no dar errores al sumar al monto
	if (libros > 0){
		monto += (libros * 100);
	}
	
	printf("\nCu%cntos cuadernos compraste?\n", 160);
	scanf("%d", &cuadernos);
	//Verifica que sea mayor a 0, para no dar errores al sumar al monto
	if (cuadernos > 0){
		monto += (cuadernos * 15.50);
	}
	
	printf("\nCu%cntas plumas compraste?\n", 160);
	scanf("%d", &plumas);
	//Verifica que sea mayor a 0, para no dar errores al sumar al monto
	if (plumas > 0){
		monto += (plumas * 2.35);
	}
	
	//Despedida
	if (monto > 0){
		printf("Gracias por su compra, que vuelva pronto\n");
		printf("Gastaste un total de %.2f pesos en nuestros productos\n", monto);
	}
	else{
		printf("Esperamos que a la siguiente quiera comprar algo :'(\n");
	}
	
	return 0;
}
