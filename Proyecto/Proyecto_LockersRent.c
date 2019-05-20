
//Librerias utilizadas

#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Formas del ASCII para la elaboracion de las letras
#define  s 32 //espacio
#define  l 219 //cuadrado largo ¦
#define  c 223 //cuadrado pequeño hacia arriba ¯
#define  d 220 //cuadrado pequeño hacia abajo _

//ajustes de errores

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif
//Constantes

#define TAMANO_CADENA 10000//maximo que puede tener un string 
#define TECLA_RETROCESO 8//usado para ocultar la contraseña con "*"
#define PRIMER_CARACTER_ASCII 32//idicador para saber cuando se estan ingresando los datos de la contraseña e irlos cambiando por un " * " para ocultar la clave de acceso del administrador o empleado
#define Total_Empleados 10000//Maximo de empleados que pueden ser dados de alta en el sistema
#define Total_Lockers 16 //numero total de locker disponibles para solicitar una renta
#define TOTAL_ATRIBUTOS_EMPLEADOS 6//total de miembros del struct de empleados
#define ENTER 13//codigo ASCII de la tecla enter,usado para ocultar la clawe de acceso
#define NOMBRE_LEIDO 1//referecia al nombre para cargar los datos
#define CLAVE_LEIDA 3//referecia a la clave para cargar los datos
#define NicknameEmpleado_LEIDO 2//usado para abrir y leer el nickname de los empleados ,para poder guardar los datos en el archivo
#define DOMICILIO_LEIDO 4//referecia al domicilio para cargar los datos
#define TELEFONO_LEIDO 5//referencia al telefono para cargar los datos
#define MatriculaEmpleado_LEIDO 6// referencia la matricula del empleado para cargar los datos
#define Lockers_LEIDOS 2//referencia el numero de locker para cargar los datos
#define Fecha_LEIDO 3//referencia la fecha para cargar los datos
#define FechaDevolucion_LEIDO 4//referencia la fecha de devolucion para cargar los datos
#define MatriculaRenta_LEIDO 5// referencia la matricula del usuario para cargar los datos
#define TOTAL_ATRIBUTOS_Usuarios 6//referencia el numero total de miembros del struct de usuarios

typedef enum {falso,verdadero} booleano;


typedef struct
{
	char NicknameEmpleado[TAMANO_CADENA+1];//nombre de usuario del empleado para acceder al sistema
	char clave [TAMANO_CADENA+1];//contraseña
	char nombre[TAMANO_CADENA+1];//nombre del empleado
	char domicilio[TAMANO_CADENA+1];//domicilio del empleado
	char telefono[TAMANO_CADENA+1];//telefono del empleado
	char matricula[TAMANO_CADENA+1];//matricula del empleado
} Empleado;//struct para almacenar los datos de los empleados que sean dados de alta en el sistema por el administrador

typedef struct
{
	char nombre[TAMANO_CADENA+1];//nombre del usuario
	char fecha [TAMANO_CADENA+1];//Fecha en la que se solicita el locker
	char locker [TAMANO_CADENA+1];// numero de locker que se solicita
	char fecha_devolucion [TAMANO_CADENA+1];//Fecha de devolucion del locker
	char matricula_renta [TAMANO_CADENA+1];//matricula del usuario(Persona que solicita la renta de algun locker)
	char estado[TAMANO_CADENA+1];//Estado del locker (En Renta)
} registro;//struct para dar de alta a los usuarios que soliciten el uso de algun locker

//Variables para la manipulacion de registros
Empleado Empleados[Total_Empleados];//total de struct de empleados
registro usuarios_locker[Total_Lockers];//total de usuarios_locker(usuarios que han solicitado la renta de algun locker)
int CuentaEmpleados;//contador para verificar y validar el numero de empleados que han sido dado de alta
int cuentaUsuarios;//contador para verificar y validar el numero de usuarios(Personas que han solicitado la renta de algun locker) que se han dado de alta en el sistema
//Funciones generales del programa
int opcionesMenuPrincipal();//Despliega el menu principal
void imprimirError();//muestra un error en caso de ingresar una opcion invalida
int opcionesMenuSesion();//Despliega el menu de acceso de los diferentes usuarios al sistema: 1) Administrador 2)Empleado
void ocultarClave(char *clave);//funcion encargada de ocultar la clave de acceso del administrador o del empleado al sistema
void pausa();//funcion para esperar el enter o presionado de alguna tecla
void inicializarRegistros();//funcion encargada de inicializar los registros de los empleados y usuarios, para poder ser leidos correctamente
void bienvenida();//funcion de bienvenida del programa

//Funciones para la manipulacion de registros de peliculas
void menuRenta();//Despliega las opciones para rentar un locker
void pedirDatosUsuario_locker(int i);//Despliega los campos a llenar de un usuario que solicita la renta de locker
void altaUsuario_locker();//permite registra un nuevo usuario en el sistema 
void cargarDatosUsuarios_locker();//permiter guardar los datos de los usuarios ingresados en el archivo correspondiente
void modificarUsuario_locker();//permite buscar un usuario en especifico y modificar los datos en caso de ser erroneos
void bajaUsuario_locker();//permite elimiar los datos de un usuario que haya solicitado la renta de algun locker  en el sistema
void listarUsuarios_locker();//permite mostrar los datos de todos aquellos usuarios que esten dados de alta en el sistema de renta de locker
void BuscarUsuario_locker();//permite buscar un usuario en especifico para poder visualizar sus datos
booleano coincideNombreUsuario_locker(char *NombreUsuario);//funcion de validacion del nombre de usuario
int damePosicionUsuario_locker(char* NombreUsuario);//permite ubicar al usario cuyo nickname sea el mismo, para poder modificarlo,buscarlo o eliminarlo en el archivo
void guardarArchivoUsuarios_locker();//guarda los datos de los usuaros que han sido dado de alta en el archivo correspondiente
void guardarArchivoEmpleados();//guarda los datos de los empleados que han sido dado de alta en el archivo correspondiente
int OpcionesMenuEmpleado();//Despliega las opciones o menu del empleado
void mostrarDatosUsuarios_locker(int i);//permite visualizar los datos de los usuarios que hayan solicitado la renta de algun locker


//Funciones para la manipulacion de registros de trabajadores

void pedirDatosEmpleado(int i);//funcion encargada de solicitar los datos correspondientes para dar de alta a un empleado al sistema
void menuAdministrador();//despliega las oopciones o menu del administrador
void inicioSesionEmpleado();//Despliega la forma o imagen del empleado , seguido del nmbre empleado, para poder ingresar su nicknama y contraseña para acceder al sistema
void menuEmpleado();
void cargarDatosaEmpleados();
void AltaEmpleado();
int QueEmpleadoIngreso(char *NicknameEmpleado);
void ModificarEmpleado();
void BajaEmpleado();
void ListarEmpleados();
void BuscarEmpleado();
void mostrarDatosEmpleado(int i);
booleano coincideNicknameEmpleado(char *NicknameEmpleado);
int damePosicionEmpleado(char *NicknameEmpleado);
int OpcionesMenuAdministrador();
booleano datosCorrectosAdministrador(char *num, char *clave);
void InicioSesionAdministrador();
booleano DatosCorrectosEmpleados(char *NicknameEmpleado, char *clave);
int opcionesMenuEmpleado();
void efecto_comprobacionArchivos();

//funciones agregadas por mi
void iniciar_sesion();
void carga_entorno();
void creditos();
void inicio_programa();
int efecto_carga();
void carga_completa();
void sesion_administrador();
void sesion_empleado();
void historial_lockers();
void historial_Trabajadores();



void imprimirError()
{
	printf("\n\nHas ingresado una opcion no valida!\n\n");
}
void creditos(){
	int desplazamiento=0;
	int contador=0;
	for(int i=0;i<80;i++){
		//Palabra:Creditos
		printf("                                          ");
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,d,s,d,d,d,s,s,d,d,d,s,d,d,d,s,s,d,d,d,s,d,d,d,s,s,d,d,s,s,s,d,d,s,s,s,s,s);
		printf("\n");
		printf("                                          ");
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,l,d,d,c,s,l,d,s,s,l,s,s,l,s,s,l,s,s,s,l,s,s,l,s,s,l,s,c,d,s,s,s,c,s,s);
		printf("\n");
		printf("                                          ");
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,d,d,s,l,s,s,l,s,l,d,d,s,l,d,d,c,s,d,l,d,s,s,l,s,s,c,d,d,c,s,d,d,c,s,s,c,s,s);
		printf("\n");
		
		if(i<18){
			desplazamiento=i+1;
		}else if(i<32){
			desplazamiento=(i+1)-18;
		}else if(i<48){
			desplazamiento=(i+1)-34;
		}else if(i<64){
			desplazamiento=(i+1)-50;
		}else desplazamiento=(i+1)-66;
		
		for(int x=0;x<desplazamiento;x++){//Imprime los saltos
			printf("\n");
			
		}
		if(i<18){
			//Palabras: Los compiladores:
			printf("                        ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,s,s,s,s,d,d,s,s,s,d,d,s,s,s,s,d,d,d,s,s,d,d,s,s,d,s,s,s,d,s,d,d,d,s,s,d,d,d,s,d,s,s,s,s,d,d,s,s,d,d,d,s,s,s,d,d,s,s,d,d,d,s,s,d,d,d,s,s,d,d,s);
			printf("\n");
			printf("                        ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,l,s,s,l,s,c,d,s,s,s,s,s,l,s,s,s,l,s,s,l,s,l,c,d,c,l,s,l,d,d,c,s,s,l,s,s,l,s,s,s,l,d,d,l,s,l,s,s,l,s,l,s,s,l,s,l,d,d,c,s,l,d,s,s,c,d,s,s);
			printf("\n");
			printf("                        ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,d,d,s,c,d,d,c,s,d,d,c,s,s,s,s,l,d,d,s,c,d,d,c,s,l,s,s,s,l,s,l,s,s,s,s,d,l,d,s,l,d,d,s,l,s,s,l,s,l,d,d,c,s,c,d,d,c,s,l,s,s,l,s,l,d,d,s,d,d,c,s);
			printf("\n\n");
			//Dibujo de computadora
			printf("                                                    ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,d,d,d,d,d,s,s,d,d,d,d,d,s,s,s,s,s);
			printf("\n");
			printf("                                                    ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,s,l,s,s,l,s,d,s,l,s,s,s,s,s);
			printf("\n");
			printf("                                                    ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,c,c,c,c,c,c,c,s,s,l,s,c,s,l,s,s,s,s,s);
			printf("\n");
			printf("                                                    ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,l,l,l,d,d,s,s,l,d,d,d,l,s,s,s,s,s);
		}else if(i<32){
			//Palabra:Carlos
			printf("                                             ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,d,s,s,d,d,s,s,d,d,d,s,s,d,s,s,s,s,d,d,s,s,s,d,d,s,s,s);
			printf("\n");
			printf("                                             ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,l,d,d,l,s,l,d,d,c,s,l,s,s,s,l,s,s,l,s,c,d,s,s,s,s);
			printf("\n");
			printf("                                             ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,d,d,s,l,s,s,l,s,l,s,s,l,s,l,d,d,s,c,d,d,c,s,d,d,c,s,s,s);
			printf("\n\n");
			
			//Palabra:Álvarez
			printf("                                           ");
			printf("%c%c%c%c%c",s,s,s,d,c);
			printf("\n");
			printf("                                           ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,d,d,s,s,d,s,s,s,d,s,s,d,s,s,d,d,s,s,d,d,d,s,s,d,d,d,s,d,d,d,s);
			printf("\n");
			printf("                                           ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,d,d,l,s,l,s,s,s,l,s,s,l,s,l,d,d,l,s,l,d,d,c,s,l,d,s,s,s,d,c,s);
			printf("\n");
			printf("                                           ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,l,s,l,d,d,s,c,l,l,c,s,l,s,s,l,s,l,s,s,l,s,l,d,d,s,l,d,d,s);
			//system("cls");//pemite crear un efecto de parpadeo
			
		}else if(i<48){
			//Palabra:Jafet
			printf("                                                ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,d,d,d,s,s,d,d,s,s,d,d,d,s,d,d,d,s,d,d,d,s);
			printf("\n");
			printf("                                                ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,l,s,s,l,d,d,l,s,l,d,s,s,l,d,s,s,s,l,s,s);
			printf("\n");
			printf("                                                ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,c,d,l,s,s,l,s,s,l,s,l,s,s,s,l,d,d,s,s,l,s,s);
			printf("\n\n");
			
			//Palabra:Fernández
			printf("                                     ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,d,c,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
			printf("\n");
			printf("                                     ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,d,s,d,d,d,s,d,d,d,s,s,d,s,s,s,s,d,s,s,d,d,s,s,d,s,s,s,s,d,s,d,d,d,s,s,d,d,d,s,d,d,d,s);
			printf("\n");
			printf("                                     ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,d,s,s,l,d,s,s,l,d,d,c,s,l,c,d,s,s,l,s,l,d,d,l,s,l,c,d,s,s,l,s,l,s,s,l,s,l,d,s,s,s,d,c,s);
			printf("\n");
			printf("                                     ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,l,d,d,s,l,s,s,l,s,l,s,s,c,d,l,s,l,s,s,l,s,l,s,s,c,d,l,s,l,d,d,c,s,l,d,d,s,l,d,d,s);
			//system("cls");
			
			
		}else if(i<64){
			//Palabra:Norely
			printf("                                            ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,s,s,s,s,d,s,s,d,d,s,s,d,d,d,s,s,d,d,d,s,d,s,s,d,s,s,s,d,s);
			printf("\n");
			printf("                                            ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,c,d,s,s,l,s,l,s,s,l,s,l,d,d,c,s,l,d,s,s,l,s,s,s,c,d,c,s,s);
			printf("\n");
			printf("                                            ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,c,d,l,s,c,d,d,c,s,l,s,s,l,s,l,d,d,s,l,d,d,s,s,l,s,s,s);
			printf("\n\n");
			
			//Palabra:Chan
			printf("                                                ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,d,s,d,s,s,d,s,s,d,d,s,s,d,s,s,s,s,d,s);
			printf("\n");
			printf("                                                ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,l,d,d,l,s,l,d,d,l,s,l,c,d,s,s,l,s);
			printf("\n");
			printf("                                                ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,d,d,s,l,s,s,l,s,l,s,s,l,s,l,s,s,c,d,l,s);
			
		}else {
			//palabra:Lockers
			printf("                                             ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,s,s,s,s,d,d,s,s,d,d,d,s,d,s,s,d,s,d,d,d,s,d,d,d,s,s,s,d,d,s);
			printf("\n");
			printf("                                             ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,l,s,s,l,s,l,s,s,s,l,d,c,s,s,l,d,s,s,l,d,d,c,s,c,d,s,s);
			printf("\n");
			printf("                                             ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,d,d,s,c,d,d,c,s,l,d,d,s,l,s,c,d,s,l,d,d,s,l,s,s,l,s,d,d,c,s);
			printf("\n\n");
			
			//Palabra:Rent
			printf("                                                 ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,d,s,s,d,d,d,s,d,s,s,s,s,d,s,d,d,d,d,d);
			printf("\n");
			printf("                                                 ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,d,d,c,s,l,d,s,s,l,c,d,s,s,l,s,s,s,l,s,s);
			printf("\n");
			printf("                                                 ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,l,s,l,d,d,s,l,s,s,c,d,l,s,s,s,l,s,s);
			printf("\n\n");
			
			//Palabra: V.1.0
			printf("                                                 ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,s,s,d,s,s,s,s,s,d,s,s,s,s,s,s,d,d,s);
			printf("\n");
			printf("                                                 ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,l,s,s,s,s,c,l,s,s,s,s,s,l,s,s,l);
			printf("\n");
			printf("                                                 ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,c,l,l,c,s,l,l,s,d,l,d,s,l,l,s,c,d,d,c);
			printf("\n\n");
			
		}
		//system("cls");
		do {
			
			contador++;
		} while(contador<22999290);
		system("cls");
		contador=0;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                           ");
	printf("Presione enter para volver al menu");
	getchar();
	getchar();
	
}
int opcionesMenuPrincipal()
{
	system("COLOR 0F");
	int opcion;
	fflush(stdin);
	printf("                                      ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,d,d,s,s,s);
	printf("\n");
	printf("                                      ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,c,c,s,s,s,s);
	printf("\n");
	printf("                                      ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,l,d,s,s,s,s,d,l,l,s,s,d,l,l,l,l,l,s,s,l,l,d,s,s,s,l,l,s,s,l,l,s,s,s,s,l,l,s);
	printf("\n");
	printf("                                      ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,l,l,d,s,s,d,l,l,l,s,s,l,l,s,s,s,s,s,s,l,l,l,l,s,s,l,l,s,s,l,l,s,s,s,s,l,l,s);
	printf("\n");
	printf("                                      ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,l,c,l,d,d,l,c,l,l,s,s,l,l,l,l,l,s,s,s,l,l,s,l,l,s,l,l,s,s,l,l,s,s,s,s,l,l,s);
	printf("\n");
	printf("                                      ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,l,s,s,l,l,s,s,l,l,s,s,l,l,s,s,s,s,s,s,l,l,s,s,l,l,l,l,s,s,l,l,s,s,s,s,l,l,s);
	printf("\n");
	printf("                                      ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,l,s,s,s,s,s,s,l,l,s,s,c,l,l,l,l,l,s,s,l,l,s,s,s,c,l,l,s,s,s,c,l,l,l,l,c,s,s);
	printf("\n\n\n");
	
	//1.- iniciar sesion
	
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",d,l,s,s,s,s,s,s,s,s,s,s,d,d,d,s,d,s,s,s,d,s,d,d,d,s,d,d,d,s,d,d,d,s,s,d,d,s,s,d,d,d,s,s,s,s,s,s,d,d,s,d,d,d,s,s,d,d,s,d,d,d,s,s,d,d,s,s,d,s,s,s,d,s,s);
	printf("\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,d,d,s,s,s,s,s,s,l,s,s,l,c,d,s,l,s,s,l,s,s,l,s,s,s,s,l,s,s,l,d,d,l,s,l,d,d,c,s,s,s,s,c,d,s,s,l,d,s,s,c,d,s,s,s,l,s,s,l,s,s,l,s,l,c,d,s,l,s,s);
	printf("\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",d,l,d,s,d,s,s,s,s,s,s,s,d,l,d,s,l,s,s,c,l,s,d,l,d,s,l,d,d,s,d,l,d,s,l,s,s,l,s,l,s,s,l,s,s,s,s,d,d,c,s,l,d,d,s,d,d,c,s,d,l,d,s,c,d,d,c,s,l,s,s,c,l,s,s);
	printf("\n\n");
	//2.- creditos
	
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,l,s,s,s,s,s,s,s,s,s,d,d,d,s,d,d,d,s,s,d,d,d,s,d,d,d,s,s,d,d,d,s,d,d,d,s,s,d,d,s,s,s,d,d,s,s,s,s,s,s,s,s);
	printf("\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",d,d,l,s,s,d,d,s,s,s,s,s,l,s,s,s,l,d,d,c,s,l,d,s,s,l,s,s,l,s,s,l,s,s,s,l,s,s,l,s,s,l,s,c,d,s,s,s,s,s,s,s,s,s);
	printf("\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,d,d,s,d,s,s,s,s,s,s,s,l,d,d,s,l,s,s,l,s,l,d,d,s,l,d,d,c,s,d,l,d,s,s,l,s,s,c,d,d,c,s,d,d,c,s,s,s,s,s,s,s,s);
	printf("\n\n");
	//3.- salir
	
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,l,s,s,s,s,s,s,s,s,s,s,d,d,s,s,d,d,s,s,d,s,s,s,d,d,d,s,d,d,d,s,s);
	printf("\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",d,d,l,s,s,d,d,s,s,s,s,s,c,d,s,s,l,d,d,l,s,l,s,s,s,s,l,s,s,l,d,d,c,s);
	printf("\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",d,d,l,s,d,s,s,s,s,s,s,s,d,d,c,s,l,s,s,l,s,l,d,d,s,d,l,d,s,l,s,s,l,s);
	printf("\n\n");
	
	printf("                                              ");
	printf(" | Ingrese una opci%cn | ",162);
	printf("\n");
	printf("                                                     ");
	printf(" >> ");
	scanf("%d",&opcion);
	return opcion;

}
void iniciar_sesion(){

	
	system("COLOR 0F");
	carga_entorno();
	//Palabras: Acceder como:
	
	printf("                              ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,d,s,s,d,d,d,s,d,d,d,s,d,d,d,s,d,d,d,s,s,d,d,d,s,d,d,d,s,s,s,s,s,d,d,d,s,s,d,d,s,s,d,d,s,d,d,s,s,d,d,s,s,s,s,d,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
	printf("\n");
	printf("                              ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,d,d,d,l,s,l,s,s,s,l,s,s,s,l,d,s,s,l,s,s,l,s,l,d,s,s,l,d,d,c,s,s,s,s,l,s,s,s,l,s,s,l,s,l,c,l,c,l,s,l,s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
	printf("\n");
	printf("                              ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,s,s,s,l,s,l,d,d,s,l,d,d,s,l,d,d,s,l,d,d,c,s,l,d,d,s,l,s,l,s,s,s,s,s,l,d,d,s,c,d,d,c,s,l,s,s,s,l,s,c,d,d,c,s,s,s,c,s,s,s,s,s,s,s,s,s,s,s,s,s,s);               
	printf("\n\n");
	
	
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,d,c,c,c,c,c,c,c,c,c,c,c,c,c,c,d,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,d,c,c,c,c,c,c,c,c,c,c,c,c,c,c,d,s,s,s);
	printf("\n");
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,s,s,s,s,d,c,c,c,d,s,s,s,s,s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s,s,s,d,c,c,c,d,s,s,s,s,s,s,l,s,s);
	printf("\n");
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,l,s,s);
	printf("\n");
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,s,l,s);
	printf("\n");
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,s,s,c,d,d,d,c,s,s,s,s,s,s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s,s,s,s,c,d,d,d,c,s,s,s,s,s,s,s,l,s);
	printf("\n");
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,d,d,d,d,d,d,d,d,d,d,s,s,s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s,s,d,d,d,d,d,d,d,d,d,d,s,s,s,s,l,s);
	printf("\n");
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,l,l,l,l,l,l,l,l,l,l,l,l,s,s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s,l,l,l,l,l,l,l,l,l,l,l,l,s,s,s,l,s);
	printf("\n");
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,l,l,l,l,l,l,l,l,l,l,l,l,l,l,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,l,l,l,l,l,l,l,l,l,l,l,l,l,l,s,l,s,s);
	printf("\n");
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s);
	printf("\n");
	printf("                             ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,c,d,d,d,d,d,d,d,d,d,d,d,d,d,d,c,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,c,d,d,d,d,d,d,d,d,d,d,d,d,d,d,c,s,s,s);
	printf("\n");
	printf("                           ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,d,s,s,d,d,d,s,s,d,d,s,d,d,s,d,d,d,s,d,d,s,s,d,s,s,s,s,s,s,s,s,s,d,s,s,d,s,s,d,d,d,d,s,d,s,s,d,s,s,d,d,d,s,s,d,d,d,d,s,s,d,d,d,s,s,d,d,s,s);
	printf("\n");
	printf("                           ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,d,d,d,l,s,l,s,s,l,s,l,c,l,c,l,s,s,l,s,s,l,c,l,d,l,s,s,s,s,s,s,s,s,s,l,s,s,l,s,c,d,d,d,s,s,l,s,s,l,s,l,d,d,d,l,s,l,d,d,d,c,s,s,l,s,s,l,s,s,l,s);
	printf("\n");
	printf("                           ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,s,s,s,l,s,l,d,d,c,s,l,s,s,s,l,s,d,l,d,s,l,s,s,c,l,s,s,l,l,s,s,s,s,s,c,d,d,c,s,d,d,d,d,c,s,c,d,d,c,s,l,s,s,s,l,s,l,s,s,l,s,s,d,l,d,s,c,d,d,c,s);               
	printf("\n\n");
	
	printf("                                    ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,l,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,l,l,l,l,s);
	printf("\n");
	printf("                                    ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,l,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,d,d,d,d,l,s);
	printf("\n");  
	printf("                                    ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,l,l,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,d,d,d,d,s);
	printf("\n\n\n");
	
	
}
void carga_entorno(){
	system("cls");
	int tiempo=0;
	int contador=0;
	int dibujado=1;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	char mensaje[]= "                   CARGANDO ENTORNO(...)\n                               ";
	int bandera=0;
	int cw=0;
	printf("                               ");
	do {
		
		do {
			contador++;
		} while(contador<22999220);
		if(tiempo<9){
			
			bandera=0;
		}
		while(bandera==0){
			cw++;
			if(cw<2){
				printf(mensaje);
			}
			bandera=1;
		}
		
		for(int i=0;i<0+dibujado;i++){
			printf("%c",219);
			
		}
		tiempo++;
		contador=0;
		dibujado++;
		
	}while(tiempo<10);
	system("cls");
}
int opcionesMenuSesion()
{
	
	int opcion;
	fflush(stdin);
	system(CLEAR);
	iniciar_sesion();
	
	printf("                                                ");
	printf("|| Ingrese una opci%cn ||",162);
	printf("\n\n");
	printf("                                                       >>  ");
	scanf("%d",&opcion);
	
	while(opcion<0&&opcion>2)
	{
		printf("\n\nHas ingresado una opcion no valida!\n\n");
		printf("1. Iniciar sesion como Administrador\n");
		printf("2. Iniciar Sesion como Empleado\n");
		printf("Opcion: ");
		scanf("%d",&opcion);
	}
	return opcion;
}

int main()
{
	bienvenida();
	inicializarRegistros();
	cargarDatosaEmpleados();
	cargarDatosUsuarios_locker();
	fflush(stdin);
	carga_entorno();
	
	int opcion;
	do
	{
		
		opcion=opcionesMenuPrincipal();
		
		switch(opcion)
		{
		case 1:
			switch(opcionesMenuSesion())
			{
			case 1:
				InicioSesionAdministrador();
				break;
				
			case 2:
				inicioSesionEmpleado();
				break;
				
			default:
				imprimirError();
				break;
			}
			
			break;
			
		case 2:
			system("cls");
			creditos();
			break;
		case 3:
			printf("Hasta luego ^0^");
			return 0;
			
		default:
			imprimirError();
			pausa();
			break;
		}
		system(CLEAR);
	}
	while(opcion!=3);
	return 0;
}
void pausa()
{
	printf("\nPresiona Enter para continuar...");
	getch();
}
void ocultarClave(char *clave)
{
	fflush(stdin);
	int i=0;
	printf("\n");
	printf("                                                   ");
	printf("Contrase%ca: ",164);
	printf("\n");
	printf("                                                         >>");
	while(clave[i]!=ENTER)
	{
		clave[i]=getch();
		if(clave[i]>PRIMER_CARACTER_ASCII && i<TAMANO_CADENA)
		{
			putchar('*');
			i++;
		}
		else if(clave[i]==TECLA_RETROCESO && i>0)
		{
			putchar(TECLA_RETROCESO);
			putchar(' ');
			putchar(TECLA_RETROCESO);
			i--;
		}
	}
	clave[i]='\0';
	printf("\n");
}

booleano DatosCorrectosEmpleados(char *NicknameEmpleado, char *clave)
{
	int i;
	
	booleano datosEncontrados;
	for(i=0; i<Total_Empleados; i++)
	{
		
		if(strcmp(NicknameEmpleado,Empleados[i].NicknameEmpleado)==0&&
		   strcmp(clave,Empleados[i].clave)==0)
		{
			datosEncontrados=verdadero;
			break;
		}
		else
		{
			datosEncontrados=falso;
		}
	}
	if(datosEncontrados)
	{
		return verdadero;
		
	}
	else
	{
		return falso;
	}
}

void pedirDatosEmpleado(int i)
{
	fflush(stdin);
	printf("***Ingresa los datos***\n\n");
	printf("Nombre: ");
	gets(Empleados[i].nombre);
	fflush(stdin);
	printf("Nickname(nombre de usuario): ");
	gets(Empleados[i].NicknameEmpleado);
	fflush(stdin);
	ocultarClave(Empleados[i].clave);
	fflush(stdin);
	printf("Domicilio: ");
	gets(Empleados[i].domicilio);
	fflush(stdin);
	printf("Telefono: ");
	gets(Empleados[i].telefono);
	fflush(stdin);
	printf("Matricula: ");
	gets(Empleados[i].matricula);

}

void inicioSesionEmpleado()
{
	system(CLEAR);
	char clave [TAMANO_CADENA+1];
	char numTrabajadorIniciado[TAMANO_CADENA];
	fflush(stdin);
	
	sesion_empleado();
	printf("                                                   ");
	printf("Usuario(Nickname): ");
	printf("\n");
	printf("                                                        >>");
	gets(numTrabajadorIniciado);
	fflush(stdin);
	printf("\n");
	printf("                                                          ");
	ocultarClave(clave);
	while(strcmp(numTrabajadorIniciado,"\0")==0)
	{
		printf("\n\nEl nombre de usuario o contrase%ca son incorrectos...",164);
		printf("\nIngrese nuevamente");
		printf("\n");
		system("pause");
		system("cls");
		sesion_empleado();
		fflush(stdin);
		printf("                                                   ");
		printf("Usuario(Nickname): ");
		printf("\n");
		printf("                                                        >>");
		gets(numTrabajadorIniciado);
	}
	while(!DatosCorrectosEmpleados(numTrabajadorIniciado,clave))
	{
		printf("\n\nEl nombre de usuario o contrase%ca son incorrectos...",164);
		printf("\nIngrese nuevamente");
		printf("\n");
		system("pause");
		system("cls");
		sesion_empleado();
		fflush(stdin);
		printf("                                                   ");
		printf("Usuario(Nickname): ");
		printf("\n");
		printf("                                                          ");
		gets(numTrabajadorIniciado);
		fflush(stdin);
		printf("\n");
		printf("                                                          ");
		printf("\n");
		ocultarClave(clave);
		while(strcmp(numTrabajadorIniciado,"\0")==0)
		{
			printf("\n\nEl nombre de usuario o contrase%ca son incorrectos...",164);
			printf("\nIngrese nuevamente");
			printf("\n");
			system("pause");
			system("cls");
			sesion_empleado();
			fflush(stdin);
			printf("Usuario(Nickname): ");
			printf("\n");
			printf("                                                          ");
			gets(numTrabajadorIniciado);
			fflush(stdin);
			printf("\n");
			printf("                                                          ");
			printf("\n");
			ocultarClave(clave);
			
		}
	}
	pausa();
	menuEmpleado();
}

void cargarDatosUsuarios_locker()
{
	FILE *lecturaUsuarios_locker;
	
	booleano sinRegistros=verdadero;
	lecturaUsuarios_locker=fopen("UsuariosLockers.txt","r");
	
	int i=0;
	int lineasLeidas=0;
	char comprobador[TAMANO_CADENA+1];
	
	if(lecturaUsuarios_locker!=NULL)
	{
		
		while(fgets(comprobador,sizeof(comprobador),lecturaUsuarios_locker)!=NULL)
		{
			
			strtok(comprobador,"\n");
			lineasLeidas++;
			
			if(lineasLeidas==NOMBRE_LEIDO)
			{
				strcpy(usuarios_locker[i].nombre,comprobador);
			}
			
			if(lineasLeidas==Lockers_LEIDOS)
			{
				strcpy(usuarios_locker[i].locker,comprobador);
			}
			
			if(lineasLeidas==Fecha_LEIDO)
			{
				strcpy(usuarios_locker[i].fecha,comprobador);
			}
			
			if(lineasLeidas==FechaDevolucion_LEIDO)
			{
				strcpy(usuarios_locker[i].fecha_devolucion,comprobador);
			}
			
			if(lineasLeidas==MatriculaRenta_LEIDO)
			{
				strcpy(usuarios_locker[i].matricula_renta,comprobador);
			}
			
			if(lineasLeidas==TOTAL_ATRIBUTOS_Usuarios)
			{
				i++;
				cuentaUsuarios++;
				sinRegistros=falso;
				lineasLeidas=0;
			}
			
		}
		
		if(!sinRegistros)
		{
			printf("Se han cargado %d registros de los usuarios de los lockers\n\n",cuentaUsuarios);
			pausa();
		}
	}
	
	else
	{
		printf("No se pudo leer el archivo o aun no se ha registrado ninguna renta de locker!\n\n");
		pausa();
		
	}
	fclose(lecturaUsuarios_locker);
	system(CLEAR);
}


void cargarDatosaEmpleados()
{
	FILE *lecturaEmpleados;
	
	booleano sinRegistros=verdadero;
	lecturaEmpleados=fopen("Empleados.txt","r");
	
	int i=0;
	int lineasLeidas=0;
	char comprobador[TAMANO_CADENA+1];
	
	if(lecturaEmpleados!=NULL)
	{
		
		while(fgets(comprobador,sizeof(comprobador),lecturaEmpleados)!=NULL)
		{
			
			strtok(comprobador,"\n");
			lineasLeidas++;
			
			if(lineasLeidas==NOMBRE_LEIDO)
			{
				strcpy(Empleados[i].nombre,comprobador);
			}
			
			if(lineasLeidas==NicknameEmpleado_LEIDO)
			{
				strcpy(Empleados[i].NicknameEmpleado,comprobador);
			}
			
			if(lineasLeidas==CLAVE_LEIDA)
			{
				strcpy(Empleados[i].clave,comprobador);
			}
			
			if(lineasLeidas==DOMICILIO_LEIDO)
			{
				strcpy(Empleados[i].domicilio,comprobador);
			}
			if(lineasLeidas==TELEFONO_LEIDO)
			{
				strcpy(Empleados[i].telefono,comprobador);
			}
			if(lineasLeidas==MatriculaEmpleado_LEIDO)
			{
				strcpy(Empleados[i].matricula,comprobador);
			}
			
			if(lineasLeidas==TOTAL_ATRIBUTOS_EMPLEADOS)
			{
				i++;
				CuentaEmpleados++;
				sinRegistros=falso;
				lineasLeidas=0;
			}
			
		}
		
		if(!sinRegistros)
		{
			printf("Se han cargado %d registros de empleados!\n\n",CuentaEmpleados);
		}
	}
	
	else
	{
		printf("No se pudo leer el archivo o aun no se ha registrado a ningun empleado en el sistema!\n\n");
		
	}
	fclose(lecturaEmpleados);
}

int QueEmpleadoIngreso(char *NicknameEmpleado)
{
	int i;
	
	for(i=0; i<Total_Empleados; i++)
	{
		if(strcmp(NicknameEmpleado,Empleados[i].NicknameEmpleado)==0)
		{
			break;
		}
	}
	return i;
}


void AltaEmpleado()
{
	if(CuentaEmpleados<Total_Empleados)
	{
		pedirDatosEmpleado(CuentaEmpleados);
		CuentaEmpleados++;
		guardarArchivoEmpleados();
		historial_Trabajadores();
		printf("\n\nRegistro completado!");
	}
	else
	{
		printf("\n\nYa no hay mas espacio de captura!\n\n");
	}
	pausa();
}


void pedirDatosUsuario_locker(int i)
{
	fflush(stdin);
	printf("Nombre: ");
	gets(usuarios_locker[i].nombre);
	fflush(stdin);
	printf("#Locker ");
	gets(usuarios_locker[i].locker);
	fflush(stdin);
	printf("Fecha: ");
	gets(usuarios_locker[i].fecha);
	fflush(stdin);
	printf("Fecha de devoluci%cn: ",162);
	gets(usuarios_locker[i].fecha_devolucion);
	fflush(stdin);
	printf("Matricula: ");
	gets(usuarios_locker[i].matricula_renta);
	fflush(stdin);
	printf("Estado locker(escribir En renta): ");
	gets(usuarios_locker[i].estado);
	fflush(stdin);
}

void altaUsuario_locker()
{
	if(cuentaUsuarios<Total_Lockers)
	{
		pedirDatosUsuario_locker(cuentaUsuarios);
		cuentaUsuarios++;
		guardarArchivoUsuarios_locker();
		historial_lockers();
		printf("\n\nRegistro completado!");
	}
	else
	{
		printf("\n\nYa no hay mas espacio de captura!\n\n");
	}
	pausa();
}

void limpiarRegistroPelicula(int i)
{
	strcpy(usuarios_locker[i].nombre,"");
	strcpy(usuarios_locker[i].locker,"");
	strcpy(usuarios_locker[i].fecha,"");
	strcpy(usuarios_locker[i].fecha_devolucion,"");
	strcpy(usuarios_locker[i].matricula_renta,"");
}

void limpiarRegistroTrabajador(int i)
{
	strcpy(Empleados[i].NicknameEmpleado,"");
	strcpy(Empleados[i].clave,"");
	strcpy(Empleados[i].domicilio,"");
	strcpy(Empleados[i].nombre,"");
	strcpy(Empleados[i].telefono,"");
	strcpy(Empleados[i].matricula,"");
}

void inicializarRegistros()
{
	int i;
	for(i=0; i<Total_Empleados; i++)
	{
		limpiarRegistroTrabajador(i);
	}
	
	for(i=0; i<Total_Lockers; i++)
	{
		limpiarRegistroPelicula(i);
	}
}


void guardarArchivoEmpleados()
{
	FILE *escritura;
	escritura=fopen("empleados.txt","w");
	int i;
	for(i=0; i<CuentaEmpleados; i++)
	{
		fprintf(escritura,"%s\n",Empleados[i].nombre);
		fprintf(escritura,"%s\n",Empleados[i].NicknameEmpleado);
		fprintf(escritura,"%s\n",Empleados[i].clave);
		fprintf(escritura,"%s\n",Empleados[i].domicilio);
		fprintf(escritura,"%s\n",Empleados[i].telefono);
		fprintf(escritura,"%s\n",Empleados[i].matricula);
		
	}
	
	fclose(escritura);
}
void historial_Trabajadores()
{
	FILE *escritura;
	escritura=fopen("Historial_trabajadores.txt","w");
	int i;
	for(i=0; i<CuentaEmpleados; i++)
	{
		fprintf(escritura,"Nombre: %s\n",Empleados[i].nombre);
		fprintf(escritura,"Nickname(nombre de usuario): %s\n",Empleados[i].NicknameEmpleado);
		fprintf(escritura,"Contrase%ca: %s\n",164,Empleados[i].clave);
		fprintf(escritura,"Domicilio: %s\n",Empleados[i].domicilio);
		fprintf(escritura,"Telefono: %s\n",Empleados[i].telefono);
		fprintf(escritura,"Matricula: %s\n",Empleados[i].matricula);
		fprintf(escritura,"--------------------------------\n");
		
	}
	
	fclose(escritura);
}
void historial_lockers()
{
	int i;
	FILE *escritura;
	escritura=fopen("Historial_lockers.txt","w");
	
	for(i=0; i<cuentaUsuarios; i++)
	{
		fprintf(escritura,"Nombre: %s\n",usuarios_locker[i].nombre);
		fprintf(escritura,"#Locker: %s\n",usuarios_locker[i].locker);
		fprintf(escritura,"#Fecha de solicitud: %s\n",usuarios_locker[i].fecha);
		fprintf(escritura,"Fecha para devolver: %s\n",usuarios_locker[i].fecha_devolucion);
		fprintf(escritura,"Matricula: %s\n",usuarios_locker[i].matricula_renta);
		fprintf(escritura,"Estado actual: %s\n",usuarios_locker[i].estado);
		fprintf(escritura,"--------------------------------\n");
	}
	fclose(escritura);
}

void guardarArchivoUsuarios_locker()
{
	int i;
	FILE *escritura;
	escritura=fopen("UsuariosLockers.txt","w");
	
	for(i=0; i<cuentaUsuarios; i++)
	{
		fprintf(escritura,"%s\n",usuarios_locker[i].nombre);
		fprintf(escritura,"%s\n",usuarios_locker[i].locker);
		fprintf(escritura,"%s\n",usuarios_locker[i].fecha);
		fprintf(escritura,"%s\n",usuarios_locker[i].fecha_devolucion);
		fprintf(escritura,"%s\n",usuarios_locker[i].matricula_renta);
		fprintf(escritura,"%s\n",usuarios_locker[i].estado);
		
	}
	fclose(escritura);
}

void bienvenida()
{
	inicio_programa();
	
	printf("\n\n");
	printf("                                          ");
	printf("Presione enter para cargar el programa\n");
	printf("                                                          ");
	getch();
	system("cls");
	
	inicio_programa();
	carga_completa();
	
	system("COLOR 0A");
	
	printf("\n\n\n");
	printf("                                          ");
	system("pause");
	system("COLOR 0F");
	system(CLEAR);
	efecto_comprobacionArchivos();
	printf("                                    \n");
	printf("                                          ");
	printf("presione enter para continuar");
	getchar();
	system("cls");
	
}


void mostrarDatosEmpleado(int i)
{
	printf("\n\nNombre: %s\n",Empleados[i].nombre);
	printf("Nickname(nombre de usuario) %s\n",Empleados[i].NicknameEmpleado);
	printf("Clave: %s\n",Empleados[i].clave);
	printf("Domicilio: %s\n",Empleados[i].domicilio);
	printf("Telefono: %s\n",Empleados[i].telefono);
	printf("Matricula: %s\n\n",Empleados[i].matricula);
}

void mostrarDatosUsuarios_locker(int i)
{
	
	printf("\tNombre: %s\n",usuarios_locker[i].nombre);
	printf("\tFecha de devoluci%cn: %s\n",162,usuarios_locker[i].fecha_devolucion);
	printf("\t#Locker: %s\n",usuarios_locker[i].locker);
	printf("\tFecha de solicitud: %s\n",usuarios_locker[i].fecha);
	printf("\tMatricula: %s\n",usuarios_locker[i].matricula_renta);
}



void menuEmpleado(char *NicknameEmpleado)
{
	int i;
	int opcion;
	system(CLEAR);
	i=QueEmpleadoIngreso(NicknameEmpleado);
	do
	{
		printf("***Bienvenido %s***\n\n",Empleados[i].nombre);
		opcion=opcionesMenuEmpleado();
		
		switch(opcion)
		{
			system(CLEAR);
		case 1:
			menuRenta();
			break;
			
		case 2:
			break;

		default:
			imprimirError();
			break;
			
		}
	}
	while(opcion!=2);
	pausa();
}

void modificarUsuario_locker()
{
	char nombreBuscar[TAMANO_CADENA];
	fflush(stdin);
	printf("MODIFICAR UNA PELICULA\n\n");
	printf("Ingresa el nombre de la pelicula que deseas modificar: ");
	gets(nombreBuscar);
	if(coincideNombreUsuario_locker(nombreBuscar))
	{
		int i=damePosicionUsuario_locker(nombreBuscar);
		mostrarDatosUsuarios_locker(i);
		fflush(stdin);
		printf("***********************************************************************\n\n");
		printf("Nuevos Datos: \n\n");
		pedirDatosUsuario_locker(i);
		guardarArchivoUsuarios_locker();
		printf("\nRegistro Modificado!\n");
	}
	else
	{
		printf("\n\nNo se encontro ningun usuario  con ese nombre!\n");
	}
	
	pausa();
	
}
//eliminar el registro de un usuario al devolver el locker
void bajaUsuario_locker()
{
	char nombreBuscar[TAMANO_CADENA];
	fflush(stdin);
	char respuesta;
	printf("Devolver locker\n\n");
	printf("Ingresa el nombre del usuario que rento el locker: ");
	gets(nombreBuscar);
	if(coincideNombreUsuario_locker(nombreBuscar))
	{
		int i=damePosicionUsuario_locker(nombreBuscar);
		mostrarDatosUsuarios_locker(i);
		fflush(stdin);
		printf("\nDeseas borrar este registro de renta(s/n) : ");
		scanf("%c",&respuesta);
		fflush(stdin);
		if(respuesta=='s'||respuesta=='S')
		{
			for(cuentaUsuarios--; i<cuentaUsuarios; i++)
			{
				usuarios_locker[i]=usuarios_locker[i+1];
			}
			guardarArchivoUsuarios_locker();
			printf("\nRegistro Eliminado!\n");
		}
		else
		{
			printf("\nRegistro Conservado!\n");
		}
	}
	else
	{
		printf("\n\nNo se encontro ninguna renta de locker con ese nombre!\n");
	}
	
	pausa();
	
}
//mostrar los datos de los usurios que hayan pedido el uso de un locker
void listarUsuarios_locker()
{
	int i;
	if(cuentaUsuarios>0)
	{
		for(i=0; i<cuentaUsuarios; i++)
		{
			mostrarDatosUsuarios_locker(i);
		}
	}
	else
	{
		printf("\n\nNo hay ninguna renta de locker registrado!\n");
	}
	
	pausa();
}

void BuscarUsuario_locker()
{
	int encontrados=0;
	int i;
	char* patron;
	char nombreBuscar[TAMANO_CADENA];
	fflush(stdin);
	
	printf("Ingresa el nombre del usuario de locker que deseas buscar: ");
	gets(nombreBuscar);
	
	for(i=0; i<cuentaUsuarios; i++)
	{
		patron=strstr(usuarios_locker[i].nombre,nombreBuscar);
		if (patron!=NULL)
		{
			mostrarDatosUsuarios_locker(i);
			printf("\n\n");
			encontrados++;
		}
		
	}
	
	if (encontrados)
	{
		printf("Se encontro %d registro(s) con la palabra buscada\n",encontrados);
	}
	else
	{
		printf("No se encontro algun registro con la palabra buscada\n");
	}
	
	pausa();
	
	
}

booleano coincideNombreUsuario_locker(char* NombreUsuario)
{
	booleano coincide=falso;
	int i;
	
	for(i=0; i<cuentaUsuarios; i++)
	{
		if (strcmp(usuarios_locker[i].nombre,NombreUsuario)==0)
		{
			coincide=verdadero;
			break;
		}
	}
	
	return coincide;
	
}

int damePosicionUsuario_locker(char* NombreUsuario)
{
	int posicion;
	int i;
	
	for(i=0; i<cuentaUsuarios; i++)
	{
		if (strcmp(usuarios_locker[i].nombre,NombreUsuario)==0)
		{
			posicion=i;
			break;
		}
	}
	
	return posicion;
}

int OpcionesMenuEmpleado()
{
	fflush(stdin);
	int opcion;
	printf("1. Dar de alta a usuario\n");
	printf("2. Dar de baja a usuario\n");
	printf("3. Modificar usuario\n");
	printf("4. Buscar usuario\n");
	printf("5. Listar usuarios\n");
	printf("6. Salir\n\n");
	printf("Opcion: ");
	scanf("%d",&opcion);
	while(opcion<0||opcion>6)
	{
		fflush(stdin);
		printf("Opcion: ");
		scanf("%d",&opcion);
	}
	system(CLEAR);
	return opcion;
}

void menuRenta()
{
	int opcion;
	do
	{
		system(CLEAR);
		printf("Control de lockers-Servicio de renta\n\n");
		opcion=OpcionesMenuEmpleado();
		switch(opcion)
		{
		case 1:
			altaUsuario_locker();
			break;
			
		case 2:
			bajaUsuario_locker();
			break;
			
		case 3:
			modificarUsuario_locker();
			break;
			
		case 4:
			BuscarUsuario_locker();
			break;
			
		case 5:
			listarUsuarios_locker();
			break;
			
		case 6:
			break;
			
		default:
			imprimirError();
			break;
		}
		
		system(CLEAR);
	}
	while(opcion!=6);
	
}

int opcionesMenuEmpleado()
{
	fflush(stdin);
	int opcion;
	printf("1. Control de lockers\n");
	printf("2. Salir\n");
	printf("Opcion: ");
	scanf("%d",&opcion);
	while(opcion<0||opcion>3)
	{
		fflush(stdin);
		printf("Opcion: ");
		scanf("%d",&opcion);
	}
	system(CLEAR);
	return opcion;
}


void menuAdministrador()
{
	int opcion;
	do
	{
		system(CLEAR);
		printf("ADMINISTRACION DE EMPLEADOS DE --LOCKERS RENT--\n\n");
		opcion=OpcionesMenuAdministrador();
		switch(opcion)
		{
		case 1:
			AltaEmpleado();
			break;
			
		case 2:
			BajaEmpleado();
			break;
			
		case 3:
			ModificarEmpleado();
			break;
			
		case 4:
			BuscarEmpleado();
			break;
			
		case 5:
			ListarEmpleados();
			break;
			
		case 6:
			break;
			
		default:
			imprimirError();
			break;
		}
		system(CLEAR);
	}
	while(opcion!=6);
	
}


void ModificarEmpleado()
{
	char buscarNumero[TAMANO_CADENA];
	fflush(stdin);
	printf("MODIFICAR UN EMPLEADO\n\n");
	printf("Ingresa el nickname(nombre de usuario) del empleado que deseas modificar: ");
	gets(buscarNumero);
	if(coincideNicknameEmpleado(buscarNumero))
	{
		int i=damePosicionEmpleado(buscarNumero);
		mostrarDatosEmpleado(i);
		fflush(stdin);
		printf("***********************************************************************\n\n");
		printf("Nuevos Datos: \n\n");
		pedirDatosEmpleado(i);
		guardarArchivoEmpleados();
		printf("\nRegistro Modificado!\n");
	}
	else
	{
		printf("\n\nNo se encontro ningun empleado con el nickname especificado!\n");
	}
	
	pausa();
	
}


void BajaEmpleado()
{
	char buscarNumero[TAMANO_CADENA];
	fflush(stdin);
	char respuesta;
	printf("DAR DE BAJA UN EMPLEADO\n\n");
	printf("Ingresa el Nickname(Nombre de usuario) del empleado que deseas eliminar: ");
	gets(buscarNumero);
	if(coincideNicknameEmpleado(buscarNumero))
	{
		int i=damePosicionEmpleado(buscarNumero);
		mostrarDatosEmpleado(i);
		fflush(stdin);
		printf("\nDeseas borrar a este empleado (s/n) : ");
		scanf("%c",&respuesta);
		fflush(stdin);
		if(respuesta=='s'||respuesta=='S')
		{
			for(CuentaEmpleados--; i<CuentaEmpleados; i++)
			{
				Empleados[i]=Empleados[i+1];
			}
			guardarArchivoEmpleados();
			printf("\nRegistro Eliminado!\n");
		}
		else
		{
			printf("\nRegistro Conservado!\n");
		}
	}
	else
	{
		printf("\n\nNo se encontro ningun empleado con esa identificaci%cn!\n",162);
	}
	
	pausa();
	
}


void ListarEmpleados()
{
	int i;
	if(CuentaEmpleados>0)
	{
		for(i=0; i<CuentaEmpleados; i++)
		{
			mostrarDatosEmpleado(i);
		}
	}
	else
	{
		printf("\n\nNo hay ningun empleado registrado!\n");
	}
	
	pausa();
	
}


void BuscarEmpleado()
{
	int encontrados=0;
	int i;
	char* patron;
	char nombreBuscar[TAMANO_CADENA];
	fflush(stdin);
	
	printf("Ingresa el nombre del empleado que deseas buscar: ");
	gets(nombreBuscar);
	
	for(i=0; i<CuentaEmpleados; i++)
	{
		patron=strstr(Empleados[i].nombre,nombreBuscar);
		if (patron!=NULL)
		{
			mostrarDatosEmpleado(i);
			printf("\n\n");
			encontrados++;
		}
		
	}
	
	if (encontrados)
	{
		printf("Se encontro %d registro(s) con la palabra buscada\n",encontrados);
	}
	else
	{
		printf("No se encontro algun registro con la palabra buscada\n");
	}
	
	pausa();
	
}


booleano coincideNicknameEmpleado(char *NicknameEmpleado)
{
	int i;
	booleano coincide=falso;
	
	for(i=0; i<CuentaEmpleados; i++)
	{
		if(strcmp(NicknameEmpleado,Empleados[i].NicknameEmpleado)==0)
		{
			coincide=verdadero;
			break;
		}
	}
	
	return coincide;
	
}


int damePosicionEmpleado(char*NicknameEmpleado)
{
	int i;
	int posicion;
	
	for(i=0; i<CuentaEmpleados; i++)
	{
		if(strcmp(NicknameEmpleado,Empleados[i].NicknameEmpleado)==0)
		{
			posicion=i;
			break;
		}
	}
	
	return posicion;
	
}


int OpcionesMenuAdministrador()
{
	fflush(stdin);
	int opcion;
	printf("1. Dar de alta a un empleado\n");
	printf("2. Dar de baja a un empleado\n");
	printf("3. Modificar a un empleado\n");
	printf("4. Buscar a un empleado\n");
	printf("5. Listar empleados\n");
	printf("6. Salir\n\n");
	printf("Opcion: ");
	scanf("%d",&opcion);
	while(opcion<0||opcion>6)
	{
		fflush(stdin);
		printf("Opcion: ");
		scanf("%d",&opcion);
	}
	system(CLEAR);
	return opcion;
}

void InicioSesionAdministrador()
{
	system(CLEAR);
	fflush(stdin);
	char numero[TAMANO_CADENA];
	char clave [TAMANO_CADENA];
	sesion_administrador();
	
	printf("                                                   ");
	printf("Usuario(Nickname): ");
	printf("\n");
	printf("                                                        >>");
	gets(numero);
	fflush(stdin);
	printf("\n");
	printf("                                                          ");
	ocultarClave(clave);
	fflush(stdin);
	
	while(!datosCorrectosAdministrador(numero,clave))
	{
		printf("\n\nEl nombre de usuario o contrase%ca son incorrectos...",164);
		printf("\nIngrese nuevamente");
		printf("\n");
		system("pause");
		system("cls");
		sesion_administrador();
	
		printf("                                                   ");
		printf("Usuario(Nickname): ");
		printf("\n");
		printf("                                                        >>");
		gets(numero);
		fflush(stdin);
		printf("\n");
		printf("                                                          ");
		ocultarClave(clave);
		fflush(stdin);
	
	}
	
	pausa();
	menuAdministrador();
	pausa();
	
}

booleano datosCorrectosAdministrador(char* num, char* clave)
{
	booleano coincide=falso;
	
	char numeroGerente[]="admin";
	char claveGerente[]="admin";
	
	if(strcmp(num,numeroGerente)==0 && strcmp(clave,claveGerente)==0)
	{
		coincide=verdadero;
	}
	
	return coincide;
}

void sesion_administrador(){
	//Figura de incio de sesion
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,d,c,c,c,c,c,c,c,c,c,c,c,c,c,c,d,s,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,s,s,s,s,d,c,c,c,d,s,s,s,s,s,s,l,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,l,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,s,l,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,s,s,c,d,d,d,c,s,s,s,s,s,s,s,l,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,d,d,d,d,d,d,d,d,d,d,s,s,s,s,l,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,l,l,l,l,l,l,l,l,l,l,l,l,s,s,s,l,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,l,l,l,l,l,l,l,l,l,l,l,l,l,l,s,l,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,c,d,d,d,d,d,d,d,d,d,d,d,d,d,d,c,s,s,s,s);
	printf("\n");
	
	//Administrador
	printf("                                               ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,d,d,d,s,s,d,d,d,s,s,d,d,s,d,d,s,d,d,d,s,d,d,s,s,d,s,s,s,s,s);
	printf("\n");
	printf("                                               ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,d,d,d,l,s,l,s,s,l,s,l,c,l,c,l,s,s,l,s,s,l,c,l,d,l,s,s,s,s,s);
	printf("\n");
	printf("                                               ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,s,s,s,l,s,l,d,d,c,s,l,s,s,s,l,s,d,l,d,s,l,s,s,c,l,s,s,l,l,s);               
	printf("\n\n\n\n");
	
}
void sesion_empleado(){
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,d,c,c,c,c,c,c,c,c,c,c,c,c,c,c,d,s,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,s,s,s,s,d,c,c,c,d,s,s,s,s,s,s,l,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,l,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,s,l,s,s,s,s,s,l,s,s,s,s,s,s,l,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,s,s,c,d,d,d,c,s,s,s,s,s,s,s,l,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,s,d,d,d,d,d,d,d,d,d,d,s,s,s,s,l,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,l,s,s,s,l,l,l,l,l,l,l,l,l,l,l,l,s,s,s,l,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,l,l,l,l,l,l,l,l,l,l,l,l,l,l,s,l,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,l,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,l,s,s,s);
	printf("\n");
	printf("                                                 ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s,s,s,c,d,d,d,d,d,d,d,d,d,d,d,d,d,d,c,s,s,s,s);
	printf("\n");
	
	//Empleado
	printf("                                          ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",d,d,d,s,d,s,s,s,d,s,d,d,d,s,s,d,s,s,s,d,d,d,s,s,d,d,s,s,d,d,d,s,s,s,d,d,s,s,s,s,s);
	printf("\n");
	printf("                                          ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,d,s,s,l,c,d,c,l,s,l,d,d,c,s,l,s,s,s,l,d,s,s,l,d,d,l,s,l,s,s,l,s,l,s,s,l,s,s,s,s);
	printf("\n");
	printf("                                          ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,d,d,s,l,s,s,s,l,s,l,s,s,s,s,l,d,d,s,l,d,d,s,l,s,s,l,s,l,d,d,c,s,c,d,d,c,s,s,s,s);               
	printf("\n\n\n\n");
}
void inicio_programa(){
	system("COLOR 70");
	
	printf("\n\n\n\n");
	
	// Palabra LOCKERS
	printf("                                ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,s,s,s,s,s,l,l,l,l,s,s,s,s,l,l,l,l,s,s,s,l,l,s,s,s,l,l,s,s,l,l,l,l,l,l,s,s,l,l,l,l,l,l,d,s,s,s,l,l,l,l,l,s,s);
	printf("\n");
	printf("                                ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,s,s,s,s,l,l,s,s,l,l,s,s,l,l,s,s,l,l,s,s,l,l,s,s,l,l,s,s,s,l,l,s,s,s,s,s,s,l,l,s,s,s,l,l,s,s,l,s,s,s,s,s,s,s);
	printf("\n");
	printf("                                ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,s,s,s,s,l,l,s,s,l,l,s,s,l,l,s,s,s,s,s,s,l,l,l,l,s,s,s,s,s,l,l,l,l,s,s,s,s,l,l,l,l,l,c,s,s,s,s,l,l,l,l,s,s,s);
	printf("\n");
	printf("                                ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,s,s,s,s,l,l,s,s,l,l,s,s,l,l,s,s,l,l,s,s,l,l,s,s,l,l,s,s,s,l,l,s,s,s,s,s,s,l,l,s,s,l,l,s,s,s,s,s,s,s,s,l,s,s);
	printf("\n");
	printf("                                ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,l,l,s,s,s,l,l,l,l,s,s,s,s,l,l,l,l,s,s,s,l,l,s,s,s,l,l,s,s,l,l,l,l,l,l,s,s,l,l,s,s,s,l,l,s,s,l,l,l,l,l,s,s,s);
	printf("\n\n");
	//Palabra RENT
	printf("                                          ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,l,l,l,l,d,s,s,l,l,l,l,l,l,s,s,l,l,l,s,s,s,l,l,s,s,l,l,l,l,l,l,l,l,s,s);
	printf("\n");
	printf("                                          ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,s,s,s,l,l,s,s,l,l,s,s,s,s,s,s,l,l,l,l,s,s,l,l,s,s,s,s,s,l,l,s,s,s,s,s);
	printf("\n"); 
	printf("                                          ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,l,l,l,c,s,s,s,l,l,l,l,s,s,s,s,l,l,s,l,l,s,l,l,s,s,s,s,s,l,l,s,s,s,s,s);
	printf("\n");
	printf("                                          ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,s,s,l,l,s,s,s,l,l,s,s,s,s,s,s,l,l,s,s,l,l,l,l,s,s,s,s,s,l,l,s,s,s,s,s);
	printf("\n");
	printf("                                          ");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",l,l,s,s,s,l,l,s,s,l,l,l,l,l,l,s,s,l,l,s,s,s,l,l,l,s,s,s,s,s,l,l,s,s,s,s,s);
	
}

int efecto_carga(){
	//Efecto de carga de programa
	
	int tiempo=0;
	int contador=0;
	int dibujado=1;
	printf("\n\n");
	char mensaje[]= "                        CARGANDO(...)\n                               ";
	int bandera=0;
	int cw=0;
	printf("                               ");
	do {
		
		do {
			contador++;
		} while(contador<22999220);
		if(tiempo<9){
			
			bandera=0;
		}
		while(bandera==0){
			cw++;
			if(cw<2){
				printf(mensaje);
			}
			
			
			bandera=1;
		}
		
		for(int i=0;i<dibujado;i++){
			printf("%c",219);
			
		}
		tiempo++;
		contador=0;
		dibujado++;
		/*system("COLOR 0F");
		system("COLOR 02");*/
		
		
		
		
		
	}while(tiempo<10);
	return cw;
}
void carga_completa(){
	char mensaje2[]= "                                                       COMPLETO                                 ";
	if(efecto_carga()==9){
		system("cls");
		inicio_programa();
		printf("\n\n\n");
		printf(mensaje2);
	}
}
void efecto_comprobacionArchivos(){
	//Efecto de carga de programa
	
	int tiempo=0;
	int contador=0;
	int dibujado=1;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	char mensaje[]= "                   COMPROBANDO ARCHIVOS(...)\n                               ";
	int bandera=0;
	int cw=0;
	printf("                               ");
	do {
		
		do {
			contador++;
		} while(contador<22999220);
		if(tiempo<9){
			
			bandera=0;
		}
		while(bandera==0){
			cw++;
			if(cw<2){
				printf(mensaje);
			}
			
			
			bandera=1;
		}
		
		for(int i=0;i<dibujado;i++){
			printf("%c",219);
			
		}
		tiempo++;
		contador=0;
		dibujado++;

	}while(tiempo<10);
}
