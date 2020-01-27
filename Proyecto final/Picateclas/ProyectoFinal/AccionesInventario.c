#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
//48,108,172,256, 258,275,362,435,478,502,530,768.
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

int flagV; //Bandera que valida que se ingresen datos correctos
int flagVsub; //Bandera que determina que se hayan ingresado datos correctos en la seleccion de subcategoria
char opcionProducto;
char busqueda[50]; //Cadena que realiza la busqueda de algun producto en particular

//Método que se encarga de cambiar la paleta de colores del texto impreso en pantalla
void color(char color){
	HANDLE cambioDeColor;
	cambioDeColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cambioDeColor, color);
}

struct producto {
	//Entradas
	char tipo[50];
	char subtipo[50];
	char nombre[50];
	char descripcion[500];
	int precioOriginal;
	int precioPromocional;
	int stock;
} articulo;

struct tarjetaPrepago {
	char codigo[20];
	int valor;
	char estado[1];
}tarjeta;

//funcion para abrir el archivo de una tarjeta y guardar sus datos en las variables temporales
void abrirTarjeta(char NIP[20]) {
	FILE *fd;
	char *direccion;
	
	direccion = malloc(500*sizeof(char)); //Se reserva memoria para la ubicacion del archivo
	
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Tarjetas\\");
	strcat(direccion, NIP);
	strcat(direccion, ".txt");
	
	
	//Verifica que el archivo exista
	fd = fopen(direccion,"r");
	if (fd == NULL){
		printf("Codigo NIP incorrecto."); //Mensaje cuando ingresa un codigo no valido
		strcpy(tarjeta.codigo, ""); //Se vacia la variable ingresada
		getch();
	}
	else{
	char caracteres[200];
	char *token;
	char sep[2]={";"}; //Separador existen 2 ; en cada tarjeta
	int j = 0;
	int datoNum;
	
	while (feof(fd) == 0) {
		int i = 0;
		
		fgets(caracteres,200,fd);
		
		token = strtok(caracteres, sep);
		
		//while para separar en tokens
		
		while(token != NULL ) {
			
			if(i==0){
				strcpy(tarjeta.codigo,token);
			}
			if(i==1){
				datoNum = atoi(token);
				tarjeta.valor = datoNum;
			}
			if(i==2){
				strcpy(tarjeta.estado,token);
			}
			i++;
			token = strtok(NULL, sep);
		}
		j++;
		printf("\n");
	}
	rewind(fd);
	}
	fclose(fd);
}

//Metodo que ulitiza la tarjeta
void utilizarTarjeta(char NIP[20]){
	system("cls");
	FILE *fd;
	char *direccion;
	
	direccion = malloc(500*sizeof(char)); //Se reserva memoria para la ubicacion del archivo
	
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Tarjetas\\");
	strcat(direccion, NIP);
	strcat(direccion, ".txt");
	
	
	strcpy(tarjeta.estado, "X"); //Cambia el estado de la tarjeta a usada
	
	//Actualiza los datos de la tarjeta
	fd = fopen(direccion,"w+");
	fprintf(fd,"%s;%d;%s",tarjeta.codigo,tarjeta.valor,tarjeta.estado);
	fclose(fd);
	
	free(direccion);
	
	getch();
}

//Metodo en el cual se crea una nueva tarjeta de regalo por parte del administrador
void GenerarTarjetaPrepago(){
	system("cls");
	
	flagV = 0; //Bandera de validacion de datos correctos
	
	printf("Ingrese el numero de activación de la tarjeta (max. 10 caracteres): ");
	scanf("%s", tarjeta.codigo);
	
	//Aqui se selecciona el valor de la tarjeta ($200, $500, $1000 o hasta $5000)
	while(flagV == 0){
		flagV = 1;
		system("cls"); fflush(stdin); //Limpia pantalla y buffer
		
		printf("Ingrese el valor de la tarjeta\n");
		printf("1. $200\n");
		printf("2. $500\n");
		printf("3. $1000\n");
		printf("4. $5000\n");
		printf("Escoja una opción (1-4): ");
		scanf(" %c", &opcionProducto);
		
		switch(opcionProducto){
		case '1':
			tarjeta.valor = 200;
			break;
		case '2':
			tarjeta.valor = 500;
			break;
		case '3':
			tarjeta.valor = 1000;
			break;
		case '4':
			tarjeta.valor = 5000;
			break;
		default:
			printf("\nOpción no válida");
			flagV = 0;
			break;
		}
	}
	
	//Se define el estado de la nueva tarjeta ("O" nueva, "X" usada)
	strcpy(tarjeta.estado, "O");
	
	//Realiza la generacion del archivo
	char direccion[100];
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Tarjetas\\");
	strcat(direccion, tarjeta.codigo);
	strcat(direccion, ".txt");
	
	printf("\nGenerando el archivo... \n");
	
	FILE *fd = fopen(direccion,"wt"); //wt = write text - escribir texto
	
	if(fd == NULL){
		printf("\nError: Ocurrió un problema al generar el archivo");
	}
	
	//Escribe el contenido de la estructura actual en el archivo de texto que contendra los datos del producto
	fwrite(tarjeta.codigo,1,strlen(tarjeta.codigo),fd);
	fprintf(fd,";");
	fprintf(fd,"%d",tarjeta.valor);
	fprintf(fd,";");
	fprintf(fd,"%s",tarjeta.estado);
	
	fclose(fd);
}

//Busca el producto
void buscarProducto(){
	printf("Ingrese el nombre del producto: ");
	scanf("%s", busqueda);
}

//funcion para abrir el archivo de un producto.
void abrirProducto(FILE *fd) {
	char caracteres[200];
	char *token;
	char sep[6]={";"}; //Separador existen 6 ; en cada producto
	int j = 0;
	int dato;
	
	while (feof(fd) == 0) {
		int i = 0;
		
		fgets(caracteres,200,fd);
		
		token = strtok(caracteres, sep);
		
		//while para separar en tokens
		
		while(token != NULL ) {
			
			if(i==0){
				strcpy(articulo.tipo,token);
			}
			if(i==1){
				strcpy(articulo.subtipo,token);
			}
			if(i==2){
				strcpy(articulo.nombre,token);
			}
			if(i==3){
				strcpy(articulo.descripcion,token);
			}
			if(i==4){
				dato = atoi(token);
				articulo.precioOriginal = dato;
			}
			if(i==5){
				dato = atoi(token);
				articulo.precioPromocional = dato;
			}
			if(i==6){
				dato = atoi(token);
				articulo.stock = dato;
			}
			i++;
			token = strtok(NULL, sep);
		}
		j++;
		printf("\n");
	}
	rewind(fd);
}

//NOTA: FUNCION DE SOLO PRUEBAS NO SE RECOMIENDA SU USO TODAVIA
void mostrarVariosProductos(int tipo, int marcador){
	struct dirent * entry;
	DIR* dir;
	dir = opendir("C:\\Cliente\\ProyectoFinal\\Productos\\");
	char directorio[500];
	strcpy(directorio,"C:\\Cliente\\ProyectoFinal\\Productos\\");
	
	int contadorTipo = 0; //Contador de productos de una categoria
	
	if(dir==NULL){
		printf("Error! Unable to read directory");
		exit(1);
	}
	
	while ((entry = readdir(dir)) != 0) {
		if (!strcmp (entry->d_name, ".")){ //Evita que imprima estas cositas
			continue;
		}
		if (!strcmp (entry->d_name, "..")){ //Evita que imprima estas cositas
			continue;
		}
		//Lee cada archivo individualmente
		strcpy(directorio,"C:\\Cliente\\ProyectoFinal\\Productos\\");
		strcat(directorio,entry->d_name);
		
		FILE *fd;
		fd = fopen(directorio,"r");
		abrirProducto(fd); //Lee el contenido del archivo
		
		if(tipo==1 && strcmp(articulo.tipo,"Gadgets")==0){ //Muestra solo los productos si son de la categoria "Gadgets"
			contadorTipo++;
			printf("%d. %s  $%d",contadorTipo ,articulo.nombre, articulo.precioOriginal); //Imprime el nombre del archivo
			if(marcador==contadorTipo){
				/*Si el marcador seleccionado coincide con el contadorTipo copiara el nombre del articulo en
				en la busqueda para ver mas a detalle el producto y realizar su compra*/
				strcpy(busqueda, articulo.nombre);
			}
		}
		if(tipo==2 && strcmp(articulo.tipo,"Software")==0){ //Muestra solo los productos si son de la categoria "Software"
			contadorTipo++;
			printf("%d. ", contadorTipo);
			//Variando de la plataforma imprimira el siguiente color
				if(strcmp(articulo.subtipo,"Switch")==0 || strcmp(articulo.subtipo,"3DS")==0){
					color(12); //Pinta el subtipo a color rojo 
				}
				if(strcmp(articulo.subtipo,"PS4")==0 || strcmp(articulo.subtipo,"PSV")==0){
				    color(1); //Pinta el subtipo a color azul
				}
				if(strcmp(articulo.subtipo,"XboxOne") == 0){
					color(2); //Pinta el subtipo a color verde
				}
				printf("%s ", articulo.subtipo);
				color(7); //Vuelve el texto al color por defecto
				printf("%s $%d", articulo.nombre, articulo.precioOriginal);
				if(marcador==contadorTipo){
					/*Si el marcador seleccionado coincide con el contadorTipo copiara el nombre del articulo en
					en la busqueda para ver mas a detalle el producto y realizar su compra*/
					strcpy(busqueda, articulo.nombre);
				}
		}
		if(tipo==3 && strcmp(articulo.tipo,"Anime")==0){ //Muestra solo los productos si son de la categoria "Anime"
			contadorTipo++;
			printf("%d. %s  $%d",contadorTipo ,articulo.nombre, articulo.precioOriginal); //Imprime el nombre del archivo
			if(marcador==contadorTipo){
				/*Si el marcador seleccionado coincide con el contadorTipo copiara el nombre del articulo en
				en la busqueda para ver mas a detalle el producto y realizar su compra*/
				strcpy(busqueda, articulo.nombre);
			}
		}
		if(tipo==4 && strcmp(articulo.tipo,"Manga")==0){ //Muestra solo los productos si son de la categoria "Manga"
			contadorTipo++;
			printf("%d. %s  $%d",contadorTipo ,articulo.nombre, articulo.precioOriginal); //Imprime el nombre del archivo
			if(marcador==contadorTipo){
				/*Si el marcador seleccionado coincide con el contadorTipo copiara el nombre del articulo en
				en la busqueda para ver mas a detalle el producto y realizar su compra*/
				strcpy(busqueda, articulo.nombre);
			}
		}
		if(tipo==5 && strcmp(articulo.tipo,"Accesorios")==0){ //Muestra solo los productos si son de la categoria "Accesorios"
			contadorTipo++;
			printf("%d. %s  $%d",contadorTipo ,articulo.nombre, articulo.precioOriginal); //Imprime el nombre del archivo
			if(marcador==contadorTipo){
				/*Si el marcador seleccionado coincide con el contadorTipo copiara el nombre del articulo en
				en la busqueda para ver mas a detalle el producto y realizar su compra*/
				strcpy(busqueda, articulo.nombre);
			}
		}
		if(tipo==6 && strcmp(articulo.tipo,"Coleccionables")==0){ //Muestra solo los productos si son de la categoria "Coleccionables"
			contadorTipo++;
			printf("%d. %s  $%d",contadorTipo ,articulo.nombre, articulo.precioOriginal); //Imprime el nombre del archivo
			if(marcador==contadorTipo){
				/*Si el marcador seleccionado coincide con el contadorTipo copiara el nombre del articulo en
				en la busqueda para ver mas a detalle el producto y realizar su compra*/
				strcpy(busqueda, articulo.nombre);
			}
		}
		
		fclose(fd); //Cierra el archivo actual
	}
	closedir(dir); //Cierra el directorio
}

//funcion que muestra el contenido del archivo del producto
void mostrarProductoContent(){
	FILE *fd;
	char *direccion;
	
	direccion = malloc(500*sizeof(char)); //Se reserva memoria para la ubicacion del archivo
	
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Productos\\");
	strcat(direccion, busqueda);
	strcat(direccion, ".txt");
	
	
	//Verifica que el archivo exista
	fd = fopen(direccion,"r");
	if (fd == NULL){
		printf("Ese producto no existe."); //Mensaje de aviso cuando no se encuentra el archivo
		strcpy(articulo.nombre,""); //Se vacia el nombre del articulo ingresado
	}
	else{
		abrirProducto(fd);
		
		system("cls");
		printf("\t\tINFORMACION DEL PRODUCTO");
		
		for(int k = 0; k < 7; k++) {
			if(k==0){
				printf("\nTipo: %s",articulo.tipo);
			}
			if(k==1){
				printf("\tSubtipo: %s",articulo.subtipo);
				printf("\n__________________________________________________");
			}
			if(k==2){
				printf("\nNombre del articulo: %s",articulo.nombre);
			}
			if(k==3){
				printf("\n\nDescripcion: %s",articulo.descripcion);
			}
			if(k==4){
				printf("\n\nPrecio: $%d",articulo.precioOriginal);
			}
			if(k==5 && articulo.precioOriginal>articulo.precioPromocional){
				float descuento;
				
				descuento = ((float)articulo.precioPromocional/articulo.precioOriginal - 1.0) * 100.0;
				
				color(10); //Pinta el color a verde claro
				printf("\nDescuento: %d%c OFF", abs(descuento), 37);
				printf("\nPrecio Oferta: $%d",articulo.precioPromocional);
				color(7); //Pinta el color al por defecto
			}
			if(k==6){
				if (articulo.stock > 0){
					printf("\nCantidad disponibles: %d",articulo.stock);
				}
				else {
					color(12); //Pinta el color a rojo
					printf("\nAGOTADO");
					color(7); //Pinta el color al por defecto
					printf("\n__________________________________________________");
				}
			}
		}
	}
	fclose(fd);
	
	free(direccion); //Libera memoria asignada del arreglo de la direccion
}

//Funcion en el cual permite editar y actualizar datos del producto
void editarDatosArchivo(){
	FILE *fd;
	
	mostrarProductoContent();
	system("cls");
	
	char *direccion;
	
	direccion = malloc(500*sizeof(char)); //Se reserva memoria para la ubicacion del archivo
	
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Productos\\");
	strcat(direccion, articulo.nombre);
	strcat(direccion, ".txt");
	
	//Se definen los nuevos datos del producto
	printf("\nNombre del producto actual: %s", articulo.nombre);
	printf("\nIngrese el nuevo nombre del producto: ");
	scanf("%s", articulo.nombre);
	
	printf("\nDescripcion del producto actual: %s", articulo.descripcion);
	printf("\nIngrese la nueva descripcion del producto: ");
	scanf("%s", articulo.descripcion);
	
	printf("\nPrecio del producto actual: %d", articulo.precioOriginal);
	printf("\nIngrese el nuevo precio del producto: ");
	scanf("%d", &articulo.precioOriginal);
	
	printf("\nPrecio promocional del producto actual: %d", articulo.precioPromocional);
	printf("\nIngrese el precio promocional del producto (debe ser menor al original): ");
	scanf("%d", &articulo.precioPromocional);
	
	//En caso que haya colocado el precio promocional mas alto que el original por accidente, se igualaran ambos precios
	if(articulo.precioPromocional>articulo.precioOriginal){
		articulo.precioOriginal = articulo.precioPromocional;
	}
	
	//Actualiza los datos del producto
	fd = fopen(direccion,"r+");
	fprintf(fd,"%s;%s;%s;%s;%d;%d;%d",
			articulo.tipo,articulo.subtipo,articulo.nombre,articulo.descripcion,articulo.precioOriginal,articulo.precioPromocional,articulo.stock);
	fclose(fd);
	
	free(direccion);
	
}

//Metodo que incrementa el stock del producto de acuerdo a la peticion por el administrador
int incrementarStock(int cant){
	FILE *fd;
	char *direccion;
	
	direccion = malloc(500*sizeof(char)); //Se reserva memoria para la ubicacion del archivo
	
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Productos\\");
	strcat(direccion, articulo.nombre);
	strcat(direccion, ".txt");
	
	articulo.stock = articulo.stock + cant; //Aumenta el stock
	
	//Actualiza los datos del producto
	fd = fopen(direccion,"w+");
	fprintf(fd,"%s;%s;%s;%s;%d;%d;%d",
			articulo.tipo,articulo.subtipo,articulo.nombre,articulo.descripcion,articulo.precioOriginal,articulo.precioPromocional,articulo.stock);
	fclose(fd);
	
	free(direccion);
	
	return articulo.stock;
}

//Metodo que decrementa el stock cuando el usuario compra uno o varios productos
int decrementarStock(int cant){
	FILE *fd;
	char *direccion;
	
	direccion = malloc(500*sizeof(char)); //Se reserva memoria para la ubicacion del archivo
	
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Productos\\");
	strcat(direccion, articulo.nombre);
	strcat(direccion, ".txt");
	
	articulo.stock = articulo.stock - cant; //Resta el stock del producto con la cantidad que el usuario ingreso
	
	//Actualiza los datos del producto
	fd = fopen(direccion,"w+");
	fprintf(fd,"%s;%s;%s;%s;%d;%d;%d",
	articulo.tipo,articulo.subtipo,articulo.nombre,articulo.descripcion,articulo.precioOriginal,articulo.precioPromocional,articulo.stock);
	fclose(fd);
	
	free(direccion);
	
	return articulo.stock;
}

//Procedimiento donde el administrador elimina un archivo ingresando su nombre
void EliminarProducto(){
	system("cls");
	int status; //Estado en el cual verifica si el archivo se elimino correctamente
	char nombre_archivo[50];
	char direccion[100];
	
	printf("Ingrese el nombre del producto que desea eliminar\n");
	printf("NOTA: Use (_) como espacio para separar\n Nombre: ");
	scanf("%s", nombre_archivo);
	
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Productos\\");
	strcat(direccion, nombre_archivo);
	strcat(direccion, ".txt");
	
	status = remove(direccion);
	
	if (status == 0)
		printf("%s ha sido eliminado de manera exitosa.\n", direccion);
	else
	{
		printf("No se pudo eliminar\n");
	}
	getch();
}

//Procedimiento donde el administrador agrega un nuevo producto definiendo sus datos y guardandolos en un archivo de texto
void GenerarProducto(){
	flagV = 0;
	flagVsub = 0;
	
	//Primero se define la categoria principal del producto
	while(flagV==0){
	flagV = 1;
	system("cls"); //Limpiar pantalla
	
	printf("Ingrese la categoria principal del producto");
	printf("\n1. Gadgets");
	printf("\n2. Software y videojuegos");
	printf("\n3. Series y Peliculas de animacion");
	printf("\n4. Manga y comics");
	printf("\n5. Accesorios y perifericos");
	printf("\n6. Coleccionables");
	printf("\nEscoja una opción  (1-6): ");
	scanf(" %c", &opcionProducto);
	
	switch(opcionProducto){
		//Una vez elegida la categoria principal se selecciona la subcategoria del producto
		case '1':
			strcpy(articulo.tipo,"Gadgets");
			
		while(flagVsub==0){
			flagVsub = 1;	
			
			system("cls");
			printf("Ingrese la subcategoria del producto");
			printf("\n1. PC y laptops");
			printf("\n2. Consolas de videojuegos");
			printf("\n3. Celulares y tabletas");
			printf("\nEscoja una opción (1-3): ");
			scanf(" %c", &opcionProducto);
			
			switch(opcionProducto){
				case '1':
					strcpy(articulo.subtipo,"Compus");
				break;
			    case '2':
					strcpy(articulo.subtipo,"Consolas");
				break;
			    case '3':
					strcpy(articulo.subtipo,"Moviles");
				break;
			    default:
					printf("\nOpción no válida");
					flagVsub = 0;
				break;
			}
		}
			
		break;
	    case '2':
			strcpy(articulo.tipo,"Software");
			
		while(flagVsub==0){
			flagVsub = 1;	
				
			system("cls");
			printf("Ingrese la subcategoria del producto");
			printf("\n1. PC");
			printf("\n2. Nintendo Switch");
			printf("\n3. Nintendo 3DS");
			printf("\n4. Playstation 4");
			printf("\n5. Playstation Vita");
			printf("\n6. Xbox one");
			printf("\nEscoja una opción (1-6): ");
			scanf(" %c", &opcionProducto);
				
			switch(opcionProducto){
				case '1':
					strcpy(articulo.subtipo,"PC");
				break;
				case '2':
					strcpy(articulo.subtipo,"Switch");
				break;
				case '3':
					strcpy(articulo.subtipo,"3DS");
				break;
				case '4':
					strcpy(articulo.subtipo,"PS4");
				break;
			    case '5':
					strcpy(articulo.subtipo,"PSV");
				break;
			    case '6':
					strcpy(articulo.subtipo,"XboxOne");
				break;
				default:
					printf("\nOpción no válida");
					flagVsub = 0;
				break;
			}
		}
			
		break;
	    case '3':
			strcpy(articulo.tipo,"Anime");
			
			while(flagVsub==0){
				flagVsub = 1;	
				
				system("cls");
				printf("Ingrese la subcategoria del producto");
				printf("\n1. Series");
				printf("\n2. Peliculas");
				printf("\n3. OVAS y especiales");
				printf("\nEscoja una opción (1-3): ");
				scanf(" %c", &opcionProducto);
				
				switch(opcionProducto){
				case '1':
					break;
				case '2':
					break;
				case '3':
					break;
				default:
					printf("\nOpción no válida");
					flagVsub = 0;
					break;
				}
			}
			
		break;
	    case '4':
			strcpy(articulo.tipo,"Manga");
			
			strcpy(articulo.subtipo,"Mangas");
		break;
	    case '5':
			strcpy(articulo.tipo,"Accesorios");
			
			while(flagVsub==0){
				flagVsub = 1;	
				
				system("cls");
				printf("Ingrese la subcategoria del producto");
				printf("\n1. Memorias y expansiones");
				printf("\n2. Perifericos");
				printf("\n3. Procesadores y tarjetas de video");
				printf("\nEscoja una opción (1-3): ");
				scanf(" %c", &opcionProducto);
				
				switch(opcionProducto){
				case '1':
					strcpy(articulo.subtipo,"Memoria");
				break;
				case '2':
					strcpy(articulo.subtipo,"Perifericos");
				break;
				case '3':
					strcpy(articulo.subtipo,"CPU&GPU");
				break;
				default:
					printf("\nOpción no válida");
					flagVsub = 0;
					break;
				}
			}
		break;
	    case '6':
			strcpy(articulo.tipo,"Coleccionables");
			
			while(flagVsub==0){
				flagVsub = 1;	
				
				system("cls");
				printf("Ingrese la subcategoria del producto");
				printf("\n1. Muñecos, figuras y similares");
				printf("\n2. Cartas, tarjetas y posters");
				printf("\n3. Otros");
				printf("\nEscoja una opción (1-3): ");
				scanf(" %c", &opcionProducto);
				
				switch(opcionProducto){
				case '1':
					strcpy(articulo.subtipo,"Figures");
				break;
				case '2':
					strcpy(articulo.subtipo,"Cards");
				break;
				case '3':
					strcpy(articulo.subtipo,"Otros");
				break;
				default:
					printf("\nOpción no válida");
					flagVsub = 0;
					break;
				}
			}
		break;
	    default:
			flagV = 0;
			printf("\nOpción no válida");
			getch();
		break;
	}
		
	system("cls"); fflush(stdin); //Limpiar pantalla y buffer
	printf("\nIngrese el nombre del producto: ");
	scanf("%s", articulo.nombre);
	
	system("cls"); fflush(stdin); //Limpiar pantalla y buffer
	printf("\nIngrese una descripción del producto: ");
	scanf("%s", articulo.descripcion);
	
	system("cls"); fflush(stdin); //Limpiar pantalla y buffer
	printf("\nIngrese el precio del producto: ");
	scanf("%d", &articulo.precioOriginal);
	
	articulo.precioPromocional = articulo.precioOriginal; //Copia el contenido del precio original al promocional
	
	system("cls"); fflush(stdin); //Limpiar pantalla y buffer
	printf("\nIngrese la cantidad: ");
	scanf("%d", &articulo.stock);
	
	}

	//Realiza la generacion del archivo
	char direccion[500];
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Productos\\");
	strcat(direccion, articulo.nombre);
	strcat(direccion, ".txt");
	
	printf("\nGenerando el archivo... \n");
	
	FILE *fd = fopen(direccion,"wt"); //wt = write text - escribir texto
	
	if(fd == NULL){
		printf("\nError: Ocurrió un problema al generar el archivo");
	}
	
	//Escribe el contenido de la estructura actual en el archivo de texto que contendra los datos del producto
	fwrite(articulo.tipo,1,strlen(articulo.tipo),fd);
	fprintf(fd,";");
	fwrite(articulo.subtipo,1,strlen(articulo.subtipo),fd);
	fprintf(fd,";");
	fwrite(articulo.nombre,1,strlen(articulo.nombre),fd);
	fprintf(fd,";");
	fwrite(articulo.descripcion,1,strlen(articulo.descripcion),fd);
	fprintf(fd,";");
	fprintf(fd,"%d",articulo.precioOriginal);
	fprintf(fd,";");
	fprintf(fd,"%d",articulo.precioPromocional);
	fprintf(fd,";");
	fprintf(fd,"%d",articulo.stock);
	
	fclose(fd);
}

