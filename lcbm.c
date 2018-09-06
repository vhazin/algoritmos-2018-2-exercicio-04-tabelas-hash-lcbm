#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    unsigned short valorChave;
    struct node *proximo;
} Node;

typedef struct pointer{
    Node *inicio, *fim;
} Pointer;

void insertNode(Pointer *tabela, short unsigned mod, int chave){
    Node *auxiliar = (Node *)malloc(sizeof(Node));
    auxiliar->valorChave = chave;
    auxiliar->proximo = NULL;

    if (tabela[mod].inicio == NULL){
        tabela[mod].inicio = auxiliar;
    } else {
        tabela[mod].fim->proximo = auxiliar;
    };

    tabela[mod].fim = auxiliar;
}

void printTable(Node *inicio, unsigned short indice){
    Node *auxiliar = inicio;
    printf("%hu -> ", indice);

    while (auxiliar != NULL){
        printf("%d -> ", auxiliar->valorChave);
        auxiliar = auxiliar->proximo;
    };

    printf("\\\n");
}

int main(void){
    Pointer tabela[100];

    unsigned short nTestes;
    scanf("%hu", &nTestes);
    while(nTestes--){
        unsigned short mEnderecos,cChaves;
        scanf("%hu %hu", &mEnderecos, &cChaves);

        for(cChaves; cChaves > 0; cChaves--){
            unsigned short chave;
            scanf("%hu", &chave);
            insertNode(tabela, chave % mEnderecos, chave);
        };

        for(unsigned short indice = 0; indice < mEnderecos; indice++){
            printTable(tabela[indice].inicio, indice);
        };

        printf("\n");
        // free(tabela);
    };
    return 0;
}
