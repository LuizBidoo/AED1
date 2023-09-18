#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 /*
 * Aqui era uma boa aplicar MergeSort
 * juntando os intervalos, como eu leio intervalos?
 * 
 * Intervals é um array de array, percorre usando ponteiros
 * ou for
 * 
 * preciso particionar o vetor em intervalos e ver quais overlapam
 * daí alocar o novo vetor e retornar ele
 * 
 * Quando overlapa? ex: (1,3)(2,6) = 2 fica entre 1 e 3, logo, overlap
 * como fazer isso? criar um novo intervalo e fazer o merge do jeito que
 * entra o menor do primeiro e se o segundo menor for do segundo 
 * intervalo, da merge com o maior do segundo
 * outro caso de overlap (1,4) (4,5) = (1,5)
 * 
 */

int* mergeOverlaping(int** intervals, int intervalsSize, int* intervalsColSize){
    int* p1[**intervals]; // primeiro intervalo
    int* p2[**intervals+1]; // próximo intervalo
    int counter = intervalsSize;
    int* newInterval = (int*)malloc(2*sizeof(int));

    for(int i = **intervals; i < intervalsSize; **intervals++){ // vai percorrer o vetor de vetores
        if(p1[*intervalsColSize] >= p2[*intervalsColSize+1]){
            newInterval[0] = p1[*intervalsColSize];
            newInterval[1] = p2[*intervalsColSize+1];
        }   
        counter--;
    }

    return newInterval;

}; 

int** mergeAll(int** intervals, int* meio, int intervalsSize){
    int* p1, p2;
    p1 = intervals; // começa em intervals
    p2 = meio+1; // começa em meio + 1
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    // inicio é o intervals
    // fim? 
    int** arrayReturn = malloc(sizeof(returnSize));
    int* meio = floor((intervalsSize/2)); // tem que ir dividindo
    mergeAll(intervals, meio, intervalsSize);
    mergeAll(intervals, )
}
    

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    return 0;
}
