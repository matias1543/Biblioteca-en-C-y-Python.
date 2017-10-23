

/*En la funcion listarAutores se busca dentro de la biblioteca los autores 
se creo un vector para guardar todos los autores, para que de esta manera 
al llamarlo no aparezcan dos veces los autores de dos o mas libros.
para inicializar la funcion se le pasa el tipo autores y la biblioteca.
cada vez que se llame a esta funcion solo compara los autores que 
se encuentran en la misma, de esta manera si se agreagan nuevos
 solo terminara agreando estos ultimos.*/


void listarAutores(Biblioteca b, Autores *autores){
	int i;
	for(i=0;i<b.n;i++){
		int j=0, cant;
		for(cant=0; cant<b.vec[i].cantidadAutores; cant++){
			int  compara = 1;
			while(j<=autores->cant && compara !=0){
				compara = strcmp(b.vec[i].autor[cant],autores->vec[j].autor);
				j++;
			}
			if(compara!=0){
				strcpy(autores->vec[autores->cant].autor, b.vec[i].autor[cant]);
				(autores->cant)++;
			}
		}	
	}
	for(i=0;i<autores->cant;i++){
		printf("%s\n", autores->vec[i].autor);
	}
}


/*busca el autor que se ingresa dentro de la biblioteca, al econtrarse llama
 a la funcion mostrarLibro para mostrar el libro en pantalla*/

void listarxAutor(Biblioteca b){
		int i, marca=0;
		char autor[20];
		printf("Ingresar el autor que desea buscar: ");
		gets(autor);
		strupr(autor);
		for(i=0; i<b.n; i++){
			int cant;
			for(cant=0; cant<b.vec[i].cantidadAutores; cant++){
				if(strcmp(autor, b.vec[i].autor[cant])==0){
					mostrarLibro(b,i);
					marca++;
				}
			}
		}
		if(marca==0){
			printf("No se encuentro ningun libro de %s, en el sistema.", autor);
		}
}


//Muestra todos los libros que se encuentran en la biblioteca
void listarxTitulo(Biblioteca b){
	int i;
	for(i=0; i<b.n; i++){
		mostrarLibro(b,i);
	}
}



/*compara el genero que se ingresa contra los que estan en sistema,
al haber coincidencia imprime el libro en pantalla.*/
void listarxGenero(Biblioteca b){
	int i, marca=0;
	char genero[20];
	printf("Ingrese el genero que desea buscar: ");
	gets(genero);
	strupr(genero);
	for(i=0; i<b.n; i++){
		if(strcmp(genero, b.vec[i].genero)==0){
			mostrarLibro(b,i);
			marca++;
		}
	}
	if(marca==0){
		printf("No se encuentran libros del genero solicitado en el sistema.");
	}
}


/*funcion que pide una editorial y la compara con las ya existentes
 en la libreria, imprime al encontrar concidencia,
en caso de no encontrar nada habisa mostrando lo que se busco.*/
void listarxEditorial(Biblioteca b){
	int i, marca=0;
	char editorial[20];
	printf("Ingresar el autor que desea buscar: ");
	gets(editorial);
	strupr(editorial);
	for(i=0; i<b.n; i++){
		if(strcmp(editorial, b.vec[i].editorial)==0){
			mostrarLibro(b,i);
			marca++;
		}
	}
	if(marca==0){
		printf("No se encuentro ningun libro de la editorial %s, en el sistema.", editorial);
	}
}



/*funcion que busca los libros editados en un rango de años por cierta editorial
se ingresan los 3 datos y se compara primero buscando coincidencia en la editorial
si no se necuentra se avisa al usuario que esa editorial no esta en el sistema
si hay coincidencia se busca entre los parametros de año, se realizaron dos funciones
 para tener en cuenta que el ingreso de los años pede no estar ordenado
si no hay libros en esos años avisa al usuario que la editorial 
existe pero no publicaciones en esa franja temporal.*/
void listarxEditorialyAnio(Biblioteca b){
	int i;
	char editorial[20], anio1[5], anio2[5];
	printf("Ingrese editorial: ");
	gets(editorial);
	strupr(editorial);
	printf("Ingrese año desde el que desea buscar: "); 
	gets(anio1);
	printf("Ingrese año hasta el que desea buscar: ");
	gets(anio2);
	for(i=0;i<b.n;i++){
		if(strcmp(editorial, b.vec[i].editorial) ==0){
			if(strcmp(anio1, anio2) <= 0){
				if(strcmp(anio1, b.vec[i].year)<=0 && strcmp(b.vec[i].year, anio2)<=0){
					mostrarLibro(b,i);
				}
			}
			else if(strcmp(anio2, anio1) < 0){
				if(strcmp(anio2, b.vec[i].year)<=0 && strcmp(b.vec[i].year, anio1)<=0){
					mostrarLibro(b,i);
				}
			}
			else{
				printf("No se encontraron libros de la %s entre los años pedidos\n.", editorial);
			}
		}
		else{
			printf("No se encontraron libros de la editorial solicitada.\n");
		}
	}
	
}



//busca todos los autores de la editorial buscada
//dentro de la comparacion se realiza una busqueda para asegurarse que solo se pone 1 vez cada autor

void ListarxAutordeEditorial(Biblioteca b){
	int i, marca=0, j, duplicado, cant;
	char autores[100][60];
	char editorial[60];
	printf("Ingrese la editorial de la que desea ver los autores disponibles: \n");
	gets(editorial);
	strupr(editorial);
	for(i=0; i<b.n;i++){
		if(strcmp(editorial, b.vec[i].editorial)==0){
			j=0;
			duplicado=3;
			for(cant=0; cant<b.vec[i].cantidadAutores; cant++){
				while(duplicado != 0 && j<=marca){
					duplicado = strcmp(autores[j], b.vec[i].autor[cant]);
					j++;
				}
				if(duplicado!=0 || marca == 0){
					strcpy(autores[marca], b.vec[i].autor[cant]);	
					printf("%s\n", b.vec[i].autor[cant]);
					marca++;
					duplicado = 3;
				}
			}		
		}
	}
	if(marca==0){
		printf("No se encontraron publicaciones de esa editorial.");
	}

}




//funcion quemuestra todos los libros por un año especifico.
void listarxAnio(Biblioteca b){
	int i;
	char anio[5];
	printf("ingrese año que desea buscar: ");
	gets(anio);
	for(i=0;i<b.n;i++){
		if(strcmp(anio, b.vec[i].year)==0){
			mostrarLibro(b,i);
		}
	}
}


//funcion que muestra todos los libros cuyo autor comience con una letra determinada

void listarxLetraAutor(Biblioteca b){
	int i, cant;
	char letra;
	printf("Ingese la inicial del apellido del autor que desea buscar: ");
	scanf("%c", &letra);
	for(i=0;i<b.n;i++){
		for(cant=0; cant<b.vec[i].cantidadAutores; cant++){
			if(toupper(letra) == toupper(b.vec[i].autor[cant][0])){
				mostrarLibro(b,i);
			}
		}
	}	
}


/*funcion que recorre el titulo, diviviendolo en palabras
compara estas palabras con una determinada
y muestra en pantalla todos los titulos que contengan dicha palabra
en caso de no encontrarse ninguno, avisa al usuario de esto.*/
void ListarxPalabra(Biblioteca b){
	fflush(stdin);
	char palabra[30], titulo[60];
	int i, marca, coincidendia = 0;
	printf("Ingrese la palabra que contiene el titulo: ");
	gets(palabra);
	strupr(palabra);
	for(i=0;i<b.n;i++){
			strcpy(titulo, b.vec[i].titulo);
			marca=0;
			char cortes[4] = " \n\t";
    		char *parte;
			parte = strtok( titulo, cortes );
			if(strcmp(parte, palabra) == 0){
				mostrarLibro(b,i);
				coincidendia++;
				marca++;
			}
			if(marca==0){
				while( (parte = strtok( NULL, cortes )) != NULL ){
					if(strcmp(parte, palabra) == 0){
						coincidendia++;
						mostrarLibro(b,i);
					}
				}
			
			}
	}
	if(coincidendia==0){
		printf("No se encontraron libros que contenga la palabra %c en la biblioteca.", palabra);
	}
}
