#include <string.h>
#include <stdio.h>

void main() {
    char p[50];
    printf("Escreva uma palavra: ");
    scanf("%50[^\n]", p);
    printf("\nPalavra escrita %s\n", p);
}