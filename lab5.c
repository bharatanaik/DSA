// 5. Singly Linked List (SLL) of Integer Data
//     - Create a SLL stack of N integer.
//     - Display of SLL
//     - Linear search.
//
//     Create a SLL queue of N Students Data Concatenation of two SLL of integers.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE create_sll(NODE first){
    int size, i;
    NODE temp;
    printf("Enter size of SLL: ");
    scanf("%d", &size);
    printf("\nEnter elements: ");
    for(i=0; i<size; i++){
        temp = (NODE)malloc(sizeof(struct node));
        scanf("%d", &temp->info);
        temp->link = first;
        first = temp;
    }
    return first;
}

void display_sll(NODE first){
    NODE cur;
    cur = first;
    printf("\n\nSLL elements: ");
    while(cur!=NULL){
        printf("%d ", cur->info);
        cur = cur->link;
    }
}

void linear_search(NODE first){
    NODE cur;
    int elem, count = 1;
    cur = first;
    printf("\nEnter element to search: ");
    scanf("%d", &elem);
    while(cur!=NULL){
        if(cur->info == elem){
            printf("Item found at %d", count);
        }
        cur = cur->link;
        count++;
    }
}


int main(){
    int op;
    NODE first;
    first = (NODE)malloc(sizeof(struct node));
    first = NULL;
    while (1){
        printf("\nOptions:\n1. Create SLL\n2. Display SLL\n3. Search in SLL\n4. Exit\nChoose option: ");
        scanf("%d", &op);
        switch (op){
            case 1: first = create_sll(first);
                break;
            case 2: display_sll(first);
                break;
            case 3:linear_search(first);
                break;
            case 4:exit(0);
            default:printf("\nInvalid option!");
                break;
        }
    }
    return 0;
}
