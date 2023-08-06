#include <stdio.h>
#include <stdlib.h>

void troca( int* a, int* b ) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void organizaVetor( int* a, int* b, int* c ) {
    if (*a < *b) {
        troca( a, b );
    }
    if (*b < *c) {
        troca( b, c );
    }
    if (*a < *b) {
        troca( a, b );
    }
}

int maxValor( int a, int b, int c ) {
    int max_value = a;
    if ( b > max_value ) {
        max_value = b;
    }
    if ( c > max_value ) {
        max_value = c;
    }
    return max_value;
}

int fillCups( int* amount, int amountSize ) {
    int a = amount[0];
    int b = amount[1];
    int c = amount[2];
    
    organizaVetor( &a, &b, &c );

    if ( a > b + c || b > a + c || c > a + b ) {
        return maxValor( a, b, c );
    }

    return ( a + b + c + 1 ) / 2;
}

int main( int argc, char const *argv[] ) {
    int amountSize = 3;
    int amount[] = {5,0,0};
    int minimumTime = fillCups( amount, amountSize );
    printf( "%d", minimumTime );

    return 0;
}