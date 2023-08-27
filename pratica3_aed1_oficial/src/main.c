#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void compare( struct TreeNode* root, int* minimumVal, int* secondMinimum ) {
    if ( root == NULL ) { // caso em que não existe
        return;
    }
    if (*minimumVal == -1) { // para pegar o primeiro menor valor
        *minimumVal = root->val;
    } else if (root->val < *minimumVal) { // para pegar um novo menor valor
        *secondMinimum = *minimumVal;
        *minimumVal = root->val;
    } else if (root->val > *minimumVal && (*secondMinimum == -1 || root->val < *secondMinimum)) { // teste para ver se existe um novo segundo menor valor
        *secondMinimum = root->val;
    }
    compare(root->left, minimumVal, secondMinimum); // recursividade para procurar à esquerda
    compare(root->right, minimumVal, secondMinimum); // recursividade para procurar à direita
}

int findSecondMinimumValue(struct TreeNode* root) {
    int minimumVal = -1;
    int secondMinimum = -1;
    compare(root, &minimumVal, &secondMinimum);

    if (secondMinimum == -1) {
        return -1;
    } else {
        return secondMinimum;
    }
}


struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    
    return root;
}

void destroy(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    destroy(root->left);
    destroy(root->right);
    free(root);
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 14);

    int secondMin = findSecondMinimumValue(root);
    printf("segundo menor: %d\n", secondMin); 

    destroy(root);

    return 0;
}