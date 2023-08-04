#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct NodeAluno{ // nodos da pilha
    int matricula; // dados do nodo
    char nome[50];
    struct NodeAluno* prox; // ponteiro para o prox
}NodeAluno;

typedef struct  { // informações da pilha
    NodeAluno* topo; // ponteiro para o topo
    int limite;
    int contagem;
}Pilha;

// função reset
Pilha* reset(){ // RETORNO: PONTEIRO PARA PILHA
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->limite = 6;
    pilha->contagem = 0;
    return pilha;
}

// função push: por ser pilha tem que ser no topo da lista

void push(Pilha* pilha, int matricula, char nome[]) { // recebe uma referencia para a pilha e o dado que vai ser inserido
    if(pilha->contagem == pilha->limite){ // caso a lista estiver cheia, não posso adicionar
        return;
    }
    NodeAluno* nodo = (NodeAluno*)malloc(sizeof(NodeAluno)); // cria uma referencia para um nodo
    nodo->matricula = matricula; // campo matricula do nodo recebe matricula que foi passada
    strcpy(nodo->nome, nome); // strcpy para nodo->nome receber o nome passado
    nodo->prox = pilha->topo; // proximo do nodo recebe o antigo topo da pilha para não perder a referencia
    pilha->topo = nodo; // o novo topo da pilha vira o nodo
    pilha->contagem++; // contagem é incrementado
}

// função pop: tem que ser também no topo da lista
NodeAluno* pop(Pilha* pilha) {
    if(pilha->contagem == 0){ // caso a lista estiver vazia
        return NULL;
    }
    NodeAluno* retirado = pilha->topo; // cria uma referencia para o nodo retirado
    pilha->topo = pilha->topo->prox; // o novo topo vai ser o próximo do que será retirado
    retirado->prox = NULL; // o próximo do retirado será NULL para ele não apontar para nada
    pilha->contagem--; // contagem decrementa
    return retirado; // retorna a referencia para o retirado
}

// limpa a pilha toda, proximo do topo aponta pra null, quantidade = 0
void clear(Pilha* pilha) {    
    while(pilha->topo != NULL){  // enquanto existir um topo
        NodeAluno* aux = pilha->topo; // vai criar uma referencia para o topo atual
        pilha->topo = pilha->topo->prox; // o próximo vai ser o novo topo
        free(aux); // da free no atual
    }
    pilha->contagem = 0;
}

void repush(Pilha* pilha, NodeAluno* retirado) {
    push(pilha, retirado->matricula, retirado->nome);
}

int main() {
    NodeAluno* retirado;
    Pilha* pilha = reset();

    push(pilha, 95, "Nelson Mandela");
    push(pilha, 32, "Jair Messias");
    push(pilha, 80, "Luis Inácio");
    retirado = pop(pilha);
    retirado = pop(pilha);
    repush(pilha, retirado);
    clear(pilha);
    printf("%s", pilha->topo->nome);
}
