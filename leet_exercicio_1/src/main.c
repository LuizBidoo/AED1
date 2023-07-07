#include <stdio.h>
#include <stdlib.h>
/*código no método mais simples
* complexidade muito alta, teria que verificar todos os numeros do array
*/


int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int returnSize = 0;
    
    int* result = twoSum(nums, numsSize, target, &returnSize);
    
    if (returnSize == 2) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        printf("Valores: %d, %d\n", nums[result[0]], nums[result[1]]);
    } else {
        printf("No valid solution found.\n");
    }
    
    free(result);
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* returnVec = (int*)malloc(2 * sizeof(int)); //só quero retornar o um vetor de tamanho 2
    *returnSize = 0; //returnSize iniciado
    for(int i = 0; i < numsSize; i++){ // for para ver o numero a esquerda
        for(int j = i+1; j < numsSize; j++) // for para ver o numero da direita
            if(nums[i] + nums[j] == target){ // se forem iguais
                *returnSize = 2; //returnSize recebendo 2, por que é o tamanho máximo para esse exercício
                returnVec[0] = i; // passa o index dos valores que 
                returnVec[1] = j; 
                return returnVec; 
            }
    }
    *returnSize = 0;
    return NULL;
}