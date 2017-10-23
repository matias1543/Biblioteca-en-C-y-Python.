#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#include"libreria.h"
#include"listar.h"
#include"archivos.h"


//En este archivo solo se encuentra el menu principal, con los respectivos loops y las llamadas a todas las funciones
//se utilizo esto para esconder el funcionamiento interno de la biblioteca


main()
{
	Libro lib;
	Biblioteca b;
	Autores autores;
	crearArchivos();
	vaciarAutores(&autores);
	vaciarBiblio(&b);
	lectura(&b);
	int accion;
	printf("Bienvenidos a la biblioteca.\n");
	do{
		do{
			int i;
			printf("Que accion desea realizar? \n");
			printf("[1]Alta libro\n");
			printf("[2]Baja libro\n");
			printf("[3]Consultar libro\n");
			printf("[4]Modificar libro\n");
			printf("[5]Listar biblioteca por...\n");
			printf("[6]Salir.\n");
			fflush(stdin);
			scanf("%d", &accion);
			fflush(stdin);
			switch(accion){
				case 1:
					if(hayLugar(b)==0){
					ingresarLibro(&lib);
					guardarLibro(lib, &b);
					}
					else{
						printf("La libreria esta llena, no se puede ingresar ningun libro.");
					}
					break;
				case 2:
					listarxTitulo(b);
					borrarLibro(&b);
					break;
				case 3:
					buscarLibro(b);
					break;
				case 4:
					listarxTitulo(b);
					editarLibro(&b,&lib);
					break;
				case 5:
					char listar;
					printf("----------------------------------------------------------------------------------\n");
					printf("[1]Listar todos los autores.\n");
					printf("[2]Listar todos los libros.\n");
					printf("[3]Listar todos los libros de un determinado genero.\n");
					printf("[4]Listar libros de un determinado autor.\n");
					printf("[5]Listar libros de una determinada editorial.\n");
					printf("[6]Listar libros de determinada editorial en rango de años.\n");
					printf("[7]Listar autores de determinada editorial.\n");
					printf("[8]Listar libros editados en determinado año\n");
					printf("[9]Listar libros cuyo autor comience con la letra...\n");
					printf("[0]Listar todos los libros cuyos titulos contentan determinada palabra...\n");
					printf("----------------------------------------------------------------------------------\n");
					fflush(stdin);
					scanf("%d", &listar);
					fflush(stdin);
					enum {  ListarTituloxPalabra = 0, ListarAutores, ListarTodo, ListarGenero, ListarLibrosAutor,
					 ListarDeterminadaEdit, ListarxEdityAnio, ListarAutoresdeEditorial, ListarLibrosdeAnio, ListarLibroxLetraAutor };
					switch(listar){
						case ListarAutores:
							listarAutores(b, &autores);
							break;
						case ListarTodo:
							listarxTitulo(b);
							break;
						case ListarGenero:
							listarxGenero(b);
							break;
						case ListarLibrosAutor:
							listarxAutor(b);
							break;
						case ListarDeterminadaEdit:
							listarxEditorial(b);
							break;
						case ListarxEdityAnio:
							listarxEditorialyAnio(b);
							break;
						case ListarAutoresdeEditorial:
							ListarxAutordeEditorial(b);
							break;
						case ListarLibrosdeAnio:
							listarxAnio(b);
							break;
						case ListarLibroxLetraAutor:
							listarxLetraAutor(b);
							break;
						case ListarTituloxPalabra:
							ListarxPalabra(b);
							break;
					}
				case 6:
					break;
			}
			fflush(stdin);
		}while( accion>6 || accion<1 );
	}while(accion != 6);
	grabarBiblioteca(b);
	printf("Gracias por utilizar nuestros servicios.");
	getch();
}
