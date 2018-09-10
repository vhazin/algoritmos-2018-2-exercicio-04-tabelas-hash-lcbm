#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    short keyValue;
    struct node *next;
} Node;

typedef struct {
    Node *head, *tail;
} Pointer;

void printChain(Pointer *table, short index, short tableLength);

int main(void){
    short testCount;
    scanf("%hi", &testCount);

    while (testCount--){
        short tableLength, keyCount;
        scanf("%hi %hi", &tableLength, &keyCount);
        
        Pointer table[tableLength];
        memset(table, 0, sizeof(Pointer) * tableLength);

        for (; keyCount > 0; keyCount--){
            short key, hash;
            scanf("%hi", &key);
            
            Node *new = (Node *)malloc(sizeof(Node));
            new -> keyValue = key;
            new -> next = NULL;
            
            hash = key % tableLength;
            if (table[hash].head == NULL)
                table[hash].head = new;
            else
                table[hash].tail -> next = new;

            table[hash].tail = new;
        }

        printChain(table, 0, tableLength);
        if (testCount) printf("\n");
    }
}

void printChain(Pointer *table, short index, short tableLength){
    Node *current = table[index].head;
    printf("%hi -> ", index);
    
    while (current != NULL){
        printf("%hi -> ", current -> keyValue);
        current = current -> next;
    }

    printf("\\\n");
    index++;
    
    if (index == tableLength) return;
    printChain(table, index, tableLength);
}
