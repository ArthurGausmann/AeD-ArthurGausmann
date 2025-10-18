#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int ra;
    char nome[50];
} Aluno;

typedef struct {
    Aluno alunos[MAX];
    int topo;
    int base;
    int limite;
} Pilha;

// Definição das funções
void Reset(Pilha *pilha);
bool Empty(Pilha *pilha);
bool Full(Pilha *pilha);
bool Push(Pilha * pilha, Aluno *item);
bool Pop(Pilha *pilha, Aluno *aluno);
void List(Pilha *pilha);

void main() {
    Pilha pilha;
    Aluno aluno1 = {123, "Arthur"};
    Aluno aluno2 = {456, "Manuela"};

    Reset(&pilha);

    Push(&pilha, &aluno1);
    Push(&pilha, &aluno2);

    List(&pilha);

    Aluno alunoAux;
    Pop(&pilha, &alunoAux);

    List(&pilha);
}

void Reset(Pilha *pilha) {  // Recebe uma ponteiro para pilha e retorna seus valores zerados
    pilha->topo = 0;        // Pilha vazia
    pilha->base = 0;        // Primeira posição disponível
    pilha->limite = MAX;    // Capacidade definida por MAX
}

bool Empty(Pilha *pilha) {      // Recebe uma pilha e retorna True/False se for vazia ou não
    return pilha->topo == 0;    // Verifica se o topo for 0, lista vazia 
                                // True -> Vazia || False -> Não vazia
}

bool Full(Pilha *pilha) {       // Recebe uma pilha e retorna True/False se estiver cheia ou não
    return pilha->topo == MAX;  // Verifica se o topo for o limite máximo, lista cheia
                                // True -> Cheia || False -> Não cheia
}

bool Push(Pilha *pilha, Aluno *item) {      // Recebe uma pilha e um elemeno, adiciona o elemento ao topo da pilha
    if(!Full(pilha)) {                      // Verifica se a pilha não estiver cheia
        pilha->alunos[pilha->topo] = *item; // Copia o item ao array na posição indicada como topo
        pilha->topo++;                      // Passo o indicador do topo para uma casa para frente
        return true;
    } else { return false; }                // Retorna falso se a pilha estiver cheia
}

bool Pop(Pilha *pilha, Aluno *aluno) {       // Recebe uma pilha e uma variável, copia o valor topo para essa variável 
    if(!Empty(pilha)) {                      // Verifica se a pilha não ta vazia
        pilha->topo--;                       // Retorna o indicador de topo para o último elemento válido
        *aluno = pilha->alunos[pilha->topo]; // Copia o elemento do topo para a variável passada
        printf("Aluno removido: %s - RA: %d\n", aluno->nome, aluno->ra);
        return true;
    } { return false; }                      // Retorna falso se a pilha estiver vazia
}

void List(Pilha *pilha) {   // Recebe uma pilha para listar seus valores
    // Loop For para ir do topo até a base, respeitando a lógiac da estrutura de pilha
    printf("\n--Lista de Alunos--\n");
    for(int i = pilha->topo - 1; i >= pilha->base; i--) {
        printf("Aluno: %s - RA: %d\n", pilha->alunos[i].nome, pilha->alunos[i].ra);
    }
}