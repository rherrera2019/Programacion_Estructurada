#include <stdio.h> //FUNCI�N PARA ENTRADAS Y SALIDAS
#include <locale.h> //Para las acentuaciones
#include <stdlib.h> //Conversi�n de tipos de datos
#include <string.h> // permite strcmp y strcpy.
#include <time.h> //Para obtener fecha y hora de la computadora

/*
Nombre: PARCIAL 1. ALUMNOS DE PROGRAMACI�N ESTRUCTURADA
Descripci�n: TODOS LOS DETALLES EST� EN EL DOCUMENTO
Autores: Victor Enrique Cauich Davalos & Alan Josue Bar�n Pat 
Version: 1.0
Fecha: 20/04/2020
*/

//PROTOTIPOS DE LAS FUNCIONES A USAR
void ValidarUsuario();
void Cambio(char Cadena[], int Tam);
void Cambio2(char Cadena[], int Tam);
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

//----------------------------FUNCI�N MAIN-------------------------
int main (){
	setlocale(LC_ALL,"");//Se aplica la funci�n de la biblioteca locale para que se puedan imprimir acentuaciones...
	
	//SOLO LLAMAMOS A LA FUNCI�N PARA QUE EL USUARIO PUEDA INTENTAR ACCEDER
	ValidarUsuario();
	
	system("cls");
	printf("Que tenga buen d�a...");
	
	printf("\n\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//----------------Funci�n para cambiar final de una Cadena---------
void Cambio(char Cadena[], int Tam)
{
	//NOSOTROS USAMOS fgets para leer, y para no tener problemas, usamos esta 
	//funci�n para cambiar el \n del fgets a un \0.
	for(int i = 0; i < Tam; i++)
	{
		if(Cadena[i] == '\n')//Se recorre cada car�cter del array hasta llegar al \n 
		{
			Cadena[i] = '\0';//Aqu+i cambiamos el \n a \0
		}
	}
}
//----------------Funci�n para cambiar final de una Cadena---------
void Cambio2(char Cadena[])
{
	for(int i = 0; i < 10; i++)
	{
		if(Cadena[i] == ' ')
		{
			Cadena[i] = '\0';
			i = 10;
		}else
		{
			if(Cadena[i] == '\0')
			{
				i = 10;
			}else
			{
				if(i+1 == 10)
				{
					Cadena[i] = '\0';
				}
			}
		}
	}
}
//--------------------Validando usuario y contrase�a---------------
void ValidarUsuario()
{
	system("cls");//Esta funci�n nos sirve para borrar la consola en Windows
	
	//DECLARAMOS LAS VARIABLES QUE NOS VAN A SERVIR
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
	
	//IMPRIMIMOS EL LOGIN
	printf("%15s", "LOGIN");
	printf("\n\n%5s%s", "", "USUARIO: ");
	fgets(Usuario, 16, stdin);//fgets va a tomar informaci�n por el consolador pero solo 16 car�cteres
	fflush(stdin);//Limpiamos el scaner del consolador
	Cambio(Usuario, 16);//Llamamos a la funci�n antes mencionada Cambio para cambiar el salto de linea que nos da fgets
	printf("\n%2s%s", "", "CONTRASE�A: ");
	fgets(Contrasenia, 16, stdin);//fgets va a tomar informaci�n por el consolador pero solo 16 car�cteres
	fflush(stdin);//Limpiamos el scaner del consolador
	Cambio(Contrasenia, 16);//Llamamos a la funci�n antes mencionada Cambio para cambiar el salto de linea que nos da fgets
	
	//Se abre un archivo y se guarda en el apuntador FILE 
	LOGIN = fopen("Datos/LOGIN.txt", "r");
	if(LOGIN == NULL)//SI NO LE DEVOLVI� NADA AL APUNTADOR ES DECIR, SI EL ARCHIVO NO EXITEN ENTRA A LAS SENTENCIAS
	{
		//SE IMPRIME QUE HUBO UN ERROR
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir por favor...");
		fflush(stdin);
		getchar();
		exit(-1);//SE CIERRA EL PROGRAMA
	}
	
	//SI ES QUE SI SE PUDO ABRIR CORRECTAMENTE EL ARCHIVO ENTONCES...
	rewind(LOGIN);//Se sit�a el cursor de lectura/escritura al principio del archivo
	fgets(Aux, 80, LOGIN);//Se ignora la primera fila del archivo 
	while(!feof(LOGIN) && Val == false) //Mientras no se termine el archivo y no se encuentre los datos del usuario, no sale del while
	{
		fgets(Aux, 80, LOGIN);//Se va tomando cada fila del archivo
		token = strtok(Aux, ",");//Se realizan token con separaci�n de ","
		
	    if(token != NULL){//Si a el token le devuelven nada o "NULL" no entra a las sentencias en el if
	    
	    	if(strcmp(Usuario, token) == 0)//Comparamos el primer dato del la linea con el usuario que se ingres�, si coincide entra en las sentencias de if
	    	{
	    		token = strtok(NULL, ",");//Se toma el siente apartado de la fila 
	    		
	    		if(strcmp(Contrasenia, token) == 0)//Comparamos el segundo dato del la linea con la contrase�a que se ingres�, si coincide entra en las sentencias de if
	    		{
	    			Val = true;//Se confirma que ya que encontr� el usuario, para que ya no continue con el if
	    			
	    			token = strtok(NULL, ",");//Se toma el siguiente dato de la linea 
	    			
	    			if(strcmp("1", token) == 0)//Se verifica si es administrador o no
	    			{
	    				Val1 = 1;//Si es administrador, se pobe que Val1 es igual a 1 para saber y nos sirva mas adelante
					}else
					{
						Val1 = 0;//Si NO es administrador, se pobe que Val1 es igual a 0 para saber y nos sirva mas adelante
					}
					
					token = strtok(NULL, ",");//Se toma el siguiente valor de la linea que son los Nombres del usuario
					strcpy(Nombres, token);//Se agregan al Array Nombres
					token = strtok(NULL, ",");//Se toma el siguiente valor de la linea que son sus Apellidos del usuario
					strcpy(Apellidos, token);//Se agregan al Array Apellidos
				}
			}	
	    }
	}
	
	
	fclose(LOGIN);//SE CIERRA EK ARCHIVO PARA NO PERDER DATOS O QUE SUCEDA ALG�N ERROR
	
	if(Val == true)//Se verifica que se hayan encontrados los datos del usuario que intenta acceder, si Val es true significa que si se encontr�, as� que si es as�, entra en las sentecias del if
	{
		
		if(Val1 == 1)//Aqu� se verifica si el usuario que accedi� es Administrador, por eso si Val1 es 1 entonces entra a la senetncia del if
		{
			MenuAdministrador(Nombres, Apellidos);//Se manda al usuario al men� de un administrador, llamando a la funci�n MenuAdministrador
		}else//Sino es administrador, entonces entra a la siguiente sentencia
		{
			MenuTrabajador(Nombres, Apellidos);//Se manda al usuario al men� de un Trabajador, llamando a la funci�n MenuTrabajador
		}
		
	}else//Si no se encontr� la informaci�n de usuario y contrase�a se entra a las siguientes sentencias
	{
		do
		{ //Todas las siguientes sentencias se ejecutaran mientras se realiza una pregunta y no se ingrese alguna de las dos opciones aceptables
			system("cls");//Se limpia la pantalla de la consola
			printf("USUARIO O CONTRASE�A INCORRECTAS, �DESEA SEGUIR INTENTANDO?");
			printf("\n1. SI.");
			printf("\n2. NO.");
			printf("\nIngrese el n�mero de la selecci�n que quiera elegir: ");
			scanf("%d", &S);
			fflush(stdin);
			if(S != 1 && S != 2)//Si no se selecciona ninguna de las dos opciones manda el siguienmte mensaje
			{
				printf("\n\nERROR, INGRESE UNA OPCI�N DADA...");
				printf("\n\n\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
			}
		}while(S != 1 && S != 2);
		
		if(S == 1)//Si se quiere seguir intentando para acceder al sistema se leen las siguientes sentencias
		{
			fflush(stdin);
			ValidarUsuario();//Se va llamando a la misma funci�n hasta que se encuentre alg�n usuario o ya no se quiera seguir intentando
		}
	}
}
//-------------------------Men� del Trabajador---------------------
void MenuTrabajador(char Nombres[21], char Apellidos[21])
{
	int Seleccion;
	do//Se ejecuta el men� hasta que ya se quiera salir del sistema
	{
		//Se imprime el men� de un Trabajador
		system("cls");
		printf("%15s%-15s", "BIENVENIDO: ", Nombres);
		printf("\n%15s%-15s", "MEN� DE T", "RABAJADOR");
		printf("\n1. Nueva Venta.");
		printf("\n2. Ver Ticket.");
		printf("\n3. Ver Ganancias.");
		printf("\n4. SALIR.");
		printf("\nIngrese el n�mero de la opci�n \nque desee realizar, por favor: ");
		scanf("%d", &Seleccion);//Se lee la opci�n
		fflush(stdin);
		
		//Conforme se realiza la selecci�n se va llamando a la funci�n que realice la selecci�n
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
				printf("Que tenga buen d�a...");
				printf("\n\n\nTeclea ENTER para salir por favor...");
				fflush(stdin);
				getchar();
				exit(1);
				break;
			default:
				system("cls");
				printf("ERROR, SELECCI�N INVALIDA...");
				printf("\nIntente de nuevo, por favor.");
				printf("\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
				MenuTrabajador(Nombres, Apellidos);
				break;
		}
	}while(Seleccion != 4);
}
//-----------------------Men� del Administrador--------------------
void MenuAdministrador(char Nombres[21], char Apellidos[21])
{
	int Seleccion;
	do//Se ejecuta el men� hasta que ya se quiera salir del sistema
	{
		//Se imprime el men� de un Trabajador
		system("cls");
		printf("%15s%-15s", "BIENVENIDO: ", Nombres);
		printf("\n%15s%-15s", "MEN� DE AD", "MINISTRADOR");
		printf("\n1. Nueva Venta.");
		printf("\n2. Ver Ticket.");
		printf("\n3. Ver Ganancias.");
		printf("\n4. Cambiar Precios.");
		printf("\n5. Agregar Trabajador.");
		printf("\n6. Eliminar Trabajador.");
		printf("\n7. SALIR.");
		printf("\nIngrese el n�mero de la opci�n \nque desee realizar, por favor: ");
		scanf("%d", &Seleccion);//Se lee la opci�n
		fflush(stdin);
		
		//Conforme se realiza la selecci�n se va llamando a la funci�n que realice la selecci�n
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
				printf("Que tenga buen d�a...");
				printf("\n\n\nTeclea ENTER para salir por favor...");
				fflush(stdin);
				getchar();
				exit(1);
				break;
			default:
				system("cls");
				printf("ERROR, SELECCI�N INVALIDA...");
				printf("\nIntente de nuevo, por favor.");
				printf("\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
				MenuAdministrador(Nombres, Apellidos);
				break;
		}
	}while(Seleccion != 7);
}
//---------------------Funci�n para crear una venta----------------
void CrearVenta(char Nombres[21], char Apellidos[21])
{
	//SE INICIALIZAN LAS VARIABLES DE LAS CANTIDADESS DE CADA INGREDIENTE
	int CantMarquesitas = 0, CantIngredientes = 0, CantEsquites = 0, CantToppings = 0, CantTostiesquites = 0;
	int CantRefrescos = 0, CantAguas = 0, Seleccion = 0;
	bool Val = false;
	
	do//SE EJECUTA EL MEN� MIENTRAS QUE NO SE DIGA QUE YA EST� LISTO EL PEDIDO O SI SE QUIERE CANCELAR
	{
		fflush(stdin);
		system("cls");
		printf("%15s", "SELECCI�N DE PRODUCTOS");
		printf("\n1. Ingresar Cantidad de Marquesitas.");
		printf("\n2. Ingresar Cantidad de Ingredientes de Marquesitas.");
		printf("\n3. Ingresar Cantidad de Esquites.");
		printf("\n4. Ingresar Cantidad de Tostiesquites.");
		printf("\n5. Ingresar Cantidad de Toppings.");
		printf("\n6. Ingresar Cantidad de Refrecos.");
		printf("\n7. Ingresar Cantidad de Aguas.");
		printf("\n8. LISTO.");
		printf("\n9. CANCELAR.");
		printf("\nIngrese el n�mero de la opci�n que desee realizar, \npor favor: ");
		scanf("%d", &Seleccion);
		fflush(stdin);
		system("cls");
		switch(Seleccion)//dDeependiendo de la seleccion que se realice se llama a la funci�n correspondiente para agregar la cantidad de producto
		{
			/*En el caso de agregar marquesitas e ingredientes, no se podr�n agregar ingredientes si no se tiene agregado al menos 1 marquesita, se valida*/
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
				//Se valida que se tenga agregado al menos 1 producto
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
				printf("ERROR, SELECCI�N INVALIDA...");
				printf("\nIntente de nuevo, por favor.");
				printf("\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
				break;
		}
	}while(Seleccion != 8 && Seleccion != 9);
	
	
	if(Seleccion != 9)
	{
		//SE INICIALIZAN LAS VARIABLES QUE NOS SIRVEN
		int NumTicket;
		char Aux[15];
		FILE *Ultimo;
		char *token;
		
		//SE ABRE EL ARCHIVO QUE SE SOLITA PARA SABER CU�L ES EL ULTIMO TICKET
		Ultimo = fopen("Tickets/UltimoNoTicket.txt", "r");
		
		if(Ultimo == NULL)//SI SUCEDE ALG�N ERROR SE CIERRA EL PROGRAMA
		{
			system("cls");
			printf("��ERROR!!");
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
		
		//YA QUE SE TOM� EL N�MERO DEL ULTIMO TICKET SE SOBREESCRIBE PONIENDO CU�L ES EL NUEVO ULTIMO N�MERO DE TICKET
		Ultimo = fopen("Tickets/UltimoNoTicket.txt", "w");
		if(Ultimo == NULL)
		{
			system("cls");
			printf("��ERROR!!");
			printf("\nEL ARCHIVO NO EXISTE...");
			printf("\n\n\nTeclea ENTER para salir, por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
		}
		fprintf(Ultimo, "%d", NumTicket);
		fclose(Ultimo);//SE CIERRA EL ARCHIVO PARA QUE SE GUARDE TODO
		
		//SE INICIALIZAN NUEVAS VARIABLES QUE NOS SERVIRAN
		char TOTALF[10];
		char NombreTicket[25];
		char NombreTicket2[35] = "Tickets/";
		sprintf(NombreTicket, "%d", NumTicket);
		strcat(NombreTicket, ".txt");
		strcat(NombreTicket2, NombreTicket);
		
		FILE *NewTicket;
		
		//SE CREA UN NUEVO ARCHIVO DEL NUEVO TICKET
		NewTicket = fopen(NombreTicket2, "w");
		if(NewTicket == NULL)
		{
			system("cls");
			printf("��ERROR!!");
			printf("\nEL ARCHIVO NO EXISTE...");
			printf("\n\n\nTeclea ENTER para salir, por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
		}
		
		//USAMOS LOS VALORES DE LA HORA Y FECHA DEL MOMENTO EN EL QUE SE EST� CREANDO EL NUEVO TICKET PARA LUEGO AGREGARLO AL ARCHIVO .TXT
		time_t FechaActual;
		time(&FechaActual);
		struct tm *MiFecha = localtime(&FechaActual);
		
		//SE VA ESCRIBIENDO EN EL NUEVO TICKET
		fprintf(NewTicket, "%15s%-15s", "LA MARQU", "ESITER�A");
		fprintf(NewTicket, "\n%15s%-15d", "TICKET #", NumTicket);
		fprintf(NewTicket, "\n------------------------------");
		
		Cambio2(Nombres);
		Cambio2(Apellidos);
		
		fprintf(NewTicket, "\nAtendi�: %s %s", Nombres, Apellidos);
		fprintf(NewTicket, "\nFecha: %d/%d/%d", MiFecha->tm_mday, MiFecha->tm_mon + 1, MiFecha->tm_year + 1900);
		
		//SE VALIDA PARA QUE SE ESCRIA BIEN LA HORA
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
		
		//SE AGREGAN A CONTINUACI�N LOS DATOS DE LOS PRODUCTOS QUE SOLICITA EL CLIENTE
		fprintf(NewTicket, "\n------------------------------");
		fprintf(NewTicket, "\n%-15s%-5s%10s", "Productos:", "Cant:", "Precio:");
		fprintf(NewTicket, "\n------------------------------");
		
		double PrecioMarquesitas, PrecioIngredientes, PrecioEsquites, PrecioToppings, PrecioTostiesquites;
		double PrecioRefrescos, PrecioAguas, TOTAL = 0;
		
		//SE VA CALCULANDO LOS PRECIOS DE CADA PRODUCTO EN SUS RESPECTIVAS FUNCIONES
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
					printf("ERROR, SELECCI�N INVALIDA...");
					printf("\nIntente de nuevo, por favor.");
					printf("\nTeclea ENTER para continuar, por favor...");
					fflush(stdin);
					getchar();
					break;
			}
		}
		//SE INGRESA EL PRECIO TOTAL
		sprintf(TOTALF, "$%.2lf", TOTAL);
		fprintf(NewTicket, "\n%20s%10s", "TOTAL:", TOTALF);
		fclose(NewTicket);
	}else
	{
		//SI SE CAMCEL� EL PEDIDO SE REGRESA AL MEN�
		system("cls");
		printf("CANCELACI�N CON �XITO");
		printf("\nTeclea ENTER para regresar al MEN�, por favor...");
		fflush(stdin);
		getchar();
	}
}
//----------------------Vallidaci�n de Marquesitas-----------------
int IngresarMarquesitas()
{
	int Num;
	printf("Ingrese cu�ntas Marquesitas son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarMarquesitas();
	}
	return Num;
}
//---------------------Vallidaci�n de Ingredientes-----------------
int IngresarIngredientes()
{
	int Num;
	printf("Ingrese cu�ntos Ingredientes para Marquesitas son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarIngredientes();
	}
	return Num;
}
//-----------------------Vallidaci�n de Esquites-------------------
int IngresarEsquites()
{
	int Num;
	printf("Ingrese cu�ntos Esquites son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarEsquites();
	}
	return Num;
}
//---------------------Vallidaci�n de Tostiesquites----------------
int IngresarTostiesquites()
{
	int Num;
	printf("Ingrese cu�ntos Tostiesquites son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarTostiesquites();
	}
	return Num;
}
//------------------------Vallidaci�n de Toppings------------------
int IngresarToppings()
{
	int Num;
	printf("Ingrese cu�ntos Toppings en TOTAL son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarToppings();
	}
	return Num;
}
//-----------------------Vallidaci�n de Refrescos------------------
int IngresarRefrescos()
{
	int Num;
	printf("Ingrese cu�ntos Refrescos son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarRefrescos();
	}
	return Num;
}
//-------------------------Vallidaci�n de Aguas--------------------
int IngresarAguas()
{
	
	int Num;
	printf("Ingrese cu�ntas Aguas son: ");
	scanf("%d", &Num);
	fflush(stdin);
	if(Num < 0)
	{
		system("cls");
		Num = IngresarAguas();
	}
	return Num;
}
/*
A CONTINUACI�N SE MUESTRAN 7 FUNCIONES QUE SIRVEN PARA QUE SE PUEDA CALCULAR EL PRECIO DE CADA PRODUCTO
LO QUE HACEN ES LO MISMO ENTRE LAS 7 FUNCIONES, LO QUE CAMBIA ES QUE CADA PRECIO EST� GUARDADO EN DIFERENTES .TXT�S,
SE ABRE EL ARCHIVO, SE TOMA LA PRIMERA FILA, SE CAMBIA LO TOMADO CON VALOR A DOUBLE, LUEGO ESE PRECIO SE MULTIPLICA CON 
LA CANTIDAD DE PRODUCTO SE PIDI� Y SE DEVUELVE ESE VALOR...
*/
//---------------------Calcular Precio de Marquesitas--------------
double CalcularPrecioMarquesitas(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioBaseMarquesita.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
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
//------------------Calcular Precio de los Ingredientes------------
double CalcularPrecioIngredientes(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioIngredientesMarquesitas.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
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
//----------------------Calcular Precio de Esquites----------------
double CalcularPrecioEsquites(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioBaseEsquite.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
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
//-------------------Calcular Precio de Tostiesquites--------------
double CalcularPrecioTostiesquites(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioBaseTostiEsquite.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
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
//----------------------Calcular Precio de Toppings----------------
double CalcularPrecioToppings(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioToppings.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
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
//---------------------Calcular Precio de Refrescos----------------
double CalcularPrecioRefrescos(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PrecioRefrescos.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
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
//-----------------------Calcular Precio de Aguas------------------
double CalcularPrecioAguas(int Cant)
{
	FILE *Costo;
	char Aux[15];
	double CostoP;
	Costo = fopen("Precios/PreciosAguas.txt", "r");
	if(Costo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
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
//-----------------------Funci�n para ver Ticket-------------------
void VerTicket()
{
	int num;
	char Name[25];
	char Name2[35] = "Tickets/";
	
	//SE LEE EL N�MERO DEL TICKET QUE SE QUIERE VER
	system("cls");
	printf("Ingrese el n�mero del ticket que desea ver, por favor: ");
	scanf("%d", &num);
	fflush(stdin);
	
	//SE CALCULA EL NOMBRE DEL ARCHIVO A BUSCAR
	sprintf(Name, "%d", num);
	strcat(Name, ".txt");
	strcat(Name2, Name);
	
	//SE INTENTA ABRIR
	FILE *Ticket;
	Ticket = fopen(Name2, "r");
	if(Ticket != NULL)
	{
		//SI SALE TODO BIEN, SE IMPRIME EL TICKET
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
		printf("\nTeclea ENTER para regresar al MEN�, por favor...");
		fflush(stdin);
		getchar();
	}else
	{//SI SALE ERROR, SE INFORMA QUE NO SE ENCONTR� Y SE VUELVE AL MEN�
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para regresar al MEN�, por favor...");
		fflush(stdin);
		getchar();
	}
	
}
//----------------------Funci�n para ver ganancias-----------------
void VerGanancias()
{
	//SE IMPRIME EL MEN�, Y DEPENDIENDO DE LA SELECCI�N SE LLEVA A LA FUNCI�N CORRESPONDIENTE
	int Seleccion;
	system("cls");
	printf("�C�MO DESEA VER LAS GANANCIAS?");
	printf("\n1. De un D�a.");
	printf("\n2. De una Semana (7 D�as).");
	printf("\n3. De un M�s (28 D�as � 4 semanas).");
	printf("\n4. Regresar al MEN�.");
	printf("\nIngrese el n�mero de la opci�n que desee realizar, \npor favor: ");
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
			//SI SE SELECCIONA UNA OPCI�N INVALIDA SE MANDA ERROR Y REALIZA UNA RECURSI�N
			printf("ERROR, SELECCI�N INVALIDA...");
			printf("\nIntente de nuevo, por favor.");
			printf("\nTeclea ENTER para regresar a las opciones, por favor...");
			fflush(stdin);
			getchar();
			VerGanancias();
			break;
	}
}
//-----------------------Ver Ganancias de un D�A-------------------
void GananciasDia()
{
	//SE INICIALIZAN LAS VARIABLES QUE NOS SERVIRAN
	int Dia, Mes, Anio;
	char Aux[35], Fecha[30];
	int NumTicket;
	char *token;
	double Ganancia = 0;
	bool Val = false;
	
	//SE LE PIDE AL USUARIO QUE INGRESE EL D�A, M�S, Y A�O DE LA FECHA A BUSCAR LA GANANCIA
	printf("Ingrese el d�a, por favor: ");
	scanf("%d", &Dia);
	fflush(stdin);
	printf("Ingrese el m�s, por favor: ");
	scanf("%d", &Mes);
	fflush(stdin);
	printf("Ingrese el a�o, por favor: ");
	scanf("%d", &Anio);
	fflush(stdin);
	
	//SE GUARDA EN EL ARRAY Fecha EL D�A, MES Y A�O PARA QUE NOS SIRVA LUEGO CON LA BUSQUEDA
	sprintf(Fecha, "%d/%d/%d", Dia, Mes, Anio);
	
	//ABRE EL ARCHIVO DE ULTIMOTICKET, PARA QUE SEPAMOS HASTA DONDE DEJAREMOS DE ABRIR ARCHIVOS
	FILE *Ultimo;
	Ultimo = fopen("Tickets/UltimoNoTicket.txt", "r");
	if(Ultimo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
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
	
	//REALIZAMOS UN FOR PARA QUE SE VAYA ABRIENDO CADA TICKET, HASTA QUE LLEGUEMOS AL ULTIMO Y SEPAMOS LA GANANCIA DEL D�A
	for(int i = 1; i <= NumTicket; i++)
	{
		strcpy(Aux,"");
		sprintf(Aux, "Tickets/%d.txt", i);
		
		FILE *Archivo;
		Archivo = fopen(Aux, "r");
		if(Archivo == NULL)
		{
			system("cls");
			printf("��ERROR!!");
			printf("\nEL ARCHIVO NO EXISTE...");
			printf("\n\n\nTeclea ENTER para salir, por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
		}
		
		fgets(Aux, 34, Archivo);
		fgets(Aux, 34, Archivo);
		fgets(Aux, 34, Archivo);
		fgets(Aux, 34, Archivo);
		fgets(Aux, 34, Archivo);
		
		token = strtok(Aux, " ");
		token = strtok(NULL, "\n");
		
		if(strcmp(Fecha, token) == 0)
		{
			Val = true;//PARA LUEGO CONFIRMAR QUE ENCONTRAMOS AL MENOS UN TICKET DEL D�A INGRESADO
			
			while(!feof(Archivo))
			{
				fgets(Aux, 34, Archivo);
			}
			
			token = strtok(Aux, "$");
			token = strtok(NULL, "\n");
			
			Ganancia = Ganancia + atof(token);//SE VAN SUMANDO LAS GANANCIAS DE CADA TICKET
			printf("\n%lf", Ganancia);
		}
		
		fclose(Archivo);//SE CIERRA CADA TICKET
	}
	
	system("cls");//SE LIMPIA LA CONSOLA
	
	if(Val == true)
	{
		//SI SE ENCONTRO AL MENOS UN TICKET DEL D�A SE IMPRIME LAS GANANCIAS
		printf("SE ENCONTR� LA GANANCIA DE LA FECHA: %s.", Fecha);
		printf("\nLA GANANCIA ES: %.2lf.", Ganancia);
	}else
	{
		//SI NO SE ENCONTR� NING�N TICKET RELACIONADO CON LO SOLICITADO SE INDICA QUE NO SE ENCONTRARON GANANCIAS DEL D�A INGRESADO
		printf("NO SE ENCONTR� LA GANANCIA DE LA FECHA: %s.", Fecha);
	}
	
	printf("\n\n\nTeclea ENTER para regresar al MEN�, por favor...");
	fflush(stdin);
	getchar();
}
//---------------------Ver Ganancias de una SEMANA-----------------
void GananciasSemana()
{
	//SE INICIALIZAN LAS VARIABLES QUE NOS SERVIRAN
	int Dia, Mes, Anio;
	char Aux[35], FechaI[30], FechaF[30];
	int NumTicket;
	char *token;
	double Ganancia = 0;
	bool Val = false;
	
	//SE IMPRIME LO QUE SE SOLICITA 
	printf("INGRESE PRIMERO LA FECHA DEL INICIO DE LA SEMANA");
	printf("\nAPARTIR DE LA FECHA QUE INGRESE EMPEZAREMOS A CONTAR");
	printf("\nLOS 7 D�AS DE LA SEMANA.");
	printf("\n\nIngrese el d�a, por favor: ");
	scanf("%d", &Dia);
	fflush(stdin);
	printf("Ingrese el m�s, por favor: ");
	scanf("%d", &Mes);
	fflush(stdin);
	printf("Ingrese el a�o, por favor: ");
	scanf("%d", &Anio);
	fflush(stdin);
	
	//SE GUARDA EN FechaI la fecha que se acaba de ingresar
	sprintf(FechaI, "%d/%d/%d", Dia, Mes, Anio);
	
	//ABRE EL ARCHIVO DE ULTIMOTICKET, PARA QUE SEPAMOS HASTA DONDE DEJAREMOS DE ABRIR ARCHIVOS
	FILE *Ultimo;
	Ultimo = fopen("Tickets/UltimoNoTicket.txt", "r");
	if(Ultimo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	rewind(Ultimo);
	fgets(Aux, 34, Ultimo);
	fclose(Ultimo);
	
	
	NumTicket = atoi(Aux);
	
	//REALIZAMOS UN FOR PARA QUE SE VAYA ABRIENDO TODOS LOS TICKETS HASTA QUE SE CUMPLAN LOS 7 D�AS A PARTIR DEL D�A INICIAL
	for(int t = 0; t < 7; t++)
	{
		
		sprintf(FechaF, "%d/%d/%d", Dia, Mes, Anio);
		
		//REALIZAMOS UN FOR PARA QUE SE VAYA ABRIENDO CADA TICKET, HASTA QUE LLEGUEMOS AL ULTIMO Y SEPAMOS LA GANANCIA DEL D�A
		for(int i = 1; i <= NumTicket; i++)
		{
			strcpy(Aux,"");
			sprintf(Aux, "Tickets/%d.txt", i);
			
			FILE *Archivo;
			Archivo = fopen(Aux, "r");
			if(Archivo == NULL)
			{
				system("cls");
				printf("��ERROR!!");
				printf("\nEL ARCHIVO NO EXISTE...");
				printf("\n\n\nTeclea ENTER para salir, por favor...");
				fflush(stdin);
				getchar();
				exit(-1);
			}
			
			fgets(Aux, 34, Archivo);
			fgets(Aux, 34, Archivo);
			fgets(Aux, 34, Archivo);
			fgets(Aux, 34, Archivo);
			fgets(Aux, 34, Archivo);
			
			token = strtok(Aux, " ");
			token = strtok(NULL, "\n");
			
			if(strcmp(FechaF, token) == 0)
			{
				Val = true;
				
				while(!feof(Archivo))
				{
					fgets(Aux, 34, Archivo);
				}
				
				token = strtok(Aux, "$");
				token = strtok(NULL, "\n");
				
				Ganancia = Ganancia + atof(token);//SE VAN SUMANDO LAS GANANCIAS DE CADA TICKET
			}
			
			fclose(Archivo);//SE CIERRA CADA ARCHIVO QUE SE ABRA
		}
		
		CalcularFecha(&Dia, &Mes, &Anio);//SE LLAMA A LA FUNCI�N PARA QUE SE CALCULE LA SIGUIENTE FECHA
		
	}
	
	
	system("cls");//SE LIMPIA LA CONSOLA
	
	if(Val == true)
	{
		//SI SE ENCONTRO AL MENOS UN TICKET DEL D�A SE IMPRIME LAS GANANCIAS
		printf("SE ENCONTR� LA GANANCIA ENTRE LAS FECHAS: %s Y %s.", FechaI, FechaF);
		printf("\nLA GANANCIA ES: %.2lf.", Ganancia);
	}else
	{
		//SI NO SE ENCONTR� NING�N TICKET RELACIONADO CON LO SOLICITADO SE INDICA QUE NO SE ENCONTRARON GANANCIAS DEL D�A INGRESADO
		printf("NO SE ENCONTRARON GANANCIAS POR LA FECHA INDICADA, VERIFIQUE MEJOR, PORFAVOR...");
	}
	
	printf("\n\n\nTeclea ENTER para regresar al MEN�, por favor...");
	fflush(stdin);
	getchar();
}
//-----------------------Ver Ganancias de un MES-------------------
void GananciasMes()
{
	//SE INICIALIZAN LAS VARIABLES QUE NOS SERVIRAN
	int Dia, Mes, Anio;
	char Aux[35], FechaI[30], FechaF[30];
	int NumTicket;
	char *token;
	double Ganancia = 0;
	bool Val = false;
	
	//SE IMPRIME LO QUE SE SOLICITA 
	printf("INGRESE PRIMERO LA FECHA DEL INICIO DE LA SEMANA");
	printf("\nAPARTIR DE LA FECHA QUE INGRESE EMPEZAREMOS A CONTAR");
	printf("\nLOS 28 D�AS � 4 SEMANAS.");
	printf("\n\nIngrese el d�a, por favor: ");
	scanf("%d", &Dia);
	fflush(stdin);
	printf("Ingrese el m�s, por favor: ");
	scanf("%d", &Mes);
	fflush(stdin);
	printf("Ingrese el a�o, por favor: ");
	scanf("%d", &Anio);
	fflush(stdin);
	
	//SE GUARDA EN FechaI la fecha que se acaba de ingresar
	sprintf(FechaI, "%d/%d/%d", Dia, Mes, Anio);
	
	//ABRE EL ARCHIVO DE ULTIMOTICKET, PARA QUE SEPAMOS HASTA DONDE DEJAREMOS DE ABRIR ARCHIVOS
	FILE *Ultimo;
	Ultimo = fopen("Tickets/UltimoNoTicket.txt", "r");
	if(Ultimo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	rewind(Ultimo);
	fgets(Aux, 34, Ultimo);
	fclose(Ultimo);
	
	
	NumTicket = atoi(Aux);
	
	//REALIZAMOS UN FOR PARA QUE SE VAYA ABRIENDO TODOS LOS TICKETS HASTA QUE SE CUMPLAN LOS 7 D�AS A PARTIR DEL D�A INICIAL
	for(int t = 0; t < 28; t++)
	{
		
		sprintf(FechaF, "%d/%d/%d", Dia, Mes, Anio);
		
		//REALIZAMOS UN FOR PARA QUE SE VAYA ABRIENDO CADA TICKET, HASTA QUE LLEGUEMOS AL ULTIMO Y SEPAMOS LA GANANCIA DEL D�A
		for(int i = 1; i <= NumTicket; i++)
		{
			strcpy(Aux,"");
			sprintf(Aux, "Tickets/%d.txt", i);
			
			FILE *Archivo;
			Archivo = fopen(Aux, "r");
			if(Archivo == NULL)
			{
				system("cls");
				printf("��ERROR!!");
				printf("\nEL ARCHIVO NO EXISTE...");
				printf("\n\n\nTeclea ENTER para salir, por favor...");
				fflush(stdin);
				getchar();
				exit(-1);
			}
			
			fgets(Aux, 34, Archivo);
			fgets(Aux, 34, Archivo);
			fgets(Aux, 34, Archivo);
			fgets(Aux, 34, Archivo);
			fgets(Aux, 34, Archivo);
			
			token = strtok(Aux, " ");
			token = strtok(NULL, "\n");
			
			if(strcmp(FechaF, token) == 0)
			{
				Val = true;
				
				while(!feof(Archivo))
				{
					fgets(Aux, 34, Archivo);
				}
				
				token = strtok(Aux, "$");
				token = strtok(NULL, "\n");
				
				Ganancia = Ganancia + atof(token);//SE VAN SUMANDO LAS GANANCIAS DE CADA TICKET
			}
			
			fclose(Archivo);//SE CIERRA CADA ARCHIVO QUE SE ABRA
		}
		
		CalcularFecha(&Dia, &Mes, &Anio);//SE LLAMA A LA FUNCI�N PARA QUE SE CALCULE LA SIGUIENTE FECHA
		
	}
	
	
	system("cls");//SE LIMPIA LA CONSOLA
	
	if(Val == true)
	{
		//SI SE ENCONTRO AL MENOS UN TICKET DEL D�A SE IMPRIME LAS GANANCIAS
		printf("SE ENCONTR� LA GANANCIA ENTRE LAS FECHAS: %s Y %s.", FechaI, FechaF);
		printf("\nLA GANANCIA ES: %.2lf.", Ganancia);
	}else
	{
		//SI NO SE ENCONTR� NING�N TICKET RELACIONADO CON LO SOLICITADO SE INDICA QUE NO SE ENCONTRARON GANANCIAS DEL D�A INGRESADO
		printf("NO SE ENCONTRARON GANANCIAS POR LA FECHA INDICADA, VERIFIQUE MEJOR, PORFAVOR...");
	}
	
	printf("\n\n\nTeclea ENTER para regresar al MEN�, por favor...");
	fflush(stdin);
	getchar();
}
//----------------------------Calcular Fecha-----------------------
int CalcularFecha(int *D, int *M, int *A)
{
	//SE VALIDA SI ES UN A�O BISIESTO
	if ( *A % 4 == 0 && *A % 100 != 0 || *A % 400 == 0 )
	{
		//SE VALIDA CUAL MES ES Y RESPECTO A ELLO SE SUMA EL D�A, MES SI ES NECESARIO Y A�O SI ES NECESARIO
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
		//SE VALIDA CUAL MES ES Y RESPECTO A ELLO SE SUMA EL D�A, MES SI ES NECESARIO Y A�O SI ES NECESARIO
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
//-------------------------Cambiar los Precios---------------------
void CambiarPrecios()
{
	//SE MANDA EL MEN� 
	int Seleccion;
	system("cls");
	printf("Elija de cu�l producto quiere cambiar precios.");
	printf("\n1. Marquesitas.");
	printf("\n2. Ingredientes de Marquesitas.");
	printf("\n3. Esquites.");
	printf("\n4. TostiEsquites.");
	printf("\n5. Toppings.");
	printf("\n6. Refrescos.");
	printf("\n7. Aguas.");
	printf("\n8. Regresar al MEN�.");
	printf("\nIngrese el n�mero de la opci�n \nque desee realizar, por favor: ");
	scanf("%d", &Seleccion);
	fflush(stdin);
	system("cls");
	//RESPECTO AL PRECIO QUE SE QUIERA CAMBIAR SE MANDA A LA FUNCI�N CORRESPONDIENTE
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
			//SI SE SELECCIONA UNA OPCI�N QUE NO SEA VALIDA SE LANZA EL SIGUIENTE ERROR 
			printf("ERROR, SELECCI�N INVALIDA...");
			printf("\nIntente de nuevo, por favor.");
			printf("\nTeclea ENTER para continuar, por favor...");
			fflush(stdin);
			getchar();
			CambiarPrecios();//SE REALIZA UN PROCESO RECURSIVO
			break;
	}
}
/*
A CONTINUACI�N SIGUIEN 7 FUNCIONES QUE SIRVEN PARA CAMBIAR PRECIOS DE CADA PRODUCTO, DEPENDIENDO DE LA FUNCI�N,
CADA FUNCI�N HACE BASICAMENTE LO MISMO, PERO SOLO CAMBIA EL PRECIO A CAMBIAR, DEBIDO AL ARCHIVO QUE SE DEBE DE 
ABRIR, HACEN TODOS ESTO: INICIALIZAR UNA VARIABLE DONDE INGRESAR EL VALOR DEL NUEVO PRECIO, SE LLAMA A UNA FUNCION QUE PIDE EL PRECIO Y SE VALIDA
CON UN PROCESO RECURSIVO, LUEGO SE ABRE EL .TXT DEL PRECIO DEL PRODUCTO CORRESPONDIENTE A CAMBIAR, SI NO SE ABRE MANDA UN ERROR 
Y SE CIERRA EL PROGRAMA, LUEGO SE REESCRIBE EL ARCHIVO Y SE INGRESA EL NUEVO PRECIO, SE CIERRA EL ARCHIVO Y
VUELVE AL MEN�.
*/
//----------------------Cambiar Precio Marquesitas-----------------
void CambiarPrecioMarquesitas()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioBaseMarquesita.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//---------------------Cambiar Precio Ingredientes-----------------
void CambiarPrecioIngredientes()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioIngredientesMarquesitas.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//-----------------------Cambiar Precio Esquites-------------------
void CambiarPrecioEsquites()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioBaseEsquite.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//---------------------Cambiar Precio TostiEsquites----------------
void CambiarPrecioTostiEsquites()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioBaseTostiEsquite.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//------------------------Cambiar Precio Toppings------------------
void CambiarPrecioToppings()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioToppings.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//------------------------Cambiar Precio Refrescos-----------------
void CambiarPrecioRefrescos()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PrecioRefrescos.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//--------------------------Cambiar Precio Aguas-------------------
void CambiarPrecioAguas()
{
	double Num = ValidarPrecio();
	
	FILE *Archivo;
	Archivo = fopen("Precios/PreciosAguas.txt", "w");
	if(Archivo == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir, por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	fprintf(Archivo, "%.2lf", Num);
	fclose(Archivo);
}
//-----------------------------Validar Precio----------------------
double ValidarPrecio()
{
	//SE INICIALIZA LA VARIABLE PARA INGRESAR UN PRECIO
	double Num;
	
	//SE PIDE AL USUARIO QUE INGRESE EL VALOR
	printf("Ingrese precio nuevo, por favor: ");
	scanf("%lf", &Num);//se lee el valor
	fflush(stdin);
	
	if(Num < 0)
	{
		//si el valor ingresado es menor a 0, se manda un error
		system("cls");
		printf("ERROR, DEBE SER MAYOR IGUA O MAYOR QUE 0...");
		printf("\nINTENTE DE NUEVO...");
		printf("\nTeclea ENTER para continuar, por favor...");
		fflush(stdin);
		getchar();
		Num = ValidarPrecio();//se realiza una recursi�n llamando a la misma funci�n, hasta que se ingrese un valor valido
	}
	return Num;//se retorna el valor ya validado
}
//---------------------------Agregar Trabajador--------------------
void AgregarTrabajador()
{
	//se limpia la consola
	system("cls");
	
	//SE INICIALIZAN LAS VARIABLES QUE NECESITAMOS
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
	
	//SE IMPRIME EL MEN�
	printf("%37s%-38s", "INGRESO DE ", "TRABAJADOR");
	
	printf("\nIngrese el nuevo Usuario (Solo se contar�n los primeros 15 car�cteres): \n");
	fgets(Usuario, 16, stdin);//SE LEE EL NUEVO USUARIO
	Cambio(Usuario, 16);//SE LLAMA A LA FUNCI�N Cambio PARA QUE SE CAMBIE EL SALTO DEL fgets
	
	//SE ABRE EL ARCHIVO DEL LOGIN
	LOGIN = fopen("Datos/LOGIN.txt", "r");
	if(LOGIN == NULL)
	{
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	
	//SE PONE EL CURSO AL INICIO DEL ARCHIVO DE LOGIN
	rewind(LOGIN);
	
	fgets(Aux, 80, LOGIN);//SE IGNORA LA PRIMERA LINEA DEL ARCHIVO
	
	//SE LEE CADA LINEA HASTA QUE SE ACABE EL ARCHIVO O SI SE LLEGA A ENCONTRAR UN USUARIO IGUAL AL QUE SE QUIERE INGRESAR
	//ESTO ES PARA QUE NO EXISTAN USUARIOS IGUALES
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
	fclose(LOGIN);//SE CIERRA EL ARCHIVO
	
	
	if(Val == true)//SI SE ENCONTR� UN USUARIO IGUAL AL QUE SE QUISO INGRESAR SE LEEN LAS SIGUIENTES SENTENCIAS
	{
		do
		{//SE EJECUTAN LAS SIGUIENTES SENTENCIAS HASTA QUE SE INGRESE UN VALOR VALIDO
			system("cls");
			printf("USUARIO YA EXISTE, �DESEA SEGUIR INTENTANDO?");
			printf("\n1. SI.");
			printf("\n2. NO.");
			printf("\nIngrese el n�mero de la selecci�n que quiera elegir: ");
			scanf("%d", &S);
			if(S != 1 && S != 2)
			{
				printf("\n\nERROR, INGRESE UNA OPCI�N DADA...");
				printf("\n\n\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
			}
		}while(S != 1 && S != 2);
		
		if(S == 1)//SI SE QUIERE SEGUIR INTENTANDO, SE REALIZA UNA RECURSIVIDAD LLAMANDO LA MISMA FUNCI�N
		{
			fflush(stdin);
			AgregarTrabajador();
		}
	}else//SI NO SE ENCONTR� UN USUARIO IGUAL AL QUE SE QUISO INGRESAR SE LEEN LAS SIGUIENTES SENTENCIAS
	{
		//SE INGRESAN LOS OTROS DATOS DEL NUEVO USUARIO
		printf("\nIngrese su contrase�a (Solo se contar�n los primeros 15 car�cteres): ");
		fgets(Contrasenia, 16, stdin);
		Cambio(Contrasenia, 16);
		printf("\nIngrese su(s) Nombre(s): ");
		fgets(Nombres, 21, stdin);
		Cambio(Nombres, 21);
		printf("\nIngrese su(s) Apellido(s): ");
		fgets(Apellidos, 21, stdin);
		Cambio(Apellidos, 21);
		do
		{//SE REALIZAN LAS SIGUIENTES SENTENCIAS DENTRO DEL DO-WHILE HASTA QUE SE INGRESE UNA OPCI�N VALIDA
			system("cls");
			printf("�El nuevo trabajador, va a ser administrador?");
			printf("\n1. SI.");
			printf("\n2. NO.");
			printf("\nIngrese el n�mero de la selecci�n que quiera elegir: ");
			scanf("%d", &S);
			if(S != 1 && S != 2)
			{
				printf("\n\nERROR, INGRESE UNA OPCI�N DADA...");
				printf("\n\n\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
			}
		}while(S != 1 && S != 2);
		
		if(S == 2)
		{//SI S ES 2, O SEA QUE ES UN SIMPLE TRABAJADOR, SE ENTIENDE QUE EN EL ARCHIVO SE GUARDAR� COMO VALOR 0
			S = 0;
		}
		
		//SE ABRE EL ARCHIVO LOGIN, PARA QUE SE AGREGUEN LOS NUEVOS DATOS
		LOGIN = fopen("Datos/LOGIN.txt", "a");
		if(LOGIN == NULL)
		{
			//SI SALE ALGO MAL SE CIERRA EL PROGRAMA
			system("cls");
			printf("��ERROR!!");
			printf("\nEL ARCHIVO NO EXISTE...");
			printf("\n\n\nTeclea ENTER para salir por favor...");
			fflush(stdin);
			getchar();
			exit(-1);
		}
		
		//SE INGRESA LA NUEVA LINEA 
		fprintf(LOGIN, "\n%s,%s,%d,%s,%s,", Usuario, Contrasenia, S, Nombres, Apellidos);
		fclose(LOGIN);
		system("cls");
		printf("LISTO");
		printf("\n\n\nTeclea ENTER para volver al MEN�, por favor...");
		fflush(stdin);
		getchar();//SE REGRESA AL MEN�
	}
}
//--------------------------Eliminar Trabajador--------------------
void EliminarTrabajador()
{
	system("cls");
	
	//SE INICIALIZAN LAS VARIABLES QUE NOS SERVIRAN
	char Usuario[16];
	FILE *LOGIN;
	FILE *NEWLOGIN;
	char *token;
	char Aux[80], Aux2[80];
	bool Val = false;
	int S;
	
	//SE IMPRIME LO QUE SE SOLICITA
	printf("%37s%-38s", "ELIMINACI�N D", "E TRABAJADOR");
	
	printf("\nIngrese el Usuario a eliminar (Solo se contar�n los primeros 15 car�cteres): \n");
	fgets(Usuario, 16, stdin);//SE LEE EL USUARIO QUE SE QUIERE ELIMINAR
	Cambio(Usuario, 16);
	
	//SE ABRE EL ARCHIVO LOGIN
	LOGIN = fopen("Datos/LOGIN.txt", "r");
	//SE CREA UN NUEVO ARCHIVO PARA GUARDAR TODOS LOS DATOS DE TODOS LOS USUARIOS, EXCEPTO EL QUE SE QUIERE ELIMINAR
	NEWLOGIN = fopen("Datos/LOGINTEMP.txt", "w");
	
	if(LOGIN == NULL || NEWLOGIN == NULL)
	{
		//SI SALE ALGO MAL SE IMPRIME LO QUE SIGUE
		system("cls");
		printf("��ERROR!!");
		printf("\nEL ARCHIVO NO EXISTE...");
		printf("\n\n\nTeclea ENTER para salir por favor...");
		fflush(stdin);
		getchar();
		exit(-1);
	}
	
	//SE PONE EL CURSOR AL INICIO DEL ARCHIVO LOGIN
	rewind(LOGIN);
	
	fgets(Aux, 80, LOGIN);
	Cambio(Aux, 80);
	fprintf(NEWLOGIN,Aux);//SE VA ESCRIBIENDO LA PRIMERA LINEA DE LOGIN EN EL NUEVO ARCHIVO
	
	//SE VA LEYENDO CADA LINEA DEL LOGIN
	while(!feof(LOGIN))
	{
		fgets(Aux, 80, LOGIN);
		strcpy(Aux2, Aux);
		token = strtok(Aux, ",");//SE VA TOMANDO EL PRIMER VALOR DE CADA LINEA QUE ES EL USUARIO
	    if(token != NULL){
	    	if(strcmp(Usuario, token) == 0)//SE VALIDA QUE NO SEA IGUAL EL USUARIO QUE SE QUIERE ELIMINAR CON EL QUE ESTAMOS EN LA LINEA ACTUAL
	    	{
	    		Val = true;//SI SE ENCUENTRA EL QUE SE QUIERE ELIINAR SE IGNORA Y SE VALIDA
			}else
			{
				//SI NO ES EL USUARIO A ELIMINAR SE ESCRIBE EN EL NUEVO ARCHIVO
				Cambio(Aux2, 80);
				fprintf(NEWLOGIN, "\n%s", Aux2);
			}
	    }
	}
	//SE CIERRAN LOS DOS ARCHIVOS PARA GUARDAR TODO
	fclose(LOGIN);
	fclose(NEWLOGIN);
	
	//SE ELIMINA EL ANTIGUO LOGIN
	remove("Datos/LOGIN.txt");
	
	//SE CAMBIA EL NOMBRE DEL NUEVO ARCHIVO, Y SE GUARDAR COMO EL ANTIGUO ARCHIVO
	rename("Datos/LOGINTEMP.txt", "Datos/LOGIN.txt");
	
	if(Val == true)
	{
		//SI SE ELIMIN� CORRECTAMENTE EL USUARIO, SE IMPRIME LO SIGUIENTE Y SE VUELVE AL MEN�
		system("cls");
		printf("LISTO");
		printf("\n\n\nTeclea ENTER para volver al MEN�, por favor...");
		fflush(stdin);
		getchar();
		
	}else
	{
		//SI NO SE ELIMIN� CORRECTAMENTE EL USUARIO, SE IMPRIME LO SIGUIENTE
		do
		{//SE EJECUTAN LAS SIGUIENTES SENTENCIAS HASTA QUE SE INGRESE UN VALOR VALIDO 
			system("cls");
			printf("USUARIO NO EXISTE, �DESEA SEGUIR INTENTANDO?");
			printf("\n1. SI.");
			printf("\n2. NO.");
			printf("\nIngrese el n�mero de la selecci�n que quiera elegir: ");
			scanf("%d", &S);
			if(S != 1 && S != 2)
			{
				printf("\n\nERROR, INGRESE UNA OPCI�N DADA...");
				printf("\n\n\nTeclea ENTER para continuar, por favor...");
				fflush(stdin);
				getchar();
			}
		}while(S != 1 && S != 2);
		
		if(S == 1)
		{//SI SE QUIERE SEGUIR INTENTANDO A ELIMINAR UN USUARIO SE REALIZA UN PROCESO RECURSIVO LLAMANDO 
		//A LA MISMA FUNCI�N HASTA QUE YA SE ELIMINE UN USUAURIO O YA NO SE QUIERA SEGUIR INTENTANDO
			fflush(stdin);
			EliminarTrabajador();
		}
	}
}

















