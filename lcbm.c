#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    short value;
    struct node *next;
} Node;

void insertNode(Node **table, short hash, short value);
void printNode(Node **table, short index);

int main(void){
    unsigned short cases;
    scanf("%hu", &cases);

    while (cases--){
        short tableLenght, keyAmmount;
        scanf("%hi %hi", &tableLenght, &keyAmmount);
        Node *table[99] = {0};

        for (short index = 0; index < keyAmmount; index++){
            short value;
            scanf("%hi", &value);
            insertNode(table, value % tableLenght, value);
        }
        for (short index = 0; index < tableLenght; index++){
            printNode(table, index);
        }
        if (cases >= 1){
            printf("\n");
        };
        free(table[tableLenght]);
    }
    return 0;
}

void insertNode(Node **table, short hash, short value){
    Node *new = (Node *)malloc(sizeof(Node));
    new -> value = value;
    new -> next = NULL;
    if (table[hash] == NULL){
        table[hash] = new;
    } else {
        Node *collision = table[hash];
        while (collision -> next != NULL){
            collision = collision -> next;
        };
        collision -> next = new;
    };
}

void printNode(Node **table, short index){
    Node *pointer = table[index];
    printf("%hi -> ", index);
    while (pointer != NULL){
        printf("%hi -> ", pointer -> value);
        pointer = pointer -> next;
    };
    printf("\\\n");
}
