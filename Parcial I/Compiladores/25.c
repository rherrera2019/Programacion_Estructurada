/*
Nombre: 25- Sueldo de un vendedor.c
Autor: Los Compiladores
Fecha : 6Feb19
Entradas: Numeros decimales
Salidas: Ingreso obtenido mas la comision del dia
Procedimiento General: Se ingresa el monto de las ventas en un dterminado dia para obtener el ingreso total del vendedor
*/

#include <stdio.h>
#include <conio.h>

#define SUELDO_BASE 200
#define BONO_ADICIONAL 200

int main(int argc, char *argv[]) {
	
	float Monven;
	int Dia;
	float LV;
	float S;
	float D;
	
	printf ("-->> Ingreso total del vendedor por ventas de un día <<-- \n");
	
	printf ("\n>> Ingrese el monto de sus ventas en el día: << \n");
		scanf ("%f", &Monven); /*Se ingresa el monto del dia (Entrada)*/
		printf ("\n>> Ingrese el día de la semana del 1 (Lunes) al 7 (Domingo): << \n");
			scanf ("%d", &Dia); /*Se ingresa el numero a evaluar (Entrada)*/
			
		if ( Dia >= 1 && Dia <= 7 ){ /*Se verifica que el numero ingresado sea válido*/
			
			if ( Dia ==1 ){ /*Ahora, se determina si es la primera respuesta posible*/
				printf ("\n>> El dia es LUNES."); /*Salida: Imprime si es lunes*/
				}
			if ( Dia ==2 ){ /*Ahora, se determina si es la primera respuesta posible*/
				printf ("\n>> El dia es MARTES."); /*Salida: Imprime si es martes*/
			}
			if ( Dia ==3 ){ /*Ahora, se determina si es la primera respuesta posible*/
				printf ("\n>> El dia es MIERCOLES."); /*Salida: Imprime si es miercoles*/
			}
			if ( Dia ==4 ){ /*Ahora, se determina si es la primera respuesta posible*/
				printf ("\n>> El dia es JUEVES."); /*Salida: Imprime si es jueves*/
			}
			if ( Dia ==5 ){ /*Ahora, se determina si es la primera respuesta posible*/
				printf ("\n>> El dia es VIERNES."); /*Salida: Imprime si es viernes*/
			}
			if ( Dia ==6 ){ /*Ahora, se determina si es la primera respuesta posible*/
				printf ("\n>> El dia es SABADO."); /*Salida: Imprime si es sabado*/
			}
			if ( Dia ==7 ){ /*Ahora, se determina si es la primera respuesta posible*/
				printf ("\n>> El dia es DOMINGO."); /*Salida: Imprime si es domingo*/
			}
		}
		
		if ( Monven >= 10000 ){ /*Se verifica que el numero ingresado sea válido para el bono*/
			
			if ( Dia >= 1 && Dia <= 5 ){/*Ahora, se determina si es la primera respuesta posible*/
				printf (" La comisión de venta es del 2.5 porciento mas BONO ADICIONAL de 200 \n");
				
				LV=SUELDO_BASE+BONO_ADICIONAL+((Monven*2.5)/100);/*Operaciones: del sueldo baso mas la comision del dia*/
				
				printf("\n>> Ingreso total del vendedor: %.2f \n", LV);/*Salida: Imprime el monto del dia*/
				
			}
			
			else if ( Dia == 6 ){
				printf(" La comisión de venta es del 4 porciento mas BONO ADICIONAL de 200 \n");
				
				S=SUELDO_BASE+BONO_ADICIONAL+((Monven*4)/100);
				
				printf("\n>> Ingreso total del vendedor: %.2f \n", S);
				
			}
			else{
				printf(" La comisión de venta es del 5 porciento mas BONO ADICIONAL de 200 \n");
				
				D=SUELDO_BASE+BONO_ADICIONAL+((Monven*5)/100);
				
				printf("\n>> Ingreso total del vendedor: %.2f \n", D);
				
			}
			
		}
		
		else if ( Dia >= 1 && Dia <= 5 ){
			printf (" La comisión de venta es del 2.5 porciento \n");
			
			LV=SUELDO_BASE+((Monven*2.5)/100);
			
			printf("\n>> Ingreso total del vendedor: %.2f \n", LV);
			
		}
		
		else if ( Dia == 6 ){
			printf(" La comisión de venta es del 4 porciento \n");
			
			S=SUELDO_BASE+((Monven*4)/100);
			
			printf("\n>> Ingreso total del vendedor: %.2f \n", S);
			
		}
		else{
			printf(" La comisión de venta es del 5 porciento \n");
			
			D=SUELDO_BASE+((Monven*5)/100);
			
			printf("\n>> Ingreso total del vendedor: %.2f \n", D);
			
		}
	
	getch(); /* Pausa */

	return 0;
}

//El codigo funciona bien, sin embargo, cuando se le dan valores que no se deberian aceptar, como el 0 o negativos, hace el proceso
//No imprime caracteres con acentos
//Es mas largo de lo que deberia, puede reducirse.
//Reviso: Programadores Empedernidos.

