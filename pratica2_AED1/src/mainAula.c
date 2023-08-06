#include <stdio.h>
#include <stdlib.h>
// Aluno: Luiz Filipe Silveira Bido
// Turma: M1

// fazer usando fila de prioridade 

/*
typedef struct ListNode{
    int cup1;
    int cup2;
    struct ListNode* next;
}ListNode;

typedef struct{
    int time;
    ListNode* topo;
}List;

List* reset() {
    List* pilha = (List*)malloc(sizeof(List));
    pilha->topo = pilha;
    pilha->topo->next = NULL; // próximo da pilha é nulo
    pilha->time = 0; // zera o tempo da pilha
    return pilha;
}

void push(List* pilha, int cup1, int cup2) {
    ListNode* enchido = (ListNode*)malloc(sizeof(ListNode));
    enchido->cup1 = cup1;
    enchido->cup2 = cup2;
    enchido->next = pilha->topo;
    pilha->topo = enchido;
    pilha->time += 1;
}

void clear(List* pilha){
    ListNode* aux;
    while(pilha->topo != NULL){
        aux = pilha->topo;
        pilha->topo->next = pilha->topo;
        free(aux);
    }
}

int fillCups(int* amount, int amountSize, List* pilha){
    int minimumTime = 0;
    for(int i = 0; i < amountSize; i++) { 
        while(amount[i] != 0) {
            if(amount[i+1] != 0){
                push(pilha, i, i+1);
                amount[i]--;
                amount[i+1]--;
            }else{
                push(pilha, i, 0);
                amount[i]--;
            }
        }
    }
    minimumTime = pilha->time;
    clear(pilha);
    return minimumTime;
}
*/

int fillCups(int* amount, int amountSize){
    int minimumTime = 0;
    for(int i = 0; i < amountSize; i++) { 
        while(amount[i] != 0) {
            if(amount[i+1] != 0){
                amount[i]--;
                amount[i+1]--;
                minimumTime++;
            }else{
                amount[i]--;
                minimumTime++;
            }
        }
    }
    return minimumTime;
}

int main(int argc, char const *argv[])
{
    int amount[] = {5,0,0};
    int minimumTime = fillCups(amount, 3);
    printf("%d", minimumTime);

    return 0;
}
