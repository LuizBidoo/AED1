#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);

int main(int argc, char const *argv[])
{
    struct ListNode *head1 = (struct ListNode *)malloc (sizeof(struct ListNode)); // cabeça da lista 1
    struct ListNode *head2 = (struct ListNode *)malloc (sizeof(struct ListNode)); // cabeça da lista 2

    head1->next = NULL; // lista 1 vazia
    head2->next = NULL; // lista 2 vazia

    push(head1, 1);
    push(head1, 2);
    push(head1, 4);

    push(head2, 1);
    push(head2, 3);
    push(head2, 4);

    mergeTwoLists(head1, head2);
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *newHead = malloc(sizeof(struct ListNode));
    newHead->next == NULL;

    if(list1->next == NULL && list2->next == NULL){
        return newHead;
    }else if(list1->next == NULL){
        return list2;
    }else if(list2->next == NULL){
        return list1;
    }
    while(list1->next != NULL || list2->next != NULL){
        if(list1->val <= list2->val){
            push(newHead, list1->val);
            list1 = list1->next;
        }else if(list2->val <= list1->val){
            push(newHead, list2->val);
            list2 = list2->next;
        }
    }
    return newHead;
}

void push(struct ListNode *head, int num){
    struct ListNode *new;
    new = (struct ListNode*) malloc(sizeof(struct ListNode));
    new->val = num;
    new->next = head->next;
    head->next = new;
}