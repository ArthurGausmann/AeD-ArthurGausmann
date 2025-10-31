#include <stdio.h>

void main() {
    int estatico[100]; // Array terá sempre 100 elementos
    // Aloca espaço para 100 mas ou não usa os 100, ou pode acabar sendo insuficiente, ruim

    int size;
    // printf("Quantos elementos: ");
    // scanf("%d", &size); 
    size = 5;

    int *dinamico = (int*)malloc(size * sizeof(int)); // Array de tamanho dinâmico
    //              Malloc int  | Tamanho euqivalente a 'size' * o espaço que um int ocupa

    if (dinamico == NULL){printf("Erro"); return;} // Verifica se foi alocado corretamente
    // Array criado e verificado

    // Preenchendo o array
    for (int i = 0; i < size; i++) {
        dinamico[i] = i * 2;
    }

    // Sempre liberar memória ao final
    // free(dinamico);
    // dinamico = NULL;

    if (dinamico[size != NULL]) {
        size = size*2;
        dinamico = (int*)realloc(dinamico, size * sizeof(int));
    }
}