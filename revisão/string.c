#include <string.h>
#include <stdio.h>

void main() {
    char p[50]; // define a variável 'p' tipo char com tamanho 50 bits
    printf("Escreva uma palavra: ");
    scanf("%50[^\n]", p); // permite ler frases separadas por espaço ' '
    printf("\nPalavra escrita %s\n", p);
}