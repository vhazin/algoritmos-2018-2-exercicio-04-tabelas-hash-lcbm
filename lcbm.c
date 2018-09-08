#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    unsigned short value;
    struct node *next, *head, *tail;
} Node;

void insertNode(Node *table, unsigned short hash, unsigned short key);
void printTable(Node *head, unsigned short index);

int main(void){
    unsigned short cases;
    scanf("%hu", &cases);
    
    while(cases--){
        unsigned short lenTable, numKeys;
        scanf("%hu %hu", &lenTable, &numKeys);
        Node table[99] = {0};

        for(; numKeys > 0; numKeys--){
            unsigned short key;
            scanf("%hu", &key);
            insertNode(table, key % lenTable, key);
        };

        for(unsigned short index = 0; index < lenTable; index++){
            printTable(table[index].head, index);
        };

        if (cases){
            printf("\n");
        };
    };
    return 0;
}

void insertNode(Node *table, unsigned short hash, unsigned short key){
    Node *new = (Node *)malloc(sizeof(Node));
    new -> value = key;
    if (table[hash].head == NULL){
        table[hash].head = new;
    } else {
        table[hash].tail -> next = new;
    };
    table[hash].tail = new;
}

void printTable(Node *head, unsigned short index){
    Node *pointer = head;
    printf("%hu -> ", index);
    while (pointer != NULL){
        printf("%hu -> ", pointer -> value);
        pointer = pointer -> next;
    };
    printf("\\\n");
}
