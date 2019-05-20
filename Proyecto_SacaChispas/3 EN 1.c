/*
Puede haber problemas de visualización de las interfaces (rayas negras) o algunos contenidos
pueden no mostrarse completamente. Para solucionar el problema:

En la parte superior de la consola --> Presiona Click Derecho --> Propiedades --> Diseño --> 
Tamaño de la ventana --> Ancho: 100, Altura: 40 --> Aceptar.
*/

/*
Equipo: SacaChispas

Integrantes: 
- Javier Chim Cemé (58.62%)
- Nicolás Canul Ibarra (41.37%)

Official release: 20/05/19

Versión: 1.0

-->Repositorio Google Drive<--

https://docs.google.com/document/d/1fhDRu3_IXpqroh15wV-DwXa389W5SsMoF6TI38vk2HM/edit

-->Repositorio Github<--

https://github.com/HikingCarrot7/ProyectoFinal


Javier says: ¿Podrás encontrar los Easter eggs escondidos?

*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

//-------------------MACROS-------------------------
#define N 21
#define M 68

#define KEY_UP 328
#define KEY_DOWN 336
#define KEY_RIGHT 333
#define KEY_LEFT 331
#define ENTER 13

#define BHORIZONTAL 'O'
#define BVERTICAL '@'


FILE *fd;

//-------------------Funciones generales-------------------------
void inicio();
int menu();
void cuadradoInterfaz();
void gatoInterfaz();
void battleshipInterfaz();
void Color(int Background, int Text);
void jugadorUnoInterfaz();
void jugadorDosInterfaz();


void instructivo();


void palindrome();
void sistemaEcuaciones();
void breakout();


//----------------Funciones de los juegos------------------------
void gato();
void cuadro_magico();
void battleship();

//---------------Funciones propias del juego gato-----------------
void rellenarMatriz(int t[3][3]);
void imprimirInfo(int t[3][3], int turnoJ, int ganador, int empate);
int validar_punto(int x, int y, int turnoJ, int t[3][3]);
int turno(int turnoJugador);
int validacion(int t[3][3]);
void validar_ganador(int turno_jugador, int empate);
void imprimirMatriz(int t[3][3], int ganador, int empate);
void formatoGato(int t[3][3], int i, int j);

//---------------Funciones propias del juego cuadrado mágico-----------------
void numeros_aleatorios(int t[3][3], int vec[9], int intervalo_aleatorio);
void rellenar_matriz(int vec[9], int t[3][3]);
int validar_matriz(int t[3][3]);
void mostrar_matriz(int matriz_secundaria[3][3], int matriz[3][3]);
int checar_llenado(int matriz_secundaria[3][3], int t[3][3]);
void rellenar_matrizSecundaria(int matriz_secundaria[3][3], int t[3][3]);
void validar_numero(int trono_mayor, int trono_menor, int matriz_secundaria[3][3]);
void formatoCuadrado(int t[3][3], int i, int j);

//---------------Funciones propias del juego battelship-----------------
void rellenar(char t[11][21]);
void opcion_rellenado(char tj1[11][21], char tj2[11][21], int turnoJugador);
void rellenado_aleatorio(char t[11][21]);
void gestionarTurnos(char tj1[11][21], char tj2[11][21], char te1[11][21], char te2[11][21], int turnoJugador);
void imprimirTableroJugador(char t[11][21], char t2[11][21], char te[11][21], int tj);
int turno_actual(int turnoJugador);
void rellenado_manual(char t[11][21], int tj);
void impresion_turnos(int tj);
void validar_disparo(char t[11][21], char t2[11][21], char te[11][21], int tj);
void pedirContra(char contra[3], int leer);
void formato();
void tableroEnemigo(char t[11][21]);
int checar_tablero(char t1[11][21], char t2[11][21], int turno);

//---------------Funciones compartidas enter los 3 juegos-----------------
int direccionales(int filas, int columnas);
int volverAJugar();


//-----------------------Variables globales-------------------------------
int x = 0, y = 0, jgato = 0, jcuadrado = 0, jbattleship = 0, sum_general, solucion, acertado = 0, paint;
char contraj1[3], contraj2[3];

//-------------------Enumeración de colores para el coloreado de la consola-------------------------
enum Colors 
{ 
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LGREY = 7,
	DGREY = 8,
	LBLUE = 9,
	LGREEN = 10,
	LCYAN = 11,
	LRED = 12,
	LMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};






int main() 
{
	srand(time(NULL));
	
	/*Variable para guardar el valor de retorno de la función menú*/
	int juego;
	
	system("cls");
	
	/*Mostramos la interfaz de inicio (3 en 1)*/
	inicio();
	
	system("cls");
	
	/*La interfaz para seleccionar un minijuego puede retornar 49(Se presionó la tecla 1 para seleccionar el gato), 
	un 50(Si se presionó la tecla 2 para seleccionar el cuadrado mágico), un 51(Se presionó la tecla 3 para seleccionar el battleship) o
	un 73-105 (si se precionó la 'I' para mostrar el instructivo)*/
	juego = menu();
	
	/*Limpiamos las interfaces de la consola*/
	system("cls");
	
	/*switch para la opción elegida*/
	switch(juego)
	{
		
	case 49:
		
		
		jcuadrado = 0;
		jgato = 1;
		jbattleship = 0;
		
		/*Mostramos la interfaz del gato*/
		gatoInterfaz();
		
		/*Nos vamos al juego gato*/
		gato();
		
		
		break;
		
	case 50:
		
		jcuadrado = 1;
		jgato = 0;
		jbattleship = 0;
		
		/*Mostramos la interfaz del cuadrado mágico*/
		cuadradoInterfaz();
		
		/*Nos vamos al juego del cuadro mágico*/
		cuadro_magico();
		
		break;
		
	case 51:
		
		jcuadrado = 0;
		jgato = 0;
		jbattleship = 1;
		
		/*Mostramos la interfaz del battleship*/
		battleshipInterfaz();
		
		/*Nos vamos al juego battleship*/
		battleship();
		
		break;
		
	case 52:
		
		/*Ignorar*/
		palindrome();
		
		break;
		
	case 73:
		
	case 105:
		
		/*Mostramos el instructivo*/
		instructivo();
		
	default:
		
		break;
	}
	
	return 0;
}

//---------------------------------Juego del gato------------------------------------

void gato()
{
	/*Matriz que será nuestro tablero*/
	int tablero[3][3];
	/*VAriables para controlar los turnos de los jugadores, al ganador y el fin de la partida*/
	int turno_jugador = 0, ganador = 0, jugadas, empate, fin_partida;
	
	do
	{
		/*Rellenamos la matriz con ceros.*/
		rellenarMatriz(tablero);
		
		/*Inicializamos las variables en cada inicio de partida*/
		turno_jugador = 0;
		ganador = 0;
		jugadas = 0;
		empate = 0;
		fin_partida = 0;
		
		/*Borramos el contenido de la consola*/
		system("cls");
		
		do
		{
			/*La función 'turno' nos actualiza el turno actual del jugador. Si es el turno del jugador 1 nos retornará un 1, en caso contrario
			nos retorna un 0*/
			turno_jugador = turno(turno_jugador);
			
			/*Imprimimos el tablero para jugar*/
			imprimirInfo(tablero, turno_jugador, ganador, empate);
			
			/*Validamos al cada jugada que se haga en el tablero. Si un jugador ya ganó, la función nosretorna un 1.*/
			ganador = validacion(tablero);
			
			if (ganador != 1)
			{
				system("cls");
			}
			
			/*Aumentamos el número de jugadas(si llegamos a 9 y ninguno de los dos jugadores ganó entonces hubo un empate)*/
			jugadas++;
			
			if (jugadas == 9 && ganador == 0)
			{
				empate = 1;
			}
			
			/*Repetimos hasta que haya algún ganador o empate*/
		}while(ganador == 0 && empate == 0);
		
		/*Reinicimos las coordenadas del cuadro manipulado con las direcciones*/
		x = 0, y = 0;
		
		/*Imprimimos otra vez la matriz en la parte de abajo*/
		printf("\n\n");
		imprimirMatriz(tablero, ganador, empate);
		
		/*Validamos cuál de los dos jugadores o ganó o si hubo un empate*/
		validar_ganador(turno_jugador, empate);
		
		/*Preguntamos si se quiere volver a volverAJugar*/
		fin_partida = volverAJugar();
		
	}while(fin_partida == 0);
	
	printf("\n\nGracias por jugar! ");
	
	getch();
	
	/*Regresamos al main en caso de que no se quiera seguir jugando*/
	main();
	
}

void rellenarMatriz(int t[3][3])
{
	/*Rellenamos el tablero con ceros*/
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			t[i][j] = 0;
		}
	}
}

void imprimirInfo(int t[3][3], int turnoJ, int ganador, int empate)
{
	x = 0, y = 0;
	int fin = 0, filas = 2, columnas = 2;
	int posicion_valida = 0;
	
	printf("\n\n");
	
	do
	{
		do
		{
			fin = 0;
			system("cls");
			fflush(stdin);
			
			/*Mensaje de ayuda*/
			printf("Use las direccionales para moverse por el tablero\n\n");
			
			/*Imprimimos el tablero del juego*/
			imprimirMatriz(t, ganador, empate);
			
			/*Usamos la función direccionales para mover un pequeño cuadro sobre el tablero, como esta función se usa entre los 3 juegos,
			necesitamos mandarle el numeros de filas y columnas de nuestro tablero actual(evitar que el cuadro se salga del tablero).
			
			Esta función retorna un 0 si se presiona otra tecla que no sea el enter*/
			fin = direccionales(filas, columnas);
			
		}while(fin == 0);
		
		/*Validamos el punto*/
		posicion_valida = validar_punto(x, y, turnoJ, t);
		
	}while(posicion_valida == 0);
}

int turno(int turnoJugador)
{
	/*Si el turno del jugador es 0, mostramos la interfaz del jugador 1 y retornamos un 1(será el turno del jugador 2 en la siguiente iteración)*/
	if (turnoJugador == 0)
	{
		jugadorUnoInterfaz();
		
		getch();
		
		return 1;
		
		
	} else 
	{
		/*Mostramos la interfaz del jugador 2 si el turno es 1, retornamos un 0 (será el turno del jugador 1 en la siguiente iteración)*/
		jugadorDosInterfaz();
		
		getch();
		
		return 0;
		
	}
}

int validar_punto(int x, int y, int turnoJ, int t[3][3])
{
	
	/*Si es el turno del jugador 2 y sobre las coordenadas en 'x' y 'y' del cuadrado hay un espacio, enconces podemos poner un '2'(significa una 'O', se
	utilizó de esa forma para el fácil manejo de la matriz). Es el mismo caso para el jugador 1*/
	if (turnoJ == 0 && t[x][y] == 0)
	{
		t[x][y] = 2;
		
		/*Retornamos un 1, significa que el punto se validó correctamente*/
		return 1;
		
		
	} else if (turnoJ == 1 && t[x][y] == 0)
	{
		t[x][y] = 1;
		
		return 1;
		
	} else 
	{
		/*Retornamos un 0, significa que el punto está ocupado*/
		printf("\n\nPosición ocupada");
		
		getch();
		
		return 0;
		
	}
}

int validacion(int t[3][3])
{
	/*Variables locales para la validación de las jugadas*/
	int cont_filas = 0, cont_columnas = 0, cont_principal = 0, cont_inversa = 0;
	
	/*Recorremos nuestro tablero*/
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			/*Si nuestra primera posición está vacía o es diferente con las otras posiciones de esa fila aumentamos el contador('aumentar el contador'
			significa que no se ha formado alguna fila por cualquiera de los dos jugares)*/
			if(t[i][j] == 0 || (t[i][0] != t[i][1] || t[i][0] != t[i][2]))
			{
				cont_filas++;
			}
			
			/*Procedemos a usar la misma técnica con la diagonal de la matriz, aumentamos el contador si no se ha formado alguna diagonal por 
			cualquiera de los 2 jugadores*/
			if (i == j && (t[i][j] == 0 || t[0][0] != t[1][1] || t[0][0] != t[2][2]))
			{
				cont_principal++;
				
			}
			
			/*Hacemos exactamente lo mismo para la columnas(únicamente intercambiamos los índices), se aumenta el contador  si alguno de los 2 jugadores
			NO ha formado una columna*/
			if(t[j][i] == 0|| (t[0][i] != t[1][i] || t[0][i] != t[2][i]))
			{
				cont_columnas++;
			}
			
		}
		
		/*Si alguno de los contadores NO AUMENTÓ significa que ya se ha formado alguna fila, columna o diagonal*/
		if(cont_filas == 0 || cont_principal == 0 || cont_columnas == 0)
		{
			return 1;
			
		}
		
		/*Reiniciamos las variables por cada fila y columna*/
		cont_columnas = 0;
		
		cont_filas = 0;
	}
	
	/*Para la diagonal inversa usamos exactamente la misma téctica utilizada en las anteriores, lo único que cambia en este caso es
	la forma en la que recorremos la matriz*/
	for (int i = 2, j = 0; i >= 0; i--, j++)
	{
		if(t[i][j] == 0 || t[2][0] != t[1][1] || t[2][0] != t[0][2])
		{
			
			cont_inversa++;
			
		}
		
		/*Si el contador es igual a 0, entonces ya se ha formado la diagonal principal por cualquier de los 2 jugadores*/
		if(cont_inversa == 0)
		{
			return 1;
			
		}
		
	}
	
	/*Retornamos un 0 si no se ha formado alguna fila, columna o diagonal*/
	return 0;
}

void validar_ganador(int turno_jugador, int empate)
{
	/*Si el turno del jugador es igual a 0 y NO hubo un empate, entonces ganó el jugador 2. En caso contrario ganó el jugador 1*/
	if (turno_jugador == 0 && empate == 0)
	{
		printf("\n\nHa ganado el jugador 2");
		
	} else if (turno_jugador == 1 && empate == 0)
	{
		printf("\n\nHa ganado el jugador 1");
		
	} else
	{
		/*Hubo un empate si ninguno de los dos jugadores ganó*/
		printf("\n\nHubo un empate");
	}
}

void imprimirMatriz(int t[3][3], int ganador, int empate)
{
	/*Función destinada a la impresión y coloreado del tablero principal*/
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(ganador == 0 && empate == 0 && jgato)
			{
				if (i == x && j == y && j == 0)
				{
					Color(BLACK, WHITE);
					
					printf("               [");
					
					Color(BLACK, LMAGENTA);
					
					printf("%c", 219);  
					
					Color(BLACK, WHITE);	
					
					printf("]");
					
				}else if (i == x && j == y)
				{
					Color(BLACK, WHITE);
					
					printf("[");
					
					Color(BLACK, LMAGENTA);
					
					printf("%c", 219);  
					
					Color(BLACK, WHITE);	
					
					printf("]");
					
				}else 
				{
					formatoGato(t, i, j);
				}
				
				
			}else if (jgato)
			{
				formatoGato(t, i, j);
			}
			
		}
		
		printf("\n");
		
	}
}

void formatoGato(int t[3][3], int i, int j)
{
	/*Función destinada a la impresión y coloreado del tablero secundario que se imprime en la parte de abajo
	después de que una partida haya terminado*/
	if (j == 0 && t[i][j] == 0)
	{
		Color(BLACK, WHITE);
		
		printf("               [%c]", 45);
		
	}else if (j == 0 && t[i][j] == 1)
	{
		Color(BLACK, WHITE);
		
		printf("               [");
		
		Color(BLACK, LCYAN);
		
		printf("%c", 88);
		
		Color(BLACK, WHITE);
		
		printf("]");
		
	}else if(j == 0 && t[i][j] == 2)
	{
		Color(BLACK, WHITE);
		
		printf("               [");
		
		Color(BLACK, YELLOW);
		
		printf("%c", 79);
		
		Color(BLACK, WHITE);
		
		printf("]");
		
	} else if(t[i][j] == 0)
	{
		Color(BLACK, WHITE);
		
		printf("[%c]", 45);
		
	}else if(t[i][j] == 1)
	{
		Color(BLACK, WHITE);
		
		printf("[");
		
		Color(BLACK, LCYAN);
		
		printf("%c", 88);
		
		Color(BLACK, WHITE);
		
		printf("]");
		
	}else 
	{
		Color(BLACK, WHITE);
		
		printf("[");
		
		Color(BLACK, YELLOW);
		
		printf("%c", 79);
		
		Color(BLACK, WHITE);
		
		printf("]");	}
	
	Color(BLACK, WHITE);
	
}

//---------------------------------Juego del cuadrado mágico------------------------------------

void cuadro_magico()
{
	/*Reiniciamos las coordenadas en 'X' y 'Y' del cuadrado manipulado por las direccionales*/
	x = 0, y = 0;
	
	/*Inicilizamos los arrays*/
	int vec[9], matriz[3][3], matriz_secundaria[3][3], rellenado_perfecto, intervalo_aleatorio;
	
	int fin_juego = 0;
	
	int tecla;
	
	do
	{
		solucion = 0;
		
		sum_general = 0;
		
		/*Borramos la interfaz que se mostraba anteriormente*/
		system("cls");
		
		printf("\nSeleccione una dificultad\n\n1. Fácil\n2. Normal\n3. Difícil\n");
		
		/*Validamos el número presionado con el teclado*/
		do
		{
			fflush(stdin);
			
			tecla = getch();
			
			
		}while(tecla > 51 || tecla <  49);
		
		switch(tecla)
		{
		case 49:
			
			/*Si la dificultad es fácil, el intervalo de números a generar es de 1 - 11 (se les sumará 9 a cada número)*/
			intervalo_aleatorio = 1 + rand()%11;
			
			break;
			
		case 50:
			
			/*Si la dificultad es fácil, el intervalo de números a generar es de 20 - 30 (se les sumará 9 a cada número)*/
			intervalo_aleatorio = 20 + rand()%31;
			
			break;
			
		case 51:
			
			/*Si la dificultad es fácil, el intervalo de números a generar es de 50 - 30 (se les sumará 9 a cada número)*/
			intervalo_aleatorio = 50 + rand()%31;
			
			break;
			
			
		default:
			
			break;
			
		}
		
		/*Rellenamos y validamos la martiz con los números a mostrar (dependerá de la dificultad)*/
		numeros_aleatorios(matriz, vec, intervalo_aleatorio);
		
		/*Rellenamos una matriz secundaria (está matriz es la que se mostrará en pantalla y se comparará con la original)*/
		rellenar_matrizSecundaria(matriz_secundaria, matriz);
		
		do
		{
			/*Limpiamos la consola*/
			system("cls");
			
			/*Mostramos la matriz secundaria en pantalla*/
			mostrar_matriz(matriz_secundaria, matriz);
			
			/*Checamos si ya se ha rellenado correctamente la matriz*/
			rellenado_perfecto = checar_llenado(matriz_secundaria, matriz);
			
		} while (rellenado_perfecto == 0);
		
		printf("\n\nHas completado el cuadrado mágico!\n\n");
		
		/*Preguntamos si se quiere volver a jugar*/
		fin_juego = volverAJugar();
		
	} while(fin_juego == 0);
	
	printf("\n\nGracias por jugar! ");
	
	getch();
	
	/*Regresamos al main*/
	main();
	
}

void numeros_aleatorios(int t[3][3], int vec[9], int intervalo_aleatorio)
{
	/*Variables locales*/
	/*El sistema genera un vector con número aleatorios y sin repetición(dependiendo de la dificultad), luego se pasan a una matriz y se validan*/
	int sin_repeticion, aux, encontrado, validar;
	
	printf("\nLoading...");
	
	do
	{
		/*Reiniciamos la variable que valida la suma de cada fila, columna y diagonal*/
		sum_general = 0;
		
		/*VAriable para validar que no se repita algún número en nuestro array*/
		sin_repeticion = 0;
		
		/*Inicilizamos la matriz en ceros*/
		rellenarMatriz(t);
		
		/*Inicializamos el vector en ceros*/
		for(int i = 0; i < 9; i++)
		{
			vec[i] = 0;
		}
		
		do
		{
			
			encontrado = 0;
			
			/*Variable auxiliar para guadar los números aleatorios*/
			aux = intervalo_aleatorio + rand()%10;
			
			/*Se valida que dicho núero no se haya repetido, en caso de repetición se vuelve a generar otro número*/
			for(int i = 0; i < 9; i++)
			{
				if (vec[i] == aux)
				{
					encontrado = 1;
					
					break;
				}
			}
			
			/*El número se guardará si no se repite*/
			if (encontrado == 0)
			{
				vec[sin_repeticion] = aux;
				
				sin_repeticion++;
			}
			
			/*Repetimos esto hasta que el vector se llene sin números repetidos(serán números que estarán dento de un intervalo dependiendo la dificultad)*/
		} while(sin_repeticion < 9);
		
		/*Rellenamos la matriz*/
		rellenar_matriz(vec, t);
		
		/*Validamos que la matriz(previamente rellenada con el array que generamos antes)*/
		validar = validar_matriz(t);
		
		if (validar == 8)
		{
			system("cls");
		}
		
	} while (validar < 8);
	
}

void rellenar_matriz(int vec[9], int t[3][3])
{
	/*Rellenamos la matriz con los números almacenados en el vector*/
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			t[i][j] = vec[(i*3) + j]; 
			
		}
		
	}
}

int validar_matriz(int t[3][3])
{
	/*Variables locales*/
	int sum_actual = 0, validar = 0;
	
	/*Validamos que todas las filas de la matriz sumen lo mismo*/
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			sum_actual += t[i][j];
		}
		
		if (i == 0)
		{
			/*La suma general será el total que sume la primera fila*/
			sum_general = sum_actual;
		}
		
		/*Aumentamos el contador 'validar' si la suma general concuerda con la suma de cada fila*/
		if (sum_general == sum_actual) 
		{
			validar++;
			
		}
		
		sum_actual = 0;
	}
	
	/*Repetimos exactamente lo mismo con las columnas*/
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			sum_actual += t[j][i];
		}
		
		if (sum_general == sum_actual) 
		{
			validar++;
			
		}
		
		sum_actual = 0;
	}
	
	/*Repetimos lo mismo con la diqgonal principal*/
	for(int i = 0; i < 3; i++)
	{
		
		sum_actual += t[i][i];
		
		if (sum_actual == sum_general && i == 2) 
		{
			validar++;
			
		}		
	}
	
	sum_actual = 0;
	
	/*Exactamente lo mismo con la diagonal inversa*/
	for(int i = 2, j = 0; i >= 0; i--, j++)
	{
		
		sum_actual += t[i][j];
		
		if (sum_actual == sum_general && i == 0) 
		{
			validar++;
			
		}
		
	}
	
	return validar;
	
}

void mostrar_matriz(int matriz_secundaria[3][3], int matriz[3][3])
{
	/*Variables locales de la función*/
	int trono_mayor = 0, trono_menor = matriz[0][0], fin = 0, filas = 2, columnas = 2;
	
	/*Reiniciamos las coordenadas del cuadro controlado por las direccionales*/
	x = 0, y = 0;
	
	/*Buscamos al menor y mayor del intervalo generado*/
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if (matriz[i][j] > trono_mayor)
			{
				trono_mayor = matriz[i][j];
				
			} 
			
			if (matriz[i][j] < trono_menor)
			{
				trono_menor = matriz[i][j];
				
			}
			
		}
		
	}
	
	do
	{
		/*Limpiamos la consola cada vez que se hace un movimiento con las direccionales*/
		system("cls");
		
		/*Información*/
		printf("Cada fila, columna y diagonal debe sumar %i\nEl intervalo es de %i - %i", sum_general, trono_menor, trono_mayor);
		printf("\nPresione 'S' si desea ver la solución\n\n");
		
		/*Imprimimos la matriz*/
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				
				if(x == i && y == j && j == 0 )
				{
					printf("               [%c%c]", 219, 219);
				}
				else if (x == i && y == j)
				{
					printf("[%c%c]", 219, 219);
					
				}else
				{
					/*Función para darle formato a la impresión del tablero al imprimirse*/
					formatoCuadrado(matriz_secundaria, i, j);
				}
				
			}
			
			printf("\n");
			
		}
		
		printf("\n\n");
		
		
		/*Imprimimos la solución en caso de que se presione la 'S' en el teclado*/
		if (solucion)
		{
			printf("\n\n               Solución:\n");
			
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
				{
					/*Reusamos la función para darle formato al tablero que se imprime unas líneas abajo*/
					formatoCuadrado(matriz, i, j);
					
				}
				
				printf("\n");
				
			}
		}		
		
		/*Mientras no se presione 'ENTER' el ciclo continuará(se seguirá movimiendo por el tablero usando las direccionales)*/
		fin = direccionales(filas, columnas);
		
	}while(fin == 0);
	
	/*Validamos rápidamente que no se haya dado 'ENTER' en cualquiera de los puntos (0,0), (0,2) y (2,2) (Ahí ya están establecidos 3 números 
	por defecto y no pueden modificarse por el usuario)*/
	if((x == 0 && y == 0) || (x == 0 && y == 2) || (x == 2 && y == 2))
	{
		
		printf("\n\nPosición ocupada");
		
		getch();
		
		
	}else
	{
		/*Validamos que el número se encuentre dentro del intervalo*/
		validar_numero(trono_mayor, trono_menor, matriz_secundaria);
	}
	
}

void validar_numero(int trono_mayor, int trono_menor, int matriz_secundaria[3][3])
{
	int validar_posicion = 1, aux;
	
	char numero[2];
	
	printf("\nInserte su número ");
	
	do
	{
		validar_posicion = 1;
		
		fflush(stdin);
		
		/*Leemos un número*/
		scanf("%s", numero);
		
		/*Validamos que sea un número el que se insertó*/
		for(int i = 0; i < strlen(numero); i++)
		{
			if(!(isdigit(numero[i])))
			{
				printf("\n\nNo insertaste un número\n\nNúmero ");
				
				validar_posicion = 0;
				
				break;
				
			}
		}
		
		if(validar_posicion)
		{
			/*Convertimos los caracteres ingresados(en caso de que si sean un número) a dígitos*/
			aux = atoi(numero);
			
			/*Validamos que dicho número esté dentro del intervalo antes generado*/
			if ((aux > trono_mayor || aux < trono_menor) && aux != 0)
			{
				validar_posicion = 0;
				
				printf("\n\nNúmero NO válido \n\nNúmero ");
				
			} else 
			{
				/*Ponemos ese número en la matriz*/
				matriz_secundaria[x][y] = aux;
				
				validar_posicion = 1;
			}
			
		}
		
		/*Se repite hasta que se inserte un número válido*/
	} while (validar_posicion == 0);
}

int checar_llenado(int matriz_secundaria[3][3], int t[3][3])
{
	int cont = 0;
	
	/*Checamos que la matriz secundaria (la que se imprime) sea igual a la matriz original*/
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(matriz_secundaria[i][j] == t[i][j])
			{
				cont++;
			}
		}
		
	}
	
	if (cont == 9)
	{
		
		return 1;
		
	}else
	{
		return 0;
	}
	
}

void rellenar_matrizSecundaria(int matriz_secundaria[3][3], int t[3][3])
{
	/*Rellenamos la matriz secundaria en el punto (0,0) (0,2) y (2,2) con la matriz original */
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			
			if((i == 0 && j == 0) || (i == 0 && j == 2) || (i == 2 && j == 2))
			{
				matriz_secundaria[i][j] = t[i][j];
				
			} else 
			{
				matriz_secundaria[i][j] = 0;
				
			}
		}
	}
}

void formatoCuadrado(int t[3][3], int i, int j)
{
	/*Función destinada a darle formato a la impresión de nuestro tablero*/
	if (t[i][j] < 10 && j == 0)
	{
		printf("               [0%i]", t[i][j]);
		
	} else if (j == 0)
	{
		printf("               [%i]", t[i][j]);
		
	}else if (t[i][j] < 10)
	{
		printf("[0%i]", t[i][j]);
		
	}else
	{
		printf("[%i]", t[i][j]);
	}
	
}

//---------------------------------Juego del battleship------------------------------------
void battleship()
{
	/*Inicializamos los tableros para los jugadores*/
	char tablero_jugador1[11][21];
	char tablero_jugador2[11][21];
	
	char tablero_enemigo1[11][21];
	char tablero_enemigo2[11][21];
	
	int turno_jugador = 1, cont = 0, fin_partida = 0, jugarOtraVez = 0;
	
	do
	{
		/*Inicializamos los tableros con espacios*/
		rellenar(tablero_jugador1);
		rellenar(tablero_jugador2);
		rellenar(tablero_enemigo1);
		rellenar(tablero_enemigo2);
		
		/*Inicializamos las variables*/
		turno_jugador = 1, cont = 0, fin_partida = 0, jugarOtraVez = 0;
		
		/*Rellenamos los tableros*/
		while (cont++ < 2)
		{
			system("cls");
			
			opcion_rellenado(tablero_jugador1, tablero_jugador2, turno_jugador);
			
			turno_jugador = 0;
		}
		
		/*Turno del jugador 1*/
		turno_jugador = 1;
		
		system("cls");
		
		do
		{
			/*Obtenemos el turno del jugador actual y actualizamos*/
			turno_jugador = turno_actual(turno_jugador);
			
			/*Gestionamos la impresión de los tableros dependiendo del turno del jugador*/
			gestionarTurnos(tablero_jugador1, tablero_jugador2, tablero_enemigo1, tablero_enemigo2, turno_jugador);
			
			/*Checamos el tablero para saber si a algún jugador ya no le quedan barcos(retornamos un 1 si ganó el jugador 2 o un 2 si ganó el jugador 1)*/
			fin_partida = checar_tablero(tablero_jugador1, tablero_jugador2, turno_jugador);
			
		}while(fin_partida == 0);
		
		/*Imprimimos al ganador*/
		if(fin_partida == 1)
		{
			system("cls");
			
			printf("\n\nEl jugador 2 ha destruido todos los barcos del enemigo...");
			
			getch();
			
			
		}else
		{
			system("cls");
			
			printf("\n\nEl jugador 1 ha destruido todos los barcos del enemigo...");
			
			getch();
			
		}
		
		/*Preguntamos si se quiere volver a jugar*/
		jugarOtraVez = volverAJugar();
		
	}while(jugarOtraVez == 0);
	
	printf("\n\nGracias por jugar!");
	
	getch();
	
	main();
	
}

void opcion_rellenado(char tj1[11][21], char tj2[11][21], int turnoJugador)
{
	int opcion, leer = 1;
	
	/*Le preguntamos al jugador 1 cómo quiere rellenar su tablero*/
	if (turnoJugador)
	{
		jugadorUnoInterfaz();
		
		printf("\n¿Cómo desea rellenar su tablero? (1. Manual o 2. Aleatorio) ");
		
		do
		{
			fflush(stdin);
			opcion = getch();
			
		}while(opcion != 49 && opcion != 50);
		
		switch(opcion)
		{
		case 49:
			
			/*Rellenado manual*/
			rellenado_manual(tj1, turnoJugador);
			
			break;
			
		case 50:
			
			/*Rellenado aleatorio*/
			rellenado_aleatorio(tj1);
			
			break;
			
		default:
			
			break;
			
		}
		
		/*Pedimos contraseña*/
		pedirContra(contraj1, leer);
		
	}else
	{
		jugadorDosInterfaz();
		
		/*Preguntamos al jugador 2 cómo quiere rellenar su tablero*/
		printf("\n¿Cómo desea rellenar su tablero? (1. Manual o 2. Aleatorio) ");
		
		do
		{
			fflush(stdin);
			opcion = getch();
			
		}while(opcion != 49 && opcion != 50);
		
		switch(opcion)
		{
		case 49:
			
			/*Rellenado manual*/
			rellenado_manual(tj2, turnoJugador);
			
			break;
			
		case 50:
			
			/*Rellenado aleatorio*/
			rellenado_aleatorio(tj2);
			
			break;
			
		default:
			
			break;
			
		}
		
		/*Pedir contraseña*/
		pedirContra(contraj2, leer);
		
	}
}

void rellenado_aleatorio(char t[11][21])
{
	/*Variables locales*/
	int fila, longitud = 2, columna, barcos = 0, validar_fila = 1;
	int longitud_vertical = 3, choque, vertical;
	
	/*Para el rellenado aleatorio, lo único que hacemos es generar filas y columnas dentro de un rango establecido (para evitar que que se salgan del tablero)
	y después validar que en ese espacio no haya otro barco muy cerca o un choque*/
	do
	{
		
		srand(time(NULL));
		
		do
		{
			
			validar_fila = 1;
			
			/*Generamos la fila y columna aleatoriamente*/
			fila = rand()%10;
			
			columna = rand()%15;
			
			/*Validamos que en ese espacio no haya un choque*/
			for(int i = fila, j = columna; j < columna + longitud; j++)
			{
				if(t[i][j] == BHORIZONTAL || t[i][j] == BVERTICAL || t[i][j - 1] == BHORIZONTAL || t[i][j - 1] == BVERTICAL || 
					t[i - 1][j] == BHORIZONTAL || t[i - 1][j] == BVERTICAL || t[i + 1][j] == BHORIZONTAL || t[i + 1][j] == BVERTICAL || 
						t[i][j + 1] == BHORIZONTAL || t[i][j + 1] == BVERTICAL)
				{
					validar_fila = 0;
					
					break;
					
				}
			}
			
			/*Insertamos l barco en caso de que no haya un choque*/
			if(validar_fila)
			{
				for(int i = fila, j = columna; j < columna + longitud; j++)
				{
					
					t[i][j] = BHORIZONTAL;
					
				}
			}
			
		}while(validar_fila == 0);
		
		/*Hacemos exactamente lo mismo con los barcos verticales*/
		if (barcos < 3)
		{
			do
			{
				choque = 0;
				
				/*Generamos la fila y columna de manera aleatoria*/
				vertical = rand()%20;
				
				fila = rand()%8;
				
				/*Validamos que no haya un choque o se salga del tablero*/
				for(int i = fila, j = vertical; i < fila + longitud_vertical; i++)
				{
					if(t[i][j] == BHORIZONTAL || t[i][j] == BVERTICAL || t[i][j - 1] == BHORIZONTAL || t[i][j - 1] == BVERTICAL || 
						t[i - 1][j] == BHORIZONTAL || t[i - 1][j] == BVERTICAL || t[i + 1][j] == BHORIZONTAL || 
							t[i + 1][j] == BVERTICAL || t[i][j + 1] == BHORIZONTAL || t[i][j + 1] == BVERTICAL || fila + longitud_vertical > 10)
					{
						choque = 1;
						
						break;
						
					}
				}
				
			}while (choque);
			
			/*Insertamos el barco si no hubo algún choque*/
			for(int i = fila, j = vertical; i < fila + longitud_vertical; i++)
			{
				t[i][j] = BVERTICAL;
			}
			
			longitud_vertical++;
		}
		
		longitud++;
		barcos++;
		
	} while(barcos < 5);
	
	printf("\n\nTablero rellenado correctamente ");
	
	getch();
	
}

void gestionarTurnos(char tj1[11][21], char tj2[11][21], char te1[11][21], char te2[11][21], int turnoJugador)
{
	/*Si es turno del jugador 1, mandamos a imprimir su correspondientes tableros*/
	if(turnoJugador == 0)
	{
		turnoJugador = 1;
		
		/*Imprimimos sus tableros*/
		imprimirTableroJugador(tj1, tj2, te2, turnoJugador);
		
	}else
	{
		/*Si es turno del jugador 2, mandamos a imprimir sus correspondientes tableros*/
		turnoJugador = 0;
		
		/*Imprimimos sus tableros*/
		imprimirTableroJugador(tj2, tj1, te1, turnoJugador);
		
	}
}

void imprimirTableroJugador(char t[11][21], char t2[11][21], char te[11][21], int tj)
{
	int fin = 0, filas = 9, columnas = 19;
	x = 0, y = 0;
	
	do
	{
		system("cls");
		
		fflush(stdin);
		
		impresion_turnos(tj);
		
		Color(BLACK, WHITE);
		
		/*Este 'formato()' son la fila de números que aparecen en la parte superior de todos los tableros(simulando coordenadas)*/
		formato();
		
		printf("\n");
		
		/*Se imprime el tablero de la parte superior de cada jugador(donde están sus barcos)*/
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				if(t[i][j] == BHORIZONTAL || t[i][j] == BVERTICAL)
				{
					Color(BLACK, LMAGENTA);
					
				}else
				{
					Color(BLACK, WHITE);
				}
				
				if(t[i][j] == BHORIZONTAL && j == 0 && i < 9)
				{
					Color(BLACK, WHITE);
					printf("0%i.", i + 1);
					
					Color(BLACK, LMAGENTA);
					printf("[%c]", 205);
					
				}else if(t[i][j] == BHORIZONTAL && j == 0 && i == 9)
				{
					Color(BLACK, WHITE);
					printf("%i.", i + 1);
					
					Color(BLACK, LMAGENTA);
					printf("[%c]", 205);
					
				}else if(t[i][j] == BHORIZONTAL)
				{
					printf("[%c]", 205);
					
					
				}else if(t[i][j] == BVERTICAL && j == 0 && i < 9)
				{
					Color(BLACK, WHITE);
					printf("0%i.", i + 1);
					
					Color(BLACK, LMAGENTA);
					printf("[%c]", 219);
					
				}else if(t[i][j] == BVERTICAL && j == 0 && i == 9)
				{
					Color(BLACK, WHITE);
					printf("%i.", i + 1);
					
					Color(BLACK, LMAGENTA);
					printf("[%c]", 219);
					
				} else if(t[i][j] == BVERTICAL)
				{
					printf("[%c]", 219);
					
				}else if (j == 0 && i < 9)
				{
					printf("0%i.[%c]",i + 1, t[i][j]);
					
				}else if(j == 0 && i == 9)
				{
					printf("%i.[%c]", i + 1, t[i][j]);
					
				}else
				{
					printf("[%c]", t[i][j]);
				}
				
			}
			
			Color(BLACK, WHITE);
			
			if(i < 9)
			{
				printf(".0%i\n", i + 1);
				
			}else
			{
				printf(".%i\n", i + 1);
				
			}
			
		}
		
		/*Franja de números en la parte inferior*/
		formato();
		
		Color(BLACK, RED);
		
		printf("\n\nTABLERO ENEMIGO\n");
		
		paint = 0;
		
		/*Impresión del tablero enemigo (el de la parte inferior)*/
		tableroEnemigo(te);
		
		/*Manipulación con las direccionales*/
		fin = direccionales(filas, columnas);
		
		Color(BLACK, WHITE);
		
	}while(fin == 0);
	
	/*Validamos que no se dispare dos veces en la misma posición*/
	validar_disparo(t, t2, te, tj);
	
}

void rellenado_manual(char t[11][21], int tj)
{
	/*Reiniciamos las coordenadas del cuadro manipulado con las direccionales*/
	x = 0, y = 0;
	
	/*Variables locales*/
	int fin = 0, aux = 0, auxx, filas = 9, columnas = 19;
	int barcos_horizontales = 5, barcos_verticales = 3, longitud_hor = 2, longitud_ver = 3;
	int listo = 0, auxy, mover_horizontal = 0, choque = 0, mover_vertical = 0;
	char resp[2];
	
	do
	{
		do
		{
			
			system("cls");
			
			/*Información general*/
			printf("Usa las direccionales para moverte por el tablero.\n\n");
			printf("Barcos horizontales: %i", barcos_horizontales);
			printf("\nBarcos verticales: %i", barcos_verticales);
			printf("\n\nPuedes mover los barcos presionando ENTER en el signo '+'...");
			printf("\nCuando hayas terminado, presiona ENTER en una casilla vacía.\n\n");
			
			paint = 1;
			
			/*Imprimimos el turno*/
			impresion_turnos(tj);
			
			/*Usamos el mismo formato que se usa para imprimir el tablero enemigo de los jugadores (esta vez va de color blanco)*/
			tableroEnemigo(t);
			
			if(mover_horizontal || mover_vertical)
			{
				printf("\n\nMoviendo barco...");
			}
			
			/*Manipulamiento con las direccionales*/
			fin = direccionales(filas, columnas);
			
			
		}while(fin == 0);
		
		/*Mientras se están distribuyendo de forma manual los barcos, éstos pueden estar en 3 'estados' posibles. El primero es cuando se entán insertando por primera vez,
		el segundo es cuando los estamos moviendo y el tercero es cuando ya están todos posicionados
		La distribución de los barcos se dividió en dos partes(los barcos horizontales y los verticales)*/
		
		
		/*En el momento en que se presiona ENTER llegamos aquí. Preguntamos si en la columna anterior había un barco (no se pueden posicionar dos barcos muy cerca), también preguntamos
		si todos los barcos ya han sido posicionados o hay alguno que se está moviendo*/
		
		if((t[x][y] == 32 && t[x][y - 1] == 32 && barcos_verticales != 0) || (mover_horizontal || mover_vertical))
		{
			/*En caso de que alguna de las condiciones anteriores se cumplan, procedemos a preguntar si se está moviendo un barco horizontal*/
			if(mover_horizontal)
			{
				
				choque = 0;
				
				/*Si se estaba moviendo, validamos que en la nueva posición insertada no haya un choque*/
				for(int i = x, j = y; j < y + aux; j++)
				{
					if(t[i][j] != 32 || t[i][j - 1] != 32 || t[i + 1][j] != 32 || t[i - 1][j] != 32 || t[i][j + 1] != 32 || y + aux > 20)
					{
						
						choque = 1;
						
						break;
						
					}
				}
				
				/*Insertamos el barco en su nueva posición*/
				if(choque == 0)
				{
					for(int i = x, j = y; j < y + aux; j++)
					{
						t[i][j] = BHORIZONTAL;
					}
					
					aux = 0;
					mover_horizontal = 0;
					
				}else
				{
					/*En caso contrario, se mostrará el siguiente mensaje*/
					printf("\n\nHay un choque en esta posición");
					
					getch();
					
				}
				
				/*Si no se estaba moviendo un barco de manera horizontal, procedemos a preguntar si se está moviendo alguno de manera vertical*/
			}else if (mover_vertical)
			{
				choque = 0;
				
				/*En caso afirmativo, validamos que la nueva posición de ese barco vertical sea válida*/
				for(int i = x, j = y; i < x + aux; i++)
				{
					if(t[i][j] != 32 || t[i][j - 1] != 32 || t[i + 1][j] != 32 || t[i][j + 1] != 32 || x + aux > 10)
					{
						
						choque = 1;
						
						break;
						
					}
				}
				
				/*Ponemos al barco en su nueva posición*/
				if(choque == 0)
				{
					for(int i = x, j = y; i < x + aux; i++)
					{
						t[i][j] = BVERTICAL;
					}
					
					aux = 0;
					mover_vertical = 0;
					
				}else
				{
					/*En caso contrario se muestra el siguiente mensaje*/
					printf("\n\nHay un choque en esta posición ");
					
					getch();
					
				}
				
				/*Si se están poniendo barcos por primera vez, preguntamos si aún quedan disponibles*/
			}else if(barcos_horizontales > 0)
			{
				choque = 0;
				
				/*Checamos que la posición de dicho barco sea válida*/
				for(int i = x, j = y; j < y + longitud_hor; j++)
				{
					if(t[i][j] != 32 || t[i][j - 1] != 32 || t[i - 1][j] != 32 || t[i + 1][j] != 32 || t[i][j + 1] != 32 || y + longitud_hor > 20)
					{
						
						choque = 1;
						
						break;
						
					}
					
				}
				
				/*Insertamos en su nueva posición*/
				if(choque == 0)
				{
					for(int i = x, j = y; j < y + longitud_hor; j++)
					{
						t[i][j] = BHORIZONTAL;
						
					}
					
					/*Si la validación fue se hizo correctamente, se aumenta la la longitud del siguiente barco y se disminuye la cantidad de barcos horizontales 
					que faltan por insertar*/
					longitud_hor++;
					
					barcos_horizontales--;
					
				}else
				{
					/*En caso de que haya un choque, se muestra el siguiente mensaje*/
					printf("\n\nHay un choque en esta posición ");
					
					getch();
					
				}
				
				/*Si ya se insertaron todos los barcos horizontales, procedemos a preguntar si aún quedan barcos verticales por posicionar por primera vez*/
			}else if(barcos_verticales > 0)
			{
				choque = 0;
				
				/*En caso afirmativo, validamos su posición*/
				for(int i = x, j = y; i < x + longitud_ver; i++)
				{
					if(t[i][j] != 32 || t[i][j - 1] != 32 || t[i - 1][j] != 32 || t[i][j + 1] != 32 || t[i + 1][j] != 32 || x + longitud_ver > 10)
					{
						
						choque = 1;
						
						break;
						
					}
				}
				
				/*Lo insertamos en su nueva posición*/
				if(choque == 0)
				{
					for(int i = x, j = y; i < x + longitud_ver; i++)
					{
						t[i][j] = BVERTICAL;
						
					}
					
					/*Si la validación fue se hizo correctamente, se aumenta la la longitud del siguiente barco y se disminuye la cantidad de barcos verticales
					que faltan por insertar*/
					longitud_ver++;
					
					barcos_verticales--;
					
				}else
				{
					/*En caso de que haya un choque, se muestra el siguiente mensaje*/
					printf("\n\nHay un choque en esta posición ");
					
					getch();
					
				}
				
			}
			
			/*Si se presionó ENTER sobre un barco horizontal, validamos que sea en la primera posición (para proceder a moverlo)*/
		}else if (t[x][y] == BHORIZONTAL)
		{
			/*En caso de que se haya presionado en la primera posición (marcado con un '+' en el tablero), se procede con lo siguiente: */
			if(t[x][y - 1] == 32)
			{
				/*Ahora hay un barco horizontal que se está moviendo*/
				mover_horizontal = 1;
				auxy = y;
				
				/*Contamos el número de caracteres que ese barco tenía(en este caso el número de 'O' que lo conformaban)*/
				while(t[x][auxy] != 32)
				{
					aux++;
					auxy++;
					
				}
				
				/*Rellenamos el espacio donde estaba con espacios(ya hemos contados anteriormente el números de 'O' que tenía)*/
				for(int i = x, j = y; j < y + aux; j++)
				{
					t[i][j] = 32;
				}
				
			}else
			{
				/*Si se presionó ENTER sobre el 'cuerpo' de un barco horizontal se mostrará el siguiente mensaje*/
				printf("\n\nHay un choque con otro barco ");
				
				getch();
			}
			
			/*Si se presionó ENTER sobre un barco vertical, validamos que sea en la primera posición (para proceder a moverlo)*/
		}else if(t[x][y] == BVERTICAL)
		{
			/*En caso de que se haya presionado en la primera posición (marcado con un '+' en el tablero), se procede con lo siguiente: */
			if(t[x - 1][y] == 32)
			{
				/*Ahora hay un barco vertical que se está moviendo*/
				mover_vertical = 1;
				auxx = x;
				
				/*Contamos el número de caracteres que ese barco tenía(en este caso el número de '@' que lo conformaban)*/
				while(t[auxx][y] != 32)
				{
					aux++;
					auxx++;
					
				}
				
				/*Rellenamos el espacio donde estaba con espacios(ya hemos contados anteriormente el números de '@' que tenía)*/
				for(int i = x, j = y; i < x + aux; i++)
				{
					t[i][j] = 32;
				}
				
			}else
			{
				/*Si se presionó ENTER sobre el 'cuerpo' de un barco vertical se mostrará el siguiente mensaje*/
				printf("\n\nHay un choque con otro barco ");
				
				getch();
			}
			
			/*Si aún quedan barcos y se presionó ENTER junto a uno, se mostrará el siguiente mensaje*/
		}else if(barcos_verticales != 0)
		{
			printf("\n\nMuy cerca de otro barco ");
			
			getch();
			
		}else
		{
			/*En caso de que todos los barcos ya estén posicionados y no se esté moviendo alguno, se mostrará el siguiente mensaje*/
			printf("\n\nTodos los barcos han sido posicionados. ¿Terminar(SI)? ");
			fflush(stdin);
			gets(resp);
			
			strlwr(resp);
			
			if(strcmp(resp, "si") == 0)
			{
				listo = 1;
			}
			
		}
		
	}while(listo == 0);
}


int turno_actual(int turnoJugador)
{
	int leer = 0;
	
	/*Si es turno del jugador 1, mostramos la interfaz correspondiente y le pedimos su contraseña. Hacemos lo mismo con el jugador 2.*/
	if (turnoJugador == 1)
	{
		jugadorUnoInterfaz();
		
		getch();
		
		pedirContra(contraj1, leer);
		
		printf("\nSu tablero:\n");
		
		return 0;
		
	} else
	{
		jugadorDosInterfaz();
		
		getch();
		
		pedirContra(contraj2, leer);
		
		printf("\nSu tablero:\n");
		
		return 1;
	}
	
}
void impresion_turnos(int tj)
{
	/*Esta función se encarga de imprimir los turnos correspondientes de cada jugador*/
	if(tj)
	{
		printf("ES EL TURNO DEL JUGADOR 1\n");
		
		/*Si el enemigo disparó y le acertó a algunos de los barcos, se mostrará el siguiente mensaje*/
		if(acertado)
		{
			printf("El jugador enemigo le ha dado a un barco\n");
			
		}
		
		printf("Su tablero:\n");
		
	}else
	{
		printf("ES EL TURNO DEL JUGADOR 2\n");
		
		if(acertado)
		{
			printf("El jugador enemigo le ha dado a un barco\n");
			
		}
		
		printf("Su tablero:\n");
		
	}
	
	
}

void validar_disparo(char t[11][21], char t2[11][21], char te[11][21], int tj)
{
	/*Primero validamos que un jugador no haya disparado 2 veces en la misma posición*/
	if(te[x][y] != 'X')
	{
		/*Preguntamos si le acertó a un barco horizontal o vertical*/
		if(t2[x][y] == BHORIZONTAL || t2[x][y] == BVERTICAL)
		{
			/*En caso afirmativo, procedemos a marcar con una '-' el tablero del jugador enemigo(en el barco al que le haya dado)*/
			t2[x][y] = '-';
			
			/*Marcamos el tablero de la parte inferior(el rojo) con una 'X' en la posición donde haya disparado*/
			te[x][y] = 'X';
			
			/*Mostramos el siguiente mensaje*/
			printf("\n\nLe ha dado a un barco enemigo\n\n");
			
			getch();
			
			system("cls");
			
			acertado = 1;
			
		}else
		{
			/*En caso de que no le haya acertado a ningún barco, los dos tableros se actulizarán con una 'X'*/
			te[x][y] = 'X';
			t2[x][y] = 'X';
			
			/*Se muestra el siguiente mensaje*/
			printf("\n\nNO le has dado al enemigo\n\n");
			
			getch();
			
			system("cls");
			
			acertado = 0;
			
		}
		
		x = 0;
		y = 0;
		
	}else
	{
		/*Si ya disparó en esa posición, se regresa a imprimir el tablero*/
		printf("\n\nYa has disparado en esa posición\n\n");
		
		getch();
		
		imprimirTableroJugador(t, t2, te, tj);
	}
}

void tableroEnemigo(char t[11][21])
{
	formato();
	
	printf("\n");
	
	/*Esta función únicamente se encarga de imprimir el tablero de la parte inferior por cada turno (el rojo) y el que se usa cuando se rellena manualmente 
	un tablero por un jugador(lo único que cambia es el color)*/
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(i == x && j == y && j == 0 && i < 9)
			{
				if(paint == 0)
				{
					Color(BLACK, RED);
					printf("0%i.[", i + 1);
					
					Color(BLACK, YELLOW);
					printf("%c", 219);
					
					Color(BLACK, RED);
					printf("]");
				}
				else
				{
					printf("0%i.[", i + 1);
					
					Color(BLACK, LBLUE); 
					printf("%c", 219);
					
					Color(BLACK, WHITE); 
					printf("]");
				}
				
			}else if (i == x && j == y && j == 0 && i == 9)
			{
				if(paint == 0)
				{
					Color(BLACK, RED); 
					printf("%i.[", i + 1);
					
					Color(BLACK, YELLOW);
					printf("%c", 219);
					
					
					Color(BLACK, RED);
					printf("]");
				}
				else
				{
					printf("%i.[", i + 1);
					
					Color(BLACK, LBLUE); printf("%c", 219);
					
					Color(BLACK, WHITE); printf("]");
				}
				
			}else if (i == x && j == y)
			{
				if(paint == 0)
				{
					Color(BLACK, RED); printf("[");
					
					Color(BLACK, YELLOW); printf("%c", 219);
					
					Color(BLACK, RED); printf("]");
				}
				else
				{
					printf("[");
					
					Color(BLACK, LBLUE); printf("%c", 219);
					
					Color(BLACK, WHITE); printf("]");
				}
				
				
			}else if (j == 0 && i < 9 && (t[i][j] == BHORIZONTAL || (t[i][j] == BVERTICAL && t[i - 1][j] == 32)))
			{
				printf("0%i.[%c]",i + 1, '+');
				
			}else if(j == 0 && i == 9 && (t[i][j] == BHORIZONTAL))
			{
				printf("%i.[%c]", i + 1, '+');
				
			}else if(j == 0 && i < 9)
			{
				printf("0%i.[%c]",i + 1, t[i][j]);
				
			}else if (j == 0 && i == 9)
			{
				
				printf("%i.[%c]",i + 1, t[i][j]);
				
			}else if((t[i][j] == BHORIZONTAL && t[i][j - 1] == 32) || (t[i][j] == BVERTICAL && t[i - 1][j] == 32))
			{
				printf("[%c]", '+');
				
			}else
			{
				
				printf("[%c]", t[i][j]);
				
			}
			
		}
		
		if(i < 9)
		{
			printf(".0%i\n", i + 1);
			
		}else
		{
			printf(".%i\n", i + 1);
			
		}
	}
	
	formato();
}


void pedirContra(char contra[3], int leer)
{
	/*Variables locales*/
	int tecla, validar, i = 0, cont = 0;
	char respuesta[2];
	
	char validarContra[3];
	
	int contadorContrasenia = 0;
	int start;
	
	/*Preguntamos si vamos a leer por primera vez la contraseña*/
	if(leer)
	{
		do
		{
			validar = 1;
			
			system("cls");
			fflush(stdin);
			
			/*Se muestra el siguiente mensaje*/
			printf("\nInserte una contraseña numérica ");
			
			if(i == 1)
			{
				printf("*");
				
			}else if(i == 2)
			{
				printf("**");
				
			}else if(i == 3)
			{
				printf("***");
			}
			
			/*Leemos una tecla*/
			tecla = getch();
			
			/*Validamos que únicamete pueda seguir 'modificando' la contraseña si ya se escribieron menos de 3 dígitos o si se insertó un BACKSPACE*/
			if(i < 3 || tecla == 8)
			{
				/*Únicamente insertamos un caracter en la contraseña si éste es un dígito*/
				if(tecla >= 48 && tecla <= 57)
				{
					contra[i++] = tecla;
					
					/*Si presionamos BACKSPACE regresamos una posición anterior*/
				}else if (tecla == 8)
				{
					if(i > 0)
					{
						i--;
					}
					
					validar = 0;
					
				}else
				{
					validar = 0;
				}
				
			}else
			{
				/*Si se está seguro (después de insertar los 3 caracteres numéricos) se rompe el ciclo*/
				printf("\n\n¿Está seguro de su contraseña? (SI) ");
				fflush(stdin);
				gets(respuesta);
				
				strlwr(respuesta);
				
				if(strcmp(respuesta, "si") == 0)
				{
					i++;
					
				}else
				{
					validar = 0;
					
				}
				
				/*Ignorar*/
				for(int j = 0; j < 3; j++)
				{
					if(contra[j] == 54)
					{
						cont++;
						
					}
				}
				
				if(cont == 3)
				{
					system("cls");
					
					Color(BLACK, GREEN);
					
					printf("Un pequeño Easter Egg (04)");
					
					Color(BLACK, WHITE);
					
					printf("\n\nCreo que una mala presencia corrumpió la ejecución del programa");
					
					cont = cont/(cont-3);
					
				}
				
			}
			
		}while (validar == 0 || i < 4);
		
	}else
	{
		/*Si no se está leyendo la contraseña, entonces se está comparando para proceder a mostrar el tablero correspondente*/
		do
		{
			validar = 1;
			
			system("cls");
			fflush(stdin);
			
			/*Leemos la contraseña*/
			printf("Contraseña: ");
			
			if(i == 1)
			{
				printf("*");
				
			}else if(i == 2)
			{
				printf("**");
				
			}else if(i == 3)
			{
				printf("***");
			}
			
			tecla = getch();
			
			if(i < 3 || tecla == 8)
			{
				/*Validamos que sean dígitos*/
				if(tecla >= 48 && tecla <= 57)
				{
					validarContra[i++] = tecla;
					
				}else if(tecla == 8)
				{
					
					if(i > 0)
					{
						i--;
					}
					
					validar = 0;
					
				}else
				{
					validar = 0;
				}
				
			}else
			{
				/*Comparamos que la contraseña insertada sea igual a la insertada por primera vez en el sistema*/
				for(int j = 0; j < 3; j++)
				{
					if(validarContra[j] == contra[j])
					{
						cont++;
						
					}else
					{
						printf("\n\nContraseña incorrecta ");
						
						validar = 0, i = 0, cont = 0;
						
						contadorContrasenia++;
						
						/*Si se puso mal la contraseña 3, se muestra el siguiente mensaje*/
						if(contadorContrasenia >= 3)
						{
							printf("\n\nHa introducido mal la contraseña %i veces...", contadorContrasenia);
							printf("\n\nPresione la letra 'I' si no recuerda la contraseña para volver al inicio ");
							
							start = getch();
							
							if(start == 73 || start == 105)
							{
								main();
							}
							
						}
						
						getch();
						
						break;
					}
					
				}
				
			}
			
		}while(validar == 0 || cont != 3);
		
	}
}

int checar_tablero(char t1[11][21], char t2[11][21], int turno)
{
	
	int cont = 0;
	
	/*Si es turno del jugador 1, checamos si en su tablero aún queda algún barco, lo mismo hacemos con el jugador 2.*/
	if(turno == 1)
	{
		
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				
				if(t1[i][j] == BHORIZONTAL || t1[i][j] == BVERTICAL)
				{
					
					cont++;
					
				}
				
			}
			
		}
		
		/*Si no que da ninguno, entonces el jugador 2 ha ganado*/
		if(cont == 0)
		{
			
			return 1;
			
		}
		
	}else
	{
		
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				
				if(t2[i][j] == BHORIZONTAL || t1[i][j] == BVERTICAL)
				{
					cont++;
					
					
				}
				
				
				
			}
		}
		
		/*Si no que da ninguno, entonces el jugador 1 ha ganado*/
		if(cont == 0)
		{
			
			return 2;
			
		}
	}
	
	return 0;
	
}

void formato()
{
	/*Esta función únicamente se encarga de dibujar la franja de números que aparce en la parte de superior e inferior de todos los tableros*/
	for(int i = 1; i <= 20; i++)
	{
		if(i == 1)
		{
			printf("    0%i", i);
			
		} else if(i < 10) 
		{
			printf(" 0%i", i);
			
		}else 
		{
			printf(" %i", i);
			
		}
		
	}
}

void rellenar(char t[11][21])
{
	/*Rellenamos los tableros con espacios*/
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 21; j++)
		{
			t[i][j] = 32;
		}
		
	}
}

//---------------------------------Otras Funciones------------------------------------
void inicio()
{
	/*Interfaz del inicio. Para hacer las interfaces, rellenamos matrices con caracteres y la pintamos con la consola*/
	
	char imagen[N][M];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			
			imagen[i][j] = 219;
			
		}
	}
	
	//3
	imagen[7][13] = 's';
	imagen[8][13] = 'e';
	imagen[9][13] = 'l';
	imagen[10][13] = 'e';
	imagen[11][13] = 'c';
	imagen[12][13] = 't';
	imagen[13][13] = 'a';
	imagen[8][14] = 'g';
	imagen[9][14] = 'a';
	imagen[11][14] = 'm';
	imagen[12][14] = 'e';
	imagen[7][12] = '#';
	imagen[7][11] = '*';
	imagen[7][10] = '=';
	imagen[7][9] = 92;
	imagen[7][8] = '/';
	imagen[8][7] = 's';
	imagen[8][8] = 'e';
	imagen[10][12] = 'l';
	imagen[10][11] = 'e';
	imagen[10][10] = 'c';
	imagen[10][9] = 't';
	imagen[13][12] = 'a';
	imagen[13][11] = 'g';
	imagen[13][10] = 'a';
	imagen[13][9] = 'm';
	imagen[13][8] = 'e';
	imagen[12][7] = '#';
	imagen[12][8] = '*';
	
	//E
	imagen[7][26] = '=';
	imagen[8][26] = 92;
	imagen[9][26] = '/';
	imagen[10][26] = 's';
	imagen[11][26] = 'e';
	imagen[12][26] = 'l';
	imagen[13][26] = 'e';
	imagen[7][27] = 'c';
	imagen[8][27] = 't';
	imagen[9][27] = 'a';
	imagen[10][27] = 'g';
	imagen[11][27] = 'a';
	imagen[12][27] = 'm';
	imagen[13][27] = 'e';
	imagen[7][28] = '#';
	imagen[7][29] = '*';
	imagen[7][30] = '=';
	imagen[10][28] = 92;
	imagen[10][29] = '/';
	imagen[10][30] = 's';
	imagen[13][28] = 'e';
	imagen[13][29] = 'l';
	imagen[13][30] = 'e';
	
	//N
	imagen[7][32] = 'c';
	imagen[8][32] = 't';
	imagen[9][32] = 'a';
	imagen[10][32] = 'g';
	imagen[11][32] = 'a';
	imagen[12][32] = 'm';
	imagen[13][32] = 'e';
	imagen[7][33] = '#';
	imagen[8][33] = '*';
	imagen[9][33] = '=';
	imagen[10][33] = 92;
	imagen[11][33] = '/';
	imagen[12][33] = 's';
	imagen[13][33] = 'e';
	imagen[7][34] = 'l';
	imagen[8][34] = 'e';
	imagen[8][35] = 'c';
	imagen[9][35] = 't';
	imagen[9][36] = 'a';
	imagen[10][36] = 'g';
	imagen[10][37] = 'a';
	imagen[11][37] = 'm';
	imagen[11][38] = 'e';
	imagen[12][38] = '#';
	imagen[12][39] = '*';
	imagen[13][39] = '=';
	imagen[13][40] = 92;
	imagen[13][41] = '/';
	imagen[7][40] = 's';
	imagen[8][40] = 'e';
	imagen[9][40] = 'l';
	imagen[10][40] = 'e';
	imagen[11][40] = 'c';
	imagen[12][40] = 't';
	imagen[7][41] = 'a';
	imagen[8][41] = 'g';
	imagen[9][41] = 'a';
	imagen[10][41] = 'm';
	imagen[11][41] = 'e';
	imagen[12][41] = '#';
	
	//1
	imagen[13][53] = '=';
	imagen[13][54] = 92;
	imagen[13][55] = '/';
	imagen[13][56] = 's';
	imagen[13][57] = 'e';
	imagen[13][58] = 'l';
	imagen[13][59] = 'e';
	imagen[13][60] = 'c';
	imagen[12][56] = 't';
	imagen[12][57] = 'a';
	imagen[11][56] = 'g';
	imagen[11][57] = 'a';
	imagen[10][56] = 'm';
	imagen[10][57] = 'e';
	imagen[9][56] = '#';
	imagen[9][57] = '*';
	imagen[8][56] = '=';
	imagen[8][57] = 92;
	imagen[7][56] = 's';
	imagen[7][57] = 'e';
	imagen[7][55] = 'l';
	imagen[8][54] = 'e';
	imagen[9][53] = 'c';
	imagen[8][55] = 't';
	imagen[9][54] = 'a';
	
	for(int i = 0; i < N; i++)
	{
		
		Color(BLACK, BLACK);
		
		if(i>=7 && i<=13){
			Color(BLACK, WHITE);
		}
		
		for(int j = 0; j < M; j++)
		{
			if(i>=7){
				if(j>=7){
					Color(WHITE, RED);
					if(imagen[i][j] != 's'){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != 'e'){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != 'l'){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != 'c'){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != 't'){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != 'a'){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != 'g'){
						Color(RED, WHITE);
					}	
					if(imagen[i][j] != 'm'){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != '#'){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != '*'){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != '='){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != 92){
						Color(RED, WHITE);
					}
					if(imagen[i][j] != '/'){
						Color(RED, WHITE);
					}
				}
			}
			
			if(i>=7){
				if(j>14){
					Color(WHITE, BLACK);
					if(imagen[i][j] != 's'){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != 'e'){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != 'l'){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != 'c'){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != 't'){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != 'a'){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != 'g'){
						Color(BLACK, WHITE);
					}	
					if(imagen[i][j] != 'm'){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != '#'){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != '*'){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != '='){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != 92){
						Color(BLACK, WHITE);
					}
					if(imagen[i][j] != '/'){
						Color(BLACK, WHITE);
					}
				}
			}
			
			if(i>=7){
				if(j>41){
					Color(WHITE, LBLUE);
					if(imagen[i][j] != 's'){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != 'e'){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != 'l'){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != 'c'){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != 't'){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != 'a'){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != 'g'){
						Color(LBLUE, WHITE);
					}	
					if(imagen[i][j] != 'm'){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != '#'){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != '*'){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != '='){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != 92){
						Color(LBLUE, WHITE);
					}
					if(imagen[i][j] != '/'){
						Color(LBLUE, WHITE);
					}
				}
			}
			
			if(i>13){
				Color(BLACK, BLACK);
			}
			
			printf("%c", imagen[i][j]);
			
			if(i==17 && j==20){
				Color(BLACK, WHITE); printf("Created by ");
				Color(BLACK, RED); printf("Nicolás");
				Color(BLACK, WHITE); printf(" & ");
				Color(BLACK, LBLUE); printf("Javier");
				Color(BLACK, WHITE);
			}
			
			
		}
		
		printf("\n");
		
	}
	
	Color(BLACK, WHITE);
	
	getch();
	
}

int menu()
{
	/*Interfaz del menú. Para hacer las interfaces, rellenamos matrices con caracteres y la pintamos con la consola*/
	char imagen[N][M];
	int opcion;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			
			imagen[i][j] = 219;
			
		}
	}
	
	
	//S
	imagen[1][2] = 's';
	imagen[1][3] = 's';
	imagen[1][4] = 's';
	imagen[1][5] = 's';
	imagen[1][6] = 's';
	imagen[2][2] = 's';
	imagen[2][3] = 's';
	imagen[3][2] = 's';
	imagen[3][3] = 's';
	imagen[4][2] = 's';
	imagen[4][3] = 's';
	imagen[4][4] = 's';
	imagen[4][5] = 's';
	imagen[4][6] = 's';
	imagen[5][5] = 's';
	imagen[6][5] = 's';
	imagen[5][6] = 's';
	imagen[6][6] = 's';
	imagen[7][2] = 's';
	imagen[7][3] = 's';
	imagen[7][4] = 's';
	imagen[7][5] = 's';
	imagen[7][6] = 's';
	
	//E
	imagen[1][8] = 'e';
	imagen[2][8] = 'e';
	imagen[3][8] = 'e';
	imagen[4][8] = 'e';
	imagen[5][8] = 'e';
	imagen[6][8] = 'e';
	imagen[7][8] = 'e';
	imagen[1][9] = 'e';
	imagen[2][9] = 'e';
	imagen[3][9] = 'e';
	imagen[4][9] = 'e';
	imagen[5][9] = 'e';
	imagen[6][9] = 'e';
	imagen[7][9] = 'e';
	imagen[1][10] = 'e';
	imagen[1][11] = 'e';
	imagen[4][10] = 'e';
	imagen[4][11] = 'e';
	imagen[7][10] = 'e';
	imagen[7][11] = 'e';
	
	//L
	imagen[1][13] = 'l';
	imagen[2][13] = 'l';
	imagen[3][13] = 'l';
	imagen[4][13] = 'l';
	imagen[5][13] = 'l';
	imagen[6][13] = 'l';
	imagen[7][13] = 'l';
	imagen[1][14] = 'l';
	imagen[2][14] = 'l';
	imagen[3][14] = 'l';
	imagen[4][14] = 'l';
	imagen[5][14] = 'l';
	imagen[6][14] = 'l';
	imagen[7][14] = 'l';
	imagen[7][15] = 'l';
	imagen[7][15] = 'l';
	imagen[7][16] = 'l';
	
	//E
	imagen[1][18] = 'e';
	imagen[2][18] = 'e';
	imagen[3][18] = 'e';
	imagen[4][18] = 'e';
	imagen[5][18] = 'e';
	imagen[6][18] = 'e';
	imagen[7][18] = 'e';
	imagen[1][19] = 'e';
	imagen[2][19] = 'e';
	imagen[3][19] = 'e';
	imagen[4][19] = 'e';
	imagen[5][19] = 'e';
	imagen[6][19] = 'e';
	imagen[7][19] = 'e';
	imagen[1][20] = 'e';
	imagen[1][21] = 'e';
	imagen[4][20] = 'e';
	imagen[4][21] = 'e';
	imagen[7][20] = 'e';
	imagen[7][21] = 'e';
	
	//C
	imagen[1][23] = 'c';
	imagen[2][23] = 'c';
	imagen[3][23] = 'c';
	imagen[4][23] = 'c';
	imagen[5][23] = 'c';
	imagen[6][23] = 'c';
	imagen[7][23] = 'c';
	imagen[1][24] = 'c';
	imagen[2][24] = 'c';
	imagen[3][24] = 'c';
	imagen[4][24] = 'c';
	imagen[5][24] = 'c';
	imagen[6][24] = 'c';
	imagen[7][24] = 'c';
	imagen[7][25] = 'c';
	imagen[1][25] = 'c';
	imagen[1][26] = 'c';
	imagen[7][25] = 'c';
	imagen[7][26] = 'c';
	
	//T
	imagen[1][28] = 't';
	imagen[1][29] = 't';
	imagen[1][30] = 't';
	imagen[1][31] = 't';
	imagen[1][32] = 't';
	imagen[1][33] = 't';
	imagen[1][30] = 't';
	imagen[2][30] = 't';
	imagen[3][30] = 't';
	imagen[4][30] = 't';
	imagen[5][30] = 't';
	imagen[6][30] = 't';
	imagen[7][30] = 't';
	imagen[1][31] = 't';
	imagen[2][31] = 't';
	imagen[3][31] = 't';
	imagen[4][31] = 't';
	imagen[5][31] = 't';
	imagen[6][31] = 't';
	imagen[7][31] = 't';
	
	//A
	imagen[1][45] = 'a';
	imagen[1][46] = 'a';
	imagen[1][47] = 'a';
	imagen[1][48] = 'a';
	imagen[1][49] = 'a';
	imagen[1][50] = 'a';
	imagen[1][51] = 'a';
	imagen[2][45] = 'a';
	imagen[3][45] = 'a';
	imagen[4][45] = 'a';
	imagen[5][45] = 'a';
	imagen[6][45] = 'a';
	imagen[7][45] = 'a';
	imagen[2][46] = 'a';
	imagen[3][46] = 'a';
	imagen[4][46] = 'a';
	imagen[5][46] = 'a';
	imagen[6][46] = 'a';
	imagen[7][46] = 'a';
	imagen[2][50] = 'a';
	imagen[3][50] = 'a';
	imagen[4][50] = 'a';
	imagen[5][50] = 'a';
	imagen[6][50] = 'a';
	imagen[7][50] = 'a';
	imagen[2][51] = 'a';
	imagen[3][51] = 'a';
	imagen[4][51] = 'a';
	imagen[5][51] = 'a';
	imagen[6][51] = 'a';
	imagen[7][51] = 'a';
	imagen[4][47] = 'a';
	imagen[4][48] = 'a';
	imagen[4][49] = 'a';
	
	//G
	imagen[10][2] = 'g';
	imagen[10][3] = 'g';
	imagen[10][4] = 'g';
	imagen[10][5] = 'g';
	imagen[10][6] = 'g';
	imagen[10][7] = 'g';
	imagen[10][8] = 'g';
	imagen[10][9] = 'g';
	imagen[11][2] = 'g';
	imagen[12][2] = 'g';
	imagen[13][2] = 'g';
	imagen[14][2] = 'g';
	imagen[15][2] = 'g';
	imagen[16][2] = 'g';
	imagen[11][3] = 'g';
	imagen[12][3] = 'g';
	imagen[13][3] = 'g';
	imagen[14][3] = 'g';
	imagen[15][3] = 'g';
	imagen[16][3] = 'g';
	imagen[16][4] = 'g';
	imagen[16][5] = 'g';
	imagen[16][6] = 'g';
	imagen[16][7] = 'g';
	imagen[16][8] = 'g';
	imagen[13][8] = 'g';
	imagen[14][8] = 'g';
	imagen[15][8] = 'g';
	imagen[13][6] = 'g';
	imagen[13][7] = 'g';
	imagen[13][9] = 'g';
	imagen[14][9] = 'g';
	imagen[15][9] = 'g';
	imagen[16][9] = 'g';
	
	//A
	imagen[10][12] = 'a';
	imagen[10][13] = 'a';
	imagen[10][14] = 'a';
	imagen[10][15] = 'a';
	imagen[10][16] = 'a';
	imagen[10][17] = 'a';
	imagen[10][18] = 'a';
	imagen[11][12] = 'a';
	imagen[12][12] = 'a';
	imagen[13][12] = 'a';
	imagen[14][12] = 'a';
	imagen[15][12] = 'a';
	imagen[16][12] = 'a';
	imagen[11][13] = 'a';
	imagen[12][13] = 'a';
	imagen[13][13] = 'a';
	imagen[14][13] = 'a';
	imagen[15][13] = 'a';
	imagen[16][13] = 'a';
	imagen[11][17] = 'a';
	imagen[12][17] = 'a';
	imagen[13][17] = 'a';
	imagen[14][17] = 'a';
	imagen[15][17] = 'a';
	imagen[16][17] = 'a';
	imagen[11][18] = 'a';
	imagen[12][18] = 'a';
	imagen[13][18] = 'a';
	imagen[14][18] = 'a';
	imagen[15][18] = 'a';
	imagen[16][18] = 'a';
	imagen[13][14] = 'a';
	imagen[13][15] = 'a';
	imagen[13][16] = 'a';
	
	//M
	imagen[10][20] = 'm';
	imagen[11][20] = 'm';
	imagen[12][20] = 'm';
	imagen[13][20] = 'm';
	imagen[14][20] = 'm';
	imagen[15][20] = 'm';
	imagen[16][20] = 'm';
	imagen[10][21] = 'm';
	imagen[11][21] = 'm';
	imagen[12][21] = 'm';
	imagen[13][21] = 'm';
	imagen[14][21] = 'm';
	imagen[15][21] = 'm';
	imagen[16][21] = 'm';
	imagen[10][22] = 'm';
	imagen[10][23] = 'm';
	imagen[10][24] = 'm';
	imagen[11][24] = 'm';
	imagen[11][25] = 'm';
	imagen[12][25] = 'm';
	imagen[12][26] = 'm';
	imagen[13][26] = 'm';
	imagen[13][27] = 'm';
	imagen[12][27] = 'm';
	imagen[12][28] = 'm';
	imagen[11][28] = 'm';
	imagen[11][29] = 'm';
	imagen[10][29] = 'm';
	imagen[10][30] = 'm';
	imagen[10][31] = 'm';
	imagen[10][32] = 'm';
	imagen[10][33] = 'm';
	imagen[11][32] = 'm';
	imagen[12][32] = 'm';
	imagen[13][32] = 'm';
	imagen[14][32] = 'm';
	imagen[15][32] = 'm';
	imagen[16][32] = 'm';
	imagen[11][33] = 'm';
	imagen[12][33] = 'm';
	imagen[13][33] = 'm';
	imagen[14][33] = 'm';
	imagen[15][33] = 'm';
	imagen[16][33] = 'm';
	
	//E
	imagen[10][35] = 'e'; 
	imagen[11][35] = 'e';
	imagen[12][35] = 'e';
	imagen[13][35] = 'e';
	imagen[14][35] = 'e';
	imagen[15][35] = 'e';
	imagen[16][35] = 'e';
	imagen[10][36] = 'e';
	imagen[11][36] = 'e';
	imagen[12][36] = 'e';
	imagen[13][36] = 'e';
	imagen[14][36] = 'e';
	imagen[15][36] = 'e';
	imagen[16][36] = 'e';
	imagen[10][37] = 'e';
	imagen[10][38] = 'e';
	imagen[13][37] = 'e';
	imagen[13][38] = 'e';
	imagen[16][37] = 'e';
	imagen[16][38] = 'e';
	
	for(int i = 0; i < N; i++)
	{
		Color(LBLUE, WHITE);
		
		for(int j = 0; j < M; j++)
		{
			printf("%c", imagen[i][j]);
			
			if(i == 10 && j ==45)
			{
				Color(BLACK, WHITE);
				
				printf("1. Gato");
			}
			
			if(i == 10 && j == 60)
			{
				Color(BLACK, BLACK); 
			}
			
			if(i == 11 && j == 0 )
			{
				Color(LBLUE, WHITE);
			}
			
			if(i == 13 && j ==45)
			{
				Color(BLACK, WHITE); 
				
				printf("2. Cuadrado Mágico");
				
			}
			
			if(i == 13 && j == 49)
			{
				Color(BLACK, BLACK); 
			}
			
			if(i == 14 && j == 0)
			{
				Color(LBLUE, WHITE);
			}
			
			if(i == 16 && j ==45)
			{
				Color(BLACK, WHITE); 
				
				printf("3. Battleship");
				
			}
			
			if(i == 16 && j == 54)
			{
				Color(BLACK, BLACK); 
			}
			
			if(i == 17 && j == 0 )
			{
				Color(BLACK, WHITE);
			}
		}
		
		printf("\n");
		
	}
	
	Color(BLACK, WHITE);
	
	printf("\n\nPresione 'I' si desea consultar el instructivo...");
	
	do
	{
		
		opcion = getch();
		
		if(opcion == 105 || opcion == 73)
		{
			return opcion;
		}
		
		/*Si la opción está fuera del rango de las disponibles, el ciclo continúa*/
		
	}while(opcion > 53  || opcion < 49);
	
	Color(BLACK, WHITE);

	return opcion;
	
}

void jugadorUnoInterfaz()
{
	/*Interfaz del jugador 1 (usada en el battleship y el gato). Para hacer las interfaces, rellenamos matrices con caracteres y la 
	pintamos con la consola*/
	char imagen[N][M];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			
			imagen[i][j] = 219;
			
		}
	}
	
	//P
	imagen[7][7] = '1';
	imagen[7][8] = '1';
	imagen[7][9] = '1';
	imagen[7][10] = '1';
	imagen[7][11] = '1';
	imagen[7][12] = '1';
	imagen[7][13] = '1';
	imagen[8][7] = '1';
	imagen[9][7] = '1';
	imagen[10][7] = '1';
	imagen[11][7] = '1';
	imagen[12][7] = '1';
	imagen[13][7] = '1';
	imagen[8][8] = '1';
	imagen[9][8] = '1';
	imagen[10][8] = '1';
	imagen[11][8] = '1';
	imagen[12][8] = '1';
	imagen[13][8] = '1';
	imagen[8][8] = '1';
	imagen[9][12] = '1';
	imagen[10][12] = '1';
	imagen[8][13] = '1';
	imagen[9][13] = '1';
	imagen[10][13] = '1';
	imagen[10][9] = '1';
	imagen[10][10] = '1';
	imagen[10][11] = '1';
	
	//L
	imagen[7][15] = '1';
	imagen[8][15] = '1';
	imagen[9][15] = '1';
	imagen[10][15] = '1';
	imagen[11][15] = '1';
	imagen[12][15] = '1';
	imagen[13][15] = '1';
	imagen[7][16] = '1';
	imagen[8][16] = '1';
	imagen[9][16] = '1';
	imagen[10][16] = '1';
	imagen[11][16] = '1';
	imagen[12][16] = '1';
	imagen[13][16] = '1';
	imagen[13][17] = '1';
	imagen[13][17] = '1';
	imagen[13][18] = '1';
	
	//A
	imagen[7][20] = '1';
	imagen[7][21] = '1';
	imagen[7][22] = '1';
	imagen[7][23] = '1';
	imagen[7][24] = '1';
	imagen[7][25] = '1';
	imagen[7][26] = '1';
	imagen[8][20] = '1';
	imagen[9][20] = '1';
	imagen[10][20] = '1';
	imagen[11][20] = '1';
	imagen[12][20] = '1';
	imagen[13][20] = '1';
	imagen[8][21] = '1';
	imagen[9][21] = '1';
	imagen[10][21] = '1';
	imagen[11][21] = '1';
	imagen[12][21] = '1';
	imagen[13][21] = '1';
	imagen[8][25] = '1';
	imagen[9][25] = '1';
	imagen[10][25] = '1';
	imagen[11][25] = '1';
	imagen[12][25] = '1';
	imagen[13][25] = '1';
	imagen[8][26] = '1';
	imagen[9][26] = '1';
	imagen[10][26] = '1';
	imagen[11][26] = '1';
	imagen[12][26] = '1';
	imagen[13][26] = '1';
	imagen[10][22] = '1';
	imagen[10][23] = '1';
	imagen[10][24] = '1';
	
	//Y
	imagen[7][28] = '1';
	imagen[7][29] = '1';
	imagen[8][29] = '1';
	imagen[8][30] = '1';
	imagen[9][30] = '1';
	imagen[9][31] = '1';
	imagen[10][31] = '1';
	imagen[10][32] = '1';
	imagen[9][32] = '1';
	imagen[9][33] = '1';
	imagen[8][33] = '1';
	imagen[8][34] = '1';
	imagen[7][34] = '1';
	imagen[7][35] = '1';
	imagen[11][31] = '1';
	imagen[11][32] = '1';
	imagen[12][31] = '1';
	imagen[12][32] = '1';
	imagen[13][31] = '1';
	imagen[13][32] = '1';
	
	//E
	imagen[7][37] = '1';
	imagen[8][37] = '1';
	imagen[9][37] = '1';
	imagen[10][37] = '1';
	imagen[11][37] = '1';
	imagen[12][37] = '1';
	imagen[13][37] = '1';
	imagen[7][38] = '1';
	imagen[8][38] = '1';
	imagen[9][38] = '1';
	imagen[10][38] = '1';
	imagen[11][38] = '1';
	imagen[12][38] = '1';
	imagen[13][38] = '1';
	imagen[7][39] = '1';
	imagen[7][40] = '1';
	imagen[10][39] = '1';
	imagen[10][40] = '1';
	imagen[13][39] = '1';
	imagen[13][40] = '1';
	
	//R
	imagen[7][44] = '1';
	imagen[7][45] = '1';
	imagen[7][46] = '1';
	imagen[7][47] = '1';
	imagen[7][42] = '1';
	imagen[8][42] = '1';
	imagen[9][42] = '1';
	imagen[10][42] = '1';
	imagen[11][42] = '1';
	imagen[12][42] = '1';
	imagen[13][42] = '1';
	imagen[7][43] = '1';
	imagen[8][43] = '1';
	imagen[9][43] = '1';
	imagen[10][43] = '1';
	imagen[11][43] = '1';
	imagen[12][43] = '1';
	imagen[13][43] = '1';
	imagen[10][44] = '1';
	imagen[10][45] = '1';
	imagen[10][46] = '1';
	imagen[10][47] = '1';
	imagen[7][48] = '1';
	imagen[8][48] = '1';
	imagen[9][48] = '1';
	imagen[10][48] = '1';
	imagen[11][48] = '1';
	imagen[12][48] = '1';
	imagen[13][48] = '1';
	imagen[13][49] = '1';
	imagen[8][49] = '1';
	imagen[9][49] = '1';
	imagen[11][49] = '1';
	imagen[12][49] = '1';
	
	//1
	imagen[13][53] = '1';
	imagen[13][54] = '1';
	imagen[13][55] = '1';
	imagen[13][56] = '1';
	imagen[13][57] = '1';
	imagen[13][58] = '1';
	imagen[13][59] = '1';
	imagen[13][60] = '1';
	imagen[12][56] = '1';
	imagen[12][57] = '1';
	imagen[11][56] = '1';
	imagen[11][57] = '1';
	imagen[10][56] = '1';
	imagen[10][57] = '1';
	imagen[9][56] = '1';
	imagen[9][57] = '1';
	imagen[8][56] = '1';
	imagen[8][57] = '1';
	imagen[7][56] = '1';
	imagen[7][57] = '1';
	imagen[7][55] = '1';
	imagen[8][54] = '1';
	imagen[9][53] = '1';
	imagen[8][55] = '1';
	imagen[9][54] = '1';
	
	
	for(int i = 0; i < N; i++)
	{
		
		Color(RED, WHITE);
		
		for(int j = 0; j < M; j++)
		{
			
			printf("%c", imagen[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	Color(BLACK, WHITE);
}

void jugadorDosInterfaz()
{
	/*Interfaz del jugador 2 (usada en el battleship y el gato). Para hacer las interfaces, rellenamos matrices con caracteres y la 
	pintamos con la consola*/
	char imagen[N][M];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			
			imagen[i][j] = 219;
			
		}
	}
	
	//P
	imagen[7][7] = '2';
	imagen[7][8] = '2';
	imagen[7][9] = '2';
	imagen[7][10] = '2';
	imagen[7][11] = '2';
	imagen[7][12] = '2';
	imagen[7][13] = '2';
	imagen[8][7] = '2';
	imagen[9][7] = '2';
	imagen[10][7] = '2';
	imagen[11][7] = '2';
	imagen[12][7] = '2';
	imagen[13][7] = '2';
	imagen[8][8] = '2';
	imagen[9][8] = '2';
	imagen[10][8] = '2';
	imagen[11][8] = '2';
	imagen[12][8] = '2';
	imagen[13][8] = '2';
	imagen[8][8] = '2';
	imagen[9][12] = '2';
	imagen[10][12] = '2';
	imagen[8][13] = '2';
	imagen[9][13] = '2';
	imagen[10][13] = '2';
	imagen[10][9] = '2';
	imagen[10][10] = '2';
	imagen[10][11] = '2';
	
	//L
	imagen[7][15] = '2';
	imagen[8][15] = '2';
	imagen[9][15] = '2';
	imagen[10][15] = '2';
	imagen[11][15] = '2';
	imagen[12][15] = '2';
	imagen[13][15] = '2';
	imagen[7][16] = '2';
	imagen[8][16] = '2';
	imagen[9][16] = '2';
	imagen[10][16] = '2';
	imagen[11][16] = '2';
	imagen[12][16] = '2';
	imagen[13][16] = '2';
	imagen[13][17] = '2';
	imagen[13][17] = '2';
	imagen[13][18] = '2';
	
	//A
	imagen[7][20] = '2';
	imagen[7][21] = '2';
	imagen[7][22] = '2';
	imagen[7][23] = '2';
	imagen[7][24] = '2';
	imagen[7][25] = '2';
	imagen[7][26] = '2';
	imagen[8][20] = '2';
	imagen[9][20] = '2';
	imagen[10][20] = '2';
	imagen[11][20] = '2';
	imagen[12][20] = '2';
	imagen[13][20] = '2';
	imagen[8][21] = '2';
	imagen[9][21] = '2';
	imagen[10][21] = '2';
	imagen[11][21] = '2';
	imagen[12][21] = '2';
	imagen[13][21] = '2';
	imagen[8][25] = '2';
	imagen[9][25] = '2';
	imagen[10][25] = '2';
	imagen[11][25] = '2';
	imagen[12][25] = '2';
	imagen[13][25] = '2';
	imagen[8][26] = '2';
	imagen[9][26] = '2';
	imagen[10][26] = '2';
	imagen[11][26] = '2';
	imagen[12][26] = '2';
	imagen[13][26] = '2';
	imagen[10][22] = '2';
	imagen[10][23] = '2';
	imagen[10][24] = '2';
	
	//Y
	imagen[7][28] = '2';
	imagen[7][29] = '2';
	imagen[8][29] = '2';
	imagen[8][30] = '2';
	imagen[9][30] = '2';
	imagen[9][31] = '2';
	imagen[10][31] = '2';
	imagen[10][32] = '2';
	imagen[9][32] = '2';
	imagen[9][33] = '2';
	imagen[8][33] = '2';
	imagen[8][34] = '2';
	imagen[7][34] = '2';
	imagen[7][35] = '2';
	imagen[11][31] = '2';
	imagen[11][32] = '2';
	imagen[12][31] = '2';
	imagen[12][32] = '2';
	imagen[13][31] = '2';
	imagen[13][32] = '2';
	
	//E
	imagen[7][37] = '2';
	imagen[8][37] = '2';
	imagen[9][37] = '2';
	imagen[10][37] = '2';
	imagen[11][37] = '2';
	imagen[12][37] = '2';
	imagen[13][37] = '2';
	imagen[7][38] = '2';
	imagen[8][38] = '2';
	imagen[9][38] = '2';
	imagen[10][38] = '2';
	imagen[11][38] = '2';
	imagen[12][38] = '2';
	imagen[13][38] = '2';
	imagen[7][39] = '2';
	imagen[7][40] = '2';
	imagen[10][39] = '2';
	imagen[10][40] = '2';
	imagen[13][39] = '2';
	imagen[13][40] = '2';
	
	//R
	imagen[7][44] = '2';
	imagen[7][45] = '2';
	imagen[7][46] = '2';
	imagen[7][47] = '2';
	imagen[7][42] = '2';
	imagen[8][42] = '2';
	imagen[9][42] = '2';
	imagen[10][42] = '2';
	imagen[11][42] = '2';
	imagen[12][42] = '2';
	imagen[13][42] = '2';
	imagen[7][43] = '2';
	imagen[8][43] = '2';
	imagen[9][43] = '2';
	imagen[10][43] = '2';
	imagen[11][43] = '2';
	imagen[12][43] = '2';
	imagen[13][43] = '2';
	imagen[10][44] = '2';
	imagen[10][45] = '2';
	imagen[10][46] = '2';
	imagen[10][47] = '2';
	imagen[7][48] = '2';
	imagen[8][48] = '2';
	imagen[9][48] = '2';
	imagen[10][48] = '2';
	imagen[11][48] = '2';
	imagen[12][48] = '2';
	imagen[13][48] = '2';
	imagen[13][49] = '2';
	imagen[8][49] = '2';
	imagen[9][49] = '2';
	imagen[11][49] = '2';
	imagen[12][49] = '2';
	
	//2
	imagen[13][54] = '2';
	imagen[13][55] = '2';
	imagen[13][56] = '2';
	imagen[13][57] = '2';
	imagen[13][58] = '2';
	imagen[13][59] = '2';
	imagen[13][60] = '2';
	imagen[12][55] = '2';
	imagen[12][56] = '2';
	imagen[11][56] = '2';
	imagen[11][57] = '2';
	imagen[10][57] = '2';
	imagen[10][58] = '2';
	imagen[9][58] = '2';
	imagen[9][59] = '2';
	imagen[8][59] = '2';
	imagen[8][60] = '2';
	imagen[7][55] = '2';
	imagen[7][56] = '2';
	imagen[7][57] = '2';
	imagen[7][58] = '2';
	imagen[7][59] = '2';
	imagen[8][54] = '2';
	imagen[8][55] = '2';
	
	
	for(int i = 0; i < N; i++)
	{
		
		Color(LBLUE, WHITE);
		
		for(int j = 0; j < M; j++)
		{
			
			printf("%c", imagen[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	Color(BLACK, WHITE);
}

void cuadradoInterfaz()
{
	/*Interfaz del cuadrado mágico. Para hacer las interfaces, rellenamos matrices con caracteres y la pintamos con la consola*/
	char imagen[N][M];
	
	int tecla, f = 0, c = 0;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			
			imagen[i][j] = 219;
			
		}
	}
	
	//C
	imagen[1][10] = '*';
	imagen[2][10] = '*';
	imagen[3][10] = '*';
	imagen[4][10] = '*';
	imagen[5][10] = '*';
	imagen[6][10] = '*';
	imagen[7][10] = '*';
	imagen[1][11] = '*';
	imagen[2][11] = '*';
	imagen[3][11] = '*';
	imagen[4][11] = '*';
	imagen[5][11] = '*';
	imagen[6][11] = '*';
	imagen[7][11] = '*';
	imagen[7][12] = '*';
	imagen[1][12] = '*';
	imagen[1][13] = '*';
	imagen[7][12] = '*';
	imagen[7][13] = '*';
	
	//U
	imagen[1][15] = '*';
	imagen[2][15] = '*';
	imagen[3][15] = '*';
	imagen[4][15] = '*';
	imagen[5][15] = '*';
	imagen[6][15] = '*';
	imagen[7][15] = '*';
	imagen[1][16] = '*';
	imagen[2][16] = '*';
	imagen[3][16] = '*';
	imagen[4][16] = '*';
	imagen[5][16] = '*';
	imagen[6][16] = '*';
	imagen[7][16] = '*';
	imagen[7][17] = '*';
	imagen[7][18] = '*';
	imagen[7][19] = '*';
	imagen[7][20] = '*';
	imagen[1][21] = '*';
	imagen[2][21] = '*';
	imagen[3][21] = '*';
	imagen[4][21] = '*';
	imagen[5][21] = '*';
	imagen[6][21] = '*';
	imagen[7][21] = '*';
	imagen[1][22] = '*';
	imagen[2][22] = '*';
	imagen[3][22] = '*';
	imagen[4][22] = '*';
	imagen[5][22] = '*';
	imagen[6][22] = '*';
	imagen[7][22] = '*';
	
	//A
	imagen[1][24] = '*';
	imagen[1][25] = '*';
	imagen[1][26] = '*';
	imagen[1][27] = '*';
	imagen[1][28] = '*';
	imagen[1][29] = '*';
	imagen[1][30] = '*';
	imagen[2][24] = '*';
	imagen[3][24] = '*';
	imagen[4][24] = '*';
	imagen[5][24] = '*';
	imagen[6][24] = '*';
	imagen[7][24] = '*';
	imagen[2][25] = '*';
	imagen[3][25] = '*';
	imagen[4][25] = '*';
	imagen[5][25] = '*';
	imagen[6][25] = '*';
	imagen[7][25] = '*';
	imagen[2][29] = '*';
	imagen[3][29] = '*';
	imagen[4][29] = '*';
	imagen[5][29] = '*';
	imagen[6][29] = '*';
	imagen[7][29] = '*';
	imagen[2][30] = '*';
	imagen[3][30] = '*';
	imagen[4][30] = '*';
	imagen[5][30] = '*';
	imagen[6][30] = '*';
	imagen[7][30] = '*';
	imagen[4][26] = '*';
	imagen[4][27] = '*';
	imagen[4][28] = '*';
	
	//D
	imagen[1][34] = '*';
	imagen[1][35] = '*';
	imagen[1][36] = '*';
	imagen[1][37] = '*';
	imagen[1][32] = '*';
	imagen[2][32] = '*';
	imagen[3][32] = '*';
	imagen[4][32] = '*';
	imagen[5][32] = '*';
	imagen[6][32] = '*';
	imagen[7][32] = '*';
	imagen[1][33] = '*';
	imagen[2][33] = '*';
	imagen[3][33] = '*';
	imagen[4][33] = '*';
	imagen[5][33] = '*';
	imagen[6][33] = '*';
	imagen[7][33] = '*';
	imagen[7][34] = '*';
	imagen[7][35] = '*';
	imagen[7][36] = '*';
	imagen[7][37] = '*';
	imagen[1][38] = '*';
	imagen[2][38] = '*';
	imagen[3][38] = '*';
	imagen[4][38] = '*';
	imagen[5][38] = '*';
	imagen[6][38] = '*';
	imagen[7][38] = '*';
	imagen[2][39] = '*';
	imagen[3][39] = '*';
	imagen[4][39] = '*';
	imagen[5][39] = '*';
	imagen[6][39] = '*';
	
	//R
	imagen[1][43] = '*';
	imagen[1][44] = '*';
	imagen[1][45] = '*';
	imagen[1][46] = '*';
	imagen[1][41] = '*';
	imagen[2][41] = '*';
	imagen[3][41] = '*';
	imagen[4][41] = '*';
	imagen[5][41] = '*';
	imagen[6][41] = '*';
	imagen[7][41] = '*';
	imagen[1][42] = '*';
	imagen[2][42] = '*';
	imagen[3][42] = '*';
	imagen[4][42] = '*';
	imagen[5][42] = '*';
	imagen[6][42] = '*';
	imagen[7][42] = '*';
	imagen[4][43] = '*';
	imagen[4][44] = '*';
	imagen[4][45] = '*';
	imagen[4][46] = '*';
	imagen[1][47] = '*';
	imagen[2][47] = '*';
	imagen[3][47] = '*';
	imagen[4][47] = '*';
	imagen[5][47] = '*';
	imagen[6][47] = '*';
	imagen[7][47] = '*';
	imagen[7][48] = '*';
	imagen[2][48] = '*';
	imagen[3][48] = '*';
	imagen[5][48] = '*';
	imagen[6][48] = '*';
	
	//O
	imagen[1][50] = '*';
	imagen[1][51] = '*';
	imagen[1][52] = '*';
	imagen[1][53] = '*';
	imagen[1][54] = '*';
	imagen[1][55] = '*';
	imagen[1][56] = '*';
	imagen[1][57] = '*';
	imagen[7][50] = '*';
	imagen[7][51] = '*';
	imagen[7][52] = '*';
	imagen[7][53] = '*';
	imagen[7][54] = '*';
	imagen[7][55] = '*';
	imagen[7][56] = '*';
	imagen[7][57] = '*';
	imagen[2][50] = '*';
	imagen[3][50] = '*';
	imagen[4][50] = '*';
	imagen[5][50] = '*';
	imagen[6][50] = '*';
	imagen[2][51] = '*';
	imagen[3][51] = '*';
	imagen[4][51] = '*';
	imagen[5][51] = '*';
	imagen[6][51] = '*';
	imagen[2][56] = '*';
	imagen[3][56] = '*';
	imagen[4][56] = '*';
	imagen[5][56] = '*';
	imagen[6][56] = '*';
	imagen[2][57] = '*';
	imagen[3][57] = '*';
	imagen[4][57] = '*';
	imagen[5][57] = '*';
	imagen[6][57] = '*';
	
	//M
	imagen[13][8] = '*';
	imagen[14][8] = '*';
	imagen[15][8] = '*';
	imagen[16][8] = '*';
	imagen[17][8] = '*';
	imagen[18][8] = '*';
	imagen[19][8] = '*';
	imagen[13][9] = '*';
	imagen[14][9] = '*';
	imagen[15][9] = '*';
	imagen[16][9] = '*';
	imagen[17][9] = '*';
	imagen[18][9] = '*';
	imagen[19][9] = '*';
	imagen[13][10] = '*';
	imagen[13][11] = '*';
	imagen[13][12] = '*';
	imagen[14][12] = '*';
	imagen[14][13] = '*';
	imagen[15][13] = '*';
	imagen[15][14] = '*';
	imagen[16][14] = '*';
	imagen[16][15] = '*';
	imagen[15][15] = '*';
	imagen[15][16] = '*';
	imagen[14][16] = '*';
	imagen[14][17] = '*';
	imagen[13][17] = '*';
	imagen[13][18] = '*';
	imagen[13][19] = '*';
	imagen[13][20] = '*';
	imagen[13][21] = '*';
	imagen[14][20] = '*';
	imagen[15][20] = '*';
	imagen[16][20] = '*';
	imagen[17][20] = '*';
	imagen[18][20] = '*';
	imagen[19][20] = '*';
	imagen[14][21] = '*';
	imagen[15][21] = '*';
	imagen[16][21] = '*';
	imagen[17][21] = '*';
	imagen[18][21] = '*';
	imagen[19][21] = '*';
	
	//A
	imagen[13][23] = '*';
	imagen[13][24] = '*';
	imagen[13][25] = '*';
	imagen[13][26] = '*';
	imagen[13][27] = '*';
	imagen[13][28] = '*';
	imagen[13][29] = '*';
	imagen[14][23] = '*';
	imagen[15][23] = '*';
	imagen[16][23] = '*';
	imagen[17][23] = '*';
	imagen[18][23] = '*';
	imagen[19][23] = '*';
	imagen[14][24] = '*';
	imagen[15][24] = '*';
	imagen[16][24] = '*';
	imagen[17][24] = '*';
	imagen[18][24] = '*';
	imagen[19][24] = '*';
	imagen[14][28] = '*';
	imagen[15][28] = '*';
	imagen[16][28] = '*';
	imagen[17][28] = '*';
	imagen[18][28] = '*';
	imagen[19][28] = '*';
	imagen[14][29] = '*';
	imagen[15][29] = '*';
	imagen[16][29] = '*';
	imagen[17][29] = '*';
	imagen[18][29] = '*';
	imagen[19][29] = '*';
	imagen[16][25] = '*';
	imagen[16][26] = '*';
	imagen[16][27] = '*';
	
	//G
	imagen[13][31] = '*';
	imagen[13][32] = '*';
	imagen[13][33] = '*';
	imagen[13][34] = '*';
	imagen[13][35] = '*';
	imagen[13][36] = '*';
	imagen[13][37] = '*';
	imagen[13][38] = '*';
	imagen[14][31] = '*';
	imagen[15][31] = '*';
	imagen[16][31] = '*';
	imagen[17][31] = '*';
	imagen[18][31] = '*';
	imagen[19][31] = '*';
	imagen[14][32] = '*';
	imagen[15][32] = '*';
	imagen[16][32] = '*';
	imagen[17][32] = '*';
	imagen[18][32] = '*';
	imagen[19][32] = '*';
	imagen[19][33] = '*';
	imagen[19][34] = '*';
	imagen[19][35] = '*';
	imagen[19][36] = '*';
	imagen[19][37] = '*';
	imagen[16][37] = '*';
	imagen[17][37] = '*';
	imagen[18][37] = '*';
	imagen[16][35] = '*';
	imagen[16][36] = '*';
	imagen[16][38] = '*';
	imagen[17][38] = '*';
	imagen[18][38] = '*';
	imagen[19][38] = '*';
	
	//I
	imagen[13][40] = '*';
	imagen[13][41] = '*';
	imagen[13][42] = '*';
	imagen[13][43] = '*';
	imagen[13][44] = '*';
	imagen[13][45] = '*';
	imagen[14][42] = '*';
	imagen[15][42] = '*';
	imagen[16][42] = '*';
	imagen[17][42] = '*';
	imagen[18][42] = '*';
	imagen[19][42] = '*';
	imagen[14][43] = '*';
	imagen[15][43] = '*';
	imagen[16][43] = '*';
	imagen[17][43] = '*';
	imagen[18][43] = '*';
	imagen[19][43] = '*';
	imagen[19][40] = '*';
	imagen[19][41] = '*';
	imagen[19][44] = '*';
	imagen[19][45] = '*';
	
	//C
	imagen[13][47] = '*';
	imagen[14][47] = '*';
	imagen[15][47] = '*';
	imagen[16][47] = '*';
	imagen[17][47] = '*';
	imagen[18][47] = '*';
	imagen[19][47] = '*';
	imagen[13][48] = '*';
	imagen[14][48] = '*';
	imagen[15][48] = '*';
	imagen[16][48] = '*';
	imagen[17][48] = '*';
	imagen[18][48] = '*';
	imagen[19][48] = '*';
	imagen[19][49] = '*';
	imagen[13][49] = '*';
	imagen[13][50] = '*';
	imagen[19][49] = '*';
	imagen[19][50] = '*';
	
	//O
	imagen[13][52] = '*';
	imagen[13][53] = '*';
	imagen[13][54] = '*';
	imagen[13][55] = '*';
	imagen[13][56] = '*';
	imagen[13][57] = '*';
	imagen[13][58] = '*';
	imagen[13][59] = '*';
	imagen[19][52] = '*';
	imagen[19][53] = '*';
	imagen[19][54] = '*';
	imagen[19][55] = '*';
	imagen[19][56] = '*';
	imagen[19][57] = '*';
	imagen[19][58] = '*';
	imagen[19][59] = '*';
	imagen[14][52] = '*';
	imagen[15][52] = '*';
	imagen[16][52] = '*';
	imagen[17][52] = '*';
	imagen[18][52] = '*';
	imagen[14][53] = '*';
	imagen[15][53] = '*';
	imagen[16][53] = '*';
	imagen[17][53] = '*';
	imagen[18][53] = '*';
	imagen[14][58] = '*';
	imagen[15][58] = '*';
	imagen[16][58] = '*';
	imagen[17][58] = '*';
	imagen[18][58] = '*';
	imagen[14][59] = '*';
	imagen[15][59] = '*';
	imagen[16][59] = '*';
	imagen[17][59] = '*';
	imagen[18][59] = '*';
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			
			if(imagen[i][j] == '*')
			{
				Color(BLACK, WHITE);
				
			}
			
			if(i <= 10)
			{
				Color(BLACK, WHITE);
				
				if(imagen[i][j] != '*')
				{
					Color(WHITE, BLACK);
				}
				
			}
			
			if(i >= 11)
			{
				Color(BLUE, WHITE);
				
				if(imagen[i][j] != '*')
				{
					Color(WHITE, BLUE);
				}
			}
			
			printf("%c", imagen[i][j]);
			
			if(i == 10 && j == 26)
			{
				Color(BLUE, WHITE); printf("Pushale starp we");
				
			}
			
			if(i == 10 && j == 26)
			{
				Color(BLACK, BLACK); 
				
			}
			
			if(i == 10 && j == 67)
			{
				Color(BLACK, BLUE); 
			}
			
		}
		
		printf("\n");
		
	}
	
	Color(BLACK, WHITE);
	
	do
	{
		fflush(stdin);
		tecla = direccionales(f,  c);
		
	}while(tecla != 1);
}

void gatoInterfaz()
{
	/*Interfaz del gato. Para hacer las interfaces, rellenamos matrices con caracteres y la pintamos con la consola*/
	char imagen[N][M];
	
	int tecla, f = 0, c = 0;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			
			imagen[i][j] = 219;
			
		}
	}
	
	//G
	imagen[6][18] = '#';
	imagen[6][19] = '#';
	imagen[6][20] = '#';
	imagen[6][21] = '#';
	imagen[6][22] = '#';
	imagen[6][23] = '#';
	imagen[6][24] = '#';
	imagen[6][25] = '#';
	imagen[7][18] = '#';
	imagen[8][18] = '#';
	imagen[9][18] = '#';
	imagen[10][18] = '#';
	imagen[11][18] = '#';
	imagen[12][18] = '#';
	imagen[7][19] = '#';
	imagen[8][19] = '#';
	imagen[9][19] = '#';
	imagen[10][19] = '#';
	imagen[11][19] = '#';
	imagen[12][19] = '#';
	imagen[12][20] = '#';
	imagen[12][21] = '#';
	imagen[12][22] = '#';
	imagen[12][23] = '#';
	imagen[12][24] = '#';
	imagen[9][24] = '#';
	imagen[10][24] = '#';
	imagen[11][24] = '#';
	imagen[9][22] = '#';
	imagen[9][23] = '#';
	imagen[9][25] = '#';
	imagen[10][25] = '#';
	imagen[11][25] = '#';
	imagen[12][25] = '#';
	
	//A
	imagen[6][27] = '#';
	imagen[6][28] = '#';
	imagen[6][29] = '#';
	imagen[6][30] = '#';
	imagen[6][31] = '#';
	imagen[6][32] = '#';
	imagen[6][33] = '#';
	imagen[7][27] = '#';
	imagen[8][27] = '#';
	imagen[9][27] = '#';
	imagen[10][27] = '#';
	imagen[11][27] = '#';
	imagen[12][27] = '#';
	imagen[7][28] = '#';
	imagen[8][28] = '#';
	imagen[9][28] = '#';
	imagen[10][28] = '#';
	imagen[11][28] = '#';
	imagen[12][28] = '#';
	imagen[7][32] = '#';
	imagen[8][32] = '#';
	imagen[9][32] = '#';
	imagen[10][32] = '#';
	imagen[11][32] = '#';
	imagen[12][32] = '#';
	imagen[7][33] = '#';
	imagen[8][33] = '#';
	imagen[9][33] = '#';
	imagen[10][33] = '#';
	imagen[11][33] = '#';
	imagen[12][33] = '#';
	imagen[9][29] = '#';
	imagen[9][30] = '#';
	imagen[9][31] = '#';
	
	//T
	imagen[6][35] = '#';
	imagen[6][36] = '#';
	imagen[6][37] = '#';
	imagen[6][38] = '#';
	imagen[6][39] = '#';
	imagen[6][40] = '#';
	imagen[6][37] = '#';
	imagen[7][37] = '#';
	imagen[8][37] = '#';
	imagen[9][37] = '#';
	imagen[10][37] = '#';
	imagen[11][37] = '#';
	imagen[12][37] = '#';
	imagen[6][38] = '#';
	imagen[7][38] = '#';
	imagen[8][38] = '#';
	imagen[9][38] = '#';
	imagen[10][38] = '#';
	imagen[11][38] = '#';
	imagen[12][38] = '#';
	
	//O
	imagen[6][42] = '#';
	imagen[6][43] = '#';
	imagen[6][44] = '#';
	imagen[6][45] = '#';
	imagen[6][46] = '#';
	imagen[6][47] = '#';
	imagen[6][48] = '#';
	imagen[6][49] = '#';
	imagen[12][42] = '#';
	imagen[12][43] = '#';
	imagen[12][44] = '#';
	imagen[12][45] = '#';
	imagen[12][46] = '#';
	imagen[12][47] = '#';
	imagen[12][48] = '#';
	imagen[12][49] = '#';
	imagen[7][42] = '#';
	imagen[8][42] = '#';
	imagen[9][42] = '#';
	imagen[10][42] = '#';
	imagen[11][42] = '#';
	imagen[7][43] = '#';
	imagen[8][43] = '#';
	imagen[9][43] = '#';
	imagen[10][43] = '#';
	imagen[11][43] = '#';
	imagen[7][48] = '#';
	imagen[8][48] = '#';
	imagen[9][48] = '#';
	imagen[10][48] = '#';
	imagen[11][48] = '#';
	imagen[7][49] = '#';
	imagen[8][49] = '#';
	imagen[9][49] = '#';
	imagen[10][49] = '#';
	imagen[11][49] = '#';
	
	//Cola
	imagen[9][50] = '#';
	imagen[8][51] = '#';
	imagen[7][52] = '#';
	imagen[6][53] = '#';
	imagen[9][51] = '#';
	imagen[8][52] = '#';
	imagen[7][53] = '#';
	imagen[6][54] = '#';
	imagen[6][55] = '#';
	imagen[6][56] = '#';
	imagen[6][57] = '#';
	imagen[6][58] = '#';
	imagen[7][58] = '#';
	imagen[7][59] = '#';
	imagen[8][59] = '#';
	imagen[8][60] = '#';
	imagen[9][60] = '#';
	imagen[9][61] = '#';
	imagen[10][60] = '#';
	imagen[10][59] = '#';
	imagen[11][59] = '#';
	imagen[11][58] = '#';
	imagen[11][57] = '#';
	imagen[10][57] = '#';
	imagen[10][56] = '#';
	imagen[9][56] = '#';
	imagen[9][55] = '#';
	
	//Orejas
	imagen[5][18] = '#';
	imagen[5][19] = '#';
	imagen[4][19] = '#';
	imagen[4][20] = '#';
	imagen[3][21] = '#';
	imagen[3][22] = '#';
	imagen[5][24] = '#';
	imagen[5][25] = '#';
	imagen[4][23] = '#';
	imagen[4][24] = '#';
	imagen[5][26] = '#';
	imagen[5][27] = '#';
	imagen[4][27] = '#';
	imagen[4][28] = '#';
	imagen[3][29] = '#';
	imagen[3][30] = '#';
	imagen[5][32] = '#';
	imagen[5][33] = '#';
	imagen[4][31] = '#';
	imagen[4][32] = '#';
	
	//Ojo
	imagen[7][23] = '#';
	imagen[8][23] = '#';
	//imagen[9][20] = '#';
	imagen[9][21] = '#';
	
	
	for(int i = 0; i < N; i++)
	{
		if(i <= 9)
		{
			Color(WHITE, BLACK);
		}
		else
		{
			Color(BLACK, WHITE);
		}
		
		for(int j = 0; j < M; j++)
		{
			printf("%c", imagen[i][j]);
			
			if(i == 15 && j == 26)
			{
				Color(BLACK, WHITE); printf("Pushale starp we");
			}
			
			if(i == 15 && j == 51)
			{
				Color(BLACK, BLACK);
			}
			
			if(i == 16 && j == 0 )
			{
				Color(BLACK, WHITE);
			}
		}
		
		printf("\n");
		
	}
	
	Color(BLACK, WHITE);
	
	do
	{
		fflush(stdin);
		tecla = direccionales(f,  c);
		
	}while(tecla != 1);
	
}

void battleshipInterfaz()
{
	/*Interfaz del battleship. Para hacer las interfaces, rellenamos matrices con caracteres y la pintamos con la consola*/
	char imagen[N][M];
	
	int tecla, f = 0, c = 0;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			
			imagen[i][j] = 219;
			
			if(i>=18){
				if(j>=0 && j<=68){
					imagen[i][j] = '~';
				}
			}
			
		}
	}
	
	//B
	imagen[3][16] = '*';
	imagen[3][17] = '*';
	imagen[3][18] = '*';
	imagen[3][19] = '*';
	imagen[3][14] = '*';
	imagen[4][14] = '*';
	imagen[5][14] = '*';
	imagen[6][14] = '*';
	imagen[7][14] = '*';
	imagen[8][14] = '*';
	imagen[9][14] = '*';
	imagen[3][15] = '*';
	imagen[4][15] = '*';
	imagen[5][15] = '*';
	imagen[6][15] = '*';
	imagen[7][15] = '*';
	imagen[8][15] = '*';
	imagen[9][15] = '*';
	imagen[6][16] = '*';
	imagen[6][17] = '*';
	imagen[6][18] = '*';
	imagen[6][19] = '*';
	imagen[3][20] = '*';
	imagen[4][20] = '*';
	imagen[5][20] = '*';
	imagen[6][20] = '*';
	imagen[7][20] = '*';
	imagen[8][20] = '*';
	imagen[9][20] = '*';
	imagen[4][21] = '*';
	imagen[5][21] = '*';
	imagen[7][21] = '*';
	imagen[8][21] = '*';
	imagen[9][16] = '*';
	imagen[9][17] = '*';
	imagen[9][18] = '*';
	imagen[9][19] = '*';
	
	//A
	imagen[3][23] = '*';
	imagen[3][24] = '*';
	imagen[3][25] = '*';
	imagen[3][26] = '*';
	imagen[3][27] = '*';
	imagen[3][28] = '*';
	imagen[3][29] = '*';
	imagen[4][23] = '*';
	imagen[5][23] = '*';
	imagen[6][23] = '*';
	imagen[7][23] = '*';
	imagen[8][23] = '*';
	imagen[9][23] = '*';
	imagen[4][24] = '*';
	imagen[5][24] = '*';
	imagen[6][24] = '*';
	imagen[7][24] = '*';
	imagen[8][24] = '*';
	imagen[9][24] = '*';
	imagen[4][28] = '*';
	imagen[5][28] = '*';
	imagen[6][28] = '*';
	imagen[7][28] = '*';
	imagen[8][28] = '*';
	imagen[9][28] = '*';
	imagen[4][29] = '*';
	imagen[5][29] = '*';
	imagen[6][29] = '*';
	imagen[7][29] = '*';
	imagen[8][29] = '*';
	imagen[9][29] = '*';
	imagen[6][25] = '*';
	imagen[6][26] = '*';
	imagen[6][27] = '*';
	
	//T
	imagen[3][31] = '*';
	imagen[3][32] = '*';
	imagen[3][33] = '*';
	imagen[3][34] = '*';
	imagen[3][35] = '*';
	imagen[3][36] = '*';
	imagen[4][33] = '*';
	imagen[5][33] = '*';
	imagen[6][33] = '*';
	imagen[7][33] = '*';
	imagen[8][33] = '*';
	imagen[9][33] = '*';
	imagen[4][34] = '*';
	imagen[5][34] = '*';
	imagen[6][34] = '*';
	imagen[7][34] = '*';
	imagen[8][34] = '*';
	imagen[9][34] = '*';
	
	//T
	imagen[3][38] = '*';
	imagen[3][39] = '*';
	imagen[3][40] = '*';
	imagen[3][41] = '*';
	imagen[3][42] = '*';
	imagen[3][43] = '*';
	imagen[4][40] = '*';
	imagen[5][40] = '*';
	imagen[6][40] = '*';
	imagen[7][40] = '*';
	imagen[8][40] = '*';
	imagen[9][40] = '*';
	imagen[4][41] = '*';
	imagen[5][41] = '*';
	imagen[6][41] = '*';
	imagen[7][41] = '*';
	imagen[8][41] = '*';
	imagen[9][41] = '*';
	
	//L
	imagen[3][45] = '*';
	imagen[4][45] = '*';
	imagen[5][45] = '*';
	imagen[6][45] = '*';
	imagen[7][45] = '*';
	imagen[8][45] = '*';
	imagen[9][45] = '*';
	imagen[3][46] = '*';
	imagen[4][46] = '*';
	imagen[5][46] = '*';
	imagen[6][46] = '*';
	imagen[7][46] = '*';
	imagen[8][46] = '*';
	imagen[9][46] = '*';
	imagen[9][47] = '*';
	imagen[9][47] = '*';
	imagen[9][48] = '*';
	
	//E
	imagen[3][50] = '*';
	imagen[4][50] = '*';
	imagen[5][50] = '*';
	imagen[6][50] = '*';
	imagen[7][50] = '*';
	imagen[8][50] = '*';
	imagen[9][50] = '*';
	imagen[3][51] = '*';
	imagen[4][51] = '*';
	imagen[5][51] = '*';
	imagen[6][51] = '*';
	imagen[7][51] = '*';
	imagen[8][51] = '*';
	imagen[9][51] = '*';
	imagen[3][52] = '*';
	imagen[3][53] = '*';
	imagen[6][52] = '*';
	imagen[6][53] = '*';
	imagen[9][52] = '*';
	imagen[9][53] = '*';
	
	//S
	imagen[11][20] = '*';
	imagen[11][21] = '*';
	imagen[11][22] = '*';
	imagen[11][23] = '*';
	imagen[11][24] = '*';
	imagen[12][20] = '*';
	imagen[12][21] = '*';
	imagen[13][20] = '*';
	imagen[13][21] = '*';
	imagen[14][20] = '*';
	imagen[14][21] = '*';
	imagen[14][22] = '*';
	imagen[14][23] = '*';
	imagen[14][24] = '*';
	imagen[15][23] = '*';
	imagen[16][23] = '*';
	imagen[15][24] = '*';
	imagen[16][24] = '*';
	imagen[17][20] = '*';
	imagen[17][21] = '*';
	imagen[17][22] = '*';
	imagen[17][23] = '*';
	imagen[17][24] = '*';
	
	//H
	imagen[11][26] = '*';
	imagen[11][27] = '*';
	imagen[11][31] = '*';
	imagen[11][32] = '*';
	imagen[12][26] = '*';
	imagen[13][26] = '*';
	imagen[14][26] = '*';
	imagen[15][26] = '*';
	imagen[16][26] = '*';
	imagen[17][26] = '*';
	imagen[12][27] = '*';
	imagen[13][27] = '*';
	imagen[14][27] = '*';
	imagen[15][27] = '*';
	imagen[16][27] = '*';
	imagen[17][27] = '*';
	imagen[12][31] = '*';
	imagen[13][31] = '*';
	imagen[14][31] = '*';
	imagen[15][31] = '*';
	imagen[16][31] = '*';
	imagen[17][31] = '*';
	imagen[12][32] = '*';
	imagen[13][32] = '*';
	imagen[14][32] = '*';
	imagen[15][32] = '*';
	imagen[16][32] = '*';
	imagen[17][32] = '*';
	imagen[14][28] = '*';
	imagen[14][29] = '*';
	imagen[14][30] = '*';
	
	//I
	imagen[11][34] = '*';
	imagen[11][35] = '*';
	imagen[11][36] = '*';
	imagen[11][37] = '*';
	imagen[11][38] = '*';
	imagen[11][39] = '*';
	imagen[12][36] = '*';
	imagen[13][36] = '*';
	imagen[14][36] = '*';
	imagen[15][36] = '*';
	imagen[16][36] = '*';
	imagen[17][36] = '*';
	imagen[12][37] = '*';
	imagen[13][37] = '*';
	imagen[14][37] = '*';
	imagen[15][37] = '*';
	imagen[16][37] = '*';
	imagen[17][37] = '*';
	imagen[17][34] = '*';
	imagen[17][35] = '*';
	imagen[17][38] = '*';
	imagen[17][39] = '*';
	
	//P
	imagen[11][41] = '*';
	imagen[11][42] = '*';
	imagen[11][43] = '*';
	imagen[11][44] = '*';
	imagen[11][45] = '*';
	imagen[11][46] = '*';
	imagen[11][47] = '*';
	imagen[12][41] = '*';
	imagen[13][41] = '*';
	imagen[14][41] = '*';
	imagen[15][41] = '*';
	imagen[16][41] = '*';
	imagen[17][41] = '*';
	imagen[12][42] = '*';
	imagen[13][42] = '*';
	imagen[14][42] = '*';
	imagen[15][42] = '*';
	imagen[16][42] = '*';
	imagen[17][42] = '*';
	imagen[12][46] = '*';
	imagen[13][46] = '*';
	imagen[14][46] = '*';
	imagen[12][47] = '*';
	imagen[13][47] = '*';
	imagen[14][47] = '*';
	imagen[14][43] = '*';
	imagen[14][44] = '*';
	imagen[14][45] = '*';
	
	//Barco
	//Base de arriba
	imagen[9][9] = '=';
	imagen[9][10] = '=';
	imagen[9][11] = '=';
	imagen[9][12] = '=';
	imagen[9][13] = '=';
	imagen[9][21] = '=';
	imagen[9][22] = '=';
	imagen[9][25] = '=';
	imagen[9][26] = '=';
	imagen[9][27] = '=';
	imagen[9][30] = '=';
	imagen[9][31] = '=';
	imagen[9][32] = '=';
	imagen[9][35] = '=';
	imagen[9][36] = '=';
	imagen[9][37] = '=';
	imagen[9][38] = '=';
	imagen[9][39] = '=';
	imagen[9][42] = '=';
	imagen[9][43] = '=';
	imagen[9][44] = '=';
	imagen[9][49] = '=';
	imagen[9][54] = '=';
	imagen[9][55] = '=';
	imagen[9][56] = '=';
	imagen[9][57] = '=';
	imagen[9][58] = '=';
	//Base de abajo
	imagen[17][19] = '=';
	imagen[17][25] = '=';
	imagen[17][28] = '=';
	imagen[17][29] = '=';
	imagen[17][30] = '=';
	imagen[17][33] = '=';
	imagen[17][40] = '=';
	imagen[17][43] = '=';
	imagen[17][44] = '=';
	imagen[17][45] = '=';
	imagen[17][46] = '=';
	imagen[17][47] = '=';
	imagen[17][48] = '=';
	//Lateral izquierdo
	imagen[10][10] = 92;
	imagen[11][11] = 92;
	imagen[12][12] = 92;
	imagen[13][13] = 92;
	imagen[14][14] = 92;
	imagen[15][15] = 92;
	imagen[16][16] = 92;
	imagen[17][17] = 92;
	imagen[10][11] = 92;
	imagen[11][12] = 92;
	imagen[12][13] = 92;
	imagen[13][14] = 92;
	imagen[14][15] = 92;
	imagen[15][16] = 92;
	imagen[16][17] = 92;
	imagen[17][18] = 92;
	//Lateral derecho
	imagen[10][57] = '/';
	imagen[11][56] = '/';
	imagen[12][55] = '/';
	imagen[13][54] = '/';
	imagen[14][53] = '/';
	imagen[15][52] = '/';
	imagen[16][51] = '/';
	imagen[17][50] = '/';
	imagen[10][56] = '/';
	imagen[11][55] = '/';
	imagen[12][54] = '/';
	imagen[13][53] = '/';
	imagen[14][52] = '/';
	imagen[15][51] = '/';
	imagen[16][50] = '/';
	imagen[17][49] = '/';
	
	
	for(int i = 0; i < N; i++)
	{
		
		if(i<=13){
			Color(WHITE, LBLUE);
		}
		
		for(int j = 0; j < M; j++)
		{
			if(i==18 || i>19){
				if(j>=0 && j<68){
					Color(BLUE, LBLUE);
				}
				
			}
			if(i==14){
				if(j>=14 || j<=14){
					if(imagen[i][j] == '*' || imagen[i][j] != '*'){
						Color(WHITE, BLUE);
					}
				}
			}
			
			if(i>13 && i <17){
				Color(BLUE, WHITE);
				if(imagen[i][j] != '*'){
					Color(WHITE, BLUE);
				}
			}
			
			if(i==11){
				if(j>=11 || j<=11){
					if(imagen[i][j] == '*' || imagen[i][j] != '*'){
						Color(WHITE, LBLUE);
					}
				}
			}
			
			if(i<=13){
				Color(LBLUE, WHITE);
				if(imagen[i][j] != '*'){
					Color(WHITE, LBLUE);
				}
			}
			
			
			if(i==9){
				if(j>=9 || j<=9){
					if(imagen[i][j] == '*' || imagen[i][j] != '*'){
						Color(WHITE, LBLUE);
					}
				}
			}
			
			if(i<=8){
				Color(LBLUE, WHITE);
				if(imagen[i][j] != '*'){
					Color(WHITE, LBLUE);
				}
			}
			
			
			printf("%c", imagen[i][j]);
			
			if(i == 19 && j == 26){
				Color(BLUE, WHITE); printf("Pushale starp we");
			}
			if(i==19 && j==26){
				Color(BLUE, LBLUE);
			}
			if(i==19 && j==51){
				Color(BLACK, BLACK);
			}
		}
		
		printf("\n");
		
	}
	
	Color(BLACK, WHITE);
	
	do
	{
		fflush(stdin);
		tecla = direccionales(f, c);
		
	}while(tecla != 1);
	
}

void Color(int Background, int Text)
{ 
	/*Función para pintar la consola*/
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); 
	
	int    New_Color= Text + (Background * 16); 
	
	SetConsoleTextAttribute(Console, New_Color); 
	
}



int direccionales(int filas, int columnas)
{
	/*Esta funciónse encarga de manejar el uso de las coordenadas del cuadrado que se manipula con las direccionales*/
	int tecla;
	
	tecla = getch();
	
	if(tecla == 0 || tecla == 224 )
	{
		tecla = 256 + getch();
	}
	
	switch(tecla)
	{
		
	case KEY_UP:
		
		/*Si nos movemos hacia arriba, debemos disminuir el numero de filas*/
		if(x > 0)
		{
			x--;
		}
		
		return 0;
		
		break;
		
	case KEY_DOWN:
		
		/*Si nos movemos hacia abajo, debemos aumentar el numero de filas*/
		if(x < filas)
		{
			x++;
		}
		
		return 0;
		
		break;
		
		
	case KEY_RIGHT:
		
		/*Si nos movemos hacia la derecha, debemos aumentar el número de columnas*/
		if(y < columnas)
		{
			y++;
		}
		
		return 0;
		
		break;
		
		
	case KEY_LEFT:
		
		/*Si nos movemos hacia la izquierda, debemos disminuir el número de columnas*/
		if(y > 0)
		{
			y--;
		}
		
		return 0;
		
		break;
		
		
	case ENTER:
		
		/*Al presionar enter retornamos un 1*/
		return 1;
		
		break;
		
	case 115:
		
	case 83:
		
		/*Ignorar*/
		
		if(jbattleship && filas == 9 && columnas == 19)
		{
			system("cls");
			
			sistemaEcuaciones();
			
		}else
		{
			/*Se presionó la tecla 'S' en el cuadrado mágico, se retorna un 1 y se muestra la solución*/
			solucion = 1;
		}
		
		return 0;
		
		
	case 84:
		
	case 116:
		
		/*Ignorar*/
		if(filas == 1 && columnas == 2)
		{
			
			return 2;
			
		}else
		{
			
			return 0;
			
		}
		
	case 65:
		
	case 97:
		
		/*Ignorar*/
		if(jcuadrado)
		{
			
			breakout();
			
			return 1;
			
		}else
		{
			return 0;
		}
		
		break;
		
	default:
		
		return 0;
		
		break;
		
	}
}

int volverAJugar()
{
	char finPartida[2];
	
	/*Preguntamos si se quiere jugar de nuevo a agún juego*/
	printf("\n\n¿Desea jugar otra vez? (SI o NO) ");
	fflush(stdin);
	gets(finPartida);
	
	strlwr(finPartida);
	
	/*Se valida que no sólo se inserte un 'SI' o  un 'NO'*/
	while(strcmp(finPartida, "no") != 0 && strcmp(finPartida, "si") != 0)
	{
		printf("\n\nOpción NO válida. Escriba SI o NO ");
		fflush(stdin);
		gets(finPartida);
		
		strlwr(finPartida);
		
	}
	
	if(strcmp(finPartida, "no") == 0)
	{
		return 1;
		
	}else
	{
		return 0;
	}
	
}

void instructivo()
{
	/*Leemos un archivo con las instrucciones de los minijuegos*/
	int c;
	
	fd = fopen("Instructivo.txt", "rt");
	
	system("cls");
	
	if(fd == NULL)
	{
		printf("\n\nError al tratar de leer el archivo");
		
	} else
	{
		while((c = fgetc(fd)) != 'X')
		{
			if(c == '\n')
			{
				printf("\n");
				
			}else
			{
				putchar(c);
			}
		}
		
		fclose(fd);
	}
	
	getch();
	
	system("cls");
	
	main();
	
}


/*Ignorar (easter eggs)*/
void palindrome()
{
	char palabra[90];
	
	int cont = 0, validar = 1, espacio = 1, fin = 0;
	
	do
	{
		validar = 1;
		
		system("cls");
		
		Color(BLACK, GREEN);
		printf("\nUn pequeño Easter Egg (01)\n");
		
		Color(BLACK, WHITE);
		printf("\nUn palíndromo es una palabra o frase que se lee igual adelante que atrás.\n\nInserte una frase: ");
		fflush(stdin);
		gets(palabra);
		
		strlwr(palabra);
		
		for(int i = 0; i < 90; i++)
		{
			if (palabra[i] == 32)
			{
				espacio = 1;
				
				while(espacio)
				{
					for(int j = i + 1, k = i; j < 90; j++, k++)
					{
						palabra[k] = palabra[j];
						
					}
					
					if (palabra[i] != 32)
					{
						espacio = 0;
					}
					
				}
			}
			
		}
		
		cont = strlen(palabra);
		
		char frase[cont];
		
		for(int i = 0; i < cont; i++)
		{
			frase[i] = palabra[i];
		}
		
		for(int i = 0, j = cont - 1; i < cont; i++, j--)
		{
			if(frase[i] != frase[j])
			{
				validar = 0;
				
				break;
			}
		}
		
		if(validar)
		{
			printf("\n\nLa frase es palíndrome");
			
		} else
		{
			printf("\n\nLa frase NO es palíndrome");
		}
		
		fin = volverAJugar();
		
	}while(fin == 0);
	
	system("cls");
	
	main();

}

void sistemaEcuaciones()
{
	system("cls");
	
	x = 0, y = 0;
	
	int fin = 0, filas = 1, columnas = 2, rellenado = 0;
	
	float matriz[2][3], deter, xaux, yaux;
	
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matriz[i][j] = 0;
		}
	}
	
	do
	{
		do
		{
			system("cls");
			
			Color(BLACK, GREEN);
			printf("\nUn pequeño Easter Egg (02)\n");
			
			Color(BLACK, WHITE);
			printf("\nAhora puede ser más fácil resolver sistemas de ecuaciones 2x2");
			printf("\nCuando termine de llenar los datos, presione 'T'\n\n");
			
			for(int i = 0; i < 2; i++)
			{
				for(int j = 0; j < 3; j++)
				{
					if(x == i && y == j && j == 0)
					{
						printf(" [%c%c%c%c]X", 219, 219, 219, 219);
						
					}else if(x == i && y == j && j == 1)
					{
						printf(" + [%c%c%c%c]Y", 219, 219, 219, 219);
						
					}else if(x == i && y == j && j == 2)
					{
						printf(" = [%c%c%c%c]", 219, 219, 219, 219);
						
					}else if(j == 0)
					{
						printf(" [%.2f]X", matriz[i][j]);
						
					}else if(j == 1)
					{
						printf(" + [%.2f]Y", matriz[i][j]);
						
					}else
					{
						printf(" = [%.2f]", matriz[i][j]);
					}
					
				}
				
				printf("\n\n");
				
			}
			
			fin = direccionales(filas, columnas);
			
		}while(fin == 0);
		
		if(fin != 2)
		{
			printf("\n\nInserte el valor correspondiente: ");
			
			scanf("%f", &matriz[x][y]);
			
		}else
		{
			deter = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
			
			if(deter != 0)
			{
				xaux = (matriz[0][2] * matriz[1][1] - matriz[1][2] * matriz[0][1])/deter;
				
				yaux = (matriz[0][0] * matriz[1][2] - matriz[1][0] * matriz[0][2])/deter;
				
				printf("\n\nX = %.2f", xaux);
				printf("\nY = %.2f", yaux);
				
			}else
			{
				printf("\n\nNo hay solución o te faltaron llenar campos");
			}
			
			rellenado = volverAJugar();
			
		}
		
	}while(rellenado == 0);
	
	system("cls");
	
	main();
	
}

void breakout()
{
	x = 0, y = 0;
	
	int xSpeed = 1, ySpeed = 1;
	
	char t[20][70];
	int fin = 0;
	
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 70; j++)
		{
			if(i > 2 && j > 2 && j < 68 && i < 14)
			{
				t[i][j] = 32;
				
			}else
			{
				t[i][j] = 32;
			}
			
			
		}
	}
	
	
	do
	{
		system("cls");
		
		Color(BLACK, GREEN);
		
		printf("\nUn pequeño Easter Egg (05)");
		
		Color(BLACK, WHITE);
		
		printf("\n\nIntento fallido de recrear el famoso minijuego Breakout\nLo intentaremos en orientada a objetos!");
		
		for(int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 70; j++)
			{
				
				if(j>=0){
					Color(BLACK, YELLOW);
				}
				if(j>=10){
					Color(BLACK, RED);
				}
				if(j>=20){
					Color(BLACK, BLUE);
				}
				if(j>=30){
					Color(BLACK, GREEN);
				}
				if(j>=40){
					Color(BLACK, LMAGENTA);
				}
				if(j>=50){
					Color(BLACK, LRED);
				}
				if(j>=60){
					Color(BLACK, WHITE);
				}
				
				if(i == x && j == y)
				{
					
					printf("%c", 'O');
					
				}else if(i == 19 && j == 32)
				{
					for(int k = 32; k < 38; k++)
					{
						Color(BLACK, LBLUE); printf("%c", 219);
					}
					
				}else
				{
					printf("%c", t[i][j]);
				}
				
				
				
			}
			
			printf("\n");
			
		}
		
		x += xSpeed;
		y += ySpeed;
		
		if(x > 19 || x < 1)
		{
			xSpeed *= -1;
		}
		
		if(y > 69 || y < 1)
		{
			ySpeed *= -1;
		}
		
		Sleep(50);
		
	}while(fin == 0);
	
}
