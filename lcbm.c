#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    short value;
    struct node *next;
} Node;

int main(void){
    int cases = 0;
    scanf("%d", &cases);  
    while(cases--){    
        short tableLenght, keyAmmount;
        scanf("%hi %hi", &tableLenght, &keyAmmount);
        Node *table[100] = {0};
        for (short index = 0; index < keyAmmount; index++){
            short value;
            scanf("%hi", &value);
            Node *new = malloc(sizeof(Node));
            new -> value = value;
            new -> next = NULL;
            short hash = value % tableLenght;
            if (table[hash] == 0){
                table[hash] = new;
            } else {
                Node *collision = table[hash];
                while (collision -> next != NULL){
                    collision = collision -> next;
                };
                collision -> next = new;
            };
        }
        for (short index = 0; index < tableLenght; index++){
            Node *pointer = table[index];
            printf("%hi -> ",index);
            while (pointer != NULL){
                printf("%hi -> ", pointer -> value);
                pointer = pointer -> next;
            };
            printf("\\\n");
        }
        free(table[tableLenght]);
        if(cases >= 1){
            printf("\n");
        };
    }
    return 0;
}
