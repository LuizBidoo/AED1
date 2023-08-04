#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minCostClimbingStairs(int* cost, int costSize){
    int *costCompare0, *costCompare1, minCost = 0;
    costCompare0 = cost[0];
    costCompare1 = cost[1];
    for(int i = 0; i < costSize; i++){
        if(costCompare0 < costCompare1){
            minCost = costCompare0;
            costCompare0 = cost[i + 1];
            costCompare1 = cost[i + 1];
        }else if(costCompare0 > costCompare1){
            minCost = costCompare1;
            costCompare0 = cost[i + 1];
            costCompare1 = cost[i + 1];
        }else if(costCompare0 == costCompare1){
            minCost = costCompare1;
            costCompare0 = cost[i + 1];
            costCompare1 = cost[i + 1];
        }
    }
    return minCost;
}

int main()
{
    int* cost;
    int costSize;

    srand(time(NULL));
    costSize = 2 + (rand() % 10);
    cost = (int *)malloc(costSize*sizeof(int));
    for(int i = 0; i < costSize; i++){
        cost[i] = rand() % 100;
    }
    for(int i = 0; i < costSize; i++){
        printf("%d\n", cost[i]);
    }
    minCostClimbingStairs(cost, costSize);
    return 0;
}
