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


Nome: Arthur Campello Gausmann
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void indica que o tipo da variável é indefinido no momento, deve ser feito um casting para o tipo correto antes de acessar

#define INICIAL_SIZE ( ( sizeof( int ) * 6 ) + ( sizeof( char ) * 70 ) ) // Tamanho inicial do buffer, para armazenar os endereços auxiliares
#define MENU ( *( int * )pBuffer ) // Utilizado para receber e selecionar a opção do menu
#define LENGHT_LIST ( *( int *)( pBuffer + sizeof( int ) ) ) // Contador para tamanho de pessoas na lista
#define AUX_INT1 ( *( int *)( pBuffer + sizeof( int ) * 2 ))
#define AUX_INT2 ( *( int *)( pBuffer + sizeof( int ) * 3 ) ) 
#define AUX_INT3 ( *( int *)( pBuffer + sizeof( int ) * 4 ) ) // Endereço int de memória para auxiliar 
#define TOTAL_SIZE ( *( int *)( pBuffer + sizeof( int ) * 5 ) ) // Tamanho total do buffer, vai ser atualizado de acordo com o necessário
#define CHAR_NOME ( (char *)( pBuffer + sizeof( int ) * 6 ) ) 
#define CHAR_EMAIL ( (char *)( pBuffer + sizeof( int ) * 6 + sizeof( char ) * 30 ) ) // Endereço char de memória para auxiliar

void *Menu ( void *pBuffer );
void *Adicionar ( void *pBuffer );
void *Remover ( void *pBuffer );
void Buscar ( void *pBuffer );
void Listar ( void *pBuffer );

void main() {
    void *pBuffer = malloc( INICIAL_SIZE );

    MENU = 0;
    LENGHT_LIST = 0;
    TOTAL_SIZE = INICIAL_SIZE;

    while( 1 ) {
        pBuffer = Menu( pBuffer );
    }
}

void *Menu( void *pBuffer) {
    printf( "\nSelecione o que deseja fazer:\n1 - Adicionar pessoa\n2 - Remover pessoa\n3 - Buscar por nome\n4 - Listar todos\n5 - Sair\n" );
    scanf("%d", &MENU );
    getchar(); // Limpar buffer do teclado

    switch ( MENU ) {
        case 1:
            pBuffer = Adicionar( pBuffer );
            break;
        case 2:
            pBuffer = Remover( pBuffer );
            break;
        case 3:
            Buscar( pBuffer );
            break;
        case 4:
            Listar( pBuffer );
            break;
        case 5:
            free( pBuffer );
            exit(0);
            break;
        default:
            printf( "Opção inválida" );
        break;
    }

    return pBuffer;
}

void *Adicionar( void *pBuffer ) {
    LENGHT_LIST++; // Soma mais 1 ao tamanho da lista

    printf( "Nome: " );
    scanf( "%[^\n]", CHAR_NOME ); // Recebendo o nome no endereço auxiliar
    getchar(); // Limpar buffer do teclado
    AUX_INT2 = strlen( CHAR_NOME ) + 1; // Recebe o tamanho do nome + \0

    printf( "Idade: " );
    scanf( "%d", &AUX_INT1); // Recebendo a idade no endereço auxiliar
    getchar(); // Limpar buffer do teclado

    printf( "Email: " );
    scanf( "%[^\n]", CHAR_EMAIL ); // Recebendo o email no endereço auxiliar
    getchar(); // Limpar buffer do teclado
    AUX_INT3 = strlen( CHAR_EMAIL ); // Recebe o tamanho do email + \0

    void *auxBuffer = realloc( pBuffer, TOTAL_SIZE + AUX_INT2 + sizeof(int) + AUX_INT3 ); // Realoca a memória com o tamanho dos nomes e email, e da idade
    if ( !auxBuffer ) { // Verifica se o realloc foi realizado corretamente
        printf( "Erro ao realocar a memória do buffer\n" );
        return pBuffer;
    }
    pBuffer = auxBuffer; // Após verificação, atualiza o espaço do buffer original

    void *auxPerson = ( pBuffer + TOTAL_SIZE ); // Auxiliar para adicionar nova pessoa, aponta para inicio da memória alocada para adicionar

    strcpy( auxPerson, CHAR_NOME); // Copia o nome para o auxiliar
    auxPerson += AUX_INT2 * sizeof( char ); // Aponta para depois de nome

    * ( int *)auxPerson = AUX_INT1; // Insere o valor da idade
    auxPerson += sizeof( int ); // Aponta para depois de idade

    strcpy( auxPerson, CHAR_EMAIL); // Copia o email

    TOTAL_SIZE += ( AUX_INT2 * sizeof( char ) ) + sizeof(int) + ( AUX_INT3 * sizeof( char ) ); // Adiciona o tamanho da nova pessoa ao tamanho total
    
    return pBuffer;

}

void *Remover( void *pBuffer) {
    printf("Função ainda não implementada\n");
    return pBuffer;
}

void Buscar( void *pBuffer ) {
    if (LENGHT_LIST == 0) {
        printf( "Nenhuma pessoa cadastrada!\n" );
        return;
    }

    printf( "Digite o nome para buscar: " );
    scanf( "%s", CHAR_NOME );

    void * auxPerson = ( pBuffer + INICIAL_SIZE );

    for ( AUX_INT1 = 1; AUX_INT1 <= LENGHT_LIST; AUX_INT1++ ) {

        if( strstr( auxPerson, CHAR_NOME ) ) {
            printf( "Pessoa encontrada %d:\n", AUX_INT1);

            printf( "   Nome: %s\n", ( char* )auxPerson );
            AUX_INT2 = strlen( ( char* )auxPerson );
            auxPerson += ( AUX_INT2 + 1);

            printf( "   Idade: %d\n", *( int* )auxPerson);
            auxPerson += sizeof( int );

            printf( "   Email: %s\n", ( char* )auxPerson );
            AUX_INT2 = strlen( ( char* )auxPerson );
            auxPerson += ( AUX_INT2 + 1);
        } else { // Caso não encontre, percorre o ponteiro auxiliar para ele estar apontado corretamente na próxima pessoa
            AUX_INT2 = strlen( ( char* )auxPerson );
            auxPerson += AUX_INT2 + 1;

            auxPerson += sizeof( int );

            AUX_INT2 = strlen( ( char* )auxPerson );
            auxPerson += AUX_INT2 + 1;
        }

    }
}

void Listar( void *pBuffer ) {
    if (LENGHT_LIST == 0) {
        printf( "Nenhuma pessoa cadastrada!\n" );
        return;
    }

    void * auxPerson = ( pBuffer + INICIAL_SIZE );

    for ( AUX_INT1 = 1; AUX_INT1 <= LENGHT_LIST; AUX_INT1++ ) {
        printf( "Pessoa %d:\n", AUX_INT1 );

        printf( "   Nome: %s \n", ( char* )auxPerson );
        AUX_INT2 = strlen( ( char* )auxPerson );
        auxPerson += ( AUX_INT2 + 1) * sizeof( char );

        printf( "   Idade: %d \n", *( int* )auxPerson);
        auxPerson += sizeof( int );

        printf( "   Email: %s \n", ( char* )auxPerson );
        AUX_INT2 = strlen( ( char* )auxPerson );
        auxPerson += ( AUX_INT2 + 1) * sizeof( char );
    }
}