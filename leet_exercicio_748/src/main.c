#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* shortestCompletingWord( char* licensePlate, char** words, int wordsSize );

int main() {
    char licensePlate[] = "aBc 12c";
    char* words[] = {"abccdef","caaacab","cbca"};
    int wordsSize = 3;

    char* menorPalavra = shortestCompletingWord( licensePlate, words, wordsSize );
    printf( "%s\n", menorPalavra );

    free( menorPalavra );
    return 0;
}

char* shortestCompletingWord( char* licensePlate, char** words, int wordsSize ) {
    int* contagemLetras = (int*)malloc( 26 * sizeof(int) );
    int tamanhoMenorPalavra = 100;
    char* menorPalavra = NULL;
    int primeiraPalavraEncontrada = 0; 

    for(int i = 0; i < 26; i++){
        contagemLetras[i] = 0;
    }

    for( int i = 0; licensePlate[i] != '\0'; i++ ){
        char letraAtual = tolower( licensePlate[i] );
        if( isalpha( letraAtual ) ){
            contagemLetras[letraAtual - 'a']++;
        }
    }

    for( int i = 0; i < wordsSize; i++ ){
        int tamanhoPalavraTestada = strlen( words[i] );
        int contadorOcorrenciaAtual[26] = {0};

        for( int j = 0; j < tamanhoPalavraTestada; j++ ){
            char letraPalavra = tolower( words[i][j] );
            contadorOcorrenciaAtual[letraPalavra - 'a']++;
        }

        int testeDeValidade = 1;
        for ( int k = 0; k < 26; k++ ) {
            if ( contagemLetras[k] > contadorOcorrenciaAtual[k] ) {
                testeDeValidade = 0;
                break;
            }
        }

        if ( testeDeValidade && tamanhoPalavraTestada <= tamanhoMenorPalavra ) {
            if ( !primeiraPalavraEncontrada || tamanhoPalavraTestada < tamanhoMenorPalavra ) {
                menorPalavra = words[i];
                tamanhoMenorPalavra = tamanhoPalavraTestada;
                primeiraPalavraEncontrada = 1;
            }
        }
    }

    free(contagemLetras);

    return menorPalavra;
}