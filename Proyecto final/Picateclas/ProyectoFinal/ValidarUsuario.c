#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "AccionesInventario.c"
//30,53,99,248,384,394,583,736.

char opcionLogin;
char vercontrasena[20]; //Contrasena para verificar en el proceso de creacion de una cuenta nueva
int GananciasTotales = 0; //Fondos ganados que ha obtenido la tienda

//Estructura que contiene todos los datos del usuario
struct Usuario{
	//Entradas
	char nombre[100];
	char pais[20];
	char estado[30];
	char municipio[30];
	int codigopostal;
	char direccion[60];
	long int notelefono;
	char contrasena[100];
	char perfil; //Representa el tipo de usuario si es normal o es administrador
	int saldo;
}usuario;

//Metodo que visualiza los movimientos y compras que ha hecho el usuario en la opcion de ver su perfil
void visualizarMovimientos(){
	char c;
	char direccion[500];
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Movimientos\\");
	strcat(direccion, usuario.nombre);
	strcat(direccion, "mov.txt");
	
	printf("\t\tMOVIMIENTOS DE LA CUENTA\n");
	
	FILE *fd = fopen(direccion,"r"); //r leer archivo
	if(fd == NULL){
		printf("Aún no has realizado un movimiento");
	}
	while((c=fgetc(fd))!=EOF){
		if(c=='\n'){
			printf("\n");
		}
		else{
			putchar(c);
		}
	}
}

//Genera movimientos de la cuenta recibe como parametros la cantidad de productos o saldo de la tarjeta ingresada y el tipo de accion para agregar el tipo de movimiento
void generarMovimientosCuenta(int cant, int val){
	char direccion[500];
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Movimientos\\");
	strcat(direccion, usuario.nombre);
	strcat(direccion, "mov.txt");
	
	FILE *fd = fopen(direccion,"at"); //at = append text - agregar texto
	
	time_t tiempo = time(0);
	struct tm * tlocal = localtime(&tiempo);
	char output[128];
	strftime(output, 128, "%d/%m/20%y %H:%M:%S", tlocal);
	
	int saldoanterior;
	
	if(val==1){
		saldoanterior = usuario.saldo + articulo.precioPromocional*cant;
		
		fprintf(fd,"\t\tTHE OTAKUGAMER ZONE");
		
		fprintf(fd,"\t\t\nFecha de compra: %s", output);
		
		fprintf(fd,"\n\nNombre producto: %s", articulo.nombre);
		fprintf(fd,"\n\nPrecio: %d", articulo.precioPromocional);
		fprintf(fd,"\n\nCantidad adquirida: %d", cant);
		
		fprintf(fd,"\n\nSaldo antes de la compra: $%d", saldoanterior);
		fprintf(fd,"\n\nTotal pagado: $%d", articulo.precioPromocional*cant);
		fprintf(fd,"\nSaldo despues de la compra: $%d", usuario.saldo);
		
		fprintf(fd,"\n___________________________________________\n");
	}
	if(val==2){
		
		fprintf(fd,"\n\nTarjeta THE OTAKUGAMER ZONE $%d", tarjeta.valor);
		saldoanterior = usuario.saldo - cant;
		
		fprintf(fd,"\n\nSaldo antes del canje: $%d", saldoanterior);
		fprintf(fd,"\n\nTotal abonado: $%d", tarjeta.valor);
		fprintf(fd,"\n\nSaldo despues del canje: $%d", usuario.saldo);
		fprintf(fd,"\n___________________________________________\n");
	}
	fclose(fd);
}

//Metodo que actualiza los datos del archivo de texto del usuario
void actualizarDatosUsuario(){
	char direccion[500];
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Usuarios\\");
	strcat(direccion, usuario.nombre);
	strcat(direccion, ".txt");
	
	FILE *fd = fopen(direccion,"w"); //wt = write text - escribir texto
	
	//Escribe los datos en el archivo
	fprintf(fd,"NOMBRE:\n");
	fwrite(usuario.nombre,1,strlen(usuario.nombre),fd);
	fprintf(fd,"\nPAIS:\n");
	fwrite(usuario.pais,1,strlen(usuario.pais),fd);
	fprintf(fd,"\nESTADO:\n");
	fwrite(usuario.estado,1,strlen(usuario.estado),fd);
	fprintf(fd,"\nMUNICIPIO O CIUDAD:\n");
	fwrite(usuario.municipio,1,strlen(usuario.municipio),fd);
	fprintf(fd,"\nDIRECCION:\n");
	fwrite(usuario.direccion,1,strlen(usuario.direccion),fd);
	fprintf(fd,"\nCODIGO POSTAL:\n");	
	fprintf(fd,"%d", usuario.codigopostal);
	fprintf(fd,"\nNUMERO DE TELEFONO:\n");
	fprintf(fd,"%ld", usuario.notelefono);
	fprintf(fd,"\nCONTRASENA:\n");
	fwrite(usuario.contrasena,1,strlen(usuario.contrasena),fd);
	fprintf(fd,"\nSALDO DISPONIBLE:\n");
	fprintf(fd,"%d", usuario.saldo);
	fprintf(fd,"\nTIPO:\n");
	fprintf(fd,"%c",usuario.perfil);
	
	fclose(fd); //Cierra el proceso del archivo de texto
}

void agregarFondos(){
	char codigo[20];
	char opcionAgTarjeta;
	
	printf("\nIngrese el codigo de la tarjeta: ");
	scanf("%s", codigo);
	
	abrirTarjeta(codigo);
	if(strlen(tarjeta.codigo) != 0){ //Verifica que el codigo de la tarjeta no este vacio. (Se vacia si el codigo ingresado fue incorrecto)
		system("cls"); //Limpiar pantalla
		
		printf("\nTarjeta de prepago THE OTAKUGAMER ZONE: %d", tarjeta.valor);
		printf("\nDesea usted utilizar esa tarjeta.");
		printf("\n1. Si");
		printf("\n2 u otra tecla. No");
		printf("\nEscoja una opcion: (1-2): ");
		scanf(" %c", &opcionAgTarjeta);
		switch(opcionAgTarjeta){
		    case '1':
				//Verifica que la tarjeta no haya sido utilizada antes
				if(strcmp(tarjeta.estado,"O")==0){
				utilizarTarjeta(codigo);
				usuario.saldo = usuario.saldo + tarjeta.valor; //Agrega el valor de la tarjeta al saldo del usuario
				actualizarDatosUsuario(); //Actualiza los datos del archivo del usuario actual
				generarMovimientosCuenta(tarjeta.valor,2);
				}
				else{
					printf("\nEsa tarjeta ya fue utilizada");
					getch();
				}
			break;
		    default:
			break;
		}
	}
}

//Metodo cuando una vez seleccionado el producto, permite realizar su compra
void comprarProducto(){
	int cantidad;
	printf("\nNombre del producto a comprar: %s", articulo.nombre);
	
	printf("\n\nIngrese la cantidad del producto: ");
	scanf("%d", &cantidad);
	
	//Determina si hay stock disponible del producto y si el usuario tiene fondos suficientes para realizar la compra
	if(articulo.stock>=cantidad && usuario.saldo>articulo.precioPromocional*cantidad){
		decrementarStock(cantidad); //Llama a la funcion del inventario que resta stock al producto
		usuario.saldo = usuario.saldo - articulo.precioPromocional * cantidad; //Resta el saldo del usuario dependiedo del precio del producto y cantidad
		actualizarDatosUsuario(); //Actualiza los datos del archivo de texto del usuario
		generarMovimientosCuenta(cantidad,1); //Inestable aun se recomienda no usar
		
		GananciasTotales = GananciasTotales + articulo.precioPromocional * cantidad;
	}
	else if(articulo.stock<cantidad){
		printf("Error: No hay stock suficiente para realizar la compra");
	}
	else if(usuario.saldo<articulo.precioPromocional*cantidad){
		printf("Error: No tienes fondos suficientes para poder realizar la compra");
	}
	
}

//Metodo cuando un usuario normal esta logueado y selecciona el producto puede realizar las siguientes acciones
void OpcionesUsuarioProducto(){
	opcionLogin = ' ';
	
	printf("\n1. Comprar");
	printf("\n2. Agregar al carrito");
	printf("\n3 u otra tecla. Regresar al menu principal");
	printf("\nEscoja una opcion (1-3): ");
	scanf(" %c", &opcionLogin);
	
	switch(opcionLogin){
		case '1':
			comprarProducto();
		break;
	    case '2':
			//Falta agregar carro, aun no disponible
		break;
		default:
		break;
	}
}

//Metodo cuando un administrador esta logueado y selecciona el producto puede realizar las siguientes acciones
void OpcionesAdministradorProducto(){
	opcionLogin = ' ';
	int cantagregar; //Cantidad que el administrador agrega en la opcion de "agregar stock"
	
	printf("\n1. Modificar los datos de este producto");
	printf("\n2. Agregar mas unidades");
	printf("\n3 u otra tecla. Regresar al menu principal");
	printf("\nEscoja una opcion (1-3): ");
	scanf(" %c", &opcionLogin);
	
	switch(opcionLogin){
	case '1':
		system("cls");
		editarDatosArchivo();
	break;
	case '2':
		printf("\n\nIngrese la cantidad que desea agregar: ");
		scanf("%d", &cantagregar);
		incrementarStock(cantagregar);
		
		printf("\nStock agregado exitosamente"); getch();
	break;
	default:
	break;
	}
}

void EditarPerfil(){
	system("cls");
	char opcionPerfil;
	
	char direccion[500];
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Usuarios\\");
	strcat(direccion, usuario.nombre);
	strcat(direccion, ".txt");
	
	FILE *fd = fopen(direccion,"r+"); //r+ = leer texto con permisos de escritura
	
	char line[100]; //Arreglo que representa la una linea en el archivo de texto que contiene un maximo de hasta 100 caracteres
	int contadorLineas = 0;
	fflush(fd);
	
	if(fd == NULL){
		printf("\nError: Ocurrió un problema al leer el archivo");
	}
	
	printf("¿Que desea editar?");
	printf("\n1. Mi ubicacion y numero telefonico");
	printf("\n2. Mi contraseña");
	printf("\nEscoja una opcion (1-2): ");
	scanf(" %c", &opcionPerfil);
	
	switch(opcionPerfil){
	    case '1':
			printf("\nIngrese su nuevo Pais: ");
			scanf("%s", usuario.pais);
			printf("\nIngrese su nuevo Estado: ");
			scanf("%s", usuario.estado);
			fflush(stdin);
			printf("\nIngrese su nueva Ciudad o municipio: ");
			scanf("%s", usuario.municipio);
			printf("\nIngrese su nueva direccion: ");
			scanf("%s", usuario.direccion);
			fflush(stdin);
			printf("\nIngrese su nuevo codigo postal: ");
			scanf("%d", &usuario.codigopostal);
			printf("\nIngrese su nuevo numero de telefono: ");
			scanf("%ld", &usuario.notelefono);
			
			
			long pos = ftell(fd); //Guarda la posicion actual del contador interno de caracteres
			
			while (fgets(line, sizeof(line), fd)) { //Lee el archivo linea por linea hasta llegar a la contraseña
				contadorLineas++;
				if(contadorLineas == 4){ //Verifica que sea la linea donde se encuentra el pais
					fseek(fd, pos, SEEK_SET); //Indica el comienzo de la linea actual
					fprintf(fd,"%s", usuario.pais);
					fflush(fd); //Limpia el buffer del archivo
					getch();
				}
				if(contadorLineas == 7){ //Verifica que sea la linea donde se encuentra el estado
					fseek(fd, pos, SEEK_SET); //Indica el comienzo de la linea actual
					fprintf(fd,"%s", usuario.estado);
					fflush(fd); //Limpia el buffer del archivo
					getch();
				}
				if(contadorLineas == 10){ //Verifica que sea la linea donde se encuentra la ciudad
					fseek(fd, pos, SEEK_SET); //Indica el comienzo de la linea actual
					fprintf(fd,"%s", usuario.municipio);
					fflush(fd); //Limpia el buffer del archivo
					getch();
				}
				if(contadorLineas == 13){ //Verifica que sea la linea donde se encuentra la direccion
					fseek(fd, pos, SEEK_SET); //Indica el comienzo de la linea actual
					fprintf(fd,"%s", usuario.direccion);
					fflush(fd); //Limpia el buffer del archivo
					getch();
				}
				if(contadorLineas == 16){ //Verifica que sea la linea donde se encuentra el codigo postal
					fseek(fd, pos, SEEK_SET); //Indica el comienzo de la linea actual
					fprintf(fd,"%d", usuario.codigopostal);
					fflush(fd); //Limpia el buffer del archivo
					getch();
				}
				if(contadorLineas == 19){ //Verifica que sea la linea donde se encuentra el telefono
					fseek(fd, pos, SEEK_SET); //Indica el comienzo de la linea actual
					fprintf(fd,"%ld", usuario.notelefono);
					fflush(fd); //Limpia el buffer del archivo
					getch();
				}
				pos = ftell(fd); //Al termino de cada linea guarda la posicion donde comienza el primer caracter de la linea siguiente
			}
		break;
		case '2':
			system("cls");
			char currentPass[50]; //Contraseña actual a ingresar
			char verPass[50]; //Contraseña para verificar
			printf("\nIngrese su contraseña actual: ");
			scanf("%s", currentPass);
			
			//Revisa si la contraseña ingresada coincide con la del usuario 
			if(strcmp(currentPass,usuario.contrasena)==0){
				printf("\nIngrese su nueva contraseña: ");
				scanf("%s", currentPass);
				printf("\nVerifica su nueva contraseña: ");
				scanf("%s", verPass);
				//Revisa si las 2 nuevas contraseñas coinciden
				if(strcmp(currentPass,verPass)==0){
					strcpy(usuario.contrasena,currentPass);
					actualizarDatosUsuario(); //Llama a la funcion que actualiza los datos del usuario
					printf("\nSu contraseña se ha actualizado exitosamente");
					getch();
				}
				else{
					printf("\nError: Las contraseñas ingresadas no coinciden");
					getch();
				}
			}
			else{
				printf("\nError: La contraseña ingresada es incorrecta");
				getch();
			}
			
		break;
		default:
			printf("\nOpción no válida");
		break;
	}
	
	fclose(fd); //Cierra el proceso del archivo de texto
}

//Metodo en el cual permite el usuario borrar su cuenta de manera permanente
void EliminarPerfil(){
	char confEliminar;
	
	system("cls");
	
	printf("\nRealmente quieres eliminar tu cuenta, ten encuenta que al eliminar");
	printf("\nperderas todos tus datos incluyendo movimientos de la cuenta y saldo");
	printf("\n1. Si");
	printf("\n2 u otra tecla. No");
	scanf(" %c", &confEliminar);
	
	if(confEliminar=='1'){
	int status; //Estado en el cual verifica si el archivo se elimino correctamente
	char direccion[100];
	
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Usuarios\\");
	strcat(direccion, usuario.nombre);
	strcat(direccion, ".txt");
	
	//Borra el archivo del usuario al igual que limpia las variables temporales
	status = remove(direccion);
	strcmp(usuario.nombre,"");
	strcmp(usuario.contrasena,"");
	
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Movimientos\\");
	strcat(direccion, usuario.nombre);
	strcat(direccion, "mov.txt");
	
	status = remove(direccion);
	
	if (status == 0)
		printf("Tu cuenta ha sido eliminada de manera exitosa");
	else
	{
		printf("No se pudo eliminar\n");
	}
	getch();
	}
	else{
		printf("\nOperacion cancelada");
	}
}

//Menu en el cual el administrador puede realizar ciertas opciones
void OpcionesAdministrador(){
	int bandExit = 0; //Bandera que determina la salida de este menu
	int cantagregar; //Cantidad que el administrador agrega en la opcion de "agregar stock"
	usuario.saldo =  usuario.saldo + GananciasTotales; //Pasa a las ganancias totales de la tienda al saldo del administrador
	
	while(bandExit == 0){
		printf("Bienvenido: %s \t\tGanancias totales $%d MXN", usuario.nombre, usuario.saldo);
		
		printf("\n¿Que desea usted hacer?");
		printf("\n1. Ver mi perfil");
		printf("\n2. Editar información de mi perfil");
		printf("\n3. Agregar nuevos productos a la tienda");
		printf("\n4. Agregar stock de un producto");
		printf("\n5. Modificar los datos de un producto");
		printf("\n6. Eliminar un producto");
		printf("\n7. Crear una nueva tarjeta de prepago");
		printf("\n8. Volver al menu principal");
		printf("\n9. Cerrar sesión");
		printf("\nEscoja una opción(1-9): ");
		scanf(" %c", &opcionLogin);
		
		switch(opcionLogin){
		case '1':
			system("cls");
			printf("\tINFORMACION DEL USUARIO\t");
			printf("\nNombre: %s", usuario.nombre);
			printf("\nPais: %s", usuario.pais);
			printf("\nEstado: %s", usuario.estado);
			printf("\nCiudad: %s", usuario.municipio);
			printf("\nDireccion: %s", usuario.direccion);
			printf("\nCodigo Postal: %d", usuario.codigopostal);
			printf("\nTelefono o celular: %ld", usuario.notelefono);
			printf("\nSaldo disponible: $%d MXN", usuario.saldo);
			
			printf("\n\nPulse cualquier tecla para regresar...");
			getch();
		break;
		case '2':
			EditarPerfil();
		break;
		case '3':
			GenerarProducto();
		break;
		case '4':
			system("cls"); //Limpiar pantalla
			
			buscarProducto();
			mostrarProductoContent();
			printf("\n\nIngrese la cantidad que desea agregar: ");
			scanf("%d", &cantagregar);
			incrementarStock(cantagregar);
			
			printf("\nStock agregado exitosamente"); getch();
			
		break;
		case '5':
			buscarProducto();
			editarDatosArchivo(); //Edita el nombre, descripcion, y precio del producto
		break;
		case '6':
			EliminarProducto();
		break;
		case '7':
			GenerarTarjetaPrepago();
		break;
		case '8':
			bandExit = 1;
		break;
		case '9':
			printf("Ha cerrado sesion"); //Limpia los valores
			strcpy(usuario.nombre, "");
			strcpy(usuario.contrasena,"");
			bandExit = 1;
		break;
		default:
			printf("\nOpción no válida");
		break;
		}
		
		system("cls");
	}
}

//Menu en el cual el usuario normal puede realizar ciertas opciones
void OpcionesUsuario(){
	int bandExit = 0; //Bandera que determina la salida de este menu
	
	while(bandExit == 0){
	printf("Hola: %s \t\tTienes disponible $%d MXN", usuario.nombre, usuario.saldo);
	
	printf("\n¿Que desea usted hacer?");
	printf("\n1. Ver mi perfil");
	printf("\n2. Editar información de mi perfil");
	printf("\n3. Ver los productos agregados al carrito");
	printf("\n4. Elminar productos agregados al carrito");
	printf("\n5. Realizar la compra de todos los productos agregados al carrito");
	printf("\n6. Agregar fondos");
	printf("\n7. Eliminar mi perfil");
	printf("\n8. Volver al menu principal");
	printf("\n9. Cerrar sesión");
	printf("\nEscoja una opción(1-9): ");
	scanf(" %c", &opcionLogin);
	
	switch(opcionLogin){
	    case '1':
			system("cls");
			printf("\tINFORMACION DEL USUARIO\t");
			printf("\nNombre: %s", usuario.nombre);
			printf("\nPais: %s", usuario.pais);
			printf("\nEstado: %s", usuario.estado);
			printf("\nCiudad: %s", usuario.municipio);
			printf("\nDireccion: %s", usuario.direccion);
			printf("\nCodigo Postal: %d", usuario.codigopostal);
			printf("\nTelefono o celular: %ld", usuario.notelefono);
			printf("\nSaldo disponible: $%d MXN", usuario.saldo);
			
			printf("\n¿Deseas ver tus movimientos de la cuenta?");
			printf("\n1. Si");
			printf("\n2 u otra tecla. No");
			printf("\nEscoja una opcion (1-2): ");
			scanf(" %c", &opcionLogin);
			
			if(opcionLogin=='1'){
			    system("cls");
				visualizarMovimientos();
			}
			
			printf("\n\nPulse cualquier tecla para regresar...");
			getch();
		break;
	    case '2':
			EditarPerfil();
		break;
		case '3':
		break;
	    case '4':
	    break;
	    case '5':
		break;
		case '6':
			agregarFondos();
		break;
     	case '7':	
			EliminarPerfil();
			strcpy(usuario.nombre, "");
			strcpy(usuario.contrasena,"");
			bandExit = 1;
		break;
	    case '8':
			bandExit = 1;
		break;
	    case '9':
			printf("Ha cerrado sesion"); //Limpia los valores
			strcpy(usuario.nombre, "");
			strcpy(usuario.contrasena,"");
			bandExit = 1;
		break;
	    default:
			printf("\nOpción no válida");
		break;
	}
	
	system("cls");
	
	}
}

//Metodo que revisa si hay un archivo de texto correspondiente para realizar el inicio de sesion
void validar(char nombre[100], char contrasena[100]){
	char direccion[500];
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Usuarios\\");
	strcat(direccion, usuario.nombre);
	strcat(direccion, ".txt");
	
	char nombreArchivo[100];
	
	strcpy(nombreArchivo, usuario.nombre);
	strcat(nombreArchivo, ".txt");
	
	FILE *fd = fopen(direccion,"r"); //r = read text - leer texto
	
	
	char *contrasenaCorrect; //Contrasena para confirmar (se obtendra del archivo de texto)
	char *ptr; //Variable que define el caracter que sera excluido
	char line[100]; //Arreglo que representa la una linea en el archivo de texto que contiene un maximo de hasta 100 caracteres
	contrasenaCorrect = (char*)malloc(100); //Se reserva espacio para la cadena de la contraseña correcta
	
	int contadorLineas = 0;
	
	//Verifica primero que el usuario exista
	if(fd == NULL){
		printf("\nHa ingresado datos incorrectos o su contrasena es incorrecta");
		strcpy(usuario.nombre, ""); //Limpia la cadena que contiene el nombre del usuario
		strcpy(usuario.contrasena,""); //Limpia la cadena que contiene la contraseña del usuario
		getch();
		system("cls");
	}
	//En caso de que exista, verificara si su contraseña ingresada es la correcta
	else {
		while (fgets(line, sizeof(line), fd)) { //Lee el archivo linea por linea hasta llegar a la contraseña
			contadorLineas++;
			if(contadorLineas == 16){ //Verifica que sea la linea donde se encuentra la contraseña
			
				ptr = strtok(line,"\n"); //Se hace una exclusion del salto de linea para descomponer la linea
			
				while(ptr == strtok(NULL, "\n")){
					ptr[strlen(ptr)-1]=0; //Elimina el salto de linea contenido en la linea actual
			    }
				
				strcpy(contrasenaCorrect, line); //Copia el contenido de la linea 16 a la cadena "contrasenaCorrect"
			}
		}
		
		//Verifica que la contraseña ingresada coincida con la contraseña con la contraseña de la cadena obtenida del archivo de texto
		if(strcmp(contrasenaCorrect,contrasena) == 0){
			printf("OK");
			
			int contadorLineas = 0;
			fseek(fd, 0, SEEK_SET); //Reinicializa la búsqueda del archivo de texto línea por línea
			
			//Guarda los datos temporalmente del usuario actual logueado
			while (fgets(line, sizeof(line), fd)) {
				contadorLineas++;
				
				if(contadorLineas == 4){ //Guarda el pais
					ptr = strtok(line,"\n"); //Se hace una exclusion del salto de linea para descomponer la cadena
					
					while(ptr == strtok(NULL, "\n")){
						ptr[strlen(ptr)-1]=0; //Elimina el salto de linea contenido en la cadena
					}
					
					strcpy(usuario.pais,line);
				}
				if(contadorLineas == 6){ //Guarda el estado
					ptr = strtok(line,"\n"); //Se hace una exclusion del salto de linea para descomponer la cadena
					
					while(ptr == strtok(NULL, "\n")){
						ptr[strlen(ptr)-1]=0; //Elimina el salto de linea contenido en la cadena
					}
					
					strcpy(usuario.estado,line);
				}
				if(contadorLineas == 8){ //Guarda el municipio o ciudad
					ptr = strtok(line,"\n"); //Se hace una exclusion del salto de linea para descomponer la cadena
					
					while(ptr == strtok(NULL, "\n")){
						ptr[strlen(ptr)-1]=0; //Elimina el salto de linea contenido en la cadena
					}
					
					strcpy(usuario.municipio,line);
				}
				if(contadorLineas == 10){ //Guarda la direccion del usuario
					ptr = strtok(line,"\n"); //Se hace una exclusion del salto de linea para descomponer la cadena
					
					while(ptr == strtok(NULL, "\n")){
						ptr[strlen(ptr)-1]=0; //Elimina el salto de linea contenido en la cadena
					}
					
					strcpy(usuario.direccion,line);
				}
				if(contadorLineas == 12){ //Guarda el codigo postal
					char *codigoPost; //Se crea un marcador tipo string para el codigo postal
					codigoPost = (char*)malloc(50); //Se reserva espacio para el codigo postal
					
					sprintf(codigoPost, "%d", usuario.codigopostal); //Copia el contenido del valor entero del cp del usuario al string "codigoPost"
					ptr = strtok(codigoPost,"\n"); //Se hace una exclusion del salto de linea para descomponer la cadena
	                				
					strcpy(codigoPost,line); //Copia el contenido de la linea a codigoPost
					
					while(ptr == strtok(NULL, "\n")){
						ptr[strlen(ptr)-1]=0; //Elimina el salto de linea contenido en la cadena "codigoPost"
					}
					
					sscanf(codigoPost, "%d", &usuario.codigopostal); //Copia el contenido del string al valor entero del cp del usuario
					
					free(codigoPost); //Libera memoria
					//NOTA: Mismo problema con el telefono
				}
				if(contadorLineas == 14){ //Guarda el numero de telefono
					ptr = strtok(line,"\n"); //Se hace una exclusion del salto de linea para descomponer la cadena
					
					while(ptr == strtok(NULL, "\n")){
						ptr[strlen(ptr)-1]=0; //Elimina el salto de linea contenido en la cadena
					}
					
					sscanf(line, "%ld", &usuario.notelefono); //Copia el contenido de la linea al numero del telefono del usuario
				}
				if(contadorLineas == 18){ //Guarda el saldo disponible del usuario logueado
					ptr = strtok(line,"\n"); //Se hace una exclusion del salto de linea para descomponer la cadena
					
					while(ptr == strtok(NULL, "\n")){
						ptr[strlen(ptr)-1]=0; //Elimina el salto de linea contenido en la cadena
					}
					
					sscanf(line, "%d", &usuario.saldo); //Copia el contenido de la linea al saldo del usuario
				}
				if(contadorLineas == 20){ //Guarda tipo del usuario logueado
					ptr = strtok(line,"\n"); //Se hace una exclusion del salto de linea para descomponer la cadena
					
					while(ptr == strtok(NULL, "\n")){
						ptr[strlen(ptr)-1]=0; //Elimina el salto de linea contenido en la cadena
					}
					
					sscanf(line, "%c", &usuario.perfil); //Copia el contenido de la linea al perfil del usuario
				}
			}
			
			system("cls");
		}
		else{
			printf("\nHa ingresado datos incorrectos o su contrasena es incorrecta");
			strcpy(usuario.nombre, ""); //Limpia la cadena que contiene el nombre del usuario
			strcpy(usuario.contrasena,""); //Limpia la cadena que contiene la contraseña del usuario
			getch();
		}
	}
	
	fclose(fd);
	free(contrasenaCorrect); //Se libera espacio de la cadena "contrasenaCorrect" cuando termine su uso
}

//Metodo que genera un archivo de texto donde contendra todos los datos del usuario registrado.
void generarUsuario(struct Usuario us){
	char direccion[100];
	strcpy(direccion, "C:\\Cliente\\ProyectoFinal\\Usuarios\\");
	strcat(direccion, usuario.nombre);
	strcat(direccion, ".txt");
	
	printf("\nGenerando el archivo... \n");

	FILE *fd = fopen(direccion,"wt"); //wt = write text - escribir texto
	
	if(fd == NULL){
		printf("\nError: Ocurrió un problema al generar el archivo");
	}
	
	//Escribe los datos en el archivo
	fprintf(fd,"NOMBRE:\n");
	fwrite(usuario.nombre,1,strlen(usuario.nombre),fd);
	fprintf(fd,"\nPAIS:\n");
	fwrite(usuario.pais,1,strlen(usuario.pais),fd);
	fprintf(fd,"\nESTADO:\n");
	fwrite(usuario.estado,1,strlen(usuario.estado),fd);
	fprintf(fd,"\nMUNICIPIO O CIUDAD:\n");
	fwrite(usuario.municipio,1,strlen(usuario.municipio),fd);
	fprintf(fd,"\nDIRECCION:\n");
	fwrite(usuario.direccion,1,strlen(usuario.direccion),fd);
	fprintf(fd,"\nCODIGO POSTAL:\n");	
	fprintf(fd,"%d", usuario.codigopostal);
	fprintf(fd,"\nNUMERO DE TELEFONO:\n");
	fprintf(fd,"%ld", usuario.notelefono);
	fprintf(fd,"\nCONTRASENA:\n");
	fwrite(usuario.contrasena,1,strlen(usuario.contrasena),fd);
	
	usuario.saldo = 0; //Incializa su saldo base
	fprintf(fd,"\nSALDO DISPONIBLE:\n");
	fprintf(fd,"%d", usuario.saldo);
	
	usuario.perfil = 'N'; //Se determina el tipo de usuario "N" significa usuario normal
	fprintf(fd,"\nTIPO:\n");
	fprintf(fd,"%c",usuario.perfil);
	
	fclose(fd); //Cierra el proceso del archivo de texto
}

//Metodo en el cual un usuario crea una nueva cuenta
void CrearUsuario(){
	int flag = 0; //Bandera de validacion de contraseñas
	int flag2 = 0; //Bandera de confirmacion de datos
	
	while(flag2==0){
	printf("Registrese para aprovechar los beneficios y promociones que ofrece the \notakugamer zone\n");
	
	printf("Nota: Los espacios deben ser ingresados separados por guión bajo (_)\n\n");
	
	fflush(stdin); //Limpiar el buffer
	printf("Ingrese su nombre de usuario: ");
	scanf("%s", usuario.nombre);
	printf("Ingrese el pais donde usted vive: ");
	scanf("%s", usuario.pais);
	printf("Ingresar el estado donde usted vive: ");
	scanf("%s", usuario.estado);
	fflush(stdin); //Limpiar el buffer
	printf("Ingrese el municipio o ciudad donde vive: ");
	scanf("%s", usuario.municipio);
	printf("Ingrese su dirección: ");
	scanf("%s", usuario.direccion);
	printf("Número de teléfono o celular: ");
	scanf("%ld", &usuario.notelefono);
	fflush(stdin); //Limpiar el buffer
	printf("Código postal: ");
	scanf("%d", &usuario.codigopostal);
	while(flag==0){
	printf("Contraseña: ");
	scanf("%s", usuario.contrasena);
	printf("Verficar contraseña: ");
	scanf("%s", vercontrasena);
		if(strcmp(usuario.contrasena,vercontrasena)==0){ //Comprueba que ambas contrasenas coincidan
			flag = 1;
		}
		else{
			printf("\nLas contraseñas no coinciden.\n");
		}
	}
	
	printf("¿Son estos datos que ingresó correctos?"); //Verifica si deseas crear esa cuenta con los datos correspondientes
	printf("\n1. Si");
	printf("\n2 o cualquier tecla. No");
	printf("\nEscoja una opcion (1-2): ");
	scanf(" %c", &opcionLogin);
		if(opcionLogin=='1'){
			flag2 = 1;
			generarUsuario(usuario); //Llama a esta funcion que genera el archivo de texto
	    }
		else{
			system("cls"); //Limpia consola
		}
	
	} //Termina while de confirmacion de datos
}

//Metodo que hace que el usuario inicie una sesion
void Login(){
	int flag = 0; //Bandera que indica cuando el ciclo de aparicion de este menu finaliza
	
	while(flag==0){
	//Aparece un menu que indica si quieres iniciar sesion o crear una nueva cuenta
	printf("¿Eres un usuario existente o nuevo?\n");
	printf("1. Existente, iniciar sesión\n");
	printf("2. Soy nuevo, crear una nueva cuenta\n");
	printf("3. Regresar al menu principal\n");
	printf("Escoja una opción (1-3): ");
	scanf(" %c", &opcionLogin);
	
	if(opcionLogin=='1'){
		system("cls"); //Limpiar pantalla
		printf("Ingrese sus datos\n");
	
    	printf("Nombre o usuario: ");
    	scanf("%s", usuario.nombre);
    	printf("Contraseña: ");
    	scanf("%s", usuario.contrasena);
		
		validar(usuario.nombre, usuario.contrasena); //Llama a la funcion que valida la entrada del usuario
		
		flag = 1;
	}
	else if(opcionLogin=='2'){
		system("cls"); //Limpiar pantalla
		CrearUsuario();
		flag = 1;
	}
	else if(opcionLogin=='3'){
		flag = 1;
		system("cls");
	}
	else{
		printf("Opción no válida");
		getch();
		system("cls");
	}
    }
}
