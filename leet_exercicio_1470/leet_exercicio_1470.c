#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    *returnSize = 2 * n;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        result[2 * i] = nums[i];
        result[2 * i + 1] = nums[n + i];
    }
    
    return result;
}
int main(){
    int *nums, numsSize, n, *returnSize;
    
    srand(time(NULL));
    
    printf("n = ");
    
    scanf("%d", &n);
    
    numsSize = 2 * n;
    int* nums = (int*)malloc(numsSize * sizeof(int));

    for(int i = 0; i < 2 * n; i++){
        nums[i] = rand() % 1000;
    }

    int* arrayResultante = shuffle(nums, numsSize, n, &returnSize);

    printf("array resultante:\n");
    for(int i = 0; i < 2 * n; i++){
        printf("%d ", arrayResultante[i]);
    }
    printf("\n");

    free(nums);
    free(arrayResultante);

    return 0;
}