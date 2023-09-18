#include <stdio.h>
#include <stdlib.h>

/*
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

}; */

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

void sortIntervals( int** intervals, int intervalsSize ) {
    for ( int i = 0; i < intervalsSize - 1; i++ ) {
        for ( int j = i + 1; j < intervalsSize; j++ ) {
            if ( intervals[i][0] > intervals[j][0] ) {
                int* temp = intervals[i];
                intervals[i] = intervals[j];
                intervals[j] = temp;
            }
        }
    }
}

int** merge( int** intervals, int intervalsSize, int* returnSize, int** returnColumnSizes ) {
    if ( intervalsSize < 1 ) {
        *returnSize = 0;
        return NULL;
    } else {
        sortIntervals( intervals, intervalsSize ); // Organiza os intervalos

        // Alocações
        int** result = ( int** )malloc( sizeof(int*) * intervalsSize );
        *returnColumnSizes = ( int* )malloc( sizeof(int) * intervalsSize );
        *returnSize = 0;

        // Inicializa o primeiro intervalo
        result[0] = intervals[0];
        ( *returnColumnSizes )[0] = 2; // Sempre são 2 colunas (início e fim)
        ( *returnSize )++;

        for ( int i = 1; i < intervalsSize; i++ ) {
            int* currentInterval = intervals[i];
            int* lastInterval = result[*returnSize - 1];

            if ( currentInterval[0] <= lastInterval[1] ) {
                lastInterval[1] = ( currentInterval[1] > lastInterval[1]) ? currentInterval[1] : lastInterval[1];
            } else {
                // Os intervalos não se sobrepõem, adiciona o intervalo atual ao resultado
                result[*returnSize] = currentInterval;
                ( *returnColumnSizes )[*returnSize] = 2;
                ( *returnSize )++;
            }
        }

        return result;
    }
}

int main() {
    int intervals[][2] = {{1, 4}, {0, 2}, {3, 5}, {6, 8}};
    int intervalsSize = 4;

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** mergedIntervals = merge( ( int** )intervals, intervalsSize, &returnSize, &returnColumnSizes );

    printf( "Merged Intervals:\n" );
    for ( int i = 0; i < returnSize; i++ ) {
        printf( "[%d, %d]\n", mergedIntervals[i][0], mergedIntervals[i][1] );
    }

    // Liberar memória alocada
    for ( int i = 0; i < returnSize; i++ ) {
        free( mergedIntervals[i] );
    }
    free( mergedIntervals );
    free( returnColumnSizes );

    return 0;
}
