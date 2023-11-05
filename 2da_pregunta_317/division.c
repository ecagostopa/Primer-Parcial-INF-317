#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    // La frase a dividir
    const char* frase = "Esta es una frase";

    // Número de hilos a utilizar
    int num_hilos = 2;

    // Contar el número de palabras en la frase
    int num_palabras = 0;
    char* palabra = strtok(strdup(frase), " ");
    while (palabra != NULL) {
        num_palabras++;
        palabra = strtok(NULL, " ");
    }

    // Crear dos arreglos de cadenas para palabras pares e impares
    char* palabras_pares[num_palabras];
    char* palabras_impares[num_palabras];

    // Inicializa OpenMP y especifica el número de hilos
    #pragma omp parallel num_threads(num_hilos)
    {
        // Obtiene el ID del hilo actual
        //int id_hilo = omp_get_thread_num();

        // Divide las palabras en pares e impares
        char* palabra = strtok(strdup(frase), " ");
        int cont=0;
        while (palabra != NULL) {
           if(strlen(palabra)%2==0)
           {
		palabras_pares[cont]=palabra;
		palabra = strtok(NULL, " ");
    	   }
    	   else{
    	   	palabras_impares[cont]=palabra;
    	   	palabra = strtok(NULL, " ");
    	   }
    	   cont++;
    	}
    }

    // Imprimir las palabras pares e impares
    printf("La frase es: %s \n", frase);
    printf("Palabras pares: ");
    for (int i = 0; i < num_palabras; i++) {
        if (palabras_pares[i] != NULL) {
            printf("%s ", palabras_pares[i]);
            //free(palabras_pares[i]);
        }
    }
    printf("\n");

    printf("Palabras impares: ");
    for (int i = 0; i < num_palabras; i++) {
        if (palabras_impares[i] != NULL) {
            printf("%s ", palabras_impares[i]);
            //free(palabras_impares[i]);
        }
    }
    printf("\n");

    return 0;
}

