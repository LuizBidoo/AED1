#include <stdio.h>

void somaAB(int *ptrA, int *ptrB) {
    *ptrA = (*ptrA) + (*ptrB);
}

int main() {
    int a, b, *ptrA, *ptrB;

    printf("Digite os dois valores:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    ptrA = &a;  // atribui o endereço de 'a' ao ponteiro ptrA
    ptrB = &b;  // atribui o endereço de 'b' ao ponteiro ptrB

    somaAB(ptrA, ptrB);

    printf("Valor de A: %d\n", a);

    return 0;
}