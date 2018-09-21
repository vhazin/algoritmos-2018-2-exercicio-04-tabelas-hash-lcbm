#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    short keyValue;
    struct node *next, *tail;
} Node;

void insertNode(Node *chain, short hash, short key);
void printChain(Node *chain, short index);

int main(void){
    short testCount;
    scanf("%hi", &testCount);
    while (testCount--){
        short tableLen, keyCount, index = 0;
        scanf("%hi %hi", &tableLen, &keyCount);
        
        Node chain[tableLen];
        memset(chain, 0, sizeof(Node) * tableLen);
        
        for (; keyCount > 0; keyCount--){
            short key;
            scanf("%hi", &key);
            insertNode(chain, key % tableLen, key);
        }
        for (; index < tableLen; index++){
            printChain(chain, index);
        }
        if (testCount) 
            printf("\n");
    }
    return 0;
}

void insertNode(Node *chain, short hash, short key){
    Node *new = (Node *)malloc(sizeof(Node));
    new -> keyValue = key;
    if (chain[hash].next == NULL)
        chain[hash].next = new;
    else
        chain[hash].tail -> next =  new;
    chain[hash].tail = new;
}

void printChain(Node *chain, short index){
    Node *current = chain[index].next;
    printf("%hi -> ", index);
    while (current != NULL){
        printf("%hi -> ", current -> keyValue);
        current = current -> next;
    }
    printf("\\\n");
}
