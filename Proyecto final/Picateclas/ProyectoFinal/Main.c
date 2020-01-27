#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "PaginaInicio.c"//Llamada al archivo PaginaInicio

int opcion;
int marcProducto;

void navegar(){
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1:
			system("cls"); //Limpia consola
			printf("Seleccion de gadgets\n");
			mostrarVariosProductos(1,0);
			printf("\nSeleccione un producto (1-?): ");
			scanf("%d", &marcProducto);
			
			mostrarVariosProductos(1,marcProducto);
			system("cls"); //Limpia pantalla para evitar duplicacion del menu de productos
			mostrarProductoContent();
			
			//Revisa que haya tanto un usuario normal registrado y que el articulo exista
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'N' && strlen(articulo.nombre) != 0){
				OpcionesUsuarioProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'A' && strlen(articulo.nombre) != 0){
				OpcionesAdministradorProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			
			getch();
			system("cls");
     	break;
	    case 2:
			system("cls"); //Limpia consola
			printf("Seleccion de videojuegos\n");
			mostrarVariosProductos(2,0);
			printf("\nSeleccione un producto (1-?): ");
			scanf("%d", &marcProducto);
			
			mostrarVariosProductos(2,marcProducto);
			system("cls"); //Limpia pantalla para evitar duplicacion del menu de productos
			mostrarProductoContent();
			
			//Revisa que haya tanto un usuario normal registrado y que el articulo exista
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'N' && strlen(articulo.nombre) != 0){
				OpcionesUsuarioProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'A' && strlen(articulo.nombre) != 0){
				OpcionesAdministradorProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			
			getch();
			system("cls");
		break;
	    case 3:
			system("cls"); //Limpia consola
			printf("Seleccion de animes\n");
			mostrarVariosProductos(3,0);
			printf("\nSeleccione un producto (1-?): ");
			scanf("%d", &marcProducto);
			
			mostrarVariosProductos(3,marcProducto);
			system("cls"); //Limpia pantalla para evitar duplicacion del menu de productos
			mostrarProductoContent();
			
			//Revisa que haya tanto un usuario normal registrado y que el articulo exista
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'N' && strlen(articulo.nombre) != 0){
				OpcionesUsuarioProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'A' && strlen(articulo.nombre) != 0){
				OpcionesAdministradorProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			
			getch();
			system("cls");
		break;
	    case 4:
			system("cls"); //Limpia consola
			printf("Seleccion de mangas\n");
			mostrarVariosProductos(4,0);
			printf("\nSeleccione un producto (1-?): ");
			scanf("%d", &marcProducto);
			
			mostrarVariosProductos(4,marcProducto);
			system("cls"); //Limpia pantalla para evitar duplicacion del menu de productos
			mostrarProductoContent();
			
			//Revisa que haya tanto un usuario normal registrado y que el articulo exista
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'N' && strlen(articulo.nombre) != 0){
				OpcionesUsuarioProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'A' && strlen(articulo.nombre) != 0){
				OpcionesAdministradorProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			
			getch();
			system("cls");
		break;
	    case 5:
			system("cls"); //Limpia consola
			printf("Seleccion de accesorios\n");
			mostrarVariosProductos(5,0);
			printf("\nSeleccione un producto (1-?): ");
			scanf("%d", &marcProducto);
			
			mostrarVariosProductos(5,marcProducto);
			system("cls"); //Limpia pantalla para evitar duplicacion del menu de productos
			mostrarProductoContent();
			
			//Revisa que haya tanto un usuario normal registrado y que el articulo exista
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'N' && strlen(articulo.nombre) != 0){
				OpcionesUsuarioProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'A' && strlen(articulo.nombre) != 0){
				OpcionesAdministradorProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			
			getch();
			system("cls");
		break;
	    case 6:
			system("cls"); //Limpia consola
			printf("Seleccion de coleccionables\n");
			mostrarVariosProductos(6,0);
			printf("\nSeleccione un producto (1-?): ");
			scanf("%d", &marcProducto);
			
			mostrarVariosProductos(6,marcProducto);
			system("cls"); //Limpia pantalla para evitar duplicacion del menu de productos
			mostrarProductoContent();
			
			//Revisa que haya tanto un usuario normal registrado y que el articulo exista
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'N' && strlen(articulo.nombre) != 0){
				OpcionesUsuarioProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'A' && strlen(articulo.nombre) != 0){
				OpcionesAdministradorProducto(); //Muestra el menu de opciones que hacer con el producto
			}
			
			getch();
			system("cls");
		break;
	    case 7:
			system("cls"); //Limpia consola
			buscarProducto(); //Metodo que realiza la busqueda del producto
			    mostrarProductoContent(); //Muestra el contenido del producto
				
				//Revisa que haya tanto un usuario normal registrado y que el articulo exista
				if(strlen(usuario.nombre) != 0 && strlen(usuario.contrasena) != 0 && usuario.perfil == 'N' && strlen(articulo.nombre) != 0){
				OpcionesUsuarioProducto(); //Muestra el menu de opciones que hacer con el producto
			    }
				
			getch();
			system("cls");
		break;
	    case 8: //La opcion 8 representa el registro o inicio de sesion
			system("cls"); //Limpia consola
			
			//Comprueba si existe un usuario logueado actualemente o no.
			if(strlen(usuario.nombre) == 0 && strlen(usuario.contrasena) == 0){
			Login();
			}
			else{
			   //Comprueba si el tipo de usuario es administrador o usuario normal
			   if(usuario.perfil == 'N'){
			   OpcionesUsuario();
			   }
			   if(usuario.perfil == 'A'){
			   OpcionesAdministrador();
			   }
			   getch();
			}
		break;
	    case 9:
			system("cls"); //Limpia consola
			getch();
		break;
	    case 10:
			system("cls"); //Limpia consola
			getch();
		break;
	    case 11:
			system("cls"); //Limpia consola
			getch();
		break;
	    case 12:
			system("cls"); //Limpia consola
			printf("Gracias por su visita ^_^, esperamos verlo pronto...");
		break;
	    case 13:
			//carrito();
			system("cls");
			
			//Comprueba si existe un usuario logueado actualemente o no.
			if(strlen(usuario.nombre) == 0 && strlen(usuario.contrasena) == 0){
				printf("\nOpción no válida");
			}
			else{
				printf("\nTus productos");
			}
			getch();
		break;		
	    default:
			system("cls"); //Limpia consola
			printf("\nOpción no válida");
			getch();
		break;
	}
}


int main(int argc, char *argv[]) {
	
	while(opcion!=12){
		imprimirMenu(); //Llama al metodo que imprime el menu principal
		navegar();
	}
	
	return 0;
}

