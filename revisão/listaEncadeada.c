#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura
typedef struct No {
    int dado;
    struct No *proximo;
} No;

// Criar novo nó
No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação!\n");
        return NULL;
    }
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

// Inserir no INÍCIO
No* inserir_inicio(No *cabeca, int valor) {
    No *novo = criar_no(valor);
    novo->proximo = cabeca;  // Novo aponta para a antiga cabeça
    return novo;             // Novo se torna a nova cabeça
}

// Inserir no FIM
No* inserir_fim(No *cabeca, int valor) {
    No *novo = criar_no(valor);
    
    // Lista vazia
    if (cabeca == NULL) {
        return novo;
    }
    
    // Encontrar o último nó
    No *atual = cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
    atual->proximo = novo;
    return cabeca;
}

// Imprimir lista
void imprimir_lista(No *cabeca) {
    No *atual = cabeca;
    
    printf("LISTA: ");
    while (atual != NULL) {
        printf("[%d] → ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Buscar elemento
No* buscar(No *cabeca, int valor) {
    No *atual = cabeca;
    
    while (atual != NULL) {
        if (atual->dado == valor) {
            return atual;  // Encontrou!
        }
        atual = atual->proximo;
    }
    
    return NULL;  // Não encontrou
}

// Remover elemento
No* remover(No *cabeca, int valor) {
    if (cabeca == NULL) return NULL;
    
    // Caso especial: remover a cabeça
    if (cabeca->dado == valor) {
        No *nova_cabeca = cabeca->proximo;
        free(cabeca);
        return nova_cabeca;
    }
    
    // Buscar o elemento
    No *anterior = cabeca;
    No *atual = cabeca->proximo;
    
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    // Se encontrou, remove
    if (atual != NULL) {
        anterior->proximo = atual->proximo;
        free(atual);
    }
    
    return cabeca;
}

// Liberar toda a lista
void liberar_lista(No *cabeca) {
    No *atual = cabeca;
    
    while (atual != NULL) {
        No *proximo = atual->proximo;  // Salva referência
        free(atual);                   // Libera nó atual
        atual = proximo;               // Avança
    }
    
    printf("Lista liberada!\n");
}