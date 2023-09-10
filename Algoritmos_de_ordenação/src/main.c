#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void insertionSort(double vet[], int vet_size) {
    double atual;
    int j, i;

    for (i = 1; i < vet_size; i++) {
        atual = vet[i]; // atual recebe o segundo valor
        j = i - 1; // valor para iterar dentro do while, é o anterior do i

        while (j >= 0 && atual < vet[j]) { //enquanto a iteração não tiver chegado no começo do vetor e o valor é menor que o próximo
            vet[j + 1] = vet[j]; // troca de posição
            j--; // decrementa
        }
        vet[j + 1] = atual; // faz a troca no vetor
    }
}

void selectionSort(double vet[], int vet_size) {
    double atual, menor, aux;
    int menor_id;

    for (int i = 0; i < vet_size - 1; i++) {
        menor = vet[i]; // começa com o primeiro sendo o menor valor
        menor_id = i;
        for (int j = i + 1; j < vet_size; j++) { // iteração para achar o menor
            if (vet[j] < menor) { // teste para ver se achou um menor
                menor = vet[j]; // se for, o menor recebe o novo menor
                menor_id = j; // guarda-se o índice
            }
        }
        aux = vet[i]; // guarda o valor atual em um auxiliar
        vet[i] = vet[menor_id]; // posição atual recebe o valor menor que foi encontrado usando o índice
        vet[menor_id] = aux; // onde estava o menor valor recebe o valor que foi trocado
    }
}

void quickSort(double vet[], int esquerda, int direita) { // no começo, o direita é o fim e o esquerda é o come;o
    double meio, tmp;
    int i, j;
    i = esquerda;
    j = direita;
    meio = vet[(esquerda + direita) / 2];
    do {
        while (vet[i] < meio) // vindo da esquerda
            i++;
        while (meio < vet[j]) // vindo da direita
            j--;
        if (i <= j) { // se os dois não se cruzaram
            tmp = vet[i];
            vet[i] = vet[j];
            vet[j] = tmp;
            i++;
            j--;
            //troca os dois de lugar e continua a andar no vetor
        }
    } while (i <= j);
    if (esquerda < j) // enquanto o j não chegar até o fim 
        quickSort(vet, esquerda, j); // recursão vindo da esquerda até o j
    if (i < direita) // enquanto o i não chegar até o fim
        quickSort(vet, i, direita); //recursão vindo da direita até o i
}

void merge(double vet[], int inicio, int metade, int fim) {
    int tamanho, fim1, fim2, p1, p2, j, k;
    double* novo;
    tamanho = fim - inicio + 1;
    fim1 = 0, fim2 = 0; // flags para ver se os vetores cortados acabaram de serem lidos
    p1 = inicio; // inicio da primeira lista
    p2 = metade + 1; // inicio da segunda lista
    novo = (double*)malloc(tamanho * sizeof(double)); // crio uma lista temporaria que será copiada para o vet
    if (novo != NULL) {
        for (int i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (vet[p1] < vet[p2]) {
                    novo[i] = vet[p1];
                    p1++;
                } else {
                    novo[i] = vet[p2];
                    p2++;
                }
                if (p1 > metade) // se p1 acabar
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            } else {
                if (!fim1) {
                    novo[i] = vet[p1];
                    p1++;
                } else {
                    novo[i] = vet[p2];
                    p2++;
                }
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++) {
            vet[k] = novo[j];
        }
    }
    free(novo); // da free no vetor auxiliar
}

void mergeSort(double vet[], int inicio, int fim) {
    int metade;
    if (fim - inicio > 1) {
        metade = floor((fim + inicio) / 2);
        mergeSort(vet, inicio, metade);
        mergeSort(vet, metade + 1, fim);
        merge(vet, inicio, metade, fim);
    }
}

void preencherVetor(double vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] = ((double)rand() / RAND_MAX) * 500.0; // Números aleatórios entre 0 e 500
    }
}

// Função para imprimir um vetor
void imprimirVetor(double vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%.2lf ", vet[i]);
    }
    printf("\n");
}

int main(int argc, char const* argv[]) {
    int n, op;
    printf("Diga o tamanho do vetor: ");
    scanf("%d", &n);

    double* vet = (double*)malloc(n * sizeof(double)); // Alocando o vetor dinamicamente
    srand(time(NULL));
    preencherVetor(vet, n);

    clock_t start, end;
    double cpu_time_used;

    printf("Escolha o algoritmo\n1. Insercao\n2. Selecao\n3. Quick\n4. Merge\n");
    scanf("%d", &op);

    printf("\nVetor nao ajeitado: ");
    imprimirVetor(vet, n);

    start = clock(); // Inicia a contagem do tempo

    switch (op) {
        case 1:
            insertionSort(vet, n);
            break;
        case 2:
            selectionSort(vet, n);
            break;
        case 3:
            quickSort(vet, 0, n - 1);
            break;
        case 4:
            mergeSort(vet, 0, n - 1);
            break;
        default:
            printf("\nNao valido\n");
            free(vet); // Liberar a memória alocada para o vetor
            return 1;
    }

    end = clock(); // Encerra a contagem do tempo
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nVetor ajeitado: ");
    imprimirVetor(vet, n);
    printf("Time measured: %.3f seconds.\n", cpu_time_used);

    free(vet); // Liberar a memória alocada para o vetor

    return 0;
}