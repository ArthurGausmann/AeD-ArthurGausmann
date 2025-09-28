#include <string.h>
#include <stdio.h>

void main() {
    //1 Ler string e imprimir
    char p[50]; // define a variável 'p' tipo char com tamanho 50 bits
    printf("Escreva uma palavra: ");
    scanf("%s", p);
    printf("-Palavra escrita %s\n", p);

    //2 Comprimento string
    int i;
    for (i = 0; p[i] != '\0'; i++); // Para retornar o tamanho da string
    printf("A string %s tem tamanho %d\n", p, i);

    //3
    char p2[50];
    printf("Escreva um nome: ");
    scanf("%s", p2);
    if (p2[0] == 'm' || p2[0] == 'M'){
        printf("-O nome %s inicia com M\n", p2);
    } else {printf("Nome inválido\n");};

    //4
    char p3[50];
    printf("Escreva um nome: ");
    scanf("%s", p3);
    for (int i = 0; i < 4; i++)
        printf("Letra na posição %d: %c\n", i+1, p3[i]);
}