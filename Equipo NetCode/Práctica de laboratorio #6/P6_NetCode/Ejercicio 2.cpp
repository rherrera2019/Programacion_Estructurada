#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: 2do REPORTE DE NOMBRE, PESO Y ESTATURA
Descripción: que lea un arreglos de una estructura de arreglos
de n x 3 elementos que contenga el nombre, peso y estatura de 
n personas; determinar el peso y la estatura promedio, así como
imprimir el mismo reporte del anterior ejercicio.
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 2.0
Fecha: 9/03/2020
*/

int CuantasPersonas();
struct Datos IngresarDatosDePersonas(struct Datos Personas[], int NoPersonas);
double CalcularPromPeso(struct Datos Personas[], int NoPersonas);
double CalcularPromEstatura(struct Datos Personas[], int NoPersonas);
void ImpresionDeReporte(struct Datos Personas[], int NoPersonas, double PromPeso, double PromEstatura);

typedef struct Datos{
   char Nombre[30];
   double Peso;
   double Estatura;
};

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int i = 0, NoPersonas = 0;
	double PromPeso, PromEstatura;
	
	printf("\nSOFTWARE PARA REALIZAR REPORTE DE NOMBRES, PESO, ESTATURA \nY, PROMEDIO DE PESO Y ESTARURA.");
	NoPersonas = CuantasPersonas();//Validamos el número de personas
	//Leemos los datos de cada persona
	struct Datos Personas[NoPersonas];
	*Personas = IngresarDatosDePersonas(Personas, NoPersonas);
	//Calcular el promedio de peso
	PromPeso = CalcularPromPeso(Personas, NoPersonas);
	//Calcular el promedio de estatura
	PromEstatura = CalcularPromEstatura(Personas, NoPersonas);
	//Impresión de reporte
	ImpresionDeReporte(Personas, NoPersonas, PromPeso, PromEstatura);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//----------------Función para saber cuántas personas se registraran-----------
int CuantasPersonas()
{
	int NumeroPersonas;
	printf("\nIngrese el número de personas que se registraran (Mayor a 0), por favor: ");
	scanf("%d", &NumeroPersonas);
	if(NumeroPersonas <= 0)
	{
		printf("\n\nERROR, intente de nuevo...");
		NumeroPersonas = CuantasPersonas();
	}
	
	if(NumeroPersonas > 0)
	{
		return NumeroPersonas;
	}
}
//----------------Función para Ingresar datos de cada persona-------------------
Datos IngresarDatosDePersonas(Datos Personas[], int NoPersonas)
{
	int i = 0;
	while(i < NoPersonas)
	{
		printf("\nIngrese el nombre de la persona #%d, por favor: ", i + 1);
		scanf("%s", &Personas[i].Nombre);
		fflush(stdin);
		printf("\nIngrese el Peso de la persona #%d, por favor: ", i + 1);
		scanf("%lf", &Personas[i].Peso);
		fflush(stdin);
		printf("\nIngrese la Estatura de la persona #%d, por favor: ", i + 1);
		scanf("%lf", &Personas[i].Estatura);
		fflush(stdin);
		i++;
	}
	return *Personas;
}
//--------------------Función para Calcular el peso promedio---------------------
double CalcularPromPeso(Datos Personas[], int NoPersonas)
{
	int i = 0;
	double PromPeso = 0;
	while(i < NoPersonas)
	{
		PromPeso = PromPeso + Personas[i].Peso;
		i++;
	}
	return PromPeso/NoPersonas;
}
//--------------------Función para Calcular la Estatura promedio---------------------
double CalcularPromEstatura(Datos Personas[], int NoPersonas)
{
	int i = 0;
	double PromEstatura = 0;
	while(i < NoPersonas)
	{
		PromEstatura = PromEstatura + Personas[i].Estatura;
		i++;
	}
	return PromEstatura/NoPersonas;
}
//------------------------Función para Impresión de reporte---------------------------
void ImpresionDeReporte(Datos Personas[], int NoPersonas, double PromPeso, double PromEstatura)
{
	int i = 0;
	printf("\n\n                               REPORTE");
	printf("\nNOMBRE                    PESO                    ESTATURA");
	printf("\n-----------------------------------------------------------");
	while(i < NoPersonas)
	{
		printf("\n%s                    %.2lf                    %.2lf", Personas[i].Nombre, Personas[i].Peso, Personas[i].Estatura);
		i++;
	}
	printf("\n-----------------------------------------------------------");
	printf("\n                          %.2lf                    %.2lf", PromPeso, PromEstatura);
}
