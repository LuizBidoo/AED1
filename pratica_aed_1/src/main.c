#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize);

int main()
{
    printf("Hello World!\n");

    return 0;
}

/* ideia inicial: alocar um array de chars 
*  para pegar cada caractere da licensePlate
*  depois comparar os arrays de palavras com
*  esse novo array de letras e a que tiver mais
*  em comum será retornada. Se ocorrer de duas 
*  terem o mesmo tamanho, fazer um strlen e pegar 
*  a menor.
*/ 

/* Segunda ideia: pegar a string de letras da licença
*  vai comparando as strings e aquelas que tiverem a maior
*  paridade salvar o índice e a palavra, caso tenha que testar
*  duas iguais.
*
*/
char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    char *letters = (char*) malloc(wordsSize * sizeof(char)); // letras encontradas
    char digits = '0123456789';
    int i, j, smallestWord = 0;

    for(i = 0; i <= 6; i++){
        for(j = 0; j <= 10; j++){
            if(strchr(licensePlate[i], digits) == 0){ //para verificar só letras
                letters[i] = licensePlate[i];
            }
        }
    }

    for(i = 0; i <= 15; i++){
        for(j = 0; j <= wordsSize; j++){
            if((strchr(words[j], letters[i]) == 0)){
                
            }
        }
    }