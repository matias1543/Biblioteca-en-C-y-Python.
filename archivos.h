

/*funciones que realizan la carga del archivo y 
la grabacion del mismo en ambos se pasa la biblioteca,
 en la primera guardar los datos de la misma en el .dat
en la segunda para levantar los datos de la misma y 
que esten disponibles al ejecutar el programa
*/


/*funcion para fijarse que los archivos existan
en caso de no existir los crea vacios para que no tire error
 al intertar leer/grabar algo que no existe.*/
void crearArchivos(){
	FILE *fp = fopen("biblio.dat", "ab");
	fclose(fp);

}



//funciones de lectura y grabacion de la biblioteca
void grabarBiblioteca( Biblioteca b ){
	int i;
	FILE *fp = fopen("biblio.dat", "wb");
	if(fp==NULL){
		printf("Error en la grabacion.");
		exit(0);
	}
	for(i=0;i<=b.n;i++){
		fwrite(&b.vec[i], sizeof(Libro), 1, fp);
	}
	fclose(fp);
}


void lectura(Biblioteca *b){
	Libro aux;
	int n = 0;
	FILE *fp = fopen("biblio.dat","rb");
	if(fp==NULL){
		printf("Error de lectura.");
		exit(0);
	}
	while(fread(&aux,sizeof(Libro),1,fp)==1){
		b->vec[n] = aux;
		b->n = n;
		n++;
	}
	fclose(fp);
}


