
//estructura donde se ingresan todos los parametrs de cada libro
typedef struct {
    char titulo[60];
    int cantidadAutores;
    char autor[3][60];
    char pag[6];
    char editorial[20];
    char isbn[20];
    char genero[30];
    char year[6];
    }Libro;


//vector que contiene todos los libros, y el contador n que indica la cantidad del mismo y el indice
//que va  adar el orden de salida para que esten ordenados alfabeticamente.
typedef struct{ 
    Libro vec[100];
    int n;
	}Biblioteca;


//datos de los autores y orden para la impresion, el orden ya es un dato dado.
typedef struct{
	char autor[60];
	int orden;
}Aut;



//se crea el vector de autores ademas de un contador para la cantidad y uno para el orden
//orden sera utilizado al momento de la impresion de los autores para que queden en orden alfabetico y sean mas facil poder buscarlos.
typedef struct{
	Aut vec[100];
	int cant;
}Autores;



//funcion que pone la cantidad de autores en 0
void vaciarAutores(Autores *autores){
	autores->cant = 0;
	
}

//funcion que pone la cantidad de libros en 0
void vaciarBiblio(Biblioteca * b){
    b->n = 0;
}


//funcion para el ingreso de los libros, todos los datos se guardan como strings.
void ingresarLibro(Libro *lib){
	int i;
	printf("Ingrese Titulo: ");
	gets(lib->titulo);
	strupr(lib->titulo);
	printf("Ingrese cantidad de autores que tiene el libro: ");
	scanf("%d", &lib->cantidadAutores);
	fflush(stdin);
	for(i = 0; i < lib->cantidadAutores; i++){
		printf("Ingrese Autor N %d:", (i+1));
		gets(lib->autor[i]);
		strupr(lib->autor[i]);
	}
	printf("Cantidad de paginas: ");
	gets(lib->pag);
	printf("Ingrese editorial: ");
	gets(lib->editorial);
	strupr(lib->editorial);
	printf("Ingrese ISBN: ");
	gets(lib->isbn);
	printf("Ingese el genero: ");
	gets(lib->genero);
	strupr(lib->genero);
	printf("Ingrese año: ");
	gets(lib->year);
	fflush(stdin);
}


//funcion que se fija si la biblioteca esta llena
//retorna 0 si hay lugar y 1 si esta llena
int hayLugar(Biblioteca b){
	if(b.n<100)
		return 0;
	else
		return 1;
}


//funcion que imprime todos los parametro de un determinado libro
//se le debe pasar la biblioteca y la posiccion del libro dentro de la misma
void mostrarLibro(Biblioteca b, int i){
	int j;
	printf("*****************************************************************************************************************\n");
	printf("Titulo: %s\n", b.vec[i].titulo);
	for(j=0; j<b.vec[i].cantidadAutores; j++){
		printf("Autor: %s\n", b.vec[i].autor[j]);
	}
	printf("Paginas: %s\nEditorial: %s\nISBN: %s\nGenero: %s\nAño:%s\n", b.vec[i].pag, b.vec[i].editorial, b.vec[i].isbn, b.vec[i].genero, b.vec[i].year);
}



//funcion que guarda el libro dentro de la biblioteca
//revisa al inicio que el titulo no se encuentre yae ne el sistema
//ofrece una revision de los datos ingresados
//si se confirma guarda el mismo en la biblioteca y aumenta el contador "n" de libros que contiene
void guardarLibro(Libro lib,  Biblioteca *b){
	char answ;
	int i, comp, marca;
	for(i=0;i<b->n;i++){
		comp = strcmp(lib.titulo, b->vec[i].titulo);
		if(comp==0){
			printf("El libro ya se encuentra en sistema.\n");
			mostrarLibro(*b, i);
			marca = 1;
		}
	}
	if(marca!= 1){
		printf("*****************************************************************************************************************\n");
		printf("Titulo: %s\n", lib.titulo);
		for(i=0; i<lib.cantidadAutores;i++){
			printf("Autor: %s\n", lib.autor[i]);
		}
		printf("Paginas: %s\nEditorial: %s\nISBN: %s\nGenero: %s\nAño:%s\n",lib.pag, lib.editorial, lib.isbn, lib.genero, lib.year);
		printf("*****************************************************************************************************************\n");
		printf("Los datos ingresados son correctos? [S][N]\n");
		scanf("%c", &answ);
		if(toupper(answ )== 'S'){
		    b->vec[b->n] = lib;
		    (b->n)++;
		}	
	}
}

//funcion que busca un libro por el titulo y retorna la posicicionn del mismo dentro de la biblioteca
//se le debe pasar la biblioteca y el titulo del libro que se quiere buscar
 int posicionLibro(Biblioteca b,char busqueda[60]){
	int compara;
	int pos =-1;
	int i = 0;
	while(i<b.n && pos == -1){
		compara = strcmp(busqueda, b.vec[i].titulo);
		if(compara==0){
			pos=i;
		}
		i++;
	}
	return pos;
}

//funcion que busca un libro dentro de la biblioteca
//esta funcion llama a la funcion posicionlibro para obtener el lugar
//la fncion posicion es utilizada a su vez para comprobar si el libro esta o no dentro del sistema
//muestra el libro buscado en pantalla
void buscarLibro(Biblioteca b){
	int i, marca, opcion, pos;
	char busqueda[60];
	printf("Ingrese el nombre del libro a buscar: ");
	fflush(stdin);
	gets(busqueda);
	strupr(busqueda);
	pos = posicionLibro(b, busqueda);
	if(pos == -1){
		printf("El libro que busca no se encuentra en nuestra biblioteca.\n");
	}
	else{
		printf("El libro esta en nuestra biblioteca.\n");
		mostrarLibro(b, pos);
	}
}







//funcion para eliminar un determinado libro ingresando el titulo
//una vez eliminado, corre todas las posiciones del vector que siguen hacia el lugar anterior.
//y se llamara a la funcion que corrige el indice.
void borrarLibro(Biblioteca *b){
	int i;
	char libro[60];
	printf("Ingrese el nombre del titulo que desea eliminar: ");
	gets(libro);
	strupr(libro);
	int p = posicionLibro(*b, libro);
	if(p != -1){
		for(i=p;i<b->n-1;i++){
			b->vec[i] = b->vec[i+1];
		}
		(b->n)--;
	}
	
	printf("El libro se elimino correctamente.");
}




//menu de edicion de libros, ofrece posibilidad de editar sus datos indivudualmente o 
//todos al mismo tiempo
//para esto se le pasa el tipo Libro, que sera utilizado para guardar los datos del libro original y modificar sobre este.
//para una vez confirmado las modificaciones sobrescribir el libro en la biblioteca
//con esto permite cancelar la edicion en cualquier momento sin que se escriba el original.

void editarLibro(Biblioteca *b, Libro *lib){
	enum { SALIR =0, Autor, Paginas, Editorial, ISBN, Genero, Anio};
	int i, editar;
	char libro[60];
	printf("Ingrese el libro que desea editar: ");
	gets(libro);
	strupr(libro);
	int p= posicionLibro(*b, libro);
	*lib = b->vec[p];
	if(p !=-1){
		do{
			do{
				char answ = 'o';
				printf("*****************************************************************************************************************\n");
					printf("Titulo: %s\n", lib->titulo);
					for(i=0; i<lib->cantidadAutores;i++){
						printf("Autor: %s\n", lib->autor[i]);
					}
					printf("Paginas: %s\nEditorial: %s\nISBN: %s\nGenero: %s\nAño:%s\n",lib->pag, lib->editorial, lib->isbn, lib->genero, lib->year);
				printf("*****************************************************************************************************************\n");
				printf("Que dato desea modificar?\n");
				printf("[1]Autor - [2]Paginas - [3]Editorial - [4]ISBN - [5]Genero - [6]Año - [0]Salir.");
				fflush(stdin);
				scanf("%d", &editar);
				fflush(stdin);
				switch(editar){
					case Autor:
						int cant, pos;
						do{
							for(cant=0; cant<lib->cantidadAutores; cant++){
								printf("[%d] Autor actual: %s\n",cant, lib->autor[cant]);
							}
							printf("Ingrese el numero de autor que desea editar: ");
							scanf("%d", &pos);
							fflush(stdin);				
							printf("Ingrese el nuevo autor: ");
							gets(lib->autor[pos]);
							strupr(lib->autor[pos]);
							printf("\nEl nuevo autor ingresado es: %s\n", lib->autor[pos]);
							printf("Es correcto: [S]i, [N]o, [C]ancelar edicion. ");
							scanf("%c", &answ);
							fflush(stdin);
						}while(toupper(answ) !='S' && toupper(answ) !='C');
						if(toupper(answ)=='S'){
							b->vec[p] = *lib;
							printf("\nEl nuevo autor es ahora: %s\n", b->vec[p].autor[pos]);
						}
						break;
					case Paginas:
						do{
							printf("La cantidad de paginas es: %s", lib->pag);
							printf("Ingrese la nueva cantidad de paginas: ");
							gets(lib->pag);
							printf("\nLa nueva cantidad de paginas es: %s\n", lib->pag);
							printf("Es correcto: [S]i, [N]o, [C]ancelar edicion. ");
							scanf("%c", &answ);
							fflush(stdin);
						}while(toupper(answ) !='S' && toupper(answ) !='C');
						if(toupper(answ)=='S'){
							b->vec[p] = *lib;
							printf("\nLos nuevos datos fueron guardados.\n");
						}
						break;
					case Editorial:
						do{
							printf("La cantidad de paginas es: %s", lib->editorial);
							printf("Ingrese la nueva editorial: ");
							gets(lib->editorial);
							strupr(lib->editorial);
							printf("\nLa nueva cantidad de paginas es: %s\n", lib->editorial);
							printf("Es correcto: [S]i, [N]o, [C]ancelar edicion. ");
							scanf("%c", &answ);
							fflush(stdin);
						}while(toupper(answ) !='S' && toupper(answ) !='C');
						if(toupper(answ)=='S'){
							b->vec[p] = *lib;
							printf("\nLos nuevos datos fueron guardados.\n");
						}
						break;
					case ISBN:
						do{
							printf("El ISBN acual es: %s", lib->isbn);
							printf("Ingrese la nueva cantidad de paginas: ");
							gets(lib->isbn);
							printf("\nEl nuevo ISBN es: %s\n", lib->isbn);
							printf("Es correcto: [S]i, [N]o, [C]ancelar edicion. ");
							scanf("%c", &answ);
							fflush(stdin);
						}while(toupper(answ) !='S' && toupper(answ) !='C');
						if(toupper(answ)=='S'){
							b->vec[p] = *lib;
							printf("\nLos nuevos datos fueron guardados.\n");
						}
						break;
					case Genero:
						do{
							printf("El genero es: %s", lib->genero);
							printf("Ingrese el nuevo genero: ");
							gets(lib->genero);
							strupr(lib->genero);
							printf("\nEl nuevo genero es: %s\n", lib->genero);
							printf("Es correcto: [S]i, [N]o, [C]ancelar edicion. ");
							scanf("%c", &answ);
							fflush(stdin);
						}while(toupper(answ) !='S' && toupper(answ) !='C');
						if(toupper(answ)=='S'){
							b->vec[p] = *lib;
							printf("\nLos nuevos datos fueron guardados.\n");
						}
						break;
					case Anio:
						do{
							printf("El año es: %s", lib->year);
							printf("Ingrese el nuevo año: ");
							gets(lib->year);
							printf("\nEl nuevo año es: %s\n", lib->year);
							printf("Es correcto: [S]i, [N]o, [C]ancelar edicion. ");
							scanf("%c", &answ);
							fflush(stdin);
						}while(toupper(answ) !='S' && toupper(answ) !='C');
						if(toupper(answ)=='S'){
							b->vec[p] = *lib;
							printf("\nLos nuevos datos fueron guardados.\n");
						}
						break;
					case SALIR:
						break;
				}
			}while(editar<0 || editar>7);
		}while(editar!=0);
	}
}






