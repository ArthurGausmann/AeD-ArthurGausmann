/*
Faça uma agenda com o seguinte menu:
1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
 
O desafio é não poder criar variáveis e sim um buffer de memória (void *pBuffer). Nisso vocês terão que fazer o trabalho que o Sistema Operacional 
faz para vocês ao organizar a memória.
 
Regras:
Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
Não pode usar struct em todo o programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pBuffer = malloc(sizeBytes); // void indica que o tipo da variável é indefinido no momento, deve ser feito um casting para o tipo correto antes de acessar

#define TAM_PESSOA( 10 * sizeof(char) + sizeof(int) + 10 * sizeof(char)) // nome(char[10]), idade(int), email(char[10])

void Menu ( void );
void Adicionar ( void );
void Remover ( void );
void Buscar ( void );
void Listar ( void );

void main() {
    Menu();
}

void Menu() {
    // primeiro int do pBuffer indica a opção do menu
    switch () {
    case 1:
        Adicionar();
        break;
    case 2:
        Remover();
        break;
    case 3:
        Buscar();
        break;
    case 4:
        Listar();
        break;
    case 5:
        free(pBuffer);
        exit(0);
        break;
    default:
        break;
    }
}

void Adicionar() {
    // realloc (qnt * TAM_PESSOA)
}

void Remover() {
    void *auxBuffer = malloc();
    memcpy();
    free(pBuffer);
    pBuffer = auxBuffer;
}

void Buscar() {
    // loop for com if(strcmp(nome, alvo)) para achar o nome igual
}

void Listar() {
    // loop for
}