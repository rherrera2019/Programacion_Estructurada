#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ValidarUsuario.c"


void Detalles(){
	printf("\n\n Productos destacados:");
	
	printf("\n\tConsola PS4 pro 1TB $5999");
	printf("\n\tNintendo Switch edicion SMASH BROS ultimate $7499");
	printf("\n\tNSW Super Smash Bros Ultimate $999");
	printf("\n\tNSW Super Mario Odyssey $999");
	printf("\n\tPS4 Jump Force $899");
	printf("\n\tPS4 Dragon Ball Fighter Z $899");
	printf("\n\tNSW Dragon Ball Fighter Z $999");
	printf("\n\tManga Panini Your Name Vol.3 $99");
	printf("\n\tManga Panini Koe no katachi Vol.1 $99");
	printf("\n\tTarjeta microSD kingston 16GB $120");

}

//Método que se encarga de imprimir la pagina principal y su contenido
void imprimirMenu(){
	
	time_t tiempo = time(0);
	struct tm * tlocal = localtime(&tiempo);
	char output[128];
	strftime(output, 128, "%d/%m/20%y", tlocal);
	printf("\r¿Que desea hacer?\t\t\t\t\tHoy es: %s\n",output);
	
	color(8);
	printf("1. Gadgets  ");
	
	color(2);
	printf("2. VideoJuegos  ");
	
	color(3);
	printf("3. Anime  ");
	
	color(4);
	printf("4. Manga  ");
	
	color(5);
	printf("5. Accesorios ");

	color(6);
	printf("6. Coleccionables ");
	
	color(7);
	/*Estas opciones apareceran dependiendo si existe un usuario loguedado 
	actualmente o no*/
	if(strlen(usuario.nombre) == 0 && strlen(usuario.contrasena) == 0){
	printf("7.Buscar un producto\t\t\t\t\t    8. Iniciar Sesion");
	}
	else{
	printf("7.Buscar un producto\t\t\t13.%c\\!%c%c%c! \t\t8.%s",238,204,206,185,usuario.nombre);
	}
	
	color(14);
	printf("\n                      _        _  _       ___"); //Dibuja la palabra "OTAKUGAMER" en amarillo (1ra linea)
	
	color(12);
	printf("\n___ _  _ ___ "); //Primera linea de la palabra THE
	color(14);
	printf("   ___ _| |_ ____| |//_   _ / _ \\  ____ ____  ____  ___"); //Dibuja la palabra "OTAKUGAMER" en amarillo (2da linea)
	color(10);
	printf("   ______"); //Joystick
	
	color(12);
	printf("\n |  |  | |"); //Segunda linea de la palabra THE
	color(14);
	printf("     / _ \\_   _|___ |  /| | | | |_| ||___ |    \\| __ |/  _)"); //Dibuja la palabra "OTAKUGAMER" en amarillo (3ra linea)
	color(10);
	printf(" (O --::)");
	
	color(12);
	printf("\n |  |--| |--"); //Tercera linea de la palabra THE
	color(14);
	printf("  | |_| || | / __ |  \\| |_| |\\__  |/ __ | | | | ___|| |"); //Dibuja la palabra "OTAKUGAMER" en amarillo (4ta linea)
	color(10);
	printf("    \\+__O/");
	
	color(12);
	printf("\n |  |  | |__"); //Cuarta linea de la palabra THE
	color(14);
	printf("   \\___/ | |_\\____|_|\\\\_____/  _| |\\____|_|_|_|____)|_|"); //Dibuja la palabra "OTAKUGAMER" en amarillo (5ta linea)
	color(10);
	printf("   //    \\\\");
	
	color(14);
	printf("\n                     \\__/                 /___|");  //Dibuja la palabra "OTAKUGAMER" en amarillo (6ta linea)
	color(7);
	printf("\t\t\tZONE");
	
	Detalles();
	
	printf("\n\n\n9.Sobre nosotros\t10.Terminos y condiciones\t11.Contacto\t12.Salir");
	
	printf("\nEscoja una opción(1-12): ");
}
