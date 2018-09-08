#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    unsigned short value;
    struct node *next;
} Node;

int main(void){
    unsigned int cases;
    scanf("%u", &cases);

    while(cases--){
        unsigned short tableLenght, keyAmmount;
        scanf("%hu %hu", &tableLenght, &keyAmmount);
        
        // Initialize
        Node *table[100] = {0};

        // Insert
        for (short key = 0; key < keyAmmount; key++){
            unsigned short value;
            scanf("%hu", &value);

            Node *new = malloc(sizeof(Node));
            new -> value = value;
            new -> next = NULL;

            unsigned short hash = value % tableLenght;
            if (table[hash] == 0){
                table[hash] = new;
            } else {
                Node *collision = table[hash];
                while (collision -> next != NULL){
                    collision = collision -> next;
                };

                collision -> next = new;
            };
        };

        // Print
        for (unsigned short index = 0; index < tableLenght; index++){
            Node *pointer = table[index];
            printf("%hu -> ", index);
            
            while (pointer != NULL){
                printf("%hu -> ", pointer -> value);
                pointer = pointer -> next;
            };

            printf("\\\n");
        };

        printf("\n");
        free(table[tableLenght]);
    };

    return 0;
};
