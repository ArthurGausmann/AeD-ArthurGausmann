#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lista[1000];

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
            case 3: //TODO: Função para listar os nomes da string
                Listar();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf( "Opção selecionada inváldia!\n" );
                break;
        }
    } while ( opt );
}

int Adicionar() {
    char nome[100];

    printf( "Escreva o nome para adicionar: " );
    scanf( "%s", nome );
    printf( "\n'%s' foi adicionado com sucesso!\n", nome );
    
    strcat( nome, "; " );
    strcat( lista, nome );
}

int Remover() {
    char aux[100];
    printf( "Escreva o nome para remover: " );
    scanf( "%s", aux );
}

int Listar() {
    printf( "\n%s\n", lista );
}