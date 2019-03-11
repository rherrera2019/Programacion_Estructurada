/* 2_Laboratorio4. Un restaurante ofrece hamburguesas sencillas, dobles y triples, 
las cuales tienen un costo de $60.00, $80.00 y $100.00, respectivamente.
 La empresa acepta tarjetas de crédito con un cargo adicional de 3% sobre la compra. 
Los clientes pueden hacer su pedido con cualquier cantidad de hamburguesas de los tipos que deseen comer.  
E.P. para determinar cuánto debe pagar cada uno de los N clientes que llegan al establecimiento. 
También, al final del día, se requiere imprimir el monto total de las ventas y el total de las comisiones por tarjeta de crédito.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 14/feb/2019
Version: 1.0 */

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	
	/*Creamos las variables necesarias para el programa*/
	int cont_clientes, numero_hamburguesas, letra_no_valida, clientes;
	
	char hamburguesa, validar[2];
	
	float total_pagar, total_pagar_general;
	
	/*Inicializamos las variables*/
	
	total_pagar = 0;
	total_pagar_general = 0;
	
	letra_no_valida = 0; //Esta variable nos ayuda a NO mostrar el pago total cuando se inserta una letra no válida.
	
	
	/*Mostramos un pequeño menú*/
	printf("\nS.- Hambueguesa sencilla");
	printf("\nD.- Hambueguesa doble");
	printf("\nT.- Hambueguesa triple");
	
	/*Preguntamos el número de clientes*/
	printf("\n\n¿Cuál es el número de clientes? ");
	scanf("%i", &clientes);
	
	/*Creamos el ciclo for para la lectura de los N clientes*/
	for (cont_clientes = 1; cont_clientes <= clientes; cont_clientes++)
	{
		/*ENTRADA DE DATOS para el número de hamburguesas que el cliente desea*/
		printf("\n\nCliente N° %i, ¿Cuál hamburguesa desea? ", cont_clientes);
		fflush(stdin); //Limpiamos el caracter que se insertó anteriormente.
		scanf("%c", &hamburguesa);
		
		/*PROCESO DE LOS DATOS según el tipo de hamburguesa que el cliente desea*/
		switch(hamburguesa)
		{
			
		case 'S':
		case 's':
			
			printf("\n\n¿Cuántas hamburguesas sencillas desea? ");
			scanf("%i", &numero_hamburguesas);
			
			total_pagar += numero_hamburguesas * 60;
			
			break;
			
		case 'D':
		case 'd':
			
			printf("\n\n¿Cuántas hamburguesas dobles desea? ");
			scanf("%i", &numero_hamburguesas);
			
			total_pagar += numero_hamburguesas * 80;
			
			break;
			
		case 'T':
		case 't':
			
			printf("\n\n¿Cuántas hamburguesas triples desea? ");
			scanf("%i", &numero_hamburguesas);
			
			total_pagar += numero_hamburguesas * 100;
			
			break;
			
		default:
			
			printf("\n\nInsertó una letra NO válida");
			
			letra_no_valida = 1; //Si se insertó una letra no válida, el código escrito después del switch no se mostrará
			
			cont_clientes--; //Disminuimos el contador para que no se salte al cliente y vuelva a tomar su orden
			
		}
		
		if (letra_no_valida == 0)
		{
			/*Preguntamos si el cliente desea algo más*/
			printf("\n\n¿Desea algo más? (si o no) ");
			fflush(stdin); //Limpiamos la validación que se insertó anteriormente.
			gets(validar);
			
			if (strcmp(validar, "no") == 0)
			{
				/*SALIDA DE DATOS para el total a pagar del cliente actual*/
				printf("\n\nEl pago total es de: %.2f", total_pagar);
				
				total_pagar_general += total_pagar;
				
				total_pagar = 0;
				
			} else
			{
				cont_clientes--; //Disminuimos el contador para que no se salte al cliente y vuelva a tomar su orden
				
			}
			
		} else
		{
			letra_no_valida = 0; //La variable se reiniciará cada vez que se inserte una letra NO válida
		}
	}
	
	/*SALIDA DE DATOS para lo recaudado en general*/
	printf("\n\nLo recaudado por todos los clientes fue: %.2f", total_pagar_general);

	getch(); //Esperar un caracter del teclado
	
	return 0;
}
/* Calificó: Punto C
-Funciona correctamente, compila y realiza lo que se escribe en el código
sin tomar en cuenta que la lectura del dato sea alguno de los 
planteados (en algunas partes si valida).Si se plantean 7 hamburguesas triples arroja
el resultado correcto de 700 pesos.
-Cuando pregunta por el número de hamburguesas no valida que sea un dato
-Tampoco valida que sea un nuero mayor a cero cuando pregunta por el
número de clientes, al preguntar si se quiere algo más tampoco valida que 
la respuesta sea alguna de las dos.
mayor o igual a cero 
-no pide ni calcula la opción de pago con tarjeta 
-Tampoco calcula en total de comisiones por pagon hechos con tarjeta.
*/
