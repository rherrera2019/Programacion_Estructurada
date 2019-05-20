//Librerias usadas
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "encrypt.h" //requisito funcional 15

#include <dirent.h>

//definicion del codigo ASCII de ciertas teclas
#define UP 72
#define DOWN 80
#define BLOCK 219
#define ENTER 13
#define ESC 27

//definicion del codigo ASCII de ciertos caracteres
#define ESQUINA_SD 187
#define ESQUINA_SI 201
#define ESQUINA_ID 188
#define ESQUINA_II 200
#define HORIZONTAL 205
#define VERTICAL 186

//PANTALLA
//X maxima = 120
//Y maxima = 30

//FUNCIONES generales
void titulo();
void posicion_cursor(int extensionString, int y);
void color(char color);
void esconder_cursor();
int verificar_archivo(char *rutaDelArchivo);
void imprimir_recuadro(int xInicial, int yInicial, int xFinal, int yFinal);

//FUNCIONES menu principal --- Requisito funcional 10-14
void imprimir_menu_principal(int opcionSeleccionada);
void ejecutar_opcion_menu_principal(int opcion);
void crear_pin();
void verificar_pin(int statusPin);
int iniciar_sesion();
int cambiar_pin();
int recuperar_pin();

//FUNCIONES MENU ABC ---  Requisitos funcionales 1-9
int menu_abc();
void imprimir_menu_abc(int opcionSeleccionada);
void ejecutar_opcion_menu_abc(int opcionSeleccionada);
void contacto_opciones(int contactoSeleccionado, char *comando);
void editar_contactos();
int seleccionar_contacto(int totalContactos);
void imprimir_contactos(int contactoSeleccionado, int contactosTotal);
int contactos_totales();
void eliminar_contacto();

//Variables globales
int salida=0, salidaABC=0, existePin, totalOpcMenuPrin;

//Funcion main
//Es la que lleva el proceso del todo el programa
int main(void)
{
    int opcion, statusPin;

    do{
        esconder_cursor();
        //Se verifica que ya haya un pin generado
        statusPin = verificar_archivo("pin.txt");
        verificar_pin(statusPin);
        //Se imprimen las opciones del menu principal
        opcion = menu_principal_opciones();
        //Se ejecuta la opcion seleccionada
        ejecutar_opcion_menu_principal(opcion);
    }
    while(salida!=1);
    return 0;
}

//Funcion que checa es estatus general del pin del usuario, y si existe, cambiara la cantidad de opciones que mostrara el menu principal
//ENTRADA:
//@statusPin: el estado en el que se encuentra el archivo de texto del pin
void verificar_pin(int statusPin){
     if(statusPin != 2){
        totalOpcMenuPrin=1;
        existePin=0;
    }
    else{
        totalOpcMenuPrin=3;
        existePin=1;
    }
}

//Funcion que ejecuta la opcion seleccionada en el menu de Altas Bajas y Cambios
//ENTRADA:
//@opcionSeleccionada: el numero de la opcion del menu ABC
void ejecutar_opcion_menu_abc(int opcionSeleccionada){
    if(opcionSeleccionada == 0){
        contacto_opciones(0, "nuevo");
    }
    else if(opcionSeleccionada == 1){
        editar_contactos();
    }
    else if(opcionSeleccionada == 2){
        eliminar_contacto();
    }
    else if(opcionSeleccionada == 3){
        if(verificar_archivo("contactos.txt") !=2){ //se verifica el estado del archivo "contactos.txt"
            system("cls");
            color(4);
            posicion_cursor(x_centrada(32), 6); printf("No hay contactos registrados aun");
            posicion_cursor(x_centrada(38), 7); printf("Pulsa cualquier tecla para regresar...");
            getch();
        }
        else{
            seleccionar_contacto(contactos_totales()); //en caso de que existan contactos, se imprimiran y seleccionaran, pero sin hacer algun cambio
        }
    }
    else if(opcionSeleccionada == 4){
        salidaABC=1;
    }
}


//Funcion que retorna la cantidad de contactos registrados por el usuario en el archivo "contactos.txt"
//SALIDA:
//@totalContactos: numero de contactos registrados
int contactos_totales(){
    FILE *contactos;
    char line[1024];
    int totalContactos=0; 
    system("cls");
    contactos = fopen("contactos.txt", "r");
    while(fgets(line, 1024, contactos) != NULL){
        //se van contando las lineas que hay en el archivo (linea = contacto)
        totalContactos++;
    }
    fclose(contactos);

    return totalContactos;
}

//Funcion que elimina el contacto seleccionado del menu de contactos
void eliminar_contacto(){
    int totalContactos, contacto;
    if(verificar_archivo("contactos.txt") != 2){ //se verefica el estado del archivo "contactos.txt"
        system("cls");
        color(4);
        posicion_cursor(x_centrada(32), 6); printf("No hay contactos registrados aun");
        posicion_cursor(x_centrada(38), 7); printf("Pulsa cualquier tecla para regresar...");
        getch();
    }
    else{ //en caso de que existan los contactos, se imprimiran, creando un menu de los contactos registrados
        totalContactos = contactos_totales();
        contacto = seleccionar_contacto(totalContactos);
        if(contacto != -1){//Si el retorno no fue ESC, se elimina el respectivo contacto, sino, solo se sale del menu de contactos
            contacto_opciones(contacto, "eliminar");
        }
    }
}

//Funcion que selecciona un contacto y permite editarlo por completo
void editar_contactos(){
    int contacto, totalContactos;
    if(verificar_archivo("contactos.txt") != 2){ //verifica el estado del archivo "contactos.txt"
        system("cls");
        color(4);
        posicion_cursor(x_centrada(32), 6); printf("No hay contactos registrados aun");
        posicion_cursor(x_centrada(38), 7); printf("Pulsa cualquier tecla para regresar...");
        getch();
    }
    else{ //si hay contactos, se imprimen creando un menu de los contactos
        totalContactos = contactos_totales();
        contacto = seleccionar_contacto(totalContactos);
        if(contacto != -1){//si el retorno no fue ESC, se le permitira a el usuario editar el contenido de su contacto
            contacto_opciones(contacto, "editar");
        }
    }
} 

//Funcion que funciona como menu de los contactos registrados, si se selecciona con ENTER, su posicion se pasara como retorno de la funcion, si se usa ESC, dara una posicion inexistente
//ENTRADA: 
//@totalContactos: numero del total de contactos registrados
//SALIDA:
//@posOpcionContacto: la posicion del de donde se haya quedado el contador, solo se retorna si la salida fue con ENTER
int seleccionar_contacto(int totalContactos){
    int posOpcionContacto=0, key=0;
    do{
        system("cls");
        imprimir_contactos(posOpcionContacto, totalContactos);
        posicion_cursor(5, posOpcionContacto*8);
        key = getch();
        switch (key){
            case UP:
                if(posOpcionContacto==0){
                    posOpcionContacto=totalContactos-1;
                }
                else{
                    posOpcionContacto--;
                }
                break;
            case DOWN:
                if(posOpcionContacto==totalContactos-1){
                    posOpcionContacto=0;
                }
                else{
                    posOpcionContacto++;
                }
                break;
            case ESC:
                posOpcionContacto = -1;
                break;
        }
    }
    while(key != ENTER && key != ESC);

    return posOpcionContacto;
}

//Funcion que imprime unicamente el menu, el contacto cuya posicion haya sido seleccionada se imprimira de color diferente
//ENTRADA:
//@contactoSeleccionada: la posicion del contacto seleccionado
//@contactosTotal: total de contactos registrados
void imprimir_contactos(int contactoSeleccionado, int contactosTotal){
    int i, j, datoCont, ajuste=0, tronoLong=0;
    //struct que almacenara todos los contactos
    struct contacto{
        char nombre[128];
        char tel[15];
        char correo[128];
        char direccion[256];
    }
    contactos[contactosTotal];

    char line[2048], dataEncrypted[256], dataDecrypted[256];
    char *ptr, *rest; 

    FILE *contactosArchivo;
    j=0;
    contactosArchivo = fopen("contactos.txt", "r");
    while(fgets(line, 2048, contactosArchivo) != NULL){ //funcion que obtendra, linea por linea, los contactos siendo linea = info del contacto, unicamente separado por ;
        line[strlen(line)-1] = '\0';
        rest = line;
        datoCont = 1;

		while ((ptr = strtok_r(rest, ";", &rest))){//strok_r dividira la linea obtenida para obtener cada dato del contacto
            strcpy(dataEncrypted, ptr);

            decrypt(dataEncrypted, dataDecrypted);
            //se buscara el dato de entre todos los contactos para saber cual sera el tamaño final de los tarjetas a imprimir
            if(strlen(dataDecrypted) > tronoLong){
                tronoLong = strlen(dataDecrypted);
            }
            //dependiendo de cual sea el dato, se asignara en su respectiva posicion del struct
            switch(datoCont){
                case 1:
                    strcpy(contactos[j].nombre,dataDecrypted);
                    datoCont++;
                    break;
                case 2:
                    strcpy(contactos[j].tel,dataDecrypted);
                    datoCont++;
                    break;
                case 3:
                    strcpy(contactos[j].correo,dataDecrypted);
                    datoCont++;
                    break;
                case 4:
                    strcpy(contactos[j].direccion,dataDecrypted);
                    datoCont++;
                    break;
            }
		}
        j++;
    }

    fclose(contactosArchivo);
    //se iteraran todos los contactos del struc para ser impresos 
    for (i = 0; i < contactosTotal; i++) {
        //si el contador coincide con el contacto seleccionado, se imprimira de otro color
        if(i == contactoSeleccionado){
            color(13);
        }
        else{
            color(7);
        }
        //se imprimira un recuadro del contacto con el respectivo tamaño encontrado
        imprimir_recuadro(x_centrada(tronoLong+4), i+ajuste, x_centrada(tronoLong+4)+tronoLong+3, i+ajuste+7);
        //cada dato se imprimira dentro del recuadro, para esto, se posiciona el puntero donde se necesite, y usando el ajuste para que vaya cambiando de posicion
        posicion_cursor(x_centrada( strlen(contactos[i].nombre)    ), i+ajuste+2); printf("%s", contactos[i].nombre);
        posicion_cursor(x_centrada( strlen(contactos[i].tel)       ), i+ajuste+3); printf("%s", contactos[i].tel);
        posicion_cursor(x_centrada( strlen(contactos[i].correo)    ), i+ajuste+4); printf("%s", contactos[i].correo);
        posicion_cursor(x_centrada( strlen(contactos[i].direccion) ), i+ajuste+5); printf("%s", contactos[i].direccion);
        ajuste += 8;
    }
}

//Funcion que editara, eliminara o creara un contacto
//ENTRADA:
//@contactoSeleccionado: la posicion del contacto seleccionado
//@comando: que hara con el contacto (editar, eliminar, crear)
void contacto_opciones(int contactoSeleccionado, char *comando){
    char stringEncrypted[512], string[2048], line[1024];
    FILE *contactos;
    //struct del contacto
    struct informacion{
        char nombre[128];
        char tel[15];
        char correo[128];
        char direccion[256];
    }contacto;
    int contContactos;
    system("cls");
    //verifica el estado del contacto, para que el archivo sea creado o solo editado
    if(verificar_archivo("contactos.txt") != 2){
        contactos = fopen("contactos.txt", "a+");
    }
    else{
        contactos = fopen("contactos.txt", "a");
    }
    fclose(contactos);
    //Checa cual es el comando
    if(strcmp(comando, "eliminar") != 0){//Si la opcion NO fue eliminar...
        //Ya que las otras 2 opciones requeriran si o si la informacion del contacto, se preguntaran de una vez
        int y=4;
        contContactos=0;
        string[0]='\0';
        color(3);
        posicion_cursor(4, y); printf("Nombre: ");
        color(7);
        gets(contacto.nombre);
        encrypt(contacto.nombre, stringEncrypted);
        strcat(string, stringEncrypted);
        strcat(string, ";");

        color(3);
        posicion_cursor(4, y+2); printf("Telefono: ");
        color(7);
        gets(contacto.tel);
        encrypt(contacto.tel, stringEncrypted);
        strcat(string, stringEncrypted);
        strcat(string, ";");

        color(3);
        posicion_cursor(4, y+4); printf("Correo: ");
        color(7);
        gets(contacto.correo);
        encrypt(contacto.correo, stringEncrypted);
        strcat(string, stringEncrypted);
        strcat(string, ";");

        color(3);
        posicion_cursor(4, y+6); printf("Direccion: ");
        color(7);
        gets(contacto.direccion);
        encrypt(contacto.direccion, stringEncrypted);
        strcat(string, stringEncrypted);
        strcat(string, "\n");
        if(strcmp(comando, "editar") == 0){//si la opcion fue editar...
            FILE *temp;
            temp = fopen("temp.txt", "w+"); //se creara un archivo temporal
            contactos = fopen("contactos.txt", "r");
            while(fgets(line, 1024, (FILE*) contactos) ){
                // si el contacto a editar coincide con nuestro contador lo que se escribira en nuestro archivo temporal sera lo que se obtuvo de fgets
                if (contContactos == contactoSeleccionado) {
                    fputs(string, temp);
                }
                //en caso de que no, simplemente pasara la linea en la que se encuentra al archivo temporal
                else{
                    fputs(line, temp);
                }
                contContactos++;
            }
            fflush(temp);
            fclose(contactos);
            fclose(temp);
            remove("contactos.txt");
            rename("temp.txt", "contactos.txt");
        }
        else{//en caso de que haya sido crear, simplemente se agregara la informacion del contacto guardado en el string al archivo de los contactos
            contactos = fopen("contactos.txt", "a");
            fputs(string, contactos);
            fclose(contactos);
        }
    }
    else{ // si la opcion fue eliminar...
        FILE *temp;
        contContactos=0;
        temp = fopen("temp.txt", "w+"); //se creara un archivo temporal
        contactos = fopen("contactos.txt", "r");
        while(fgets(line, 1024, (FILE*) contactos) ){
            // si el contacto a eliminar coincide con el contacto que se esta leyendo, no se agrega al archivo temporal
            if (contContactos != contactoSeleccionado) {
                fputs(line, temp);
            }
            contContactos++;
        }
        fflush(temp);
        fclose(contactos);
        fclose(temp);
        remove("contactos.txt"); //el archivo temporal sera la nueva lista y se eliminara la antigua
        rename("temp.txt", "contactos.txt"); 
    }
}

//Imprime las opciones disponibles dentro del menu de Altas Bajas y Cambios, si la opcion esta seleccionada, se imprimira de un color diferente
void imprimir_menu_abc(int opcionSeleccionada){
    if(opcionSeleccionada == 0){color(13);} else{color(7);}
    imprimir_recuadro(x_centrada(28), 3, x_centrada(28)+27,5);
    posicion_cursor(x_centrada(17),4);
    printf("Agregar contactos");
    if(opcionSeleccionada == 1){color(13);} else{color(7);}
    imprimir_recuadro(x_centrada(28), 7, x_centrada(28)+27,9);
    posicion_cursor(x_centrada(18),8);
    printf("Editar un contacto");
    if(opcionSeleccionada == 2){color(13);} else{color(7);} 
    imprimir_recuadro(x_centrada(28), 11, x_centrada(28)+27,13);
    posicion_cursor(x_centrada(20),12);
    printf("Eliminar un contacto");
    if(opcionSeleccionada == 3){color(13);} else{color(7);} 
    imprimir_recuadro(x_centrada(28), 15, x_centrada(28)+27,17);
    posicion_cursor(x_centrada(23),16);
    printf("Ver todos los contactos");
    if(opcionSeleccionada == 4){color(13);} else{color(7);} 
    imprimir_recuadro(x_centrada(28), 19, x_centrada(28)+27,21);
    posicion_cursor(x_centrada(26),20);
    printf("Regresar al menu principal");
}

//Funcion que itera, mediante el teclado, la opcion seleccionada en el menu de Altas Bajas y Cambios
//@SALIDA: Si se aprieta la tecla ENTER, el ciclo se rompe y la funcion devolvera la opcion seleccionada del menu de ABC
int menu_abc(){
    int posOpcionABC=0, key=0;
    do{
        system("cls");
        imprimir_menu_abc(posOpcionABC);
        key = getch();
        switch (key){
            case UP:
                if(posOpcionABC==0){
                    posOpcionABC=4;
                }
                else{
                    posOpcionABC--;
                }
                break;
            case DOWN:
                if(posOpcionABC==4){
                    posOpcionABC=0;
                }
                else{
                    posOpcionABC++;
                }
                break;
        }
    }
    while(key != ENTER);

    return posOpcionABC;
}

//Funcion que imprime las opciones del menu principal y las itera dependiendo de la tecla que se presione, asi como ejecutar la opcion seleccionada cuando se presione ENTER
int menu_principal_opciones(){
    int posOpcionPrincipal=0, key=0;
   
    do{
        system("cls");
        titulo();
        imprimir_menu_principal(posOpcionPrincipal);
        key = getch();
        switch (key){
            case UP:
                if(posOpcionPrincipal==0){
                    posOpcionPrincipal=totalOpcMenuPrin;
                }
                else{
                    posOpcionPrincipal--;
                }
                break;
            case DOWN:
                if(posOpcionPrincipal==totalOpcMenuPrin){
                    posOpcionPrincipal=0;
                }
                else{
                    posOpcionPrincipal++;
                }
                break;
        }
    }
    while(key != ENTER);

    return posOpcionPrincipal;
}
//Funcion que imprime el titulo del programa
void titulo(){
    color(6);
    posicion_cursor(x_centrada(66),1);
    printf("   __    __        ___   ___    __  _____  _      ___  _____  ___ ");
    posicion_cursor(x_centrada(66),2);
    printf("  /__\\/\\ \\ \\      / __\\ /___\\/\\ \\ \\/__   \\/_\\    / __\\/__   \\/___\\");
    posicion_cursor(x_centrada(66),3);
    printf(" /_\\ /  \\/ /____ / /   //  //  \\/ /  / /\\//_\\\\  / /     / /\\//  //");
    posicion_cursor(x_centrada(66),4);
    printf("//__/ /\\  /_____/ /___/ \\_// /\\  /  / / /  _  \\/ /___  / / / \\_// ");
    posicion_cursor(x_centrada(66),5);
    printf("\\__/\\_\\ \\/      \\____/\\___/\\_\\ \\/   \\/  \\_/ \\_/\\____/  \\/  \\___/  ");
}
//Funcion que posiciona el cursor de la ventana de comandos para imprimir lo que se quiera
//ENTRADA:
//@extensionString: la longitud del string que se quierep posicionar, para que se imprima centrado de manera horizontal
//@y: la coordenada en y de la ventana de comandos
void posicion_cursor(int x, int y){
	HANDLE manipulador;
	COORD coordenadas;
	manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
	coordenadas.X = x;
	coordenadas.Y = y;
	SetConsoleCursorPosition(manipulador, coordenadas);
}
//Funcion que reposiciona la x inicial de un texto a una centrada respecto a la extension del text que se quiere imprimir despues
//ENTRADA: 
//@extensionString: La cantidad de caracteres que tiene el string
//SALIDA: 
//La posicion de x para que el texto que se imprimira despues sea un centrado
int x_centrada(int extensionString){
    return 59-(extensionString/2);
}
//Funcion que imprime un marco
//ENTRADA:
//@xInicial: la posicion de x donde se empezara a dibujar el marco
//@yInicial: la posicion de y donde se empezara a dibujar el marco
//@xFinal: la posicion de x donde se terminara de dibujar el marco
//@yFinal: la posicion de y donde se terminara de dibujar el marco
void imprimir_recuadro(int xInicial, int yInicial, int xFinal, int yFinal){
    int i;
    posicion_cursor(xInicial, yInicial);
    printf("%c", ESQUINA_SI);

	posicion_cursor(xInicial, yFinal);
    printf("%c", ESQUINA_II);

	posicion_cursor(xFinal, yInicial);
    printf("%c", ESQUINA_SD);

	posicion_cursor(xFinal, yFinal);
    printf("%c", ESQUINA_ID);

    for (i=xInicial+1; i< xFinal; i++){
        posicion_cursor(i, yInicial);
        printf("%c", HORIZONTAL);
    }
    for (i=xInicial+1; i< xFinal; i++){
        posicion_cursor(i, yFinal);
        printf("%c", HORIZONTAL);
    }
    for (i=yInicial+1; i < yFinal; i++){
        posicion_cursor(xInicial, i);
        printf("%c\n", VERTICAL);
    }
    for (i=yInicial+1; i < yFinal; i++){
        posicion_cursor(xFinal, i);
        printf("%c\n", VERTICAL);
    }
}
//Funcion que unicamente imprime las opciones del programa, dependiendo si hay o no hay pin
void imprimir_menu_principal(int opcionSeleccionada){
    //Cambio de color si la opcion esta seleccionada
    int y;
    if(existePin == 1){
        y=20;
        if(opcionSeleccionada == 0){color(13);} else{color(7);}
        imprimir_recuadro(x_centrada(20), 8, x_centrada(20)+19, 10);
        posicion_cursor(x_centrada(14), 9);
        printf("Iniciar sesi%cn", 162);
        //Cambio de color si la opcion esta seleccionada
        if(opcionSeleccionada == totalOpcMenuPrin-2){color(13);} else{color(7);}
        imprimir_recuadro(x_centrada(20), 12, x_centrada(20)+19, 14);
        posicion_cursor(x_centrada(11), 13);
        printf("Cambiar PIN");
        //Cambio de color si la opcion esta seleccionada
        if(opcionSeleccionada == totalOpcMenuPrin-1){color(13);} else{color(7);}
        imprimir_recuadro(x_centrada(20), 16, x_centrada(20)+19, 18);
        posicion_cursor(x_centrada(13), 17);
        printf("Recuperar PIN", 162);
    }
    else{
        y=12;
        if(opcionSeleccionada == 0){color(13);} else{color(7);}
        imprimir_recuadro(x_centrada(20), 8, x_centrada(20)+19, 10);
        posicion_cursor(x_centrada(8), 9);
        printf("Crear PIN");
    }
    //Cambio de color si la opcion esta seleccionada
    if(opcionSeleccionada == totalOpcMenuPrin){color(13);} else{color(7);}
    imprimir_recuadro(x_centrada(20), y, x_centrada(20)+19, y+2);
    posicion_cursor(x_centrada(18), y+1);
    printf("Salir del programa");
}
//Funcion que lee le un pin que ingrese el usuario, en caso de no cumplir con las caracteristicas requeridas, se le pedira de nuevo.
//ENTRADA:
//@opcion: 0 si el PIN es ingresado por primera vez, para generar la pregunta de recuperacion
//           cualquier otro numero indicara que solo se editara el PIN
void crear_pin(int opcion){
    int i, j, error=0;
    char pinUsuario[5], pinEncriptado[1024], aux[1024], pregunta[1024], respuesta[1024], line[2048];
    FILE *pinArchivo, *preguntaArchivo;
    system("cls");
    //Do-While para volver a pedir el pin en caso que no cumpla con la extension pedida
    do{
        error=0;
        color(13);
        posicion_cursor(x_centrada(66), 7); printf("Ingresa PIN con el que vas a proteger tus contactos (de 4 digitos):");
        color(7);
        fflush(stdin);
        imprimir_recuadro(x_centrada(8), 9, x_centrada(8)+7,11);
        posicion_cursor(x_centrada(4), 10);
        gets(pinUsuario);
        if(strlen(pinUsuario) < 4 || strlen(pinUsuario) > 4){
            color(4);
            posicion_cursor(x_centrada(46), 13); printf("El pin debe tener 4 digitos, vuelve a ponerlo!");
            color(7);
            posicion_cursor(x_centrada(49), 14); printf("Pulsa cualquier tecla para intentarlo de nuevo...");
            error=1;
            getch();
        }
        else{
            for(i=0; i<4; i++){
                if(pinUsuario[i] < '0' || pinUsuario[i]>'9'){
                    color(4);
                    posicion_cursor(x_centrada(52),13); printf("El pin debe contener solo numeros, vuelve a ponerlo!");
                    color(7);
                    posicion_cursor(x_centrada(49),14); printf("Pulsa cualquier tecla para intentarlo de nuevo...");
                    error=1;
                    getch();
                    break;
                }
            }
        }
        
        system("cls");
    }
    while (error==1);
    //Funcion para encriptar el pin 
    encrypt(pinUsuario, pinEncriptado);
    //funcion para poner el pin encriptado en el archivo
    pinArchivo = fopen("pin.txt", "w");
    fputs(pinEncriptado, pinArchivo);
    fclose(pinArchivo);

    if(opcion == 0){//en caso de que sea la primera vez que se ingresa PIN, se genera la pregunta de recuperacion
        line[0]='\0';
        system("cls");
        preguntaArchivo = fopen("pregunta.txt", "w+");
        color(3);
        posicion_cursor(4, 7); printf("Ingresa la pregunta de seguridad: ");
        color(7);
        gets(aux);
        encrypt(aux, pregunta);
        strcat(line, pregunta);
        strcat(line, ";");

        color(3);
        posicion_cursor(4, 8); printf("Ingresa su respuesta: ");
        color(7);
        gets(aux);
        encrypt(aux, respuesta);
        strcat(line, respuesta);
        fputs(line, preguntaArchivo);
        system("cls");
        color(2);
        posicion_cursor(x_centrada(42), 7); printf("Pregunta de seguridad ingresada con exito!");
        fclose(preguntaArchivo);
    }
    color(2);
    posicion_cursor(x_centrada(21), 8); printf("PIN Creado con exito!");
    posicion_cursor(x_centrada(56), 10); printf("Pulsa cualquier tecla para regresar al menu principal...");
    getch();
}

//Funcion que recibe la ruta del archivo, y verifica si existe, si tiene informacion o no
//ENTRADA: 
//@rutaDelArchivo: es la ruta del archivo a verificar.
//SALIDA:
//@status: retorna 0 si el archivo no existe.
//         retorna 1 si el archivo existe, pero no tiene informacion.
//         retorna 2 si el archivo existe y tiene informacion dentro.
int verificar_archivo(char *rutaDelArchivo){
    FILE *archivo;
    int status, size;

    archivo = fopen(rutaDelArchivo, "r");
    if (archivo != NULL) {
        fseek (archivo, 0, SEEK_END);
        size = ftell(archivo);
        if (size != 0) {
            status=2;
        }
        else{
            status=1;
        }
    }
    else{
        status = 0;
    }
    fclose(archivo);

    return status;
}


//Funcion que busca el pin ya creado, compara con el que esta ingresando el usuario, y, en caso de ser iguales, se inicia la sesion
//ENTRADA:
//(dentro de la funcion) @pinIngresado: el pin que el usuario da
//SALIDA:
//@sesion: el estatus de la sesion, en caso de que el pin ya creado sea igual al pin que ingreso el usuario, se retorna 1, sino, se retorna 0
int iniciar_sesion(){
    char pinIngresado[5], pinPrograma[100];
    int intentos=4, fallo, i=0, c, sesion;
    FILE *pinArchivo;
    pinArchivo = fopen("pin.txt", "r");
    while (c != EOF){
        c = fgetc(pinArchivo);
        pinPrograma[i] = (char)c;
        i++;
    }
    pinPrograma[i]='\0';
    fclose(pinArchivo);
    do{
        fallo=0;
        system("cls");
        color(13);
        posicion_cursor(x_centrada(15), 7); printf("Ingresa tu PIN:");
        color(7);
        imprimir_recuadro(x_centrada(8), 9, x_centrada(8)+7, 11);
        posicion_cursor(x_centrada(4), 10);
        gets(pinIngresado);
        if(!compare(pinIngresado, pinPrograma)){
            color(4);
            intentos--;
            posicion_cursor(x_centrada(41), 13); printf("El pin es incorrecto! Te quedan %d intentos", intentos);
            fallo=1;
        }
        else{
            color(2);
            posicion_cursor(x_centrada(32), 13); printf("PIN ingresado de manera exitosa!");
        }
        posicion_cursor(x_centrada(39), 14); printf("Pulsa cualquier tecla para continuar...");
        getch();
    }
    while(intentos > 0 && fallo == 1);
    if(intentos == 0){
        posicion_cursor(x_centrada(30), 16); printf("Has fallado todos los intentos");
        sesion=0;
        getch();
    }
    else{
        sesion=1;
    }

    return sesion;
}

//Funcion que permite cambiar el pin conociendolo previamente
//SALIDA: 
//@stop: el estado del programa en general, si se cumple (sea igual a 1), entonces se termina el programa
int cambiar_pin(){
    char pinIngresado[5], pinPrograma[100];
    int intentos=4, fallo, i=0, c, stop;
    FILE *pinArchivo;
    pinArchivo = fopen("pin.txt", "r");
    while (c != EOF){
        c = fgetc(pinArchivo);
        pinPrograma[i] = (char)c;
        i++;
    }
    pinPrograma[i]='\0';
    fclose(pinArchivo);
    do{
        fallo=0;
        system("cls");
        color(13);
        posicion_cursor(x_centrada(24), 7); printf("Ingresa tu PIN anterior:");
        color(7);
        imprimir_recuadro(x_centrada(8), 9, x_centrada(8)+7, 11);
        posicion_cursor(x_centrada(4), 10);
        gets(pinIngresado);
        if(!compare(pinIngresado, pinPrograma)){
            color(4);
            intentos--;
            posicion_cursor(x_centrada(66), 13); printf("El PIN ingresado no coincide con el anterior! Te quedan %d intentos", intentos);
            posicion_cursor(x_centrada(49), 14); printf("Pulsa cualquier tecla para intentarlo de nuevo...");
            getch();
            fallo=1;
        }
        else{
            crear_pin(1);
            fallo=0;
        }
    }
    while(intentos > 0 && fallo == 1);
    if(intentos == 0){
        posicion_cursor(x_centrada(30), 16); printf("Has fallado todos los intentos");
        stop=0;
        getch();
    }
    else{
        stop=1;
    }

    return stop;
}

//Funcion que permite cambiar el pin sin conocerlo previamente
//SALIDA: 
//@stop: el estado del programa en general, si se cumple (sea igual a 1), entonces se termina el programa
int recuperar_pin(){
    char aux[1024], pregunta[1024], respuesta[1024], respUsuario[1024];
    int i=0, c, j=0, stop, intentos=4, fallo = 0;
    FILE *preguntaArchivo;
    preguntaArchivo = fopen("pregunta.txt", "r");
    while (c != EOF){
        c = fgetc(preguntaArchivo);
        aux[i] = (char)c;
        i++;
    }
    aux[i+1]='\0';

    char *ptr, *rest; 
    rest = aux;

	while ((ptr = strtok_r(rest, ";", &rest))){
        if(j==0){
            decrypt(ptr, pregunta);
        }
        else{
            strcpy(respuesta, ptr);
        }
        j++;
    }
    
    do{
        system("cls");
        posicion_cursor(6, 5);
        color(3);
        printf("Pregunta de seguridad -> %s: ", pregunta);
        color(7);
        gets(respUsuario);
        if(compare(respUsuario, respuesta) == 1){
            crear_pin(1);
            fallo = 0;
        }
        else{
            color(4);
            intentos--;
            posicion_cursor(x_centrada(50), 7); printf("La respuesta no es correcta, te quedan %d intentos.", intentos);
            posicion_cursor(x_centrada(49), 7); printf("Pulsa cualquier tecla para continuar...");
        }
    }
    while(intentos > 0 && fallo == 1);
    if(intentos == 0){
        color(4);
        posicion_cursor(x_centrada(30), 16); printf("Has fallado todos los intentos");
        stop=0;
        getch();
    }
    else{
        stop=1;
    }    
}
//Funcion que ejecuta la opcion seleccionada del menu principal, dependiendo si hay o no un pin asignado
//ENTRADA:
//@opcion: es el numero de opcion que se ha seleccionado
void ejecutar_opcion_menu_principal(int opcion){
    int sesion = 0, opcionABC, error; 
    if(existePin != 1){
        if(opcion == 0){
            crear_pin(0);
        }
        else if (opcion == totalOpcMenuPrin){
            salida=1;
        }
    }
    else{
        if(opcion == 0){
            sesion = iniciar_sesion();
            if(sesion != 0){
                do{
                    system("cls");
                    opcionABC = menu_abc();
                    ejecutar_opcion_menu_abc(opcionABC);
                }
                while(salidaABC!=1);
            }
            else{
                exit(0);
            }
        }
        else if(opcion == totalOpcMenuPrin-2){
            error = cambiar_pin();
            if(error == 0){
                salida=1;
            }
            else{
                salida=0;
            }
        }
        else if(opcion == totalOpcMenuPrin-1){
            recuperar_pin();
        }
        else if (opcion == totalOpcMenuPrin){
            salida=1;
        }
    }
    
}

//Funcion para esconder el puntero del cursor (donde se esta escribiendo el texto)
void esconder_cursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
//funcion para cambiar de color el texto
//ENTRADA:
//@color: es el codigo del color que se quiere

/*
0	black
1	blue
2	green
3	cyan
4	red
5	magenta
6	yellow/brown
7	white
8	gray
9	bright blue
10	bright green
11	bright cyan
12	bright red
13	bright magenta
14	bright yellow
15	white

*/

void color(char color){
	HANDLE cambioDeColor;
	cambioDeColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cambioDeColor, color);
}