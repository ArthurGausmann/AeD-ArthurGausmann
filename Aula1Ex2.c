#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Adicionar( void );
void Remover( void );
void Listar ( void );

char *lista = NULL;

void main () {
    int opt;
    do {
        printf( "\nSelecione o que você deseja fazer: \n1. Adicionar nome\n2. Remover nome\n3. Listar\n4. Sair\n" );
        scanf( "%d", &opt );
        printf( "Selecionado opção: %d\n", opt );

        switch ( opt ) {
            case 1: //TODO: Função para adicionar os nomes na string
                Adicionar();
                break;
            case 2: //TODO: Função para remover os nomes na string
                Remover();
                break;
            case 3: //Função para listar os nomes da string
                Listar();
                break;
            case 4:
                free(lista);
                exit(0);
                break;
            default:
                printf( "Opção selecionada inváldia!\n" );
                break;
        }
    } while ( opt );
}

void Adicionar() {
    char nome[80];

    printf( "Escreva o nome para adicionar: " );
    scanf( "%s", nome );
    
    lista = (char *)realloc(lista, strlen(nome) * sizeof(char*));
    printf( "\n'%s' foi adicionado com sucesso!\n", nome );

    strcat( nome, "; " );
    strcat( lista, nome );
}

void Remover() {
    char aux[80];
    printf( "Escreva o nome para remover: " );
    scanf( "%s", aux );
}

void Listar() {
    printf( "\n%s\n", lista );
}