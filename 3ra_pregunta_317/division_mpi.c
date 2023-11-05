#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    char* frase = "Esta es una frase corta";
    
    //Contar palabras de la frase
    int num_palabras = 0;
    char* palabra = strtok(strdup(frase), " ");
    while (palabra != NULL) {
        num_palabras++;
        palabra = strtok(NULL, " ");
    }
    
    // Definir las palabras
    char* palabras1[num_palabras];//pares
    char* palabras2[num_palabras];//impares
    
    // Dividir la frase en palabras
    int cont = 0;
    int cnt=0;
    char* palabras = strtok(strdup(frase), " ");
    while (palabras != NULL) {
    	if(strlen(palabras)%2==0){
    		palabras1[cont] = palabras;
    		cont++;
    		palabras = strtok(NULL, " ");
    	}
    	else{
    		palabras2[cnt] = palabras;
    		cnt++;
    		palabras = strtok(NULL, " ");
    	}
    	
    }

    // Crear vectores para cada proceso
    const char *mi_palabra1 = palabras1[rank];
    const char *mi_palabra2 = palabras2[rank];

    // Imprimir las palabras para cada proceso
    printf("Frase: %s \n", frase);
    printf("Hilo %d - Palabra Par: %s\n", rank, mi_palabra1);
    printf("Hilo %d - Palabra Impar: %s\n", rank, mi_palabra2);

    MPI_Finalize();
    return 0;
}

