#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Tree {
    struct TreeNode *root;
};

// segundo menor valor sempre vai ser o da esquerda da root
// se ele n for igual a root, se for é o da direita
// e se só tiver coisa à direita?
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// segundo menor valor sempre vai ser o da esquerda da root
// se ele n for igual a root, se for é o da direita
// e se só tiver coisa à direita?
bool leafTest(struct TreeNode* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }else{
        return false;
    }
}

int findSecondMinimumValue(struct TreeNode* root){
    if(root->left == NULL && root->right == NULL)
        return -1;
    if(leafTest(root->left)){ // se o da esquerda for uma folha
        if(root->left->val == root->right->val){
            if(root->val == root->left->val){
                return -1;
            }else{
                return root->left->val;
            }
        } 
        if(root->left->val == root->val){
            return root->right->val;
        }
    }if(root->left == NULL){
        findSecondMinimumValue(root->right);
    }else{
        findSecondMinimumValue(root->left);
    }
    return NULL;
}

int main(){
    
}