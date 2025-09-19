#include <stdio.h>
#include <stdlib.h>

int MAX = 100;
// string lista[MAX];

void main () {
    int opt;
    do {
        printf("\nSelecione o que você deseja fazer: \n1. Adicionar nome\n2. Remover nome\n3. Listar\n4. Sair\n");
        scanf("%d", &opt);
        printf("Selecionado opção: %d\n", opt);

        switch (opt) {
            case 1: //TODO: Função para adicionar os nomes na string
                break;
            case 2: //TODO: Função para remover os nomes na string
                break;
            case 3: //TODO: Função para listar os nomes da string
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Opção selecionada inváldia!\n");
                break;
        }
    } while (opt);
}