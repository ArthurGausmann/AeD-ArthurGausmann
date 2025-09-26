#include <stdio.h>

void main() {
    printf("Quantidade de bytes do tipo 'int': %ld\n", sizeof(int)); // fornece a quantidade de bytes que o tipo de dado ocupa
    printf("Quantidade de bytes do tipo 'char': %ld\n", sizeof(char)); 
    printf("Quantidade de bytes do tipo 'float': %ld\n", sizeof(float)); 

    int num = 5; // 'num' como int e valor 5
    int *m; // 'm' é um ponteiro do tipo int

    m = &num; // ''m' aponta para 'num'

    printf( "Endereço de memória que 'm' está apontando: %p\n", m ); // imprime o endereço que o ponteiro 'm' está apontado
    printf( "Valor que 'm' está apontando: %d\n", *m ); // imprime o conteúdo (valor) que 'm' está apontado

    int *k;
    k = m; // 'k' recebe 'm', agora 'k' também aponta para 'num'

    printf("Tanto 'k': %d, quanto 'm': %d, apontam para 'num'\n", *k, *m); // imprime os conteúdos de 'k' e 'm'
}