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

// void indica que o tipo da variável é indefinido no momento, deve ser feito um casting para o tipo correto antes de acessar

#define INICIAL_SIZE ( ( sizeof( int ) * 5 ) + ( sizeof( char ) * 70 ) ) // Tamanho inicial do buffer, para armazenar os endereços auxiliares

#define TAM_PESSOA ( sizeof( char ) * 30 + sizeof( int ) + sizeof( char ) * 40 ) // nome(char[10]), idade(int), email(char[10])
#define MENU ( *( int * )pBuffer ) // Utilizado para receber e selecionar a opção do menu
#define LENGHT_LIST ( *( int *)( pBuffer + sizeof( int ) ) ) // Contador para tamanho de pessoas na lista
#define AUX_INT1 ( *( int *)( pBuffer + sizeof( int ) * 2 ))
#define AUX_INT2 ( *( int *)( pBuffer + sizeof( int ) * 3 ) ) 
#define AUX_INT3 ( *( int *)( pBuffer + sizeof( int ) * 4 ) ) // Endereço int de memória para auxiliar 
#define CHAR_NOME ( (char *)( pBuffer + sizeof( int ) * 5 ) ) 
#define CHAR_EMAIL ( (char *)( pBuffer + sizeof( int ) * 5 + sizeof( char ) * 30 ) ) // Endereço char de memória para auxiliar

void *Menu ( void *pBuffer );
void *Adicionar ( void *pBuffer );
void *Remover ( void *pBuffer );
void Buscar ( void *pBuffer );
void Listar ( void *pBuffer );

void main() {
    void *pBuffer = malloc( INICIAL_SIZE );

    Menu();
}

void *Menu( void *pBuffer) {
    do (
        printf(
            "Selecione o que deseja fazer:\n
            1 - Adicionar pessoa\n
            2 - Remover pessoa\n
            3 - Buscar por nome\n
            4 - Listar todos\n
            5 - Sair"
        );
        scanf("%d", &MENU );

        switch ( MENU ) {
        case 1:
            pBuffer = Adicionar( *pBuffer );
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
            free( pBuffer );
            exit(0);
            break;
        default:
            break;
        }
    ) while ( MENU );
}

void *Adicionar( void *pBuffer ) {
    LENGHT_LIST++; // Soma mais 1 ao tamanho da lista

    printf( "Nome: " );
    scanf( " %[^\n]", CHAR_NOME ); // Recebendo o nome no endereço auxiliar
    printf( "Idade: " );
    scanf( " %d", AUX_INT1); // Recebendo a idade no endereço auxiliar
    printf( "Email: " );
    scanf( " %[^\n]", CHAR_EMAIL ); // Recebendo o email no endereço auxiliar

    realloc( pBuffer, INICIAL_SIZE + ( TAM_PESSOA * LENGHT_LIST ) ); // Alterando o tamanho da memória do pBuffer para adicionar a nova pessoa (não dinâmica)


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