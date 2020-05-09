#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <stdlib.h> //Conversión de tipos de datos
#include <string.h> // permite strcmp y strcpy.
#include <time.h> //Para obtener fecha y hora de la computadora

/*
Nombre: PARCIAL 1. ALUMNOS DE PROGRAMACIÓN ESTRUCTURADA
Descripción: TODOS LOS DETALLES ESTÁ EN EL DOCUMENTO
Autores: Victor Enrique Cauich Davalos & Alan Josue Barón Pat 
Version: 1.0
Fecha: 20/04/2020
*/

void ValidarUsuario();
void Cambio(char Cadena[], int Tam);
void MenuAdministrador(char Nombres[20], char Apellidos[20]);
void MenuTrabajador(char Nombres[20], char Apellidos[20]);
void CrearVenta(char Nombres[20], char Apellidos[20]);
int IngresarMarquesitas();
int IngresarIngredientes();
int IngresarEsquites();
int IngresarTostiesquites();
int IngresarToppings();
int IngresarRefrescos();
int IngresarAguas();
double CalcularPrecioMarquesitas(int Cant);
double CalcularPrecioIngredientes(int Cant);
double CalcularPrecioEsquites(int Cant);
double CalcularPrecioTostiesquites(int Cant);
double CalcularPrecioToppings(int Cant);
double CalcularPrecioRefrescos(int Cant);
double CalcularPrecioAguas(int Cant);
void VerTicket();
void VerGanancias();
void GananciasDia();
void GananciasSemana();
void GananciasMes();
int CalcularFecha(int *D, int *M, int *A);
void CambiarPrecios();
void CambiarPrecioMarquesitas();
void CambiarPrecioIngredientes();
void CambiarPrecioEsquites();
void CambiarPrecioTostiEsquites();
void CambiarPrecioToppings();
void CambiarPrecioRefrescos();
void CambiarPrecioAguas();
double ValidarPrecio();
void AgregarTrabajador();
void EliminarTrabajador();

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	
	ValidarUsuario();
	
	system("cls");
	printf("Que tenga buen día...");
	
	printf("\n\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//----------------Función para cambiar final de una Cadena---------
void Cambio(char Cadena[], int Tam)
{
	for(int i = 0; i < Tam; i++)
	{
		if(Cadena[i] == '\n')
		{
			Cadena[i] = '\0';
		}
	}
}
//-------------Validando usuario y contraseña---------------
void ValidarUsuario()
{
	system("cls");
	FILE *LOGIN;
	char *token;
	char Usuario[16];
	char Contrasenia[16];
	char Nombres[21];
	char Apellidos[21];
	bool Val = false;
	int Val1;
	char Aux[80];
	int S;
	printf("%15s", "LOGIN");
	printf("\n\n%5s%s", "", "USUARIO: ");
	fgets(Usuario, 16, stdin);
	fflush(stdin);
	Cambio(Usuario, 16);
	printf("\n%2s%s", "", "CONTRASEÑA: ");
	fgets(Contrasenia, 16, stdin);
	fflush(stdin);
	Cambio(Contrasenia, 16);
	LOGIN = fopen("Datos/LOGIN.txt", "r");
	if(LOGIN == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	rewind(LOGIN);
	fgets(Aux, 80, LOGIN);
	while(!feof(LOGIN) && Val == false)
	{
		fgets(Aux, 80, LOGIN);
		token = strtok(Aux, ",");
	    if(token != NULL){
	    	if(strcmp(Usuario, token) == 0)
	    	{
	    		token = strtok(NULL, ",");
	    		if(strcmp(Contrasenia, token) == 0)
	    		{
	    			Val = true;
	    			token = strtok(NULL, ",");
	    			if(strcmp("1", token) == 0)
	    			{
	    				Val1 = 1;
					}else
					{
						Val1 = 0;
					}
					token = strtok(NULL, ",");
					strcpy(Nombres, token);
					token = strtok(NULL, ",");
					strcpy(Apellidos, token);
				}
			}	
	    }
	}
	fclose(LOGIN);
	if(Val == true)
	{
		printf("CORRECTO");
		if(Val1 == 1)
		{
			MenuAdministrador(Nombres, Apellidos);
		}else
		{
			MenuTrabajador(Nombres, Apellidos);
		}
		
	}else
	{
		do
		{
			system("cls");
			printf("USUARIO O CONTRASEÑA INCORRECTAS, ¿DESEA SEGUIR INTENTANDO?");
			printf("\n1. SI.");
			printf("\n2. NO.");
			printf("\nIngrese el número de la selección que quiera elegir: ");
			scanf("%d", &S);
			if(S != 1 && S != 2)
			{
				printf("\n\nERROR, INGRESE UNA OPCIÓN DADA...");
				printf("\n\n\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
			}
		}while(S != 1 && S != 2);
		
		if(S == 1)
		{
			fflush(stdin);
			ValidarUsuario();
		}
	}
}
//--------------Menú del Trabajador----------------------------
void MenuTrabajador(char Nombres[21], char Apellidos[21])
{
	int Seleccion;
	do
	{
		system("cls");
		printf("%15s%-15s", "BIENVENIDO: ", Nombres);
		printf("\n%15s%-15s", "MENÚ DE T", "RABAJADOR");
		printf("\n1. Nueva Venta.");
		printf("\n2. Ver Ticket.");
		printf("\n3. Ver Ganancias.");
		printf("\n4. SALIR.");
		printf("\nIngrese el número de la opción \nque desee realizar, por favor: ");
		scanf("%d", &Seleccion);
		fflush(stdin);
		switch(Seleccion)
		{
			case 1:
				CrearVenta(Nombres, Apellidos);
				break;
			case 2:
				VerTicket();
				break;
			case 3:
				VerGanancias();
				break;
			case 4:
				system("cls");
				printf("Que tenga buen día...");
				printf("\n\n\nTeclea ENTER para salir por favor...");
				fflush(stdin);
				getchar();
				exit(1);
				break;
			default:
				system("cls");
				printf("ERROR, SELECCIÓN INVALIDA...");
				printf("\nIntente de nuevo, por favor.");
				printf("\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
				MenuTrabajador(Nombres, Apellidos);
				break;
		}
	}while(Seleccion != 4);
}
//--------------Menú del Administrador----------------------------
void MenuAdministrador(char Nombres[21], char Apellidos[21])
{
	int Seleccion;
	do
	{
		system("cls");
		printf("%15s%-15s", "BIENVENIDO: ", Nombres);
		printf("\n%15s%-15s", "MENÚ DE AD", "MINISTRADOR");
		printf("\n1. Nueva Venta.");
		printf("\n2. Ver Ticket.");
		printf("\n3. Ver Ganancias.");
		printf("\n4. Cambiar Precios.");
		printf("\n5. Agregar Trabajador.");
		printf("\n6. Eliminar Trabajador.");
		printf("\n7. SALIR.");
		printf("\nIngrese el número de la opción \nque desee realizar, por favor: ");
		scanf("%d", &Seleccion);
		fflush(stdin);
		switch(Seleccion)
		{
			case 1:
				CrearVenta(Nombres, Apellidos);
				break;
			case 2:
				VerTicket();
				break;
			case 3:
				VerGanancias();
				break;
			case 4:
				CambiarPrecios();
				break;
			case 5:
				AgregarTrabajador();
				break;
			case 6:
				EliminarTrabajador();
				break;
			case 7:
				system("cls");
				printf("Que tenga buen día...");
				printf("\n\n\nTeclea ENTER para salir por favor...");
				fflush(stdin);
				getchar();
				exit(1);
				break;
			default:
				system("cls");
				printf("ERROR, SELECCIÓN INVALIDA...");
				printf("\nIntente de nuevo, por favor.");
				printf("\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
				MenuAdministrador(Nombres, Apellidos);
				break;
		}
	}while(Seleccion != 7);
}
//------------------Función para crear una venta---------
void CrearVenta(char Nombres[21], char Apellidos[21])
{
	int CantMarquesitas = 0, CantIngredientes = 0, CantEsquites = 0, CantToppings = 0, CantTostiesquites = 0;
	int CantRefrescos = 0, CantAguas = 0, Seleccion = 0;
	bool Val = false;
	do
	{
		fflush(stdin);
		system("cls");
		printf("%15s", "SELECCIÓN DE PRODUCTOS");
		printf("\n1. Ingresar Cantidad de Marquesitas.");
		printf("\n2. Ingresar Cantidad de Ingredientes de Marquesitas.");
		printf("\n3. Ingresar Cantidad de Esquites.");
		printf("\n4. Ingresar Cantidad de Tostiesquites.");
		printf("\n5. Ingresar Cantidad de Toppings.");
		printf("\n6. Ingresar Cantidad de Refrecos.");
		printf("\n7. Ingresar Cantidad de Aguas.");
		printf("\n8. LISTO.");
		printf("\n9. CANCELAR.");
		printf("\nIngrese el número de la opción que desee realizar, \npor favor: ");
		scanf("%d", &Seleccion);
		fflush(stdin);
		system("cls");
		switch(Seleccion)
		{
			case 1:
				CantMarquesitas = IngresarMarquesitas();
				if(CantMarquesitas == 0)
				{
					CantIngredientes = 0;
				}
				break;
			case 2:
				if(CantMarquesitas < 1)
				{
					printf("ERROR, DEBE AGREGAR AL MENOS 1 MARQUESITA...");
					printf("\nTeclea ENTER para continuar, por favor...");
					fflush(stdin);
					getchar();
				}else
				{
					CantIngredientes = IngresarIngredientes();
				}
				break;
			case 3:
				CantEsquites = IngresarEsquites();
				break;
			case 4:
				CantTostiesquites = IngresarTostiesquites();
				break;
			case 5:
				CantToppings = IngresarToppings();
				break;
			case 6:
				CantRefrescos = IngresarRefrescos();
				break;
			case 7:
				CantAguas = IngresarAguas();
				break;
			case 8:
				if(CantMarquesitas == 0)
				{
					if(CantEsquites == 0)
					{
						if(CantTostiesquites == 0)
						{
							if(CantToppings == 0)
							{
								if(CantRefrescos == 0)
								{
									if(CantAguas == 0)
									{
										Seleccion = 10;
										printf("ERROR, PARA COMPLETAR LA VENTA, \nDEBE HABER AL MENOS UN PRODUCTO COMPRADO...");
										printf("\nIntente de nuevo, por favor.");
										printf("\nTeclea ENTER para continuar, por favor...");
										fflush(stdin);
										getchar();
									}
								}
							}
						}
					}
				}
				break;
			case 9:
				break;
			default:
				printf("ERROR, SELECCIÓN INVALIDA...");
				printf("\nIntente de nuevo, por favor.");
				printf("\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
				break;
		}
	}while(Seleccion != 8 && Seleccion != 9);
	
	if(Seleccion != 9)
	{
		int NumTicket;
		char Aux[15];
		FILE *Ultimo;
		Ultimo = fopen("Tickets/UltimoNoTicket.txt", "r");
		if(Ultimo == NULL)
		{
			system("cls");
			printf("¡¡ERROR!!");
			printf("\nEL ARCHIVO NO EXISTE...");
			printf("\n\n\nTeclea ENTER para salir, por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
		}
		rewind(Ultimo);
		fgets(Aux, 15, Ultimo);
		fclose(Ultimo);
		
		NumTicket = atoi(Aux) + 1;
		Ultimo = fopen("Tickets/UltimoNoTicket.txt", "w");
		if(Ultimo == NULL)
		{
			system("cls");
			printf("¡¡ERROR!!");
			printf("\nEL ARCHIVO NO EXISTE...");
			printf("\n\n\nTeclea ENTER para salir, por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
		}
		fprintf(Ultimo, "%d", NumTicket);
		fclose(Ultimo);
		
		char TOTALF[10];
		char NombreTicket[25];
		char NombreTicket2[35] = "Tickets/";
		sprintf(NombreTicket, "%d", NumTicket);
		strcat(NombreTicket, ".txt");
		strcat(NombreTicket2, NombreTicket);
		
		FILE *NewTicket;
		NewTicket = fopen(NombreTicket2, "w");
		if(NewTicket == NULL)
		{
			system("cls");
			printf("¡¡ERROR!!");
			printf("\nEL ARCHIVO NO EXISTE...");
			printf("\n\n\nTeclea ENTER para salir, por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
		}
		time_t FechaActual;
		time(&FechaActual);
		struct tm *MiFecha = localtime(&FechaActual);
		fprintf(NewTicket, "%15s%-15s", "LA MARQU", "ESITERÍA");
		fprintf(NewTicket, "\n%15s%-15d", "TICKET #", NumTicket);
		fprintf(NewTicket, "\n------------------------------");
		fprintf(NewTicket, "\nAtendió: %s %s", Nombres, Apellidos);
		fprintf(NewTicket, "\nFecha: %d/%d/%d", MiFecha->tm_mday, MiFecha->tm_mon + 1, MiFecha->tm_year + 1900);
		if(MiFecha->tm_hour < 10)
		{
			if(MiFecha->tm_min < 10)
			{
				if(MiFecha->tm_sec < 10)
				{
					fprintf(NewTicket, "\nHora: 0%d:0%d:0%d", MiFecha->tm_hour, MiFecha->tm_min, MiFecha->tm_sec);
				}else
				{
					fprintf(NewTicket, "\nHora: 0%d:0%d:%d", MiFecha->tm_hour, MiFecha->tm_min, MiFecha->tm_sec);
				}
			}else
			{
				if(MiFecha->tm_sec < 10)
				{
					fprintf(NewTicket, "\nHora: 0%d:%d:0%d", MiFecha->tm_hour, MiFecha->tm_min, MiFecha->tm_sec);
				}else
				{
					fprintf(NewTicket, "\nHora: 0%d:%d:%d", MiFecha->tm_hour, MiFecha->tm_min, MiFecha->tm_sec);
				}
			}
		}else
		{
			if(MiFecha->tm_min < 10)
			{
				if(MiFecha->tm_sec < 10)
				{
					fprintf(NewTicket, "\nHora: %d:0%d:0%d", MiFecha->tm_hour, MiFecha->tm_min, MiFecha->tm_sec);
				}else
				{
					fprintf(NewTicket, "\nHora: %d:0%d:%d", MiFecha->tm_hour, MiFecha->tm_min, MiFecha->tm_sec);
				}
			}else
			{
				if(MiFecha->tm_sec < 10)
				{
					fprintf(NewTicket, "\nHora: %d:%d:0%d", MiFecha->tm_hour, MiFecha->tm_min, MiFecha->tm_sec);
				}else
				{
					fprintf(NewTicket, "\nHora: %d:%d:%d", MiFecha->tm_hour, MiFecha->tm_min, MiFecha->tm_sec);
				}
			}
		}
		fprintf(NewTicket, "\n------------------------------");
		fprintf(NewTicket, "\n%-15s%-5s%10s", "Productos:", "Cant:", "Precio:");
		fprintf(NewTicket, "\n------------------------------");
		
		double PrecioMarquesitas, PrecioIngredientes, PrecioEsquites, PrecioToppings, PrecioTostiesquites;
		double PrecioRefrescos, PrecioAguas, TOTAL = 0;
		
		for(int i = 1; i <= 7; i++)
		{
			switch(i)
			{
				case 1:
					if(CantMarquesitas > 0)
					{
						PrecioMarquesitas = CalcularPrecioMarquesitas(CantMarquesitas);
						fprintf(NewTicket, "\n%-15s%-5d%10.2lf", "Marquesitas", CantMarquesitas, PrecioMarquesitas);
						fprintf(NewTicket, "\n------------------------------");
						TOTAL = TOTAL + PrecioMarquesitas;
					}
					break;
				case 2:
					if(CantIngredientes > 0)
					{
						PrecioIngredientes = CalcularPrecioIngredientes(CantIngredientes);
						fprintf(NewTicket, "\n%-15s%-5d%10.2lf", "Ingredientes", CantIngredientes, PrecioIngredientes);
						fprintf(NewTicket, "\n------------------------------");
						TOTAL = TOTAL + PrecioIngredientes;
					}
					break;
				case 3:
					if(CantEsquites > 0)
					{
						PrecioEsquites = CalcularPrecioEsquites(CantEsquites);
						fprintf(NewTicket, "\n%-15s%-5d%10.2lf", "Esquites", CantEsquites, PrecioEsquites);
						fprintf(NewTicket, "\n------------------------------");
						TOTAL = TOTAL + PrecioEsquites;
					}
					break;
				case 4:
					if(CantTostiesquites > 0)
					{
						PrecioTostiesquites = CalcularPrecioTostiesquites(CantTostiesquites);
						fprintf(NewTicket, "\n%-15s%-5d%10.2lf", "Tostiesquites", CantTostiesquites, PrecioTostiesquites);
						fprintf(NewTicket, "\n------------------------------");
						TOTAL = TOTAL + PrecioTostiesquites;
					}
					break;
				case 5:
					if(CantToppings > 0)
					{
						PrecioToppings = CalcularPrecioToppings(CantToppings);
						fprintf(NewTicket, "\n%-15s%-5d%10.2lf", "Toppings", CantToppings, PrecioToppings);
						fprintf(NewTicket, "\n------------------------------");
						TOTAL = TOTAL + PrecioToppings;
					}
					break;
				case 6:
					if(CantRefrescos > 0)
					{
						PrecioRefrescos = CalcularPrecioRefrescos(CantRefrescos);
						fprintf(NewTicket, "\n%-15s%-5d%10.2lf", "Refrescos", CantRefrescos, PrecioRefrescos);
						fprintf(NewTicket, "\n------------------------------");
						TOTAL = TOTAL + PrecioRefrescos;
					}
					break;
				case 7:
					if(CantAguas > 0)
					{
						PrecioAguas = CalcularPrecioAguas(CantAguas);
						fprintf(NewTicket, "\n%-15s%-5d%10.2lf", "Aguas", CantAguas, PrecioAguas);
						fprintf(NewTicket, "\n------------------------------");
						TOTAL = TOTAL + PrecioAguas;
					}
					break;
				default:
					printf("ERROR, SELECCIÓN INVALIDA...");
					printf("\nIntente de nuevo, por favor.");
					printf("\nTeclea ENTER para continuar, por favor...");
					fflush(stdin);
					getchar();
					break;
			}
		}
		sprintf(TOTALF, "$%.2lf", TOTAL);
		fprintf(NewTicket, "\n%20s%10s", "TOTAL:", TOTALF);
		fclose(NewTicket);
	}else
	{
		system("cls");
		printf("CANCELACIÓN CON ÉXITO");
		printf("\nTeclea ENTER para regresar al MENÚ, por favor...");
		fflush(stdin);
		getchar();
	}
}
//---------------Vallidación de Marquesitas---------
int IngresarMarquesitas()
{
	int Num;
	printf("Ingrese cuántas Marquesitas son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarMarquesitas();
	}
	return Num;
}
//---------------Vallidación de Ingredientes--------
int IngresarIngredientes()
{
	int Num;
	printf("Ingrese cuántos Ingredientes para Marquesitas son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarIngredientes();
	}
	return Num;
}
//---------------Vallidación de Esquites-------------
int IngresarEsquites()
{
	int Num;
	printf("Ingrese cuántos Esquites son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarEsquites();
	}
	return Num;
}
//---------------Vallidación de Tostiesquites-------
int IngresarTostiesquites()
{
	int Num;
	printf("Ingrese cuántos Tostiesquites son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarTostiesquites();
	}
	return Num;
}
//---------------Vallidación de Toppings-------------
int IngresarToppings()
{
	int Num;
	printf("Ingrese cuántos Toppings en TOTAL son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarToppings();
	}
	return Num;
}
//---------------Vallidación de Refrescos------------
int IngresarRefrescos()
{
	int Num;
	printf("Ingrese cuántos Refrescos son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarRefrescos();
	}
	return Num;
}
//---------------Vallidación de Aguas----------------
int IngresarAguas()
{
	int Num;
	printf("Ingrese cuántas Aguas son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarAguas();
	}
	return Num;
}
//--------------Calcular Precio de Marquesitas--------
double CalcularPrecioMarquesitas(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioBaseMarquesita.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fgets(Aux, 15, Costo);
	CostoP = atof(Aux);
	fclose(Costo);
	return Cant * CostoP;
}
//---------Calcular Precio de los Ingredientes--------
double CalcularPrecioIngredientes(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioIngredientesMarquesitas.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fgets(Aux, 15, Costo);
	CostoP = atof(Aux);
	fclose(Costo);
	return Cant * CostoP;
}
//--------------Calcular Precio de Esquites-----------
double CalcularPrecioEsquites(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioBaseEsquite.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fgets(Aux, 15, Costo);
	CostoP = atof(Aux);
	fclose(Costo);
	return Cant * CostoP;
}
//------------Calcular Precio de Tostiesquites--------
double CalcularPrecioTostiesquites(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioBaseTostiEsquite.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fgets(Aux, 15, Costo);
	CostoP = atof(Aux);
	fclose(Costo);
	return (Cant*CostoP);
}
//--------------Calcular Precio de Toppings-----------
double CalcularPrecioToppings(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioToppings.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fgets(Aux, 15, Costo);
	CostoP = atof(Aux);
	fclose(Costo);
	return Cant * CostoP;
}
//--------------Calcular Precio de Refrescos-----------
double CalcularPrecioRefrescos(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioRefrescos.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fgets(Aux, 15, Costo);
	CostoP = atof(Aux);
	fclose(Costo);
	return Cant * CostoP;
}
//--------------Calcular Precio de Aguas---------------
double CalcularPrecioAguas(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PreciosAguas.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fgets(Aux, 15, Costo);
	CostoP = atof(Aux);
	fclose(Costo);
	return Cant * CostoP;
}
//------------Función para ver Ticket------------------
void VerTicket()
{
	int num;
	char Name[25];
	char Name2[35] = "Tickets/";
	
	system("cls");
	printf("Ingrese el número del ticket que desea ver, por favor: ");
	scanf("%d", &num);
	fflush(stdin);
	
	sprintf(Name, "%d", num);
	strcat(Name, ".txt");
	strcat(Name2, Name);
	
	FILE *Ticket;
	Ticket = fopen(Name2, "r");
	if(Ticket != NULL)
	{
		system("cls");
		printf("ENCONTRADO, TECLEAR ENTER PARA VER EL TICKET.\n");
		fflush(stdin);
		getchar();
		system("cls");
		rewind(Ticket);
		char Aux[30];
		while(!feof(Ticket))
		{
			fgets(Aux, 30, Ticket);
			printf("%s", Aux);
		}
		fclose(Ticket);
		printf("\n\nLISTO...");
		printf("\nTeclea ENTER para regresar al MENÚ, por favor...");
		fflush(stdin);
		getchar();
	}else
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para regresar al MENÚ, por favor...");
		fflush(stdin);
		getchar();
	}
	
}
//--------------Función para ver ganancias-----------------
void VerGanancias()
{
	int Seleccion;
	system("cls");
	printf("¿CÓMO DESEA VER LAS GANANCIAS?");
	printf("\n1. De un Día.");
	printf("\n2. De una Semana (7 Días).");
	printf("\n3. De un Més (28 Días ó 4 semanas).");
	printf("\n4. Regresar al MENÚ.");
	printf("\nIngrese el número de la opción que desee realizar, \npor favor: ");
	scanf("%d", &Seleccion);
	fflush(stdin);
	system("cls");
	switch(Seleccion)
	{
		case 1:
			GananciasDia();
			break;
		case 2:
			GananciasSemana();
			break;
		case 3:
			GananciasMes();
			break;
		case 4:
			break;
		default:
			printf("ERROR, SELECCIÓN INVALIDA...");
			printf("\nIntente de nuevo, por favor.");
			printf("\nTeclea ENTER para regresar a las opciones, por favor...");
			fflush(stdin);
			getchar();
			VerGanancias();
			break;
	}
}
//--------------Ver Ganancias de un DÍA----------------
void GananciasDia()
{
	int Dia, Mes, Anio;
	char Aux[35], Fecha[30];
	int NumTicket;
	char *token;
	double Ganancia = 0;
	bool Val = false;
	
	printf("Ingrese el día, por favor: ");
	scanf("%d", &Dia);
	fflush(stdin);
	printf("Ingrese el més, por favor: ");
	scanf("%d", &Mes);
	fflush(stdin);
	printf("Ingrese el año, por favor: ");
	scanf("%d", &Anio);
	fflush(stdin);
	
	sprintf(Fecha, "%d/%d/%d", Dia, Mes, Anio);
	
	
	FILE *Ultimo;
	Ultimo = fopen("Tickets/UltimoNoTicket.txt", "r");
	if(Ultimo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	rewind(Ultimo);
	fgets(Aux, 30, Ultimo);
	fclose(Ultimo);
	
	NumTicket = atoi(Aux);
	
	for(int i = 1; i <= NumTicket; i++)
	{
		strcpy(Aux,"");
		sprintf(Aux, "Tickets/%d.txt", i);
		
		FILE *Archivo;
		Archivo = fopen(Aux, "r");
		if(Archivo == NULL)
		{
			system("cls");
			printf("¡¡ERROR!!");
			printf("\nEL ARCHIVO NO EXISTE...");
			printf("\n\n\nTeclea ENTER para salir, por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
		}
		
		fgets(Aux, 35, Archivo);
		fgets(Aux, 35, Archivo);
		fgets(Aux, 35, Archivo);
		fgets(Aux, 35, Archivo);
		fgets(Aux, 35, Archivo);
		
		token = strtok(Aux, " ");
		token = strtok(NULL, "\n");
		
		if(strcmp(Fecha, token) == 0)
		{
			Val = true;
			
			while(!feof(Archivo))
			{
				fgets(Aux, 35, Archivo);
			}
			
			token = strtok(Aux, "$");
			token = strtok(NULL, "\n");
			
			Ganancia = Ganancia + atof(token);
		}
		
		fclose(Archivo);
	}
	
	system("cls");
	
	if(Val == true)
	{
		printf("SE ENCONTRÓ LA GANANCIA DE LA FECHA: %s.", Fecha);
		printf("\nLA GANANCIA ES: %.2lf.", Ganancia);
	}else
	{
		printf("NO SE ENCONTRÓ LA GANANCIA DE LA FECHA: %s.", Fecha);
	}
	
	printf("\n\n\nTeclea ENTER para regresar al MENÚ, por favor...");
	fflush(stdin);
	getchar();
}
//--------------Ver Ganancias de una SEMANA------------
void GananciasSemana()
{
	int Dia, Mes, Anio;
	char Aux[35], FechaI[30], FechaF[30];
	int NumTicket;
	char *token;
	double Ganancia = 0;
	bool Val = false;
	
	printf("INGRESE PRIMERO LA FECHA DEL INICIO DE LA SEMANA");
	printf("\nAPARTIR DE LA FECHA QUE INGRESE EMPEZAREMOS A CONTAR");
	printf("\nLOS 7 DÍAS DE LA SEMANA.");
	printf("\n\nIngrese el día, por favor: ");
	scanf("%d", &Dia);
	fflush(stdin);
	printf("Ingrese el més, por favor: ");
	scanf("%d", &Mes);
	fflush(stdin);
	printf("Ingrese el año, por favor: ");
	scanf("%d", &Anio);
	fflush(stdin);
	
	sprintf(FechaI, "%d/%d/%d", Dia, Mes, Anio);
	
	FILE *Ultimo;
	Ultimo = fopen("Tickets/UltimoNoTicket.txt", "r");
	if(Ultimo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	rewind(Ultimo);
	fgets(Aux, 30, Ultimo);
	fclose(Ultimo);
	
	
	NumTicket = atoi(Aux);
	
	
	for(int t = 0; t < 7; t++)
	{
		
		sprintf(FechaF, "%d/%d/%d", Dia, Mes, Anio);
		
		for(int i = 1; i <= NumTicket; i++)
		{
			strcpy(Aux,"");
			sprintf(Aux, "Tickets/%d.txt", i);
			
			FILE *Archivo;
			Archivo = fopen(Aux, "r");
			if(Archivo == NULL)
			{
				system("cls");
				printf("¡¡ERROR!!");
				printf("\nEL ARCHIVO NO EXISTE...");
				printf("\n\n\nTeclea ENTER para salir, por favor...");
				fflush(stdin);
				getchar();
				exit(-1);
			}
			
			fgets(Aux, 35, Archivo);
			fgets(Aux, 35, Archivo);
			fgets(Aux, 35, Archivo);
			fgets(Aux, 35, Archivo);
			fgets(Aux, 35, Archivo);
			
			token = strtok(Aux, " ");
			token = strtok(NULL, "\n");
			
			if(strcmp(FechaF, token) == 0)
			{
				Val = true;
				
				while(!feof(Archivo))
				{
					fgets(Aux, 35, Archivo);
				}
				
				token = strtok(Aux, "$");
				token = strtok(NULL, "\n");
				
				Ganancia = Ganancia + atof(token);
			}
			
			fclose(Archivo);
		}
		
		CalcularFecha(&Dia, &Mes, &Anio);
		
	}
	
	
	system("cls");
	
	if(Val == true)
	{
		printf("SE ENCONTRÓ LA GANANCIA ENTRE LAS FECHAS: %s Y %s.", FechaI, FechaF);
		printf("\nLA GANANCIA ES: %.2lf.", Ganancia);
	}else
	{
		printf("NO SE ENCONTRARON GANANCIAS POR LA FECHA INDICADA, VERIFIQUE MEJOR, PORFAVOR...");
	}
	
	printf("\n\n\nTeclea ENTER para regresar al MENÚ, por favor...");
	fflush(stdin);
	getchar();
}
//--------------Ver Ganancias de un MES----------------
void GananciasMes()
{
	int Dia, Mes, Anio;
	char Aux[35], FechaI[30], FechaF[30];
	int NumTicket;
	char *token;
	double Ganancia = 0;
	bool Val = false;
	
	printf("INGRESE PRIMERO LA FECHA DEL INICIO DE LA SEMANA");
	printf("\nAPARTIR DE LA FECHA QUE INGRESE EMPEZAREMOS A CONTAR");
	printf("\nLOS 28 DÍAS Ó 4 SEMANAS.");
	printf("\n\nIngrese el día, por favor: ");
	scanf("%d", &Dia);
	fflush(stdin);
	printf("Ingrese el més, por favor: ");
	scanf("%d", &Mes);
	fflush(stdin);
	printf("Ingrese el año, por favor: ");
	scanf("%d", &Anio);
	fflush(stdin);
	
	sprintf(FechaI, "%d/%d/%d", Dia, Mes, Anio);
	
	FILE *Ultimo;
	Ultimo = fopen("Tickets/UltimoNoTicket.txt", "r");
	if(Ultimo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	rewind(Ultimo);
	fgets(Aux, 30, Ultimo);
	fclose(Ultimo);
	
	
	NumTicket = atoi(Aux);
	
	
	for(int t = 0; t < 28; t++)
	{
		
		sprintf(FechaF, "%d/%d/%d", Dia, Mes, Anio);
		
		for(int i = 1; i <= NumTicket; i++)
		{
			strcpy(Aux,"");
			sprintf(Aux, "Tickets/%d.txt", i);
			
			FILE *Archivo;
			Archivo = fopen(Aux, "r");
			if(Archivo == NULL)
			{
				system("cls");
				printf("¡¡ERROR!!");
				printf("\nEL ARCHIVO NO EXISTE...");
				printf("\n\n\nTeclea ENTER para salir, por favor...");
				fflush(stdin);
				getchar();
				exit(-1);
			}
			
			fgets(Aux, 35, Archivo);
			fgets(Aux, 35, Archivo);
			fgets(Aux, 35, Archivo);
			fgets(Aux, 35, Archivo);
			fgets(Aux, 35, Archivo);
			
			token = strtok(Aux, " ");
			token = strtok(NULL, "\n");
			
			if(strcmp(FechaF, token) == 0)
			{
				Val = true;
				
				while(!feof(Archivo))
				{
					fgets(Aux, 35, Archivo);
				}
				
				token = strtok(Aux, "$");
				token = strtok(NULL, "\n");
				
				Ganancia = Ganancia + atof(token);
			}
			
			fclose(Archivo);
		}
		
		CalcularFecha(&Dia, &Mes, &Anio);
		
	}
	
	
	system("cls");
	
	if(Val == true)
	{
		printf("SE ENCONTRÓ LA GANANCIA ENTRE LAS FECHAS: %s Y %s.", FechaI, FechaF);
		printf("\nLA GANANCIA ES: %.2lf.", Ganancia);
	}else
	{
		printf("NO SE ENCONTRARON GANANCIAS POR LA FECHA INDICADA, VERIFIQUE MEJOR, PORFAVOR...");
	}
	
	printf("\n\n\nTeclea ENTER para regresar al MENÚ, por favor...");
	fflush(stdin);
	getchar();
}
//-----------------Calcular Fecha---------------------------
int CalcularFecha(int *D, int *M, int *A)
{
	if ( *A % 4 == 0 && *A % 100 != 0 || *A % 400 == 0 )
	{
		switch(*M)
		{
			case 1:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 2:
				if(*D == 29)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 3:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 4:
				if(*D == 30)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 5:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 6:
				if(*D == 30)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 7:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 8:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 9:
				if(*D == 30)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 10:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 11:
				if(*D == 30)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 12:
				if(*D == 31)
				{
					*D = 1;
					*M = 1;
					*A = *A + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
		}
	}else
	{
		switch(*M)
		{
			case 1:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 2:
				if(*D == 28)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 3:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 4:
				if(*D == 30)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 5:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 6:
				if(*D == 30)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 7:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 8:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 9:
				if(*D == 30)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 10:
				if(*D == 31)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 11:
				if(*D == 30)
				{
					*D = 1;
					*M = *M + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
			case 12:
				if(*D == 31)
				{
					*D = 1;
					*M = 1;
					*A = *A + 1;
				}else
				{
					*D = *D + 1;
				}
				break;
		}
	}
}
//----------------Cambiar los Precios------------------------
void CambiarPrecios()
{
	int Seleccion;
	system("cls");
	printf("Elija de cuál producto quiere cambiar precios.");
	printf("\n1. Marquesitas.");
	printf("\n2. Ingredientes de Marquesitas.");
	printf("\n3. Esquites.");
	printf("\n4. TostiEsquites.");
	printf("\n5. Toppings.");
	printf("\n6. Refrescos.");
	printf("\n7. Aguas.");
	printf("\n8. Regresar al MENÚ.");
	printf("\nIngrese el número de la opción \nque desee realizar, por favor: ");
	scanf("%d", &Seleccion);
	fflush(stdin);
	system("cls");
	switch(Seleccion)
	{
		case 1:
			CambiarPrecioMarquesitas();
			break;
		case 2:
			CambiarPrecioIngredientes();
			break;
		case 3:
			CambiarPrecioEsquites();
			break;
		case 4:
			CambiarPrecioTostiEsquites();
			break;
		case 5:
			CambiarPrecioToppings();
			break;
		case 6:
			CambiarPrecioRefrescos();
			break;
		case 7:
			CambiarPrecioAguas();
			break;
		case 8:
			break;
		default:
			printf("ERROR, SELECCIÓN INVALIDA...");
			printf("\nIntente de nuevo, por favor.");
			printf("\nTeclea ENTER para continuar, por favor...");
			fflush(stdin);
			getchar();
			CambiarPrecios();
			break;
	}
}
//-----------------Cambiar Precio Marquesitas-----------
void CambiarPrecioMarquesitas()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioBaseMarquesita.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//-----------------Cambiar Precio Ingredientes-----------
void CambiarPrecioIngredientes()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioIngredientesMarquesitas.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//-----------------Cambiar Precio Esquites---------------
void CambiarPrecioEsquites()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioBaseEsquite.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//-----------------Cambiar Precio TostiEsquites-----------
void CambiarPrecioTostiEsquites()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioBaseTostiEsquite.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//-----------------Cambiar Precio Toppings----------------
void CambiarPrecioToppings()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioToppings.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//-----------------Cambiar Precio Refrescos---------------
void CambiarPrecioRefrescos()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioRefrescos.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//-----------------Cambiar Precio Aguas-------------------
void CambiarPrecioAguas()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PreciosAguas.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//------------------Validar Precio-------------------------
double ValidarPrecio()
{
	double Num;
	printf("Ingrese precio nuevo, por favor: ");
	scanf("%lf", &Num);
	
	if(Num < 0)
	{
		system("cls");
		printf("ERROR, DEBE SER MAYOR IGUA O MAYOR QUE 0...");
		printf("\nINTENTE DE NUEVO...");
		printf("\nTeclea ENTER para continuar, por favor...");
		fflush(stdin);
		getchar();
		Num = ValidarPrecio();
	}
	return Num;
}
//----------------Agregar Trabajador----------------------
void AgregarTrabajador()
{
	system("cls");
	
	char Usuario[16];
	char Contrasenia[16];
	int Admin;
	char Nombres[21];
	char Apellidos[21];
	FILE *LOGIN;
	char *token;
	char Aux[80];
	bool Val = false;
	int S;
	
	printf("%37s%-38s", "INGRESO DE ", "TRABAJADOR");
	
	printf("\nIngrese el nuevo Usuario (Solo se contarán los primeros 15 carácteres): \n");
	fgets(Usuario, 16, stdin);
	Cambio(Usuario, 16);
	
	LOGIN = fopen("Datos/LOGIN.txt", "r");
	if(LOGIN == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	
	rewind(LOGIN);
	
	fgets(Aux, 80, LOGIN);
	
	while(!feof(LOGIN) && Val == false)
	{
		fgets(Aux, 80, LOGIN);
		token = strtok(Aux, ",");
	    if(token != NULL){
	    	if(strcmp(Usuario, token) == 0)
	    	{
	    		Val = true;
			}	
	    }
	}
	fclose(LOGIN);
	
	if(Val == true)
	{
		do
		{
			system("cls");
			printf("USUARIO YA EXISTE, ¿DESEA SEGUIR INTENTANDO?");
			printf("\n1. SI.");
			printf("\n2. NO.");
			printf("\nIngrese el número de la selección que quiera elegir: ");
			scanf("%d", &S);
			if(S != 1 && S != 2)
			{
				printf("\n\nERROR, INGRESE UNA OPCIÓN DADA...");
				printf("\n\n\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
			}
		}while(S != 1 && S != 2);
		
		if(S == 1)
		{
			fflush(stdin);
			AgregarTrabajador();
		}
	}else
	{
		printf("\nIngrese su contraseña (Solo se contarán los primeros 15 carácteres): ");
		fgets(Contrasenia, 16, stdin);
		Cambio(Contrasenia, 16);
		printf("\nIngrese su(s) Nombre(s): ");
		fgets(Nombres, 21, stdin);
		Cambio(Nombres, 21);
		printf("\nIngrese su(s) Apellido(s): ");
		fgets(Apellidos, 21, stdin);
		Cambio(Apellidos, 21);
		do
		{
			system("cls");
			printf("¿El nuevo trabajador, va a ser administrador?");
			printf("\n1. SI.");
			printf("\n2. NO.");
			printf("\nIngrese el número de la selección que quiera elegir: ");
			scanf("%d", &S);
			if(S != 1 && S != 2)
			{
				printf("\n\nERROR, INGRESE UNA OPCIÓN DADA...");
				printf("\n\n\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
			}
		}while(S != 1 && S != 2);
		
		if(S == 2)
		{
			S = 0;
		}
		
		LOGIN = fopen("Datos/LOGIN.txt", "a");
		if(LOGIN == NULL)
		{
			system("cls");
			printf("¡¡ERROR!!");
			printf("\nEL ARCHIVO NO EXISTE...");
			printf("\n\n\nTeclea ENTER para salir por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
		}
		
		fprintf(LOGIN, "\n%s,%s,%d,%s,%s,", Usuario, Contrasenia, S, Nombres, Apellidos);
		fclose(LOGIN);
		system("cls");
		printf("LISTO");
		printf("\n\n\nTeclea ENTER para volver al MENÚ, por favor...");
		fflush(stdin);
		getchar();
	}
}
//----------------Eliminar Trabajador----------------------
void EliminarTrabajador()
{
	system("cls");
	
	char Usuario[16];
	FILE *LOGIN;
	FILE *NEWLOGIN;
	char *token;
	char Aux[80], Aux2[80];
	bool Val = false;
	int S;
	
	printf("%37s%-38s", "ELIMINACIÓN D", "E TRABAJADOR");
	
	printf("\nIngrese el Usuario a eliminar (Solo se contarán los primeros 15 carácteres): \n");
	fgets(Usuario, 16, stdin);
	Cambio(Usuario, 16);
	
	LOGIN = fopen("Datos/LOGIN.txt", "r");
	NEWLOGIN = fopen("Datos/LOGINTEMP.txt", "w");
	
	if(LOGIN == NULL || NEWLOGIN == NULL)
	{
		system("cls");
		printf("¡¡ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	
	rewind(LOGIN);
	
	fgets(Aux, 80, LOGIN);
	Cambio(Aux, 80);
	fprintf(NEWLOGIN,Aux);
	
	while(!feof(LOGIN))
	{
		fgets(Aux, 80, LOGIN);
		strcpy(Aux2, Aux);
		token = strtok(Aux, ",");
	    if(token != NULL){
	    	if(strcmp(Usuario, token) == 0)
	    	{
	    		Val = true;
			}else
			{
				Cambio(Aux2, 80);
				fprintf(NEWLOGIN, "\n%s", Aux2);
			}
	    }
	}
	fclose(LOGIN);
	fclose(NEWLOGIN);
	
	remove("Datos/LOGIN.txt");
	
	rename("Datos/LOGINTEMP.txt", "Datos/LOGIN.txt");
	
	if(Val == true)
	{
		system("cls");
		printf("LISTO");
		printf("\n\n\nTeclea ENTER para volver al MENÚ, por favor...");
		fflush(stdin);
		getchar();
		
	}else
	{
		
		do
		{
			system("cls");
			printf("USUARIO NO EXISTE, ¿DESEA SEGUIR INTENTANDO?");
			printf("\n1. SI.");
			printf("\n2. NO.");
			printf("\nIngrese el número de la selección que quiera elegir: ");
			scanf("%d", &S);
			if(S != 1 && S != 2)
			{
				printf("\n\nERROR, INGRESE UNA OPCIÓN DADA...");
				printf("\n\n\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
			}
		}while(S != 1 && S != 2);
		
		if(S == 1)
		{
			fflush(stdin);
			EliminarTrabajador();
		}
	}
}

















